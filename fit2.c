TCanvas *c1;
//TCanvas *c2;
//TCanvas *c3;

Double_t langaufun(Double_t *x, Double_t *par) {

   //Fit parameters:
   //par[0]=Width (scale) parameter of Landau density
   //par[1]=Most Probable (MP, location) parameter of Landau density
   //par[2]=Total area (integral -inf to inf, normalization constant)
   //par[3]=Width (sigma) of convoluted Gaussian function
   //
   //In the Landau distribution (represented by the CERNLIB approximation), 
   //the maximum is located at x=-0.22278298 with the location parameter=0.
   //This shift is corrected within this function, so that the actual
   //maximum is identical to the MP parameter.

      // Numeric constants
      Double_t invsq2pi = 0.3989422804014;   // (2 pi)^(-1/2)
      Double_t mpshift  = 0; //-0.22278298;       // Landau maximum location

      // Control constants
      Double_t np = 300; //nstp; //100.0;      // number of convolution steps
      Double_t sc = 5.0;      // convolution extends to +-sc Gaussian sigmas

      // Variables
      Double_t xx;
      Double_t mpc;
      Double_t fland;
      Double_t sum = 0.0;
      Double_t xlow,xupp;
      Double_t step;
      Double_t i;


      // MP shift correction
      mpc = par[1] - mpshift * par[0]; 

      // Range of convolution integral
      xlow = x[0] - sc * par[3];
      xupp = x[0] + sc * par[3];

      step = (xupp-xlow) / np;

      // Convolution integral of Landau and Gaussian by sum
      for(i=1.0; i<=np/2; i++) {
         xx = xlow + (i-.5) * step;
         fland = TMath::Landau(xx,mpc,par[0]) / par[0];
         sum += fland * TMath::Gaus(x[0],xx,par[3]);

         xx = xupp - (i-.5) * step;
         fland = TMath::Landau(xx,mpc,par[0]) / par[0];
         sum += fland * TMath::Gaus(x[0],xx,par[3]);
      }

      return (par[2] * step * sum * invsq2pi / par[3]);
}
//=====================================================================
void fit(int nBins = 40,
	 float binLo = 0.0,
	 float binHi = 10.0,
	 float lfit = 3,
	 float rfit = 7)   //    40 for 20 GeV  and 10 for 5 GeV   and   10 for muon
{

  if ( gROOT->GetListOfCanvases()->FindObject("c1") == NULL ) c1 = new TCanvas("c1", "c1", 1);
//  if ( gROOT->GetListOfCanvases()->FindObject("c2") == NULL ) c2 = new TCanvas("c2", "c2", 1);
//  if ( gROOT->GetListOfCanvases()->FindObject("c3") == NULL ) c3 = new TCanvas("c3", "c3", 1);

  gStyle->SetOptStat(0);  

  TH1F *ehcal1 = new TH1F("ehcal1", "Kaon0L 5 GeV", nBins, binLo, binHi); // Kaon0L 20 GeV      and    Kaon0L 5 GeV    and Muon 10 GeV
  TH1F *ehcal2 = new TH1F("ehcal2", "Kaon0L 5 GeV", nBins, binLo, binHi); // Kaon0L 20 GeV      and    Kaon0L 5 GeV    and Muon 10 GeV
  TH1F *ehcal3 = new TH1F("ehcal2", "Kaon0L 5 GeV", nBins, binLo, binHi); // Kaon0L 20 GeV      and    Kaon0L 5 GeV    and Muon 10 GeV

  //fit(45,0.95,12.5,2.1,7.5)
  const char *fname1 = "./../without/without_5gun_k0L_5GeV_iso_2000evt_ILD_l1_v02_FTFP_BERT.root";
  const char *fname2 = "./../with/with_5gun_k0L_5GeV_iso_2000evt_ILD_l1_v02_FTFP_BERT.root";
  const char *fname3 = "./../with/0.4_with_5gun_k0L_5GeV_iso_2000evt_ILD_l1_v02_FTFP_BERT.root";

  //
  // Some common variables
  //
  const char *treeName = "Tree";
  //============================
  // Open file 1 and fill tree 1
  //============================
  std::cout << "Trying to open file1... ";
  TFile *file1 = new TFile(fname1, "READ");
  if (!file1) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;
  std::cout << "Setup a tree1... ";
  TTree *tree1 = (TTree *)file1->Get(treeName);
  if (!tree1) {
    std::cout << "[FAIL]" << std::endl;
    file1->Close();
    return;
  }
  std::cout << "[OK]" << std::endl;
  unsigned int nEvents1 = tree1->GetEntries();
  //cout << "nEvents1 === " << nEvents1 << endl;
  Float_t energy1 = 0;
  Float_t trigger1 = 0;
  tree1->SetBranchAddress("ehcal", &energy1);
  tree1->SetBranchAddress("eecal", &trigger1);
  for (unsigned int i = 0; i <nEvents1; i++) {
    tree1->GetEntry(i);
//     cout << "trigger1 === " << trigger1 << endl;  
    if (trigger1 < 1) {
      ehcal1->Fill(energy1);
//     cout << "energy1 === " << energy1 << endl;  
    }
  }
  delete tree1;
  file1->Close();

  //============================
  // Open file 2 and fill tree 2
  //============================
  std::cout << "Trying to open file2... ";
  TFile *file2 = new TFile(fname2, "READ");
  if (!file2) { 
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;
  std::cout << "Setup a tree2... ";
  TTree *tree2 = (TTree *)file2->Get(treeName);
  if (!tree2) {
    std::cout << "[FAIL]" << std::endl;
    file2->Close();
    return;
  }
  std::cout << "[OK]" << std::endl;
  unsigned int nEvents2 = tree2->GetEntries();
  //cout << "nEvents2 === " << nEvents2 << endl;
  Float_t energy2 = 0;
  Float_t trigger2 = 0;
  tree2->SetBranchAddress("ehcal", &energy2);
  tree2->SetBranchAddress("eecal", &trigger2);

  for (unsigned int i = 0; i <nEvents2; i++) {
    tree2->GetEntry(i);
//     cout << "trigger2 === " << trigger2 << endl;  
    if (trigger2 < 1) {
      ehcal2->Fill(energy2);
//     cout << "energy2 === " << energy2 << endl;  
    }  
  }
  delete tree2;
  file2->Close();

  //============================
  // Open file 3 and fill tree 3
  //============================
  std::cout << "Trying to open file1... ";
  TFile *file3 = new TFile(fname3, "READ");
  if (!file3) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;
  std::cout << "Setup a tree3... ";
  TTree *tree3 = (TTree *)file3->Get(treeName);
  if (!tree3) {
    std::cout << "[FAIL]" << std::endl;
    file3->Close();
    return;
  }
  std::cout << "[OK]" << std::endl;
  unsigned int nEvents3 = tree3->GetEntries();
  //cout << "nEvents1 === " << nEvents1 << endl;
  Float_t energy3 = 0;
  Float_t trigger3 = 0;
  tree3->SetBranchAddress("ehcal", &energy3);
  tree3->SetBranchAddress("eecal", &trigger3);
  for (unsigned int i = 0; i <nEvents3; i++) {
    tree3->GetEntry(i);
//     cout << "trigger1 === " << trigger1 << endl;  
    if (trigger3 < 1) {
      ehcal3->Fill(energy3);
//     cout << "energy1 === " << energy1 << endl;  
    }
  }
  delete tree3;
  file3->Close();

  //==========================
  // Plot and fit
  //==========================
  ehcal1->GetYaxis()->SetTitle("Number of events");
  ehcal1->GetXaxis()->SetTitle("Energy, GeV");
  ehcal1->GetXaxis()->SetRangeUser(binLo, binHi);   //    10:40 for 20 GeV and 1:10 for 5 GeV   and   0:5 for muon

  TF1 *fitFunc1;
  TF1 *fitFunc2;
  TF1 *fitFunc3;

  //--- Fit hist 1 
  fitFunc1 = new TF1("fitFunc1", "gaus", lfit, rfit);  //    15:27 for 20 GeV and 2:7 for 5 GeV   and   0.5:3 for muon
  ehcal1->Fit(fitFunc1,"Q0R");
  Float_t mean1 = fitFunc1->GetParameter(1);
  Float_t sigma1 = fitFunc1->GetParameter(2);
  std::cout << "gMean1 : " << mean1 << std::endl;
  std::cout << "gSigma1 : " << sigma1 << std::endl;
  Double_t chi21 = 0;
  chi21 = fitFunc1->GetChisquare() / fitFunc1->GetNDF();
  std::cout << "g(Chi^2/NDF)1 : " << chi21 << std::endl;

  //--- Fit hist 2
  fitFunc2 = new TF1("fitFunc2", "gaus", lfit, rfit);  //    15:27 for 20 GeV and 2:7 for 5 GeV   and   0.5:3 for muon
  ehcal2->Fit(fitFunc2,"Q0R");
  Float_t mean2 = fitFunc2->GetParameter(1);
  Float_t sigma2 = fitFunc2->GetParameter(2);
  std::cout << "gMean2 : " << mean2 << std::endl;
  std::cout << "gSigma2 : " << sigma2 << std::endl;
  Double_t chi22 = 0;
  chi22 = fitFunc2->GetChisquare() / fitFunc2->GetNDF();
  std::cout << "g(Chi^2/NDF)2 : " << chi22 << std::endl;

  //--- Fit hist 3 
  fitFunc3 = new TF1("fitFunc3", "gaus", lfit, rfit);  //    15:27 for 20 GeV and 2:7 for 5 GeV   and   0.5:3 for muon
  ehcal3->Fit(fitFunc3,"Q0R");
  Float_t mean3 = fitFunc3->GetParameter(1);
  Float_t sigma3 = fitFunc3->GetParameter(2);
  std::cout << "gMean3 : " << mean3 << std::endl;
  std::cout << "gSigma3 : " << sigma3 << std::endl;
  Double_t chi23 = 0;
  chi23 = fitFunc3->GetChisquare() / fitFunc3->GetNDF();
  std::cout << "g(Chi^2/NDF)3 : " << chi23 << std::endl;

  //--- Plot
  c1->cd();
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

  TLegend *lsc = new TLegend(0.55,0.62,0.90,0.92);
  lsc->AddEntry(ehcal1,"Without smearing","pl");
  lsc->AddEntry(ehcal2,"20% smearing","pl");
  lsc->AddEntry(ehcal3,"40% smearing","pl");
  lsc->Draw();

}

