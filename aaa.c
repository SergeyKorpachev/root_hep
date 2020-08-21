void aaa() {
  const float NUM_BIN_X = 25;
  const float NUM_BIN_Y = 100;
  const float X_LOW = -5;
  const float X_UP = 5;
  const float Y_LOW = -1000;
  const float Y_UP = 1000;  
   
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);

  float x, y;
  TH2F *hist;
  FILE *file_x = fopen("out_chi22_second.txt", "r");
  FILE *file_y = fopen("out.txt", "r");

  if (!((long)file_x * (long)file_y)) return;
  
  hist = new TH2F("mean & chi2", "mean & chi2", NUM_BIN_Y, Y_LOW, Y_UP, NUM_BIN_X, X_LOW, X_UP);
  while(1) {
    fscanf(file_x, "%E", &x);
    fscanf(file_y, "%E", &y);
    if (feof(file_x) || feof(file_y)) break;

    printf("!!!!!%E %E\n", x, y);

    hist->Fill(y, x);
  }
  hist->GetXaxis()->SetTitle("mean");
  hist->GetYaxis()->SetTitle("chi2");
  //hist->GetZaxis()->SetTitle("Mean of p.e.");

  //gStyle->SetOptStat(0);

  hist->Draw();
 
  c1->SaveAs("final.jpg");
  
}
