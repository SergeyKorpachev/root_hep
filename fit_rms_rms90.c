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

void fit( const int fenergy = 5, const int nBins = 100 ) {

//  TCanvas *c1 = new TCanvas("c1", "c1", 1);
//  gStyle->SetOptStat(10);

  char fname_data[ 200 ];
  char ftempname_data[ 200 ];

  char fname_ann[ 200 ];
  char ftempname_ann[ 200 ];

  for ( int i = 0; i < 200; i++ ) fname_data[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) ftempname_data[ i ] = 0;

  for ( int i = 0; i < 200; i++ ) fname_ann[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) ftempname_ann[ i ] = 0;

  sprintf( ftempname_data, "./data/gun_k0L_%dgev_FTFP_BERT_5000evt_ILD_l5_v02steel", fenergy );
  sprintf( fname_data, "%s.root", ftempname_data );

  sprintf( ftempname_ann, "tree%d", fenergy );
  sprintf( fname_ann, "ann%d", fenergy );

  //
  // Open data file
  //
  std::cout << "Trying to open data file... ";
  TFile *file_data = new TFile(fname_data, "READ");
  if (!file_data) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Open ann file
  //
  std::cout << "Trying to open ann file... ";
  TFile *file_ann = new TFile("./ann.root", "READ");
  if (!file_ann) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  const char *treeName_data = "tree";
  const char *treeName_ann = ftempname_ann;

  //
  // Setup a TTree for data
  //
  std::cout << "Setup a tree for data... ";
  TTree *tree_data = (TTree *)file_data->Get(treeName_data);
  if (!tree_data) {
    std::cout << "[FAIL]" << std::endl;
    file_data->Close();
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Setup a TTree for ann
  //
  std::cout << "Setup a tree for ann... ";
  TTree *tree_ann = (TTree *)file_ann->Get(treeName_ann);
  if (!tree_ann) {
    std::cout << "[FAIL]" << std::endl;
    file_ann->Close();
    return;
  }
  std::cout << "[OK]" << std::endl;

  printf( "\n" );

  unsigned int nEvents_data = tree_data->GetEntries();
  unsigned int nEvents_ann = tree_ann->GetEntries();

  cout << "nEvents_data = " << nEvents_data << " and nEvents_ann = " << nEvents_ann << endl;
  if ( nEvents_data == nEvents_ann ) cout << "They are the same :)" << endl;
  else cout << "There is a problem :(" << endl;

  printf( "\n" );

  TH1F *hist_data;
  TH1F *hist_ann;

  const float binLo = 0.0;
  const float binHi = fenergy + 50.0;

  //
  // Setup a branch for data
  //
  Float_t energy_data = 0;
  tree_data->SetBranchAddress("energy", &energy_data);

  //
  // Setup a branch for ann
  //
  Float_t energy_ann = 0;
  tree_ann->SetBranchAddress(fname_ann, &energy_ann);

  //
  // Create a histogram
  //
  hist_data = new TH1F("hist_data", "hist_data", nBins, binLo, binHi);
  hist_ann = new TH1F("hist_ann", "hist_ann", nBins, binLo, binHi);

  for ( int i = 0; i <nEvents_data; i++ ) {
    tree_data -> GetEntry(i);
    if ( energy_data > 0 ) hist_data -> Fill( energy_data );
  }

  for ( int i = 0; i <nEvents_ann; i++ ) {
    tree_ann -> GetEntry(i);
    if ( energy_ann > 0 ) hist_ann -> Fill( energy_ann );
  }
    
  cout << "Underflow hist_data === " << hist_data->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_data === " << hist_data->GetBinContent( nBins + 1 ) << endl;

  cout << "Underflow hist_ann === " << hist_ann->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_ann === " << hist_ann->GetBinContent( nBins + 1 ) << endl;

  printf( "\n" );

  float mean_data = hist_data -> GetMean();
  float meanerror_data = hist_data -> GetMeanError();
  float rms_data = hist_data -> GetRMS();
  float rmserror_data = hist_data -> GetRMSError();
  cout << " data:"
    << "  Mean_data: " << mean_data
    << "  Mean_data error: " << meanerror_data
    << "  RMS_data: " << rms_data
    << "  RMS_data error: " << rmserror_data
    << endl;

  float mean_ann = hist_ann -> GetMean();
  float meanerror_ann = hist_ann -> GetMeanError();
  float rms_ann = hist_ann -> GetRMS();
  float rmserror_ann = hist_ann -> GetRMSError();
  cout << " ann:"
    << "  Mean_ann: " << mean_ann
    << "  Mean_ann error: " << meanerror_ann
    << "  RMS_ann: " << rms_ann
    << "  RMS_ann error: " << rmserror_ann
    << endl;

  printf( "\n" );

  float value90_data = 90.0;
  float mean90_data = 0;
  float rms90_data = 0;
  int left90_data = 0;
  int right90_data = 0;
  f( hist_data, value90_data, mean90_data, rms90_data, left90_data, right90_data );
  cout << "mean90_data = " << mean90_data << " and rms90_data = " << rms90_data << endl;
//  cout << "left90_data = " << left90_data << " and right90_data = " << right90_data << endl;
//  cout << "left value 90 for data = " << hist_data->GetBinCenter( left90_data ) << " and right value 90 for data= " << hist_data->GetBinCenter( right90_data ) << endl;

  printf( "\n" );

  float value90_ann = 90.0;
  float mean90_ann = 0;
  float rms90_ann = 0;
  int left90_ann = 0;
  int right90_ann = 0;
  f( hist_ann, value90_ann, mean90_ann, rms90_ann, left90_ann, right90_ann );
  cout << "mean90_ann = " << mean90_ann << " and rms90_ann = " << rms90_ann << endl;
//  cout << "left90_ann = " << left90_ann << " and right90_ann = " << right90_ann << endl;
//  cout << "left value 90 for ann = " << hist_ann->GetBinCenter( left90_ann ) << " and right value 90 for ann = " << hist_ann->GetBinCenter( right90_ann ) << endl;

/*  printf( "\n" );

  float value100_data = 100.0;
  float mean100_data = 0;
  float rms100_data = 0;
  int left100_data = 0;
  int right100_data = 0;
  f( hist_data, value100_data, mean100_data, rms100_data, left100_data, right100_data );
  cout << "mean100_data = " << mean100_data << " and rms100_data = " << rms100_data << endl;
  cout << "left100_data = " << left100_data << " and right100_data = " << right100_data << endl;
  cout << "left value 100 for data = " << hist_data->GetBinCenter( left100_data ) << " and right value 100 for data= " << hist_data->GetBinCenter( right100_data ) << endl;

  printf( "\n" );

  float value100_ann = 100.0;
  float mean100_ann = 0;
  float rms100_ann = 0;
  int left100_ann = 0;
  int right100_ann = 0;
  f( hist_ann, value100_ann, mean100_ann, rms100_ann, left100_ann, right100_ann );
  cout << "mean100_ann = " << mean100_ann << " and rms100_ann = " << rms100_ann << endl;
  cout << "left100_ann = " << left100_ann << " and right100_ann = " << right100_ann << endl;
  cout << "left value 100 for ann = " << hist_ann->GetBinCenter( left100_ann ) << " and right value 100 for ann = " << hist_ann->GetBinCenter( right100_ann ) << endl;
*/
  printf( "\n" );

  printf( "-------------------------------------------------------------------------------------------------\n" );
  printf( "-------------------------------------------------------------------------------------------------\n" );
  printf( "-------------------------------------------------------------------------------------------------\n" );
  
  cout << "Energy: " << fenergy << endl;
  
  cout << "mean_data: " << mean_data << endl;
  cout << "rms_data: " << rms_data << endl;

//  cout << "mean100_data: " << mean100_data << endl;
//  cout << "rms100_data: " << rms100_data << endl;

  cout << "mean90_data: " << mean90_data << endl;
  cout << "rms90_data: " << rms90_data << endl;

  cout << endl;

  cout << "mean_ann: " << mean_ann << endl;
  cout << "rms_ann: " << rms_ann << endl;

//  cout << "mean100_ann: " << mean100_ann << endl;
//  cout << "rms100_ann: " << rms100_ann << endl;

  cout << "mean90_ann: " << mean90_ann << endl;
  cout << "rms90_ann: " << rms90_ann << endl;

  printf( "-------------------------------------------------------------------------------------------------\n" );
  printf( "-------------------------------------------------------------------------------------------------\n" );
  printf( "-------------------------------------------------------------------------------------------------\n" );

  printf( "\n" );

/*  TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
  ptstats->SetName("stats");
  ptstats->SetBorderSize(1);
  ptstats->SetFillColor(0);
  ptstats->SetTextAlign(12);
  ptstats->SetTextFont(42);

  char fname_title[ 200 ];
  for ( int i = 0; i < 200; i++ ) fname_title[ i ] = 0;
  sprintf(fname_title, "Comparison of distributions for %d GeV", fenergy);

  hist_ann->SetTitle( fname_title );

  hist_ann->GetXaxis()->SetTitle("E_{reco}, GeV");
  hist_ann->GetYaxis()->SetTitle("Number of events");
  hist_ann->GetYaxis()->SetLabelSize(0.038);
  hist_ann->GetXaxis()->SetLabelSize(0.038);
  hist_ann->GetYaxis()->SetTitleSize(0.038);
  hist_ann->GetXaxis()->SetTitleSize(0.038);

  TText *ptstats_LaTex = ptstats->AddText("AAAAAAA");
  ptstats->SetOptStat(10);
  ptstats->Draw();

  char fname2[ 200 ];
  for ( int i = 0; i < 200; i++ ) fname2[ i ] = 0;

  c1 -> cd();
  c1 -> SetTickx(1);
  c1 -> SetTicky(1);

  hist_ann->SetLineColor(kRed);
  hist_ann->SetLineWidth(1);
  hist_ann->SetMarkerColor(2);
  hist_ann->SetMarkerStyle(7);
  hist_ann->SetMarkerSize(1);

  hist_data->SetLineColor(kBlue);
  hist_data->SetLineWidth(1);
  hist_data->SetMarkerColor(2);
  hist_data->SetMarkerStyle(7);
  hist_data->SetMarkerSize(1);

  hist_ann -> Draw("ehist");
  hist_data -> Draw("ehist SAME");
    
  sprintf(fname2, "comp_%d.png", fenergy);
  c1 -> SaveAs(fname2);
*/
  delete hist_data;
  delete hist_ann;

  file_data -> Close();
  file_ann -> Close();

}

void fit_rms_rms90( const int bins = 100 ) {

  int mass[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 18, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 80, 90, 120 };
  int dim = 29;

  for (int i = 0; i < dim; i++ ) {
      fit( mass[ i ], bins );
  }
    
}
