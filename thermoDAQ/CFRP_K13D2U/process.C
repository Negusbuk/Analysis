#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20150212-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "16400 16800");
  //T->Process("CalTempVsTime.C+");
  
  T->Process("Analysis.C+", "31 0 27000 27200");
}
