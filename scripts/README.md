# 1. Setup
* Panda and Rucio:
```bash
lsetup panda rucio
```

* Edit `gridNickName` and `productionName` in ProductionManager.py
* Edit the path of the hadding script in createJobScript
* Do this in a clean shell aka not where you have RootCore setup already.

# 2. GRID Proxy by Chris Lester ;)
You need to get a grid certificate that is not located on your tmp directory, which is the usual case, but available somewhere through afs. This will allow all the batch nodes you submit to have grid access in order to rucio get your jobs.

```bash
voms-proxy-init -voms atlas -out $HOME/.globus/gridproxy.cert -valid 24:0 
export X509_USER_PROXY=${HOME}/.globus/gridproxy.cert
```
NOTE: I have this persistify for 24 hours. I don't know how to make this last longer, so if you can redo the whole above process before it expries on any lxplus node! 

# 3. [Pandamon](https://github.com/dguest/pandamonium)
(optional if you want to upload other peoples done jobs to eos)
```bash
git clone https://github.com/dguest/pandamonium.git
export PATH=$PATH:$(pwd)/pandamonium
```

# 4. Submit
```bash
python ProductionManager.py
```
The script will get a list of GRID jobs that are "Done" and a list of DSIDs that are already uploaded to EOS. It also checks if bjobs are currently running and skips those samples. This means the script is safe to run as many times as you want.
