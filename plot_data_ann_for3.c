void plot_data_ann_for3() {
   TCanvas *c1 = new TCanvas("graph1","graph1",200,10,700,500);
   TCanvas *c2 = new TCanvas("graph2","graph2",200,10,700,500);
   TCanvas *c3 = new TCanvas("graph3","graph3",200,10,700,500);
   TCanvas *c4 = new TCanvas("graph4","graph4",200,10,700,500);

//   TCanvas *c5 = new TCanvas("graph5","graph5",200,10,700,500);
//   TCanvas *c6 = new TCanvas("graph6","graph6",200,10,700,500);

/*   TCanvas *c7 = new TCanvas("graph7","graph7",200,10,700,500);
   TCanvas *c8 = new TCanvas("graph8","graph8",200,10,700,500);
   TCanvas *c9 = new TCanvas("graph9","graph9",200,10,700,500);
   TCanvas *c10 = new TCanvas("graph10","graph10",200,10,700,500);
   TCanvas *c11 = new TCanvas("graph11","graph11",200,10,700,500);
   TCanvas *c12 = new TCanvas("graph12","graph12",200,10,700,500);
*/
   c1->SetGrid();
   c2->SetGrid();
   c3->SetGrid();
   c4->SetGrid();

//   c5->SetGrid();
//   c6->SetGrid();

//   c7->SetGrid();
//   c8->SetGrid();

   c1->SetTickx(1);
   c1->SetTicky(1);
   c2->SetTickx(1);
   c2->SetTicky(1);
   c3->SetTickx(1);
   c3->SetTicky(1);
   c4->SetTickx(1);
   c4->SetTicky(1);

//   c5->SetTickx(1);
//   c5->SetTicky(1);
//   c6->SetTickx(1);
//   c6->SetTicky(1);

   const Int_t n = 29; // 9

   Float_t energy[ n ];
   Float_t energyerror[ n ];
   
// for data
   Float_t mean[ n ];
   Float_t meanerror[ n ];
   Float_t rms[ n ];
   Float_t rmserror[ n ];
   
   Float_t mean_hist90[ n ];
   Float_t meanerror_hist90[ n ];
   Float_t rms_hist90[ n ];
   Float_t rmserror_hist90[ n ];

   Float_t mean_mean[ n ];
//   Float_t rms_mean[ n ];
   Float_t mean_meanerror[ n ];
//   Float_t rms_meanerror[ n ];
   Float_t mean_sigma[ n ];
//   Float_t rms_sigma[ n ];
   Float_t mean_sigmaerror[ n ];
//   Float_t rms_sigmaerror[ n ];
//   Float_t mean_chi[ n ];
//   Float_t rms_chi[ n ];

   Float_t ratio_hist[ n ];
   Float_t ratio_error_stat_hist[ n ];
   Float_t ratio_error_sys_hist[ n ];
   Float_t ratio_error_hist[ n ];
   Float_t resolution_hist[ n ];
   Float_t resolution_error_stat_hist[ n ];
   Float_t resolution_error_sys_hist[ n ];
   Float_t resolution_error_hist[ n ];

   Float_t ratio_hist90[ n ];
   Float_t ratio_error_stat_hist90[ n ];
   Float_t ratio_error_sys_hist90[ n ];
   Float_t ratio_error_hist90[ n ];
   Float_t resolution_hist90[ n ];
   Float_t resolution_error_stat_hist90[ n ];
   Float_t resolution_error_sys_hist90[ n ];
   Float_t resolution_error_hist90[ n ];

   Float_t ratio[ n ];
   Float_t ratio_error_stat[ n ];
   Float_t ratio_error_sys[ n ];
   Float_t ratio_error[ n ];
   Float_t resolution[ n ];
   Float_t resolution_error_stat[ n ];
   Float_t resolution_error_sys[ n ];
   Float_t resolution_error[ n ];

// for ann
   Float_t mean2[ n ];
   Float_t meanerror2[ n ];
   Float_t rms2[ n ];
   Float_t rmserror2[ n ];

   Float_t mean_hist902[ n ];
   Float_t meanerror_hist902[ n ];
   Float_t rms_hist902[ n ];
   Float_t rmserror_hist902[ n ];

   Float_t mean_mean2[ n ];
//   Float_t rms_mean2[ n ];
   Float_t mean_meanerror2[ n ];
//   Float_t rms_meanerror2[ n ];
   Float_t mean_sigma2[ n ];
//   Float_t rms_sigma2[ n ];
   Float_t mean_sigmaerror2[ n ];
//   Float_t rms_sigmaerror2[ n ];
//   Float_t mean_chi2[ n ];
//   Float_t rms_chi2[ n ];

   Float_t ratio_hist2[ n ];
   Float_t ratio_error_stat_hist2[ n ];
   Float_t ratio_error_sys_hist2[ n ];
   Float_t ratio_error_hist2[ n ];
   Float_t resolution_hist2[ n ];
   Float_t resolution_error_stat_hist2[ n ];
   Float_t resolution_error_sys_hist2[ n ];
   Float_t resolution_error_hist2[ n ];

   Float_t ratio_hist902[ n ];
   Float_t ratio_error_stat_hist902[ n ];
   Float_t ratio_error_sys_hist902[ n ];
   Float_t ratio_error_hist902[ n ];
   Float_t resolution_hist902[ n ];
   Float_t resolution_error_stat_hist902[ n ];
   Float_t resolution_error_sys_hist902[ n ];
   Float_t resolution_error_hist902[ n ];

   Float_t ratio2[ n ];
   Float_t ratio_error_stat2[ n ];
   Float_t ratio_error_sys2[ n ];
   Float_t ratio_error2[ n ];
   Float_t resolution2[ n ];
   Float_t resolution_error_stat2[ n ];
   Float_t resolution_error_sys2[ n ];
   Float_t resolution_error2[ n ];
    
//   Float_t lin1_sys[ n ];
//   Float_t lin2_sys[ n ];
//   Float_t abs_sys[ n ];
//   Float_t rel_sys[ n ];

// for difference
/*   Float_t ratio_abs_hist[ n ];
   Float_t ratio_abs_error_stat_hist[ n ];
   Float_t ratio_abs_error_sys_hist[ n ];
   Float_t ratio_abs_error_hist[ n ];

   Float_t ratio_abs_hist90[ n ];
   Float_t ratio_abs_error_stat_hist90[ n ];
   Float_t ratio_abs_error_sys_hist90[ n ];
   Float_t ratio_abs_error_hist90[ n ];

   Float_t ratio_abs[ n ];
   Float_t ratio_abs_error_stat[ n ];
   Float_t ratio_abs_error_sys[ n ];
   Float_t ratio_abs_error[ n ];

   Float_t ratio_abs_other_hist[ n ];
   Float_t ratio_abs_other_error_stat_hist[ n ];
   Float_t ratio_abs_other_error_sys_hist[ n ];
   Float_t ratio_abs_other_error_hist[ n ];

   Float_t ratio_abs_other_hist90[ n ];
   Float_t ratio_abs_other_error_stat_hist90[ n ];
   Float_t ratio_abs_other_error_sys_hist90[ n ];
   Float_t ratio_abs_other_error_hist90[ n ];

   Float_t ratio_abs_other[ n ];
   Float_t ratio_abs_other_error_stat[ n ];
   Float_t ratio_abs_other_error_sys[ n ];
   Float_t ratio_abs_other_error[ n ];
*/
// for third
   Float_t mean3[ n ];
   Float_t meanerror3[ n ];
   Float_t rms3[ n ];
   Float_t rmserror3[ n ];

   Float_t mean_hist903[ n ];
   Float_t meanerror_hist903[ n ];
   Float_t rms_hist903[ n ];
   Float_t rmserror_hist903[ n ];

   Float_t mean_mean3[ n ];
//   Float_t rms_mean3[ n ];
   Float_t mean_meanerror3[ n ];
//   Float_t rms_meanerror3[ n ];
   Float_t mean_sigma3[ n ];
//   Float_t rms_sigma3[ n ];
   Float_t mean_sigmaerror3[ n ];
//   Float_t rms_sigmaerror3[ n ];
//   Float_t mean_chi3[ n ];
//   Float_t rms_chi3[ n ];

   Float_t ratio_hist3[ n ];
   Float_t ratio_error_stat_hist3[ n ];
   Float_t ratio_error_sys_hist3[ n ];
   Float_t ratio_error_hist3[ n ];
   Float_t resolution_hist3[ n ];
   Float_t resolution_error_stat_hist3[ n ];
   Float_t resolution_error_sys_hist3[ n ];
   Float_t resolution_error_hist3[ n ];

   Float_t ratio_hist903[ n ];
   Float_t ratio_error_stat_hist903[ n ];
   Float_t ratio_error_sys_hist903[ n ];
   Float_t ratio_error_hist903[ n ];
   Float_t resolution_hist903[ n ];
   Float_t resolution_error_stat_hist903[ n ];
   Float_t resolution_error_sys_hist903[ n ];
   Float_t resolution_error_hist903[ n ];

   Float_t ratio3[ n ];
   Float_t ratio_error_stat3[ n ];
   Float_t ratio_error_sys3[ n ];
   Float_t ratio_error3[ n ];
   Float_t resolution3[ n ];
   Float_t resolution_error_stat3[ n ];
   Float_t resolution_error_sys3[ n ];
   Float_t resolution_error3[ n ];

   for( int i = 0; i < n; i++ ) {

   energy[ i ] = 0.0;
   energyerror[ i ] = 0.0;
   
// for data
   mean[ i ] = 0.0;
   meanerror[ i ] = 0.0;
   rms[ i ] = 0.0;
   rmserror[ i ] = 0.0;
   
   mean_hist90[ i ] = 0.0;
   meanerror_hist90[ i ] = 0.0;
   rms_hist90[ i ] = 0.0;
   rmserror_hist90[ i ] = 0.0;
   
   mean_mean[ i ] = 0.0;
//   rms_mean[ i ] = 0.0;
   mean_meanerror[ i ] = 0.0;
//   rms_meanerror[ i ] = 0.0;
   mean_sigma[ i ] = 0.0;
//   rms_sigma[ i ] = 0.0;
   mean_sigmaerror[ i ] = 0.0;
//   rms_sigmaerror[ i ] = 0.0;
//   mean_chi[ i ] = 0.0;
//   rms_chi[ i ] = 0.0;
   
   ratio_hist[ i ] = 0.0;
   ratio_error_stat_hist[ i ] = 0.0;
   ratio_error_sys_hist[ i ] = 0.0;
   ratio_error_hist[ i ] = 0.0;
   resolution_hist[ i ] = 0.0;
   resolution_error_stat_hist[ i ] = 0.0;
   resolution_error_sys_hist[ i ] = 0.0;
   resolution_error_hist[ i ] = 0.0;
   
   ratio_hist90[ i ] = 0.0;
   ratio_error_stat_hist90[ i ] = 0.0;
   ratio_error_sys_hist90[ i ] = 0.0;
   ratio_error_hist90[ i ] = 0.0;
   resolution_hist90[ i ] = 0.0;
   resolution_error_stat_hist90[ i ] = 0.0;
   resolution_error_sys_hist90[ i ] = 0.0;
   resolution_error_hist90[ i ] = 0.0;
   
   ratio[ i ] = 0.0;
   ratio_error_stat[ i ] = 0.0;
   ratio_error_sys[ i ] = 0.0;
   ratio_error[ i ] = 0.0;
   resolution[ i ] = 0.0;
   resolution_error_stat[ i ] = 0.0;
   resolution_error_sys[ i ] = 0.0;
   resolution_error[ i ] = 0.0;

// for ann
   mean2[ i ] = 0.0;
   meanerror2[ i ] = 0.0;
   rms2[ i ] = 0.0;
   rmserror2[ i ] = 0.0;
   
   mean_hist902[ i ] = 0.0;
   meanerror_hist902[ i ] = 0.0;
   rms_hist902[ i ] = 0.0;
   rmserror_hist902[ i ] = 0.0;
   
   mean_mean2[ i ] = 0.0;
//   rms_mean2[ i ] = 0.0;
   mean_meanerror2[ i ] = 0.0;
//   rms_meanerror2[ i ] = 0.0;
   mean_sigma2[ i ] = 0.0;
//   rms_sigma2[ i ] = 0.0;
   mean_sigmaerror2[ i ] = 0.0;
//   rms_sigmaerror2[ i ] = 0.0;
//   mean_chi2[ i ] = 0.0;
//   rms_chi2[ i ] = 0.0;
   
   ratio_hist2[ i ] = 0.0;
   ratio_error_stat_hist2[ i ] = 0.0;
   ratio_error_sys_hist2[ i ] = 0.0;
   ratio_error_hist2[ i ] = 0.0;
   resolution_hist2[ i ] = 0.0;
   resolution_error_stat_hist2[ i ] = 0.0;
   resolution_error_sys_hist2[ i ] = 0.0;
   resolution_error_hist2[ i ] = 0.0;
   
   ratio_hist902[ i ] = 0.0;
   ratio_error_stat_hist902[ i ] = 0.0;
   ratio_error_sys_hist902[ i ] = 0.0;
   ratio_error_hist902[ i ] = 0.0;
   resolution_hist902[ i ] = 0.0;
   resolution_error_stat_hist902[ i ] = 0.0;
   resolution_error_sys_hist902[ i ] = 0.0;
   resolution_error_hist902[ i ] = 0.0;
   
   ratio2[ i ] = 0.0;
   ratio_error_stat2[ i ] = 0.0;
   ratio_error_sys2[ i ] = 0.0;
   ratio_error2[ i ] = 0.0;
   resolution2[ i ] = 0.0;
   resolution_error_stat2[ i ] = 0.0;
   resolution_error_sys2[ i ] = 0.0;
   resolution_error2[ i ] = 0.0;
       
//   lin1_sys[ i ] = 0.0;
//   lin2_sys[ i ] = 0.0;
//   abs_sys[ i ] = 0.0;
//   rel_sys[ i ] = 0.0;

// for difference
/*   ratio_abs_hist[ i ] = 0.0;
   ratio_abs_error_stat_hist[ i ] = 0.0;
   ratio_abs_error_sys_hist[ i ] = 0.0;
   ratio_abs_error_hist[ i ] = 0.0;

   ratio_abs_hist90[ i ] = 0.0;
   ratio_abs_error_stat_hist90[ i ] = 0.0;
   ratio_abs_error_sys_hist90[ i ] = 0.0;
   ratio_abs_error_hist90[ i ] = 0.0;

   ratio_abs[ i ] = 0.0;
   ratio_abs_error_stat[ i ] = 0.0;
   ratio_abs_error_sys[ i ] = 0.0;
   ratio_abs_error[ i ] = 0.0;

   ratio_abs_other_hist[ i ] = 0.0;
   ratio_abs_other_error_stat_hist[ i ] = 0.0;
   ratio_abs_other_error_sys_hist[ i ] = 0.0;
   ratio_abs_other_error_hist[ i ] = 0.0;

   ratio_abs_other_hist90[ i ] = 0.0;
   ratio_abs_other_error_stat_hist90[ i ] = 0.0;
   ratio_abs_other_error_sys_hist90[ i ] = 0.0;
   ratio_abs_other_error_hist90[ i ] = 0.0;

   ratio_abs_other[ i ] = 0.0;
   ratio_abs_other_error_stat[ i ] = 0.0;
   ratio_abs_other_error_sys[ i ] = 0.0;
   ratiso_abs_other_error[ i ] = 0.0;
*/
// for third
   mean3[ i ] = 0.0;
   meanerror3[ i ] = 0.0;
   rms3[ i ] = 0.0;
   rmserror3[ i ] = 0.0;
   
   mean_hist903[ i ] = 0.0;
   meanerror_hist903[ i ] = 0.0;
   rms_hist903[ i ] = 0.0;
   rmserror_hist903[ i ] = 0.0;
   
   mean_mean3[ i ] = 0.0;
//   rms_mean3[ i ] = 0.0;
   mean_meanerror3[ i ] = 0.0;
//   rms_meanerror3[ i ] = 0.0;
   mean_sigma3[ i ] = 0.0;
//   rms_sigma3[ i ] = 0.0;
   mean_sigmaerror3[ i ] = 0.0;
//   rms_sigmaerror3[ i ] = 0.0;
//   mean_chi3[ i ] = 0.0;
//   rms_chi3[ i ] = 0.0;
   
   ratio_hist3[ i ] = 0.0;
   ratio_error_stat_hist3[ i ] = 0.0;
   ratio_error_sys_hist3[ i ] = 0.0;
   ratio_error_hist3[ i ] = 0.0;
   resolution_hist3[ i ] = 0.0;
   resolution_error_stat_hist3[ i ] = 0.0;
   resolution_error_sys_hist3[ i ] = 0.0;
   resolution_error_hist3[ i ] = 0.0;
   
   ratio_hist903[ i ] = 0.0;
   ratio_error_stat_hist903[ i ] = 0.0;
   ratio_error_sys_hist903[ i ] = 0.0;
   ratio_error_hist903[ i ] = 0.0;
   resolution_hist903[ i ] = 0.0;
   resolution_error_stat_hist903[ i ] = 0.0;
   resolution_error_sys_hist903[ i ] = 0.0;
   resolution_error_hist903[ i ] = 0.0;
   
   ratio3[ i ] = 0.0;
   ratio_error_stat3[ i ] = 0.0;
   ratio_error_sys3[ i ] = 0.0;
   ratio_error3[ i ] = 0.0;
   resolution3[ i ] = 0.0;
   resolution_error_stat3[ i ] = 0.0;
   resolution_error_sys3[ i ] = 0.0;
   resolution_error3[ i ] = 0.0;

   }

// for data
   FILE *file1 = fopen("out_data.txt", "r");
   if ( !(long)file1 ) return;

// for ann
   FILE *file2 = fopen("out_ann.txt", "r");
   if ( !(long)file2 ) return;
    
// for third
   FILE *file3 = fopen("out_ann_test.txt", "r");
   if ( !(long)file3 ) return;
    
// for systematic
//   FILE *file4 = fopen("systematic.txt", "r");
//   if ( !(long)file4 ) return;

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
    
// for third
  for ( int i = 0; i < n; i++ ) {
    fscanf( file3, "%f %E %E %E %E %E %E %E %E %E %E %E %E\n", &energy[i], &mean_hist903[i], &meanerror_hist903[i], &rms_hist903[i], &rmserror_hist903[i], &mean3[i], &meanerror3[i], &rms3[i], &rmserror3[i], &mean_mean3[i], &mean_meanerror3[i], &mean_sigma3[i], &mean_sigmaerror3[i] );
    if ( feof( file3 ) ) break;
  }
    
// for systematic
//  for ( int i = 0; i < n; i++ ) {
//    fscanf( file4, "%f %E %E %E %E\n", &energy[i], &lin1_sys[i], &lin2_sys[i], &abs_sys[i], &rel_sys[i] );
//    if ( feof( file4 ) ) break;
//  }
 
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

// for difference
/*    ratio_abs_hist[ i ] = ( rms2[i] - rms[i] ) / rms[i];
    ratio_abs_error_stat_hist[ i ] = sqrt( pow( (rmserror2[i]) / (rms[i]), 2 ) + pow( (rms2[i] * rmserror[i]) / (rms[i] * rms[i]), 2 ) );
    ratio_abs_error_sys_hist[ i ] = 0.0;
    ratio_abs_error_hist[ i ] = sqrt( ( pow( ratio_abs_error_stat_hist[ i ], 2 ) ) + ( pow( ratio_abs_error_sys_hist[ i ], 2 ) ) );
      
    ratio_abs_hist90[ i ] = ( rms_hist902[i] - rms_hist90[i] ) / rms_hist90[i];
    ratio_abs_error_stat_hist90[ i ] = sqrt( pow( (rmserror_hist902[i]) / (rms_hist90[i]), 2 ) + pow( (rms_hist902[i] * rmserror_hist90[i]) / (rms_hist90[i] * rms_hist90[i]), 2 ) );
    ratio_abs_error_sys_hist90[ i ] = 0.0;
    ratio_abs_error_hist90[ i ] = sqrt( ( pow( ratio_abs_error_stat_hist90[ i ], 2 ) ) + ( pow( ratio_abs_error_sys_hist90[ i ], 2 ) ) );

    ratio_abs[ i ] = ( mean_sigma2[i] - mean_sigma[i] ) / mean_sigma[i];
    ratio_abs_error_stat[ i ] = sqrt( pow( (mean_sigmaerror2[i]) / (mean_sigma[i]), 2 ) + pow( (mean_sigma2[i] * mean_sigmaerror[i]) / (mean_sigma[i] * mean_sigma[i]), 2 ) );
    ratio_abs_error_sys[ i ] = 0.0;
    ratio_abs_error[ i ] = sqrt( ( pow( ratio_abs_error_stat[ i ], 2 ) ) + ( pow( ratio_abs_error_sys[ i ], 2 ) ) );

    ratio_abs_other_hist[ i ] = rms2[i] / rms[i];
    ratio_abs_other_error_stat_hist[ i ] = sqrt( pow( (rmserror2[i]) / (rms[i]), 2 ) + pow( (rms2[i] * rmserror[i]) / (rms[i] * rms[i]), 2 ) );
    ratio_abs_other_error_sys_hist[ i ] = 0.0;
    ratio_abs_other_error_hist[ i ] = sqrt( ( pow( ratio_abs_other_error_stat_hist[ i ], 2 ) ) + ( pow( ratio_abs_other_error_sys_hist[ i ], 2 ) ) );
      
    ratio_abs_other_hist90[ i ] = rms_hist902[i] / rms_hist90[i];
    ratio_abs_other_error_stat_hist90[ i ] = sqrt( pow( (rmserror_hist902[i]) / (rms_hist90[i]), 2 ) + pow( (rms_hist902[i] * rmserror_hist90[i]) / (rms_hist90[i] * rms_hist90[i]), 2 ) );
    ratio_abs_other_error_sys_hist90[ i ] = 0.0;
    ratio_abs_other_error_hist90[ i ] = sqrt( ( pow( ratio_abs_other_error_stat_hist90[ i ], 2 ) ) + ( pow( ratio_abs_other_error_sys_hist90[ i ], 2 ) ) );

    ratio_abs_other[ i ] = mean_sigma2[i] / mean_sigma[i];
    ratio_abs_other_error_stat[ i ] = sqrt( pow( (mean_sigmaerror2[i]) / (mean_sigma[i]), 2 ) + pow( (mean_sigma2[i] * mean_sigmaerror[i]) / (mean_sigma[i] * mean_sigma[i]), 2 ) );
    ratio_abs_other_error_sys[ i ] = 0.0;
    ratio_abs_other_error[ i ] = sqrt( ( pow( ratio_abs_other_error_stat[ i ], 2 ) ) + ( pow( ratio_abs_other_error_sys[ i ], 2 ) ) );
*/
// for third
    ratio_hist3[ i ] = ( mean3[i] - energy[i] ) / energy[i];
    ratio_error_stat_hist3[ i ] = sqrt( pow( (meanerror3[i]) / (energy[i]), 2 ) + pow( (mean3[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys_hist3[ i ] = 0.0;
    ratio_error_hist3[ i ] = sqrt( ( pow( ratio_error_stat_hist3[ i ], 2 ) ) + ( pow( ratio_error_sys_hist3[ i ], 2 ) ) );
            
    ratio_hist903[ i ] = ( mean_hist903[i] - energy[i] ) / energy[i];
    ratio_error_stat_hist903[ i ] = sqrt( pow( (meanerror_hist903[i]) / (energy[i]), 2 ) + pow( (mean_hist903[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys_hist903[ i ] = 0.0;
    ratio_error_hist903[ i ] = sqrt( ( pow( ratio_error_stat_hist903[ i ], 2 ) ) + ( pow( ratio_error_sys_hist903[ i ], 2 ) ) );

    ratio3[ i ] = ( mean_mean3[i] - energy[i] ) / energy[i];
    ratio_error_stat3[ i ] = sqrt( pow( (mean_meanerror3[i]) / (energy[i]), 2 ) + pow( (mean_mean3[i] * energyerror[i]) / (energy[i] * energy[i]), 2 ) );
    ratio_error_sys3[ i ] = 0.0;
    ratio_error3[ i ] = sqrt( ( pow( ratio_error_stat3[ i ], 2 ) ) + ( pow( ratio_error_sys3[ i ], 2 ) ) );
          
    resolution_hist3[ i ] = rms3[i] / mean3[i];
    resolution_error_stat_hist3[ i ] = sqrt( pow( (rmserror3[i]) / (mean3[i]), 2 ) + pow( (rms3[i] * meanerror3[i]) / (mean3[i] * mean3[i]), 2 ) );
    resolution_error_sys_hist3[ i ] = 0.0;
    resolution_error_hist3[ i ] = sqrt( ( pow( resolution_error_stat_hist3[ i ], 2 ) ) + ( pow( resolution_error_sys_hist3[ i ], 2 ) ) );
          
    resolution_hist903[ i ] = rms_hist903[i] / mean_hist903[i];
    resolution_error_stat_hist903[ i ] = sqrt( pow( (rmserror_hist903[i]) / (mean_hist903[i]), 2 ) + pow( (rms_hist903[i] * meanerror_hist903[i]) / (mean_hist903[i] * mean_hist903[i]), 2 ) );
    resolution_error_sys_hist903[ i ] = 0.0;
    resolution_error_hist903[ i ] = sqrt( ( pow( resolution_error_stat_hist903[ i ], 2 ) ) + ( pow( resolution_error_sys_hist903[ i ], 2 ) ) );

    resolution3[ i ] = mean_sigma3[i] / mean_mean3[i];
    resolution_error_stat3[ i ] = sqrt( pow( (mean_sigmaerror3[i]) / (mean_mean3[i]), 2 ) + pow( (mean_sigma3[i] * mean_meanerror3[i]) / (mean_mean3[i] * mean_mean3[i]), 2 ) );
    resolution_error_sys3[ i ] = 0.0;
    resolution_error3[ i ] = sqrt( ( pow( resolution_error_stat3[ i ], 2 ) ) + ( pow( resolution_error_sys3[ i ], 2 ) ) );
      
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

// for ann
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
       
// for third
     printf( " %f ", mean3[i] );
     printf( " %f ", meanerror3[i] );
     printf( " %f ", rms3[i] );
     printf( " %f ", rmserror3[i] );
              
     printf( " %f ", mean_hist903[i] );
     printf( " %f ", meanerror_hist903[i] );
     printf( " %f ", rms_hist903[i] );
     printf( " %f ", rmserror_hist903[i] );
                    
     printf( " %f ", ratio_hist3[i] );
     printf( " %f ", ratio_error_hist3[i] );
     printf( " %f ", resolution_hist3[i] );
     printf( " %f ", resolution_error_hist3[i] );
           
     printf( " %f ", ratio_hist903[i] );
     printf( " %f ", ratio_error_hist903[i] );
     printf( " %f ", resolution_hist903[i] );
     printf( " %f ", resolution_error_hist903[i] );
              
     printf( " %f ", mean_mean3[i] );
     printf( " %f ", mean_meanerror3[i] );
     printf( " %f ", mean_sigma3[i] );
     printf( " %f ", mean_sigmaerror3[i] );
     printf( " %f ", ratio3[i] );
     printf( " %f ", ratio_error3[i] );
     printf( " %f ", resolution3[i] );
     printf( " %f ", resolution_error3[i] );
            
     printf( "\n" );
     printf( "\n" );
     printf( "\n" );
       
   }
    
  const Float_t binLo_lin1 = -0.4;
  const Float_t binHi_lin1 = 0.3;

  const Float_t binLo_lin2 = 0.0;
  const Float_t binHi_lin2 = 130.0;

  const Float_t binLo_abs = 0.0;
  const Float_t binHi_abs = 9.0;

  const Float_t binLo_rel = 0.0;
  const Float_t binHi_rel = 0.45;

//  const Float_t binLo_abs_dif1 = -1.0;
//  const Float_t binHi_abs_dif1 = 1.0;

//  const Float_t binLo_abs_dif2 = -1.0;
//  const Float_t binHi_abs_dif2 = 1.0;

//--------------------------------------------------------------------------------------------------
/*
   TH1F *hist_lin1;
   TH1F *hist_lin2;
   TH1F *hist_abs;
   TH1F *hist_rel;
   TH1F *hist_abs_dif1;
   TH1F *hist_abs_dif2;

   TH1F *hist1_lin1;
   TH1F *hist1_lin2;
   TH1F *hist1_abs;
   TH1F *hist1_rel;

  const Int_t nBins = 30;

  hist_lin1 = new TH1F("hist_lin1", "hist_lin1", nBins, binLo_lin1, binHi_lin1);
  hist_lin2 = new TH1F("hist_lin2", "hist_lin2", nBins, binLo_lin2, binHi_lin2);
  hist_abs = new TH1F("hist_abs", "hist_abs", nBins, binLo_abs, binHi_abs);
  hist_rel = new TH1F("hist_rel", "hist_rel", nBins, binLo_rel, binHi_rel);
  hist_abs_dif1 = new TH1F("hist_abs_dif1", "hist_abs_dif1", nBins, binLo_abs_dif1, binHi_abs_dif1);
  hist_abs_dif2 = new TH1F("hist_abs_dif2", "hist_abs_dif2", nBins, binLo_abs_dif2, binHi_abs_dif2);

  hist1_lin1 = new TH1F("hist1_lin1", "hist1_lin1", nBins, binLo_lin1, binHi_lin1);
  hist1_lin2 = new TH1F("hist1_lin2", "hist1_lin2", nBins, binLo_lin2, binHi_lin2);
  hist1_abs = new TH1F("hist1_abs", "hist1_abs", nBins, binLo_abs, binHi_abs);
  hist1_rel = new TH1F("hist1_rel", "hist1_rel", nBins, binLo_rel, binHi_rel);

  for (int i = 0; i < n; i++) {

     hist_lin1 -> Fill( ratio_hist90[ i ] );
     hist_lin2 -> Fill( mean_hist90[ i ] );
     hist_abs -> Fill( rms_hist90[ i ] );
     hist_rel -> Fill( resolution_hist90[ i ] );
     hist_abs_dif1 -> Fill( ratio_abs_hist90[ i ] );
     hist_abs_dif2 -> Fill( ratio_abs_other_hist90[ i ] );

     hist1_lin1 -> Fill( ratio_hist902[ i ] );
     hist1_lin2 -> Fill( mean_hist902[ i ] );
     hist1_abs -> Fill( rms_hist902[ i ] );
     hist1_rel -> Fill( resolution_hist902[ i ] );    

  }

  cout << "Underflow hist_lin1 === " << hist_lin1->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_lin1 === " << hist_lin1->GetBinContent( nBins + 1 ) << endl;

  cout << "Underflow hist_lin2 === " << hist_lin2->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_lin2 === " << hist_lin2->GetBinContent( nBins + 1 ) << endl;

  cout << "Underflow hist_abs === " << hist_abs->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_abs === " << hist_abs->GetBinContent( nBins + 1 ) << endl;

  cout << "Underflow hist_rel === " << hist_rel->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_rel === " << hist_rel->GetBinContent( nBins + 1 ) << endl;

  printf( "\n" );

  cout << "Underflow hist_abs_dif1 === " << hist_abs_dif1->GetBinContent( 0 ) << endl;
  cout << "Overflow hist_abs_dif1 === " << hist_abs_dif1->GetBinContent( nBins + 1 ) << endl;

//  cout << "Underflow hist_abs_dif2 === " << hist_abs_dif2->GetBinContent( 0 ) << endl;
//  cout << "Overflow hist_abs_dif2 === " << hist_abs_dif2->GetBinContent( nBins + 1 ) << endl;

  printf( "\n" );

  cout << "Underflow hist1_lin1 === " << hist1_lin1->GetBinContent( 0 ) << endl;
  cout << "Overflow hist1_lin1 === " << hist1_lin1->GetBinContent( nBins + 1 ) << endl;

  cout << "Underflow hist1_lin2 === " << hist1_lin2->GetBinContent( 0 ) << endl;
  cout << "Overflow hist1_lin2 === " << hist1_lin2->GetBinContent( nBins + 1 ) << endl;

  cout << "Underflow hist1_abs === " << hist1_abs->GetBinContent( 0 ) << endl;
  cout << "Overflow hist1_abs === " << hist1_abs->GetBinContent( nBins + 1 ) << endl;

  cout << "Underflow hist1_rel === " << hist1_rel->GetBinContent( 0 ) << endl;
  cout << "Overflow hist1_rel === " << hist1_rel->GetBinContent( nBins + 1 ) << endl;

  printf( "\n" );

  Float_t mean_hist_lin1 = hist_lin1 -> GetMean();
  Float_t meanerror_hist_lin1 = hist_lin1 -> GetMeanError();
  Float_t rms_hist_lin1 = hist_lin1 -> GetRMS();
  Float_t rmserror_hist_lin1 = hist_lin1 -> GetRMSError();
  cout << " 0:"
    << "  mean_hist_lin1: " << mean_hist_lin1
    << "  meanerror_hist_lin1: " << meanerror_hist_lin1
    << "  rms_hist_lin1: " << rms_hist_lin1
    << "  rmserror_hist_lin1: " << rmserror_hist_lin1
    << endl;

  Float_t mean_hist_lin2 = hist_lin2 -> GetMean();
  Float_t meanerror_hist_lin2 = hist_lin2 -> GetMeanError();
  Float_t rms_hist_lin2 = hist_lin2 -> GetRMS();
  Float_t rmserror_hist_lin2 = hist_lin2 -> GetRMSError();
  cout << " 0:"
    << "  mean_hist_lin2: " << mean_hist_lin2
    << "  meanerror_hist_lin2: " << meanerror_hist_lin2
    << "  rms_hist_lin2: " << rms_hist_lin2
    << "  rmserror_hist_lin2: " << rmserror_hist_lin2
    << endl;

  Float_t mean_hist_abs = hist_abs -> GetMean();
  Float_t meanerror_hist_abs = hist_abs -> GetMeanError();
  Float_t rms_hist_abs = hist_abs -> GetRMS();
  Float_t rmserror_hist_abs = hist_abs -> GetRMSError();
  cout << " 0:"
    << "  mean_hist_abs: " << mean_hist_abs
    << "  meanerror_hist_abs: " << meanerror_hist_abs
    << "  rms_hist_abs: " << rms_hist_abs
    << "  rmserror_hist_abs: " << rmserror_hist_abs
    << endl;

  Float_t mean_hist_rel = hist_rel -> GetMean();
  Float_t meanerror_hist_rel = hist_rel -> GetMeanError();
  Float_t rms_hist_rel = hist_rel -> GetRMS();
  Float_t rmserror_hist_rel = hist_rel -> GetRMSError();
  cout << " 0:"
    << "  mean_hist_rel: " << mean_hist_rel
    << "  meanerror_hist_rel: " << meanerror_hist_rel
    << "  rms_hist_rel: " << rms_hist_rel
    << "  rmserror_hist_rel: " << rmserror_hist_rel
    << endl;

  printf( "\n" );

  Float_t mean_hist_abs_dif1 = hist_abs_dif1 -> GetMean();
  Float_t meanerror_hist_abs_dif1 = hist_abs_dif1 -> GetMeanError();
  Float_t rms_hist_abs_dif1 = hist_abs_dif1 -> GetRMS();
  Float_t rmserror_hist_abs_dif1 = hist_abs_dif1 -> GetRMSError();
  cout << " 0:"
    << "  mean_hist_abs_dif1: " << mean_hist_abs_dif1
    << "  meanerror_hist_abs_dif1: " << meanerror_hist_abs_dif1
    << "  rms_hist_abs_dif1: " << rms_hist_abs_dif1
    << "  rmserror_hist_abs_dif1: " << rmserror_hist_abs_dif1
    << endl;

  Float_t mean_hist_abs_dif2 = hist_abs_dif2 -> GetMean();
  Float_t meanerror_hist_abs_dif2 = hist_abs_dif2 -> GetMeanError();
  Float_t rms_hist_abs_dif2 = hist_abs_dif2 -> GetRMS();
  Float_t rmserror_hist_abs_dif2 = hist_abs_dif2 -> GetRMSError();
  cout << " 0:"
    << "  mean_hist_abs_dif2: " << mean_hist_abs_dif2
    << "  meanerror_hist_abs_dif2: " << meanerror_hist_abs_dif2
    << "  rms_hist_abs_dif2: " << rms_hist_abs_dif2
    << "  rmserror_hist_abs_dif2: " << rmserror_hist_abs_dif2
    << endl;

  printf( "\n" );

  Float_t mean_hist1_lin1 = hist1_lin1 -> GetMean();
  Float_t meanerror_hist1_lin1 = hist1_lin1 -> GetMeanError();
  Float_t rms_hist1_lin1 = hist1_lin1 -> GetRMS();
  Float_t rmserror_hist1_lin1 = hist1_lin1 -> GetRMSError();
  cout << " 0:"
    << "  mean_hist1_lin1: " << mean_hist1_lin1
    << "  meanerror_hist1_lin1: " << meanerror_hist1_lin1
    << "  rms_hist1_lin1: " << rms_hist1_lin1
    << "  rmserror_hist1_lin1: " << rmserror_hist1_lin1
    << endl;

  Float_t mean_hist1_lin2 = hist1_lin2 -> GetMean();
  Float_t meanerror_hist1_lin2 = hist1_lin2 -> GetMeanError();
  Float_t rms_hist1_lin2 = hist1_lin2 -> GetRMS();
  Float_t rmserror_hist1_lin2 = hist1_lin2 -> GetRMSError();
  cout << " 0:"
    << "  mean_hist1_lin2: " << mean_hist1_lin2
    << "  meanerror_hist1_lin2: " << meanerror_hist1_lin2
    << "  rms_hist1_lin2: " << rms_hist1_lin2
    << "  rmserror_hist1_lin2: " << rmserror_hist1_lin2
    << endl;

  Float_t mean_hist1_abs = hist1_abs -> GetMean();
  Float_t meanerror_hist1_abs = hist1_abs -> GetMeanError();
  Float_t rms_hist1_abs = hist1_abs -> GetRMS();
  Float_t rmserror_hist1_abs = hist1_abs -> GetRMSError();
  cout << " 0:"
    << "  mean_hist1_abs: " << mean_hist1_abs
    << "  meanerror_hist1_abs: " << meanerror_hist1_abs
    << "  rms_hist1_abs: " << rms_hist1_abs
    << "  rmserror_hist1_abs: " << rmserror_hist1_abs
    << endl;

  Float_t mean_hist1_rel = hist1_rel -> GetMean();
  Float_t meanerror_hist1_rel = hist1_rel -> GetMeanError();
  Float_t rms_hist1_rel = hist1_rel -> GetRMS();
  Float_t rmserror_hist1_rel = hist1_rel -> GetRMSError();
  cout << " 0:"
    << "  mean_hist1_rel: " << mean_hist1_rel
    << "  meanerror_hist1_rel: " << meanerror_hist1_rel
    << "  rms_hist1_rel: " << rms_hist1_rel
    << "  rmserror_hist1_rel: " << rmserror_hist1_rel
    << endl;

*/
//--------------------------------------------------------------------------------------------------

   printf( "\n" );

   TGraphErrors *agr;
   TGraphErrors *bgr;
    
   TGraphErrors *cgr;
   TGraphErrors *dgr;
    
   TGraphErrors *egr;
   TGraphErrors *fgr;

   char fname[ 100 ];
   for ( int i = 0; i < 100; i++ ) fname[ i ] = 0;

   c1->cd();
   agr = new TGraphErrors( n, energy, ratio_hist90, energyerror, ratio_error_sys_hist90 );
   agr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, ratio_hist90, energyerror, ratio_error_stat_hist90 );
   bgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, ratio_hist902, energyerror, ratio_error_sys_hist902 ); // ratio_error_sys_hist902 // lin1_sys
   cgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, ratio_hist902, energyerror, ratio_error_stat_hist902 );
   dgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   egr = new TGraphErrors( n, energy, ratio_hist903, energyerror, ratio_error_sys_hist903 );
   egr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   egr->GetXaxis()->SetTitle("E_{true}, GeV");
   fgr = new TGraphErrors( n, energy, ratio_hist903, energyerror, ratio_error_stat_hist903 );
   fgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   fgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Linearity (Single K0_{L} in ILD)" );
   agr->GetYaxis()->SetRangeUser(binLo_lin1, binHi_lin1);
   agr->SetTitle(fname);
    
//--------------------------------------------------------------------------------------------------
/*
    Double_t lin1_chi2 = 0.0;
    Double_t lin1_chisl = 0.0;
    Double_t lin1_znam = 0.0;

    for ( int i = 0; i < n; i++ ) {
        lin1_chisl = ratio_hist90[i] - ratio_hist902[i];
        lin1_znam = sqrt( pow( ratio_error_stat_hist90[i], 2 ) + pow( ratio_error_stat_hist902[i], 2 ) );
            
        lin1_chi2 = lin1_chi2 + pow( ( lin1_chisl / lin1_znam ), 2 );
    }
        
    cout << "Linearity: lin1_chi2 === " << lin1_chi2 << endl;
    cout << "Linearity: lin1_chi2 / n === " << lin1_chi2 / n << endl;
    cout << "Linearity: lin1_chi2 / 29 === " << lin1_chi2 / 29 << "\n" << endl;
 */
//--------------------------------------------------------------------------------------------------

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
   egr->SetMarkerColor(kGreen-6);
   egr->SetFillStyle(3001);
   egr->SetLineColor(kGreen-6);
   egr->SetLineWidth(3);
   egr->SetFillColor(kGreen-6);
   egr->SetMarkerStyle(20);
   egr->Draw("3 SAME");
   fgr->SetMarkerColor(kGreen+3);
   fgr->SetLineColor(kGreen+3);
   fgr->SetLineWidth(3);
   fgr->SetFillColor(kGreen-6);
   fgr->SetMarkerStyle(20);
   fgr->Draw("P SAME");
   c1->Update();

   c2->cd();
   agr = new TGraphErrors( n, energy, mean_hist90, energyerror, energyerror );
   agr->GetYaxis()->SetTitle("E_{reco}, GeV");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, mean_hist90, energyerror, meanerror_hist90 );
   bgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, mean_hist902, energyerror, energyerror ); // energyerror // lin2_sys
   cgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, mean_hist902, energyerror, meanerror_hist902 );
   dgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   egr = new TGraphErrors( n, energy, mean_hist903, energyerror, energyerror );
   egr->GetYaxis()->SetTitle("E_{reco}, GeV");
   egr->GetXaxis()->SetTitle("E_{true}, GeV");
   fgr = new TGraphErrors( n, energy, mean_hist903, energyerror, meanerror_hist903 );
   fgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   fgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Linearity 2 (Single K0_{L} in ILD)" );
   agr->GetYaxis()->SetRangeUser(binLo_lin2, binHi_lin2);
   agr->SetTitle(fname);
    
//--------------------------------------------------------------------------------------------------
/*
    Double_t lin2_chi2 = 0.0;
    Double_t lin2_chisl = 0.0;
    Double_t lin2_znam = 0.0;

    for ( int i = 0; i < n; i++ ) {
        lin2_chisl = mean_hist90[i] - mean_hist902[i];
        lin2_znam = sqrt( pow( meanerror_hist90[i], 2 ) + pow( meanerror_hist902[i], 2 ) );
                
        lin2_chi2 = lin2_chi2 + pow( ( lin2_chisl / lin2_znam ), 2 );
    }
            
    cout << "Linearity 2: lin2_chi2 === " << lin2_chi2 << endl;
    cout << "Linearity 2: lin2_chi2 / n === " << lin2_chi2 / n << endl;
    cout << "Linearity 2: lin2_chi2 / 29 === " << lin2_chi2 / 29 << "\n" << endl;
 */
//--------------------------------------------------------------------------------------------------

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
   egr->SetMarkerColor(kGreen-6);
   egr->SetFillStyle(3001);
   egr->SetLineColor(kGreen-6);
   egr->SetLineWidth(3);
   egr->SetFillColor(kGreen-6);
   egr->SetMarkerStyle(20);
   egr->Draw("3 SAME");
   fgr->SetMarkerColor(kGreen+3);
   fgr->SetLineColor(kGreen+3);
   fgr->SetLineWidth(3);
   fgr->SetFillColor(kGreen-6);
   fgr->SetMarkerStyle(20);
   fgr->Draw("P SAME");
   c2->Update();

   c3->cd();
   agr = new TGraphErrors( n, energy, rms_hist90, energyerror, energyerror );
   agr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, rms_hist90, energyerror, rmserror_hist90 );
   bgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, rms_hist902, energyerror, energyerror ); // energyerror // abs_sys
   cgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, rms_hist902, energyerror, rmserror_hist902 );
   dgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   egr = new TGraphErrors( n, energy, rms_hist903, energyerror, energyerror );
   egr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   egr->GetXaxis()->SetTitle("E_{true}, GeV");
   fgr = new TGraphErrors( n, energy, rms_hist903, energyerror, rmserror_hist903 );
   fgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   fgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Absolute energy resolution (Single K0_{L} in ILD)" );
   agr->GetYaxis()->SetRangeUser(binLo_abs, binHi_abs);
   agr->SetTitle(fname);
    
