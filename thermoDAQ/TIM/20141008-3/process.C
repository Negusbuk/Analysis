#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20141008-3.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "6500 6700 19000 19200");
  //T->Process("CalTempVsTime.C+");
  
  T->Process("Analysis.C+", "15 7 0 12850 13050");
}
