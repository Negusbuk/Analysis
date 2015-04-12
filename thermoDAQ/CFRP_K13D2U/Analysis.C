#define Analysis_cxx
// The class definition in Analysis.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("Analysis.C")
// Root > T->Process("Analysis.C","some options")
// Root > T->Process("Analysis.C+")
//

#include <iostream>
#include <fstream>
#include <sstream>

#include "Analysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TLine.h>
#include <TF1.h>
#include <TLatex.h>

Double_t myfunction1(Double_t *x, Double_t *par)
{
  double xx =x[0];
  double p0 = par[0];
  double p1 = par[1];
  double p2 = par[2];
  double p3 = par[3];
  
  double f = 0;
  if (xx<=p3) {
    f = p0 + p1*xx;
  } else {
    f = p0 + p2 + p1*xx;
  }
  
  return f;
}

Double_t myfunction2(Double_t *x, Double_t *par)
{
  double xx =x[0];
  double p0 = par[0];
  double p1 = par[1];
  double p2 = par[2];
  double p3 = par[3];
  double p4 = par[4];
  
  double f = 0;
  if (xx<=p3) {
    f = p0 + p1*xx;
  } else {
    f = p0 + p2 + p4*xx;
  }
  
  return f;
}

Double_t myfunction3(Double_t *x, Double_t *par)
{
  double xx =x[0];
  double p0 = par[0];
  double p1 = par[1];

  return p0 + xx * p1;
}
 
CalibrationSet::CalibrationSet()
{
  minTime_ = 0;
  maxTime_ = 2147483647;
  for (int i=0;i<8;++i) {
    cal_[i] = 0.;
  }
}

void CalibrationSet::read(std::ifstream& ifile)
{
  ifile >> minTime_;
  ifile >> maxTime_;
  
  for (int i=0;i<8;++i) { 
    ifile >> cal_[i];
  }
  
  std::cout << minTime_ << " " << maxTime_ << std::endl;
}

void Analysis::pushPoint(TGraph* gr,
                         Double_t x, Double_t y)
{
  int nPoints = gr->GetN();
  gr->Set(nPoints+1);
  gr->SetPoint(nPoints, x, y);
}

void Analysis::pushPoint(TGraphErrors* gr,
                         Double_t x, Double_t y,
                         Double_t ex, Double_t ey)
{
  int nPoints = gr->GetN();
  gr->Set(nPoints+1);
  gr->SetPoint(nPoints, x, y);
  gr->SetPointError(nPoints, ex, ey);
}

void Analysis::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString options = GetOption();
  
  calset_ = 0;
  minTime_ = 0;
  maxTime_ = 0;
  std::ifstream ifile("calibration.txt");
  int calcount;
  ifile >> calcount;
  for (int i=0;i<calcount;++i) {
    CalibrationSet * calset = new CalibrationSet();
    calset->read(ifile);
    calibrationSets_.Add(calset);
  }

  std::ifstream ifile2("position.txt");
  int poscount;
  ifile2 >> poscount;
  for (int i=1;i<=poscount;++i) {
    ifile2 >> position[i];
  }
  
  std::cout << options << std::endl;
  std::istringstream iss(options.Data());
  iss >> fit_;
  iss >> calidx_;
  calset_ = (CalibrationSet*)calibrationSets_.At(calidx_);
  iss >> minTime_;
  iss >> maxTime_;
 
  nDataEntries = 0;
  for (int i=0;i<=5;++i) {
    data[i] = 0;
  }
}

void Analysis::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).
  
  TString option = GetOption();
}

