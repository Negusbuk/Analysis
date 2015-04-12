#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20150216-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "12800 13100");
  //T->Process("CalTempVsTime.C+");

  //T->Process("Analysis.C+", "31 0 25300 25800");
  //T->Process("Analysis.C+", "31 0 37700 38200");
  //T->Process("Analysis.C+", "31 0 49400 49900");
  T->Process("Analysis.C+", "31 0 61300 61800");
}