//--------------------------------------------------------------------------------------------------
/*
    Double_t abs_chi2 = 0.0;
    Double_t abs_chisl = 0.0;
    Double_t abs_znam = 0.0;

    for ( int i = 0; i < n; i++ ) {
        abs_chisl = rms_hist90[i] - rms_hist902[i];
        abs_znam = sqrt( pow( rmserror_hist90[i], 2 ) + pow( rmserror_hist902[i], 2 ) );
                    
        abs_chi2 = abs_chi2 + pow( ( abs_chisl / abs_znam ), 2 );
    }
                
    cout << "Absolute energy resolution: abs_chi2 === " << abs_chi2 << endl;
    cout << "Absolute energy resolution: abs_chi2 / n === " << abs_chi2 / n << endl;
    cout << "Absolute energy resolution: abs_chi2 / 29 === " << abs_chi2 / 29 << "\n" << endl;
 */
//--------------------------------------------------------------------------------------------------

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
   egr->SetMarkerColor(kGreen-6);
   egr->SetFillStyle(3001);
   egr->SetLineColor(kGreen-6);
   egr->SetLineWidth(3);
   egr->SetFillColor(kGreen-6);
   egr->SetMarkerStyle(20);
   egr->Draw("3 SAME");
   fgr->SetMarkerColor(kGreen+3);
   fgr->SetLineColor(kGreen+3);
   fgr->SetLineWidth(3);
   fgr->SetFillColor(kGreen-6);
   fgr->SetMarkerStyle(20);
   fgr->Draw("P SAME");
   c3->Update();

   c4->cd();
   agr = new TGraphErrors( n, energy, resolution_hist90, energyerror, resolution_error_sys_hist90 );
   agr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, resolution_hist90, energyerror, resolution_error_stat_hist90 );
   bgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, resolution_hist902, energyerror, resolution_error_sys_hist902 ); // resolution_error_sys_hist902 // rel_sys
   cgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, resolution_hist902, energyerror, resolution_error_stat_hist902 );
   dgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   egr = new TGraphErrors( n, energy, resolution_hist903, energyerror, resolution_error_sys_hist903 );
   egr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   egr->GetXaxis()->SetTitle("E_{true}, GeV");
   fgr = new TGraphErrors( n, energy, resolution_hist903, energyerror, resolution_error_stat_hist903 );
   fgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   fgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Relative energy resolution (Single K0_{L} in ILD)" );
   agr->GetYaxis()->SetRangeUser(binLo_rel, binHi_rel);
   agr->SetTitle(fname);
    
