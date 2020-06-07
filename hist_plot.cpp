// This is a simple code to plot three distributions from .root files.

void hist_plot() {
    TFile *file2 = new TFile("file_name_1.root");
    TFile *file4 = new TFile("file_name_2.root");
    TFile *file6 = new TFile("file_name_3.root");
    TH1F *hist2; 
    TH1F *hist4;
    TH1F *hist6;
    TF1 *fitFunc;

    gStyle->SetOptStat(0);  

   /* printf("File open... ");
    if (!file) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");
   */ 

    printf("Loading histogram... ");
    hist2 = file2->GetObject("fCounterSipm", hist2); 
    hist4 = file4->GetObject("fCounterSipm", hist4); 
    hist6 = file6->GetObject("fCounterSipm", hist6); 

  /*  if (!hist1) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");

    if (!hist2) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");
   */


    fitFunc = new TF1("fitFunc", "landau");
    hist2->Fit(fitFunc);  
    hist4->Fit(fitFunc);  
    hist6->Fit(fitFunc);  
   

    hist4->SetLineColor(kRed);
    hist6->SetLineColor(kBlue);
    hist2->Draw("SAME");
    hist4->Draw("SAME");
    hist6->Draw("SAME");
    
}
