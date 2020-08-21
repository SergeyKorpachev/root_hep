void final() {
  const float NUM_BIN_X = 25;
  const float NUM_BIN_Y = 25;
  const float X_LOW = 0;
  const float X_UP = 37;
  const float Y_LOW = 0;
  const float Y_UP = 37;  
  const char *FNAME_X = "x_scan3.txt";
  const char *FNAME_Y = "y_scan3.txt";
  const char *FNAME_AMP = "out_scan3_plus.txt";
   
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);

  float x, y, amp;
  TH2F *hist;
  FILE *file_x = fopen(FNAME_X, "r");
  FILE *file_y = fopen(FNAME_Y, "r");
  FILE *file_amp = fopen(FNAME_AMP, "r");  
  
  if (!((long)file_x * (long)file_y * (long)file_amp)) return;
  
  hist = new TH2F("Mean of p.e.", "Mean of p.e.", NUM_BIN_X, X_LOW, X_UP, NUM_BIN_Y, Y_LOW, Y_UP);
  while(1) {
    fscanf(file_x, "%f,", &x);
    fscanf(file_y, "%f,", &y);
    fscanf(file_amp, "%f,", &amp);
    if (feof(file_x) || feof(file_y) || feof(file_amp)) break;

    printf("%f %f %f\n", x, y, amp);

    hist->Fill(x, y, (amp / 10.0));
  }
  hist->GetXaxis()->SetTitle("x, mm ");
  hist->GetYaxis()->SetTitle("y, mm ");
  //hist->GetZaxis()->SetTitle("Mean of p.e.");

  gStyle->SetOptStat(0);

  hist->Draw("colz");
 
  c1->SaveAs("final.jpg");
  
}
