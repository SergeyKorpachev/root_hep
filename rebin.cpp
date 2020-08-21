void rebin() {
    TFile *file;
    int x = 0;
    float a = 0;
    float b = 0;
    float c = 0;
    int d = 0;
    FILE *out = fopen("out.txt", "r");
    if (!(long)out) return;
    while(1) {
    fscanf(out, "%i %f %f %f %i",&x,&a,&b,&c,&d);
    if (d == 1)
      {
         switch (x) {
          case 22:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz22mm_e200.root");
          goto X;
          }
          case 24:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz24mm_e200.root");
          goto X;
          }
          case 26:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz26mm_e200.root");
          goto X;
          }
          case 28:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz28mm_e200.root");
          goto X;
          }
          case 210:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz210mm_e200.root");
          goto X;
          }
          case 212:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz212mm_e200.root");
          goto X;
          }
          case 214:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz214mm_e200.root");
          goto X;
          }
          case 42:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz42mm_e200.root");
          goto X;
          }
          case 44:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz44mm_e200.root");
          goto X;
          }
          case 46:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz46mm_e200.root");
          goto X;
          }
          case 48:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz48mm_e200.root");
          goto X;
          }
          case 410:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz410mm_e200.root");
          goto X;
          }
          case 412:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz412mm_e200.root");
          goto X;
          }
          case 414:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz414mm_e200.root");
          goto X;
          }
          case 62:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz62mm_e200.root");
          goto X;
          }
          case 64:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz64mm_e200.root");
          goto X;
          }
          case 66:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz66mm_e200.root");
          goto X;
          }
          case 68:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz68mm_e200.root");
          goto X;
          }
          case 610:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz610mm_e200.root");
          goto X;
          }
          case 612:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz612mm_e200.root");
          goto X;
          }
          case 614:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz614mm_e200.root");
          goto X;
          }
          case 82:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz82mm_e200.root");
          goto X;
          }
          case 84:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz84mm_e200.root");
          goto X;
          }
          case 86:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz86mm_e200.root");
          goto X;
          }
          case 88:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz88mm_e200.root");
          goto X;
          }
          case 810:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz810mm_e200.root");
          goto X;
          }
          case 812:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz812mm_e200.root");
          goto X;
          }
          case 814:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz814mm_e200.root");
          goto X;
          }
          case 102:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz102mm_e200.root");
          goto X;
          }
          case 104:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz104mm_e200.root");
          goto X;
          }
          case 106:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz106mm_e200.root");
          goto X;
          }
          case 108:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz108mm_e200.root");
          goto X;
          }
          case 1010:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz1010mm_e200.root");
          goto X;
          }
          case 1012:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz1012mm_e200.root");
          goto X;
          }
          case 1014:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz1014mm_e200.root");
          goto X;
          }
          case 122:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz122mm_e200.root");
          goto X;
          }
          case 124:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz124mm_e200.root");
          goto X;
          }
          case 126:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz126mm_e200.root");
          goto X;
          }
          case 128:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz128mm_e200.root");
          goto X;
          }
          case 1210:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz1210mm_e200.root");
          goto X;
          }
          case 1212:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz1212mm_e200.root");
          goto X;
          }
          case 1214:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz1214mm_e200.root");
          goto X;
          }
          case 142:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz142mm_e200.root");
          goto X;
          }
          case 144:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz144mm_e200.root");
          goto X;
          }
          case 146:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz146mm_e200.root");
          goto X;
          }
          case 148:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz148mm_e200.root");
          goto X;
          }
          case 1410:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz1410mm_e200.root");
          goto X;
          }
          case 1412:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz1412mm_e200.root");
          goto X;
          }
          case 1414:
          {
          file = new TFile("dimple_scint3_box15_gap01_xz1414mm_e200.root");
          goto X;
          }
          default:
          {
          std::cout << "Error in \"a\" " << std::endl;
          goto X;
          }

    }
    }
  }
    X : 
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

    hist->Rebin();

    fitFunc1 = new TF1("fitFunc1", "gaus");

    hist->GetYaxis()->SetTitle("Number of events");
    hist->GetXaxis()->SetTitle("Number of photons");
    hist->Fit(fitFunc1, "0");
    float mean1 = fitFunc1->GetParameter(1);
    float sigma1 = fitFunc1->GetParameter(2);
    std::cout << "Mean1 : " << mean1 << std::endl;
    std::cout << "Sigma1 : " << sigma1 << std::endl;


   fitFunc2 = new TF1("fitFunc2", "gaus", mean1 - 1.5*sigma1, mean1 + 1.5*sigma1);
   hist->Fit(fitFunc2, "R");
   float mean2 = fitFunc2->GetParameter(1);
   float sigma2 = fitFunc2->GetParameter(2);
   std::cout << "Mean2 : " << mean2 << std::endl;
   std::cout << "Sigma2 : " << sigma2 << std::endl;

   int flag = 0;
   double chi2 = 0;
   chi2 = fitFunc2->GetChisquare() / fitFunc2->GetNDF();
   if (chi2 > 5) flag = 1;


     switch (x) {
          case 22:
          {
          c1->SaveAs("22-rebin.jpg");
          goto XX;
          }
          case 24:
          {
          c1->SaveAs("24-rebin.jpg");
          goto XX;
          }
          case 26:
          {
          c1->SaveAs("26-rebin.jpg");
          goto XX;
          }
          case 28:
          {
          c1->SaveAs("28-rebin.jpg");
          goto XX;
          }
          case 210:
          {
          c1->SaveAs("210-rebin.jpg");
          goto XX;
          }
          case 212:
          {
          c1->SaveAs("212-rebin.jpg");
          goto XX;
          }
          case 214:
          {
          c1->SaveAs("214-rebin.jpg");
          goto XX;
          }
          case 42:
          {
          c1->SaveAs("42-rebin.jpg");
          goto XX;
          }
          case 44:
          {
          c1->SaveAs("44-rebin.jpg");
          goto XX;
          }
          case 46:
          {
          c1->SaveAs("46-rebin.jpg");
          goto XX;
          }
          case 48:
          {
          c1->SaveAs("48-rebin.jpg");
          goto XX;
          }
          case 410:
          {
          c1->SaveAs("410-rebin.jpg");
          goto XX;
          }
          case 412:
          {
          c1->SaveAs("412-rebin.jpg");
          goto XX;
          }
          case 414:
          {
          c1->SaveAs("414-rebin.jpg");
          goto XX;
          }
          case 62:
          {
          c1->SaveAs("62-rebin.jpg");
          goto XX;
          }
          case 64:
          {
          c1->SaveAs("64-rebin.jpg");
          goto XX;
          }
          case 66:
          {
          c1->SaveAs("66-rebin.jpg");
          goto XX;
          }
          case 68:
          {
          c1->SaveAs("68-rebin.jpg");
          goto XX;
          }
          case 610:
          {
          c1->SaveAs("610-rebin.jpg");
          goto XX;
          }
          case 612:
          {
          c1->SaveAs("612-rebin.jpg");
          goto XX;
          }
          case 614:
          {
          c1->SaveAs("614-rebin.jpg");
          goto XX;
          }
          case 82:
          {
          c1->SaveAs("82-rebin.jpg");
          goto XX;
          }
          case 84:
          {
          c1->SaveAs("84-rebin.jpg");
          goto XX;
          }
          case 86:
          {
          c1->SaveAs("86-rebin.jpg");
          goto XX;
          }
          case 88:
          {
          c1->SaveAs("88-rebin.jpg");
          goto XX;
          }
          case 810:
          {
          c1->SaveAs("810-rebin.jpg");
          goto XX;
          }
          case 812:
          {
          c1->SaveAs("812-rebin.jpg");
          goto XX;
          }
          case 814:
          {
          c1->SaveAs("814-rebin.jpg");
          goto XX;
          }
          case 102:
          {
          c1->SaveAs("102-rebin.jpg");
          goto XX;
          }
          case 104:
          {
          c1->SaveAs("104-rebin.jpg");
          goto XX;
          }
          case 106:
          {
          c1->SaveAs("106-rebin.jpg");
          goto XX;
          }
          case 108:
          {
          c1->SaveAs("108-rebin.jpg");
          goto XX;
          }
          case 1010:
          {
          c1->SaveAs("1010-rebin.jpg");
          goto XX;
          }
          case 1012:
          {
          c1->SaveAs("1012-rebin.jpg");
          goto XX;
          }
          case 1014:
          {
          c1->SaveAs("1014-rebin.jpg");
          goto XX;
          }
          case 122:
          {
          c1->SaveAs("122-rebin.jpg");
          goto XX;
          }
          case 124:
          {
          c1->SaveAs("124-rebin.jpg");
          goto XX;
          }
          case 126:
          {
          c1->SaveAs("126-rebin.jpg");
          goto XX;
          }
          case 128:
          {
          c1->SaveAs("128-rebin.jpg");
          goto XX;
          }
          case 1210:
          {
          c1->SaveAs("1210-rebin.jpg");
          goto XX;
          }
          case 1212:
          {
          c1->SaveAs("1212-rebin.jpg");
          goto XX;
          }
          case 1214:
          {
          c1->SaveAs("1214-rebin.jpg");
          goto XX;
          }
          case 142:
          {
          c1->SaveAs("142-rebin.jpg");
          goto XX;
          }
          case 144:
          {
          c1->SaveAs("144-rebin.jpg");
          goto XX;
          }
          case 146:
          {
          c1->SaveAs("146-rebin.jpg");
          goto XX;
          }
          case 148:
          {
          c1->SaveAs("148-rebin.jpg");
          goto XX;
          }
          case 1410:
          {
          c1->SaveAs("1410-rebin.jpg");
          goto XX;
          }
          case 1412:
          {
          c1->SaveAs("1412-rebin.jpg");
          goto XX;
          }
          case 1414:
          {
          c1->SaveAs("1414-rebin.jpg");
          goto XX;
          }
          default:
          {
          std::cout << "Error in picture" << std::endl;
          goto XX;
          }
          }

       XX : 
//   hist->Draw();

   FILE *nout = fopen("nout.txt", "a+");
       printf("File open... ");
       if (!nout) {
          printf("[FAIL]\n");
          return 0;
       } else printf("[OK]\n");
   fprintf(nout,"%i %E %E %E %i\n",x, mean2, sigma2, chi2, flag);
  //  fclose(out);
}