//--------------------------------------------------------------------------------------------------
/*
    Double_t rel_chi2 = 0.0;
    Double_t rel_chisl = 0.0;
    Double_t rel_znam = 0.0;

    for ( int i = 0; i < n; i++ ) {
        rel_chisl = resolution_hist90[i] - resolution_hist902[i];
        rel_znam = sqrt( pow( resolution_error_stat_hist90[i], 2 ) + pow( resolution_error_stat_hist902[i], 2 ) );
        
        rel_chi2 = rel_chi2 + pow( ( rel_chisl / rel_znam ), 2 );
      }
    
    cout << "Relative energy resolution: rel_chi2 === " << rel_chi2 << endl;
    cout << "Relative energy resolution: rel_chi2 / n === " << rel_chi2 / n << endl;
    cout << "Relative energy resolution: rel_chi2 / 29 === " << rel_chi2 / 29 << "\n" << endl;
 */
//--------------------------------------------------------------------------------------------------

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
   egr->SetMarkerColor(kGreen-6);
   egr->SetFillStyle(3001);
   egr->SetLineColor(kGreen-6);
   egr->SetLineWidth(3);
   egr->SetFillColor(kGreen-6);
   egr->SetMarkerStyle(20);
   egr->Draw("3 SAME");
   fgr->SetMarkerColor(kGreen+3);
   fgr->SetLineColor(kGreen+3);
   fgr->SetLineWidth(3);
   fgr->SetFillColor(kGreen-6);
   fgr->SetMarkerStyle(20);
   fgr->Draw("P SAME");
   c4->Update();
   
