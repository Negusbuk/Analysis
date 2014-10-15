#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140731-2.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "5950 6150  18850 19050  30500 30700");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 0 13300 13500");
  //T->Process("Analysis.C+", "15 7 1 24550 24750");
  T->Process("Analysis.C+", "15 15 2 35550 35750");
}
