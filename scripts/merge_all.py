#Script for merging root files greater than 100 GB in size. Usage is "python merge_all.py outputFileName inputFileNames", arguments are consistent with hadd 

import ROOT
import os, sys

print 'Merging %s' % sys.argv[1]

print "Max tree size",ROOT.TTree.GetMaxTreeSize()
ROOT.TTree.SetMaxTreeSize(1000000000000) # 1000 Gb
print "Updated tree size",ROOT.TTree.GetMaxTreeSize()

rm = ROOT.TFileMerger(False)
rm.SetFastMethod(True)


path = 'mypath'
file_output = '%s' % sys.argv[1]
file_list = []
#for path, dirs, files in os.walk(path):
#  for filename in files:
#    if ('%s_part' % sys.argv[1]) in filename: file_list.append(path+filename)

files = open(sys.argv[2],'r')
for filename in files:
    filename = filename.rstrip()
    file_list.append(filename)

print "Input file list:",file_list
print "Output file:",file_output

for F in file_list:

    print "Adding ->",F
    rm.AddFile(F)

rm.OutputFile(file_output)
rm.Merge()
