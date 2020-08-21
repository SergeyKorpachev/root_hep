void ccc ()
{
  //
  // Some common variables
  //
  const int nBins = 200;
  const float binLo = 0.0;
  const float binHi = 600.0;
  const float gMean = 2.0;
  const float gSigma = 3.0;
  
  //
  // Open file
  //
  std::cout << "File open... ";
  TFile *file = new TFile("/home/korpachev/Desktop/result_newnew/1.0/AAAAAAA.root", "r");
  if (!file) {
   std::cout << "[FAIL]\n" << std::endl;
   return 0;
  } else std::cout << "[OK]" << std::endl;

  //
  // Create an output file
  //
  std::cout << "Trying to create output file... ";
  TFile *fOut = new TFile("out_AAAAAAA.root", "RECREATE");
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
  TTree *tree = (TTree *)file->Get("DRTile");
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

//  hPhotonInSipm->Rebin();
//  hPhotonInSipm->GetXaxis()->SetRangeUser(0, 200);

  fOut->cd();
  hPhotonInSipm_without_trigger->Write();
  hPhotonInSipm->Write();
  copy_from_in_file->Write();
  fOut->Write();
  fOut->Close();
  file->Close();

  printf("All is ok :)\n");

}
