#include "TopDataPreparation/SampleXsection.h"
#include<iostream>
#include<fstream>
#include <memory>
#include<stdio.h>
using namespace std;
int main()
{

	ifstream file; ofstream out_file;
	string s; int dsid; string del; int count;
  	file.open("Xsection13TeV_tth_bkg_v1.txt");
  	out_file.open("temporary.txt");

	SampleXsection tdp;
	const char* const rc = getenv("ROOTCOREBIN"); 
	std::string filename = std::string(rc) + "/data/TopDataPreparation/XSection-MC15-13TeV-fromSusyGrp.data";
	if (!tdp.readFromFile(filename.c_str())) {
	        std::cout << "TopDataPreparation - could not read file\n";
	        std::cout << filename << "\n";
	        std::cout << "Maybe check it exists, first?" << std::endl;
	       exit(1);
	    }
	
	for(int i=0;i<5;i++)
    	{
    	  getline(file,s);
      	  out_file<<s<<endl;
   	 }

	while(!file.eof())
    	{
      		file>>dsid;
      		count =0;
      		while(!file.eof() && count<9)
        	{
          		if(count==0)
            		out_file<<dsid<<"\t"<<tdp.getRawXsection(dsid)<<"\t"<<tdp.getKfactor(dsid)<<"\t";
          		file>>del;
          		if(count>1)
           	 	{
              			out_file<<del<<"\t";
            		}
         	 count++;
        	}
	out_file<<endl;
    }

  file.close(); out_file.close();
  remove("Xsection13TeV_tth_bkg_v1.txt");
  rename("temporary.txt","Xsection13TeV_tth_bkg_v1.txt");	
	

	return 0;
}