/*   c5->cd();
   agr = new TGraphErrors( n, energy, ratio_abs_hist90, energyerror, ratio_abs_error_sys_hist90 );
   agr->GetYaxis()->SetTitle("( #DeltaE_{ann} - #DeltaE_{reco} ) / #DeltaE_{reco}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, ratio_abs_hist90, energyerror, ratio_abs_error_stat_hist90 );
   bgr->GetYaxis()->SetTitle("( #DeltaE_{ann} - #DeltaE_{reco} ) / #DeltaE_{reco}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
//   cgr = new TGraphErrors( n, energy, ratio_abs_hist90, energyerror, ratio_abs_error_sys_hist90 );
//   cgr->GetYaxis()->SetTitle("( #DeltaE_{ann} - #DeltaE_{reco} ) / #DeltaE_{reco}");
//   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
//   dgr = new TGraphErrors( n, energy, ratio_abs_hist90, energyerror, ratio_abs_error_stat_hist90 );
//   dgr->GetYaxis()->SetTitle("( #DeltaE_{ann} - #DeltaE_{reco} ) / #DeltaE_{reco}");
//   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Absolute difference (Single K0_{L} in ILD)" );
//   agr->GetYaxis()->SetRangeUser(0.5, 2.0);
//   agr->GetYaxis()->SetRangeUser(binLo_abs_dif1, binHi_abs_dif1);
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
   c5->Update();

   c6->cd();
   agr = new TGraphErrors( n, energy, ratio_abs_other_hist90, energyerror, ratio_abs_other_error_sys_hist90 );
   agr->GetYaxis()->SetTitle("#DeltaE_{ann} / #DeltaE_{reco}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, ratio_abs_other_hist90, energyerror, ratio_abs_other_error_stat_hist90 );
   bgr->GetYaxis()->SetTitle("#DeltaE_{ann} / #DeltaE_{reco}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
//   cgr = new TGraphErrors( n, energy, ratio_abs_other_hist90, energyerror, ratio_abs_other_error_sys_hist90 );
//   cgr->GetYaxis()->SetTitle("#DeltaE_{ann} / #DeltaE_{reco}");
//   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
//   dgr = new TGraphErrors( n, energy, ratio_abs_other_hist90, energyerror, ratio_abs_other_error_stat_hist90 );
//   dgr->GetYaxis()->SetTitle("#DeltaE_{ann} / #DeltaE_{reco}");
//   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Absolute difference 2 (Single K0_{L} in ILD)" );
//   agr->GetYaxis()->SetRangeUser(1.5, 3.0);
//   agr->GetYaxis()->SetRangeUser(binLo_abs_dif2, binHi_abs_dif2);
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
   c6->Update();
*/
   TLegend *lsc1 = new TLegend(0.55,0.62,0.90,0.92);
   lsc1->AddEntry(bgr,"reco, hist90 (stat)","pl");
   lsc1->AddEntry(dgr,"dnn, hist90 (stat)","pl"); // (stat+sys) and "plf"
   lsc1->AddEntry(fgr,"dnn_test, hist90 (stat)","pl");
   
   TLegend *lsc2 = new TLegend(0.55,0.62,0.90,0.92);
   lsc2->AddEntry(bgr,"reco, hist90 (stat)","pl");
   lsc2->AddEntry(dgr,"dnn, hist90 (stat)","pl"); // (stat+sys) and "plf"
   lsc2->AddEntry(fgr,"dnn_test, hist90 (stat)","pl");
   
   TLegend *lsc3 = new TLegend(0.55,0.62,0.90,0.92);
   lsc3->AddEntry(bgr,"reco, hist90 (stat)","pl");
   lsc3->AddEntry(dgr,"dnn, hist90 (stat)","pl"); // (stat+sys) and "plf"
   lsc3->AddEntry(fgr,"dnn_test, hist90 (stat)","pl");
   
   TLegend *lsc4 = new TLegend(0.55,0.62,0.90,0.92);
   lsc4->AddEntry(bgr,"reco, hist90 (stat)","pl");
   lsc4->AddEntry(dgr,"dnn, hist90 (stat)","pl"); // (stat+sys) and "plf"
   lsc4->AddEntry(fgr,"dnn_test, hist90 (stat)","pl");

