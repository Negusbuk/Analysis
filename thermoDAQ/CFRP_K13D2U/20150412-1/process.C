#define process_cxx

#include <TFile.h>
#include <TTree.h>

void process()
{
  TFile *file = TFile::Open("20150412-1.root");

  TTree *T = (TTree*)file->Get("thermoDAQ");
  
  //T->Process("TempVsTime.C+");
  //T->Process("Calibration.C+", "20000 20200");
  //T->Process("CalTempVsTime.C+");

  //T->Process("Analysis.C+", "31 0  31700  32200");
  //T->Process("Analysis.C+", "31 0  45900  46400");
  //T->Process("Analysis.C+", "31 0  59300  59800");
  //T->Process("Analysis.C+", "31 0  72800  73300");
  //T->Process("Analysis.C+", "31 0  85300  85800");
  T->Process("Analysis.C+", "31 0  98600  99100");
}
