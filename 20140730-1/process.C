#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140730-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "10800 11000  32400 32600  54000 54200");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 0 21600 21800");
  //T->Process("Analysis.C+", "15 7 1 43200 43400");
  T->Process("Analysis.C+", "15 7 2 64600 65000");
}
