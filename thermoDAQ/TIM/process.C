#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
<<<<<<< HEAD
  TFile *file = TFile::Open("20141008-2.root");
=======
  TFile *file = TFile::Open("20141030-1.root");
>>>>>>> d1d676d62220703b7586abd1be4e87a79103c003

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
<<<<<<< HEAD
  //T->Process("Calibration.C+", "1550 1750 14400 14600");
  //T->Process("CalTempVsTime.C+");
  
  T->Process("Analysis.C+", "15 7 0 8800 9000");
=======
  //T->Process("Calibration.C+", "4450 4650");
  //T->Process("CalTempVsTime.C+");
  
  T->Process("Analysis.C+", "15 7 0 11100 11300");
>>>>>>> d1d676d62220703b7586abd1be4e87a79103c003
}
