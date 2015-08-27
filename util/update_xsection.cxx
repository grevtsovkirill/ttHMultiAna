#include "TopDataPreparation/SampleXsection.h"
#include<iostream>
#include<fstream>
#include <sstream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>

using namespace std;
int main()
{

  ifstream file; ofstream out_file; bool notfound;
	string s, del; int dsid, count;
	const char* outfile_name[]={"Xsection13TeV_tth_bkg_v1.txt", "Xsection13TeV_tth_sig_v1.txt"};

	SampleXsection tdp;
	const char* const rc = getenv("ROOTCOREBIN"); 
	std::string filename = std::string(rc) + "/data/TopDataPreparation/XSection-MC15-13TeV-fromSusyGrp.data";
	if (!tdp.readFromFile(filename.c_str())) {
	        std::cout << "TopDataPreparation - could not read file\n";
	        std::cout << filename << "\n";
	        std::cout << "Maybe check it exists, first?" << std::endl;
	       exit(1);
	    }

	for(int i =0; i<2;i++)
	{
        	file.open(outfile_name[i]);
        	out_file.open("temporary.txt");	

		while(!file.eof())
    		{
		 	getline(file,s);
			stringstream line(s);
			if(line>>dsid)
			{
			  notfound = false;
				if(tdp.getRawXsection(dsid)== -1 || tdp.getKfactor(dsid)== -1 )
				{
					cout<<"Xsection for DSID: "<<dsid<<" not found in TopDataPreparation Package\n";
					notfound = true;
				}
				if(notfound ==false)
				  {
				    out_file<<setw(7)<<dsid<<"\t"<<setw(14)<<tdp.getRawXsection(dsid)<<"\t"<<setw(9)<<tdp.getKfactor(dsid)<<"\t";
				  }
				else
				  {
				    out_file<<setw(7)<<dsid<<"\t";
				  }
				count=0;
				while(line>>del)
				{
				  if(notfound==true && count<=1)
				    {
				      if(count==0) out_file<<setw(14);
				      if(count==1) out_file<<setw(9);
				      out_file<<del<<"\t";
				    }
				  else if(count > 1)
				    {
				      if(count==6) out_file<<setw(30);
				      else if(count==7) out_file<<setw(35);
				      else if(count==5 || count == 8) out_file<<setw(5);
				      else out_file<<setw(9);
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
 	 remove(outfile_name[i]);
 	 rename("temporary.txt",outfile_name[i]);
	cout<<"Successfully Updated "<<outfile_name[i]<<endl;
	}	
	

	return 0;
}
