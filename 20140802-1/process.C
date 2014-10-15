#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140802-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "6400 6600  36000 38000  80000 82000");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 1 14350 14550");
  //T->Process("Analysis.C+", "15 7 1 20150 20350");
  T->Process("Analysis.C+", "15 7 1 24750 24950");
}
