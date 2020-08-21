void pict() {
  const float maxx = 34.0;
  const float minx = 1.0;
  const float stepx = 1.5;
  const float NUM_BIN_X = (maxx - minx)/stepx + 1;
  const float NUM_BIN_Y = (maxx - minx)/stepx + 1;
  const float X_LOW = minx - stepx*0.5;
  const float X_UP = X_LOW + NUM_BIN_X*stepx;
  const float Y_LOW = minx - stepx*0.5;
  const float Y_UP = X_LOW + NUM_BIN_X*stepx;
  const char *FNAME_X = "coords.txt";
  const char *FNAME_AMP = "out.txt";
   
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);
  TCanvas *c2 = new TCanvas("c2", "c2", 600, 600);
 
  TH1F* uniformity = new TH1F("Uniformity", "Uniformity", 100, 0, 100);

  float x, y, amp;
  TH2F *hist;
  TH2F *hist2;
  FILE *file_x = fopen(FNAME_X, "r");
  FILE *file_amp = fopen(FNAME_AMP, "r");  
  
  if (!((long)file_x * (long)file_amp)) return;

  hist = new TH2F("MPV", "MPV", 20, -15.0, 15.0, 20, -15.0, 15.0);
  hist2 = new TH2F("Chi2", "Chi2", 20, -15.0, 15.0, 20, -15.0, 15.0);
//  hist->GetZaxis()->SetRangeUser(18,32);
  hist->GetZaxis()->SetRangeUser(10,50);
  while(1) {
    fscanf(file_x, "%f %f", &x, &y);
    float t1 = 0.0;
    float t2 = 0.0;
    fscanf(file_amp, "%f %f %f", &amp, &t1, &t2);
    if (feof(file_x) || feof(file_amp)) break;

    printf("%f %f %f\n", x, y, amp);

    hist->Fill(x, y, amp);
    if ( amp > 0 ) uniformity->Fill( amp );
    hist2->Fill(x, y, t2);
  }
 
  float mean_uniformity = uniformity->GetMean();
  float rms_uniformity = uniformity->GetRMS();
  printf("Uniformity === %f / %f === %f\n", rms_uniformity, mean_uniformity, rms_uniformity / mean_uniformity );
  printf("Number of values === %f\n", float( uniformity->GetEntries() ) );
  printf("N overflow === %f\n", float ( uniformity->GetBinContent(101) ) );


  c1->cd();
 
  char stitle[50];  

  hist->GetXaxis()->SetTitle("x, mm ");
  hist->GetYaxis()->SetTitle("y, mm ");
  float uni = 1 - ( rms_uniformity / mean_uniformity );
  uni = uni * 100;
  sprintf(stitle,"U = %3.0f %%  mean = %3.1f p.e.              MPV[p.e.]", round( uni ), mean_uniformity);
  hist->SetTitle(stitle);
  sprintf(stitle,"U = %3.0f %%  mean = %3.1f p.e.              #chi^{2}/NDF", round( uni ), mean_uniformity);
  hist2->SetTitle(stitle);
//  hist->GetZaxis()->SetTitle("Mean of p.e.");


//------------------------------------------------------------------------------------------------------------------------

  const double RELQE = 0.1;
  double dmeanMPV = uniformity->GetMeanError()/mean_uniformity;
  double drmsMPV = uniformity->GetRMSError()/rms_uniformity;
  double suMPV = uni*sqrt(dmeanMPV*dmeanMPV + drmsMPV*drmsMPV);
  double speMPV = mean_uniformity*sqrt(dmeanMPV*dmeanMPV + RELQE*RELQE);
  printf("Uniformity === 1 - %f / %f === %f +- %f (%f%% from rms)\n",rms_uniformity, mean_uniformity, uni, suMPV, 100*drmsMPV);
  printf("<p.e.> = %f +- %f (%f%% from mean)\n", mean_uniformity, speMPV, 100*dmeanMPV);

//------------------------------------------------------------------------------------------------------------------------


  gStyle->SetOptStat(0);

  hist->Draw("colz");

//  uniformity->Draw();

  c2->cd();
  
  hist2->GetXaxis()->SetTitle("x, mm ");
  hist2->GetYaxis()->SetTitle("y, mm ");

  hist2->Draw("colz");
 
//  c1->SaveAs("final.jpg");
  
}
