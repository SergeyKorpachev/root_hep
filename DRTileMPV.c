void DRTileMPV() {
    TFile *file = new TFile("flat_scint3_box15_gap01_xz2mm_e200.root");
    TH1F *hist;
    TF1 *fitFunc1;
    TF1 *fitFunc2;

    TCanvas *c1 = new TCanvas("c1", "c1", 1);

    printf("File open... ");
    if (!file) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");

    printf("Loading histogram... ");
    hist = (TH1F *)file->Get("fCounterSipm");
    if (!hist) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");

      fitFunc1 = new TF1("fitFunc1", "gaus");
 
   // fitFunc->SetParameter(0, 100.); // Amp
  //  fitFunc->SetParameter(1, 46.);   // Mean
  //  fitFunc->SetParameter(2, 0.5);   // Sigma
 //   hY->Fit(fitFunc, "", "", 60., 450.);   

    hist->GetYaxis()->SetTitle("Number of events");
    hist->GetXaxis()->SetTitle("Number of photons");
    hist->Fit(fitFunc1, "0");
    float mean1 = fitFunc1->GetParameter(1);
    float sigma1 = fitFunc1->GetParameter(2);
    std::cout << "Mean1 : " << mean1 << std::endl;
    std::cout << "Sigma1 : " << sigma1 << std::endl;


   fitFunc2 = new TF1("fitFunc2", "gaus", mean1 - 2*sigma1, mean1 + 2*sigma1);
   hist->Fit(fitFunc2, "R");
   float mean2 = fitFunc2->GetParameter(1);
   float sigma2 = fitFunc2->GetParameter(2);
   std::cout << "Mean2 : " << mean2 << std::endl;
   std::cout << "Sigma2 : " << sigma2 << std::endl;
    
   c1->SaveAs("2.jpg");

//   hist->Draw();

   FILE *mean = fopen("mean2.txt", "a+");
       printf("File open... ");
       if (!mean) {
          printf("[FAIL]\n");
          return 0;
       } else printf("[OK]\n");
   fprintf(mean, "%E\n", mean2);
  //  fclose(mean);

    FILE *chi2_old = fopen("chi2-flat-old.txt", "a+");
    printf("File open... ");
    if (!chi2_old) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");

    fprintf(chi2_old, "%E\n", fitFunc1->GetChisquare() / fitFunc1->GetNDF());
    
  //  fclose(chi2_old);

    FILE *chi2 = fopen("chi2-flat.txt", "a+");
    printf("File open... ");
    if (!chi2) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");

    fprintf(chi2, "%E\n", fitFunc2->GetChisquare() / fitFunc2->GetNDF());
    
   // fclose(chi2);

 /*  FILE *sigma = fopen("sigma2.txt", "a+");
       printf("File open... ");
       if (!sigma) {
          printf("[FAIL]\n");
          return 0;
       } else printf("[OK]\n");
   fprintf(sigma, "%E\n", sigma2);
 */  // fclose(sigma);

}
