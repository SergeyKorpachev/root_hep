/*Double_t func(Double_t *x, Double_t *par) {
    
    Double_t a = sqrt((par[0]*par[0])/(*x) + par[1]*par[1] + (par[2]*par[2])/((*x)*(*x)));
    
    return a;
    
}
*/
void plot_data_ann_2() {
   TCanvas *c1 = new TCanvas("graph1","graph1",200,10,700,500);
   TCanvas *c2 = new TCanvas("graph2","graph2",200,10,700,500);
   TCanvas *c3 = new TCanvas("graph3","graph3",200,10,700,500);
   TCanvas *c4 = new TCanvas("graph4","graph4",200,10,700,500);
   TCanvas *c5 = new TCanvas("graph5","graph5",200,10,700,500);
   TCanvas *c6 = new TCanvas("graph6","graph6",200,10,700,500);

   c1->SetGrid();
   c2->SetGrid();
   c3->SetGrid();
   c4->SetGrid();

   c5->SetGrid();
   c6->SetGrid();

   c1->SetTickx(1);
   c1->SetTicky(1);
   c2->SetTickx(1);
   c2->SetTicky(1);
   c3->SetTickx(1);
   c3->SetTicky(1);
   c4->SetTickx(1);
   c4->SetTicky(1);

   c5->SetTickx(1);
   c5->SetTicky(1);
   c6->SetTickx(1);
   c6->SetTicky(1);

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

   Float_t lin1_sys[ n ];
   Float_t lin2_sys[ n ];
   Float_t abs_sys[ n ];
   Float_t rel_sys[ n ];

// for difference
   Float_t ratio_abs_hist[ n ];
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

   lin1_sys[ i ] = 0.0;
   lin2_sys[ i ] = 0.0;
   abs_sys[ i ] = 0.0;
   rel_sys[ i ] = 0.0;

// for difference
   ratio_abs_hist[ i ] = 0.0;
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
   ratio_abs_other_error[ i ] = 0.0;

   }

// for data
   FILE *file1 = fopen("out_data.txt", "r");
   if ( !(long)file1 ) return;

// for ann
   FILE *file2 = fopen("out_ann.txt", "r");
   if ( !(long)file2 ) return;

// for systematic
   FILE *file3 = fopen("systematic.txt", "r");
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

// for systematic
  for ( int i = 0; i < n; i++ ) {
    fscanf( file3, "%f %E %E %E %E\n", &energy[i], &lin1_sys[i], &lin2_sys[i], &abs_sys[i], &rel_sys[i] );
    if ( feof( file3 ) ) break;
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

// for difference
    ratio_abs_hist[ i ] = ( rms2[i] - rms[i] ) / rms[i];
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
   cgr = new TGraphErrors( n, energy, ratio_hist902, energyerror, lin1_sys ); // lin1_sys
   cgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, ratio_hist902, energyerror, ratio_error_stat_hist902 );
   dgr->GetYaxis()->SetTitle("( E_{reco} - E_{true} ) / E_{true}");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Linearity (Single K0_{L} in ILD)" );
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
   agr = new TGraphErrors( n, energy, mean_hist90, energyerror, energyerror );
   agr->GetYaxis()->SetTitle("E_{reco}, GeV");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, mean_hist90, energyerror, meanerror_hist90 );
   bgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, mean_hist902, energyerror, lin2_sys ); // lin2_sys
   cgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, mean_hist902, energyerror, meanerror_hist902 );
   dgr->GetYaxis()->SetTitle("E_{reco}, GeV");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Linearity 2 (Single K0_{L} in ILD)" );
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
   c2->Update();

   c3->cd();
   agr = new TGraphErrors( n, energy, rms_hist90, energyerror, energyerror );
   agr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, rms_hist90, energyerror, rmserror_hist90 );
   bgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, rms_hist902, energyerror, abs_sys ); // abs_sys
   cgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, rms_hist902, energyerror, rmserror_hist902 );
   dgr->GetYaxis()->SetTitle("#DeltaE_{reco}, GeV");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Absolute energy resolution (Single K0_{L} in ILD)" );
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
   c3->Update();

   c4->cd();
    
    Int_t nnn = n - 1;
    
    Float_t energyttt[nnn];
    Float_t energyerrorttt[nnn];
    Float_t resolution_hist90ttt[nnn];
    Float_t resolution_hist902ttt[nnn];
    Float_t resolution_error_sys_hist90ttt[nnn];
    Float_t resolution_error_stat_hist90ttt[nnn];
    Float_t rel_systtt[nnn];
    Float_t resolution_error_stat_hist902ttt[nnn];
    
   for (int i = 0; i < nnn; i++) {
       energyttt[i] = 0.0;
       energyerrorttt[i] = 0.0;
       resolution_hist90ttt[i] = 0.0;
       resolution_hist902ttt[i] = 0.0;
       resolution_error_sys_hist90ttt[i] = 0.0;
       resolution_error_stat_hist90ttt[i] = 0.0;
       rel_systtt[i] = 0.0;
       resolution_error_stat_hist902ttt[i] = 0.0;
   }
    
   for (int i = 1; i < n; i++) {
       energyttt[i-1] = energy[i];
       energyerrorttt[i-1] = energyerror[i];
       resolution_hist90ttt[i-1] = resolution_hist90[i];
       resolution_hist902ttt[i-1] = resolution_hist902[i];
       resolution_error_sys_hist90ttt[i-1] = resolution_error_sys_hist90[i];
       resolution_error_stat_hist90ttt[i-1] = resolution_error_stat_hist90[i];
       rel_systtt[i-1] = rel_sys[i];
       resolution_error_stat_hist902ttt[i-1] = resolution_error_stat_hist902[i];
   }
    
   agr = new TGraphErrors( n, energy, resolution_hist90, energyerror, resolution_error_sys_hist90 );
   agr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, resolution_hist90, energyerror, resolution_error_stat_hist90 );
   bgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
   cgr = new TGraphErrors( n, energy, resolution_hist902, energyerror, rel_sys ); // rel_sys
   cgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
   dgr = new TGraphErrors( n, energy, resolution_hist902, energyerror, resolution_error_stat_hist902 );
   dgr->GetYaxis()->SetTitle("#DeltaE_{reco} / E_{reco}");
   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Relative energy resolution (Single K0_{L} in ILD)" );
   agr->GetYaxis()->SetRangeUser(0.0, 0.45);
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

    cout << "Data_stat_fit:" << endl;
    //f1 -> SetParameter(2, 0.0);
    //f1 -> SetParameter(1, 0.0);
    //f1 -> SetParameter(2, 0.0);
    bgr -> Fit( f1 );
    cout << "Ann_stat_fit:" << endl;
    //f2 -> SetParameter(2, 0.3);
    dgr -> Fit( f1 );
    cout << "Ann_sys_fit:" << endl;
    //f2 -> SetParameter(2, 0.3);
    cgr -> Fit( f1 );
    //f1->SetLineColor(kBlue);
     
