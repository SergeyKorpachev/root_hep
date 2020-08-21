void code_final() {
  const float maxx = 34.0;
  const float minx = 1.0;
  const float stepx = 1.5;
  const float NUM_BIN_X = (maxx - minx)/stepx + 1;
  const float NUM_BIN_Y = (maxx - minx)/stepx + 1;
  const float X_LOW = minx - stepx*0.5;
  const float X_UP = X_LOW + NUM_BIN_X*stepx;
  const float Y_LOW = minx - stepx*0.5;
  const float Y_UP = X_LOW + NUM_BIN_X*stepx;
  const char *FNAME_X = "x.txt";
  const char *FNAME_Y = "y.txt";
  const char *FNAME_AMP = "mean.txt";  //  mean.txt, evcut.txt, evtot.txt, chi2.txt
   
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);

  float x, y, amp;
  TH2F *hist;
  FILE *file_x = fopen(FNAME_X, "r");
  FILE *file_y = fopen(FNAME_Y, "r");
  FILE *file_amp = fopen(FNAME_AMP, "r");  
  
  if (!((long)file_x * (long)file_y * (long)file_amp)) return;

// N events above pedestal (200.000000 ADC)
// Chi2/NDF
// Total number of events 
// MPV

  hist = new TH2F("MPV", "MPV", NUM_BIN_X, X_LOW, X_UP, NUM_BIN_Y, Y_LOW, Y_UP);
  while(1) {
    fscanf(file_x, "%f,", &x);
    fscanf(file_y, "%f,", &y);
    fscanf(file_amp, "%f,", &amp);
    if (feof(file_x) || feof(file_y) || feof(file_amp)) break;

    printf("%f %f %f\n", x, y, amp);

    hist->Fill(x, y, amp);
  }
  hist->GetXaxis()->SetTitle("x, mm ");
  hist->GetYaxis()->SetTitle("y, mm ");
  //hist->GetZaxis()->SetTitle("Mean of p.e.");

  gStyle->SetOptStat(0);

  hist->Draw("colz");
 
//  c1->SaveAs("final.jpg");
  
}
