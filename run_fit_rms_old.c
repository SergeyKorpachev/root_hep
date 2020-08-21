void f60( TH1* h, float &a, float &b ) {
  TAxis* axis = h -> GetXaxis();
  Int_t nbins = axis -> GetNbins();
  Int_t imean = axis -> FindBin( h -> GetMean() );
  Double_t entries = 0.6 * ( h -> GetEntries() );
  Double_t w = h -> GetBinContent( imean );
  Double_t x = h -> GetBinCenter( imean );
  Double_t sumw = w;
  Double_t sumwx = w*x;
  Double_t sumwx2 = w*x*x;
  for ( Int_t i = 1; i < nbins; i++ ) {
    if ( i > 0 ) {
    w = h -> GetBinContent( imean - i );
    x = h -> GetBinCenter( imean - i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( i <= nbins ) {
    w = h -> GetBinContent( imean + i );
    x = h -> GetBinCenter( imean + i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( sumw > entries ) break;
  }
  x = sumwx / sumw;
  Double_t rms2 = TMath::Abs( ( sumwx2 / sumw ) - ( x * x ) );
  Double_t result = TMath::Sqrt( rms2 );
  printf( "RMS of central 60%% = %f, RMS total = %f, Mean of central 60%% = %f, Mean total = %f\n", result, h -> GetRMS(), x, h -> GetMean() );
  a = x;
  b = result;
}

void f65( TH1* h, float &a, float &b ) {
  TAxis* axis = h -> GetXaxis();
  Int_t nbins = axis -> GetNbins();
  Int_t imean = axis -> FindBin( h -> GetMean() );
  Double_t entries = 0.65 * ( h -> GetEntries() );
  Double_t w = h -> GetBinContent( imean );
  Double_t x = h -> GetBinCenter( imean );
  Double_t sumw = w;
  Double_t sumwx = w*x;
  Double_t sumwx2 = w*x*x;
  for ( Int_t i = 1; i < nbins; i++ ) {
    if ( i > 0 ) {
    w = h -> GetBinContent( imean - i );
    x = h -> GetBinCenter( imean - i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( i <= nbins ) {
    w = h -> GetBinContent( imean + i );
    x = h -> GetBinCenter( imean + i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( sumw > entries ) break;
  }
  x = sumwx / sumw;
  Double_t rms2 = TMath::Abs( ( sumwx2 / sumw ) - ( x * x ) );
  Double_t result = TMath::Sqrt( rms2 );
  printf( "RMS of central 65%% = %f, RMS total = %f, Mean of central 65%% = %f, Mean total = %f\n", result, h -> GetRMS(), x, h -> GetMean() );
  a = x;
  b = result;
}

void f70( TH1* h, float &a, float &b ) {
  TAxis* axis = h -> GetXaxis();
  Int_t nbins = axis -> GetNbins();
  Int_t imean = axis -> FindBin( h -> GetMean() );
  Double_t entries = 0.7 * ( h -> GetEntries() );
  Double_t w = h -> GetBinContent( imean );
  Double_t x = h -> GetBinCenter( imean );
  Double_t sumw = w;
  Double_t sumwx = w*x;
  Double_t sumwx2 = w*x*x;
  for ( Int_t i = 1; i < nbins; i++ ) {
    if ( i > 0 ) {
    w = h -> GetBinContent( imean - i );
    x = h -> GetBinCenter( imean - i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( i <= nbins ) {
    w = h -> GetBinContent( imean + i );
    x = h -> GetBinCenter( imean + i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( sumw > entries ) break;
  }
  x = sumwx / sumw;
  Double_t rms2 = TMath::Abs( ( sumwx2 / sumw ) - ( x * x ) );
  Double_t result = TMath::Sqrt( rms2 );
  printf( "RMS of central 70%% = %f, RMS total = %f, Mean of central 70%% = %f, Mean total = %f\n", result, h -> GetRMS(), x, h -> GetMean() );
  a = x;
  b = result;
}

void f75( TH1* h, float &a, float &b ) {
  TAxis* axis = h -> GetXaxis();
  Int_t nbins = axis -> GetNbins();
  Int_t imean = axis -> FindBin( h -> GetMean() );
  Double_t entries = 0.75 * ( h -> GetEntries() );
  Double_t w = h -> GetBinContent( imean );
  Double_t x = h -> GetBinCenter( imean );
  Double_t sumw = w;
  Double_t sumwx = w*x;
  Double_t sumwx2 = w*x*x;
  for ( Int_t i = 1; i < nbins; i++ ) {
    if ( i > 0 ) {
    w = h -> GetBinContent( imean - i );
    x = h -> GetBinCenter( imean - i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( i <= nbins ) {
    w = h -> GetBinContent( imean + i );
    x = h -> GetBinCenter( imean + i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( sumw > entries ) break;
  }
  x = sumwx / sumw;
  Double_t rms2 = TMath::Abs( ( sumwx2 / sumw ) - ( x * x ) );
  Double_t result = TMath::Sqrt( rms2 );
  printf( "RMS of central 75%% = %f, RMS total = %f, Mean of central 75%% = %f, Mean total = %f\n", result, h -> GetRMS(), x, h -> GetMean() );
  a = x;
  b = result;
}

void f80( TH1* h, float &a, float &b ) {
  TAxis* axis = h -> GetXaxis();
  Int_t nbins = axis -> GetNbins();
  Int_t imean = axis -> FindBin( h -> GetMean() );
  Double_t entries = 0.8 * ( h -> GetEntries() );
  Double_t w = h -> GetBinContent( imean );
  Double_t x = h -> GetBinCenter( imean );
  Double_t sumw = w;
  Double_t sumwx = w*x;
  Double_t sumwx2 = w*x*x;
  for ( Int_t i = 1; i < nbins; i++ ) {
    if ( i > 0 ) {
    w = h -> GetBinContent( imean - i );
    x = h -> GetBinCenter( imean - i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( i <= nbins ) {
    w = h -> GetBinContent( imean + i );
    x = h -> GetBinCenter( imean + i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( sumw > entries ) break;
  }
  x = sumwx / sumw;
  Double_t rms2 = TMath::Abs( ( sumwx2 / sumw ) - ( x * x ) );
  Double_t result = TMath::Sqrt( rms2 );
  printf( "RMS of central 80%% = %f, RMS total = %f, Mean of central 80%% = %f, Mean total = %f\n", result, h -> GetRMS(), x, h -> GetMean() );
  a = x;
  b = result;
}

void f85( TH1* h, float &a, float &b ) {
  TAxis* axis = h -> GetXaxis();
  Int_t nbins = axis -> GetNbins();
  Int_t imean = axis -> FindBin( h -> GetMean() );
  Double_t entries = 0.85 * ( h -> GetEntries() );
  Double_t w = h -> GetBinContent( imean );
  Double_t x = h -> GetBinCenter( imean );
  Double_t sumw = w;
  Double_t sumwx = w*x;
  Double_t sumwx2 = w*x*x;
  for ( Int_t i = 1; i < nbins; i++ ) {
    if ( i > 0 ) {
    w = h -> GetBinContent( imean - i );
    x = h -> GetBinCenter( imean - i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( i <= nbins ) {
    w = h -> GetBinContent( imean + i );
    x = h -> GetBinCenter( imean + i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( sumw > entries ) break;
  }
  x = sumwx / sumw;
  Double_t rms2 = TMath::Abs( ( sumwx2 / sumw ) - ( x * x ) );
  Double_t result = TMath::Sqrt( rms2 );
  printf( "RMS of central 85%% = %f, RMS total = %f, Mean of central 85%% = %f, Mean total = %f\n", result, h -> GetRMS(), x, h -> GetMean() );
  a = x;
  b = result;
}

void f901( TH1* h, float &a, float &b ) {
  TAxis* axis = h -> GetXaxis();
  Int_t nbins = axis -> GetNbins();
  Int_t imean = axis -> FindBin( h -> GetMean() );
  Double_t entries = 0.9 * ( h -> GetEntries() );
  Double_t w = h -> GetBinContent( imean );
  Double_t x = h -> GetBinCenter( imean );
  Double_t sumw = w;
  Double_t sumwx = w*x;
  Double_t sumwx2 = w*x*x;
  for ( Int_t i = 1; i < nbins; i++ ) {
    if ( i > 0 ) {
    w = h -> GetBinContent( imean - i );
    x = h -> GetBinCenter( imean - i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( i <= nbins ) {
    w = h -> GetBinContent( imean + i );
    x = h -> GetBinCenter( imean + i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( sumw > entries ) break;
  }
  x = sumwx;
  Double_t rms2 = TMath::Abs( ( sumwx2 ) - ( x * x ) );
  Double_t result = TMath::Sqrt( rms2 );
  printf( "RMS of central 901%% = %f, RMS total = %f, Mean of central 901%% = %f, Mean total = %f\n", result, h -> GetRMS(), x, h -> GetMean() );
  a = x;
  b = result;
}

void f90( TH1* h, float &a, float &b ) {
  TAxis* axis = h -> GetXaxis();
  Int_t nbins = axis -> GetNbins();
  Int_t imean = axis -> FindBin( h -> GetMean() );
  Double_t entries = 0.9 * ( h -> GetEntries() );
  Double_t w = h -> GetBinContent( imean );
  Double_t x = h -> GetBinCenter( imean );
  Double_t sumw = w;
  Double_t sumwx = w*x;
  Double_t sumwx2 = w*x*x;
  for ( Int_t i = 1; i < nbins; i++ ) {
    if ( i > 0 ) {
    w = h -> GetBinContent( imean - i );
    x = h -> GetBinCenter( imean - i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( i <= nbins ) {
    w = h -> GetBinContent( imean + i );
    x = h -> GetBinCenter( imean + i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( sumw > entries ) break;
  }
  x = sumwx / sumw;
  Double_t rms2 = TMath::Abs( ( sumwx2 / sumw ) - ( x * x ) );
  Double_t result = TMath::Sqrt( rms2 );
  printf( "RMS of central 90%% = %f, RMS total = %f, Mean of central 90%% = %f, Mean total = %f\n", result, h -> GetRMS(), x, h -> GetMean() );
  a = x;
  b = result;
}

void f95( TH1* h, float &a, float &b ) {
  TAxis* axis = h -> GetXaxis();
  Int_t nbins = axis -> GetNbins();
  Int_t imean = axis -> FindBin( h -> GetMean() );
  Double_t entries = 0.95 * ( h -> GetEntries() );
  Double_t w = h -> GetBinContent( imean );
  Double_t x = h -> GetBinCenter( imean );
  Double_t sumw = w;
  Double_t sumwx = w*x;
  Double_t sumwx2 = w*x*x;
  for ( Int_t i = 1; i < nbins; i++ ) {
    if ( i > 0 ) {
    w = h -> GetBinContent( imean - i );
    x = h -> GetBinCenter( imean - i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( i <= nbins ) {
    w = h -> GetBinContent( imean + i );
    x = h -> GetBinCenter( imean + i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( sumw > entries ) break;
  }
  x = sumwx / sumw;
  Double_t rms2 = TMath::Abs( ( sumwx2 / sumw ) - ( x * x ) );
  Double_t result = TMath::Sqrt( rms2 );
  printf( "RMS of central 95%% = %f, RMS total = %f, Mean of central 95%% = %f, Mean total = %f\n", result, h -> GetRMS(), x, h -> GetMean() );
  a = x;
  b = result;
}

void f100( TH1* h, float &a, float &b ) {
  TAxis* axis = h -> GetXaxis();
  Int_t nbins = axis -> GetNbins();
  Int_t imean = axis -> FindBin( h -> GetMean() );
  Double_t entries = 1.0 * ( h -> GetEntries() );
  Double_t w = h -> GetBinContent( imean );
  Double_t x = h -> GetBinCenter( imean );
  Double_t sumw = w;
  Double_t sumwx = w*x;
  Double_t sumwx2 = w*x*x;
  for ( Int_t i = 1; i < nbins; i++ ) {
    if ( i > 0 ) {
    w = h -> GetBinContent( imean - i );
    x = h -> GetBinCenter( imean - i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( i <= nbins ) {
    w = h -> GetBinContent( imean + i );
    x = h -> GetBinCenter( imean + i );
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( sumw > entries ) break;
  }
  x = sumwx / sumw;
  Double_t rms2 = TMath::Abs( ( sumwx2 / sumw ) - ( x * x ) );
  Double_t result = TMath::Sqrt( rms2 );
  printf( "RMS of central 100%% = %f, RMS total = %f, Mean of central 100%% = %f, Mean total = %f\n", result, h -> GetRMS(), x, h -> GetMean() );
  a = x;
  b = result;
}

void fit_data( const int fenergy = 5, const int nBins = 1000 ) {

  char fname[ 200 ];
  char ftempname[ 200 ];
  char fname2[ 200 ];

//  const float cut = sqrtf( float( fenergy ) );

//  cout << "Cut === " << cut << endl;

  for ( int i = 0; i < 200; i++ ) fname[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) ftempname[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) fname2[ i ] = 0;

  sprintf( ftempname, "gun_k0L_%dgev_FTFP_BERT_5000evt_ILD_l5_v02steel", fenergy );
  sprintf( fname, "%s.root", ftempname );

  TH1F *hist;

  TH1F *hist_mean;
  TH1F *hist_sigma;
  TH1F *hist_chi_full;
  TH1F *hist_chi;
  TH1F *hist_meanerror;
  TH1F *hist_sigmaerror;

  TCanvas *c1 = new TCanvas("c1", "c1", 1);

  gStyle->SetOptStat(0);

  const char *treeName = "tree";
  const float binLo = 0.0;
  const float binHi = fenergy + 30.0;

  const int nBins_fit = 10;
  const float binHi_fit = ( binHi - fenergy ) / 2.0;
  const float binHi_fit_error = binHi_fit - 8.0;

//  const float cut = 2.0; //0.6 * sqrt( energy );

  //
  // Open data file
  //
  std::cout << "Trying to open data file... ";
  TFile *file = new TFile(fname, "READ");
  if (!file) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Open file for output
  //
   FILE *out = fopen("2out_data.txt", "a+");
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
  tree->SetBranchAddress("energy", &energy);

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
    
  cout << "Underflow hist === " << hist->GetBinContent( 0 ) << endl;
  cout << "Overflow hist === " << hist->GetBinContent( nBins + 1 ) << endl;

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

  cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
  float mean60 = 0;
  float rms60 = 0;
  f60( hist, mean60, rms60 );
  cout << "mean60 = " << mean60 << " and rms60 = " << rms60 << endl;
  float mean65 = 0;
  float rms65 = 0;
  f65( hist, mean65, rms65 );
  cout << "mean65 = " << mean65 << " and rms65 = " << rms65 << endl;
  float mean70 = 0;
  float rms70 = 0;
  f70( hist, mean70, rms70 );
  cout << "mean70 = " << mean70 << " and rms70 = " << rms70 << endl;
  float mean75 = 0;
  float rms75 = 0;
  f75( hist, mean75, rms75 );
  cout << "mean75 = " << mean75 << " and rms75 = " << rms75 << endl;
  float mean80 = 0;
  float rms80 = 0;
  f80( hist, mean80, rms80 );
  cout << "mean80 = " << mean80 << " and rms80 = " << rms80 << endl;
  float mean85 = 0;
  float rms85 = 0;
  f85( hist, mean85, rms85 );
  cout << "mean85 = " << mean85 << " and rms85 = " << rms85 << endl;
  float mean90 = 0;
  float rms90 = 0;
  f90( hist, mean90, rms90 );
  cout << "mean90 = " << mean90 << " and rms90 = " << rms90 << endl;
    
    float mean901 = 0;
    float rms901 = 0;
    f901( hist, mean901, rms901 );
    cout << "mean901 = " << mean901 << " and rms901 = " << rms901 << endl;
    
  float mean95 = 0;
  float rms95 = 0;
  f95( hist, mean95, rms95 );
  cout << "mean95 = " << mean95 << " and rms95 = " << rms95 << endl;
  float mean100 = 0;
  float rms100 = 0;
  f100( hist, mean100, rms100 );
  cout << "mean100 = " << mean100 << " and rms100 = " << rms100 << endl;
  cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    
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

     sprintf( fname2, "%d_%s.jpg", i, ftempname );
     c1->SaveAs( fname2 );
     for ( int j = 0; j < 200; j++ ) fname2[ j ] = 0;

     delete fitFunc;

  }
    
  cout << "Underflow hist_mean === " << hist_mean->GetBinContent( 0 ) << endl;
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

//  fprintf( out, "%d %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E\n", fenergy, mean60, rms60, mean65, rms65, mean70, rms70, mean75, rms75, mean80, rms80, mean85, rms85, mean90, rms90, mean95, rms95, mean100, rms100, mean, meanerror, rms, rmserror, mean_mean, rms_mean, mean_meanerror, rms_meanerror, mean_sigma, rms_sigma, mean_sigmaerror, rms_sigmaerror, mean_chi, rms_chi );
//  fprintf( out, "%d %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E\n", fenergy, mean60, rms60, mean65, rms65, mean70, rms70, mean75, rms75, mean80, rms80, mean85, rms85, mean90, rms90, mean95, rms95, mean100, rms100, mean, meanerror, rms, rmserror, mean_mean, rms_mean, mean_meanerror, mean_sigma, rms_sigma, mean_sigmaerror, mean_chi );
  fprintf( out, "%d %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E\n", fenergy, mean60, rms60, mean65, rms65, mean70, rms70, mean75, rms75, mean80, rms80, mean85, rms85, mean90, rms90, mean95, rms95, mean100, rms100, mean, meanerror, rms, rmserror, mean_mean, mean_meanerror, mean_sigma, mean_sigmaerror, mean_chi );
  delete hist;
  fclose( out );
  file -> Close();

  for ( int i = 0; i < 20; i++ ) printf( "%E\n", mass_chi[ i ] );
  printf("-------------------\n");
  printf( "%E\n", mass_chi[ i_min ] );
  printf( "%E\n", min_chi );
  printf("-------------------\n");
  for ( int i = 0; i < 20; i++ ) printf( "%E\n", mass_chi_full[ i ] );

}

/*void fit_ann( const int fenergy = 5, const int nBins = 1000 ) {

  char fname[ 200 ];
  char ftempname[ 200 ];
  char fname2[ 200 ];
    
  char fname_tree[ 200 ];
  char fname_branch[ 200 ];

//  const float cut = sqrtf( float( fenergy ) );

//  cout << "Cut === " << cut << endl;

  for ( int i = 0; i < 200; i++ ) fname[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) ftempname[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) fname2[ i ] = 0;

  for ( int i = 0; i < 200; i++ ) fname_tree[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) fname_branch[ i ] = 0;

  sprintf( ftempname, "test_ann" );
  sprintf( fname, "%s.root", ftempname );

  TH1F *hist;

  TH1F *hist_mean;
  TH1F *hist_sigma;
  TH1F *hist_chi_full;
  TH1F *hist_chi;
  TH1F *hist_meanerror;
  TH1F *hist_sigmaerror;

  TCanvas *c1 = new TCanvas("c1", "c1", 1);

  gStyle->SetOptStat(0);

  sprintf( fname_tree, "tree%d", fenergy );
    
  const char *treeName = fname_tree;
  const float binLo = 0.0;
  const float binHi = fenergy + 20.0;

  const int nBins_fit = 10;
  const float binHi_fit = ( binHi - fenergy ) / 2.0;
  const float binHi_fit_error = binHi_fit - 8.0;

//  const float cut = 2.0; //0.6 * sqrt( energy );

  //
  // Open data file
  //
  std::cout << "Trying to open data file... ";
  TFile *file = new TFile(fname, "READ");
  if (!file) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Open file for output
  //
   FILE *out = fopen("2out_ann.txt", "a+");
       printf("File o2en... ");
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

  sprintf( fname_branch, "ann%d", fenergy );

  //
  // Setup a branch
  //
  Float_t ann = 0;
  tree->SetBranchAddress(fname_branch, &ann);

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
    if ( ann > 0 ) hist -> Fill( ann );
  }

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

     if ( fitchi < 2.5 ) {
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

     sprintf( fname2, "%d_%s_%d.jpg", i, ftempname, fenergy );
     c1->SaveAs( fname2 );
     for ( int j = 0; j < 200; j++ ) fname2[ j ] = 0;

     delete fitFunc;

  }

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

  float mean_mean = hist_mean -> GetMean();
  float rms_mean = hist_mean -> GetRMS();
  cout << " Mean:"
      << "  Mean_mean: " << mean_mean
    << "  RMS_mean: " << rms_mean
    << endl;

  float mean_sigma = hist_sigma -> GetMean();
  float rms_sigma = hist_sigma -> GetRMS();
  cout << " Sigma:"
      << "  Mean_sigma: " << mean_sigma
    << "  RMS_sigma: " << rms_sigma
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

//  fprintf( out, "%d %E %E %E %E %E %E %E %E %E %E %E %E %E %E\n", fenergy, mean, meanerror, rms, rmserror, mean_mean, rms_mean, mean_meanerror, rms_meanerror, mean_sigma, rms_sigma, mean_sigmaerror, rms_sigmaerror, mean_chi, rms_chi );
  fprintf( out, "%d %E %E %E %E %E %E %E %E %E %E %E\n", fenergy, mean, meanerror, rms, rmserror, mean_mean, rms_mean, mean_meanerror, mean_sigma, rms_sigma, mean_sigmaerror, mean_chi );
  delete hist;
  fclose( out );
  file -> Close();

  for ( int i = 0; i < 20; i++ ) printf( "%E\n", mass_chi[ i ] );
  printf("-------------------\n");
  printf( "%E\n", mass_chi[ i_min ] );
  printf( "%E\n", min_chi );
  printf("-------------------\n");
  for ( int i = 0; i < 20; i++ ) printf( "%E\n", mass_chi_full[ i ] );

}
*/
void run_fit_rms_old( const int bins = 1000 ) {

//  int mass[] = { 1, 2, 3, 4, 5, 10, 15, 20, 25, 30, 40, 50, 60, 70, 80, 90 };
  int mass[] = { 5, 10, 15, 20, 25, 30, 40, 50, 60 };
  int dim = 9; // 16

  for (int i = 0; i < dim; i++ ) {
      fit_data( mass[ i ], bins );
      //fit_ann( mass[ i ], bins );
  }
    
}
