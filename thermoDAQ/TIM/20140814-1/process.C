#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140814-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "30000 31000");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 0 14500 14700");
  T->Process("Analysis.C+", "15 7 0 18550 18750");
  //T->Process("Analysis.C+", "15 7 0 23200 23400");
}
