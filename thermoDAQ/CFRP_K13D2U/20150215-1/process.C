#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20150215-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "100 600");
  //T->Process("CalTempVsTime.C+");
  
  T->Process("Analysis.C+", "30 0 36300 36800");
  //T->Process("Analysis.C+", "30 0 57700 58200");
  //T->Process("Analysis.C+", "30 0 79100 79600");
}
