void MPV() {
  const float NUM_BIN_X = 10;
  const float NUM_BIN_Z = 10;
  const float X_LOW = 0;
  const float X_UP = 20;
  const float Z_LOW = 0;
  const float Z_UP = 20;  
  const char *FNAME_X = "x-full.txt";
  const char *FNAME_Z = "z-full.txt";
  const char *FNAME_AMP = "amp-full.txt"; // amp
   
 // TCanvas *c1 = new TCanvas("c1", "c1", 1);

  float x, z, amp;
  TH2F *hist;
  FILE *file_x = fopen(FNAME_X, "r");
  FILE *file_z = fopen(FNAME_Z, "r");
  FILE *file_amp = fopen(FNAME_AMP, "r");  
  
  if (!((long)file_x * (long)file_z * (long)file_amp)) return;
  
  hist = new TH2F("MPV", "MPV", NUM_BIN_X, X_LOW, X_UP, NUM_BIN_Z, Z_LOW, Z_UP);
  while(1) {
    fscanf(file_x, "%f,", &x);
    fscanf(file_z, "%f,", &z);
    fscanf(file_amp, "%f,", &amp);
    if (feof(file_x) || feof(file_z) || feof(file_amp)) break;

    hist->Fill(x, z, amp);
  }
  hist->GetXaxis()->SetTitle("z, mm ");
  hist->GetYaxis()->SetTitle("x, mm ");
  hist->GetZaxis()->SetTitle("MPV light yield");

  gStyle->SetOptStat(0);

  hist->Draw("colz");
 
 // c1->SaveAs("dimple.jpg");
  
}
