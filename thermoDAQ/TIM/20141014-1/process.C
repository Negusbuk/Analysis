#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20141014-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "11500 11700");
  //T->Process("CalTempVsTime.C+");
  
  T->Process("Analysis.C+", "15 7 0 17050 17250");
}
