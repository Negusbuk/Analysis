#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140805-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "7150 7350  41000 41200");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 0 13750 13950");
  //T->Process("Analysis.C+", "15 7 0 18350 18550");
  T->Process("Analysis.C+", "15 7 0 23300 23500");
}
