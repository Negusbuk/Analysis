#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140815-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "29200 29600");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 0 12700 12900");
  T->Process("Analysis.C+", "15 7 0 17200 17400");
  //T->Process("Analysis.C+", "15 7 0 21400 21600");
}
