void plot_hists() {
     TCanvas *c1 = new TCanvas("graph1","graph1",200,10,700,500);
//     TCanvas *c2 = new TCanvas("graph2","graph2",200,10,700,500);
//     TCanvas *c3 = new TCanvas("graph3","graph3",200,10,700,500);
//     TCanvas *c4 = new TCanvas("graph4","graph4",200,10,700,500);
//     TCanvas *c5 = new TCanvas("graph5","graph5",200,10,700,500);
//     TCanvas *c6 = new TCanvas("graph6","graph6",200,10,700,500);
//     TCanvas *c7 = new TCanvas("graph7","graph7",200,10,700,500);
//     TCanvas *c8 = new TCanvas("graph8","graph8",200,10,700,500);

//     c1->SetGrid();
//     c2->SetGrid();
//     c3->SetGrid();
//     c4->SetGrid();
//     c5->SetGrid();
//     c6->SetGrid();
//     c7->SetGrid();
//     c8->SetGrid();

     const Int_t n = 29; // 9
     const Int_t nfiles = 10;

     Float_t energy[nfiles][ n ];
     Float_t energyerror[nfiles][ n ];
 
// for ann
    Float_t mean[nfiles][ n ];
    Float_t meanerror[nfiles][ n ];
    Float_t rms[nfiles][ n ];
    Float_t rmserror[nfiles][ n ];

    Float_t mean_hist90[nfiles][ n ];
    Float_t meanerror_hist90[nfiles][ n ];
    Float_t rms_hist90[nfiles][ n ];
    Float_t rmserror_hist90[nfiles][ n ];

    Float_t mean_mean[nfiles][ n ];
//    Float_t rms_mean[nfiles][ n ];
    Float_t mean_meanerror[nfiles][ n ];
//    Float_t rms_meanerror[nfiles][ n ];
    Float_t mean_sigma[nfiles][ n ];
//    Float_t rms_sigma[nfiles][ n ];
    Float_t mean_sigmaerror[nfiles][ n ];
//    Float_t rms_sigmaerror[nfiles][ n ];
//    Float_t mean_chi[nfiles][ n ];
//    Float_t rms_chi[nfiles][ n ];

    Float_t ratio_hist[nfiles][ n ];
    Float_t ratio_error_stat_hist[nfiles][ n ];
    Float_t ratio_error_sys_hist[nfiles][ n ];
    Float_t ratio_error_hist[nfiles][ n ];
    Float_t resolution_hist[nfiles][ n ];
    Float_t resolution_error_stat_hist[nfiles][ n ];
    Float_t resolution_error_sys_hist[nfiles][ n ];
    Float_t resolution_error_hist[nfiles][ n ];

    Float_t ratio_hist90[nfiles][ n ];
    Float_t ratio_error_stat_hist90[nfiles][ n ];
    Float_t ratio_error_sys_hist90[nfiles][ n ];
    Float_t ratio_error_hist90[nfiles][ n ];
    Float_t resolution_hist90[nfiles][ n ];
    Float_t resolution_error_stat_hist90[nfiles][ n ];
    Float_t resolution_error_sys_hist90[nfiles][ n ];
    Float_t resolution_error_hist90[nfiles][ n ];

    Float_t ratio[nfiles][ n ];
    Float_t ratio_error_stat[nfiles][ n ];
    Float_t ratio_error_sys[nfiles][ n ];
    Float_t ratio_error[nfiles][ n ];
    Float_t resolution[nfiles][ n ];
    Float_t resolution_error_stat[nfiles][ n ];
    Float_t resolution_error_sys[nfiles][ n ];
    Float_t resolution_error[nfiles][ n ];

// for data

    Float_t denergy[ n ];
    Float_t denergyerror[ n ];

    Float_t dmean[ n ];
    Float_t dmeanerror[ n ];
    Float_t drms[ n ];
    Float_t drmserror[ n ];

    Float_t dmean_hist90[ n ];
    Float_t dmeanerror_hist90[ n ];
    Float_t drms_hist90[ n ];
    Float_t drmserror_hist90[ n ];

    Float_t dmean_mean[ n ];
//    Float_t drms_mean[ n ];
    Float_t dmean_meanerror[ n ];
//    Float_t drms_meanerror[ n ];
    Float_t dmean_sigma[ n ];
//    Float_t drms_sigma[ n ];
    Float_t dmean_sigmaerror[ n ];
//    Float_t drms_sigmaerror[ n ];
//    Float_t dmean_chi[ n ];
//    Float_t drms_chi[ n ];

    Float_t dratio_hist[ n ];
    Float_t dratio_error_stat_hist[ n ];
    Float_t dratio_error_sys_hist[ n ];
    Float_t dratio_error_hist[ n ];
    Float_t dresolution_hist[ n ];
    Float_t dresolution_error_stat_hist[ n ];
    Float_t dresolution_error_sys_hist[ n ];
    Float_t dresolution_error_hist[ n ];

    Float_t dratio_hist90[ n ];
    Float_t dratio_error_stat_hist90[ n ];
    Float_t dratio_error_sys_hist90[ n ];
    Float_t dratio_error_hist90[ n ];
    Float_t dresolution_hist90[ n ];
    Float_t dresolution_error_stat_hist90[ n ];
    Float_t dresolution_error_sys_hist90[ n ];
    Float_t dresolution_error_hist90[ n ];

    Float_t dratio[ n ];
    Float_t dratio_error_stat[ n ];
    Float_t dratio_error_sys[ n ];
    Float_t dratio_error[ n ];
    Float_t dresolution[ n ];
    Float_t dresolution_error_stat[ n ];
    Float_t dresolution_error_sys[ n ];
    Float_t dresolution_error[ n ];
    
    for( int j = 0; j < nfiles; j++ ) {
        for( int i = 0; i < n; i++ ) {

            energy[ j ][ i ] = 0.0;
            energyerror[ j ][ i ] = 0.0;
    
            // for ann
            mean[ j ][ i ] = 0.0;
            meanerror[ j ][ i ] = 0.0;
            rms[ j ][ i ] = 0.0;
            rmserror[ j ][ i ] = 0.0;
    
            mean_hist90[ j ][ i ] = 0.0;
            meanerror_hist90[ j ][ i ] = 0.0;
            rms_hist90[ j ][ i ] = 0.0;
            rmserror_hist90[ j ][ i ] = 0.0;
    
            mean_mean[ j ][ i ] = 0.0;
            //    rms_mean[ j ][ i ] = 0.0;
            mean_meanerror[ j ][ i ] = 0.0;
            //    rms_meanerror[ j ][ i ] = 0.0;
            mean_sigma[ j ][ i ] = 0.0;
            //    rms_sigma[ j ][ i ] = 0.0;
            mean_sigmaerror[ j ][ i ] = 0.0;
            //    rms_sigmaerror[ j ][ i ] = 0.0;
            //    mean_chi[ j ][ i ] = 0.0;
            //    rms_chi[ j ][ i ] = 0.0;
    
            ratio_hist[ j ][ i ] = 0.0;
            ratio_error_stat_hist[ j ][ i ] = 0.0;
            ratio_error_sys_hist[ j ][ i ] = 0.0;
            ratio_error_hist[ j ][ i ] = 0.0;
            resolution_hist[ j ][ i ] = 0.0;
            resolution_error_stat_hist[ j ][ i ] = 0.0;
            resolution_error_sys_hist[ j ][ i ] = 0.0;
            resolution_error_hist[ j ][ i ] = 0.0;
    
            ratio_hist90[ j ][ i ] = 0.0;
            ratio_error_stat_hist90[ j ][ i ] = 0.0;
            ratio_error_sys_hist90[ j ][ i ] = 0.0;
            ratio_error_hist90[ j ][ i ] = 0.0;
            resolution_hist90[ j ][ i ] = 0.0;
            resolution_error_stat_hist90[ j ][ i ] = 0.0;
            resolution_error_sys_hist90[ j ][ i ] = 0.0;
            resolution_error_hist90[ j ][ i ] = 0.0;
    
            ratio[ j ][ i ] = 0.0;
            ratio_error_stat[ j ][ i ] = 0.0;
            ratio_error_sys[ j ][ i ] = 0.0;
            ratio_error[ j ][ i ] = 0.0;
            resolution[ j ][ i ] = 0.0;
            resolution_error_stat[ j ][ i ] = 0.0;
            resolution_error_sys[ j ][ i ] = 0.0;
            resolution_error[ j ][ i ] = 0.0;

        }
    }

    for( int i = 0; i < n; i++ ) {
    
        // for data

        denergy[ i ] = 0.0;
        denergyerror[ i ] = 0.0;

        dmean[ i ] = 0.0;
        dmeanerror[ i ] = 0.0;
        drms[ i ] = 0.0;
        drmserror[ i ] = 0.0;
    
        dmean_hist90[ i ] = 0.0;
        dmeanerror_hist90[ i ] = 0.0;
        drms_hist90[ i ] = 0.0;
        drmserror_hist90[ i ] = 0.0;
    
        dmean_mean[ i ] = 0.0;
        //    drms_mean[ i ] = 0.0;
        dmean_meanerror[ i ] = 0.0;
        //    drms_meanerror[ i ] = 0.0;
        dmean_sigma[ i ] = 0.0;
        //    drms_sigma[ i ] = 0.0;
        dmean_sigmaerror[ i ] = 0.0;
        //    drms_sigmaerror[ i ] = 0.0;
        //    dmean_chi[ i ] = 0.0;
        //    drms_chi[ i ] = 0.0;
    
        dratio_hist[ i ] = 0.0;
        dratio_error_stat_hist[ i ] = 0.0;
        dratio_error_sys_hist[ i ] = 0.0;
        dratio_error_hist[ i ] = 0.0;
        dresolution_hist[ i ] = 0.0;
        dresolution_error_stat_hist[ i ] = 0.0;
        dresolution_error_sys_hist[ i ] = 0.0;
        dresolution_error_hist[ i ] = 0.0;
    
        dratio_hist90[ i ] = 0.0;
        dratio_error_stat_hist90[ i ] = 0.0;
        dratio_error_sys_hist90[ i ] = 0.0;
        dratio_error_hist90[ i ] = 0.0;
        dresolution_hist90[ i ] = 0.0;
        dresolution_error_stat_hist90[ i ] = 0.0;
        dresolution_error_sys_hist90[ i ] = 0.0;
        dresolution_error_hist90[ i ] = 0.0;
    
        dratio[ i ] = 0.0;
        dratio_error_stat[ i ] = 0.0;
        dratio_error_sys[ i ] = 0.0;
        dratio_error[ i ] = 0.0;
        dresolution[ i ] = 0.0;
        dresolution_error_stat[ i ] = 0.0;
        dresolution_error_sys[ i ] = 0.0;
        dresolution_error[ i ] = 0.0;

    }
    
    char fname[ 200 ];
    for ( int i = 0; i < 200; i++ ) fname[ i ] = 0;

// for ann
    FILE *file[nfiles];
    for( int i = 0; i < nfiles; i++ ) {
        sprintf( fname, "%d_out_ann.txt", i + 1 );
        file[i] = fopen(fname, "r");
        if ( !(long)file[i] ) return;
    }

// for data
    FILE *dfile= fopen("out_data.txt", "r");
        if ( !(long)dfile ) return;

// for ann
    for( int j = 0; j < nfiles; j++ ) {
        for ( int i = 0; i < n; i++ ) {
           fscanf( file[j], "%f %E %E %E %E %E %E %E %E %E %E %E %E\n", &energy[j][i], &mean_hist90[j][i], &meanerror_hist90[j][i], &rms_hist90[j][i], &rmserror_hist90[j][i], &mean[j][i], &meanerror[j][i], &rms[j][i], &rmserror[j][i], &mean_mean[j][i], &mean_meanerror[j][i], &mean_sigma[j][i], &mean_sigmaerror[j][i] );
           if ( feof( file[j] ) ) break;
        }
    }

// for data
    for ( int i = 0; i < n; i++ ) {
           fscanf( dfile, "%f %E %E %E %E %E %E %E %E %E %E %E %E\n", &denergy[i], &dmean_hist90[i], &dmeanerror_hist90[i], &drms_hist90[i], &drmserror_hist90[i], &dmean[i], &dmeanerror[i], &drms[i], &drmserror[i], &dmean_mean[i], &dmean_meanerror[i], &dmean_sigma[i], &dmean_sigmaerror[i] );
           if ( feof( dfile ) ) break;
    }
 
    for ( int j = 0; j < nfiles; j++ ) {
        for ( int i = 0; i < n; i++ ) {
            // for ann
            ratio_hist[ j ][ i ] = ( mean[ j ][ i ] - energy[ j ][ i ] ) / energy[ j ][ i ];
            ratio_error_stat_hist[ j ][ i ] = sqrt( pow( (meanerror[ j ][ i ]) / (energy[ j ][ i ]), 2 ) + pow( (mean[ j ][ i ] * energyerror[ j ][ i ]) / (energy[ j ][ i ] * energy[ j ][ i ]), 2 ) );
            ratio_error_sys_hist[ j ][ i ] = 0.0;
            ratio_error_hist[ j ][ i ] = sqrt( ( pow( ratio_error_stat_hist[ j ][ i ], 2 ) ) + ( pow( ratio_error_sys_hist[ j ][ i ], 2 ) ) );
               
            ratio_hist90[ j ][ i ] = ( mean_hist90[ j ][ i ] - energy[ j ][ i ] ) / energy[ j ][ i ];
            ratio_error_stat_hist90[ j ][ i ] = sqrt( pow( (meanerror_hist90[ j ][ i ]) / (energy[ j ][ i ]), 2 ) + pow( (mean_hist90[ j ][ i ] * energyerror[ j ][ i ]) / (energy[ j ][ i ] * energy[ j ][ i ]), 2 ) );
            ratio_error_sys_hist90[ j ][ i ] = 0.0;
            ratio_error_hist90[ j ][ i ] = sqrt( ( pow( ratio_error_stat_hist90[ j ][ i ], 2 ) ) + ( pow( ratio_error_sys_hist90[ j ][ i ], 2 ) ) );

            ratio[ j ][ i ] = ( mean_mean[ j ][ i ] - energy[ j ][ i ] ) / energy[ j ][ i ];
            ratio_error_stat[ j ][ i ] = sqrt( pow( (mean_meanerror[ j ][ i ]) / (energy[ j ][ i ]), 2 ) + pow( (mean_mean[ j ][ i ] * energyerror[ j ][ i ]) / (energy[ j ][ i ] * energy[ j ][ i ]), 2 ) );
            ratio_error_sys[ j ][ i ] = 0.0;
            ratio_error[ j ][ i ] = sqrt( ( pow( ratio_error_stat[ j ][ i ], 2 ) ) + ( pow( ratio_error_sys[ j ][ i ], 2 ) ) );
            
            resolution_hist[ j ][ i ] = rms[ j ][ i ] / mean[ j ][ i ];
            resolution_error_stat_hist[ j ][ i ] = sqrt( pow( (rmserror[ j ][ i ]) / (mean[ j ][ i ]), 2 ) + pow( (rms[ j ][ i ] * meanerror[ j ][ i ]) / (mean[ j ][ i ] * mean[ j ][ i ]), 2 ) );
            resolution_error_sys_hist[ j ][ i ] = 0.0;
            resolution_error_hist[ j ][ i ] = sqrt( ( pow( resolution_error_stat_hist[ j ][ i ], 2 ) ) + ( pow( resolution_error_sys_hist[ j ][ i ], 2 ) ) );
            
            resolution_hist90[ j ][ i ] = rms_hist90[ j ][ i ] / mean_hist90[ j ][ i ];
            resolution_error_stat_hist90[ j ][ i ] = sqrt( pow( (rmserror_hist90[ j ][ i ]) / (mean_hist90[ j ][ i ]), 2 ) + pow( (rms_hist90[ j ][ i ] * meanerror_hist90[ j ][ i ]) / (mean_hist90[ j ][ i ] * mean_hist90[ j ][ i ]), 2 ) );
            resolution_error_sys_hist90[ j ][ i ] = 0.0;
            resolution_error_hist90[ j ][ i ] = sqrt( ( pow( resolution_error_stat_hist90[ j ][ i ], 2 ) ) + ( pow( resolution_error_sys_hist90[ j ][ i ], 2 ) ) );

            resolution[ j ][ i ] = mean_sigma[ j ][ i ] / mean_mean[ j ][ i ];
            resolution_error_stat[ j ][ i ] = sqrt( pow( (mean_sigmaerror[ j ][ i ]) / (mean_mean[ j ][ i ]), 2 ) + pow( (mean_sigma[ j ][ i ] * mean_meanerror[ j ][ i ]) / (mean_mean[ j ][ i ] * mean_mean[ j ][ i ]), 2 ) );
            resolution_error_sys[ j ][ i ] = 0.0;
            resolution_error[ j ][ i ] = sqrt( ( pow( resolution_error_stat[ j ][ i ], 2 ) ) + ( pow( resolution_error_sys[ j ][ i ], 2 ) ) );
        }
    }

    for ( int i = 0; i < n; i++ ) {
            // for data
            dratio_hist[ i ] = ( dmean[ i ] - denergy[ i ] ) / denergy[ i ];
            dratio_error_stat_hist[ i ] = sqrt( pow( (dmeanerror[ i ]) / (denergy[ i ]), 2 ) + pow( (dmean[ i ] * denergyerror[ i ]) / (denergy[ i ] * denergy[ i ]), 2 ) );
            dratio_error_sys_hist[ i ] = 0.0;
            dratio_error_hist[ i ] = sqrt( ( pow( dratio_error_stat_hist[ i ], 2 ) ) + ( pow( dratio_error_sys_hist[ i ], 2 ) ) );
               
            dratio_hist90[ i ] = ( dmean_hist90[ i ] - denergy[ i ] ) / denergy[ i ];
            dratio_error_stat_hist90[ i ] = sqrt( pow( (dmeanerror_hist90[ i ]) / (denergy[ i ]), 2 ) + pow( (dmean_hist90[ i ] * denergyerror[ i ]) / (denergy[ i ] * denergy[ i ]), 2 ) );
            dratio_error_sys_hist90[ i ] = 0.0;
            dratio_error_hist90[ i ] = sqrt( ( pow( dratio_error_stat_hist90[ i ], 2 ) ) + ( pow( dratio_error_sys_hist90[ i ], 2 ) ) );

            dratio[ i ] = ( dmean_mean[ i ] - denergy[ i ] ) / denergy[ i ];
            dratio_error_stat[ i ] = sqrt( pow( (dmean_meanerror[ i ]) / (denergy[ i ]), 2 ) + pow( (dmean_mean[ i ] * denergyerror[ i ]) / (denergy[ i ] * denergy[ i ]), 2 ) );
            dratio_error_sys[ i ] = 0.0;
            dratio_error[ i ] = sqrt( ( pow( dratio_error_stat[ i ], 2 ) ) + ( pow( dratio_error_sys[ i ], 2 ) ) );
            
            dresolution_hist[ i ] = drms[ i ] / dmean[ i ];
            dresolution_error_stat_hist[ i ] = sqrt( pow( (drmserror[ i ]) / (dmean[ i ]), 2 ) + pow( (drms[ i ] * dmeanerror[ i ]) / (dmean[ i ] * dmean[ i ]), 2 ) );
            dresolution_error_sys_hist[ i ] = 0.0;
            dresolution_error_hist[ i ] = sqrt( ( pow( dresolution_error_stat_hist[ i ], 2 ) ) + ( pow( dresolution_error_sys_hist[ i ], 2 ) ) );
            
            dresolution_hist90[ i ] = drms_hist90[ i ] / dmean_hist90[ i ];
            dresolution_error_stat_hist90[ i ] = sqrt( pow( (drmserror_hist90[ i ]) / (dmean_hist90[ i ]), 2 ) + pow( (drms_hist90[ i ] * dmeanerror_hist90[ i ]) / (dmean_hist90[ i ] * dmean_hist90[ i ]), 2 ) );
            dresolution_error_sys_hist90[ i ] = 0.0;
            dresolution_error_hist90[ i ] = sqrt( ( pow( dresolution_error_stat_hist90[ i ], 2 ) ) + ( pow( dresolution_error_sys_hist90[ i ], 2 ) ) );

            dresolution[ i ] = dmean_sigma[ i ] / dmean_mean[ i ];
            dresolution_error_stat[ i ] = sqrt( pow( (dmean_sigmaerror[ i ]) / (dmean_mean[ i ]), 2 ) + pow( (dmean_sigma[ i ] * dmean_meanerror[ i ]) / (dmean_mean[ i ] * dmean_mean[ i ]), 2 ) );
            dresolution_error_sys[ i ] = 0.0;
            dresolution_error[ i ] = sqrt( ( pow( dresolution_error_stat[ i ], 2 ) ) + ( pow( dresolution_error_sys[ i ], 2 ) ) );
    }

    printf( "\n" );
    for (int j = 0; j < nfiles; j++) {
        printf( "File number: %d\n", j+1 );
        for (int i = 0; i < n; i++) {
            printf( " %f ", energy[j][i] );
            printf( " %f ", energyerror[j][i] );
      
            // for ann
            printf( " %f ", mean[j][i] );
            printf( " %f ", meanerror[j][i] );
            printf( " %f ", rms[j][i] );
            printf( " %f ", rmserror[j][i] );
         
            printf( " %f ", mean_hist90[j][i] );
            printf( " %f ", meanerror_hist90[j][i] );
            printf( " %f ", rms_hist90[j][i] );
            printf( " %f ", rmserror_hist90[j][i] );
                 
            printf( " %f ", ratio_hist[j][i] );
            printf( " %f ", ratio_error_hist[j][i] );
            printf( " %f ", resolution_hist[j][i] );
            printf( " %f ", resolution_error_hist[j][i] );
     
            printf( " %f ", ratio_hist90[j][i] );
            printf( " %f ", ratio_error_hist90[j][i] );
            printf( " %f ", resolution_hist90[j][i] );
            printf( " %f ", resolution_error_hist90[j][i] );
         
            printf( " %f ", mean_mean[j][i] );
            printf( " %f ", mean_meanerror[j][i] );
            printf( " %f ", mean_sigma[j][i] );
            printf( " %f ", mean_sigmaerror[j][i] );
            printf( " %f ", ratio[j][i] );
            printf( " %f ", ratio_error[j][i] );
            printf( " %f ", resolution[j][i] );
            printf( " %f ", resolution_error[j][i] );
      
            printf( "\n" );
            printf( "\n" );
            printf( "\n" );
        }
    }
    
    const int nBins1 = 100;
    const float binLo1 = -0.5;
    const float binHi1 = 0.5;

    const int nBins2 = 10;
    const float binLo2 = 0.0;
    const float binHi2 = 130.0;
    
    const int nBins3 = 10;
    const float binLo3 = 0.0;
    const float binHi3 = 9.0;
    
    const int nBins4 = 10;
    const float binLo4 = 0.0;
    const float binHi4 = 0.5;

    TH1F *hist1[n];  // lin1
    TH1F *hist2[n];  // lin2
    TH1F *hist3[n];  // abs
    TH1F *hist4[n];  // rel
    
/*    char fname1[ 200 ];
    for ( int i = 0; i < 200; i++ ) fname1[ i ] = 0;
    
    char fname2[ 200 ];
    for ( int i = 0; i < 200; i++ ) fname2[ i ] = 0;
    
    char fname3[ 200 ];
    for ( int i = 0; i < 200; i++ ) fname3[ i ] = 0;
    
    char fname4[ 200 ];
    for ( int i = 0; i < 200; i++ ) fname4[ i ] = 0;
    
    sprintf( fname1, "%d_out_ann.txt", i );
  */
    
    for( int i = 0; i < n; i++ ) {
        hist1[i] = new TH1F("hist1", "hist1", nBins1, binLo1, binHi1);
        hist2[i] = new TH1F("hist2", "hist2", nBins2, binLo2, binHi2);
        hist3[i] = new TH1F("hist3", "hist3", nBins3, binLo3, binHi3);
        hist4[i] = new TH1F("hist4", "hist4", nBins4, binLo4, binHi4);
    }

    for ( int j = 0; j < nfiles; j++ ) {
        for ( int i = 0; i < n; i++ ) {
            hist1[i] -> Fill( ratio_hist90[ j ][ i ] );
            hist2[i] -> Fill( mean_hist90[ j ][ i ] );
            hist3[i] -> Fill( rms_hist90[ j ][ i ] );
            hist4[i] -> Fill( resolution_hist90[ j ][ i ] );
        }
    }
    
    
    for ( int i = 0; i < n; i++ ) {
        cout << "Underflow hist1[" << i << "] === " << hist1[i]->GetBinContent( 0 ) << endl;
        cout << "Overflow hist1[" << i << "] === " << hist1[i]->GetBinContent( nBins1 + 1 ) << endl;
        
        cout << "Underflow hist2[" << i << "] === " << hist2[i]->GetBinContent( 0 ) << endl;
        cout << "Overflow hist2[" << i << "] === " << hist2[i]->GetBinContent( nBins2 + 1 ) << endl;
        
        cout << "Underflow hist3[" << i << "] === " << hist3[i]->GetBinContent( 0 ) << endl;
        cout << "Overflow hist3[" << i << "] === " << hist3[i]->GetBinContent( nBins3 + 1 ) << endl;
        
        cout << "Underflow hist4[" << i << "] === " << hist4[i]->GetBinContent( 0 ) << endl;
        cout << "Overflow hist4[" << i << "] === " << hist4[i]->GetBinContent( nBins4 + 1 ) << endl;
    }

    c1->cd();
    hist1[28]->DrawCopy();
    
    float mean1[n];
    float meanerror1[n];
    float rms1[n];
    float rmserror1[n];
    
    float mean2[n];
    float meanerror2[n];
    float rms2[n];
    float rmserror2[n];
    
    float mean3[n];
    float meanerror3[n];
    float rms3[n];
    float rmserror3[n];
    
    float mean4[n];
    float meanerror4[n];
    float rms4[n];
    float rmserror4[n];
    
    for ( int i = 0; i < n; i++ ) {
        mean1[i] = 0;
        meanerror1[i] = 0;
        rms1[i] = 0;
        rmserror1[i] = 0;
        
        mean2[i] = 0;
        meanerror2[i] = 0;
        rms2[i] = 0;
        rmserror2[i] = 0;
        
        mean3[i] = 0;
        meanerror3[i] = 0;
        rms3[i] = 0;
        rmserror3[i] = 0;
        
        mean4[i] = 0;
        meanerror4[i] = 0;
        rms4[i] = 0;
        rmserror4[i] = 0;
    }

    for ( int i = 0; i < n; i++ ) {
        mean1[i] = hist1[i] -> GetMean();
        meanerror1[i] = hist1[i] -> GetMeanError();
        rms1[i] = hist1[i] -> GetRMS();
        rmserror1[i] = hist1[i] -> GetRMSError();
        
        cout << "1_" << i + 1 << ": "
        << "  Mean1_" << i + 1 << ": " << mean1[i]
        << "  Mean1_" << i + 1 << " error: "<< meanerror1[i]
        << "  RMS1_" << i + 1 << ": " << rms1[i]
        << "  RMS1_" << i + 1 << " error: " << rmserror1[i]
        << endl;
        
        
        mean2[i] = hist2[i] -> GetMean();
        meanerror2[i] = hist2[i] -> GetMeanError();
        rms2[i] = hist2[i] -> GetRMS();
        rmserror2[i] = hist2[i] -> GetRMSError();
        
        cout << "2_" << i + 1 << ": "
        << "  Mean2_" << i + 1 << ": " << mean2[i]
        << "  Mean2_" << i + 1 << " error: "<< meanerror2[i]
        << "  RMS2_" << i + 1 << ": " << rms2[i]
        << "  RMS2_" << i + 1 << " error: " << rmserror2[i]
        << endl;
        
        
        mean3[i] = hist3[i] -> GetMean();
        meanerror3[i] = hist3[i] -> GetMeanError();
        rms3[i] = hist3[i] -> GetRMS();
        rmserror3[i] = hist3[i] -> GetRMSError();
        
        cout << "3_" << i + 1 << ": "
        << "  Mean3_" << i + 1 << ": " << mean3[i]
        << "  Mean3_" << i + 1 << " error: "<< meanerror3[i]
        << "  RMS3_" << i + 1 << ": " << rms3[i]
        << "  RMS3_" << i + 1 << " error: " << rmserror3[i]
        << endl;
        
        
        mean4[i] = hist4[i] -> GetMean();
        meanerror4[i] = hist4[i] -> GetMeanError();
        rms4[i] = hist4[i] -> GetRMS();
        rmserror4[i] = hist4[i] -> GetRMSError();
        
        cout << "4_" << i + 1 << ": "
        << "  Mean4_" << i + 1 << ": " << mean4[i]
        << "  Mean4_" << i + 1 << " error: "<< meanerror4[i]
        << "  RMS4_" << i + 1 << ": " << rms4[i]
        << "  RMS4_" << i + 1 << " error: " << rmserror4[i]
        << endl;
    }

    //
    // Open file for output
    //
    
    FILE *out = fopen("systematic.txt", "a+");
    printf("File open... ");
    if (!out) {
       printf("[FAIL]\n");
       return;
    } else printf("[OK]\n");

    for ( int i = 0; i < n; i++ ) {
        fprintf( out, "%f %E %E %E %E\n", energy[0][i], rms1[i], rms2[i], rms3[i], rms4[i] );
    }

    TH1F *dhist1[n];  // lin1 with data
    TH1F *dhist2[n];  // lin2 with data
    TH1F *dhist3[n];  // abs with data
    TH1F *dhist4[n];  // rel with data
    
    for( int i = 0; i < n; i++ ) {
        dhist1[i] = new TH1F("dhist1", "dhist1", nBins1, binLo1, binHi1);
        dhist2[i] = new TH1F("dhist2", "dhist2", nBins2, binLo2, binHi2);
        dhist3[i] = new TH1F("dhist3", "dhist3", nBins3, binLo3, binHi3);
        dhist4[i] = new TH1F("dhist4", "dhist4", nBins4, binLo4, binHi4);
    }

    for ( int j = 0; j < nfiles; j++ ) {
        for ( int i = 0; i <n; i++ ) {
            dhist1[i] -> Fill( ratio_hist90[ j ][ i ] );
            dhist2[i] -> Fill( mean_hist90[ j ][ i ] );
            dhist3[i] -> Fill( rms_hist90[ j ][ i ] );
            dhist4[i] -> Fill( resolution_hist90[ j ][ i ] );
        }
    }

    for ( int i = 0; i < n; i++ ) {
        dhist1[i] -> Fill( dratio_hist90[ i ] );
        dhist2[i] -> Fill( dmean_hist90[ i ] );
        dhist3[i] -> Fill( drms_hist90[ i ] );
        dhist4[i] -> Fill( dresolution_hist90[ i ] );
    }
    
    for ( int i = 0; i < n; i++ ) {
        delete hist1[i];
        delete hist2[i];
        delete hist3[i];
        delete hist4[i];
        
        delete dhist1[i];
        delete dhist2[i];
        delete dhist3[i];
        delete dhist4[i];
    }

  fclose( out );
//  file -> Close();

/*

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
    c2->Update();

    c3->cd();
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
    
    c5->cd();
    agr = new TGraphErrors( n, energy, ratio_abs_hist90, energyerror, ratio_abs_error_sys_hist90 );
    agr->GetYaxis()->SetTitle("( #DeltaE_{ann} - #DeltaE_{reco} ) / #DeltaE_{reco}");
    agr->GetXaxis()->SetTitle("E_{true}, GeV");
    bgr = new TGraphErrors( n, energy, ratio_abs_hist90, energyerror, ratio_abs_error_stat_hist90 );
    bgr->GetYaxis()->SetTitle("( #DeltaE_{ann} - #DeltaE_{reco} ) / #DeltaE_{reco}");
    bgr->GetXaxis()->SetTitle("E_{true}, GeV");
//    cgr = new TGraphErrors( n, energy, ratio_abs_hist90, energyerror, ratio_abs_error_sys_hist90 );
//    cgr->GetYaxis()->SetTitle("( #DeltaE_{ann} - #DeltaE_{reco} ) / #DeltaE_{reco}");
//    cgr->GetXaxis()->SetTitle("E_{true}, GeV");
//    dgr = new TGraphErrors( n, energy, ratio_abs_hist90, energyerror, ratio_abs_error_stat_hist90 );
//    dgr->GetYaxis()->SetTitle("( #DeltaE_{ann} - #DeltaE_{reco} ) / #DeltaE_{reco}");
//    dgr->GetXaxis()->SetTitle("E_{true}, GeV");
    sprintf( fname, "Absolute difference" );
//    agr->GetYaxis()->SetRangeUser(-1.0, 1.0);
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
//    cgr = new TGraphErrors( n, energy, ratio_abs_other_hist90, energyerror, ratio_abs_other_error_sys_hist90 );
//    cgr->GetYaxis()->SetTitle("#DeltaE_{ann} / #DeltaE_{reco}");
//    cgr->GetXaxis()->SetTitle("E_{true}, GeV");
//    dgr = new TGraphErrors( n, energy, ratio_abs_other_hist90, energyerror, ratio_abs_other_error_stat_hist90 );
//    dgr->GetYaxis()->SetTitle("#DeltaE_{ann} / #DeltaE_{reco}");
//    dgr->GetXaxis()->SetTitle("E_{true}, GeV");
    sprintf( fname, "Absolute difference 2" );
//    agr->GetYaxis()->SetRangeUser(-1.0, 1.0);
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

    TLegend *lsc5 = new TLegend(0.55,0.62,0.90,0.92);
    lsc5->AddEntry(bgr,"mc vs ann, hist90 (stat)","pl");
//    lsc5->AddEntry(dgr,"mc vs ann, hist90 (stat)","pl");

    TLegend *lsc6 = new TLegend(0.55,0.62,0.90,0.92);
    lsc6->AddEntry(bgr,"mc vs ann, hist90 (stat)","pl");
//    lsc6->AddEntry(dgr,"mc vs ann, hist90 (stat)","pl");
    
    TLegend *lsc7 = new TLegend(0.55,0.62,0.90,0.92);
    lsc7->AddEntry(bgr,"mc, hist90 (stat)","pl");
    lsc7->AddEntry(dgr,"ann, hist90 (stat)","pl");

    TLegend *lsc8 = new TLegend(0.55,0.62,0.90,0.92);
    lsc8->AddEntry(bgr,"mc, hist90 (stat)","pl");
    lsc8->AddEntry(dgr,"ann, hist90 (stat)","pl");

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
    c7->cd();
    lsc7->Draw();
    c8->cd();
    lsc8->Draw();
*/

}
