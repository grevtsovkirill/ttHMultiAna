#include "TopDataPreparation/SampleXsection.h"
#include<iostream>
#include<fstream>
#include <sstream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int main()
{

	ifstream file; ofstream out_file;
	string s, del; int dsid, count;
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
	

	while(!file.eof())
    	{
	 	getline(file,s);
		stringstream line(s);
		if(line>>dsid)
		{
			out_file<<dsid<<"\t"<<tdp.getRawXsection(dsid)<<"\t"<<tdp.getKfactor(dsid)<<"\t";
			count=0;
			while(line>>del)
			{
				if(count > 1)
				{
					out_file<<del<<"\t";
				}
				count++;
			}
			out_file<<endl;
		}
		else
		{
			out_file<<s<<endl;
			continue;
		}	
   	}

  file.close(); out_file.close();
  remove("Xsection13TeV_tth_bkg_v1.txt");
  rename("temporary.txt","Xsection13TeV_tth_bkg_v1.txt");	
	

	return 0;
}
