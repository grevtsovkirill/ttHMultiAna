# Author: David Hohn <david.hohn@cern.ch>
# Date: 15.1.2016
# Script that can download grid jobs from a running production that are already done.

def makeHadd(outFname):
    outFile=open(outFname,'w')
    outFile.write('#!/bin/bash                              \n')
    outFile.write('start=`date +%s`                       \n\n')
    outFile.write('function cleanExit {                     \n')
    outFile.write('    end=`date +%s`                       \n')
    outFile.write('    runtime=$((end-start))               \n')
    outFile.write('    echo runtime $runtime seconds      \n\n')
    outFile.write('    rm -rf $RUNDIR/$outDS                \n')
    outFile.write('    echo exit $1                         \n')
    outFile.write('    exit $1                              \n')
    outFile.write('}                                        \n')
    outFile.write('outDS=$1                                 \n')
    outFile.write('eosPath=$2                               \n')
    outFile.write('DSID=$3                                  \n')
    outFile.write('if echo $outDS | grep -q "_a766"         \n')
    outFile.write('then                                     \n')
    outFile.write('  fileName=${DSID}_AFII.root             \n')
    outFile.write('else                                     \n')
    outFile.write('  fileName=${DSID}.root                  \n')
    outFile.write('fi                                       \n')
    outFile.write('inDS=$4                                \n\n')
    outFile.write('echo "Job Info"                          \n')
    outFile.write('echo "Download from: $outDS"             \n')
    outFile.write('echo "Upload to    : $eosPath/$fileName" \n')
    outFile.write('echo                                   \n\n')
    outFile.write('#cd $TMPDIR                              \n')
    outFile.write('#echo $TMPDIR                            \n')
    outFile.write('#echo $pwd                               \n')
    outFile.write('RUNDIR=$(pwd)                            \n')
    outFile.write('mkdir $outDS                             \n')
    outFile.write('cd $outDS                              \n\n')
    outFile.write('echo "Will download $outDS"              \n')
    outFile.write('rucio download $outDS|tee rucio.log      \n')
    outFile.write('rucioExit=$?                             \n')
    outFile.write('echo "rucio exit $rucioExit"             \n')
    outFile.write('grep -q "Files that cannot be downloaded :             0" rucio.log\n')
    outFile.write('rucioFail=$?                             \n')
    outFile.write('echo "rucio failed to download? $rucioFail"\n')
    outFile.write('echo                                         \n')
    outFile.write('([ $rucioExit -eq 0 ] && [ $rucioFail -eq 0 ]) || ( echo $inDS >> ${LSB_OUTDIR}/../rucio.fail; cleanExit 1 )\n\n')
    outFile.write('cd $outDS                                \n')
    outFile.write('echo ls -l                               \n')
    outFile.write('ls -l                                    \n')
    outFile.write('echo                                   \n\n')
    outFile.write('echo "Will hadd $(ls -1 *.root*|wc -l) files"\n')
    outFile.write('hadd -n 5 $fileName *.root*              \n')
    outFile.write('haddExit=$?                              \n')
    outFile.write('echo "hadd exit $haddExit"               \n')
    outFile.write('[ $haddExit -eq 0 ] || cleanExit 2     \n\n')
    outFile.write('ls -l $fileName                          \n\n')
    outFile.write('echo xrdcp -f -np $fileName $eosPath/$fileName\n')
    outFile.write('xrdcp -f -np $fileName $eosPath/$fileName\n')
    outFile.write('eoscpExit=$?                             \n')
    outFile.write('echo "eos cp exit $haddExit"             \n')
    outFile.write('[ $eoscpExit -eq 0 ] || cleanExit 3    \n\n')
    outFile.write('echo "alles goed"                      \n\n')
    outFile.write('cleanExit 0                              \n')
    outFile.close()
    

#============================================================================
def printOut(target, value):
    if len(value.strip()):
        target.write(value)
        target.flush()

#============================================================================
class link:
    """
    object that creates a link and clean up after itself
    """
   
    def __init__(self,target,linkname):
        self.target = target
        self.linkname = linkname

        cmd = ['ln','-s']
        cmd += [target]
        cmd += [linkname]
        cmd = " ".join(cmd)
        print cmd
        os.system(cmd)

    def __del__(self):
        os.remove(self.linkname)
        os.remove(self.linkname+"c")

