struct Measurement {
  double irradiation;
  double delta;
  int sample;
  double impedance;
  double error;
};

Measurement MPC315[] = {
  { +0.0, -0.0350,  1, 0.274, 0.190 },
  { +0.0, +0.0350,  1, 0.415, 0.201 },
  { +1.0, -0.0250,  1, 0.590, 0.208 },
  { +1.0, +0.0000,  1, 0.513, 0.203 },
  { +1.0, +0.0250,  1, 0.409, 0.250 },
  { +1.0, +0.0125,  2, 0.517, 0.208 },
  { +2.0, -0.0250,  1, 0.844, 0.223 },
  { +2.0, +0.0250,  2, 0.676, 0.216 },
  { +3.0, -0.0250,  1, 0.555, 0.257 },
  { +3.0, +0.0250,  2, 0.758, 0.268 },
  { +0.0, +0.0000, 11, 0.306, 0.195 },
  { -1.0,  0, 0, 0, 0 }
};

Measurement T725[] = {
  { +0.0, -0.0250,  1, 1.811, 0.330 },
  { +0.0, +0.0250,  2, 1.695, 0.273 },
  { +1.0, -0.0250,  1, 2.120, 0.348 },
  { +1.0, +0.0250,  1, 2.174, 0.300 },
  { +1.0, -0.0250,  2, 3.444, 0.373 },
  { +1.0, +0.0000,  2, 3.218, 0.360 },
  { +1.0, +0.0250,  2, 3.365, 0.368 },
  { +2.0, -0.0250,  1, 2.579, 0.375 },
  { +2.0, +0.0250,  1, 2.657, 0.328 },
  { +2.0, -0.0250,  2, 2.937, 0.343 },
  { +2.0, +0.0250,  2, 2.667, 0.328 },
  { +3.0, -0.0250,  1, 2.299, 0.358 },
  { +3.0, +0.0000,  2, 2.526, 0.320 },
  { +3.0, +0.0250,  2, 2.401, 0.313 },
  { +0.0, +0.0000, 11, 0.552, 0.258 },
  { -1.0,  0, 0, 0, 0 }
};

Measurement T777[] = {
  { +0.0, -0.0250,  1, 1.928, 0.337 },
  { +0.0, +0.0250,  2, 1.889, 0.285 },
  { +1.0, -0.0250,  1, 2.697, 0.382 },
  { +1.0, +0.0250,  1, 2.669, 0.329 },
  { +1.0, +0.0000,  2, 2.921, 0.343 },
  { +2.0, -0.0250,  1, 2.875, 0.392 },
  { +2.0, +0.0250,  2, 3.159, 0.356 },
  { +3.0, -0.0250,  1, 2.879, 0.392 },
  { +3.0, +0.0250,  2, 3.013, 0.348 },
  { +0.0, +0.0000, 11, 0.731, 0.219 },
  { +0.0, -0.1250, 11, 0.796, 0.223 },
  { +0.0, +0.0000, 12, 0.151, 0.187 },
  { -1.0,  0, 0, 0, 0 }
};

