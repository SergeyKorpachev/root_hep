/*Double_t func(Double_t *x, Double_t *par) {
    
    Double_t a = sqrt((par[0]*par[0])/(*x) + par[1]*par[1] + (par[2]*par[2])/((*x)*(*x)));
    
    return a;
    
}
*/
void fit_rel2() {
   TCanvas *c1 = new TCanvas("graph1","graph1",200,10,700,500);
    
   c1->SetGrid();

   const Int_t n = 9; // 16
    
   Float_t energy[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t energyerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
     
   Float_t mean[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t meanerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rmserror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
     
   Float_t mean_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t meanerror_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rmserror_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
     
   Float_t mean_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t meanerror_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rmserror_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
      
   Float_t mean90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
     
   Float_t mean_mean[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms_mean[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean_meanerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms_meanerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean_sigma[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms_sigma[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean_sigmaerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms_sigmaerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean_chi[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms_chi[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t resolution_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t resolution_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t resolution_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t resolution90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t resolution95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t resolution[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   FILE *file1 = fopen("new_2out_data.txt", "r");
   if ( !(long)file1 ) return;

  for ( int i = 0; i < n; i++ ) {
    fscanf( file1, "%f %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E\n", &energy[i], &mean_hist90[i], &meanerror_hist90[i], &rms_hist90[i], &rmserror_hist90[i], &mean_hist95[i], &meanerror_hist95[i], &rms_hist95[i], &rmserror_hist95[i], &mean90[i], &rms90[i], &mean95[i], &rms95[i], &mean[i], &meanerror[i], &rms[i], &rmserror[i], &mean_mean[i], &mean_meanerror[i], &mean_sigma[i], &mean_sigmaerror[i], &mean_chi[i] );
    if ( feof( file1 ) ) break;
  }
 
  for ( int i = 0; i < n; i++ ) {
    
    resolution_hist[ i ] = rms[i] / mean[i];
    resolution_error_stat_hist[ i ] = sqrt( pow( (rmserror[i]) / (mean[i]), 2 ) + pow( (rms[i] * meanerror[i]) / (mean[i] * mean[i]), 2 ) );
    resolution_error_sys_hist[ i ] = 0.0;
    resolution_error_hist[ i ] = sqrt( ( pow( resolution_error_stat_hist[ i ], 2 ) ) + ( pow( resolution_error_sys_hist[ i ], 2 ) ) );
          
    resolution_hist90[ i ] = rms_hist90[i] / mean_hist90[i];
    resolution_error_stat_hist90[ i ] = sqrt( pow( (rmserror_hist90[i]) / (mean_hist90[i]), 2 ) + pow( (rms_hist90[i] * meanerror_hist90[i]) / (mean_hist90[i] * mean_hist90[i]), 2 ) );
    resolution_error_sys_hist90[ i ] = 0.0;
    resolution_error_hist90[ i ] = sqrt( ( pow( resolution_error_stat_hist90[ i ], 2 ) ) + ( pow( resolution_error_sys_hist90[ i ], 2 ) ) );
            
    resolution_hist95[ i ] = rms_hist95[i] / mean_hist95[i];
    resolution_error_stat_hist95[ i ] = sqrt( pow( (rmserror_hist95[i]) / (mean_hist95[i]), 2 ) + pow( (rms_hist95[i] * meanerror_hist95[i]) / (mean_hist95[i] * mean_hist95[i]), 2 ) );
    resolution_error_sys_hist95[ i ] = 0.0;
    resolution_error_hist95[ i ] = sqrt( ( pow( resolution_error_stat_hist95[ i ], 2 ) ) + ( pow( resolution_error_sys_hist95[ i ], 2 ) ) );
          
    resolution90[ i ] = rms90[i] / mean90[i];
    resolution_error_stat90[ i ] = 0.0;
    resolution_error_sys90[ i ] = 0.0;
    resolution_error90[ i ] = sqrt( ( pow( resolution_error_stat90[ i ], 2 ) ) + ( pow( resolution_error_sys90[ i ], 2 ) ) );
          
    resolution95[ i ] = rms95[i] / mean95[i];
    resolution_error_stat95[ i ] = 0.0;
    resolution_error_sys95[ i ] = 0.0;
    resolution_error95[ i ] = sqrt( ( pow( resolution_error_stat95[ i ], 2 ) ) + ( pow( resolution_error_sys95[ i ], 2 ) ) );

    resolution[ i ] = mean_sigma[i] / mean_mean[i];
    resolution_error_stat[ i ] = sqrt( pow( (mean_sigmaerror[i]) / (mean_mean[i]), 2 ) + pow( (mean_sigma[i] * mean_meanerror[i]) / (mean_mean[i] * mean_mean[i]), 2 ) );
    resolution_error_sys[ i ] = 0.0;
    resolution_error[ i ] = sqrt( ( pow( resolution_error_stat[ i ], 2 ) ) + ( pow( resolution_error_sys[ i ], 2 ) ) );

  }
    printf( "\n" );
    for (int i = 0; i < n; i++) {
      printf( " %f ", energy[i] );
      printf( " %f ", energyerror[i] );
      
      printf( " %f ", mean[i] );
      printf( " %f ", meanerror[i] );
      printf( " %f ", rms[i] );
      printf( " %f ", rmserror[i] );
        
      printf( " %f ", mean_hist90[i] );
      printf( " %f ", meanerror_hist90[i] );
      printf( " %f ", rms_hist90[i] );
      printf( " %f ", rmserror_hist90[i] );
        
      printf( " %f ", mean_hist95[i] );
      printf( " %f ", meanerror_hist95[i] );
      printf( " %f ", rms_hist95[i] );
      printf( " %f ", rmserror_hist95[i] );

      printf( " %f ", mean90[i] );
      printf( " %f ", rms90[i] );
      printf( " %f ", mean95[i] );
      printf( " %f ", rms95[i] );
        
      printf( " %f ", resolution_hist[i] );
      printf( " %f ", resolution_error_hist[i] );
     
      printf( " %f ", resolution_hist90[i] );
      printf( " %f ", resolution_error_hist90[i] );
        
      printf( " %f ", resolution_hist95[i] );
      printf( " %f ", resolution_error_hist95[i] );
      
      printf( " %f ", resolution90[i] );
      printf( " %f ", resolution_error90[i] );
      printf( " %f ", resolution95[i] );
      printf( " %f ", resolution_error95[i] );
      
      printf( " %f ", mean_mean[i] );
      printf( " %f ", rms_mean[i] );
      printf( " %f ", mean_meanerror[i] );
      printf( " %f ", rms_meanerror[i] );
      printf( " %f ", mean_sigma[i] );
      printf( " %f ", rms_sigma[i] );
      printf( " %f ", mean_sigmaerror[i] );
      printf( " %f ", rms_sigmaerror[i] );
      printf( " %f ", resolution[i] );
      printf( " %f ", resolution_error[i] );
      
      printf( "\n" );
      printf( "\n" );
      printf( "\n" );

    }

   TGraphErrors *xgr;
   TGraphErrors *ygr;
   TGraphErrors *agr;
   TGraphErrors *bgr;
   TGraphErrors *cgr;
   TGraphErrors *dgr;

   char fname[ 100 ];
   for ( int i = 0; i < 100; i++ ) fname[ i ] = 0;

   //c1->cd();
   xgr = new TGraphErrors( n, energy, resolution, energyerror, resolution_error );
   xgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   xgr->GetXaxis()->SetTitle("E_{true}, GeV");
   ygr = new TGraphErrors( n, energy, resolution_hist90, energyerror, resolution_error_hist90 );
   ygr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   ygr->GetXaxis()->SetTitle("E_{true}, GeV");
   agr = new TGraphErrors( n, energy, resolution, energyerror, resolution_error );
   agr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, resolution_hist90, energyerror, resolution_error_hist90 );
   bgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, resolution_hist95, energyerror, resolution_error_hist95 );
   cgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, resolution_hist, energyerror, resolution_error_hist );
   dgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Relative energy resolution" );
   agr->GetYaxis()->SetRangeUser(0.0, 0.30);
   agr->SetTitle(fname);
    
   //TFormula *my_formula2 = new TFormula("my_formula2","[0]*[0]/x + [1]*[1] + ([2]*[2])/(x*x)");
   //TFormula *my_formula = new TFormula("my_formula","TMath::Power([0], 2)/x + TMath::Power([1], 2) + TMath::Power([2], 2)/(TMath::Power(x, 2))");

   //TF1 *f0 = new TF1("f0", "sqrt([0]*[0]/x + [1]*[1])" );
   //TF1 *f1 = new TF1("f1", "sqrt([0]*[0]/x + [1]*[1])" );
   //TF1 *f2 = new TF1("f2", "sqrt([0]*[0]/x + [1]*[1])" );
   //TF1 *f3 = new TF1("f3", "sqrt([0]*[0]/x + [1]*[1])" );
   //TF1 *f4 = new TF1("f4", "sqrt([0]*[0]/x + [1]*[1])" );
 
   //TF1 *f0 = new TF1("f0", "sqrt([0]*[0]/x + [1]*[1] + ([2]*[2])/(x*x))" );
   TF1 *f1 = new TF1("f1", "sqrt([0]*[0]/x + [1]*[1] + ([2]*[2])/(x*x))" );
   //TF1 *f2 = new TF1("f2", "sqrt([0]*[0]/x + [1]*[1] + ([2]*[2])/(x*x))" );
   //TF1 *f3 = new TF1("f3", "sqrt([0]*[0]/x + [1]*[1] + ([2]*[2])/(x*x))" );
   //TF1 *f4 = new TF1("f4", "sqrt([0]*[0]/x + [1]*[1] + ([2]*[2])/(x*x))" );
    
   //TF1 *f1 = new TF1("f1", "my_formula" );

   cout << "Fit_test:" << endl;
   //f1 -> SetParameter(2, 0.0);
   //f1 -> SetParameter(1, 0.0);
   //f1 -> SetParameter(2, 0.0);
   xgr -> Fit( f1 );
   cout << "Hist90_2_test:" << endl;
   //f2 -> SetParameter(2, 0.3);
   ygr -> Fit( f1 );
    
   cout << "Fit:" << endl;
   //f1 -> SetParameter(0, 0.0);
   //f1 -> SetParameter(1, 0.0);
   //f1 -> SetParameter(2, 0.0);
   agr -> Fit( f1 );
   cout << "Hist90_2:" << endl;
   //f2 -> SetParameter(2, 0.3);
   bgr -> Fit( f1 );
   cout << "Hist95_2:" << endl;
   //f3 -> SetParameter(2, 0.3);
   cgr -> Fit( f1 );
   cout << "Hist:" << endl;
   //f4 -> SetParameter(2, 0.3);
   dgr -> Fit( f1 );
   //f1->SetLineColor(kBlue);
   //f1->SetLineColor(kRed);
   //f1->SetLineColor(kGreen);
   //f1->SetLineColor(kMagenta);

   //c1 -> cd();
   agr->SetFillColor(kBlue);
   //agr->SetFillStyle(3001);
   agr->SetMarkerColor(kBlue);
   agr->SetLineColor(kBlue);
   agr->SetLineWidth(3);
   agr->SetMarkerStyle(20);
   agr->Draw("A P");
   bgr->SetMarkerColor(kRed);
   bgr->SetLineColor(kRed);
   bgr->SetLineWidth(3);
   bgr->SetFillColor(kRed);
   bgr->SetMarkerStyle(20);
   bgr->Draw("P SAME");
   cgr->SetMarkerColor(kGreen);
   //cgr->SetFillStyle(3001);
   cgr->SetLineColor(kGreen);
   cgr->SetLineWidth(3);
   cgr->SetFillColor(kGreen);
   cgr->SetMarkerStyle(20);
   cgr->Draw("P SAME");
   dgr->SetMarkerColor(kMagenta);
   dgr->SetLineColor(kMagenta);
   dgr->SetLineWidth(3);
   dgr->SetFillColor(kMagenta);
   dgr->SetMarkerStyle(20);
   dgr->Draw("P SAME");
   c1->Update();
    
   TLegend *lsc1 = new TLegend(0.55,0.62,0.90,0.92);
   lsc1->AddEntry(agr,"fit (stat)","pl");
   lsc1->AddEntry(bgr,"hist90_2 (stat)","pl");
   lsc1->AddEntry(cgr,"hist95_2 (stat)","pl");
   lsc1->AddEntry(dgr,"hist (stat)","pl");

   //c1->cd();
   lsc1->Draw();

}