#============================================================================
class Sample:
    def __init__(self,job=None):
        ''' takes a pandatools.LocalJobsetSpec'''
        if job:
            outDS = job.outDS.split(',')[0]
            dsid  = outDS.split('.')[2]
            size  = getDSSize(outDS)
            self.dsid     = str(dsid)
            self.size     = int(size)
            self.outDS    = str(outDS)
            self.inDS     = str(job.inDS)
            self.AFII     = self.outDS.count('_a766') > 0
            
    def __eq__(self, other):
        return (self.dsid == other.dsid) and (self.AFII == other.AFII )
        
    def __str__(self):
        return "DSID: %s"  % self.dsid

    def __hash__(self):
        return hash(self.dsid)

#============================================================================
class BJob:
    def __init__(self,outDir,jobScript):
        self.jobScript   = jobScript
        self.q           = '8nh'
        self.pool        = None
        self.outDir      = outDir

    def setQ(self, q):
        queues = ['8nm','1nh','8nh','1nd','2nd','1nw','2nw']
        if q not in queues:
            print "not a valid queue. Choose one from"
            print queues
            raise Exception()
        self.q = q

    def setPool(self, pool):
        #pool is requested in MB, assumed to be provided in B
        self.pool = max(1,pool/1e6)
        
    def command(self):
        if os.getenv("LSB_STDOUT_DIRECT") == None:
            command = ['bsub', '-q', self.q]
            if self.pool != None:
                command += ['-R "rusage[pool=%d]"' %self.pool]
            command += ['-o %s.out' % self.jobScript[:-3] ]
            command += ['/bin/bash', self.jobScript]
            return command
        else:
            raise Exception("LSB_STDOUT_DIRECT is set. No pool resource can be requested.")

    def submit(self):
        command = self.command()
        commandShellTrue = ' '.join( command )
        process  = subprocess.Popen(commandShellTrue, stdout=subprocess.PIPE, stderr=subprocess.PIPE,shell=True,cwd=self.outDir)

        #print result
        (stdout, stderr) = process.communicate()
        printOut(sys.stdout,stdout)
        printOut(sys.stderr,stderr)

    
    def __str__(self):
        command = self.command()
        return ' '.join( command )
    
#============================================================================
def getSamplesOnEOS(eosMGM,eosPath):
    eos = '/afs/cern.ch/project/eos/installation/0.3.15/bin/eos.select'
    os.environ['EOS_MGM_URL'] = eosMGM
    #cache list of files on eos
    eosFindCmd = eos+" find -f "+eosPath+"/"
    #output is of form path/filename
    eosFindOutput = subprocess.Popen(eosFindCmd.split(' '),stdout=subprocess.PIPE)
    eosFilesList = eosFindOutput.communicate()[0].splitlines()
    print eosFilesList
    samples = []
    for f in eosFilesList:
        filename = f.split('/')[-1]
        dsid = filename.split('.')[0]
        sample = Sample()
        sample.dsid = dsid.split('_')[0]
        if len(dsid.split('_'))>1:
            sample.AFII = True
        else:
            sample.AFII = False
        samples += [sample]
    return samples

#============================================================================
def getDSSize(DSName):
    totalSize = 0
    client = rucioCLI.Client()
    '''strip trailing /'''
    DSName = DSName.strip("/")
    for f in client.list_files('user.'+gridNickName,DSName):
    #for f in client.list_files('user.narayan','user.narayan.364212.Sherpa.DAOD_HIGG8D1.e5421_s3126_r9364_r9315_p3371.tthml_gn2_first.2018-03-20_output.root'):
        totalSize += int(f['bytes'])
    return totalSize

#============================================================================
def getDoneSamplesOnGRIDOtherUser():
    samples = []
    #https://github.com/dguest/pandamonium
    cmd = "pandamon user.%s*%s | awk '$1 ~ /done/ {print $4}'" %(gridNickName,productionName)
    print 'getting done GRID jobs with:'
    print cmd
    for line in subprocess.Popen(cmd,stdout=subprocess.PIPE,stderr=subprocess.PIPE,shell=True).communicate()[0].splitlines():
        #all the following to mimick the Sample constructor
        #https://stackoverflow.com/questions/19476816/creating-an-empty-object-in-python
        job = type('', (), {})()
        #strip trailing /
        if line[-1] in "/":
            line = line[:-1]
        job.outDS = line+'_output.root,dummy'
        job.inDS = ''
        samples += [Sample(job)]

    return samples

