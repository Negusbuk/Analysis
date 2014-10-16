struct Measurement {
  double irradiation;
  double delta;
  int sample;
  double impedance;
  double error;
};

Measurement MPC315[] = {
  {  0.0, -0.025, 1, 0.318, 0.204 },
  {  0.0, +0.025, 1, 0.393, 0.170 },
  {  1.0, -0.025, 1, 0.563, 0.206 },
  {  1.0,  0.000, 1, 0.457, 0.205 },
  {  1.0, +0.025, 1, 0.402, 0.216 },
  {  1.0, +0.0125, 2, 0.534, 0.171 },
  {  2.0, -0.025, 1, 0.860, 0.219 },
  {  2.0, +0.025, 2, 0.651, 0.172 },
  {  3.0, -0.025, 1, 0.457, 0.216 },
  {  3.0, +0.025, 2, 0.660, 0.217 },
  {  0.0,  0.000, 0, 0.264, 0.169 },
  { -1.0,  0, 0, 0, 0 }
};

Measurement T725[] = {
  {  0.0, -0.025, 1, 1.718, 0.226 },
  {  0.0, +0.025, 2, 1.648, 0.178 },
  {  1.0, +0.025, 1, 2.041, 0.229 },
  {  1.0, -0.025, 1, 2.071, 0.178 },
  {  1.0, +0.025, 2, 3.387, 0.190 },
  {  1.0, -0.025, 2, 3.212, 0.189 },
  {  2.0, -0.025, 1, 2.496, 0.232 },
  {  2.0, +0.025, 2, 2.821, 0.186 },
  {  3.0, -0.000, 1, 2.212, 0.230 },
  {  3.0, -0.025, 2, 2.434, 0.184 },
  {  3.0, +0.025, 2, 2.326, 0.183 },
  {  0.0,  0.000, 0, 0.560, 0.217 },
  { -1.0,  0, 0, 0, 0 }
};

Measurement T777[] = {
  {  0.0, -0.025, 1, 1.892, 0.228 },
  {  0.0, +0.025, 2, 1.863, 0.180 },
  {  1.0, -0.025, 1, 2.534, 0.233 },
  {  1.0, +0.025, 2, 2.859, 0.187 },
  {  2.0, -0.025, 1, 2.789, 0.235 },
  {  3.0, -0.025, 1, 2.709, 0.234 },
  {  0.0,  0.000, 0, 0.673, 0.172 },
  {  0.0, -0.125, 0, 0.771, 0.173 },
  { -1.0,  0, 0, 0, 0 }
};

Measurement T557[] = {
  {  0.0, -0.025, 1, 1.121, 0.221 },
  {  0.0, +0.025, 2, 1.232, 0.176 },
  {  1.0, -0.025, 1, 3.554, 0.241 },
  {  1.0, +0.025, 2, 2.680, 0.185 },
  {  2.0, -0.025, 1, 3.147, 0.237 },
  {  3.0, -0.025, 1, 2.596, 0.233 },
  {  0.0,  0.000, 0, 0.238, 0.214 },
  {  0.0, -0.125, 0, 0.246, 0.169 },
  { -1.0,  0, 0, 0, 0 }
};

