void first(const char *fname = "flat_x1.5_z1.5mm_3000evt.root", const char *fOutName = "out_x1.5_z1.5.root") {

  //
  // Some common variables
  //
  const char *treeName = "DRTile";
  const int nBins = 50;
  const float binLo = 0.0;
  const float binHi = 5.0;
//  const float gMean = 3.0;
//  const float gSigma = 2.0;
//  const double eff = 0.15;

//   std::cout << " gSigma == " << gSigma << std::endl;

  //
  // Create an output file
  //
  std::cout << "[SiPM macro]: Trying to create output file... ";
  TFile *fOut = new TFile(fOutName, "RECREATE");
  if (!fOut) {
    file->Close();
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;
 
  //
  // Open file
  //
  std::cout << "[SiPM macro]: Trying to open file... ";
  TFile *file = new TFile(fname, "READ");
  if (!file) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Setup a TTree
  //
  std::cout << "[SiPM macro]: Setup a tree... ";
  TTree *tree = (TTree *)file->Get(treeName);
  TH1F *hist = (TH1F *)file->Get("fcountE");
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
  Double_t E_first_particle = 0;
  tree->SetBranchAddress("E_first_particle", &E_first_particle); 

  //
  // Create a histogram and random generator
  //
  TH1F *E_first_particle_hist = new TH1F("E_first_particle", "E_first_particle", nBins, binLo, binHi);

  for (unsigned int i = 0; i < nEvents; i++) {
    tree->GetEntry(i);
    E_first_particle_hist->Fill(E_first_particle);
  }

  TH1F *copy_from_in_file=(TH1F*)hist->Clone();
  copy_from_in_file->GetXaxis()->SetRangeUser(1.25, 2.5);

  E_first_particle_hist->GetXaxis()->SetRangeUser(1.25, 2.5);

  fOut->cd();
  E_first_particle_hist->Write();
  copy_from_in_file->Write();
  fOut->Write();
  fOut->Close();
  file->Close();
}
