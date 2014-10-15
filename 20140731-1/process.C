#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140731-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "4900 5100  18900 19100  31800 32000");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 0 12100 12300");
  //T->Process("Analysis.C+", "15 7 1 26200 26400");
  T->Process("Analysis.C+", "15 15 2 38400 38600");
}
