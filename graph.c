void graph(int count = 1) {
   TCanvas *c1 = new TCanvas("graph","graph",200,10,700,500);

   //c1->SetFillColor(42);
   //gStyle->SetPalette(52);
   c1->SetGrid();
   //c1->GetFrame()->SetFillColor(21);
   //c1->GetFrame()->SetBorderSize(12);

   const Int_t n = 9;

   Float_t energy[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t energyerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t meanerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t sigma[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t sigmaerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t value[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t error[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

   Float_t energy2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t energyerror2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t meanerror2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t sigma2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t sigmaerror2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t value2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t error2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

   Float_t energy3[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t energyerror3[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean3[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t meanerror3[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t sigma3[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t sigmaerror3[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t value3[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t error3[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

   float temp11 = 0;
   float temp12 = 0;
   float temp21 = 0;
   float temp22 = 0;
   float temp31 = 0;
   float temp32 = 0;
/*
   for (int i = 0; i < n; i++) {
     printf( " %f ", energy[i] );
     printf( " %f ", energyerror[i] );
     printf( " %f ", mean[i] );
     printf( " %f ", meanerror[i] );
     printf( " %f ", sigma[i] );
     printf( " %f ", sigmaerror[i] );
     printf( " %f ", value[i] );
     printf( " %f ", error[i] );
     printf( "\n" );
     printf( " %f ", energy2[i] );
     printf( " %f ", energyerror2[i] );
     printf( " %f ", mean2[i] );
     printf( " %f ", meanerror2[i] );
     printf( " %f ", sigma2[i] );
     printf( " %f ", sigmaerror2[i] );
     printf( " %f ", value2[i] );
     printf( " %f ", error2[i] );
     printf( "\n" );
   }
*/
   FILE *file = fopen("out_nodigi.txt", "r");
   if ( !(long)file ) return;

   FILE *file2 = fopen("out_digi.txt", "r");
   if ( !(long)file2 ) return;

   FILE *file3 = fopen("out_60digi.txt", "r");
   if ( !(long)file3 ) return;

  for ( int i = 0; i < n; i++ ) {
    fscanf( file, "%f %E %E %E %E %E %E\n", &energy[i], &mean[i], &meanerror[i], &sigma[i], &sigmaerror[i], &temp11, &temp12 );
    if ( feof( file ) ) break;
  }

  for ( int i = 0; i < n; i++ ) {
    fscanf( file2, "%f %E %E %E %E %E %E\n", &energy2[i], &mean2[i], &meanerror2[i], &sigma2[i], &sigmaerror2[i], &temp21, &temp22 );
    if ( feof( file2 ) ) break;
  }

  for ( int i = 0; i < n; i++ ) {
    fscanf( file3, "%f %E %E %E %E %E %E\n", &energy3[i], &mean3[i], &meanerror3[i], &sigma3[i], &sigmaerror3[i], &temp31, &temp32 );
    if ( feof( file3 ) ) break;
  }

  for ( int i = 0; i < n; i++ ) {
    value[ i ] = sigma[i] / mean[i];
    error[ i ] = sqrt( pow( (sigmaerror[i])/(mean[i]) ,2 ) + pow( (sigma[i] * meanerror[i])/(mean[i] * mean[i]) ,2 ) );

    value2[ i ] = sigma2[i] / mean2[i];
    error2[ i ] = sqrt( pow( (sigmaerror2[i])/(mean2[i]) ,2 ) + pow( (sigma2[i] * meanerror2[i])/(mean2[i] * mean2[i]) ,2 ) );

    value3[ i ] = sigma3[i] / mean3[i];
    error3[ i ] = sqrt( pow( (sigmaerror3[i])/(mean3[i]) ,2 ) + pow( (sigma3[i] * meanerror3[i])/(mean3[i] * mean3[i]) ,2 ) );
  }

   printf( "\n" );
   for (int i = 0; i < n; i++) {
     printf( " %f ", energy[i] );
     printf( " %f ", energyerror[i] );
     printf( " %f ", mean[i] );
     printf( " %f ", meanerror[i] );
     printf( " %f ", sigma[i] );
     printf( " %f ", sigmaerror[i] );
     printf( " %f ", value[i] );
     printf( " %f ", error[i] );
     printf( "\n" );
   }

   printf( "\n" );
   for (int i = 0; i < n; i++) {
     printf( " %f ", energy2[i] );
     printf( " %f ", energyerror2[i] );
     printf( " %f ", mean2[i] );
     printf( " %f ", meanerror2[i] );
     printf( " %f ", sigma2[i] );
     printf( " %f ", sigmaerror2[i] );
     printf( " %f ", value2[i] );
     printf( " %f ", error2[i] );
     printf( "\n" );
   }

   printf( "\n" );
   for (int i = 0; i < n; i++) {
     printf( " %f ", energy3[i] );
     printf( " %f ", energyerror3[i] );
     printf( " %f ", mean3[i] );
     printf( " %f ", meanerror3[i] );
     printf( " %f ", sigma3[i] );
     printf( " %f ", sigmaerror3[i] );
     printf( " %f ", value3[i] );
     printf( " %f ", error3[i] );
     printf( "\n" );
   }

   printf( "Here is difference:\n" );

   Float_t v1 = 0;
   Float_t v2 = 0;
   Float_t v3 = 0;
  
   for ( int i = 0; i < n; i++ ) {
       printf( " %f, %f, %f, %f \n", energy[i], value[i], value2[i], value3[i] );
       printf( " Difference between nodigi and digi20: %f \n", value2[i] - value[i] );
       v1 = v1 + ( value2[i] - value[i] );
       printf( " Difference between digi20 and digi60: %f \n", value3[i] - value2[i] );
       v2 = v2 + ( value3[i] - value2[i] );
       printf( " Difference between nodigi and digi60: %f \n", value3[i] - value[i] );
       v3 = v3 + ( value3[i] - value[i] );
   } 

   printf( "Average values: %f, %f, %f \n", v1/n, v2/n, v3/n );

   TGraphErrors *agr;
   TGraphErrors *bgr;
   TGraphErrors *cgr;

   char fname[ 100 ];
   for ( int i = 0; i < 100; i++ ) fname[ i ] = 0;

   if ( count == 1 ) {
     //agr = new TGraphErrors( n, energy, sigma, energyerror, sigmaerror );
     agr = new TGraphErrors( n, energy, value, energyerror, error );

     //bgr = new TGraphErrors( n, energy2, sigma2, energyerror2, sigmaerror2 );
     bgr = new TGraphErrors( n, energy2, value2, energyerror2, error2 );

     //cgr = new TGraphErrors( n, energy3, sigma3, energyerror3, sigmaerror3 );
     cgr = new TGraphErrors( n, energy3, value3, energyerror3, error3 );

     sprintf( fname, "" ); // Relative energy resolution
     agr->GetYaxis()->SetTitle("Sigma / Mean");
     agr->GetXaxis()->SetTitle("Energy, GeV");
     bgr->GetYaxis()->SetTitle("Sigma / Mean");
     bgr->GetXaxis()->SetTitle("Energy, GeV");
     cgr->GetYaxis()->SetTitle("Sigma / Mean");
     cgr->GetXaxis()->SetTitle("Energy, GeV");

     agr->GetYaxis()->SetRangeUser(0.0,0.25);

   } 
   else {
     agr = new TGraphErrors( n, energy, sigma, energyerror, sigmaerror );
     //agr = new TGraphErrors( n, energy, value, energyerror, error );

     bgr = new TGraphErrors( n, energy2, sigma2, energyerror2, sigmaerror2 );
     //bgr = new TGraphErrors( n, energy2, value2, energyerror2, error2 );

     cgr = new TGraphErrors( n, energy3, sigma3, energyerror3, sigmaerror3 );
     //cgr = new TGraphErrors( n, energy3, value3, energyerror3, error3 );

     sprintf( fname, "" ); // Absolute energy resolution
     agr->GetYaxis()->SetTitle("Sigma, GeV");
     agr->GetXaxis()->SetTitle("Energy, GeV");
     bgr->GetYaxis()->SetTitle("Sigma, GeV");
     bgr->GetXaxis()->SetTitle("Energy, GeV");
     cgr->GetYaxis()->SetTitle("Sigma, GeV");
     cgr->GetXaxis()->SetTitle("Energy, GeV");

     agr->GetYaxis()->SetRangeUser(0.0,8.0);

   }

   agr->SetTitle(fname);
   agr->SetMarkerColor(12); // kBlue
   agr->SetMarkerStyle(34); // 21
   agr->Draw("ALP");
   bgr->SetMarkerColor(15); // kRed
   bgr->SetMarkerStyle(22); // 21
   bgr->Draw("LPSAME");
   cgr->SetMarkerColor(17); // kGreen
   cgr->SetMarkerStyle(20); // 21
   cgr->Draw("LPSAME");

   TLegend *lsc = new TLegend(0.55,0.62,0.90,0.92);
   lsc->AddEntry(agr,"nodigi","pl");
   lsc->AddEntry(bgr,"digi(20%)","pl");
   lsc->AddEntry(cgr,"digi(60%)","pl");
   lsc->Draw();

   c1->Update();

}



