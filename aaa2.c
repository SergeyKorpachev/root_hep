void aaa2() {
  const float NUM_BIN_X = 25;
  const float NUM_BIN_Y = 25;
  const float X_LOW = 0;
  const float X_UP = 37;
  const float Y_LOW = 0;
  const float Y_UP = 37;  
  const char *FNAME_X = "/home/root1/processing/out_chi22_second.txt.txt";
  const char *FNAME_Y = "/home/root1/processing/out.txt";
   
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);

  float x, y;
  TH2F *hist;
  FILE *file_x = fopen(FNAME_X, "r");
  FILE *file_y = fopen(FNAME_Y, "r");
  
  if (!((long)file_x * (long)file_y)) return;
  
  hist = new TH2F("mean & chi2", "mean & chi2", NUM_BIN_X, X_LOW, X_UP, NUM_BIN_Y, Y_LOW, Y_UP);
  while(1) {
    fscanf(file_x, "%f,", &x);
    fscanf(file_y, "%f,", &y);
    if (feof(file_x) || feof(file_y)) break;

    printf("!!!!!!!!!!!!!!!!!!!!!\n");
    printf("!!!!!%f %f\n", x, y);

    hist->Fill(x, y);
  }
  hist->GetXaxis()->SetTitle("chi2");
  hist->GetYaxis()->SetTitle("mean");
  //hist->GetZaxis()->SetTitle("Mean of p.e.");

  //gStyle->SetOptStat(0);

  hist->Draw();
 
  c1->SaveAs("final.jpg");
  
}
