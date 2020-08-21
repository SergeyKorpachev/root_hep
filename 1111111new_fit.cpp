void new_fit() {
    TFile *file = new TFile("flat_scint3_box15_gap01_xz2mm_e200.root");
    TH1F *hist; 
    TF1 *fitFunc1;
    TF1 *fitFunc2;

   /* printf("File open... ");
    if (!file) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");
   */ 

    printf("Loading histogram... ");
    hist = (TH1F *)file->Get("fCounterSipm");
  /*  if (!hist1) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");
  */

    fitFunc1 = new TF1("fitFunc1", "gaus");
    hist->Fit(fitFunc1);
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

   hist->Draw();

  /* FILE *file = fopen("mean2.txt", "a+");
       printf("File open... ");
       if (!file) {
          printf("[FAIL]\n");
          return 0;
       } else printf("[OK]\n");
   fprintf(file, "%E\n", mean2);
   // fclose(file);

   FILE *file1 = fopen("sigma2.txt", "a+");
       printf("File open... ");
       if (!file1) {
          printf("[FAIL]\n");
          return 0;
       } else printf("[OK]\n");
   fprintf(file1, "%E\n", sigma2);
 */  // fclose(file1);

    
}
