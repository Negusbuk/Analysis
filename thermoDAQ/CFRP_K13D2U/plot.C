Double_t myfunction(Double_t *x, Double_t *par)
{
  double xx =x[0];
  double p0 = par[0];
  double p1 = par[1];

  return p0 + xx * p1;
}

struct Data {
  double bath;
  double ambient;
  double bottom;
  double top;
  double slope;
};

Data M2[] = { { 12.5031, 23.7709, 24.0098, 29.5339, 0.0626048 }, // 20150216-1  1
              { 14.9948, 23.9009, 25.9580, 30.9657, 0.0555942 }, // 20150216-1  2
              { 17.5056, 24.0684, 27.9194, 32.4062, 0.0485321 }, // 20150216-1  3
              { 19.9754, 24.2597, 29.9156, 33.8673, 0.0413661 }, // 20150216-1  4
              { -999.0, -1.0, -1.0, -1.0, -1.0 }
};

Data M1[] = { { 20.0029, 22.9366, 22.4600, 27.7463, 0.0672649 }, // 20150212-1  1
              { 15.0104, 21.8795, 18.5872, 24.6736, 0.0802060 }, // 20150212-1  2
              { 12.4947, 21.6652, 16.7063, 23.1672, 0.0866975 }, // 20150212-1  6
              { 9.99151, 21.0075, 14.7072, 21.6006, 0.0932997 }, // 20150212-1  3
              { 7.49013, 20.8415, 12.9006, 20.1143, 0.0991401 }, // 20150212-1  5
              { 4.99665, 20.2296, 10.8822, 18.5087, 0.1056600 }, // 20150212-1  4
              { -999.0, -1.0, -1.0, -1.0, -1.0 }
};

void plot()
{
  TGraph * gr1 = new TGraph();
  gr1->SetMarkerStyle(21);
  int nPoints1 = 0;

  TGraph * gr2 = new TGraph();
  gr2->SetMarkerStyle(21);
  int nPoints2 = 0;

  TGraph * gr3 = new TGraph();
  gr3->SetMarkerStyle(21);
  int nPoints3 = 0;

  TGraph * gr4 = new TGraph();
  gr4->SetMarkerStyle(21);
  int nPoints4 = 0;

  TGraph * gr5 = new TGraph();
  gr5->SetMarkerStyle(21);
  int nPoints5 = 0;

  while (M1[nPoints1].bath!=-999.0) {
    gr1->SetPoint(nPoints1, M1[nPoints1].ambient, M1[nPoints1].slope);
    nPoints1++;

    gr2->SetPoint(nPoints2, M1[nPoints2].bath, M1[nPoints2].ambient);
    nPoints2++;

    gr3->SetPoint(nPoints3, M1[nPoints3].bottom, M1[nPoints3].ambient);
    nPoints3++;

    gr4->SetPoint(nPoints4, M1[nPoints4].top, M1[nPoints4].ambient);
    nPoints4++;

    gr5->SetPoint(nPoints5, M1[nPoints5].top, M1[nPoints5].slope);
    nPoints5++;
  }

  TF1 * fit = new TF1("fit", myfunction, 5, 35, 2);
  fit->SetLineColor(2);

  gr3->Draw("AP");
  gr3->Fit(fit, "NR");
  fit->Draw("same");

  double Tbottom = fit->GetParameter(0) / (1.0 - fit->GetParameter(1));
  cout << Tbottom << endl;

  gr4->Draw("AP");
  gr4->Fit(fit, "NR");
  fit->Draw("same");

  double Ttop = fit->GetParameter(0) / (1.0 - fit->GetParameter(1));
  cout << Ttop << endl;

  gr5->Draw("AP");

  gr5->Fit(fit, "NR");
  fit->Draw("same");

  cout << fit->Eval(Tbottom) << endl;
  cout << fit->Eval(Ttop) << endl;
  cout << fit->Eval(Ttop + (Ttop-Tbottom)) << endl;
}
