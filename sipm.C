void sipm(const char *fname = "tree.root", const char *fOutName = "out.root") {
  //
  // Some common variables
  //
  const char *treeName = "DRTile";
  const int nBins = 200;
  const float binLo = 0.;
  const float binHi = 1000.;
  //const float gMean = 0.;
  const float gSigma = 3.;

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
  Double_t photonsInSipm;
  tree->SetBranchAddress("photonsInSipm", &photonsInSipm);

  //
  // Create a histogram and random generator
  //
  TH1F *hPhotonInSipm = new TH1F("hPhotonInSipm", "", nBins, binLo, binHi);
  TRandom *ranGen = new TRandom();

  for (unsigned int i = 0; i < nEvents; i++) {
    tree->GetEntry(i);
    float nPhCorr = photonsInSipm + ranGen->Gaus(photonsInSipm, gSigma);
    hPhotonInSipm->Fill(nPhCorr);
  }
  
  fOut->cd();
  hPhotonInSipm->Write();
  fOut->Write();
  fOut->Close();
  file->Close();
}
