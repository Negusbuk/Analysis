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
 
CalibrationSet::CalibrationSet()
{
  minTime_ = 0;
  maxTime_ = 2147483647;
  for (int i=0;i<10;++i) {
    cal_[i] = 0.;
  }
}

void CalibrationSet::read(std::ifstream& ifile)
{
  ifile >> minTime_;
  ifile >> maxTime_;
  
  int count, i;
  double cal;

  ifile >> count;
  for (int j=0;j<count;j++) {
    ifile >> i >> cal;
    cal_[i] = cal;
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
  
  for (int i=1;i<=4;++i) {
    grTTop[i] = new TGraph();
    grTBottom[i] = new TGraph();
  }
  
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
  
  std::cout << options << std::endl;
  std::istringstream iss(options.Data());
  iss >> fitBottom_;
  iss >> fitTop_;
  iss >> calidx_;
  calset_ = (CalibrationSet*)calibrationSets_.At(calidx_);
  iss >> minTime_;
  iss >> maxTime_;
  
  positionBottom[4] =  8.0;
  positionBottom[3] = 16.0;
  positionBottom[2] = 24.0;
  positionBottom[1] = 32.0;
  positionBottomFace = positionBottom[1] + 8.0;
  
  thickness = 0.0;
  
  positionTopFace = positionBottomFace + thickness;
  positionTop[1] = positionTopFace +  8.0;
  positionTop[2] = positionTopFace + 16.0;
  positionTop[3] = positionTopFace + 24.0;
  positionTop[4] = positionTopFace + 32.0;
  
  nDataEntries = 0;
  for (int i=0;i<=4;++i) {
    dataTop[i] = 0;
    dataBottom[i] = 0;
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
    temperature1 -= calset_->getCal(1);
    temperature2 -= calset_->getCal(2);
    temperature3 -= calset_->getCal(3);
    temperature4 -= calset_->getCal(4);
    temperature5 -= calset_->getCal(5);
    temperature6 -= calset_->getCal(6);
    temperature7 -= calset_->getCal(7);
    temperature8 -= calset_->getCal(8);
  }
  
  TBottom1 = temperature5;
  TBottom2 = temperature6;
  TBottom3 = temperature7;
  TBottom4 = temperature8;
  
  TTop1 = temperature1;
  TTop2 = temperature2;
  TTop3 = temperature3;
  TTop4 = temperature4;
 
  if (uTime>=minTime_ && uTime<=maxTime_) {
    dataTop[1] += TTop1;
    dataTop[2] += TTop2;
    dataTop[3] += TTop3;
    dataTop[4] += TTop4;
    dataBottom[1] += TBottom1;
    dataBottom[2] += TBottom2;
    dataBottom[3] += TBottom3;
    dataBottom[4] += TBottom4;
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
  
  for (int i=1;i<=4;++i) {
    dataTop[i] /= nDataEntries;
    dataBottom[i] /= nDataEntries;
  }

  TGraphErrors * grTop = new TGraphErrors();
  grTop->SetMarkerStyle(21);
  TGraphErrors * grBottom = new TGraphErrors();
  grBottom->SetMarkerStyle(21);
  TGraphErrors * grCombineds = new TGraphErrors();
  grCombineds->SetMarkerStyle(21);
  TGraphErrors * grCombined = new TGraphErrors();
  grCombined->SetMarkerStyle(21);
  
  int bit = 1;
  for (int i=1;i<=4;++i) {
    if (fitTop_&bit) {
      pushPoint(grTop, positionTop[i], dataTop[i], ErrorPos, ErrorT);
      pushPoint(grCombineds, positionTop[i], dataTop[i], ErrorPos, ErrorT);
      pushPoint(grCombined, positionTop[i], dataTop[i], ErrorPos, ErrorT);
    }
    bit <<= 1;
  }
  bit = 1;
  for (int i=1;i<=4;++i) {
    if (fitBottom_&bit) {
      pushPoint(grBottom, positionBottom[i], dataBottom[i], ErrorPos, ErrorT);
      pushPoint(grCombineds, positionBottom[i], dataBottom[i], ErrorPos, ErrorT);
      pushPoint(grCombined, positionBottom[i], dataBottom[i], ErrorPos, ErrorT);
    }
    bit <<= 1;
  }
  
  TCanvas *c = new TCanvas("c", "c", 700, 500);
  
  grBottom->Draw("AP");
  
  TH1F* frame = c->DrawFrame(0, dataBottom[4]-(dataBottom[3]-dataBottom[4])*6.0,
                             positionTop[4]+8.0, dataTop[1]+(dataTop[2]-dataTop[1])*6.0);
  frame->GetXaxis()->SetTitle("Position [mm]");
  frame->GetYaxis()->SetTitle("Temperature [K]");
  
  grTop->Draw("P");
  grBottom->Draw("P");
  
  TLine * lineTop = new TLine(positionTopFace, dataBottom[4]-(dataBottom[3]-dataBottom[4])*6.0,
                              positionTopFace, dataTop[1]+(dataTop[2]-dataTop[1])*6.0);
  lineTop->Draw("same");
  TLine * lineBottom = new TLine(positionBottomFace, dataBottom[4]-(dataBottom[3]-dataBottom[4])*6.0,
                                 positionBottomFace, dataTop[1]+(dataTop[2]-dataTop[1])*6.0);
  lineBottom->Draw("same");
  
  TF1 * fitTop = new TF1("fitTop", "pol1", positionTopFace, positionTop[4]+8.0);
  fitTop->SetLineColor(2);
  grTop->Fit(fitTop, "NR");
  fitTop->Draw("same");
  std::cout << fitTop->GetParameter(1) << std::endl;
  
  TF1 * fitBottom = new TF1("fitBottom", "pol1", 0.0, positionBottomFace);
  fitBottom->SetLineColor(2);
  grBottom->Fit(fitBottom, "NR");
  fitBottom->Draw("same");
  std::cout << fitBottom->GetParameter(1) << std::endl;
  
  TF1 * fitCombineds = new TF1("fitCombineds", myfunction1, 0.0, positionTop[4]+8.0, 4);
  TF1 * fitCombined = new TF1("fitCombined", myfunction2, 0.0, positionTop[4]+8.0, 5);
  fitCombineds->FixParameter(3, positionBottomFace);
  fitCombined->FixParameter(3, positionBottomFace);
  grCombineds->Fit(fitCombineds, "NR");
  grCombined->Fit(fitCombined, "NR");
  
  fitCombined->Draw("same");
  
  Float_t TTopFace = fitTop->Eval(positionTopFace);
  Float_t dTTopFace = positionTopFace * fitTop->GetParError(1) + fitTop->GetParError(0);
  std::cout << dTTopFace << std::endl;
  TLine * topLine = new TLine(0, TTopFace, positionTop[4]+8.0, TTopFace);
  topLine->SetLineColor(8);
  topLine->Draw("same");

  Float_t TBottomFace = fitBottom->Eval(positionBottomFace);
  Float_t dTBottomFace = positionBottomFace * fitBottom->GetParError(1) + fitBottom->GetParError(0);
  std::cout << dTBottomFace << std::endl;
  TLine * bottomLine = new TLine(0, TBottomFace, positionTop[4]+8.0, TBottomFace);
  bottomLine->SetLineColor(8);
  bottomLine->Draw("same");
  
  Float_t dT = TTopFace - TBottomFace;
  Float_t ddT = dTTopFace + dTBottomFace;
  std::cout << ddT << std::endl;
  TLatex* tex;
  //tex = new TLatex(positionTopFace+4, dataBottom[1],
  //                 Form("#DeltaT = %.3f K", dT));
  //tex->SetTextAlign(13);
  //tex->Draw("same");

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
}