void plot()
{
  int MPC315color = kBlack;
  int T725color = kRed+1;
  int T777color = kGreen+1;
  int T557color = kBlue-7;
  
  int sample0marker = 20;
  float sample0markersize = 1.2;
  int sample1marker = 21;
  float sample1markersize = 1.0;
  int sample2marker = 20;
  float sample2markersize = 1.0;
  int i;
  
  TGraphErrors * grMPC315_0 = new TGraphErrors();
  int nMPC315_0 = 0;
  grMPC315_0->SetMarkerSize(sample0markersize);
  grMPC315_0->SetMarkerStyle(sample0marker);
  grMPC315_0->SetMarkerColor(MPC315color);
  grMPC315_0->SetLineColor(MPC315color);
  TGraphErrors * grMPC315_1 = new TGraphErrors();
  int nMPC315_1 = 0;
  grMPC315_1->SetMarkerSize(sample1markersize);
  grMPC315_1->SetMarkerStyle(sample1marker);
  grMPC315_1->SetMarkerColor(MPC315color);
  grMPC315_1->SetLineColor(MPC315color);
  TGraphErrors * grMPC315_10 = new TGraphErrors();
  int nMPC315_10 = 0;
  grMPC315_10->SetMarkerSize(sample1markersize);
  grMPC315_10->SetMarkerStyle(sample1marker);
  grMPC315_10->SetMarkerColor(MPC315color);
  grMPC315_10->SetLineColor(MPC315color);
  TGraphErrors * grMPC315_2 = new TGraphErrors();
  int nMPC315_2 = 0;
  grMPC315_2->SetMarkerSize(sample2markersize);
  grMPC315_2->SetMarkerStyle(sample2marker);
  grMPC315_2->SetMarkerColor(MPC315color);
  grMPC315_2->SetLineColor(MPC315color);
  
  i = 0;
  while (MPC315[i].irradiation!=-1.0) {
    if (MPC315[i].sample==0) {
      grMPC315_0->SetPoint(nMPC315_0, MPC315[i].impedance, -0.1+MPC315[i].delta);
      grMPC315_0->SetPointError(nMPC315_0, MPC315[i].error, 0.0);
      nMPC315_0++;
    }
    if (MPC315[i].sample==1) {
      grMPC315_1->SetPoint(nMPC315_1, MPC315[i].irradiation+MPC315[i].delta, MPC315[i].impedance);
      grMPC315_1->SetPointError(nMPC315_1, 0.0, MPC315[i].error);
      nMPC315_1++;
    }
    if (MPC315[i].sample==1 && MPC315[i].irradiation==0.0) {
      grMPC315_10->SetPoint(nMPC315_10, MPC315[i].impedance, +0.1+MPC315[i].delta);
      grMPC315_10->SetPointError(nMPC315_10, MPC315[i].error, 0.0);
      nMPC315_10++;
    }
    if (MPC315[i].sample==2) {
      grMPC315_2->SetPoint(nMPC315_2, MPC315[i].irradiation+MPC315[i].delta, MPC315[i].impedance);
      grMPC315_2->SetPointError(nMPC315_2, 0.0, MPC315[i].error);
      nMPC315_2++;
    }
    i++;
  }

  TGraphErrors * grT725_0 = new TGraphErrors();
  int nT725_0 = 0;
  grT725_0->SetMarkerSize(sample0markersize);
  grT725_0->SetMarkerStyle(sample0marker);
  grT725_0->SetMarkerColor(T725color);
  grT725_0->SetLineColor(T725color);
  TGraphErrors * grT725_1 = new TGraphErrors();
  int nT725_1 = 0;
  grT725_1->SetMarkerSize(sample1markersize);
  grT725_1->SetMarkerStyle(sample1marker);
  grT725_1->SetMarkerColor(T725color);
  grT725_1->SetLineColor(T725color);
  TGraphErrors * grT725_10 = new TGraphErrors();
  int nT725_10 = 0;
  grT725_10->SetMarkerSize(sample1markersize);
  grT725_10->SetMarkerStyle(sample1marker);
  grT725_10->SetMarkerColor(T725color);
  grT725_10->SetLineColor(T725color);
  TGraphErrors * grT725_2 = new TGraphErrors();
  int nT725_2 = 0;
  grT725_2->SetMarkerSize(sample2markersize);
  grT725_2->SetMarkerStyle(sample2marker);
  grT725_2->SetMarkerColor(T725color);
  grT725_2->SetLineColor(T725color);
  
  i = 0;
  while (T725[i].irradiation!=-1.0) {
    if (T725[i].sample==0) {
      grT725_0->SetPoint(nT725_0, T725[i].impedance, 1.0-0.1+T725[i].delta);
      grT725_0->SetPointError(nT725_0, T725[i].error, 0.0);
      nT725_0++;
    }
    if (T725[i].sample==1) {
      grT725_1->SetPoint(nT725_1, T725[i].irradiation+T725[i].delta, T725[i].impedance);
      grT725_1->SetPointError(nT725_1, 0.0, T725[i].error);
      nT725_1++;
    }
    if (T725[i].sample==1 && T725[i].irradiation==0.0) {
      grT725_10->SetPoint(nT725_10, T725[i].impedance, 1.0+0.1+T725[i].delta);
      grT725_10->SetPointError(nT725_10, T725[i].error, 0.0);
      nT725_10++;
    }
    if (T725[i].sample==2) {
      grT725_2->SetPoint(nT725_2, T725[i].irradiation+T725[i].delta, T725[i].impedance);
      grT725_2->SetPointError(nT725_2, 0.0, T725[i].error);
      nT725_2++;
    }
    i++;
  }

  TGraphErrors * grT777_0 = new TGraphErrors();
  int nT777_0 = 0;
  grT777_0->SetMarkerSize(sample0markersize);
  grT777_0->SetMarkerStyle(sample0marker);
  grT777_0->SetMarkerColor(T777color);
  grT777_0->SetLineColor(T777color);
  TGraphErrors * grT777_1 = new TGraphErrors();
  int nT777_1 = 0;
  grT777_1->SetMarkerSize(sample1markersize);
  grT777_1->SetMarkerStyle(sample1marker);
  grT777_1->SetMarkerColor(T777color);
  grT777_1->SetLineColor(T777color);
  TGraphErrors * grT777_10 = new TGraphErrors();
  int nT777_10 = 0;
  grT777_10->SetMarkerSize(sample1markersize);
  grT777_10->SetMarkerStyle(sample1marker);
  grT777_10->SetMarkerColor(T777color);
  grT777_10->SetLineColor(T777color);
  TGraphErrors * grT777_2 = new TGraphErrors();
  int nT777_2 = 0;
  grT777_2->SetMarkerSize(sample2markersize);
  grT777_2->SetMarkerStyle(sample2marker);
  grT777_2->SetMarkerColor(T777color);
  grT777_2->SetLineColor(T777color);
  
  i = 0;
  while (T777[i].irradiation!=-1.0) {
    if (T777[i].sample==0) {
      grT777_0->SetPoint(nT777_0, T777[i].impedance, 2.0-0.1+T777[i].delta);
      grT777_0->SetPointError(nT777_0, T777[i].error, 0.0);
      nT777_0++;
    }
    if (T777[i].sample==1) {
      grT777_1->SetPoint(nT777_1, T777[i].irradiation+T777[i].delta, T777[i].impedance);
      grT777_1->SetPointError(nT777_1, 0.0, T777[i].error);
      nT777_1++;
    }
    if (T777[i].sample==1 && T777[i].irradiation==0.0) {
      grT777_10->SetPoint(nT777_10, T777[i].impedance, 2.0+0.1+T777[i].delta);
      grT777_10->SetPointError(nT777_10, T777[i].error, 0.0);
      nT777_10++;
    }
    if (T777[i].sample==2) {
      grT777_2->SetPoint(nT777_2, T777[i].irradiation+T777[i].delta, T777[i].impedance);
      grT777_2->SetPointError(nT777_2, 0.0, T777[i].error);
      nT777_2++;
    }
    i++;
  }
  
  TGraphErrors * grT557_0 = new TGraphErrors();
  int nT557_0 = 0;
  grT557_0->SetMarkerSize(sample0markersize);
  grT557_0->SetMarkerStyle(sample0marker);
  grT557_0->SetMarkerColor(T557color);
  grT557_0->SetLineColor(T557color);
  TGraphErrors * grT557_1 = new TGraphErrors();
  int nT557_1 = 0;
  grT557_1->SetMarkerSize(sample1markersize);
  grT557_1->SetMarkerStyle(sample1marker);
  grT557_1->SetMarkerColor(T557color);
  grT557_1->SetLineColor(T557color);
  TGraphErrors * grT557_10 = new TGraphErrors();
  int nT557_10 = 0;
  grT557_10->SetMarkerSize(sample1markersize);
  grT557_10->SetMarkerStyle(sample1marker);
  grT557_10->SetMarkerColor(T557color);
  grT557_10->SetLineColor(T557color);
  TGraphErrors * grT557_2 = new TGraphErrors();
  int nT557_2 = 0;
  grT557_2->SetMarkerSize(sample2markersize);
  grT557_2->SetMarkerStyle(sample2marker);
  grT557_2->SetMarkerColor(T557color);
  grT557_2->SetLineColor(T557color);
  
  i = 0;
  while (T557[i].irradiation!=-1.0) {
    if (T557[i].sample==0) {
      grT557_0->SetPoint(nT557_0, T557[i].impedance, 3.0-0.1+T557[i].delta);
      grT557_0->SetPointError(nT557_0, T557[i].error, 0.0);
      nT557_0++;
    }
    if (T557[i].sample==1) {
      grT557_1->SetPoint(nT557_1, T557[i].irradiation+T557[i].delta, T557[i].impedance);
      grT557_1->SetPointError(nT557_1, 0.0, T557[i].error);
      nT557_1++;
    }
    if (T557[i].sample==1 && T557[i].irradiation==0.0) {
      grT557_10->SetPoint(nT557_10, T557[i].impedance, 3.0+0.1+T557[i].delta);
      grT557_10->SetPointError(nT557_10, T557[i].error, 0.0);
      nT557_10++;
    }
    if (T557[i].sample==2) {
      grT557_2->SetPoint(nT557_2, T557[i].irradiation+T557[i].delta, T557[i].impedance);
      grT557_2->SetPointError(nT557_2, 0.0, T557[i].error);
      nT557_2++;
    }
    i++;
  }

  TCanvas * c= new TCanvas("c", "c", 700, 500);
  c->SetGridx(false);
  c->SetGridy(true);
  TH1F * frame = c->DrawFrame(-0.5, 0.0, 3.5, 4.0);
  frame->GetXaxis()->SetNdivisions(505);
  frame->GetXaxis()->SetTickLength(0);
  frame->GetXaxis()->SetTitle("irradiation [MGy]");
  frame->GetYaxis()->SetTitle("thermal impedance [K cm^2/W]");
  
  grMPC315_1->Draw("P");
  grMPC315_2->Draw("P");
  
  grT725_1->Draw("P");
  grT725_2->Draw("P");

  grT777_1->Draw("P");
  grT777_2->Draw("P");

    grT557_1->Draw("P");
    grT557_2->Draw("P");
  /*
  */
  
  //return;

  int specMarkerStyle = 4;
  float specMarkerSize = 1.2;
  TGraph * grMPC315specs = new TGraph();
  grMPC315specs->SetMarkerSize(specMarkerSize);
  grMPC315specs->SetMarkerStyle(specMarkerStyle);
  grMPC315specs->SetMarkerColor(MPC315color);
  grMPC315specs->SetPoint(0, 0.208, 0);
  TGraph * grT725specs = new TGraph();
  grT725specs->SetMarkerStyle(specMarkerStyle);
  grT725specs->SetMarkerSize(specMarkerSize);
  grT725specs->SetMarkerColor(T725color);
  grT725specs->SetPoint(0, 0.710, 1);
  TGraph * grT777specs = new TGraph();
  grT777specs->SetMarkerStyle(specMarkerStyle);
  grT777specs->SetMarkerSize(specMarkerSize);
  grT777specs->SetMarkerColor(T777color);
  grT777specs->SetPoint(0, 0.130, 2);
  TGraph * grT557specs = new TGraph();
  grT557specs->SetMarkerStyle(specMarkerStyle);
  grT557specs->SetMarkerSize(specMarkerSize);
  grT557specs->SetMarkerColor(T557color);
  grT557specs->SetPoint(0, 0.130, 3);
  
  c->Clear();
  c->SetGridx(true);
  c->SetGridy(false);
  TH1F * frame = c->DrawFrame(-0.1, -0.5, 2.4, 3.5);
  frame->GetXaxis()->SetNdivisions(520);
  frame->GetXaxis()->SetTitle("thermal impedance [K cm^2/W]");
  frame->GetYaxis()->Set(4, -0.5, 3.5);
  frame->GetYaxis()->SetLabelSize(0.05);
  frame->GetYaxis()->SetBinLabel(1, "MPC315");
  frame->GetYaxis()->SetBinLabel(2, "T725");
  frame->GetYaxis()->SetBinLabel(3, "T777");
  frame->GetYaxis()->SetBinLabel(4, "T557");
  frame->GetYaxis()->SetTickLength(0);
  
  grMPC315specs->Draw("P");
  grT725specs->Draw("P");
  grT777specs->Draw("P");
  grT557specs->Draw("P");

  grMPC315_0->Draw("P");
  grT725_0->Draw("P");
  grT777_0->Draw("P");
  grT557_0->Draw("P");

  grMPC315_10->Draw("P");
  grT725_10->Draw("P");
  grT777_10->Draw("P");
  grT557_10->Draw("P");

  TLine * line = new TLine(-0.1, 0.5, 2.4, 0.5);
  line->Draw();
  TLine * line = new TLine(-0.1, 1.5, 2.4, 1.5);
  line->Draw();
  TLine * line = new TLine(-0.1, 2.5, 2.4, 2.5);
  line->Draw();

  TLegend * legend = new TLegend(0.5, 0.15, 0.875, 0.275);
  legend->AddEntry(grMPC315specs, "specs", "P");
  legend->AddEntry(grMPC315_0, "measured (10 psi)", "P");
  legend->AddEntry(grMPC315_10, "measured (0 psi)", "P");
  legend->Draw();
  
  c->Print("TIM_0MGy_Comparison.pdf");
}
