#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20141017-3.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "6700 6900");
  T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 0 11000 11100");
}
