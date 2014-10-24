#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140821-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "5700 5900");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 0 13600 13800");
  //T->Process("Analysis.C+", "15 7 0 17700 17900");
  T->Process("Analysis.C+", "15 7 0 21800 22000");
}
