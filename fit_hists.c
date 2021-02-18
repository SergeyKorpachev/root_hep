void f( TH1* h, float &value, float &a, float &b, int &l, int &r ) {
  cout << "Value === " << value << endl;
  cout << "Value / 100.0 === " << value / 100.0 << endl;
  TAxis* axis = h -> GetXaxis();
  Int_t nbins = axis -> GetNbins();
  Int_t imean = axis -> FindBin( h -> GetMean() );
  Double_t entries = ( value / 100.0 ) * ( h -> GetEntries() );
  Double_t w = h -> GetBinContent( imean );
  Double_t x = h -> GetBinCenter( imean );
  Double_t sumw = w;
  Double_t sumwx = w*x;
  Double_t sumwx2 = w*x*x;
  for ( Int_t i = 1; i < nbins; i++ ) {
    if ( i > 0 ) {
    w = h -> GetBinContent( imean - i );
    x = h -> GetBinCenter( imean - i );
    l = imean - i;
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( i <= nbins ) {
    w = h -> GetBinContent( imean + i );
    x = h -> GetBinCenter( imean + i );
    r = imean + i;
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( sumw > entries ) break;
  }
  x = sumwx / sumw;
  Double_t rms2 = TMath::Abs( ( sumwx2 / sumw ) - ( x * x ) );
  Double_t result = TMath::Sqrt( rms2 );
  printf( "RMS of central %0.f%% = %f, RMS total = %f, Mean of central %.f%% = %f, Mean total = %f\n", value, result, h -> GetRMS(), value, x, h -> GetMean() );
  a = x;
  b = result;
}

void fit_ann( const int fenergy = 5, const int nBins = 1000, const int nfile = 1 ) {

  char fname[ 200 ];
  char ftempname[ 200 ];
  char fname2[ 200 ];
  char fname3[ 200 ];
  char fname4[ 200 ];

  for ( int i = 0; i < 200; i++ ) fname[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) ftempname[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) fname2[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) fname3[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) fname4[ i ] = 0;

  sprintf( ftempname, "tree%d", fenergy );
  sprintf( fname, "ann%d", fenergy );

  TH1F *hist;
  //TH1F *hist90;
  //TH1F *hist95;
    
  TH1F *hist2;
  TH1F *hist3;
  TH1F *hist4;
  TH1F *hist5;
  TH1F *hist6;
  TH1F *hist7;

  TH1F *hist_mean;
  TH1F *hist_sigma;
  TH1F *hist_chi_full;
  TH1F *hist_chi;
  TH1F *hist_meanerror;
  TH1F *hist_sigmaerror;

  TCanvas *c1 = new TCanvas("c1", "c1", 1);
/*  TCanvas *c2 = new TCanvas("c2", "c2", 1);
  TCanvas *c3 = new TCanvas("c3", "c3", 1);
  TCanvas *c4 = new TCanvas("c4", "c4", 1);
    
  TCanvas *c5 = new TCanvas("c5", "c5", 1);
  TCanvas *c6 = new TCanvas("c6", "c6", 1);
  TCanvas *c7 = new TCanvas("c7", "c7", 1);
  TCanvas *c8 = new TCanvas("c8", "c8", 1);
  */
  gStyle->SetOptStat(0);

  const char *treeName = ftempname;
  const float binLo = 0.0;
  const float binHi = fenergy + 30.0;

  const int nBins_fit = 10;
  const float binHi_fit = ( binHi - fenergy ) / 2.0;
  const float binHi_fit_error = binHi_fit - 8.0;

  //
  // Open data file
  //

  sprintf( fname3, "./%d_ann.root", nfile );

  std::cout << "Trying to open data file... ";
  TFile *file = new TFile(fname3, "READ");
  if (!file) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Open file for output
  //

  sprintf( fname4, "%d_out_ann.txt", nfile );

   FILE *out = fopen(fname4, "a+");
       printf("File open... ");
       if (!out) {
          printf("[FAIL]\n");
          return;
       } else printf("[OK]\n");

  //
  // Setup a TTree
  //
  std::cout << "Setup a tree... ";
  TTree *tree = (TTree *)file->Get(treeName);
  if (!tree) {
    std::cout << "[FAIL]" << std::endl;
    file->Close();
    return;
  }
  std::cout << "[OK]" << std::endl;

  unsigned int nEvents = tree->GetEntries();

  //
  // Setup a branch
  //
  Float_t energy = 0;
  tree->SetBranchAddress(fname, &energy);

  //
  // Create a histogram and random generator
  //
  hist = new TH1F("hist", "hist", nBins, binLo, binHi);

  hist_mean = new TH1F("hist_mean", "hist_mean", nBins_fit, binLo, binHi);
  hist_sigma = new TH1F("hist_sigma", "hist_sigma", nBins_fit, binLo, binHi_fit);
  hist_chi_full = new TH1F("hist_chi_full", "hist_chi_full", nBins_fit, binLo, binHi_fit);
  hist_chi = new TH1F("hist_chi", "hist_chi", nBins_fit, binLo, binHi_fit);
  hist_meanerror = new TH1F("hist_meanerror", "hist_meanerror", nBins_fit, binLo, binHi_fit_error);
  hist_sigmaerror = new TH1F("hist_sigmaerror", "hist_sigmaerror", nBins_fit, binLo, binHi_fit_error);

  for ( int i = 0; i <nEvents; i++ ) {
    tree -> GetEntry(i);
    if ( energy > 0 ) hist -> Fill( energy );
  }
    
//  cout << "Underflow hist === " << hist->GetBinContent( 0 ) << endl;
//  cout << "Overflow hist === " << hist->GetBinContent( nBins + 1 ) << endl;

  float mean = hist -> GetMean();
  float meanerror = hist -> GetMeanError();
  float rms = hist -> GetRMS();
  float rmserror = hist -> GetRMSError();
  cout << " 0:"
    << "  Mean: " << mean
    << "  Mean error: " << meanerror
    << "  RMS: " << rms
    << "  RMS error: " << rmserror
    << endl;
    
/*  cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
  cout << "f2:" << endl;
  float res = 0.0;
  float reserror = 0.0;
  float sc = 0.0;
  float scerror = 0.0;
  bool pr = 1;
  f2( hist, res, reserror, sc, scerror, pr );
    
  cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
  cout << "f3:" << endl;
  f3( hist );
    
  cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
  cout << "f4:" << endl;
  float res4 = 0.0;
  float reserror4 = 0.0;
  bool fix4 = 1;
  bool pr4 = 1;
  f4( hist, res4, reserror4, fix4, pr4 );
*/
  cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;

  cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
  float value90 = 90.0;
  float mean90 = 0;
  float rms90 = 0;
  int left90 = 0;
  int right90 = 0;
  f( hist, value90, mean90, rms90, left90, right90 );
  cout << "mean90 = " << mean90 << " and rms90 = " << rms90 << endl;
  cout << "left90 = " << left90 << " and right90 = " << right90 << endl;
  cout << "Left value 90 = " << hist->GetBinCenter( left90 ) << " and right value 90 = " << hist->GetBinCenter( right90 ) << endl;
    
  float value95 = 95.0;
  float mean95 = 0;
  float rms95 = 0;
  int left95 = 0;
  int right95 = 0;
  f( hist, value95, mean95, rms95, left95, right95 );
  cout << "mean95 = " << mean95 << " and rms95 = " << rms95 << endl;
  cout << "left95 = " << left95 << " and right95 = " << right95 << endl;
  cout << "Left value 95 = " << hist->GetBinCenter( left95 ) << " and right value 95 = " << hist->GetBinCenter( right95 ) << endl;
    
  float value96 = 96.0;
  float mean96 = 0;
  float rms96 = 0;
  int left96 = 0;
  int right96 = 0;
  f( hist, value96, mean96, rms96, left96, right96 );
  cout << "mean96 = " << mean96 << " and rms96 = " << rms96 << endl;
  cout << "left96 = " << left96 << " and right96 = " << right96 << endl;
  cout << "Left value 96 = " << hist->GetBinCenter( left96 ) << " and right value 96 = " << hist->GetBinCenter( right96 ) << endl;
    
  float value97 = 97.0;
  float mean97 = 0;
  float rms97 = 0;
  int left97 = 0;
  int right97 = 0;
  f( hist, value97, mean97, rms97, left97, right97 );
  cout << "mean97 = " << mean97 << " and rms97 = " << rms97 << endl;
  cout << "left97 = " << left97 << " and right97 = " << right97 << endl;
  cout << "Left value 97 = " << hist->GetBinCenter( left97 ) << " and right value 97 = " << hist->GetBinCenter( right97 ) << endl;
    
  float value98 = 98.0;
  float mean98 = 0;
  float rms98 = 0;
  int left98 = 0;
  int right98 = 0;
  f( hist, value98, mean98, rms98, left98, right98 );
  cout << "mean98 = " << mean98 << " and rms98 = " << rms98 << endl;
  cout << "left98 = " << left98 << " and right98 = " << right98 << endl;
  cout << "Left value 98 = " << hist->GetBinCenter( left98 ) << " and right value 98 = " << hist->GetBinCenter( right98 ) << endl;
    
  float value99 = 99.0;
  float mean99 = 0;
  float rms99 = 0;
  int left99 = 0;
  int right99 = 0;
  f( hist, value99, mean99, rms99, left99, right99 );
  cout << "mean99 = " << mean99 << " and rms99 = " << rms99 << endl;
  cout << "left99 = " << left99 << " and right99 = " << right99 << endl;
  cout << "Left value 99 = " << hist->GetBinCenter( left99 ) << " and right value 99 = " << hist->GetBinCenter( right99 ) << endl;
  cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    
  //hist90 = new TH1F("hist90", "hist90", nBins, hist->GetBinCenter( left90 ), hist->GetBinCenter( right90 ));
  //hist95 = new TH1F("hist95", "hist95", nBins, hist->GetBinCenter( left95 ), hist->GetBinCenter( right95 ));
    
  /*for ( int i = 0; i <nEvents; i++ ) {
    tree -> GetEntry(i);
    if ( energy > 0 ) hist90 -> Fill( energy );
    if ( energy > 0 ) hist95 -> Fill( energy );
  }*/

  hist2 = (TH1F*)hist->Clone();
  hist3 = (TH1F*)hist->Clone();
  hist4 = (TH1F*)hist->Clone();
  hist5 = (TH1F*)hist->Clone();
  hist6 = (TH1F*)hist->Clone();
  hist7 = (TH1F*)hist->Clone();
    
  hist2->GetXaxis()->SetRange(left90, right90);
  hist3->GetXaxis()->SetRange(left95, right95);
  hist4->GetXaxis()->SetRange(left96, right96);
  hist5->GetXaxis()->SetRange(left97, right97);
  hist6->GetXaxis()->SetRange(left98, right98);
  hist7->GetXaxis()->SetRange(left99, right99);
        
  cout << "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ" << endl;
    
  cout << "Underflow hist2 === " << hist2->GetBinContent( 0 ) << endl;
  cout << "Overflow hist2 === " << hist2->GetBinContent( nBins + 1 ) << endl;
  float mean_hist2 = hist2 -> GetMean();
  float meanerror_hist2 = hist2 -> GetMeanError();
  float rms_hist2 = hist2 -> GetRMS();
  float rmserror_hist2 = hist2 -> GetRMSError();
  cout << " 0:"
    << "  Mean2: " << mean_hist2
    << "  Mean2 error: " << meanerror_hist2
    << "  RMS2: " << rms_hist2
    << "  RMS2 error: " << rmserror_hist2
    << endl;
    
  cout << "Underflow hist3 === " << hist3->GetBinContent( 0 ) << endl;
  cout << "Overflow hist3 === " << hist3->GetBinContent( nBins + 1 ) << endl;
  float mean_hist3 = hist3 -> GetMean();
  float meanerror_hist3 = hist3 -> GetMeanError();
  float rms_hist3 = hist3 -> GetRMS();
  float rmserror_hist3 = hist3 -> GetRMSError();
  cout << " 0:"
    << "  Mean3: " << mean_hist3
    << "  Mean3 error: " << meanerror_hist3
    << "  RMS3: " << rms_hist3
    << "  RMS3 error: " << rmserror_hist3
    << endl;
    
  cout << "Underflow hist4 === " << hist4->GetBinContent( 0 ) << endl;
  cout << "Overflow hist4 === " << hist4->GetBinContent( nBins + 1 ) << endl;
  float mean_hist4 = hist4 -> GetMean();
  float meanerror_hist4 = hist4 -> GetMeanError();
  float rms_hist4 = hist4 -> GetRMS();
  float rmserror_hist4 = hist4 -> GetRMSError();
  cout << " 0:"
    << "  Mean4: " << mean_hist4
    << "  Mean4 error: " << meanerror_hist4
    << "  RMS4: " << rms_hist4
    << "  RMS4 error: " << rmserror_hist4
    << endl;
  
  cout << "Underflow hist5 === " << hist5->GetBinContent( 0 ) << endl;
  cout << "Overflow hist5 === " << hist5->GetBinContent( nBins + 1 ) << endl;
  float mean_hist5 = hist5 -> GetMean();
  float meanerror_hist5 = hist5 -> GetMeanError();
  float rms_hist5 = hist5 -> GetRMS();
  float rmserror_hist5 = hist5 -> GetRMSError();
  cout << " 0:"
    << "  Mean5: " << mean_hist5
    << "  Mean5 error: " << meanerror_hist5
    << "  RMS5: " << rms_hist5
    << "  RMS5 error: " << rmserror_hist5
    << endl;
  
  cout << "Underflow hist6 === " << hist6->GetBinContent( 0 ) << endl;
  cout << "Overflow hist6 === " << hist6->GetBinContent( nBins + 1 ) << endl;
  float mean_hist6 = hist6 -> GetMean();
  float meanerror_hist6 = hist6 -> GetMeanError();
  float rms_hist6 = hist6 -> GetRMS();
  float rmserror_hist6 = hist6 -> GetRMSError();
  cout << " 0:"
    << "  Mean6: " << mean_hist6
    << "  Mean6 error: " << meanerror_hist6
    << "  RMS6: " << rms_hist6
    << "  RMS6 error: " << rmserror_hist6
    << endl;
  
  cout << "Underflow hist7 === " << hist7->GetBinContent( 0 ) << endl;
  cout << "Overflow hist7 === " << hist7->GetBinContent( nBins + 1 ) << endl;
  float mean_hist7 = hist7 -> GetMean();
  float meanerror_hist7 = hist7 -> GetMeanError();
  float rms_hist7 = hist7 -> GetRMS();
  float rmserror_hist7 = hist7 -> GetRMSError();
  cout << " 0:"
    << "  Mean7: " << mean_hist7
    << "  Mean7 error: " << meanerror_hist7
    << "  RMS7: " << rms_hist7
    << "  RMS7 error: " << rmserror_hist7
    << endl;
    
  cout << "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ" << endl;
  
  float step = 0.1;

  float mass_chi_full[ 20 ];
  for ( int i = 0; i < 20; i++ ) mass_chi_full[ i ] = 0;

  float mass_chi[ 20 ];
  for ( int i = 0; i < 20; i++ ) mass_chi[ i ] = 0;

  float mass_mean[ 20 ];
  for ( int i = 0; i < 20; i++ ) mass_mean[ i ] = 0;
  float mass_sigma[ 20 ];
  for ( int i = 0; i < 20; i++ ) mass_sigma[ i ] = 0;
  float mass_meanerror[ 20 ];
  for ( int i = 0; i < 20; i++ ) mass_meanerror[ i ] = 0;
  float mass_sigmaerror[ 20 ];
  for ( int i = 0; i < 20; i++ ) mass_sigmaerror[ i ] = 0;

  int i_const = 10;

  for ( int i = 10; i <= 25; i++ ) {
     
     cout << "i === " << i << endl;
     float range = i * step;

     TF1 *fitFunc = new TF1("fitFunc", "gaus", mean - range * rms, mean + range * rms);
     hist -> Fit( fitFunc, "R" );
     float fitmean = fitFunc -> GetParameter(1);
     float fitsigma = fitFunc -> GetParameter(2);
     float fitchi = fitFunc -> GetChisquare() / fitFunc -> GetNDF();
     float fitmeanerror = fitFunc -> GetParError(1);
     float fitsigmaerror = fitFunc -> GetParError(2);

     hist_chi_full -> Fill( fitchi );
     mass_chi_full[ i - i_const ] = fitchi;

     if ( fitchi < 1.5 ) {
         hist_mean -> Fill( fitmean );
         mass_mean[ i - i_const ] = fitmean;

         hist_sigma -> Fill( fitsigma );
         mass_sigma[ i - i_const ] = fitsigma;

         hist_chi -> Fill( fitchi );
         mass_chi[ i - i_const ] = fitchi;

         hist_meanerror -> Fill( fitmeanerror );
         mass_meanerror[ i - i_const ] = fitmeanerror;

         hist_sigmaerror -> Fill( fitsigmaerror );
         mass_sigmaerror[ i - i_const ] = fitsigmaerror;
     }

     cout << " 1:"
           << "  Mean: " << fitmean
        << " Mean error: " << fitmeanerror
          << "  Sigma: " << fitsigma
          << " Sigma error: " << fitsigmaerror
      << "  Chi2/ndf: " << fitchi
      << endl;

//     sprintf( fname2, "%d_%s.jpg", i, ftempname );
//     c1->SaveAs( fname2 );
//     for ( int j = 0; j < 200; j++ ) fname2[ j ] = 0;

     delete fitFunc;

  }
/*
  c2 -> cd();
  hist -> SetMarkerStyle(20);
  hist -> SetMarkerColor(kBlue);
  hist -> SetLineColor(kBlue);
  hist -> Draw("p e");
  c3 -> cd();
  hist90 -> SetMarkerStyle(20);
  hist90 -> SetMarkerColor(kRed);
  hist90 -> SetLineColor(kRed);
  hist90 -> Draw("p e");
  c4 -> cd();
  hist95 -> SetMarkerStyle(20);
  hist95 -> SetMarkerColor(kGreen);
  hist95 -> SetLineColor(kGreen);
  hist95 -> Draw("p e");
    
  c5 -> cd();
  hist2 -> SetMarkerStyle(20);
  hist2 -> SetMarkerColor(kRed);
  hist2 -> SetLineColor(kRed);
  hist2 -> Draw("p e");
  c6 -> cd();
  hist3 -> SetMarkerStyle(20);
  hist3 -> SetMarkerColor(kGreen);
  hist3 -> SetLineColor(kGreen);
  hist3 -> Draw("p e");
    
       c7 -> cd();
    hist->SetTitle("1");
    hist->GetYaxis()->SetTitle("Number of events");
    hist->GetXaxis()->SetTitle("Energy, GeV");
    hist -> SetMarkerStyle(20);
    hist -> SetMarkerColor(kBlue);
    hist -> SetLineColor(kBlue);
    hist -> Draw("p e");
    hist2 -> SetMarkerStyle(20);
    hist2 -> SetMarkerColor(kRed);
    hist2 -> SetLineColor(kRed);
    hist2 -> Draw("p e SAME");
//    hist3 -> SetMarkerStyle(20);
//    hist3 -> SetMarkerColor(kGreen);
//    hist3 -> SetLineColor(kGreen);
//    hist3 -> Draw("p e SAME");

        c8 -> cd();
    c8->Update();
        hist->SetTitle("Full distribution and 95% of the distribution");
        hist->GetYaxis()->SetTitle("Number of events");
        hist->GetXaxis()->SetTitle("Energy, GeV");
        hist -> SetMarkerStyle(20);
        hist -> SetMarkerColor(kBlue);
        hist -> SetLineColor(kBlue);
        hist -> Draw("p e");
//        hist2 -> SetMarkerStyle(20);
//        hist2 -> SetMarkerColor(kRed);
//        hist2 -> SetLineColor(kRed);
//        hist2 -> Draw("p e SAME");
        hist3 -> SetMarkerStyle(20);
        hist3 -> SetMarkerColor(kGreen);
        hist3 -> SetLineColor(kGreen);
        hist3 -> Draw("p e SAME");
*/
 
/*  cout << "Underflow hist_mean === " << hist_mean->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_mean === " << hist_mean->GetBinContent( nBins_fit + 1 ) << endl;
    
  cout << "Underflow hist_sigma === " << hist_sigma->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_sigma === " << hist_sigma->GetBinContent( nBins_fit + 1 ) << endl;
    
  cout << "Underflow hist_chi === " << hist_chi->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_chi === " << hist_chi->GetBinContent( nBins_fit + 1 ) << endl;
    
  cout << "Underflow hist_chi_full === " << hist_chi_full->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_chi_full === " << hist_chi_full->GetBinContent( nBins_fit + 1 ) << endl;
    
  cout << "Underflow hist_meanerror === " << hist_meanerror->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_meanerror === " << hist_meanerror->GetBinContent( nBins_fit + 1 ) << endl;
    
  cout << "Underflow hist_sigmaerror === " << hist_sigmaerror->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_sigmaerror === " << hist_sigmaerror->GetBinContent( nBins_fit + 1 ) << endl;
*/
  float min_chi = 2.5;
  float min = 0.0;
  int i_min = 0;
  for ( int i = 0; i < 20; i++ ) {

      if ( mass_chi[ i ] > 0.0 ) {

          if ( mass_chi[ i ] < min_chi ) {
             min_chi = mass_chi[ i ];
             i_min = i;
          }

      }

  }

//  float mean_mean = hist_mean -> GetMean();
//  float rms_mean = hist_mean -> GetRMS();
  float mean_mean = mass_mean[ i_min ];
  cout << " Mean:"
      << "  Mean_mean: " << mean_mean
//    << "  RMS_mean: " << rms_mean
    << endl;

//  float mean_sigma = hist_sigma -> GetMean();
//  float rms_sigma = hist_sigma -> GetRMS();
  float mean_sigma = mass_sigma[ i_min ];
  cout << " Sigma:"
      << "  Mean_sigma: " << mean_sigma
//    << "  RMS_sigma: " << rms_sigma
    << endl;

//  float mean_chi = hist_chi -> GetMean();
//  float rms_chi = hist_chi -> GetRMS();
  float mean_chi = mass_chi[ i_min ];
  cout << " Chi:"
      << "  Mean_chi: " << mean_chi
//    << "  RMS_chi: " << rms_chi
    << endl;

//  float mean_meanerror = hist_meanerror -> GetMean();
//  float rms_meanerror = hist_meanerror -> GetRMS();
  float mean_meanerror = mass_meanerror[ i_min ];
  cout << " Meanerror:"
      << "  Mean_meanerror: " << mean_meanerror
//    << "  RMS_meanerror: " << rms_meanerror
    << endl;

//  float mean_sigmaerror = hist_sigmaerror -> GetMean();
//  float rms_sigmaerror = hist_sigmaerror -> GetRMS();
  float mean_sigmaerror = mass_sigmaerror[ i_min ];
  cout << " Sigmaerror:"
      << "  Mean_sigmaerror: " << mean_sigmaerror
//    << "  RMS_sigmaerror: " << rms_sigmaerror
    << endl;

//  fprintf( out, "%d %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E\n", fenergy, mean90, rms90, mean95, rms95, mean, meanerror, rms, rmserror, mean_mean, rms_mean, mean_meanerror, rms_meanerror, mean_sigma, rms_sigma, mean_sigmaerror, rms_sigmaerror, mean_chi, rms_chi );
//  fprintf( out, "%d %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E\n", fenergy, mean90, rms90, mean95, rms95, mean, meanerror, rms, rmserror, mean_mean, rms_mean, mean_meanerror, mean_sigma, rms_sigma, mean_sigmaerror, mean_chi );
//  fprintf( out, "%d %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E\n", fenergy, mean_hist2, meanerror_hist2, rms_hist2, rmserror_hist2, mean_hist3, meanerror_hist3, rms_hist3, rmserror_hist3, mean_hist4, meanerror_hist4, rms_hist4, rmserror_hist4, mean_hist5, meanerror_hist5, rms_hist5, rmserror_hist5, mean_hist6, meanerror_hist6, rms_hist6, rmserror_hist6, mean_hist7, meanerror_hist7, rms_hist7, rmserror_hist7, mean, meanerror, rms, rmserror, mean_mean, mean_meanerror, mean_sigma, mean_sigmaerror, mean_chi );
  fprintf( out, "%d %E %E %E %E %E %E %E %E %E %E %E %E\n", fenergy, mean_hist2, meanerror_hist2, rms_hist2, rmserror_hist2, mean, meanerror, rms, rmserror, mean_mean, mean_meanerror, mean_sigma, mean_sigmaerror );
  delete hist;
  fclose( out );
  file -> Close();

/*  for ( int i = 0; i < 20; i++ ) printf( "%E\n", mass_chi[ i ] );
  printf("-------------------\n");
  printf( "%E\n", mass_chi[ i_min ] );
  printf( "%E\n", min_chi );
  printf("-------------------\n");
  for ( int i = 0; i < 20; i++ ) printf( "%E\n", mass_chi_full[ i ] );
*/
}

void fit_hists( const int bins = 1000 ) {
    
  int nfiles = 10;

  int number_file[nfiles];

  for (int i = 0; i < nfiles; i++) {
      number_file[ i ] = i + 1;
  }

  int mass[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 80, 90, 120 };
//  int mass[] = { 5, 10, 15, 20, 25, 30, 40, 50, 60 };
  int dim = 29; // 9


  for (int j = 0; j < nfiles; j++ ) {
      for (int i = 0; i < dim; i++ ) {
          fit_ann( mass[ i ], bins, number_file[ j ] );
      }
  }

   
}
