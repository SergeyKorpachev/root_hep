void final() {
  const float NUM_BIN_X = 3;
  const float NUM_BIN_Z = 3;
  const float X_LOW = 0.0;
  const float X_UP = 65.0;
  const float Z_LOW = 1.0;
  const float Z_UP = -1.0;  
  const char *AMP = "out_nodigi.txt";
  const char *AMP2 = "out_digi.txt";
   
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);

  int count = 1;

  int energy = 0;

  float mean, sigma, mean2, sigma2;
  TH2F *hist, *hist2;
  FILE *file = fopen(AMP, "r");
  FILE *file2 = fopen(AMP2, "r");
  
  if ( !(long)file ) return;
  if ( !(long)file2 ) return;
  
  hist = new TH2F("Relative_resolution", "Relative_resolution", NUM_BIN_X, X_LOW, X_UP, NUM_BIN_Z, Z_LOW, Z_UP);
  hist2 = new TH2F("Relative_resolution", "Relative_resolution", NUM_BIN_X, X_LOW, X_UP, NUM_BIN_Z, Z_LOW, Z_UP);
  while(1) {
  
    if ( count > 9 ) break;
  
    fscanf(file, "%f %f", &mean, &sigma);
    fscanf(file2, "%f %f", &mean2, &sigma2);

    if ( feof( file ) ) break;
    if ( feof( file2 ) ) break;

    if ( count == 1 ) energy = 5;
    if ( count == 2 ) energy = 10;
    if ( count == 3 ) energy = 15;
    if ( count == 4 ) energy = 20;
    if ( count == 5 ) energy = 25;
    if ( count == 6 ) energy = 30;
    if ( count == 7 ) energy = 40;
    if ( count == 8 ) energy = 50;
    if ( count == 9 ) energy = 60;

    hist->Fill( energy, sigma / mean );
    hist2->Fill( energy, sigma2 / mean2 );

    cout << "energy == " << energy << " and sigma / mean === " << sigma / mean << endl; 
    cout << "energy == " << energy << " and sigma2 / mean2 === " << sigma2 / mean2 << endl; 
    
    count++;
  }
  hist->GetXaxis()->SetTitle("");
  hist->GetYaxis()->SetTitle("Relative resolution");
  hist->GetZaxis()->SetTitle("Beam energy, GeV");
  hist->SetMarkerStyle(20);
  hist->SetMarkerColor(kRed);
//  hist->DrawCopy("p e");

  hist2->GetXaxis()->SetTitle("");
  hist2->GetYaxis()->SetTitle("Relative resolution");
  hist2->GetZaxis()->SetTitle("Beam energy, GeV");
  hist2->SetMarkerStyle(20);
  hist2->SetMarkerColor(kBlue);
//  hist2->DrawCopy("p e");

  gStyle->SetOptStat(0);

  hist->Draw();
  hist2->Draw("SAME");
//  float aaa = hist->GetRMS(3);
//  printf("aaa === %f\n", aaa );
 
 // c1->SaveAs("flat.jpg");
  
}
