void hist() {
    TFile *file2 = new TFile("flat_scint3_box15_gap01_xz2mm_e200.root");
    TFile *file4 = new TFile("flat_scint3_box15_gap01_xz4mm_e200.root");
    TFile *file6 = new TFile("flat_scint3_box15_gap01_xz6mm_e200.root");
    TH1F *hist2; 
    TH1F *hist4;
    TH1F *hist6;
    TF1 *fitFunc2;
    TF1 *fitFunc4;
    TF1 *fitFunc6;

    TCanvas *c1 = new TCanvas("c1", "c1", 1);

    gStyle->SetOptStat(0);  

   /* printf("File open... ");
    if (!file) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");
   */ 

    printf("Loading histogram... ");
    hist2 = (TH1F *)file2->Get("fCounterSipm");
    hist4 = (TH1F *)file4->Get("fCounterSipm");
    hist6 = (TH1F *)file6->Get("fCounterSipm");

  /*  if (!hist1) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");

    if (!hist2) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");
   */

    hist2->Rebin();
    hist4->Rebin();
    hist6->Rebin();

    fitFunc2 = new TF1("fitFunc", "gaus");
    fitFunc4 = new TF1("fitFunc", "gaus");
    fitFunc6 = new TF1("fitFunc", "gaus");

    fitFunc4->SetLineColor(kGreen);
    fitFunc6->SetLineColor(kBlue);

    hist2->Fit(fitFunc2);  
    hist4->Fit(fitFunc4);  
    hist6->Fit(fitFunc6);  



    hist2->Draw("SAME");
    hist4->Draw("SAME");
    hist6->Draw("SAME");
  
    hist6->GetYaxis()->SetTitle("Number of events");
    hist6->GetXaxis()->SetTitle("Number of photons");


   c1->SaveAs("pic.jpg");
   
}
