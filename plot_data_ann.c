void plot_data_ann() {
   TCanvas *c1 = new TCanvas("graph1","graph1",200,10,700,500);
   TCanvas *c2 = new TCanvas("graph2","graph2",200,10,700,500);
   TCanvas *c3 = new TCanvas("graph3","graph3",200,10,700,500);
   TCanvas *c4 = new TCanvas("graph4","graph4",200,10,700,500);

   c1->SetGrid();
   c2->SetGrid();
   c3->SetGrid();
   c4->SetGrid();

   const Int_t n = 19; // 9

   Float_t energy[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t energyerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
// for data
   Float_t mean[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t meanerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rmserror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t mean_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t meanerror_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rmserror_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t mean_mean[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//   Float_t rms_mean[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean_meanerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//   Float_t rms_meanerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean_sigma[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//   Float_t rms_sigma[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean_sigmaerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//   Float_t rms_sigmaerror[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//   Float_t mean_chi[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//   Float_t rms_chi[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t ratio_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_hist[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t ratio_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_hist90[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t linearity_error[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t absolute_error[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// for ann
   Float_t mean2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t meanerror2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rmserror2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t mean_hist902[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t meanerror_hist902[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rms_hist902[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t rmserror_hist902[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t mean_mean2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//   Float_t rms_mean2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean_meanerror2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//   Float_t rms_meanerror2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean_sigma2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//   Float_t rms_sigma2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t mean_sigmaerror2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//   Float_t rms_sigmaerror2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//   Float_t mean_chi2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//   Float_t rms_chi2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t ratio_hist2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat_hist2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys_hist2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_hist2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_hist2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat_hist2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys_hist2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_hist2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t ratio_hist902[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat_hist902[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys_hist902[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_hist902[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_hist902[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat_hist902[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys_hist902[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_hist902[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   
   Float_t linearity_error2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t absolute_error2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_stat2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error_sys2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t ratio_error2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_stat2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error_sys2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t resolution_error2[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// for data
   FILE *file1 = fopen("out_data.txt", "r");
   if ( !(long)file1 ) return;

// for ann
   FILE *file2 = fopen("out_ann.txt", "r");
   if ( !(long)file2 ) return;

// for data
  for ( int i = 0; i < n; i++ ) {
    fscanf( file1, "%f %E %E %E %E %E %E %E %E %E %E %E %E\n", &energy[i], &mean_hist90[i], &meanerror_hist90[i], &rms_hist90[i], &rmserror_hist90[i], &mean[i], &meanerror[i], &rms[i], &rmserror[i], &mean_mean[i], &mean_meanerror[i], &mean_sigma[i], &mean_sigmaerror[i] );
    if ( feof( file1 ) ) break;
  }

// for ann
  for ( int i = 0; i < n; i++ ) {
    fscanf( file2, "%f %E %E %E %E %E %E %E %E %E %E %E %E\n", &energy[i], &mean_hist902[i], &meanerror_hist902[i], &rms_hist902[i], &rmserror_hist902[i], &mean2[i], &meanerror2[i], &rms2[i], &rmserror2[i], &mean_mean2[i], &mean_meanerror2[i], &mean_sigma2[i], &mean_sigmaerror2[i] );
    if ( feof( file2 ) ) break;
  }
 
  for ( int i = 0; i < n; i++ ) {

// for data
    ratio_hist[ i ] = ( mean[i] - energy[i] ) / energy[i];
    ratio_error_stat_hist[ i ] = sqrt( pow( (meanerror[i]) / (energy[i]), 2 ) + pow( (mean[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys_hist[ i ] = 0.0;
    ratio_error_hist[ i ] = sqrt( ( pow( ratio_error_stat_hist[ i ], 2 ) ) + ( pow( ratio_error_sys_hist[ i ], 2 ) ) );
      
    ratio_hist90[ i ] = ( mean_hist90[i] - energy[i] ) / energy[i];
    ratio_error_stat_hist90[ i ] = sqrt( pow( (meanerror_hist90[i]) / (energy[i]), 2 ) + pow( (mean_hist90[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys_hist90[ i ] = 0.0;
    ratio_error_hist90[ i ] = sqrt( ( pow( ratio_error_stat_hist90[ i ], 2 ) ) + ( pow( ratio_error_sys_hist90[ i ], 2 ) ) );

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

    resolution[ i ] = mean_sigma[i] / mean_mean[i];
    resolution_error_stat[ i ] = sqrt( pow( (mean_sigmaerror[i]) / (mean_mean[i]), 2 ) + pow( (mean_sigma[i] * mean_meanerror[i]) / (mean_mean[i] * mean_mean[i]), 2 ) );
    resolution_error_sys[ i ] = 0.0;
    resolution_error[ i ] = sqrt( ( pow( resolution_error_stat[ i ], 2 ) ) + ( pow( resolution_error_sys[ i ], 2 ) ) );

// for ann
    ratio_hist2[ i ] = ( mean2[i] - energy[i] ) / energy[i];
    ratio_error_stat_hist2[ i ] = sqrt( pow( (meanerror2[i]) / (energy[i]), 2 ) + pow( (mean2[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys_hist2[ i ] = 0.0;
    ratio_error_hist2[ i ] = sqrt( ( pow( ratio_error_stat_hist2[ i ], 2 ) ) + ( pow( ratio_error_sys_hist2[ i ], 2 ) ) );
      
    ratio_hist902[ i ] = ( mean_hist902[i] - energy[i] ) / energy[i];
    ratio_error_stat_hist902[ i ] = sqrt( pow( (meanerror_hist902[i]) / (energy[i]), 2 ) + pow( (mean_hist902[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys_hist902[ i ] = 0.0;
    ratio_error_hist902[ i ] = sqrt( ( pow( ratio_error_stat_hist902[ i ], 2 ) ) + ( pow( ratio_error_sys_hist902[ i ], 2 ) ) );

    ratio2[ i ] = ( mean_mean2[i] - energy[i] ) / energy[i];
    ratio_error_stat2[ i ] = sqrt( pow( (mean_meanerror2[i]) / (energy[i]), 2 ) + pow( (mean_mean2[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys2[ i ] = 0.0;
    ratio_error2[ i ] = sqrt( ( pow( ratio_error_stat2[ i ], 2 ) ) + ( pow( ratio_error_sys2[ i ], 2 ) ) );
    
    resolution_hist2[ i ] = rms2[i] / mean2[i];
    resolution_error_stat_hist2[ i ] = sqrt( pow( (rmserror2[i]) / (mean2[i]), 2 ) + pow( (rms2[i] * meanerror2[i]) / (mean2[i] * mean2[i]), 2 ) );
    resolution_error_sys_hist2[ i ] = 0.0;
    resolution_error_hist2[ i ] = sqrt( ( pow( resolution_error_stat_hist2[ i ], 2 ) ) + ( pow( resolution_error_sys_hist2[ i ], 2 ) ) );
    
    resolution_hist902[ i ] = rms_hist902[i] / mean_hist902[i];
    resolution_error_stat_hist902[ i ] = sqrt( pow( (rmserror_hist902[i]) / (mean_hist902[i]), 2 ) + pow( (rms_hist902[i] * meanerror_hist902[i]) / (mean_hist902[i] * mean_hist902[i]), 2 ) );
    resolution_error_sys_hist902[ i ] = 0.0;
    resolution_error_hist902[ i ] = sqrt( ( pow( resolution_error_stat_hist902[ i ], 2 ) ) + ( pow( resolution_error_sys_hist902[ i ], 2 ) ) );

    resolution2[ i ] = mean_sigma2[i] / mean_mean2[i];
    resolution_error_stat2[ i ] = sqrt( pow( (mean_sigmaerror2[i]) / (mean_mean2[i]), 2 ) + pow( (mean_sigma2[i] * mean_meanerror2[i]) / (mean_mean2[i] * mean_mean2[i]), 2 ) );
    resolution_error_sys2[ i ] = 0.0;
    resolution_error2[ i ] = sqrt( ( pow( resolution_error_stat2[ i ], 2 ) ) + ( pow( resolution_error_sys2[ i ], 2 ) ) );
    
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
     
// for data
     printf( " %f ", mean[i] );
     printf( " %f ", meanerror[i] );
     printf( " %f ", rms[i] );
     printf( " %f ", rmserror[i] );
       
     printf( " %f ", mean_hist90[i] );
     printf( " %f ", meanerror_hist90[i] );
     printf( " %f ", rms_hist90[i] );
     printf( " %f ", rmserror_hist90[i] );
             
     printf( " %f ", ratio_hist[i] );
     printf( " %f ", ratio_error_hist[i] );
     printf( " %f ", resolution_hist[i] );
     printf( " %f ", resolution_error_hist[i] );
    
     printf( " %f ", ratio_hist90[i] );
     printf( " %f ", ratio_error_hist90[i] );
     printf( " %f ", resolution_hist90[i] );
     printf( " %f ", resolution_error_hist90[i] );
       
     printf( " %f ", mean_mean[i] );
     printf( " %f ", mean_meanerror[i] );
     printf( " %f ", mean_sigma[i] );
     printf( " %f ", mean_sigmaerror[i] );
     printf( " %f ", ratio[i] );
     printf( " %f ", ratio_error[i] );
     printf( " %f ", resolution[i] );
     printf( " %f ", resolution_error[i] );
     
     printf( "\n" );
     printf( "\n" );
     printf( "\n" );

// for data
     printf( " %f ", mean2[i] );
     printf( " %f ", meanerror2[i] );
     printf( " %f ", rms2[i] );
     printf( " %f ", rmserror2[i] );
       
     printf( " %f ", mean_hist902[i] );
     printf( " %f ", meanerror_hist902[i] );
     printf( " %f ", rms_hist902[i] );
     printf( " %f ", rmserror_hist902[i] );
             
     printf( " %f ", ratio_hist2[i] );
     printf( " %f ", ratio_error_hist2[i] );
     printf( " %f ", resolution_hist2[i] );
     printf( " %f ", resolution_error_hist2[i] );
    
     printf( " %f ", ratio_hist902[i] );
     printf( " %f ", ratio_error_hist902[i] );
     printf( " %f ", resolution_hist902[i] );
     printf( " %f ", resolution_error_hist902[i] );
       
     printf( " %f ", mean_mean2[i] );
     printf( " %f ", mean_meanerror2[i] );
     printf( " %f ", mean_sigma2[i] );
     printf( " %f ", mean_sigmaerror2[i] );
     printf( " %f ", ratio2[i] );
     printf( " %f ", ratio_error2[i] );
     printf( " %f ", resolution2[i] );
     printf( " %f ", resolution_error2[i] );
     
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
   agr = new TGraphErrors( n, energy, ratio_hist90, energyerror, ratio_error_sys_hist90 );
   agr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, ratio_hist90, energyerror, ratio_error_stat_hist90 );
   bgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, ratio_hist902, energyerror, ratio_error_sys_hist902 );
   cgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, ratio_hist902, energyerror, ratio_error_stat_hist902 );
   dgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Linearity" );
   agr->GetYaxis()->SetRangeUser(-0.4, 0.3);
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
   agr = new TGraphErrors( n, energy, rms_hist90, energyerror, energyerror );
   agr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, rms_hist90, energyerror, rmserror_hist90 );
   bgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, rms_hist902, energyerror, energyerror );
   cgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, rms_hist902, energyerror, rmserror_hist902 );
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
   agr = new TGraphErrors( n, energy, mean_hist90, energyerror, energyerror );
   agr->GetYaxis()->SetTitle("E_{reco}, GeV");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, mean_hist90, energyerror, meanerror_hist90 );
   bgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, mean_hist902, energyerror, energyerror );
   cgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, mean_hist902, energyerror, meanerror_hist902 );
   dgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Linearity 2" );
   agr->GetYaxis()->SetRangeUser(0.0, 130.0);
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
   agr = new TGraphErrors( n, energy, resolution_hist90, energyerror, resolution_error_sys_hist90 );
   agr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, resolution_hist90, energyerror, resolution_error_stat_hist90 );
   bgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, resolution_hist902, energyerror, resolution_error_sys_hist902 );
   cgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, resolution_hist902, energyerror, resolution_error_stat_hist902 );
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
   
   TLegend *lsc1 = new TLegend(0.55,0.62,0.90,0.92);
   lsc1->AddEntry(bgr,"mc, hist90 (stat)","pl");
   lsc1->AddEntry(dgr,"ann, hist90 (stat)","pl");
   
   TLegend *lsc2 = new TLegend(0.55,0.62,0.90,0.92);
   lsc2->AddEntry(bgr,"mc, hist90 (stat)","pl");
   lsc2->AddEntry(dgr,"ann, hist90 (stat)","pl");
   
   TLegend *lsc3 = new TLegend(0.55,0.62,0.90,0.92);
   lsc3->AddEntry(bgr,"mc, hist90 (stat)","pl");
   lsc3->AddEntry(dgr,"ann, hist90 (stat)","pl");
   
   TLegend *lsc4 = new TLegend(0.55,0.62,0.90,0.92);
   lsc4->AddEntry(bgr,"mc, hist90 (stat)","pl");
   lsc4->AddEntry(dgr,"ann, hist90 (stat)","pl");

   c1->cd();
   lsc1->Draw();
   c2->cd();
   lsc2->Draw();
   c3->cd();
   lsc3->Draw();
   c4->cd();
   lsc4->Draw();

}
