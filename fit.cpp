void fit() {
    TFile *file = new TFile("out_x1.5_z1.5-1.root");
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
    hist = (TH1F *)file->Get("hPhotonInSipm");
    if (!hist) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");

    fitFunc1 = new TF1("fitFunc1", "gaus");

    hist->GetYaxis()->SetTitle("Number of events");
    hist->GetXaxis()->SetTitle("Number of photons");
    hist->Fit(fitFunc1, "0");
    float mean1 = fitFunc1->GetParameter(1);
    float sigma1 = fitFunc1->GetParameter(2);
    std::cout << "Mean1 : " << mean1 << std::endl;
    std::cout << "Sigma1 : " << sigma1 << std::endl;


   fitFunc2 = new TF1("fitFunc2", "gaus", mean1 - sigma1, mean1 + sigma1);
   hist->Fit(fitFunc2, "R");
   float mean2 = fitFunc2->GetParameter(1);
   float sigma2 = fitFunc2->GetParameter(2);
   std::cout << "Mean2 : " << mean2 << std::endl;
   std::cout << "Sigma2 : " << sigma2 << std::endl;

//   int flag = 0;
//   double chi2 = 0;
//   chi2 = fitFunc2->GetChisquare() / fitFunc2->GetNDF();
//   if (chi2 > 5) flag = 1;
    
//   c1->SaveAs("pic.jpg");

   hist->Draw();

/*   FILE *out = fopen("out.txt", "a+");
       printf("File open... ");
       if (!out) {
          printf("[FAIL]\n");
          return 0;
       } else printf("[OK]\n");
   fprintf(out,"%i %E %E %E %i\n", a, mean2, sigma2, chi2, flag);
  // out << mean2 << " " << sigma2 << " " << chi2 << " " << flag << std::endl;
  //  fclose(out);
*/
}
