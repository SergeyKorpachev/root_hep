void ccc ()
{
  TF1 *fitFunc;
  TF1 *fitFunc2;
 
  TCanvas *c1 = new TCanvas("c1", "c1", 1);
  
  FILE* file = fopen("/home/root1/Desktop/diplom/data/result_new/0.0/AAAAAAA.root", "r");
  TH1F* hist = new TH1F("hist","hist",200,0.,1600.);

  std::cout << "File open... " << std::endl;
  if (!file) {
   std::cout << "[FAIL]\n" << std::endl;
   return 0;
  } else std::cout << "[OK]" << std::endl;

  Int_t a = 0;
  Int_t b = 0;
  Char_t buf[0xFF];
  while( feof(file) == 0 ) {
    fscanf ( file,"%d %d", &a, &b );
    fgets( buf, 0xFF, file );
    // ---------------------------------------------
    if ( a == 4  ) hist->Fill( b );
    //----------------------------------------------

    a = b = 0;
    }
  hist->Rebin();
  hist->GetXaxis()->SetRangeUser(400, 1600);

  fitFunc = new TF1("fitFunc", "gaus");
  hist->Fit(fitFunc, "0");

  Float_t mean = fitFunc->GetParameter(1);
  Float_t sigma = fitFunc->GetParameter(2);
  Double_t chi2 = 0;
  chi2 = fitFunc->GetChisquare() / fitFunc->GetNDF();

  fitFunc2 = new TF1("fitFunc2", "gaus", mean - 1.5*sigma, mean + 1.5*sigma);
  hist->Fit(fitFunc2, "R");
  Float_t mean2 = fitFunc2->GetParameter(1);
  Float_t sigma2 = fitFunc2->GetParameter(2);
  Double_t chi22 = 0;
  chi22 = fitFunc2->GetChisquare() / fitFunc2->GetNDF();
  FILE *out = fopen("out.txt", "a+");
     printf("File open... ");
     if (!out) {
        printf("[FAIL]\n");
        return 0;
     } else printf("[OK]\n");
  fprintf(out,"%E\n", mean2);	
  fclose(out);

  if ( ( chi22 > 5 ) || ( chi22 < 0 ) ) c1->SaveAs("fail_AAAAAAA.jpg");

  FILE *out1 = fopen("out_chi22.txt", "a+"); 
     printf("File open... ");
     if (!out1) {
        printf("[FAIL]\n");
        return 0;
     } else printf("[OK]\n");
  fprintf(out1,"%E\n", chi22);   
  fclose(out1);

  hist->Draw();
  c1->SaveAs("AAAAAAA.jpg");
  fclose( file );

}

