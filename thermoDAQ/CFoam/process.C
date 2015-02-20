#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20141028-2.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "5150 5350");
  //T->Process("CalTempVsTime.C+");
  
<<<<<<< HEAD
  T->Process("Analysis.C+", "15 7 0 9250 9300");
=======
  T->Process("Analysis.C+", "15 7 0 11050 11250");
>>>>>>> d1d676d62220703b7586abd1be4e87a79103c003
}