Bool_t Analysis::Process(Long64_t entry)
{
  // The Process() function is called for each entry in the tree (or possibly
  // keyed object in the case of PROOF) to be processed. The entry argument
  // specifies which entry in the currently loaded tree is to be processed.
  // It can be passed to either Analysis::GetEntry() or TBranch::GetEntry()
  // to read either all or the required parts of the data. When processing
  // keyed objects with PROOF, the object is already loaded and is available
  // via the fObject pointer.
  //
  // This function should contain the "body" of the analysis. It can contain
  // simple or elaborate selection criteria, run algorithms on the data
  // of the event and typically fill histograms.
  //
  // The processing can be stopped by calling Abort().
  //
  // Use fStatus to set the return value of TTree::Process().
  //
  // The return value is currently not used.
  
  GetEntry(entry);

  static bool firstEntry = true;
  if (firstEntry) {
    minUTime = uTime;
    firstEntry = false;
  }
  
  uTime -= minUTime;

  if (calset_) {
    temperature0 -= calset_->getCal(0) - calset_->getCal(7);
    temperature1 -= calset_->getCal(1) - calset_->getCal(7);
    temperature2 -= calset_->getCal(2) - calset_->getCal(7);
    temperature3 -= calset_->getCal(3) - calset_->getCal(7);
    temperature4 -= calset_->getCal(4) - calset_->getCal(7);
    temperature5 -= calset_->getCal(5) - calset_->getCal(7);
    temperature6 -= calset_->getCal(6) - calset_->getCal(7);
  }
  
  T1 = temperature0;
  T2 = temperature1;
  T3 = temperature2;
  T4 = temperature3;
  T5 = temperature4;

  if (uTime>=minTime_ && uTime<=maxTime_) {
    data[1] += T1;
    data[2] += T2;
    data[3] += T3;
    data[4] += T4;
    data[5] += T5;
    data[6] += temperature5; // top
    data[7] += temperature6; // bottom
    data[8] += temperature7; // ambient
    bath += bathTemperature;
    nDataEntries++;
  }

  return kTRUE;
}

void Analysis::SlaveTerminate()
{
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.
  
}

void Analysis::Terminate()
{
  // The Terminate() function is the last function to be called during
  // a query. It always runs on the client, it can be used to present
  // the results graphically or save the results to file.
  
  for (int i=1;i<=8;++i) {
    data[i] /= nDataEntries;
  }
  bath /= nDataEntries;

  //TGraphErrors * grT = new TGraphErrors();
  TGraph * grT = new TGraph();
  grT->SetMarkerStyle(21);
  
  int bit = 1;
  for (int i=1;i<=5;++i) {
    if (fit_&bit) {
      //pushPoint(grT, position[i], data[i], 5*ErrorPos, 20*ErrorT);
      pushPoint(grT, position[i], data[i]);
    }
    bit <<= 1;
  }
  
  TCanvas *c = new TCanvas("c", "c", 700, 500);
   
  TH1F* frame = c->DrawFrame(position[1]-5.0, data[5]-(data[4]-data[5])*5.0,
                             position[5]+5.0, data[1]+(data[1]-data[2])*5.0);
  frame->GetXaxis()->SetTitle("Position [mm]");
  frame->GetYaxis()->SetTitle("Temperature [K]");
  
  grT->Draw("P");
  
  TF1 * fit = new TF1("fit", myfunction3, position[1]-5.0, position[5]+5.0, 2);
  fit->SetLineColor(2);
  grT->Fit(fit, "NR");
  fit->Draw("same");

  std::cout << bath << ", "
            << data[8] << ", "
            << data[7] << ", "
            << data[6] << ", "
            << -1.0 * fit->GetParameter(1) << std::endl;

/*
  tex = new TLatex(positionBottomFace+1, dataBottom[1],
                   Form("#DeltaT_{c} = %.3f K (%.3f K/m)",
                        fitCombined->GetParameter(2),
                        1000.*fitCombineds->GetParameter(1)));
  tex->SetTextAlign(13);
  tex->Draw("same");

  tex = new TLatex(positionBottomFace+1, dataBottom[3],
                   Form("#Delta#DeltaT_{c} = %.6f K",
                        fitCombined->GetParError(2)));
  tex->SetTextAlign(13);
  tex->Draw("same");

  tex = new TLatex(positionBottom[1], dataBottom[4],
                   Form("%.3f K/m", 1000.*fitBottom->GetParameter(1)));
  tex->SetTextAlign(33);
  tex->Draw("same");


  tex = new TLatex(positionTop[1], dataTop[4],
                   Form("%.3f K/m", 1000.*fitTop->GetParameter(1)));
  tex->SetTextAlign(11);
  tex->Draw("same");

  c->Print("Analysis.png");
  
  std::ofstream ofile("fitresults.txt");
  ofile << 1000.*fitTop->GetParameter(1) << std::endl;
  ofile << 1000.*fitCombineds->GetParameter(1) << std::endl;
  ofile << 1000.*fitBottom->GetParameter(1) << std::endl;
  ofile << fitCombined->GetParameter(2) << std::endl;
  ofile << fitCombined->GetParError(2) << std::endl;
  ofile.close();
  */
}
