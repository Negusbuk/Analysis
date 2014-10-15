#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140801-2.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "6350 6550  50000 52000");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 0 13700 13900");
  //T->Process("Analysis.C+", "15 7 0 18950 19150");
  //T->Process("Analysis.C+", "15 15 0 23850 24050");
}
