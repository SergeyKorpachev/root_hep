void DRTileMPV() {
    TFile *file = new TFile("flat_scint3_box15_gap01_xz2mm_e200.root");
    TH1D *hist;
    TF1 *fitFunc;


    printf("File open... ");
    if (!file) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");

    printf("Loading histogram... ");
    hist = file->GetObject("fCounterSipm", hist);
    if (!hist) {
        printf("[FAIL]\n");
        return 0;
    } else printf("[OK]\n");

    fitFunc = new TF1("fitFunc", "landau");
    hist->Fit(fitFunc, "M0");
  //  hist->Draw();
    printf("\n\tMPV = %E\n\n", fitFunc->GetParameter(1));

    printf("\n\tChisquare = %E\n\n", fitFunc->GetChisquare());
}
