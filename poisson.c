void poisson(const char *fname = "./up/AAAAA.root", const char *fOutName = "./up/1/1out_AAAAA.root") {

  TRandom2 *ranGen = new TRandom2();
  ranGen->SetSeed(0);

  //
  // Some common variables
  //
  const char *treeName = "DRTile";
  const int nBins = 400;
  const float binLo = 0.0;
  const float binHi = 200.0;
  const float gMean = 3.0;
  const float gSigma = 1.5;
  const float eff = 0.15;

//   std::cout << " gSigma == " << gSigma << std::endl;

  //
  // Open file
  //
  std::cout << "Trying to open file... ";
  TFile *file = new TFile(fname, "READ");
  if (!file) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Create an output file
  //
  std::cout << "Trying to create output file... ";
  TFile *fOut = new TFile(fOutName, "RECREATE");
  if (!fOut) {
    file->Close();
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Setup a TTree
  //
  std::cout << "Setup a tree... ";
  TTree *tree = (TTree *)file->Get(treeName);
  TH1F *hist = (TH1F *)file->Get("fCounterSipm");
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
  Double_t photonsInSipm = 0;
  Double_t trigger = 0;
  tree->SetBranchAddress("photonsInSipm", &photonsInSipm);
  tree->SetBranchAddress("trigger", &trigger);  

  //
  // Create a histogram and random generator
  //
  TH1F *hPhotonInSipm = new TH1F("hPhotonInSipm", "hPhotonInSipm", nBins, binLo, binHi);
  TH1F *hPhotonInSipm_without_trigger = new TH1F("hPhotonInSipm_without_trigger", "hPhotonInSipm_without_trigger", nBins, binLo, binHi);

  for (unsigned int i = 0; i <nEvents; i++) {
    tree->GetEntry(i);
    hPhotonInSipm_without_trigger->Fill(photonsInSipm);
    if (trigger == 1) {
      float nPhCorr = ranGen->Poisson(eff * photonsInSipm) + ranGen->Gaus(gMean, gSigma);
      hPhotonInSipm->Fill(nPhCorr);
    }
  }

  TH1F *copy_from_in_file=(TH1F*)hist->Clone();

  //hPhotonInSipm->Rebin();
//  hPhotonInSipm->GetXaxis()->SetRangeUser(0, 200);

  fOut->cd();
  hPhotonInSipm_without_trigger->Write();
  hPhotonInSipm->Write();
  copy_from_in_file->Write();
  fOut->Write();
  fOut->Close();
  file->Close();
}