#============================================================================
def getDoneSamplesOnGRID():
    pbookCore = pbook.PBookCore(False,False,False,False)
    pbookCore.sync()
    pbookCore.clean()
    pbookCore.updateTaskJobsetMap()

    done     = 0
    broken   = 0
    finished = 0
    failed   = 0
    running  = 0
    total    = 0

    samples = []
    
    jobList = pbookCore.getLocalJobList()
    for job in jobList:
        if job.outDS.count(productionName):
            total += 1
            if job.taskStatus == 'finished' or job.taskStatus == 'failed':
                # these are the jobs that we sometimes retry and for which the status might not be up to date
                job = pbookCore.statusJobJobset(job.JobsetID,forceUpdate=True)
            if job.taskStatus == 'done':
                done += 1
                samples += [Sample(job)]
            elif job.taskStatus == 'broken':
                broken += 1
            elif job.taskStatus == 'finished':
                finished += 1
                print job
                status_map = {}
                # jobStatus look like:
                #>>> job.jobStatus
                #'finished*109,failed*1'
                for status in job.jobStatus.split(','):
                    status_name  = status.split('*')[0]
                    status_count = status.split('*')[1]
                    status_map[status_name] = int(status_count)
                #call anything with more than 95% a success for mc
                finish_fraction = float(status_map['finished'])/float(sum(status_map.values()))
                if finish_fraction > 0.95 and not job.inDS.count('data') and not job.outDS.count('Sys'):
                    print 'Uploading job with %s finish fraction and DS %s' %( finish_fraction, job.inDS)
                    samples += [Sample(job)]
                else:
                    #print 'Retrying finished job with DS', job.inDS
                    #pbookCore.retry(job.JobID)
                    pass
            elif job.taskStatus == 'failed':
                failed += 1
                #print 'Retry failed job with DS', job.inDS
                #pbookCore.retry(job.JobID)
            elif job.taskStatus == 'running':
                running +=1

    print '%s jobs in %s' % (total, productionName)
    print 'broken:   %s' % broken
    print 'finished: %s' % finished
    print 'failed:   %s' % failed
    print 'running:  %s' % running
    print 'done:     %s' % done

    return samples

#============================================================================
def createJobScript(outDir,sample,eosMGM,eosPath,grid_user):

    jobScript = '%s_%s' % (productionName, sample.dsid)
    if sample.outDS.find('_a766') > 0:
        jobScript += '_AFII'
    jobScript += '.sh'

    copyPath    = eosMGM+eosPath
    makeHadd('hadd.sh')
    runScript   = 'hadd.sh'
    runScript   = os.popen('readlink -f hadd.sh','r').read().strip('\n')
    
    if sample.size > 100e9:
        eosMkdirCmd = 'eos '+eosMGM+' mkdir -p '+eosPath+'/'+sample.dsid
        eosMkdir = subprocess.Popen(eosMkdirCmd.split(' '))
        eosMkdir.wait()
        if eosMkdir.returncode != 0:
            raise RuntimeError('Couldnt eos mkdir')
        
        runScript = 'nohadd.sh'
    
    file = open(outDir+ '/' + jobScript, 'w') 
    file.write('#!/bin/sh                                                                          \n')
    file.write('date                                                                               \n')
    file.write('source /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/user/atlasLocalSetup.sh        \n')
    #file.write('setupATLAS                                                                         \n')
    file.write('RUCIO_ACCOUNT=%s                                                                \n'%(grid_user))
    file.write('lsetup rucio -f                                               \n')
    file.write('echo X509_USER_PROXY                                                \n')
    file.write('pwd                                                                                \n')
    file.write('which root                                                                         \n')
    txt  = 'source %s \\\n' % runScript
    txt += '%s \\\n' % sample.outDS
    txt += '%s \\\n' % copyPath
    txt += '%s \\\n' % sample.dsid
    txt += '%s \\\n' % sample.inDS
    file.write(txt)
    file.close() 

    return jobScript 


#============================================================================
def SampleHasRunningBJob(jobName, runningBJobs):
    #runningBJobs is list of strings, output of bjobs
    for bjob in runningBJobs:
        #check if there is still a bjob runnig for this sample
        if bjob.count(jobName):
            return True

    return False

