void sipm1(const char *fname = "tree.root", const char *fOutName = "out.root") {
  //
  // Some common variables
  //
  const char *treeName = "DRTile";
  const int nBins = 200;
  const float binLo = 0.0;
  const float binHi = 2000.0;
  //const float gMean = 0.0;
  const float gSigma = 3.0;
  const float gSigma2 = 5.0;
  const float gSigma3 = 10.0;
  const float gSigma4 = 15.0;

 // TCanvas *c1 = new TCanvas("c1", "c1", 1);

 // c1->Divide(2 , 2);

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
  TH1F *in = new TH1F("in", "in", nBins, 0., 1600.);
  TH1F *in_trigger = new TH1F("in_trigger", "in_trigger", nBins, binLo, binHi);
  TH1F *hPhotonInSipm = new TH1F("hPhotonInSipm", "hPhotonInSipm", nBins, binLo, binHi);
  TH1F *hPhotonInSipm2 = new TH1F("hPhotonInSipm2", "hPhotonInSipm2", nBins, binLo, binHi);
  TH1F *hPhotonInSipm3 = new TH1F("hPhotonInSipm3", "hPhotonInSipm3", nBins, binLo, binHi);
  TH1F *hPhotonInSipm4 = new TH1F("hPhotonInSipm4", "hPhotonInSipm4", nBins, binLo, binHi);
  TRandom *ranGen = new TRandom();

  for (unsigned int i = 0; i < nEvents; i++) {
    tree->GetEntry(i);
    in->Fill(photonsInSipm);
    if (trigger == 1) {
      float nPhCorr = ranGen->Gaus(photonsInSipm, gSigma);
      float nPhCorr2 =ranGen->Gaus(photonsInSipm, gSigma2);
      float nPhCorr3 =ranGen->Gaus(photonsInSipm, gSigma3);
      float nPhCorr4 =ranGen->Gaus(photonsInSipm, gSigma4);
      hPhotonInSipm->Fill(nPhCorr);
    //  hPhotonInSipm->SetLineColor(kGreen);
      hPhotonInSipm2->Fill(nPhCorr2);
      hPhotonInSipm3->Fill(nPhCorr3);
      hPhotonInSipm4->Fill(nPhCorr4);

      in_trigger->Fill(photonsInSipm);
    }
  }

  TH1F *in_copy=(TH1F*)in->Clone();
  TH1F *in_copy_2=(TH1F*)hist->Clone();

  //c1->cd(1);  
  //in->Draw("SAME");
  //c1->cd(2);
  //in_trigger->Draw("SAME");
  //hPhotonInSipm->DRAW("SAME");


  fOut->cd();
  hPhotonInSipm->Write();
  hPhotonInSipm2->Write();
  hPhotonInSipm3->Write();
  hPhotonInSipm4->Write();
  in->Write();
  in_copy->Write();
  in_copy_2->Write();
  in_trigger->Write();

  fOut->Write();
  fOut->Close();
  file->Close();
}
