TCanvas *c1;

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

void fit1() {  //   After Digi

  const char *fname = "./up/dmp_ag10um_4.00_1.6_x5.5_z5.5mm_ds1.00_3000evt.root";
  const char *fOutName = "./up/out/out_dmp_ag10um_4.00_1.6_x5.5_z5.5mm_ds1.00_3000evt.root";

  TRandom2 *ranGen = new TRandom2();
  ranGen->SetSeed(0);

  if ( gROOT->GetListOfCanvases()->FindObject("c1") == NULL ) c1 = new TCanvas("c1", "c1", 1);

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

  //
  // Open file
  //
  std::cout << "Trying to open file... ";
  TFile *file = new TFile(fname, "READ");
  if (!file) {
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

  fOut->cd();
  hPhotonInSipm_without_trigger->Write();
  hPhotonInSipm->Write();
  copy_from_in_file->Write();
  fOut->Write();
  fOut->Close();
  file->Close();


  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



  TFile *filenew = new TFile("./up/out/out_dmp_ag10um_4.00_1.6_x5.5_z5.5mm_ds1.00_3000evt.root");

  TH1F *histnew;

  printf("File open... ");
  if (!filenew) {
      printf("[FAIL]\n");
      return 0;
  } else printf("[OK]\n");

  printf("Loading histogram... ");

  histnew = (TH1F *)filenew->Get("hPhotonInSipm");

  if (!histnew) {
      printf("[FAIL]\n");
      return 0;
  } else printf("[OK]\n"); 

  TF1 *ff1 = new TF1("ff1",langaufun,0,80,4);
  ff1->SetParameters(0.1*histnew->GetMean(),
		    histnew->GetMean(),
		    double(histnew->GetEntries()),
		    0.1*histnew->GetMean());
  ff1->SetParNames("Width","MP","Area","GSigma");
  histnew->Fit(ff1,"Q0R");
  std::cout << "Fit result for 1: " << std::endl
	    << " MPV = " << ff1->GetParameter(1) << "+-" << ff1->GetParError(1) << std::endl
	    << " Lwidth = " << ff1->GetParameter(0) << "+-" << ff1->GetParError(0) << std::endl
	    << " Gwidth = " << ff1->GetParameter(3) << "+-" << ff1->GetParError(3) << std::endl
	    << " Scale = " << ff1->GetParameter(2) << "+-" << ff1->GetParError(2) << std::endl
	    << "    chi2/ndf = " << ff1->GetChisquare() << " / " << ff1->GetNDF() 
	    << " = " << ff1->GetChisquare()/ff1->GetNDF()
	    << std::endl;
  
  c1->cd();

  histnew->DrawCopy();
  ff1->Draw("SAME");

}
