void code ()
{
  float adcCut = 550;
  int nrebin = 2;
  float sigRange = 1.5;

  TF1 *fitFunc;
  TF1 *fitFunc2;

  char stxt[120];
  
  TCanvas *c1 = new TCanvas("c1", "c1", 1);

  //
  // Open file
  //
  std::cout << "File open... ";
  FILE* file = fopen("/home/root1/Desktop/diplom/data/processing/ITEP/newnew/uniformity_calice_170303/desy_tile_hv_28_170303_scan3_scan_8.5_8.5.txt", "r");
  if (!file) {
   std::cout << "[FAIL]\n" << std::endl;
   return 0;
  } else std::cout << "[OK]" << std::endl;

  //
  // Create an output file
  //
  std::cout << "Trying to create output file... ";
  FILE* fevtot = fopen("evtot.txt", "a+");
  if (!fevtot) {
   std::cout << "[FAIL]" << std::endl;
   return 0;
  } else std::cout << "[OK]" << std::endl;

  std::cout << "Trying to create output file... ";
  FILE* fevcut = fopen("evcut.txt", "a+");
  if (!fevcut) {
   std::cout << "[FAIL]" << std::endl;
   return 0;
  } else std::cout << "[OK]" << std::endl;

  std::cout << "Trying to create output file... ";
  FILE* fmean = fopen("mean.txt", "a+");
  if (!fmean) {
   std::cout << "[FAIL]" << std::endl;
   return 0;
  } else std::cout << "[OK]" << std::endl;

  std::cout << "Trying to create output file... ";
  FILE* fchi2 = fopen("chi2.txt", "a+");
  if (!fchi2) {
   std::cout << "[FAIL]" << std::endl;
   return 0;
  } else std::cout << "[OK]" << std::endl;

  TH1F* histTotal = new TH1F("histTotal","Full ADC range",200,0.,1600.);
  sprintf(stxt,"Signal above %f ADC", adcCut);
  TH1F* histCut = new TH1F("histCut",stxt,100,0.,1600.);

  // read data
  Int_t a = 0;
  Int_t b = 0;
  Char_t buf[0xFF];
  while( feof(file) == 0 ) {
    fscanf ( file,"%d %d", &a, &b );
    fgets( buf, 0xFF, file );
    // ---------------------------------------------
    if ( a == 4 ) {
      histTotal->Fill( b );
      if ( b > adcCut ) histCut->Fill( b );
    }
    //----------------------------------------------
    a = b = 0;
    }

  //fill hists
  Float_t evtot = 0;
  Float_t evcut = 0;
  evtot = float(histTotal->GetEntries());
  int nevt = histCut->GetEntries();
  evcut = float(nevt);

  if ( nevt < 50 ) {
    std::cout << "No events in signal region." << std::endl;
    return;
  }

  int nbinInit = histCut->GetNbinsX();
  int irebin = nbinInit/(nrebin*pow(nevt,1./3));
  //if ( nrebin > 1 ) histCut->Rebin(nrebin);
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  if ( irebin > 1 ) histCut->Rebin(irebin);
  Float_t mean = histCut->GetMean();
  Float_t sigma = histCut->GetRMS();

/*    std::cout << "  Nevt: " << nevt
	      << "  Mean: " << mean
	      << "  RMS: " << sigma
	      << std::endl;
  */

  fitFunc = new TF1("fitFunc", "gaus", mean - sigRange*sigma, mean + sigRange*sigma);
  histCut->Fit(fitFunc, "QR0N" );
  //std::cout << "FIT 1" << std::endl;

  mean = fitFunc->GetParameter(1);
  sigma = fitFunc->GetParameter(2);
  Double_t chi2 = 0;
  chi2 = fitFunc->GetChisquare() / fitFunc->GetNDF();

  int minNDF = 4;
  int curNDF = 0;
  int ncount = 0;
  while ( curNDF < 4 && ncount < 10 ) {
    ncount++;
    fitFunc2 = new TF1("fitFunc2", "gaus", 
		       mean - sigRange*sigma, 
		       mean + sigRange*sigma);
    histCut->Fit(fitFunc2, "QR");
    //std::cout << "FIT " << ncount+1 << std::endl;
    sigRange *= 2;
    curNDF = fitFunc2->GetNDF();
  }
  //std:: cout << "Last range: " << sigRange << std::endl;

  Float_t mean2 = fitFunc2->GetParameter(1);
  Float_t sigma2 = fitFunc2->GetParameter(2);
  Double_t chi22 = 0;
  chi22 = fitFunc2->GetChisquare() / fitFunc2->GetNDF();

/*  std::cout << "  Nevt: " << nevt
	    << "  Mean: " << mean2
	    << "  Sigma: " << sigma2
	    << "  Chi2/ndf: " << chi22
	    << std::endl;
*/
  histCut->Draw();

/*  fprintf(fevtot,"%E\n", evtot);	
  fprintf(fevcut,"%E\n", evcut);	
  fprintf(fmean,"%E\n", mean2);	
  fprintf(fchi2,"%E\n", chi22);	
*/
  fclose( fevtot );
  fclose( fevcut );
  fclose( fmean );
  fclose( fchi2 );
  fclose( file );

}
