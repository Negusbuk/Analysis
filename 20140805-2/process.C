#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140805-2.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "5950 6150  34000 34500");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 1 13300 13500");
  //T->Process("Analysis.C+", "15 7 1 17600 17800");
  T->Process("Analysis.C+", "15 15 1 21900 22100");
}
