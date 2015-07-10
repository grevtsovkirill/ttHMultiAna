#include<iostream>
#include<fstream>
#include<sstream>
#include<stdio.h>
using namespace std;

void update(int dsid,double &xsection,double &kfactor);

int main()
{

  ifstream file; ofstream out_file;
  string s; int dsid; double kfactor, xsection; string del; int count;
  file.open("Xsection13TeV_tth_bkg_v1.txt");
  out_file.open("temporary.txt");

  for(int i=0;i<5;i++)
    {
      getline(file,s);
      out_file<<s<<endl;
    }

  while(!file.eof())
    {
      file>>dsid;
      update(dsid,xsection,kfactor);
      count =0;
      while(!file.eof() && count<9)
	{
	  if(count==0)
	    out_file<<dsid<<"\t"<<xsection<<"\t"<<kfactor<<"\t";
	  file>>del; 
	  if(count>1)
	    {
	      out_file<<del<<"\t";
	    }
	  count++;
	}
      	  out_file<<endl;
    }

  file.close();
  out_file.close();
  remove("Xsection13TeV_tth_bkg_v1.txt");
  rename("temporary.txt","Xsection13TeV_tth_bkg_v1.txt");
  return 0;
}



void update(int dsid, double &xsection, double &kfactor)
{
  ifstream file; 
  ostringstream convert;
  string s, id_str; 
  convert<<dsid;
  id_str=convert.str();
  file.open("XSection-MC15-13TeV-fromSusyGrp.data");
  while(!file.eof())
    {
      file>>s;
      if(s==id_str)
	{
	  file>>xsection>>kfactor;
	}
    }
  file.close();
}

