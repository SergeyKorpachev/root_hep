
void temp() {
//  float maxx = 31.0;
//  float minx = 1.0;
//  float stepx = 1.5;
//  int nh = (maxx - minx)/stepx + 1;
//  int nh = 20;
//  float minh = minx - stepx*0.5;
//  float maxh = minh + nh*stepx;
  const char *FNAME_X = "out1.txt";
   
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);

  float x;
  TH1F *hist;
  FILE *file_x = fopen(FNAME_X, "r");
  
  if ( !(long)file_x ) return;
  
  hist = new TH1F("MPV", "MPV", 100, 0, 1000);
  while(1) {
    fscanf(file_x, "%f,", &x);
    if ( feof(file_x) ) break;

    hist->Fill( x );
    printf( "values === %f\n", x );
  }
  hist->GetXaxis()->SetTitle("mpv values");

  gStyle->SetOptStat("eMR");

  hist->Draw();
  float mean = hist->GetMean();
  float rms = hist->GetRMS();
  printf("uniformity === %f\n", rms / mean );
  
}


