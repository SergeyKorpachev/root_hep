//TCanvas *c1;
//TCanvas *c2;
//TCanvas *c3;

void res(const char *fname = "./results/no/nodigi_gun_k0L_20GeV_iso_5000evt_ILD_l5_v02_FTFP_BERT.root", const char *fOutName = "no_out.root") {

  //
  // Some common variables
  //
  const char *treeName = "Tree";
  const int nBins = 1000;
  const float binLo = 0.0;
  const float binHi = 100.0;

//  if ( gROOT->GetListOfCanvases()->FindObject("c1") == NULL ) c1 = new TCanvas("c1", "c1", 1);
//  if ( gROOT->GetListOfCanvases()->FindObject("c2") == NULL ) c2 = new TCanvas("c2", "c2", 1);
//z  if ( gROOT->GetListOfCanvases()->FindObject("c3") == NULL ) c3 = new TCanvas("c3", "c3", 1);

//  gStyle->SetOptStat(0);  

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
  Float_t Energy = 0;
  Float_t feta = 0;
  Float_t eecal = 0;
  Float_t ehcal = 0;
  tree->SetBranchAddress("Energy", &Energy);
  tree->SetBranchAddress("feta", &feta);  
  tree->SetBranchAddress("eecal", &eecal);  
  tree->SetBranchAddress("ehcal", &ehcal);  

  //
  // Create a histogram and random generator
  //
  TH1F *hb = new TH1F("hb", "hb", nBins, binLo, binHi);
  TH1F *he = new TH1F("he", "he", nBins, binLo, binHi);
  TH1F *hr = new TH1F("hr", "hr", nBins, binLo, binHi);

  for (unsigned int i = 0; i <nEvents; i++) {
    tree -> GetEntry(i);
    if ( eecal < 0.02 ) {
       if ( ( feta < 1.3 ) && ( feta > -1.3 ) ) hb -> Fill( Energy );
       if ( ( ( feta < 2.5 ) && ( feta > 1.5 ) ) || ( ( feta < -1.5 ) && ( feta > -2.5 ) ) ) he -> Fill( Energy );
       if ( ( ( feta < 1.5 ) && ( feta > 1.3 ) ) || ( ( feta < -1.3 ) && ( feta > -1.5 ) ) ) hr -> Fill( Energy );
    }
  }

  //hb->Rebin();
  //hb->GetXaxis()->SetRangeUser(0, 200);

  //--- Plot
/*  c1->cd();
  hb->Draw();
  c2->cd();
  he->Draw();
  c3->cd();
  hr->Draw();

  ehcal1->SetMarkerStyle(20);
  ehcal1->SetMarkerColor(kRed);
  ehcal1->DrawCopy("p e");
  fitFunc1->SetLineColor(kRed);
  fitFunc1->SetLineWidth(2);
  fitFunc1->Draw("SAME");

  ehcal2->SetMarkerStyle(21);
  ehcal2->SetMarkerColor(kBlue);
  ehcal2->DrawCopy("p e SAME");
  fitFunc2->SetLineColor(kBlue);
  fitFunc3->SetLineWidth(2);
  fitFunc2->Draw("SAME");

  ehcal3->SetMarkerStyle(22);
  ehcal3->SetMarkerColor(kGreen);
  ehcal3->DrawCopy("p e SAME");
  fitFunc3->SetLineColor(kGreen);
  fitFunc3->SetLineWidth(2);
  fitFunc3->Draw("SAME");
*/

  fOut->cd();
  hb->Write();
  he->Write();
  hr->Write();
  fOut->Write();
  fOut->Close();
  file->Close();

}
