#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140820-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "22000 23000");
  //T->Process("CalTempVsTime.C+");
  
  T->Process("Analysis.C+", "15 7 0 13200 13600");
}
