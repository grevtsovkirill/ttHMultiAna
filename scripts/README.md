TO SUBMIT:

# 1. Setup
..* Panda and Rucio:
Use a new shell 

`lsetup panda rucio`

```
usage: ProductionManager.py [-h] [--trailPattern TRAILPATTERN]
                            [--nickname NICKNAME] [--eosOutput EOSOUTPUT]
                            [--eosMGM EOSMGM]

optional arguments:
  -h, --help            show this help message and exit
  --trailPattern TRAILPATTERN
                        rucio container trailing patterns. Eg: if container
                        name is user.awesomenickname.etag.ptag.rtag.myid you
                        may use 'rtag.myid' as pattern
  --nickname NICKNAME   your grid NickName
  --eosOutput EOSOUTPUT
                        output eos path; eg /eos/atlas/user/n/narayan/myDir;
                        Note the directory must exist
  --eosMGM EOSMGM       defaults to root://eosatlas.cern.ch/. Leave untouched
                        if you are using CERN eos
```

# 2. GRID Proxy by Stolen from Chris Lester ;)
...You need to get a grid certificate that is not located on your tmp directory, which is the usual case, but available somewhere through afs. This will allow all the batch nodes you submit to have grid access in order to rucio get your jobs.

```
voms-proxy-init -voms atlas -out $HOME/.globus/gridproxy.cert -valid 24:0 
export X509_USER_PROXY=${HOME}/.globus/gridproxy.cert
```
...NOTE: I have this persistify for 24 hours. I don't know how to make this last longer, so if you can redo the whole above process before it expries on any lxplus node! 

# 3. [Pandamon](https://github.com/dguest/pandamonium)
...(optional if you want to upload other peoples done jobs to eos)
```
git clone https://github.com/dguest/pandamonium.git
export PATH=$PATH:$(pwd)/pandamonium
```

# 4. Submit
`python ProductionManager.py`
The script will get a list of GRID jobs that are "Done" and a list of DSIDs that are already uploaded to EOS. It also checks if bjobs are currently running and skips those samples. This means the script is safe to run as many times as you want.
