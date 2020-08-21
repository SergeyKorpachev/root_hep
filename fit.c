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

//void fit(int nb, float ll, float rl) {
void fit() {

  if ( gROOT->GetListOfCanvases()->FindObject("c1") == NULL ) c1 = new TCanvas("c1", "c1", 1);
//  if ( gROOT->GetListOfCanvases()->FindObject("c2") == NULL ) c2 = new TCanvas("c2", "c2", 1);
//  if ( gROOT->GetListOfCanvases()->FindObject("c3") == NULL ) c3 = new TCanvas("c3", "c3", 1);

  gStyle->SetOptStat(0);  

  const char *fname1 = "./../with/with_5gun_k0L_5GeV_iso_2000evt_ILD_l1_v02_FTFP_BERT.root";
  const char *fname2 = "./../without/without_5gun_k0L_5GeV_iso_2000evt_ILD_l1_v02_FTFP_BERT.root";

  const char *fOutName1 = "./out_with_5gun_k0L_5GeV_iso_2000evt_ILD_l1_v02_FTFP_BERT.root";
  const char *fOutName2 = "./out_without_5gun_k0L_5GeV_iso_2000evt_ILD_l1_v02_FTFP_BERT.root";

  //
  // Some common variables
  //

  const char *treeName = "Tree";
  const int nBins = 40;
  const float binLo = 0.0;
  const float binHi = 10.0;   //    40 for 20 GeV  and 10 for 5 GeV   and   10 for muon

  // start for first group

  //
  // Open file
  //
  std::cout << "Trying to open file1... ";
  TFile *file1 = new TFile(fname1, "READ");
  if (!file1) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Create an output file
  //
  std::cout << "Trying to create output file1... ";
  TFile *fOut1 = new TFile(fOutName1, "RECREATE");
  if (!fOut1) {
    file1->Close();
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  // end for first group

  // start for second group

  //
  // Open file
  //
  std::cout << "Trying to open file2... ";
  TFile *file2 = new TFile(fname2, "READ");
  if (!file2) { 
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Create an output file
  //
  std::cout << "Trying to create output file2... ";
  TFile *fOut2 = new TFile(fOutName2, "RECREATE");
  if (!fOut2) {
    file2->Close();
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  // end for second group

  // Tree for first group

  //
  // Setup a TTree
  //
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

  //
  // Setup a branch
  //
  Float_t energy1 = 0;
  Float_t trigger1 = 0;
  tree1->SetBranchAddress("ehcal", &energy1);
  tree1->SetBranchAddress("eecal", &trigger1);

  // Tree for second group

  //
  // Setup a TTree
  //
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

  //
  // Setup a branch
  //
  Float_t energy2 = 0;
  Float_t trigger2 = 0;
  tree2->SetBranchAddress("ehcal", &energy2);
  tree2->SetBranchAddress("eecal", &trigger2);

  //
  // Create a histograms
  //

  TH1F *ehcal1 = new TH1F("ehcal1", "Kaon0L 5 GeV", nBins, binLo, binHi); // Kaon0L 20 GeV      and    Kaon0L 5 GeV    and Muon 10 GeV
  TH1F *ehcal2 = new TH1F("ehcal2", "Kaon0L 5 GeV", nBins, binLo, binHi); // Kaon0L 20 GeV      and    Kaon0L 5 GeV    and Muon 10 GeV

  // For first tree

  for (unsigned int i = 0; i <nEvents1; i++) {
    tree1->GetEntry(i);
//     cout << "trigger1 === " << trigger1 << endl;  
    if (trigger1 < 1) {
      ehcal1->Fill(energy1);
//     cout << "energy1 === " << energy1 << endl;  
    }
  }

  // For second tree

  for (unsigned int i = 0; i <nEvents2; i++) {
    tree2->GetEntry(i);
//     cout << "trigger2 === " << trigger2 << endl;  
    if (trigger2 < 1) {
      ehcal2->Fill(energy2);
//     cout << "energy2 === " << energy2 << endl;  
    }  
  }

  ehcal1->GetYaxis()->SetTitle("Number of events");
  ehcal1->GetXaxis()->SetTitle("Energy, GeV");

  ehcal2->GetYaxis()->SetTitle("Number of events");
  ehcal2->GetXaxis()->SetTitle("Energy, GeV");

//  cout << "Entries1 === " << ehcal1->GetEntries() << endl;
//  cout << "Entries2 === " << ehcal2->GetEntries() << endl;

  //ehcal1->Rebin();
  //ehcal1->GetXaxis()->SetRangeUser(0, 30);

  fOut1->cd();
  ehcal1->Write();
  fOut1->Write();
  fOut1->Close();

  fOut2->cd();
  ehcal2->Write();
  fOut2->Write();
  fOut2->Close();

  file1->Close();
  file2->Close();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  TFile *f1 = new TFile("out_with_5gun_k0L_5GeV_iso_2000evt_ILD_l1_v02_FTFP_BERT.root");
  TFile *f2 = new TFile("out_without_5gun_k0L_5GeV_iso_2000evt_ILD_l1_v02_FTFP_BERT.root");

  TH1F *hist1;
  TH1F *hist2;
  TF1 *fitFunc1;
  TF1 *fitFunc2;

  // for 1 file

  printf("File open fit1... ");
  if (!f1) {
      printf("[FAIL]\n");
      return 0;
  } else printf("[OK]\n");

  // for 2 file

  printf("File open fit2... ");
  if (!f2) {
      printf("[FAIL]\n");
      return 0;
  } else printf("[OK]\n");

  printf("Loading two histograms for fitting... ");

  hist1 = (TH1F *)f1->Get("ehcal1");
  hist1->GetXaxis()->SetRangeUser(1, 10);   //    10:40 for 20 GeV and 1:10 for 5 GeV   and   0:5 for muon
  hist2 = (TH1F *)f2->Get("ehcal2");
  hist2->GetXaxis()->SetRangeUser(1, 10);   //    10:40 for 20 GeV and 1:10 for 5 GeV   and   0:5 for muon

  // for 1 file

  if (!hist1) {
      printf("[FAIL]\n");
      return 0;
  } else printf("[OK]\n");

  // for 2 file

  if (!hist1) {
      printf("[FAIL]\n");
      return 0;
  } else printf("[OK]\n");

 // Fit analysis for 1

 // Fit for muon ----------------------------------------------------------------------------------------
/*
  TF1 *ff1 = new TF1("ff1",langaufun,ll,rl,4);  //    0.5:3 for muon 
  ff1->SetParameters(0.2*hist1->GetMean(),
		    hist1->GetMean(),
		    double(hist1->GetEntries()),
		    0.2*hist1->GetMean());
  ff1->SetParNames("Width","MP","Area","GSigma");
  hist1->Fit(ff1,"Q0R");
  std::cout << "Fit result for 1: " << std::endl
	    << " MPV = " << ff1->GetParameter(1) << "+-" << ff1->GetParError(1) << std::endl
	    << " Lwidth = " << ff1->GetParameter(0) << "+-" << ff1->GetParError(0) << std::endl
	    << " Gwidth = " << ff1->GetParameter(3) << "+-" << ff1->GetParError(3) << std::endl
	    << " Scale = " << ff1->GetParameter(2) << "+-" << ff1->GetParError(2) << std::endl
	    << "    chi2/ndf = " << ff1->GetChisquare() << " / " << ff1->GetNDF() 
	    << " = " << ff1->GetChisquare()/ff1->GetNDF()
	    << std::endl;

  //--- plot result
//  gStyle->SetOptStat(1110);
//  gStyle->SetOptFit(1111);

  TF1 *ff2 = new TF1("ff2",langaufun,ll,rl,4);  //    0.5:3 for muon 
  ff2->SetParameters(0.2*hist2->GetMean(),
		    hist2->GetMean(),
		    double(hist2->GetEntries()),
		    0.2*hist2->GetMean());
  ff2->SetParNames("Width","MP","Area","GSigma");
  hist2->Fit(ff2,"Q0R");
  std::cout << "Fit result for 2: " << std::endl
	    << " MPV = " << ff2->GetParameter(1) << "+-" << ff2->GetParError(1) << std::endl
	    << " Lwidth = " << ff2->GetParameter(0) << "+-" << ff2->GetParError(0) << std::endl
	    << " Gwidth = " << ff2->GetParameter(3) << "+-" << ff2->GetParError(3) << std::endl
	    << " Scale = " << ff2->GetParameter(2) << "+-" << ff2->GetParError(2) << std::endl
	    << "    chi2/ndf = " << ff2->GetChisquare() << " / " << ff2->GetNDF() 
	    << " = " << ff2->GetChisquare()/ff2->GetNDF()
	    << std::endl;

  //--- plot result
//  gStyle->SetOptStat(1110);
//  gStyle->SetOptFit(1111);
*/
 // -----------------------------------------------------------------------------------------------------



  fitFunc1 = new TF1("fitFunc1", "gaus", 2,7);  //    15:27 for 20 GeV and 2:7 for 5 GeV   and   0.5:3 for muon
  hist1->Fit(fitFunc1,"Q0R");
  Float_t mean1 = fitFunc1->GetParameter(1);
  Float_t sigma1 = fitFunc1->GetParameter(2);
  std::cout << "gMean1 : " << mean1 << std::endl;
  std::cout << "gSigma1 : " << sigma1 << std::endl;

  Double_t chi21 = 0;
  chi21 = fitFunc1->GetChisquare() / fitFunc1->GetNDF();
  std::cout << "g(Chi^2/NDF)1 : " << chi21 << std::endl;

 // Fit analysis for 2

  fitFunc2 = new TF1("fitFunc2", "gaus", 2, 7);  //    15:27 for 20 GeV and 2:7 for 5 GeV   and   0.5:3 for muon
  hist2->Fit(fitFunc2,"Q0R");
  Float_t mean2 = fitFunc2->GetParameter(1);
  Float_t sigma2 = fitFunc2->GetParameter(2);
  std::cout << "gMean2 : " << mean2 << std::endl;
  std::cout << "gSigma2 : " << sigma2 << std::endl;

  Double_t chi22 = 0;
  chi22 = fitFunc2->GetChisquare() / fitFunc2->GetNDF();
  std::cout << "g(Chi^2/NDF)2 : " << chi22 << std::endl;



/*  c1->cd();
  hist1->SetMarkerStyle(20);
  hist1->SetMarkerColor(kRed);
  hist1->DrawCopy("p e");
  fitFunc1->Draw("SAME");

  c2->cd();
  hist2->SetMarkerStyle(20);
  hist2->SetMarkerColor(kBlue);
  hist2->DrawCopy("p e");
  fitFunc2->SetLineColor(kBlue);
  fitFunc2->Draw("SAME");
*/
  c1->cd();
/*  hist1->DrawCopy("hist e");
  fitFunc1->SetLineColor(kBlue);
  fitFunc1->DrawCopy("SAME");
  hist2->SetLineColor(kRed);
  hist2->DrawCopy("hist e SAME");
  fitFunc2->Draw("SAME");
*/
  hist1->SetMarkerStyle(20);
  hist1->SetMarkerColor(kRed);
  hist1->DrawCopy("p e");
  fitFunc1->Draw("SAME");
//  ff1->Draw("SAME");

  hist2->SetMarkerStyle(20);
  hist2->SetMarkerColor(kBlue);
  hist2->DrawCopy("p e SAME");
  fitFunc2->SetLineColor(kBlue);
  fitFunc2->Draw("SAME");
//  ff2->SetLineColor(kBlue);
//  ff2->Draw("SAME");

  TLegend *lsc = new TLegend(0.55,0.62,0.90,0.92);
  lsc->AddEntry(hist1,"With smearing","pl");
  lsc->AddEntry(hist2,"Without smearing","pl");
  lsc->Draw();

//  f1->Close();
//  f2->Close();

}

