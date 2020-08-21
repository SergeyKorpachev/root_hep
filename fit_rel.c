void fit_rel() {
   TCanvas *c1 = new TCanvas("graph1","graph1",200,10,700,500);
    
   c1->SetGrid();

   const Int_t n = 9; // 16

   Float_t energy[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t energyerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t mean[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
     
   Float_t mean90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t mean_mean[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean_sigma[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t resolution_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t temp = 0;
    
   FILE *file1 = fopen("new_2out_data.txt", "r");
   if ( !(long)file1 ) return;

  for ( int i = 0; i < n; i++ ) {
    fscanf( file1, "%f %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E %E\n", &energy[i], &temp, &temp, &temp, &temp, &temp, &temp, &temp, &temp, &temp, &temp, &temp, &temp, &mean90[i], &rms90[i], &mean95[i], &rms95[i], &temp, &temp, &mean[i], &temp, &rms[i], &temp, &mean_mean[i], &temp, &mean_sigma[i], &temp, &temp );
    if ( feof( file1 ) ) break;
  }
 
  for ( int i = 0; i < n; i++ ) {
    
    resolution_hist[ i ] = rms[i] / mean[i];
    
    resolution90[ i ] = rms90[i] / mean90[i];
    
    resolution95[ i ] = rms95[i] / mean95[i];
    
    resolution[ i ] = mean_sigma[i] / mean_mean[i];

  }
    
   printf( "\n" );
   for (int i = 0; i < n; i++) {
     printf( " %f ", energy[i] );
     printf( " %f ", energyerror[i] );
     
     printf( " %f ", mean[i] );
     printf( " %f ", rms[i] );

     printf( " %f ", mean90[i] );
     printf( " %f ", rms90[i] );
     printf( " %f ", mean95[i] );
     printf( " %f ", rms95[i] );
       
     printf( " %f ", resolution_hist[i] );
     
     printf( " %f ", resolution90[i] );
     printf( " %f ", resolution95[i] );
     
     printf( " %f ", mean_mean[i] );
     printf( " %f ", mean_sigma[i] );
     printf( " %f ", resolution[i] );
     
     printf( "\n" );
     printf( "\n" );
     printf( "\n" );

   }

   TGraph *agr;
   TGraph *bgr;
   TGraph *cgr;
   TGraph *dgr;

   char fname[ 100 ];
   for ( int i = 0; i < 100; i++ ) fname[ i ] = 0;

   c1->cd();
   agr = new TGraph( n, energy, resolution );
   agr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraph( n, energy, resolution90 );
   bgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraph( n, energy, resolution95 );
   cgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraph( n, energy, resolution_hist );
   dgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Relative energy resolution" );
   agr->GetYaxis()->SetRangeUser(0.0, 0.30);
   agr->SetTitle(fname);
    
   //TF1 *f1 = new TF1("f1", "sqrt([0]*[0]/x + [1]*[1])" );
   //TF1 *f2 = new TF1("f2", "sqrt([0]*[0]/x + [1]*[1])" );
   //TF1 *f3 = new TF1("f3", "sqrt([0]*[0]/x + [1]*[1])" );
   //TF1 *f4 = new TF1("f4", "sqrt([0]*[0]/x + [1]*[1])" );
    
   TF1 *f1 = new TF1("f1", "sqrt([0]*[0]/x + [1]*[1] + ([2]*[2])/(x*x))" );
   TF1 *f2 = new TF1("f2", "sqrt([0]*[0]/x + [1]*[1] + ([2]*[2])/(x*x))" );
   TF1 *f3 = new TF1("f3", "sqrt([0]*[0]/x + [1]*[1] + ([2]*[2])/(x*x))" );
   TF1 *f4 = new TF1("f4", "sqrt([0]*[0]/x + [1]*[1] + ([2]*[2])/(x*x))" );
    
   cout << "Fit:" << endl;
   agr -> Fit( f1 );
   cout << "Hist90:" << endl;
   bgr -> Fit( f2 );
   cout << "Hist95:" << endl;
   cgr -> Fit( f3 );
   cout << "Hist:" << endl;
   dgr -> Fit( f4 );
   f1->SetLineColor(kBlue);
   f2->SetLineColor(kRed);
   f3->SetLineColor(kGreen);
   f4->SetLineColor(kMagenta);

   c1 -> cd();
   agr->SetFillColor(kBlue);
   //agr->SetFillStyle(3001);
   agr->SetMarkerColor(kBlue);
   agr->SetLineColor(kBlue);
   agr->SetLineWidth(3);
   agr->SetMarkerStyle(20);
   agr->Draw("A P");
//   f1 -> Draw();
   bgr->SetMarkerColor(kRed);
   bgr->SetLineColor(kRed);
   bgr->SetLineWidth(3);
   bgr->SetFillColor(kRed);
   bgr->SetMarkerStyle(20);
   bgr->Draw("P SAME");
//   f2 -> Draw("SAME");
   cgr->SetMarkerColor(kGreen);
   //cgr->SetFillStyle(3001);
   cgr->SetLineColor(kGreen);
   cgr->SetLineWidth(3);
   cgr->SetFillColor(kGreen);
   cgr->SetMarkerStyle(20);
   cgr->Draw("P SAME");
//   f3 -> Draw("SAME");
   dgr->SetMarkerColor(kMagenta);
   dgr->SetLineColor(kMagenta);
   dgr->SetLineWidth(3);
   dgr->SetFillColor(kMagenta);
   dgr->SetMarkerStyle(20);
   dgr->Draw("P SAME");
//   f4 -> Draw("SAME");
   c1->Update();
    
   TLegend *lsc1 = new TLegend(0.55,0.62,0.90,0.92);
   lsc1->AddEntry(agr,"fit (w/o errors)","pl");
   lsc1->AddEntry(bgr,"hist90 (w/o errors)","pl");
   lsc1->AddEntry(cgr,"hist95 (w/o errors)","pl");
   lsc1->AddEntry(dgr,"hist (w/o errors)","pl");

   c1->cd();
   lsc1->Draw();

}