//   TLegend *lsc5 = new TLegend(0.55,0.62,0.90,0.92);
//   lsc5->AddEntry(bgr,"reco w.r.t dnn, hist90 (stat)","pl");
//   lsc5->AddEntry(dgr,"mc vs ann, hist90 (stat)","pl");

//   TLegend *lsc6 = new TLegend(0.55,0.62,0.90,0.92);
//   lsc6->AddEntry(bgr,"reco w.r.t dnn, hist90 (stat)","pl");
//   lsc6->AddEntry(dgr,"mc vs ann, hist90 (stat)","pl");
   
//   TLegend *lsc7 = new TLegend(0.55,0.62,0.90,0.92);
//   lsc7->AddEntry(bgr,"mc, hist90 (stat)","pl");
//   lsc7->AddEntry(dgr,"ann, hist90 (stat)","pl");

//   TLegend *lsc8 = new TLegend(0.55,0.62,0.90,0.92);
//   lsc8->AddEntry(bgr,"mc, hist90 (stat)","pl");
//   lsc8->AddEntry(dgr,"ann, hist90 (stat)","pl");

   c1->cd();
   lsc1->Draw();
   c2->cd();
   lsc2->Draw();
   c3->cd();
   lsc3->Draw();
   c4->cd();
   lsc4->Draw();
//   c5->cd();
//   lsc5->Draw();
//   c6->cd();
//   lsc6->Draw();
//   c7->cd();
//   lsc7->Draw();
//   c8->cd();
//   lsc8->Draw();
/*
   c7->cd();
   hist1_lin1->SetLineColor(kRed);
   hist1_lin1 -> Draw();
   hist_lin1 -> Draw("SAME");

   c8->cd();
   hist_lin2 -> Draw();
   hist1_lin2->SetLineColor(kRed);
   hist1_lin2 -> Draw("SAME");

   c9->cd();
   hist1_abs->SetLineColor(kRed);
   hist1_abs -> Draw();
   hist_abs -> Draw("SAME");

   c10->cd();
   hist_rel -> Draw();
   hist1_rel->SetLineColor(kRed);
   hist1_rel -> Draw("SAME");

   c11->cd();
   hist_abs_dif1 -> Draw();

   c12->cd();
   hist_abs_dif2 -> Draw();
*/
}
