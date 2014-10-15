#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20140729-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "10600 10800  32200 32400  53800 54000");
  //T->Process("CalTempVsTime.C+");
  
  //T->Process("Analysis.C+", "15 7 0 21400 21600");
  //T->Process("Analysis.C+", "15 7 1 43000 43200");
  T->Process("Analysis.C+", "15 15 2 64600 64800");
}
