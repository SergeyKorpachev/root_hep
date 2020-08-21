void fitres( const int energy = 5, const int nBins = 500) {

  const float range = 1.3;

  char fname[ 200 ];
  char ftempname[ 200 ];
  char fname2[ 200 ];

  const float cut = sqrtf( float( energy ) );

  cout << "Cut === " << cut << endl;

  for ( int i = 0; i < 200; i++ ) fname[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) ftempname[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) fname2[ i ] = 0;

  sprintf( ftempname, "/group/cms/korpachev/resolution_ild_fit/resol/40000/60digi/gun_k0L_%dgev_FTFP_BERT_40000evt_ILD_l5_v02steel", energy );
  sprintf( fname, "%s.root", ftempname );

  TF1 *fitFunc;
  TF1 *fitFunc2;
  TH1F *hist;

  TCanvas *c1 = new TCanvas("c1", "c1", 1);

  gStyle->SetOptStat(0);

  const char *treeName = "Tree";
//  const int nBins = 1000;
  const float binLo = 0.0;
  const float binHi = energy + 20.0;

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
   FILE *out = fopen("out.txt", "a+");
       printf("File open... ");
       if (!out) {
          printf("[FAIL]\n");
          return 0;
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
  Float_t eecal = 0;
  Float_t ehcal = 0;
  tree->SetBranchAddress("eecal", &eecal);
  tree->SetBranchAddress("ehcal", &ehcal);

  //
  // Create a histogram and random generator
  //
  hist = new TH1F("hist", "hist", nBins, binLo, binHi);

  for ( int i = 0; i <nEvents; i++ ) {
    tree -> GetEntry(i);
    if ( (eecal < 1.5)  && ( ehcal > cut )) hist -> Fill( ehcal + eecal );
  }

  float mean = hist -> GetMean();
  float rms = hist -> GetRMS();

  cout << " 0:"
  	<< "  Mean: " << mean
	<< "  RMS: " << rms
	<< endl;

  fitFunc = new TF1("fitFunc", "gaus", mean - range * rms, mean + range * rms);
  hist -> Fit( fitFunc, "R" );
  float fitmean = fitFunc -> GetParameter(1);
  float fitsigma = fitFunc -> GetParameter(2);
  float fitchi = fitFunc -> GetChisquare() / fitFunc -> GetNDF();
  float fiterrormean = fitFunc -> GetParError(1);
  float fiterrorsigma = fitFunc -> GetParError(2);

  cout << " 1:"
  	<< "  Mean: " << fitmean
  	<< " Mean error: " << fiterrormean
	<< "  Sigma: " << fitsigma
        << " Sigma error: " << fiterrorsigma
	<< "  Chi2/ndf: " << fitchi
	<< endl;

  fitFunc2 = new TF1("fitFunc2", "gaus", fitmean - range * fitsigma, fitmean + range * fitsigma);
  hist -> Fit( fitFunc2, "R" );
  hist->GetYaxis()->SetTitle("Events");
  hist->GetXaxis()->SetTitle("Energy, GeV");
  float fitmean2 = fitFunc2 -> GetParameter(1);
  float fitsigma2 = fitFunc2 -> GetParameter(2);
  float fitchi2 = fitFunc2 -> GetChisquare() / fitFunc2 -> GetNDF();
  float fiterrormean2 = fitFunc -> GetParError(1);
  float fiterrorsigma2 = fitFunc -> GetParError(2);

  cout << " 2:"
  	<< "  Mean2: " << fitmean2
        << " Mean error: " << fiterrormean2
	<< "  Sigma2: " << fitsigma2
        << " Sigma error: " << fiterrorsigma2
	<< "  Chi2/ndf: " << fitchi2
	<< endl;

  if ( fitchi < fitchi2 ) {
    fitmean2 = fitmean;
    fiterrormean2 = fiterrormean;
    fitsigma2 = fitsigma;
    fiterrorsigma2 = fiterrorsigma;
    fitchi2 = fitchi;
  }

  fprintf( out, "%d %E %E %E %E %E %E\n", energy, fitmean2, fiterrormean2, fitsigma2, fiterrorsigma2, fitchi, fitchi2 );

  sprintf( fname2, "%s.jpg", ftempname );

  c1->SaveAs( fname2 );

//  delete hist;
//  fclose(  out );
//  file -> Close();

}
