void diff_rms_graph() {
    
   float FFF = 90.0;
      
   char fname_out[ 200 ];
   for ( int i = 0; i < 200; i++ ) fname_out[ i ] = 0;
    
   char fname_legend[ 200 ];
   for ( int i = 0; i < 200; i++ ) fname_legend[ i ] = 0;
    
   char fname_legend2[ 200 ];
   for ( int i = 0; i < 200; i++ ) fname_legend2[ i ] = 0;
    
   TCanvas *c1 = new TCanvas("graph1","graph1",200,10,700,500);
   TCanvas *c2 = new TCanvas("graph2","graph2",200,10,700,500);
   TCanvas *c3 = new TCanvas("graph3","graph3",200,10,700,500);
   TCanvas *c4 = new TCanvas("graph4","graph4",200,10,700,500);

   c1->SetGrid();
   c2->SetGrid();
   c3->SetGrid();
   c4->SetGrid();

   const Int_t n = 9; // 16

   Float_t energy[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t energyerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t mean[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t meanerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rmserror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t mean2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t meanerror2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rmserror2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t ratio[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t ratio2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   sprintf( fname_out, "out_diff_rms_%0.f.txt", FFF );

   FILE *file1 = fopen(fname_out, "r");
   if ( !(long)file1 ) return;

  for ( int i = 0; i < n; i++ ) {
    fscanf( file1, "%f %E %E %E %E %E %E %E %E\n", &energy[i], &mean[i], &meanerror[i], &rms[i], &rmserror[i], &mean2[i], &meanerror2[i], &rms2[i], &rmserror2[i] );
    if ( feof( file1 ) ) break;
  }
 
  for ( int i = 0; i < n; i++ ) {

    ratio[ i ] = ( mean[i] - energy[i] ) / energy[i];
    ratio_error_stat[ i ] = sqrt( pow( (meanerror[i]) / (energy[i]), 2 ) + pow( (mean[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys[ i ] = 0.0;
    ratio_error[ i ] = sqrt( ( pow( ratio_error_stat[ i ], 2 ) ) + ( pow( ratio_error_sys[ i ], 2 ) ) );
      
    ratio2[ i ] = ( mean2[i] - energy[i] ) / energy[i];
    ratio_error_stat2[ i ] = sqrt( pow( (meanerror2[i]) / (energy[i]), 2 ) + pow( (mean2[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys2[ i ] = 0.0;
    ratio_error2[ i ] = sqrt( ( pow( ratio_error_stat2[ i ], 2 ) ) + ( pow( ratio_error_sys2[ i ], 2 ) ) );
      
    resolution[ i ] = rms[i] / mean[i];
    resolution_error_stat[ i ] = sqrt( pow( (rmserror[i]) / (mean[i]), 2 ) + pow( (rms[i] * meanerror[i]) / (mean[i] * mean[i]), 2 ) );
    resolution_error_sys[ i ] = 0.0;
    resolution_error[ i ] = sqrt( ( pow( resolution_error_stat[ i ], 2 ) ) + ( pow( resolution_error_sys[ i ], 2 ) ) );
      
    resolution2[ i ] = rms2[i] / mean2[i];
    resolution_error_stat2[ i ] = sqrt( pow( (rmserror2[i]) / (mean2[i]), 2 ) + pow( (rms2[i] * meanerror2[i]) / (mean2[i] * mean2[i]), 2 ) );
    resolution_error_sys2[ i ] = 0.0;
    resolution_error2[ i ] = sqrt( ( pow( resolution_error_stat2[ i ], 2 ) ) + ( pow( resolution_error_sys2[ i ], 2 ) ) );
    
  }
    
    printf( "\n" );
    for (int i = 0; i < n; i++) {
        
      printf( " mean === %f \n", mean[i] );
      printf( " rms === %f \n", rms[i] );
      printf( " mean === %f \n", mean[i] );
      printf( " rms === %f \n", rms[i] );

      printf( " mean2 === %f \n", mean2[i] );
      printf( " rms2 === %f \n", rms2[i] );
      printf( " mean2 === %f \n", mean2[i] );
      printf( " rms2 === %f \n", rms2[i] );
        
      printf( "\n" );
     
      printf( " ratio === %f \n", ratio[i] );
      printf( " ratio_error === %f \n", ratio_error[i] );
      printf( " resolution === %f \n", resolution[i] );
      printf( " resolution_error === %f \n", resolution_error[i] );
      printf( " ratio2 === %f \n", ratio2[i] );
      printf( " ratio_error2 === %f \n", ratio_error2[i] );
      printf( " resolution2 === %f \n", resolution2[i] );
      printf( " resolution_error2 === %f \n", resolution_error2[i] );
      
      printf( " ratio === %f \n", ratio[i] );
      printf( " ratio_error === %f \n", ratio_error[i] );
      printf( " resolution === %f \n", resolution[i] );
      printf( " resolution_error === %f \n", resolution_error[i] );
      printf( " ratio2 === %f \n", ratio2[i] );
      printf( " ratio_error2 === %f \n", ratio_error2[i] );
      printf( " resolution2 === %f \n", resolution2[i] );
      printf( " resolution_error2 === %f \n", resolution_error2[i] );

      printf( "\n" );
      printf( "\n" );
      printf( "\n" );
    }

   TGraphErrors *agr;
   TGraphErrors *bgr;
    
   TGraphErrors *cgr;
   TGraphErrors *dgr;

   char fname[ 100 ];
   for ( int i = 0; i < 100; i++ ) fname[ i ] = 0;

   c1->cd();
   agr = new TGraphErrors( n, energy, ratio, energyerror, ratio_error_sys );
   agr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, ratio, energyerror, ratio_error_stat );
   bgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, ratio2, energyerror, ratio_error_sys2 );
   cgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, ratio2, energyerror, ratio_error_stat2 );
   dgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Linearity" );
   agr->GetYaxis()->SetRangeUser(-0.2, 0.2);
   agr->SetTitle(fname);

   agr->SetFillColor(kCyan);
   agr->SetFillStyle(3001);
   agr->SetMarkerColor(kCyan);
   agr->SetLineColor(kCyan);
   agr->SetLineWidth(3);
   agr->SetMarkerStyle(34);
   agr->Draw("A 3");
   bgr->SetMarkerColor(kBlue);
   bgr->SetLineColor(kBlue);
   bgr->SetLineWidth(3);
   bgr->SetFillColor(kCyan);
   bgr->SetMarkerStyle(20);
   bgr->Draw("P SAME");
   cgr->SetMarkerColor(kYellow-6);
   cgr->SetFillStyle(3001);
   cgr->SetLineColor(kYellow-6);
   cgr->SetLineWidth(3);
   cgr->SetFillColor(kYellow-6);
   cgr->SetMarkerStyle(20);
   cgr->Draw("3 SAME");
   dgr->SetMarkerColor(kRed);
   dgr->SetLineColor(kRed);
   dgr->SetLineWidth(3);
   dgr->SetFillColor(kYellow-6);
   dgr->SetMarkerStyle(20);
   dgr->Draw("P SAME");
   c1->Update();

   c2->cd();
   agr = new TGraphErrors( n, energy, rms, energyerror, energyerror );
   agr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, rms, energyerror, rmserror );
   bgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, rms2, energyerror, energyerror );
   cgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, rms2, energyerror, rmserror2 );
   dgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Absolute energy resolution" );
   agr->GetYaxis()->SetRangeUser(0.0, 9.0);
   agr->SetTitle(fname);

   agr->SetFillColor(kCyan);
   agr->SetFillStyle(3001);
   agr->SetMarkerColor(kCyan);
   agr->SetLineColor(kCyan);
   agr->SetLineWidth(3);
   agr->SetMarkerStyle(34);
   agr->Draw("A 3");
   bgr->SetMarkerColor(kBlue);
   bgr->SetLineColor(kBlue);
   bgr->SetLineWidth(3);
   bgr->SetFillColor(kCyan);
   bgr->SetMarkerStyle(20);
   bgr->Draw("P SAME");
   cgr->SetMarkerColor(kYellow-6);
   cgr->SetFillStyle(3001);
   cgr->SetLineColor(kYellow-6);
   cgr->SetLineWidth(3);
   cgr->SetFillColor(kYellow-6);
   cgr->SetMarkerStyle(20);
   cgr->Draw("3 SAME");
   dgr->SetMarkerColor(kRed);
   dgr->SetLineColor(kRed);
   dgr->SetLineWidth(3);
   dgr->SetFillColor(kYellow-6);
   dgr->SetMarkerStyle(20);
   dgr->Draw("P SAME");
   c2->Update();

   c3->cd();
   agr = new TGraphErrors( n, energy, mean, energyerror, energyerror );
   agr->GetYaxis()->SetTitle("E_{reco}, GeV");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, mean, energyerror, meanerror );
   bgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, mean2, energyerror, energyerror );
   cgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, mean2, energyerror, meanerror2 );
   dgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Linearity 2" );
   agr->GetYaxis()->SetRangeUser(0.0, 70.0);
   agr->SetTitle(fname);

   agr->SetFillColor(kCyan);
   agr->SetFillStyle(3001);
   agr->SetMarkerColor(kCyan);
   agr->SetLineColor(kCyan);
   agr->SetLineWidth(3);
   agr->SetMarkerStyle(34);
   agr->Draw("A 3");
   bgr->SetMarkerColor(kBlue);
   bgr->SetLineColor(kBlue);
   bgr->SetLineWidth(3);
   bgr->SetFillColor(kCyan);
   bgr->SetMarkerStyle(20);
   bgr->Draw("P SAME");
   cgr->SetMarkerColor(kYellow-6);
   cgr->SetFillStyle(3001);
   cgr->SetLineColor(kYellow-6);
   cgr->SetLineWidth(3);
   cgr->SetFillColor(kYellow-6);
   cgr->SetMarkerStyle(20);
   cgr->Draw("3 SAME");
   dgr->SetMarkerColor(kRed);
   dgr->SetLineColor(kRed);
   dgr->SetLineWidth(3);
   dgr->SetFillColor(kYellow-6);
   dgr->SetMarkerStyle(20);
   dgr->Draw("P SAME");
   c3->Update();

   c4->cd();
   agr = new TGraphErrors( n, energy, resolution, energyerror, resolution_error_sys );
   agr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, resolution, energyerror, resolution_error_stat );
   bgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, resolution2, energyerror, resolution_error_sys2 );
   cgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, resolution2, energyerror, resolution_error_stat2 );
   dgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Relative energy resolution" );
   agr->GetYaxis()->SetRangeUser(0.0, 0.30);
   agr->SetTitle(fname);

   agr->SetFillColor(kCyan);
   agr->SetFillStyle(3001);
   agr->SetMarkerColor(kCyan);
   agr->SetLineColor(kCyan);
   agr->SetLineWidth(3);
   agr->SetMarkerStyle(34);
   agr->Draw("A 3");
   bgr->SetMarkerColor(kBlue);
   bgr->SetLineColor(kBlue);
   bgr->SetLineWidth(3);
   bgr->SetFillColor(kCyan);
   bgr->SetMarkerStyle(20);
   bgr->Draw("P SAME");
   cgr->SetMarkerColor(kYellow-6);
   cgr->SetFillStyle(3001);
   cgr->SetLineColor(kYellow-6);
   cgr->SetLineWidth(3);
   cgr->SetFillColor(kYellow-6);
   cgr->SetMarkerStyle(20);
   cgr->Draw("3 SAME");
   dgr->SetMarkerColor(kRed);
   dgr->SetLineColor(kRed);
   dgr->SetLineWidth(3);
   dgr->SetFillColor(kYellow-6);
   dgr->SetMarkerStyle(20);
   dgr->Draw("P SAME");
   c4->Update();
    
   sprintf( fname_legend, "hist%0.f_old (stat)", FFF );
   sprintf( fname_legend2, "hist%0.f_new (stat)", FFF );
   
   TLegend *lsc1 = new TLegend(0.55,0.62,0.90,0.92);
   lsc1->AddEntry( bgr, fname_legend, "pl" );
   lsc1->AddEntry( dgr, fname_legend2, "pl" );
   
   TLegend *lsc2 = new TLegend(0.55,0.62,0.90,0.92);
   lsc2->AddEntry( bgr, fname_legend, "pl" );
   lsc2->AddEntry( dgr, fname_legend2, "pl" );
   
   TLegend *lsc3 = new TLegend(0.55,0.62,0.90,0.92);
   lsc3->AddEntry( bgr, fname_legend, "pl" );
   lsc3->AddEntry( dgr, fname_legend2, "pl" );
   
   TLegend *lsc4 = new TLegend(0.55,0.62,0.90,0.92);
   lsc4->AddEntry( bgr, fname_legend, "pl" );
   lsc4->AddEntry( dgr, fname_legend2, "pl" );

   c1->cd();
   lsc1->Draw();
   c2->cd();
   lsc2->Draw();
   c3->cd();
   lsc3->Draw();
   c4->cd();
   lsc4->Draw();

}
