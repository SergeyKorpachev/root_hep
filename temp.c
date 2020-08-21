
void temp() {
  const float NUM_BIN_X = 10;
  const float NUM_BIN_Y = 10;
  const float X_LOW = -15.0;
  const float X_UP = 15.0;
  const float Y_LOW = -15.0;
  const float Y_UP = 15.0;  

  const char *FNAME = "out_mc_final.txt";
   
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);

  TH1F* uniformity = new TH1F("Uniformity", "Uniformity", 10, 0, 100);

  float x, y, z;
  TH2F *hist;
  FILE *file = fopen(FNAME, "r");
  
  if ( !(long)file ) return;
  
  hist = new TH2F("MPV", "MPV", NUM_BIN_X, X_LOW, X_UP, NUM_BIN_Y, Y_LOW, Y_UP);
  while(1) {
    fscanf(file, "%f %f %f", &x, &y, &z);
    if ( feof(file) ) break;

    hist->Fill( x, y, z );
    uniformity->Fill( z );
    printf("z === %f\n", z);
  }
  hist->GetXaxis()->SetTitle("x [mm]");
  hist->GetYaxis()->SetTitle("y [mm]");
  hist->GetZaxis()->SetTitle("MPV light yield");

  float mean_uniformity = uniformity->GetMean();
  float rms_uniformity = uniformity->GetRMS();
  printf("Uniformity === %f / %f === %f\n", rms_uniformity, mean_uniformity, rms_uniformity / mean_uniformity );
//  printf("Number of values === %f\n", float( uniformity->GetEntries() ) );
//  printf("N overflow === %f\n", float ( uniformity->GetBinContent(101) ) );

  gStyle->SetOptStat(0);

  hist->Draw("colz");
}


