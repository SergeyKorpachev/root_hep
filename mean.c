void mean ()
{
  TF1 *fitFunc;
 
  TCanvas *c1 = new TCanvas("c1", "c1", 1);
  
  FILE* file = fopen("/home/root1/Desktop/processing/out.txt", "r");
  TH1F* hist = new TH1F("hist","hist",300,0.,10.);

  std::cout << "File open... " << std::endl;
  if (!file) {
   std::cout << "[FAIL]\n" << std::endl;
   return 0;
  } else std::cout << "[OK]" << std::endl;

  Int_t a = 0;
  Char_t buf[0xFF];
  while( feof(file) == 0 ) {
    fscanf ( file,"%d", &a);
    fgets( buf, 0xFF, file );
    // ---------------------------------------------
    if ( a >= 0  ) hist->Fill( a );
    //----------------------------------------------
    a = 0;
    }
/* 
// hist->GetXaxis()->SetRangeUser(300, 1600);
  fitFunc = new TF1("fitFunc", "gaus");
  hist->Fit(fitFunc);

  Float_t mean = fitFunc->GetParameter(1);
  Float_t sigma = fitFunc->GetParameter(2);
  Double_t chi2 = 0;
  chi2 = fitFunc->GetChisquare() / fitFunc->GetNDF();
  FILE *out = fopen("out.txt", "a+");
     printf("File open... ");
     if (!out) {
        printf("[FAIL]\n");
        return 0;
     } else printf("[OK]\n");
  fprintf(out,"%E\n", mean);	
  fclose(out);
*/
  hist->Draw();
  c1->SaveAs("mean.jpg");
  fclose( file );

}