//    cout << "Fit:" << endl;
    //f1 -> SetParameter(0, 0.0);
    //f1 -> SetParameter(1, 0.0);
    //f1 -> SetParameter(2, 0.0);
//    agr -> Fit( f1 );
//    cout << "Hist90_2:" << endl;
    //f2 -> SetParameter(2, 0.3);
//    bgr -> Fit( f1 );
//    cout << "Hist95_2:" << endl;
    //f3 -> SetParameter(2, 0.3);
//    cgr -> Fit( f1 );
//    cout << "Hist:" << endl;
    //f4 -> SetParameter(2, 0.3);
//    dgr -> Fit( f1 );
    //f1->SetLineColor(kBlue);
    //f1->SetLineColor(kRed);
    //f1->SetLineColor(kGreen);
    //f1->SetLineColor(kMagenta);


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
   
   c5->cd();
   agr = new TGraphErrors( n, energy, ratio_abs_hist90, energyerror, ratio_abs_error_sys_hist90 );
   agr->GetYaxis()->SetTitle("( #DeltaE_{dnn} - #DeltaE_{reco} ) / #DeltaE_{reco}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, ratio_abs_hist90, energyerror, ratio_abs_error_stat_hist90 );
   bgr->GetYaxis()->SetTitle("( #DeltaE_{dnn} - #DeltaE_{reco} ) / #DeltaE_{reco}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
//   cgr = new TGraphErrors( n, energy, ratio_abs_hist90, energyerror, ratio_abs_error_sys_hist90 );
//   cgr->GetYaxis()->SetTitle("( #DeltaE_{ann} - #DeltaE_{reco} ) / #DeltaE_{reco}");
//   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
//   dgr = new TGraphErrors( n, energy, ratio_abs_hist90, energyerror, ratio_abs_error_stat_hist90 );
//   dgr->GetYaxis()->SetTitle("( #DeltaE_{ann} - #DeltaE_{reco} ) / #DeltaE_{reco}");
//   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Absolute difference (Single K0_{L} in ILD)" );
//   agr->GetYaxis()->SetRangeUser(-1.0, 1.0);
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
   agr->GetYaxis()->SetTitle("#DeltaE_{dnn} / #DeltaE_{reco}");
   agr->GetXaxis()->SetTitle("E_{true}, GeV");
   bgr = new TGraphErrors( n, energy, ratio_abs_other_hist90, energyerror, ratio_abs_other_error_stat_hist90 );
   bgr->GetYaxis()->SetTitle("#DeltaE_{dnn} / #DeltaE_{reco}");
   bgr->GetXaxis()->SetTitle("E_{true}, GeV");
//   cgr = new TGraphErrors( n, energy, ratio_abs_other_hist90, energyerror, ratio_abs_other_error_sys_hist90 );
//   cgr->GetYaxis()->SetTitle("#DeltaE_{ann} / #DeltaE_{reco}");
//   cgr->GetXaxis()->SetTitle("E_{true}, GeV");
//   dgr = new TGraphErrors( n, energy, ratio_abs_other_hist90, energyerror, ratio_abs_other_error_stat_hist90 );
//   dgr->GetYaxis()->SetTitle("#DeltaE_{ann} / #DeltaE_{reco}");
//   dgr->GetXaxis()->SetTitle("E_{true}, GeV");
   sprintf( fname, "Absolute difference 2 (Single K0_{L} in ILD)" );
//   agr->GetYaxis()->SetRangeUser(-1.0, 1.0);
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

   TLegend *lsc1 = new TLegend(0.55,0.62,0.90,0.92);
   lsc1->AddEntry(bgr,"reco, hist90 (stat)","pl");
//   lsc1->AddEntry(cgr,"ann, hist90 (sys)","pl");
   lsc1->AddEntry(dgr,"dnn, hist90 (stat+sys)","plf");
   
   TLegend *lsc2 = new TLegend(0.55,0.62,0.90,0.92);
   lsc2->AddEntry(bgr,"reco, hist90 (stat)","pl");
//   lsc2->AddEntry(cgr,"ann, hist90 (sys)","pl");
   lsc2->AddEntry(dgr,"dnn, hist90 (stat+sys)","plf");
   
   TLegend *lsc3 = new TLegend(0.55,0.62,0.90,0.92);
   lsc3->AddEntry(bgr,"reco, hist90 (stat)","pl");
//   lsc3->AddEntry(cgr,"ann, hist90 (sys)","pl");
   lsc3->AddEntry(dgr,"dnn, hist90 (stat+sys)","plf");
   
   TLegend *lsc4 = new TLegend(0.55,0.62,0.90,0.92);
   lsc4->AddEntry(bgr,"reco, hist90 (stat)","pl");
//   lsc4->AddEntry(cgr,"ann, hist90 (sys)","pl");
   lsc4->AddEntry(dgr,"dnn, hist90 (stat+sys)","plf");

   TLegend *lsc5 = new TLegend(0.55,0.62,0.90,0.92);
   lsc5->AddEntry(bgr,"reco w.r.t dnn, hist90 (stat)","pl");
//   lsc5->AddEntry(dgr,"mc vs ann, hist90 (stat)","pl");

   TLegend *lsc6 = new TLegend(0.55,0.62,0.90,0.92);
   lsc6->AddEntry(bgr,"reco w.r.t dnn, hist90 (stat)","pl");
//   lsc6->AddEntry(dgr,"mc vs ann, hist90 (stat)","pl");

   c1->cd();
   lsc1->Draw();
   c2->cd();
   lsc2->Draw();
   c3->cd();
   lsc3->Draw();
   c4->cd();
   lsc4->Draw();
   c5->cd();
   lsc5->Draw();
   c6->cd();
   lsc6->Draw();
    
    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    printf( "QWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQW" );
    printf( "QWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQW" );
    printf( "QWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQW" );
    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    for (int i = 0; i < n; i++) {
        printf( " %f ", energy[i] );
//        printf( " %f ", energyerror[i] );
        
   // for data
//        printf( " %f ", mean[i] );
//        printf( " %f ", meanerror[i] );
//        printf( " %f ", rms[i] );
//        printf( " %f ", rmserror[i] );
          
        printf( " %f ", mean_hist90[i] );
//        printf( " %f ", meanerror_hist90[i] );
        printf( " %f ", rms_hist90[i] );
//        printf( " %f ", rmserror_hist90[i] );
                
//        printf( " %f ", ratio_hist[i] );
//        printf( " %f ", ratio_error_hist[i] );
//        printf( " %f ", resolution_hist[i] );
//        printf( " %f ", resolution_error_hist[i] );
       
//        printf( " %f ", ratio_hist90[i] );
//        printf( " %f ", ratio_error_hist90[i] );
        printf( " %f ", resolution_hist90[i] );
//        printf( " %f ", resolution_error_hist90[i] );
          
//        printf( " %f ", mean_mean[i] );
//        printf( " %f ", mean_meanerror[i] );
//        printf( " %f ", mean_sigma[i] );
//        printf( " %f ", mean_sigmaerror[i] );
//        printf( " %f ", ratio[i] );
//        printf( " %f ", ratio_error[i] );
//        printf( " %f ", resolution[i] );
//        printf( " %f ", resolution_error[i] );
        
        printf( "\n" );

   // for ann
//        printf( " %f ", mean2[i] );
//        printf( " %f ", meanerror2[i] );
//        printf( " %f ", rms2[i] );
//        printf( " %f ", rmserror2[i] );
          
        printf( " %f ", mean_hist902[i] );
//        printf( " %f ", meanerror_hist902[i] );
        printf( " %f ", rms_hist902[i] );
//        printf( " %f ", rmserror_hist902[i] );
                
//        printf( " %f ", ratio_hist2[i] );
//        printf( " %f ", ratio_error_hist2[i] );
//        printf( " %f ", resolution_hist2[i] );
//        printf( " %f ", resolution_error_hist2[i] );
       
//        printf( " %f ", ratio_hist902[i] );
//        printf( " %f ", ratio_error_hist902[i] );
        printf( " %f ", resolution_hist902[i] );
//        printf( " %f ", resolution_error_hist902[i] );
          
//        printf( " %f ", mean_mean2[i] );
//        printf( " %f ", mean_meanerror2[i] );
//        printf( " %f ", mean_sigma2[i] );
//        printf( " %f ", mean_sigmaerror2[i] );
//        printf( " %f ", ratio2[i] );
//        printf( " %f ", ratio_error2[i] );
//        printf( " %f ", resolution2[i] );
//        printf( " %f ", resolution_error2[i] );
//
        printf( "\n" );
        printf( "\n" );
        printf( "\n" );
    }
    
    printf( "RES\n" );
    printf( "resolution_hist90 for data and resolution_hist902 for ann\n" );
    for (int i = 0; i < n; i++) {
        printf("%f : resolution_hist90/resolution_hist902 === %f and (resolution_hist90/resolution_hist902)-1 === %f (%f %%)\n", energy[i], resolution_hist90[i]/resolution_hist902[i], (resolution_hist90[i]/resolution_hist902[i])-1, ((resolution_hist90[i]/resolution_hist902[i])-1)*100);
    }
    printf( "RES\n" );
    
    printf( "MEAN\n" );
    printf( "mean_hist90 for data and mean_hist902 for ann\n" );
    for (int i = 0; i < n; i++) {
        printf("%f : mean_hist902/mean_hist90 === %f and (mean_hist902/mean_hist90)-1 === %f (%f %%)\n", energy[i], mean_hist902[i]/mean_hist90[i], (mean_hist902[i]/mean_hist90[i])-1, ((mean_hist902[i]/mean_hist90[i])-1)*100);
    }
    printf( "MEAN\n" );
    
    printf( "MEAN for 90 and 120\n" );
    printf( "mean_hist90 for data and mean_hist902 for ann\n" );
    for (int i = n-2; i < n; i++) {
        printf("%f : mean_hist90/mean_hist902 === %f and (mean_hist90/mean_hist902)-1 === %f (%f %%)\n", energy[i], mean_hist90[i]/mean_hist902[i], (mean_hist90[i]/mean_hist902[i])-1, ((mean_hist90[i]/mean_hist902[i])-1)*100);
    }
    printf( "MEAN for 90 and 120\n" );
    
    printf( "ABS\n" );
    printf( "rms_hist90 for data and rms_hist902 for ann\n" );
    for (int i = 0; i < n; i++) {
        printf("%f : rms_hist90/rms_hist902 === %f and (rms_hist90/rms_hist902)-1 === %f (%f %%)\n", energy[i], rms_hist90[i]/rms_hist902[i], (rms_hist90[i]/rms_hist902[i])-1, ((rms_hist90[i]/rms_hist902[i])-1)*100);
    }
    printf( "ABS\n" );
    
    Float_t res_everage = 0;
    
    printf( "RES average\n" );
    printf( "resolution_hist90 for data and resolution_hist902 for ann and n = 29\n" );
    for (int i = 1; i < n; i++) {
        printf("%f : (resolution_hist90/resolution_hist902)-1 === %f\n", energy[i], (resolution_hist90[i]/resolution_hist902[i])-1);
        res_everage = res_everage + ((resolution_hist90[i]/resolution_hist902[i])-1);
    }
    printf("res_everage === %f and res_everage/(n-1) === %f (%f %%)\n", res_everage, res_everage/(n-1), (res_everage/(n-1))*100);
    printf( "RES average\n" );

}
