#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140804-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "7150 7350  29000 30000");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 3 1 15600 15800");
  //T->Process("Analysis.C+", "15 7 0 19800 20000");
  T->Process("Analysis.C+", "15 7 1 24000 24200");
}
