import os,sys,subprocess

def getXsecAndKFac(dsid):
    cmd = "cat %s | grep %s | awk '$1== %s {print $2}'"%(TDP,dsid,dsid)
    proc = subprocess.Popen(cmd, stdout = subprocess.PIPE, shell=True)
    xsec = proc.stdout.read()
    cmd2 = cmd.replace("$2","$3")
    proc = subprocess.Popen(cmd2, stdout = subprocess.PIPE, shell=True)
    kfac = proc.stdout.read()
    if xsec and kfac:
        return xsec.strip("\n"), kfac.strip("\n")
    else:
        return 0,0 



fList = os.listdir(os.getcwd())
xsecFiles = [f for f in fList if ( f.startswith("Xsection") and f.endswith(".txt") ) ] # Get list of Xsection files to update
TDP = "/cvmfs/atlas.cern.ch/repo/sw/database/GroupData/dev/AnalysisTop/TopDataPreparation/XSection-MC15-13TeV.data" # TopDataPreparation
#TDP = "/afs/cern.ch/work/y/yshimoga/ttHMultiFW/source/ttHMultiAna/data/XSection-MC15-13TeV.data" # TopDataPreparation

if os.path.exists(TDP):
    print "TopDataPreparation Status: OK"
else:
    raise Exception("Could not read: %s \n May be check it exists, first?"%TDP)


for fname in xsecFiles:
    print "Updating %s"%fname
    infile = open(fname, "r")
    outfile = open("tmp_"+fname, "w")
    for line in infile:
        l = line.strip()
        if not l or l[0] == '#':   # blank line or comment
            outfile.write(line)
            continue
        ls = line.split()
        xsec, kfac = getXsecAndKFac(ls[0])
        #print xsec, kfac
        if float(xsec)<=0 or float(kfac)<=0:
            try:
                xsec = ls[1]
                kfac = ls[2]
                print "TDP:: Xsection for DSID: %s is invalid. Keeping old value"%ls[0]
            except :
                print "Xsection of DSID %s is set to Zero"%ls[0]
                xsec = 0
                kfac = 0
        filtEff = "1.0"; Uncert = "--"; Mass = "-999"; Prio = "2";
        Gen = "Default"; Info = "General"; SimType = "Full"; 
        try:
            filtEff = ls[3] 
            Uncert = ls[4]
            Mass = ls[5]
            Prio = ls[6]
            Gen = ls[7]
            Info = ls[8]
            SimType = ls[9]
        except:
            print "Generator information for DSID: %s is not available"%ls[0]
        outfile.write("%7s   %14s   %13s   %4s   %4s   %4s   %2s   %19s   %35s   %6s\n"%(ls[0],xsec,kfac,filtEff,Uncert,Mass,Prio,Gen,Info,SimType))
    cmd = "mv tmp_%s %s"%(fname,fname)
    #print cmd
    os.system(cmd)

            
    
    
