struct Data {
  double bath;
  double ambient;
  double bottom;
  double top;
  double slope;
};

Data M1[] = { {  }, // 20150215-1
              // { 15.2694, 23.6784, 23.5450, 27.7996, 0.0542167 }, // 20150215-1  1
              // { 17.5094, 23.8155, 25.3245, 28.8320, 0.0415029 }, // 20150215-1  2
              // { 20.0022, 24.0308, 27.2065, 29.9941, 0.0291696 }, // 20150215-1  3
              { 12.5031, 23.7709, 24.0098, 29.5339, 0.0571683 }, // 20150216-1  1
              { 14.9948, 23.9009, 25.9580, 30.9657, 0.0507901 }, // 20150216-1  2
              { 17.5056, 24.0684, 27.9194, 32.4062, 0.0443656 }, // 20150216-1  3
              { 19.9754, 24.2597, 29.9156, 33.8673, 0.0378457 }, // 20150216-1  4
              // { 19.9915, 21.9800, 21.9885, 25.1160, 0.0416423 }, // 20150219-1
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
    gr1->SetPoint(nPoints1, M1[nPoints1].bath, M1[nPoints1].slope);
    nPoints1++;

    gr2->SetPoint(nPoints2, M1[nPoints2].bath, M1[nPoints2].ambient);
    nPoints2++;

    gr3->SetPoint(nPoints3, M1[nPoints3].bath, M1[nPoints3].top);
    nPoints3++;

    gr4->SetPoint(nPoints4, M1[nPoints4].top, M1[nPoints4].ambient);
    nPoints4++;

    gr5->SetPoint(nPoints5, M1[nPoints5].top, M1[nPoints5].slope);
    nPoints5++;
  }

  gr5->Draw("AP");
}
