void ccc_fit ()
{

  Float_t sigRange = 1.5;
  //const Int_t nrebin = 2;

  TH1F *hist;
  TF1 *fitFunc;
  TF1 *fitFunc2;
 
  TCanvas *c1 = new TCanvas("c1", "c1", 1);
  
  TFile* file = new TFile("/home/korpachev/Desktop/out/1.0/AAAAAAA.root", "r");

  std::cout << "File open... ";
  if (!file) {
   std::cout << "[FAIL]\n" << std::endl;
   return 0;
  } else std::cout << "[OK]" << std::endl;

  printf("Loading histogram... ");
  hist = (TH1F *)file->Get("hPhotonInSipm");
  if (!hist) {
   printf("[FAIL]\n");
   return 0;
  } else printf("[OK]\n");

  //hist->Rebin();
  //hist->GetXaxis()->SetRangeUser(0, 600);

  Int_t nevt = hist->GetEntries();
  Float_t mean = hist->GetMean();
  Float_t sigma = hist->GetRMS();
  std::cout << "  Nevt: " << nevt
	    << "  Mean: " << mean
	    << "  RMS: " << sigma
	    << std::endl;

  if ( nevt < 50 ) {
   std::cout << "No events in signal region." << std::endl;
   delete hist;
   return;
  }

  //Int_t nbinInit = hist->GetNbinsX();
  //Int_t irebin = nbinInit/(nrebin*pow(nevt,1./3));
  //if ( irebin > 1 ) hist->Rebin(irebin);

  fitFunc = new TF1("fitFunc", "gaus", mean - sigRange*sigma, mean + sigRange*sigma);
  hist->Fit(fitFunc, "QR0N" );

  mean = fitFunc->GetParameter(1);
  sigma = fitFunc->GetParameter(2);
  Double_t chi2 = 0;
  chi2 = fitFunc->GetChisquare() / fitFunc->GetNDF();

  int minNDF = 4;
  int curNDF = 0;
  int ncount = 0;
  while ( curNDF < 4 && ncount < 10 ) {
    ncount++;
    fitFunc2 = new TF1("fitFunc2", "gaus", 
		       mean - sigRange*sigma, 
		       mean + sigRange*sigma);
    hist->Fit(fitFunc2, "QR");
    sigRange *= 2;
    curNDF = fitFunc2->GetNDF();
  }

  Float_t mean2 = fitFunc2->GetParameter(1);
  Float_t sigma2 = fitFunc2->GetParameter(2);
  Double_t chi22 = 0;
  chi22 = fitFunc2->GetChisquare() / fitFunc2->GetNDF();

  std::cout << "  Nevt: " << nevt
	    << "  Mean: " << mean2
	    << "  Sigma: " << sigma2
	    << "  Chi2/ndf: " << chi22
	    << std::endl;

  gStyle->SetOptStat(0);
  //gStyle->SetOptFit(111);
  c1->cd();
  fitFunc2->SetLineWidth(3);
  fitFunc2->SetLineColor(2);
  hist->GetXaxis()->SetTitle("Number of electrons");
  hist->GetYaxis()->SetTitle("Number of entries");
  hist->SetLineWidth(2);
  hist->SetLineColor(1);
  c1->Update();

  //hist->Draw();

  FILE *out = fopen("out_1.0.txt", "a+");
  printf("File open... ");
  if (!out) {
     printf("[FAIL]\n");
     return 0;
  } else printf("[OK]\n");
  fprintf(out,"%E %E %E  %E\n", mean2, chi22, fitFunc2->GetChisquare(), fitFunc2->GetNDF());	
  fclose(out);

  if ( ( chi22 > 5 ) || ( chi22 < 0 ) ) c1->SaveAs("fail_AAAAAAA.jpg");
  else 					c1->SaveAs("AAAAAAA.jpg");
  file->Close();

}