Measurement T557[] = {
  { +0.0, -0.0250,  1, 1.466, 0.315 },
  { +0.0, +0.0250,  2, 1.303, 0.251 },
  { +1.0, -0.0250,  1, 3.638, 0.406 },
  { +1.0, +0.0250,  1, 3.590, 0.381 },
  { +1.0, -0.0250,  2, 2.747, 0.333 },
  { +1.0, +0.0250,  2, 2.673, 0.329 },
  { +2.0, -0.0250,  1, 3.165, 0.409 },
  { +2.0, +0.0250,  1, 2.954, 0.344 },
  { +2.0, -0.0250,  2, 2.683, 0.329 },
  { +2.0, +0.0250,  2, 2.509, 0.320 },
  { +3.0, -0.0250,  1, 2.640, 0.378 },
  { +3.0, +0.0250,  1, 2.878, 0.340 },
  { +3.0, +0.0000,  2, 3.150, 0.356 },
  { +0.0, +0.0000, 11, 0.278, 0.242 },
  { +0.0, -0.1250, 11, 0.247, 0.192 },
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
  
  TGraphErrors * grMPC315_11 = new TGraphErrors();
  int nMPC315_11 = 0;
  grMPC315_11->SetMarkerSize(sample0markersize);
  grMPC315_11->SetMarkerStyle(sample0marker);
  grMPC315_11->SetMarkerColor(MPC315color);
  grMPC315_11->SetLineColor(MPC315color);
  TGraphErrors * grMPC315_1 = new TGraphErrors();
  int nMPC315_1 = 0;
  grMPC315_1->SetMarkerSize(sample1markersize);
  grMPC315_1->SetMarkerStyle(sample1marker);
  grMPC315_1->SetMarkerColor(MPC315color);
  grMPC315_1->SetLineColor(MPC315color);
  grMPC315_1->SetFillColor(MPC315color);
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
    if (MPC315[i].sample==11) {
      grMPC315_11->SetPoint(nMPC315_11, MPC315[i].impedance, -0.1+MPC315[i].delta);
      grMPC315_11->SetPointError(nMPC315_11, MPC315[i].error, 0.0);
      nMPC315_11++;
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

  TGraphErrors * grT725_11 = new TGraphErrors();
  int nT725_11 = 0;
  grT725_11->SetMarkerSize(sample0markersize);
  grT725_11->SetMarkerStyle(sample0marker);
  grT725_11->SetMarkerColor(T725color);
  grT725_11->SetLineColor(T725color);
  TGraphErrors * grT725_1 = new TGraphErrors();
  int nT725_1 = 0;
  grT725_1->SetMarkerSize(sample1markersize);
  grT725_1->SetMarkerStyle(sample1marker);
  grT725_1->SetMarkerColor(T725color);
  grT725_1->SetLineColor(T725color);
  grT725_1->SetFillColor(T725color);
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
    if (T725[i].sample==11) {
      grT725_11->SetPoint(nT725_11, T725[i].impedance, 1.0-0.1+T725[i].delta);
      grT725_11->SetPointError(nT725_11, T725[i].error, 0.0);
      nT725_11++;
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

  TGraphErrors * grT777_11 = new TGraphErrors();
  int nT777_11 = 0;
  grT777_11->SetMarkerSize(sample0markersize);
  grT777_11->SetMarkerStyle(sample0marker);
  grT777_11->SetMarkerColor(T777color);
  grT777_11->SetLineColor(T777color);
  TGraphErrors * grT777_12 = new TGraphErrors();
  int nT777_12 = 0;
  grT777_12->SetMarkerSize(sample0markersize);
  grT777_12->SetMarkerStyle(sample0marker);
  grT777_12->SetMarkerColor(T777color+2);
  grT777_12->SetLineColor(T777color+2);
  TGraphErrors * grT777_1 = new TGraphErrors();
  int nT777_1 = 0;
  grT777_1->SetMarkerSize(sample1markersize);
  grT777_1->SetMarkerStyle(sample1marker);
  grT777_1->SetMarkerColor(T777color);
  grT777_1->SetLineColor(T777color);
  grT777_1->SetFillColor(T777color);
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
    if (T777[i].sample==11) {
      grT777_11->SetPoint(nT777_11, T777[i].impedance, 2.0-0.1+T777[i].delta);
      grT777_11->SetPointError(nT777_11, T777[i].error, 0.0);
      nT777_11++;
    }
    if (T777[i].sample==12) {
      grT777_12->SetPoint(nT777_12, T777[i].impedance, 2.0-0.1+T777[i].delta);
      grT777_12->SetPointError(nT777_12, T777[i].error, 0.0);
      nT777_12++;
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
  
  TGraphErrors * grT557_11 = new TGraphErrors();
  int nT557_11 = 0;
  grT557_11->SetMarkerSize(sample0markersize);
  grT557_11->SetMarkerStyle(sample0marker);
  grT557_11->SetMarkerColor(T557color);
  grT557_11->SetLineColor(T557color);
  TGraphErrors * grT557_1 = new TGraphErrors();
  int nT557_1 = 0;
  grT557_1->SetMarkerSize(sample1markersize);
  grT557_1->SetMarkerStyle(sample1marker);
  grT557_1->SetMarkerColor(T557color);
  grT557_1->SetLineColor(T557color);
  grT557_1->SetFillColor(T557color);
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
    if (T557[i].sample==11) {
      grT557_11->SetPoint(nT557_11, T557[i].impedance, 3.0-0.1+T557[i].delta);
      grT557_11->SetPointError(nT557_11, T557[i].error, 0.0);
      nT557_11++;
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

  double Rmax = 4.25;
  
  TCanvas * c= new TCanvas("c", "c", 700, 500);
  c->SetGridx(false);
  c->SetGridy(true);

  c->Clear();
  TH1F * frame = c->DrawFrame(-0.5, 0.0, 3.5, Rmax);
  frame->GetXaxis()->SetNdivisions(505);
  frame->GetXaxis()->SetTickLength(0);
  frame->GetXaxis()->SetTitle("irradiation [MGy]");
  frame->GetYaxis()->SetTitle("thermal impedance [K cm^2/W]");
  grMPC315_1->Draw("P");
  grMPC315_2->Draw("P");
  TLatex * latex = new TLatex(-0.25, 3.60, "MPC315");
  latex->Draw();
  c->Print("RvsDose_MPC325.pdf");

  c->Clear();
  TH1F * frame = c->DrawFrame(-0.5, 0.0, 3.5, Rmax);
  frame->GetXaxis()->SetNdivisions(505);
  frame->GetXaxis()->SetTickLength(0);
  frame->GetXaxis()->SetTitle("irradiation [MGy]");
  frame->GetYaxis()->SetTitle("thermal impedance [K cm^2/W]");
  grT725_1->Draw("P");
  grT725_2->Draw("P");
  TLatex * latex = new TLatex(-0.25, 3.60, "T725");
  latex->Draw();
  c->Print("RvsDose_T725.pdf");

  c->Clear();
  TH1F * frame = c->DrawFrame(-0.5, 0.0, 3.5, Rmax);
  frame->GetXaxis()->SetNdivisions(505);
  frame->GetXaxis()->SetTickLength(0);
  frame->GetXaxis()->SetTitle("irradiation [MGy]");
  frame->GetYaxis()->SetTitle("thermal impedance [K cm^2/W]");
  grT777_1->Draw("P");
  grT777_2->Draw("P");
  TLatex * latex = new TLatex(-0.25, 3.60, "T777");
  latex->Draw();
  c->Print("RvsDose_T7777.pdf");

  c->Clear();
  TH1F * frame = c->DrawFrame(-0.5, 0.0, 3.5, Rmax);
  frame->GetXaxis()->SetNdivisions(505);
  frame->GetXaxis()->SetTickLength(0);
  frame->GetXaxis()->SetTitle("irradiation [MGy]");
  frame->GetYaxis()->SetTitle("thermal impedance [K cm^2/W]");
  grT557_1->Draw("P");
  grT557_2->Draw("P");
  TLatex * latex = new TLatex(-0.25, 3.60, "T557");
  latex->Draw();
  c->Print("RvsDose_T557.pdf");

  c->Clear();
  TH1F * frame = c->DrawFrame(-0.5, 0.0, 3.5, Rmax);
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
  c->Print("RvsDoseNoLegend.pdf");
  TLegend * legend = new TLegend(0.15, 0.65, 0.3, 0.875);
  legend->AddEntry(grMPC315_1, "MPC315", "F");
  legend->AddEntry(grT725_1, "T725", "F");
  legend->AddEntry(grT777_1, "T777", "F");
  legend->AddEntry(grT557_1, "T557", "F");
  legend->Draw();
  c->Print("RvsDose.pdf");

  int specMarkerStyle = 4;
  float specMarkerSize = 1.2;
  TGraph * grMPC315specs = new TGraph();
  grMPC315specs->SetMarkerSize(specMarkerSize);
  grMPC315specs->SetMarkerStyle(specMarkerStyle);
  grMPC315specs->SetMarkerColor(MPC315color);
  grMPC315specs->SetPoint(0, 0.208, 0.25);
  TGraph * grT725specs = new TGraph();
  grT725specs->SetMarkerStyle(specMarkerStyle);
  grT725specs->SetMarkerSize(specMarkerSize);
  grT725specs->SetMarkerColor(T725color);
  grT725specs->SetPoint(0, 0.710, 1);
  TGraph * grT777specs = new TGraph();
  grT777specs->SetMarkerStyle(specMarkerStyle);
  grT777specs->SetMarkerSize(specMarkerSize);
  grT777specs->SetMarkerColor(T777color);
  grT777specs->SetPoint(0, 0.130, 2.1);
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

  grMPC315_11->Draw("P");
  grT725_11->Draw("P");
  grT777_11->Draw("P");
  grT777_12->Draw("P");
  grT557_11->Draw("P");

  TLine * line = new TLine(-0.1, 0.5, 2.4, 0.5);
  line->Draw();
  TLine * line = new TLine(-0.1, 1.5, 2.4, 1.5);
  line->Draw();
  TLine * line = new TLine(-0.1, 2.5, 2.4, 2.5);
  line->Draw();

  TLegend * legend = new TLegend(0.5, 0.15, 0.875, 0.275);
  legend->AddEntry(grMPC315specs, "specs", "P");
  legend->AddEntry(grMPC315_11, "measured (10 psi)", "P");
  legend->AddEntry(grMPC315_10, "measured (0 psi)", "P");
  legend->Draw();
  
  c->Print("TIM_Comparison_Specs.pdf");

  grMPC315_10->Draw("P");
  grT725_10->Draw("P");
  grT777_10->Draw("P");
  grT557_10->Draw("P");
  
  c->Print("TIM_Comparison.pdf");
}
