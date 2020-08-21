void sipm2(const char *fname = "flat_scint3_box15_gap01_x_z_13.5_13.5mm_e200_5.0.root", const char *fOutName = "out_13.5_5.0.root") {

  //
  // Some common variables
  //
  const char *treeName = "DRTile";
  const int nBins = 200;
  const float binLo = 0.0;
  const float binHi = 1600.0;
  const float gMean = 2.0;
  const float gSigma = 3.0;

   std::cout << " gSigma == " << gSigma << std::endl;

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
  TH1F *hPhotonInSipm = new TH1F("hPhotonInSipm", "hPhotonInSipm", ( nBins / 2.0 ), binLo, 20.0);

  TRandom *ranGen = new TRandom();

  for (unsigned int i = 0; i < nEvents; i++) {
    tree->GetEntry(i);
    hPhotonInSipm_without_trigger->Fill(photonsInSipm);
    if (trigger == 1) {
      float nPhCorr = 0.1 * photonsInSipm + ranGen->Gaus(gMean, gSigma);
      hPhotonInSipm->Fill(nPhCorr);
    }
  }

  TH1F *copy_from_in_file=(TH1F*)hist->Clone();

  //hPhotonInSipm->Rebin();
  hPhotonInSipm->GetXaxis()->SetRangeUser(0, 200);

  fOut->cd();
  hPhotonInSipm_without_trigger->Write();
  hPhotonInSipm->Write();
  copy_from_in_file->Write();
  fOut->Write();
  fOut->Close();
  file->Close();
}
