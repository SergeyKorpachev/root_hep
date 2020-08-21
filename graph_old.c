void graph() {
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
    
   Float_t ratio_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t ratio_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t ratio_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_hist95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
   Float_t ratio90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t ratio95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error95[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t linearity_error[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t absolute_error[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
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

    //linearity_error[ i ] = sqrt( ( pow( mean_meanerror[ i ], 2 ) ) + ( pow( rms_mean[ i ], 2 ) ) );
    //absolute_error[ i ] = sqrt( ( pow( mean_sigmaerror[ i ], 2 ) ) + ( pow( rms_sigma[ i ], 2 ) ) );
    //linearity_error2[ i ] = sqrt( ( pow( mean_meanerror2[ i ], 2 ) ) + ( pow( rms_mean2[ i ], 2 ) ) );
    //absolute_error2[ i ] = sqrt( ( pow( mean_sigmaerror2[ i ], 2 ) ) + ( pow( rms_sigma2[ i ], 2 ) ) );

    ratio_hist[ i ] = ( mean[i] - energy[i] ) / energy[i];
    ratio_error_stat_hist[ i ] = sqrt( pow( (meanerror[i]) / (energy[i]), 2 ) + pow( (mean[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys_hist[ i ] = 0.0;
    ratio_error_hist[ i ] = sqrt( ( pow( ratio_error_stat_hist[ i ], 2 ) ) + ( pow( ratio_error_sys_hist[ i ], 2 ) ) );
      
    ratio_hist90[ i ] = ( mean_hist90[i] - energy[i] ) / energy[i];
    ratio_error_stat_hist90[ i ] = sqrt( pow( (meanerror_hist90[i]) / (energy[i]), 2 ) + pow( (mean_hist90[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys_hist90[ i ] = 0.0;
    ratio_error_hist90[ i ] = sqrt( ( pow( ratio_error_stat_hist90[ i ], 2 ) ) + ( pow( ratio_error_sys_hist90[ i ], 2 ) ) );
      
    ratio_hist95[ i ] = ( mean_hist95[i] - energy[i] ) / energy[i];
    ratio_error_stat_hist95[ i ] = sqrt( pow( (meanerror_hist95[i]) / (energy[i]), 2 ) + pow( (mean_hist95[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys_hist95[ i ] = 0.0;
    ratio_error_hist95[ i ] = sqrt( ( pow( ratio_error_stat_hist95[ i ], 2 ) ) + ( pow( ratio_error_sys_hist95[ i ], 2 ) ) );

    ratio90[ i ] = ( mean90[i] - energy[i] ) / energy[i];
    ratio_error_stat90[ i ] = 0.0;
    ratio_error_sys90[ i ] = 0.0;
    ratio_error90[ i ] = sqrt( ( pow( ratio_error_stat90[ i ], 2 ) ) + ( pow( ratio_error_sys90[ i ], 2 ) ) );
    ratio95[ i ] = ( mean95[i] - energy[i] ) / energy[i];
    ratio_error_stat95[ i ] = 0.0;
    ratio_error_sys95[ i ] = 0.0;
    ratio_error95[ i ] = sqrt( ( pow( ratio_error_stat95[ i ], 2 ) ) + ( pow( ratio_error_sys95[ i ], 2 ) ) );
    
    ratio[ i ] = ( mean_mean[i] - energy[i] ) / energy[i];
    ratio_error_stat[ i ] = sqrt( pow( (mean_meanerror[i]) / (energy[i]), 2 ) + pow( (mean_mean[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys[ i ] = 0.0;
    ratio_error[ i ] = sqrt( ( pow( ratio_error_stat[ i ], 2 ) ) + ( pow( ratio_error_sys[ i ], 2 ) ) );
    
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
    
    
/*    printf( "\n" );
    for (int i = 0; i < n; i++) {
        
      printf( " mean_hist90 === %f \n", mean_hist90[i] );
      printf( " rms_hist90 === %f \n", rms_hist90[i] );
      printf( " mean_hist95 === %f \n", mean_hist95[i] );
      printf( " rms_hist95 === %f \n", rms_hist95[i] );

      printf( " mean90 === %f \n", mean90[i] );
      printf( " rms90 === %f \n", rms90[i] );
      printf( " mean95 === %f \n", mean95[i] );
      printf( " rms95 === %f \n", rms95[i] );
        
          printf( "\n" );
     
      printf( " ratio_hist90 === %f \n", ratio_hist90[i] );
      printf( " ratio_error_hist90 === %f \n", ratio_error_hist90[i] );
      printf( " resolution_hist90 === %f \n", resolution_hist90[i] );
      printf( " resolution_error_hist90 === %f \n", resolution_error_hist90[i] );
      printf( " ratio_hist95 === %f \n", ratio_hist95[i] );
      printf( " ratio_error_hist95 === %f \n", ratio_error_hist95[i] );
      printf( " resolution_hist95 === %f \n", resolution_hist95[i] );
      printf( " resolution_error_hist95 === %f \n", resolution_error_hist95[i] );
      
      printf( " ratio90 === %f \n", ratio90[i] );
      printf( " ratio_error90 === %f \n", ratio_error90[i] );
      printf( " resolution90 === %f \n", resolution90[i] );
      printf( " resolution_error90 === %f \n", resolution_error90[i] );
      printf( " ratio95 === %f \n", ratio95[i] );
      printf( " ratio_error95 === %f \n", ratio_error95[i] );
      printf( " resolution95 === %f \n", resolution95[i] );
      printf( " resolution_error95 === %f \n", resolution_error95[i] );

      printf( "\n" );
      printf( "\n" );
      printf( "\n" );

    }
*/
    
    
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
       
     printf( " %f ", ratio_hist[i] );
     printf( " %f ", ratio_error_hist[i] );
     printf( " %f ", resolution_hist[i] );
     printf( " %f ", resolution_error_hist[i] );
    
     printf( " %f ", ratio_hist90[i] );
     printf( " %f ", ratio_error_hist90[i] );
     printf( " %f ", resolution_hist90[i] );
     printf( " %f ", resolution_error_hist90[i] );
       
     printf( " %f ", ratio_hist95[i] );
     printf( " %f ", ratio_error_hist95[i] );
     printf( " %f ", resolution_hist95[i] );
     printf( " %f ", resolution_error_hist95[i] );
     
     printf( " %f ", ratio90[i] );
     printf( " %f ", ratio_error90[i] );
     printf( " %f ", resolution90[i] );
     printf( " %f ", resolution_error90[i] );
     printf( " %f ", ratio95[i] );
     printf( " %f ", ratio_error95[i] );
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
     printf( " %f ", linearity_error[i] );
     printf( " %f ", absolute_error[i] );
     printf( " %f ", ratio[i] );
     printf( " %f ", ratio_error[i] );
     printf( " %f ", resolution[i] );
     printf( " %f ", resolution_error[i] );
     
     printf( "\n" );
     printf( "\n" );
     printf( "\n" );

   }

   TGraphErrors *agr;
   TGraphErrors *bgr;
    
   TGraphErrors *cgr;
   TGraphErrors *dgr;
    
   TGraphErrors *egr;
   TGraphErrors *fgr;
    
   TGraphErrors *ggr;
   TGraphErrors *hgr;

   char fname[ 100 ];
   for ( int i = 0; i < 100; i++ ) fname[ i ] = 0;

   c1->cd();
   agr = new TGraphErrors( n, energy, ratio, energyerror, ratio_error_sys );
   //agr = new TGraphErrors( n, energy, ratio80, energyerror, ratio_error_sys80 );
   //agr = new TGraphErrors( n, energy, ratio90, energyerror, ratio_error_sys90 );
   //agr = new TGraphErrors( n, energy, ratio, energyerror, ratio_error_sys );
   //agr = new TGraphErrors( n, energy, ratio90, energyerror, ratio_error_sys90 );
   //agr = new TGraphErrors( n, energy, ratio2, energyerror, ratio_error_sys2 );
   //agr = new TGraphErrors( n, energy, ratio, energyerror, ratio_error_sys );
   agr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, ratio, energyerror, ratio_error_stat );
   //bgr = new TGraphErrors( n, energy, ratio80, energyerror, ratio_error_stat80 );
   //bgr = new TGraphErrors( n, energy, ratio90, energyerror, ratio_error_stat90 );
   //bgr = new TGraphErrors( n, energy, ratio, energyerror, ratio_error_stat );
   //bgr = new TGraphErrors( n, energy, ratio90, energyerror, ratio_error_stat90 );
   //bgr = new TGraphErrors( n, energy, ratio2, energyerror, ratio_error_stat2 );
   //bgr = new TGraphErrors( n, energy, ratio, energyerror, ratio_error_stat );
   bgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, ratio_hist90, energyerror, ratio_error_sys_hist90 );
   //cgr = new TGraphErrors( n, energy, ratio85, energyerror, ratio_error_sys85 );
   //cgr = new TGraphErrors( n, energy, ratio95, energyerror, ratio_error_sys95 );
   //cgr = new TGraphErrors( n, energy, ratio2, energyerror, ratio_error_sys2 );
   //cgr = new TGraphErrors( n, energy, ratio100, energyerror, ratio_error_sys100 );
   //cgr = new TGraphErrors( n, energy, ratio_hist, energyerror, ratio_error_sys_hist );
   //cgr = new TGraphErrors( n, energy, ratio2, energyerror, ratio_error_sys2 );
   cgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, ratio_hist90, energyerror, ratio_error_stat_hist90 );
   //dgr = new TGraphErrors( n, energy, ratio85, energyerror, ratio_error_stat85 );
   //dgr = new TGraphErrors( n, energy, ratio95, energyerror, ratio_error_stat95 );
   //dgr = new TGraphErrors( n, energy, ratio2, energyerror, ratio_error_stat2 );
   //dgr = new TGraphErrors( n, energy, ratio100, energyerror, ratio_error_stat100 );
   //dgr = new TGraphErrors( n, energy, ratio_hist, energyerror, ratio_error_stat_hist );
   //dgr = new TGraphErrors( n, energy, ratio2, energyerror, ratio_error_stat2 );
   dgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   egr = new TGraphErrors( n, energy, ratio_hist95, energyerror, ratio_error_sys_hist95 );
   //egr = new TGraphErrors( n, energy, ratio90, energyerror, ratio_error_sys90 );
   //egr = new TGraphErrors( n, energy, ratio100, energyerror, ratio_error_sys100 );
   //egr = new TGraphErrors( n, energy, ratio90, energyerror, ratio_error_sys90 );
   //egr = new TGraphErrors( n, energy, ratio_hist, energyerror, ratio_error_sys_hist );
   //egr = new TGraphErrors( n, energy, ratio90, energyerror, ratio_error_sys90 );
   //egr = new TGraphErrors( n, energy, ratio_hist, energyerror, ratio_error_sys_hist );
   egr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   egr->GetXaxis()->SetTitle("E_{true}, GeV");
   fgr = new TGraphErrors( n, energy, ratio_hist95, energyerror, ratio_error_stat_hist95 );
   //fgr = new TGraphErrors( n, energy, ratio90, energyerror, ratio_error_stat90 );
   //fgr = new TGraphErrors( n, energy, ratio100, energyerror, ratio_error_stat100 );
   //fgr = new TGraphErrors( n, energy, ratio90, energyerror, ratio_error_stat90 );
   //fgr = new TGraphErrors( n, energy, ratio_hist, energyerror, ratio_error_stat_hist );
   //fgr = new TGraphErrors( n, energy, ratio90, energyerror, ratio_error_stat90 );
   //fgr = new TGraphErrors( n, energy, ratio_hist, energyerror, ratio_error_stat_hist );
   fgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   fgr->GetXaxis()->SetTitle("E_{true}, GeV");
   ggr = new TGraphErrors( n, energy, ratio_hist, energyerror, ratio_error_sys_hist );
   ggr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   ggr->GetXaxis()->SetTitle("E_{true}, GeV");
   hgr = new TGraphErrors( n, energy, ratio_hist, energyerror, ratio_error_stat_hist );
   hgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   hgr->GetXaxis()->SetTitle("E_{true}, GeV");
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
   egr->SetMarkerColor(kViolet-6);
   egr->SetFillStyle(3001);
   egr->SetLineColor(kViolet-6);
   egr->SetLineWidth(3);
   egr->SetFillColor(kViolet-6);
   egr->SetMarkerStyle(20);
   egr->Draw("3 SAME");
   fgr->SetMarkerColor(kGreen+1);
   fgr->SetLineColor(kGreen+1);
   fgr->SetLineWidth(3);
   fgr->SetFillColor(kViolet-6);
   fgr->SetMarkerStyle(20);
   fgr->Draw("P SAME");
   ggr->SetMarkerColor(kMagenta-10);
   ggr->SetFillStyle(3001);
   ggr->SetLineColor(kMagenta-10);
   ggr->SetLineWidth(3);
   ggr->SetFillColor(kMagenta-10);
   ggr->SetMarkerStyle(20);
   ggr->Draw("3 SAME");
   hgr->SetMarkerColor(kMagenta+1);
   hgr->SetLineColor(kMagenta+1);
   hgr->SetLineWidth(3);
   hgr->SetFillColor(kMagenta-10);
   hgr->SetMarkerStyle(20);
   hgr->Draw("P SAME");
   c1->Update();

   c2->cd();
   agr = new TGraphErrors( n, energy, mean_sigma, energyerror, energyerror );
   //agr = new TGraphErrors( n, energy, rms80, energyerror, energyerror );
   //agr = new TGraphErrors( n, energy, rms90, energyerror, energyerror );
   //agr = new TGraphErrors( n, energy, mean_sigma, energyerror, rms_sigma );
   //agr = new TGraphErrors( n, energy, rms90, energyerror, energyerror );
   //agr = new TGraphErrors( n, energy, mean_sigma2, energyerror, rms_sigma2 );
   //agr = new TGraphErrors( n, energy, mean_sigma, energyerror, rms_sigma );
   //agr->GetYaxis()->SetTitle("#sigma_{reco}, GeV");
   //agr->GetXaxis()->SetTitle("E_{true}, GeV");
   agr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, mean_sigma, energyerror, mean_sigmaerror );
   //bgr = new TGraphErrors( n, energy, rms80, energyerror, energyerror );
   //bgr = new TGraphErrors( n, energy, rms90, energyerror, energyerror );
   //bgr = new TGraphErrors( n, energy, mean_sigma, energyerror, mean_sigmaerror );
   //bgr = new TGraphErrors( n, energy, rms90, energyerror, energyerror );
   //bgr = new TGraphErrors( n, energy, mean_sigma2, energyerror, mean_sigmaerror2 );
   //bgr = new TGraphErrors( n, energy, mean_sigma, energyerror, mean_sigmaerror );
   bgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, rms_hist90, energyerror, energyerror );
   //cgr = new TGraphErrors( n, energy, rms85, energyerror, energyerror );
   //cgr = new TGraphErrors( n, energy, rms95, energyerror, energyerror );
   //cgr = new TGraphErrors( n, energy, mean_sigma2, energyerror, rms_sigma2 );
   //cgr = new TGraphErrors( n, energy, rms100, energyerror, energyerror );
   //cgr = new TGraphErrors( n, energy, rms, energyerror, energyerror );// energyerror == 0
   //cgr = new TGraphErrors( n, energy, mean_sigma2, energyerror, rms_sigma2 );
   cgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, rms_hist90, energyerror, rmserror_hist90 );
   //dgr = new TGraphErrors( n, energy, rms85, energyerror, energyerror );
   //dgr = new TGraphErrors( n, energy, rms95, energyerror, energyerror );
   //dgr = new TGraphErrors( n, energy, mean_sigma2, energyerror, mean_sigmaerror2 );
   //dgr = new TGraphErrors( n, energy, rms100, energyerror, energyerror );
   //dgr = new TGraphErrors( n, energy, rms, energyerror, rmserror );
   //dgr = new TGraphErrors( n, energy, mean_sigma2, energyerror, mean_sigmaerror2 );
   dgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   egr = new TGraphErrors( n, energy, rms_hist95, energyerror, energyerror );
   //egr = new TGraphErrors( n, energy, rms90, energyerror, energyerror );
   //egr = new TGraphErrors( n, energy, rms100, energyerror, energyerror );
   //egr = new TGraphErrors( n, energy, rms90, energyerror, energyerror );
   //egr = new TGraphErrors( n, energy, rms, energyerror, energyerror );
   //egr = new TGraphErrors( n, energy, rms90, energyerror, energyerror );
   //egr = new TGraphErrors( n, energy, rms, energyerror, energyerror );
   egr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   egr->GetXaxis()->SetTitle("E_{true}, GeV");
   fgr = new TGraphErrors( n, energy, rms_hist95, energyerror, rmserror_hist95 );
   //fgr = new TGraphErrors( n, energy, rms90, energyerror, energyerror );
   //fgr = new TGraphErrors( n, energy, rms100, energyerror, energyerror );
   //fgr = new TGraphErrors( n, energy, rms90, energyerror, energyerror );
   //fgr = new TGraphErrors( n, energy, rms, energyerror, rmserror );
   //fgr = new TGraphErrors( n, energy, rms90, energyerror, energyerror );
   //fgr = new TGraphErrors( n, energy, rms, energyerror, rmserror );
   fgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   fgr->GetXaxis()->SetTitle("E_{true}, GeV");
   ggr = new TGraphErrors( n, energy, rms, energyerror, energyerror );
   ggr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   ggr->GetXaxis()->SetTitle("E_{true}, GeV");
   hgr = new TGraphErrors( n, energy, rms, energyerror, rmserror );
   hgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   hgr->GetXaxis()->SetTitle("E_{true}, GeV");
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
   egr->SetMarkerColor(kViolet-6);
   egr->SetFillStyle(3001);
   egr->SetLineColor(kViolet-6);
   egr->SetLineWidth(3);
   egr->SetFillColor(kViolet-6);
   egr->SetMarkerStyle(20);
   egr->Draw("3 SAME");
   fgr->SetMarkerColor(kGreen+1);
   fgr->SetLineColor(kGreen+1);
   fgr->SetLineWidth(3);
   fgr->SetFillColor(kViolet-6);
   fgr->SetMarkerStyle(20);
   fgr->Draw("P SAME");
   ggr->SetMarkerColor(kMagenta-10);
   ggr->SetFillStyle(3001);
   ggr->SetLineColor(kMagenta-10);
   ggr->SetLineWidth(3);
   ggr->SetFillColor(kMagenta-10);
   ggr->SetMarkerStyle(20);
   ggr->Draw("3 SAME");
   hgr->SetMarkerColor(kMagenta+1);
   hgr->SetLineColor(kMagenta+1);
   hgr->SetLineWidth(3);
   hgr->SetFillColor(kMagenta-10);
   hgr->SetMarkerStyle(20);
   hgr->Draw("P SAME");
   c2->Update();

   c3->cd();
   agr = new TGraphErrors( n, energy, mean_mean, energyerror, energyerror );
   //agr = new TGraphErrors( n, energy, mean80, energyerror, energyerror );
   //agr = new TGraphErrors( n, energy, mean90, energyerror, energyerror );
   //agr = new TGraphErrors( n, energy, mean_mean, energyerror, rms_mean );
   //agr = new TGraphErrors( n, energy, mean90, energyerror, energyerror );
   //agr = new TGraphErrors( n, energy, mean_mean2, energyerror, rms_mean2 );
   //agr = new TGraphErrors( n, energy, mean_mean, energyerror, rms_mean );
   agr->GetYaxis()->SetTitle("E_{reco}, GeV");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, mean_mean, energyerror, mean_meanerror );
   //bgr = new TGraphErrors( n, energy, mean80, energyerror, energyerror );
   //bgr = new TGraphErrors( n, energy, mean90, energyerror, energyerror );
   //bgr = new TGraphErrors( n, energy, mean_mean, energyerror, mean_meanerror );
   //bgr = new TGraphErrors( n, energy, mean90, energyerror, energyerror );
   //bgr = new TGraphErrors( n, energy, mean_mean2, energyerror, mean_meanerror2 );
   //bgr = new TGraphErrors( n, energy, mean_mean, energyerror, mean_meanerror );
   bgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, mean_hist90, energyerror, energyerror );
   //cgr = new TGraphErrors( n, energy, mean85, energyerror, energyerror );
   //cgr = new TGraphErrors( n, energy, mean95, energyerror, energyerror );
   //cgr = new TGraphErrors( n, energy, mean_mean2, energyerror, rms_mean2 );
   //cgr = new TGraphErrors( n, energy, mean100, energyerror, energyerror );
   //cgr = new TGraphErrors( n, energy, mean, energyerror, energyerror );
   //cgr = new TGraphErrors( n, energy, mean_mean2, energyerror, rms_mean2 );
   cgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, mean_hist90, energyerror, meanerror_hist90 );
   //dgr = new TGraphErrors( n, energy, mean85, energyerror, energyerror );
   //dgr = new TGraphErrors( n, energy, mean95, energyerror, energyerror );
   //dgr = new TGraphErrors( n, energy, mean_mean2, energyerror, mean_meanerror2 );
   //dgr = new TGraphErrors( n, energy, mean100, energyerror, energyerror );
   //dgr = new TGraphErrors( n, energy, mean, energyerror, meanerror );
   //dgr = new TGraphErrors( n, energy, mean_mean2, energyerror, mean_meanerror2 );
   dgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   egr = new TGraphErrors( n, energy, mean_hist95, energyerror, energyerror );
   //egr = new TGraphErrors( n, energy, mean90, energyerror, energyerror );
   //egr = new TGraphErrors( n, energy, mean100, energyerror, energyerror );
   //egr = new TGraphErrors( n, energy, mean90, energyerror, energyerror );
   //egr = new TGraphErrors( n, energy, mean, energyerror, energyerror );
   //egr = new TGraphErrors( n, energy, mean90, energyerror, energyerror );
   //egr = new TGraphErrors( n, energy, mean, energyerror, energyerror );
   egr->GetYaxis()->SetTitle("E_{reco}, GeV");
   egr->GetXaxis()->SetTitle("E_{true}, GeV");
   fgr = new TGraphErrors( n, energy, mean_hist95, energyerror, meanerror_hist95 );
   //fgr = new TGraphErrors( n, energy, mean90, energyerror, energyerror );
   //fgr = new TGraphErrors( n, energy, mean100, energyerror, energyerror );
   //fgr = new TGraphErrors( n, energy, mean90, energyerror, energyerror );
   //fgr = new TGraphErrors( n, energy, mean, energyerror, meanerror );
   //fgr = new TGraphErrors( n, energy, mean90, energyerror, energyerror );
   //fgr = new TGraphErrors( n, energy, mean, energyerror, meanerror );
   fgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   fgr->GetXaxis()->SetTitle("E_{true}, GeV");
   ggr = new TGraphErrors( n, energy, mean, energyerror, energyerror );
   ggr->GetYaxis()->SetTitle("E_{reco}, GeV");
   ggr->GetXaxis()->SetTitle("E_{true}, GeV");
   hgr = new TGraphErrors( n, energy, mean, energyerror, meanerror );
   hgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   hgr->GetXaxis()->SetTitle("E_{true}, GeV");
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
   egr->SetMarkerColor(kViolet-6);
   egr->SetFillStyle(3001);
   egr->SetLineColor(kViolet-6);
   egr->SetLineWidth(3);
   egr->SetFillColor(kViolet-6);
   egr->SetMarkerStyle(20);
   egr->Draw("3 SAME");
   fgr->SetMarkerColor(kGreen+1);
   fgr->SetLineColor(kGreen+1);
   fgr->SetLineWidth(3);
   fgr->SetFillColor(kViolet-6);
   fgr->SetMarkerStyle(20);
   fgr->Draw("P SAME");
   ggr->SetMarkerColor(kMagenta-10);
   ggr->SetFillStyle(3001);
   ggr->SetLineColor(kMagenta-10);
   ggr->SetLineWidth(3);
   ggr->SetFillColor(kMagenta-10);
   ggr->SetMarkerStyle(20);
   ggr->Draw("3 SAME");
   hgr->SetMarkerColor(kMagenta+1);
   hgr->SetLineColor(kMagenta+1);
   hgr->SetLineWidth(3);
   hgr->SetFillColor(kMagenta-10);
   hgr->SetMarkerStyle(20);
   hgr->Draw("P SAME");
   c3->Update();

   c4->cd();
   agr = new TGraphErrors( n, energy, resolution, energyerror, resolution_error_sys );
   //agr = new TGraphErrors( n, energy, resolution80, energyerror, resolution_error_sys80 );
   //agr = new TGraphErrors( n, energy, resolution90, energyerror, resolution_error_sys90 );
   //agr = new TGraphErrors( n, energy, resolution, energyerror, resolution_error_sys );
   //agr = new TGraphErrors( n, energy, resolution90, energyerror, resolution_error_sys90 );
   //agr = new TGraphErrors( n, energy, resolution2, energyerror, resolution_error_sys2 );
   //agr = new TGraphErrors( n, energy, resolution, energyerror, resolution_error_sys );
   //agr->GetYaxis()->SetTitle("#sigma_{reco} / E_{reco}");
   //agr->GetXaxis()->SetTitle("E_{true}, GeV");
   agr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, resolution, energyerror, resolution_error_stat );
   //bgr = new TGraphErrors( n, energy, resolution80, energyerror, resolution_error_stat80 );
   //bgr = new TGraphErrors( n, energy, resolution90, energyerror, resolution_error_stat90 );
   //bgr = new TGraphErrors( n, energy, resolution, energyerror, resolution_error_stat );
   //bgr = new TGraphErrors( n, energy, resolution90, energyerror, resolution_error_stat90 );
   //bgr = new TGraphErrors( n, energy, resolution2, energyerror, resolution_error_stat2 );
   //bgr = new TGraphErrors( n, energy, resolution, energyerror, resolution_error_stat );
   bgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, resolution_hist90, energyerror, resolution_error_sys_hist90 );
   //cgr = new TGraphErrors( n, energy, resolution85, energyerror, resolution_error_sys85 );
   //cgr = new TGraphErrors( n, energy, resolution95, energyerror, resolution_error_sys95 );
   //cgr = new TGraphErrors( n, energy, resolution2, energyerror, resolution_error_sys2 );
   //cgr = new TGraphErrors( n, energy, resolution100, energyerror, resolution_error_sys100 );
   //cgr = new TGraphErrors( n, energy, resolution_hist, energyerror, resolution_error_sys_hist );
   //cgr = new TGraphErrors( n, energy, resolution2, energyerror, resolution_error_sys2 );
   cgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, resolution_hist90, energyerror, resolution_error_stat_hist90 );
   //dgr = new TGraphErrors( n, energy, resolution85, energyerror, resolution_error_stat85 );
   //dgr = new TGraphErrors( n, energy, resolution95, energyerror, resolution_error_stat95 );
   //dgr = new TGraphErrors( n, energy, resolution2, energyerror, resolution_error_stat2 );
   //dgr = new TGraphErrors( n, energy, resolution100, energyerror, resolution_error_stat100 );
   //dgr = new TGraphErrors( n, energy, resolution_hist, energyerror, resolution_error_stat_hist );
   //dgr = new TGraphErrors( n, energy, resolution2, energyerror, resolution_error_stat2 );
   dgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   egr = new TGraphErrors( n, energy, resolution_hist95, energyerror, resolution_error_sys_hist95 );
   //egr = new TGraphErrors( n, energy, resolution90, energyerror, resolution_error_sys90 );
   //egr = new TGraphErrors( n, energy, resolution100, energyerror, resolution_error_sys100 );
   //egr = new TGraphErrors( n, energy, resolution90, energyerror, resolution_error_sys90 );
   //egr = new TGraphErrors( n, energy, resolution_hist, energyerror, resolution_error_sys_hist );
   //egr = new TGraphErrors( n, energy, resolution90, energyerror, resolution_error_sys90 );
   //egr = new TGraphErrors( n, energy, resolution_hist, energyerror, resolution_error_sys_hist );
   egr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   egr->GetXaxis()->SetTitle("E_{true}, GeV");
   fgr = new TGraphErrors( n, energy, resolution_hist95, energyerror, resolution_error_stat_hist95 );
   //fgr = new TGraphErrors( n, energy, resolution90, energyerror, resolution_error_stat90 );
   //fgr = new TGraphErrors( n, energy, resolution100, energyerror, resolution_error_stat100 );
   //fgr = new TGraphErrors( n, energy, resolution90, energyerror, resolution_error_stat90 );
   //fgr = new TGraphErrors( n, energy, resolution_hist, energyerror, resolution_error_stat_hist );
   //fgr = new TGraphErrors( n, energy, resolution90, energyerror, resolution_error_stat90 );
   //fgr = new TGraphErrors( n, energy, resolution_hist, energyerror, resolution_error_stat_hist );
   fgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   fgr->GetXaxis()->SetTitle("E_{true}, GeV");
   ggr = new TGraphErrors( n, energy, resolution_hist, energyerror, resolution_error_sys_hist );
   ggr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   ggr->GetXaxis()->SetTitle("E_{true}, GeV");
   hgr = new TGraphErrors( n, energy, resolution_hist, energyerror, resolution_error_stat_hist );
   hgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   hgr->GetXaxis()->SetTitle("E_{true}, GeV");
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
   egr->SetMarkerColor(kViolet-6);
   egr->SetFillStyle(3001);
   egr->SetLineColor(kViolet-6);
   egr->SetLineWidth(3);
   egr->SetFillColor(kViolet-6);
   egr->SetMarkerStyle(20);
   egr->Draw("3 SAME");
   fgr->SetMarkerColor(kGreen+1);
   fgr->SetLineColor(kGreen+1);
   fgr->SetLineWidth(3);
   fgr->SetFillColor(kViolet-6);
   fgr->SetMarkerStyle(20);
   fgr->Draw("P SAME");
   ggr->SetMarkerColor(kMagenta-10);
   ggr->SetFillStyle(3001);
   ggr->SetLineColor(kMagenta-10);
   ggr->SetLineWidth(3);
   ggr->SetFillColor(kMagenta-10);
   ggr->SetMarkerStyle(20);
   ggr->Draw("3 SAME");
   hgr->SetMarkerColor(kMagenta+1);
   hgr->SetLineColor(kMagenta+1);
   hgr->SetLineWidth(3);
   hgr->SetFillColor(kMagenta-10);
   hgr->SetMarkerStyle(20);
   hgr->Draw("P SAME");
   c4->Update();
    
   TLegend *lsc1 = new TLegend(0.55,0.62,0.90,0.92);
   lsc1->AddEntry(bgr,"fit (stat)","pl");
   lsc1->AddEntry(dgr,"hist90_2 (stat)","pl");
   lsc1->AddEntry(fgr,"hist95_2 (stat)","pl");
   lsc1->AddEntry(hgr,"hist (stat)","pl");
   //lsc1->AddEntry(bgr,"hist90 (w/o errors)","pl");
   //lsc1->AddEntry(dgr,"hist95 (w/o errors)","pl");
   //lsc1->AddEntry(fgr,"hist90_2 (stat)","pl");
   //lsc1->AddEntry(hgr,"hist95_2 (stat)","pl");
   //lsc1->AddEntry(bgr,"fit (stat)","pl");
   //lsc1->AddEntry(dgr,"hist90 (w/o errors)","pl");
   //lsc1->AddEntry(fgr,"hist95 (w/o errors)","pl");
   //lsc1->AddEntry(hgr,"hist (stat)","pl");
   //lsc1->AddEntry(bgr,"data, rms80 w/o errors","plf");
   //lsc1->AddEntry(dgr,"data, rms85 w/o errors","plf");
   //lsc1->AddEntry(fgr,"data, rms90 w/o errors","plf");
   //lsc1->AddEntry(bgr,"data, rms90 w/o errors","plf");
   //lsc1->AddEntry(dgr,"data, rms95 w/o errors","plf");
   //lsc1->AddEntry(fgr,"data, rms100 w/o errors","plf");
   //lsc1->AddEntry(bgr,"data, fit 1","plf");
   //lsc1->AddEntry(dgr,"data, fit 2 (stat)","plf");
   //lsc1->AddEntry(fgr,"data, rms90 w/o errors","plf");
   //lsc1->AddEntry(bgr,"data, rms90 w/o errors","plf");
   //lsc1->AddEntry(dgr,"data, rms100 w/o errors","plf");
   //lsc1->AddEntry(fgr,"data, rms_hist (stat)","plf");
   //lsc1->AddEntry(bgr,"data, fit 2 (stat)","plf");
   //lsc1->AddEntry(dgr,"data, rms_hist (stat)","plf");
   //lsc1->AddEntry(fgr,"data, rms90 w/o errors","plf");
   //lsc1->AddEntry(bgr,"data, fit 1","plf");
   //lsc1->AddEntry(dgr,"data, fit 2 (stat)","plf");
   //lsc1->AddEntry(fgr,"data, rms_hist (stat)","plf");
    
   TLegend *lsc2 = new TLegend(0.55,0.62,0.90,0.92);
   lsc2->AddEntry(bgr,"fit (stat)","pl");
   lsc2->AddEntry(dgr,"hist90_2 (stat)","pl");
   lsc2->AddEntry(fgr,"hist95_2 (stat)","pl");
   lsc2->AddEntry(hgr,"hist (stat)","pl");
    
   TLegend *lsc3 = new TLegend(0.55,0.62,0.90,0.92);
   lsc3->AddEntry(bgr,"fit (stat)","pl");
   lsc3->AddEntry(dgr,"hist90_2 (stat)","pl");
   lsc3->AddEntry(fgr,"hist95_2 (stat)","pl");
   lsc3->AddEntry(hgr,"hist (stat)","pl");
    
   TLegend *lsc4 = new TLegend(0.55,0.62,0.90,0.92);
   lsc4->AddEntry(bgr,"fit (stat)","pl");
   lsc4->AddEntry(dgr,"hist90_2 (stat)","pl");
   lsc4->AddEntry(fgr,"hist95_2 (stat)","pl");
   lsc4->AddEntry(hgr,"hist (stat)","pl");

   c1->cd();
   lsc1->Draw();
   c2->cd();
   lsc2->Draw();
   c3->cd();
   lsc3->Draw();
   c4->cd();
   lsc4->Draw();

}
