#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140801-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "7150 7350  31400 31600");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 0 14450 14650");
  //T->Process("Analysis.C+", "15 7 0 18350 18550");
  T->Process("Analysis.C+", "15 15 0 23350 23550");
}
