# Author: David Hohn <david.hohn@cern.ch>
# Date: 15.1.2016
# Script that can download grid jobs from a running production that are already done.

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

    def __eq__(self, other):
        return self.dsid == other.dsid
        
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
    eos = '/afs/cern.ch/project/eos/installation/0.3.84-aquamarine/bin/eos.select'
    os.environ['EOS_MGM_URL'] = eosMGM
    #cache list of files on eos
    eosFindCmd = eos+" find -f "+eosPath+"/"
    #output is of form path/filename
    eosFindOutput = subprocess.Popen(eosFindCmd.split(' '),stdout=subprocess.PIPE)
    eosFilesList = eosFindOutput.communicate()[0].splitlines()
    samples = []
    for f in eosFilesList:
        filename = f.split('/')[-1]
        dsid = filename.split('.')[0]
        dsid = dsid.split('_')[0]
        sample = Sample()
        sample.dsid = dsid
        samples += [sample]
    return samples

#============================================================================
def getDSSize(DSName):
    totalSize = 0
    client = rucioCLI.Client()
    for f in client.list_files('user.'+gridNickName,DSName):
        totalSize += int(f['bytes'])
    return totalSize

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
def createJobScript(outDir,sample,eosMGM,eosPath):

    jobScript = '%s_%s' % (productionName, sample.dsid)
    if sample.outDS.find('_a766') > 0:
        jobScript += '_AFII'
    jobScript += '.sh'

    copyPath = eosMGM+eosPath
    runScript = 'hadd.sh'
    
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
    file.write('RUCIO_ACCOUNT=rwolff                                                                \n')
    file.write('lsetup "rcsetup Top,2.4.30" rucio -f                                               \n')
    file.write('pwd                                                                                \n')
    file.write('which root                                                                         \n')
    txt  = 'source /afs/cern.ch/work/r/rwolff/atlas/ttHMultiAna_v28/ttHMultilepton/scripts/%s \\\n' % runScript
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
    import os, sys
    import subprocess

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

    eosMGM = 'root://eospublic.cern.ch/'
    #eosPath = '/eos/escience/UniTexas/HSG8/multileptons_ntuple_run2/25ns_v20/04/Data'
    #eosPath = '/eos/escience/UniTexas/HSG8/multileptons_ntuple_run2/25ns_v28/01/Sys_1l3l4l'
    #eosPath = '/eos/escience/UniTexas/HSG8/multileptons_ntuple_run2/25ns_v28/01/Sys_2l'
    eosPath = '/eos/escience/UniTexas/HSG8/multileptons_ntuple_run2/25ns_v28/01/Sys_1l2t_2los1t'
    samplesOnEOS = getSamplesOnEOS(eosMGM,eosPath)
    
    gridNickName = 'rwolff'
    #productionName = '18.08.16.Data-04'
    #productionName = '2017-05-13.Sys_v28_1l3l4l'
    #productionName = '2017-05-13.Sys_v28_2l'
    productionName = '2017-05-13.Sys_v28_2los1tau_1l2tau'
    #productionName = '17.07.16.Sys.x'

    
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
            jobScript = createJobScript(outDir, copySample, eosMGM, eosPath)
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
            submitted += 1

    totalSize = 0
    for s in doneSamplesOnGRID:
        totalSize += s.size
            
    print "\nSummary"
    print "GRID jobs that are done: %s"        % len(doneSamplesOnGRID)
    print "of which %s are already on EOS"     % len(list(set(doneSamplesOnGRID) & set(samplesOnEOS)))
    print "%s bjobs have been submitted now"   % submitted
    print "Total Size: %s"                     % totalSize

    '''
    extras = set(doneSamplesOnGRID) - set(samplesOnEOS)
    for e in list(extras):
        print e.outDS
    '''
    
