#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20150219-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "40000 41000");
  //T->Process("CalTempVsTime.C+");
  
  T->Process("Analysis.C+", "30 0 26000 26600");
}
