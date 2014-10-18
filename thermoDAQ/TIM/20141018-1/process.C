#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20141018-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "4800 5000");
  //T->Process("CalTempVsTime.C+");
  
  T->Process("Analysis.C+", "15 7 0 11600 11800");
}
