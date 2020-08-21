TCanvas *c1;

void onedist( const int energy1 = 5, const int energy2 = 5, const int energy3 = 5, const int nBins = 50) {

  char fname1[ 200 ];
  char fname2[ 200 ];
  char fname3[ 200 ];
  char ftempname1[ 200 ];
  char ftempname2[ 200 ];
  char ftempname3[ 200 ];

  const float cut1 = sqrtf( float( energy1 ) ); //float( energy1 ) / 2;
  const float cut2 = sqrtf( float( energy2 ) );
  const float cut3 = sqrtf( float( energy3 ) );

  cout << "Cut1 === " << cut1 << endl;
  cout << "Cut2 === " << cut2 << endl;
  cout << "Cut3 === " << cut3 << endl;

  for ( int i = 0; i < 200; i++ ) fname1[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) ftempname1[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) fname2[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) ftempname2[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) fname3[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) ftempname3[ i ] = 0;

  sprintf( ftempname1, "/home/korpachev/Desktop/resolution_ild_fit/resol/40000/nodigi/gun_k0L_%dgev_FTFP_BERT_40000evt_ILD_l5_v02steel", energy1 );
  sprintf( fname1, "%s.root", ftempname1 );
  sprintf( ftempname2, "/home/korpachev/Desktop/resolution_ild_fit/resol/40000/digi/gun_k0L_%dgev_FTFP_BERT_40000evt_ILD_l5_v02steel", energy2 );
  sprintf( fname2, "%s.root", ftempname2 );
  sprintf( ftempname3, "/home/korpachev/Desktop/resolution_ild_fit/resol/40000/60digi/gun_k0L_%dgev_FTFP_BERT_40000evt_ILD_l5_v02steel", energy3 );
  sprintf( fname3, "%s.root", ftempname3 );

  TH1F *hist1;
  TH1F *hist2;
  TH1F *hist3;

  if ( gROOT->GetListOfCanvases()->FindObject("c1") == NULL ) c1 = new TCanvas("c1", "c1", 1);

  gStyle->SetOptStat(0);

  const char *treeName = "Tree";
//  const int nBins = 1000;
  const float binLo = 0.0;
  const float binHi1 = energy1 + 20.0;
  const float binHi2 = energy2 + 20.0;
  const float binHi3 = energy3 + 20.0;

//  const float cut = 2.0; //0.6 * sqrt( energy );

  //
  // Open data file 1
  //
  std::cout << "Trying to open data file 1 ... ";
  TFile *file1 = new TFile(fname1, "READ");
  if (!file1) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Open data file 2
  //
  std::cout << "Trying to open data file 2 ... ";
  TFile *file2 = new TFile(fname2, "READ");
  if (!file2) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Open data file 3
  //
  std::cout << "Trying to open data file 3 ... ";
  TFile *file3 = new TFile(fname3, "READ");
  if (!file3) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Setup a TTree 1
  //
  std::cout << "Setup a tree 1 ... ";
  TTree *tree1 = (TTree *)file1->Get(treeName);
  if (!tree1) {
    std::cout << "[FAIL]" << std::endl;
    file1->Close();
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Setup a TTree 2
  //
  std::cout << "Setup a tree 2 ... ";
  TTree *tree2 = (TTree *)file2->Get(treeName);
  if (!tree2) {
    std::cout << "[FAIL]" << std::endl;
    file2->Close();
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Setup a TTree 3
  //
  std::cout << "Setup a tree 3 ... ";
  TTree *tree3 = (TTree *)file3->Get(treeName);
  if (!tree3) {
    std::cout << "[FAIL]" << std::endl;
    file3->Close();
    return;
  }
  std::cout << "[OK]" << std::endl;

  unsigned int nEvents1 = tree1->GetEntries();
  unsigned int nEvents2 = tree2->GetEntries();
  unsigned int nEvents3 = tree3->GetEntries();

  //
  // Setup a branch 1
  //
  Float_t eecal1 = 0;
  Float_t ehcal1 = 0;
  tree1->SetBranchAddress("eecal", &eecal1);
  tree1->SetBranchAddress("ehcal", &ehcal1);

  //
  // Setup a branch 2
  //
  Float_t eecal2 = 0;
  Float_t ehcal2 = 0;
  tree2->SetBranchAddress("eecal", &eecal2);
  tree2->SetBranchAddress("ehcal", &ehcal2);

  //
  // Setup a branch 3
  //
  Float_t eecal3 = 0;
  Float_t ehcal3 = 0;
  tree3->SetBranchAddress("eecal", &eecal3);
  tree3->SetBranchAddress("ehcal", &ehcal3);

  //
  // Create a histograms
  //
  hist1 = new TH1F("hist1", "hist1", nBins, binLo, binHi1);
  hist2 = new TH1F("hist2", "hist2", nBins, binLo, binHi2);
  hist3 = new TH1F("hist3", "hist3", nBins, binLo, binHi3);

  for ( int i = 0; i <nEvents1; i++ ) {
    tree1 -> GetEntry(i);
    if ( (eecal1 < 1.5)  && ( ehcal1 > cut1 )) hist1 -> Fill( ehcal1 + eecal1);
  }

  for ( int i = 0; i <nEvents2; i++ ) {
    tree2 -> GetEntry(i);
    if ( (eecal2 < 1.5)  && ( ehcal2 > cut2 )) hist2 -> Fill( ehcal2 + eecal2);
  }

  for ( int i = 0; i <nEvents3; i++ ) {
    tree3 -> GetEntry(i);
    if ( (eecal3 < 1.5)  && ( ehcal3 > cut3 )) hist3 -> Fill( ehcal3 + eecal3);
  }

  cout << "Entries1:   " << hist1->GetEntries() << endl;
  cout << "Entries2:   " << hist2->GetEntries() << endl;
  cout << "Entries3:   " << hist3->GetEntries() << endl;
  
  hist1->Scale(1. / float( hist1->GetEntries() ) );
  hist2->Scale(1. / float( hist2->GetEntries() ) );
  hist3->Scale(1. / float( hist3->GetEntries() ) );

  c1->cd();
  hist1->SetMarkerStyle(20);
  hist1->SetMarkerColor(kRed);
  hist1->DrawCopy("p e");
 
  hist2->SetMarkerStyle(21);
  hist2->SetMarkerColor(kBlue);
  hist2->DrawCopy("p e SAME");

  hist3->SetMarkerStyle(22);
  hist3->SetMarkerColor(kGreen);
  hist3->DrawCopy("p e SAME");

  TLegend *lsc = new TLegend(0.55,0.62,0.90,0.92);
  lsc->AddEntry(hist1,"nodigi","pl");
  lsc->AddEntry(hist2,"digi(20%)","pl");
  lsc->AddEntry(hist3,"60digi(60%)","pl");
  lsc->Draw();

//  delete hist;
//  file -> Close();

}
