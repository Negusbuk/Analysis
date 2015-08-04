#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20150803-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "3600 3750");
  //T->Process("CalTempVsTime.C+");
  
  T->Process("Analysis.C+", "15 7 0 10500 10700");
}