#============================================================================
#============================================================================
#============================================================================
if __name__ == '__main__':
    import os, sys,argparse
    import subprocess
    parser = argparse.ArgumentParser()
    parser.add_argument("--trailPattern",default="",
        help="rucio container trailing patterns. Eg: if container name is user.awesomenickname.etag.ptag.rtag.myid you may use 'rtag.myid' as pattern")
    parser.add_argument("--nickname",default="",help="your grid NickName")
    parser.add_argument("--eosOutput",default="",help="output eos path; eg /eos/atlas/user/n/narayan/myDir; Note the directory must exist")
    parser.add_argument("--eosMGM",default="root://eosatlas.cern.ch/",help="defaults to root://eosatlas.cern.ch/. Leave untouched if you are using CERN eos")
        
    parsed = parser.parse_args()
    
    if parsed.trailPattern =="" or parsed.nickname=="" or parsed.eosOutput=="":
        sys.exit("ERROR: grid nickname or trailPattern misisng. Check the usage of the tool")
    
    try:
        os.environ['X509_USER_PROXY']
    except KeyError:
        raise RuntimeError('Please setup your GRID certificate as described in the README.')

    #passing the env variables to lxbatch is a bit weird. better start clean.
    for env_var in ['ROOTCOREBIN','ROOTSYS']:
        if env_var in os.environ.keys():
            raise RuntimeError('Please use a clean shell. The environment variable passing to the batch jobs is finicky.')

    #link pbook to pbook.py in working directory so it can be imported
    pbookPath = os.environ['ATLAS_LOCAL_PANDACLIENT_PATH']+'/bin/pbook'
    pbookLinkname = os.getcwd()+"/pbook.py"
    pbookLink = link(pbookPath,pbookLinkname)
    import pbook

    rucioPath = os.environ['RUCIO_HOME']+'/bin/rucio'
    rucioLinkname = os.getcwd()+"/rucioCLI.py"
    rucioLink = link(rucioPath,rucioLinkname)
    import rucioCLI

    import logging
    allLoggers = logging.Logger.manager.loggerDict
    #rucio needs to shut up
    for log in allLoggers:
        if isinstance(allLoggers[log],logging.Logger):
            allLoggers[log].setLevel(logging.ERROR)

    logger = logging.getLogger(__name__)
    logger.setLevel(logging.INFO)

    eosMGM          = parsed.eosMGM
    eosPath         = parsed.eosOutput
    samplesOnEOS    = getSamplesOnEOS(eosMGM,eosPath)
    
    gridNickName    = parsed.nickname
    #productionName = '2017-05-13.Sys_v28_2l'
    productionName = parsed.trailPattern

    userenv = 'RUCIO_ACCOUNT' if 'RUCIO_ACCOUNT' in os.environ else 'USER'
    #doneSamplesOnGRID = getDoneSamplesOnGRID()
    if gridNickName != os.environ[userenv]:
        doneSamplesOnGRID = getDoneSamplesOnGRIDOtherUser()
        print doneSamplesOnGRID
    else:
        doneSamplesOnGRID = getDoneSamplesOnGRID()
    
   #samples that are done on GRID but not yet on EOS
    samplesCopyEOS = list(set(doneSamplesOnGRID) - set(samplesOnEOS))
    runningBJobs = subprocess.Popen(["bjobs","-l"],stdout=subprocess.PIPE,stderr=subprocess.PIPE).communicate()[0].splitlines()
    submitted = 0
    for copySample in samplesCopyEOS:
        if SampleHasRunningBJob(productionName+'_'+copySample.dsid,runningBJobs):
            print copySample, "has a running job. Wait for it."
            doSubmit = False
        else:
            doSubmit = True
            
        if doSubmit:
            outDir = productionName+'/'+copySample.dsid+'_jobdir'
            if not os.path.isdir(outDir):
                os.makedirs(outDir)
            jobScript = createJobScript(outDir, copySample, eosMGM, eosPath,gridNickName)
            job = BJob(outDir, jobScript)
            if copySample.size > 10e9:
                job.setQ('1nd')
            else:
                job.setQ('8nh')
            job.setPool(2*copySample.size)
            if copySample.size > 100e9:
                job.setPool(copySample.size)
            print job
            job.submit()
            #break

    totalSize = 0
    for s in doneSamplesOnGRID:
        totalSize += s.size
            
    print "\nSummary"
    print "GRID jobs that are done: %s"        % len(doneSamplesOnGRID)
    print "of which %s are already on EOS"     % len(list(set(doneSamplesOnGRID) & set(samplesOnEOS)))
#    print "%s bjobs have been submitted now"   % submitted
    print "Total Size: %s"                     % totalSize

    '''
    extras = set(doneSamplesOnGRID) - set(samplesOnEOS)
    for e in list(extras):
        print e.outDS
    '''

