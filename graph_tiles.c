void graph_tiles() {
    TCanvas *c1 = new TCanvas("plot","plot",200,10,700,500);
    c1->SetGrid();

//////////////////////////////////////////////////// 1 = data, 2 = 380, 3 = 190, 4 = 140, 5 = 60, 6 = 38 /////////////////////////////////////////////////////////////

    const Int_t n = 400;
    Int_t n2 = 41;

    Float_t x1[n];
    Float_t y1[n];
    Float_t a1[n];
    Float_t ea1[n];

    Float_t x2[n];
    Float_t y2[n];
    Float_t a2[n];
    Float_t ea2[n];

    Float_t x3[n];
    Float_t y3[n];
    Float_t a3[n];
    Float_t ea3[n];

    Float_t x4[n];
    Float_t y4[n];
    Float_t a4[n];
    Float_t ea4[n];

    Float_t x5[n];
    Float_t y5[n];
    Float_t a5[n];
    Float_t ea5[n];

    Float_t x6[n];
    Float_t y6[n];
    Float_t a6[n];
    Float_t ea6[n];
    

    Float_t x1f[n2];
    Float_t a1f[n2];
    Float_t ea1f[n2];

    Float_t x2f[n2];
    Float_t a2f[n2];
    Float_t ea2f[n2];

    Float_t x3f[n2];
    Float_t a3f[n2];
    Float_t ea3f[n2];

    Float_t x4f[n2];
    Float_t a4f[n2];
    Float_t ea4f[n2];

    Float_t x5f[n2];
    Float_t a5f[n2];
    Float_t ea5f[n2];

    Float_t x6f[n2];
    Float_t a6f[n2];
    Float_t ea6f[n2];

    Float_t errors[n2];
    Float_t errors_x[n2];
    
    for ( int i = 0; i < n; i++ ) x1[ i ] = 0;
    for ( int i = 0; i < n; i++ ) y1[ i ] = 0;
    for ( int i = 0; i < n; i++ ) a1[ i ] = 0;
    for ( int i = 0; i < n; i++ ) ea1[ i ] = 0;

    for ( int i = 0; i < n; i++ ) x2[ i ] = 0;
    for ( int i = 0; i < n; i++ ) y2[ i ] = 0;
    for ( int i = 0; i < n; i++ ) a2[ i ] = 0;
    for ( int i = 0; i < n; i++ ) ea2[ i ] = 0;

    for ( int i = 0; i < n; i++ ) x3[ i ] = 0;
    for ( int i = 0; i < n; i++ ) y3[ i ] = 0;
    for ( int i = 0; i < n; i++ ) a3[ i ] = 0;
    for ( int i = 0; i < n; i++ ) ea3[ i ] = 0;

    for ( int i = 0; i < n; i++ ) x4[ i ] = 0;
    for ( int i = 0; i < n; i++ ) y4[ i ] = 0;
    for ( int i = 0; i < n; i++ ) a4[ i ] = 0;
    for ( int i = 0; i < n; i++ ) ea4[ i ] = 0;

    for ( int i = 0; i < n; i++ ) x5[ i ] = 0;
    for ( int i = 0; i < n; i++ ) y5[ i ] = 0;
    for ( int i = 0; i < n; i++ ) a5[ i ] = 0;
    for ( int i = 0; i < n; i++ ) ea5[ i ] = 0;

    for ( int i = 0; i < n; i++ ) x6[ i ] = 0;
    for ( int i = 0; i < n; i++ ) y6[ i ] = 0;
    for ( int i = 0; i < n; i++ ) a6[ i ] = 0;
    for ( int i = 0; i < n; i++ ) ea6[ i ] = 0;

    
    for ( int i = 0; i < n2; i++ ) x1f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) a1f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) ea1f[ i ] = 0;

    for ( int i = 0; i < n2; i++ ) x2f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) a2f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) ea2f[ i ] = 0;

    for ( int i = 0; i < n2; i++ ) x3f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) a3f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) ea3f[ i ] = 0;

    for ( int i = 0; i < n2; i++ ) x4f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) a4f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) ea4f[ i ] = 0;

    for ( int i = 0; i < n2; i++ ) x5f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) a5f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) ea5f[ i ] = 0;

    for ( int i = 0; i < n2; i++ ) x6f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) a6f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) ea6f[ i ] = 0;

    for ( int i = 0; i < n2; i++ ) errors[ i ] = 0.0;
    for ( int i = 0; i < n2; i++ ) errors_x[ i ] = 0.75; // sqrt(1.5);
   
    FILE *file1 = fopen("data.txt", "r");
    if ( !(long)file1 ) return;
    
    FILE *file2 = fopen("mc_380.txt", "r");
    if ( !(long)file2 ) return;

    FILE *file3 = fopen("mc_190.txt", "r");
    if ( !(long)file3 ) return;

    FILE *file4 = fopen("mc_140.txt", "r");
    if ( !(long)file4 ) return;

    FILE *file5 = fopen("mc_60_0.14.txt", "r");
    if ( !(long)file5 ) return;

    FILE *file6 = fopen("mc_38.txt", "r");
    if ( !(long)file6 ) return;

    for ( int i = 0; i < n; i++ ) {
        fscanf( file1, "%f %f %f %f\n", &x1[i], &y1[i], &a1[i], &ea1[i]);
        if ( feof( file1 ) ) break;
    }
    for ( int i = 0; i < n; i++ ) {
        fscanf( file2, "%f %f %f %f\n", &x2[i], &y2[i], &a2[i], &ea2[i]);
        if ( feof( file2 ) ) break;
    }
    for ( int i = 0; i < n; i++ ) {
        fscanf( file3, "%f %f %f %f\n", &x3[i], &y3[i], &a3[i], &ea3[i]);
        if ( feof( file3 ) ) break;
    }
    for ( int i = 0; i < n; i++ ) {
        fscanf( file4, "%f %f %f %f\n", &x4[i], &y4[i], &a4[i], &ea4[i]);
        if ( feof( file4 ) ) break;
    }
    for ( int i = 0; i < n; i++ ) {
        fscanf( file5, "%f %f %f %f\n", &x5[i], &y5[i], &a5[i], &ea5[i]);
        if ( feof( file5 ) ) break;
    }
    for ( int i = 0; i < n; i++ ) {
        fscanf( file6, "%f %f %f %f\n", &x6[i], &y6[i], &a6[i], &ea6[i]);
        if ( feof( file6 ) ) break;
    }

    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    
    cout << "data:" << endl;
    for (int i = 0; i < n; i++) {
        printf( " %f %f %f %f\n", x1[i], y1[i], a1[i], ea1[i] );
    }
    cout << "mc_380:" << endl;
    for (int i = 0; i < n; i++) {
        printf( " %f %f %f %f\n", x2[i], y2[i], a2[i], ea2[i] );
    }
    cout << "mc_190:" << endl;
    for (int i = 0; i < n; i++) {
        printf( " %f %f %f %f\n", x3[i], y3[i], a3[i], ea3[i] );
    }
    cout << "mc_140:" << endl;
    for (int i = 0; i < n; i++) {
        printf( " %f %f %f %f\n", x4[i], y4[i], a4[i], ea4[i] );
    }
    cout << "mc_60:" << endl;
    for (int i = 0; i < n; i++) {
        printf( " %f %f %f %f\n", x5[i], y5[i], a5[i], ea5[i] );
    }
    cout << "mc_38:" << endl;
    for (int i = 0; i < n; i++) {
        printf( " %f %f %f %f\n", x6[i], y6[i], a6[i], ea6[i] );
    }

    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    
//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

// for mc_380
    for (int i = 0; i < n; i++) {
        if ( x2[i] == -14.5 ) {
            x2[i] = 5.5;
            continue;
        }
        if ( x2[i] == -13.0 ) {
            x2[i] = 7.0;
            continue;
        }
        if ( x2[i] == -11.5 ) {
            x2[i] = 8.5;
            continue;
        }
        if ( x2[i] == -10.0 ) {
            x2[i] = 10.0;
            continue;
        }
        if ( x2[i] == -8.5 ) {
            x2[i] = 11.5;
            continue;
        }
        if ( x2[i] == -7.0 ) {
            x2[i] = 13.0;
            continue;
        }
        if ( x2[i] == -5.5 ) {
            x2[i] = 14.5;
            continue;
        }
        if ( x2[i] == -4.0 ) {
            x2[i] = 16.0;
            continue;
        }
        if ( x2[i] == -2.5 ) {
            x2[i] = 17.5;
            continue;
        }
        if ( x2[i] == -1.0 ) {
            x2[i] = 19.0;
            continue;
        }
        if ( x2[i] == 1.0 ) {
            x2[i] = 20.5;
            continue;
        }
        if ( x2[i] == 2.5 ) {
            x2[i] = 22.0;
            continue;
        }
        if ( x2[i] == 4.0 ) {
            x2[i] = 23.5;
            continue;
        }
        if ( x2[i] == 5.5 ) {
            x2[i] = 25.0;
            continue;
        }
        if ( x2[i] == 7.0 ) {
            x2[i] = 26.5;
            continue;
        }
        if ( x2[i] == 8.5 ) {
            x2[i] = 28.0;
            continue;
        }
        if ( x2[i] == 10.0 ) {
            x2[i] = 29.5;
            continue;
        }
        if ( x2[i] == 11.5 ) {
            x2[i] = 31.0;
            continue;
        }
        if ( x2[i] == 13.0 ) {
            x2[i] = 32.5;
            continue;
        }
        if ( x2[i] == 14.5 ) {
            x2[i] = 34.0;
            continue;
        }
    }

// for mc_190
    for (int i = 0; i < n; i++) {
        if ( x3[i] == -14.5 ) {
            x3[i] = 5.5;
            continue;
        }
        if ( x3[i] == -13.0 ) {
            x3[i] = 7.0;
            continue;
        }
        if ( x3[i] == -11.5 ) {
            x3[i] = 8.5;
            continue;
        }
        if ( x3[i] == -10.0 ) {
            x3[i] = 10.0;
            continue;
        }
        if ( x3[i] == -8.5 ) {
            x3[i] = 11.5;
            continue;
        }
        if ( x3[i] == -7.0 ) {
            x3[i] = 13.0;
            continue;
        }
        if ( x3[i] == -5.5 ) {
            x3[i] = 14.5;
            continue;
        }
        if ( x3[i] == -4.0 ) {
            x3[i] = 16.0;
            continue;
        }
        if ( x3[i] == -2.5 ) {
            x3[i] = 17.5;
            continue;
        }
        if ( x3[i] == -1.0 ) {
            x3[i] = 19.0;
            continue;
        }
        if ( x3[i] == 1.0 ) {
            x3[i] = 20.5;
            continue;
        }
        if ( x3[i] == 2.5 ) {
            x3[i] = 22.0;
            continue;
        }
        if ( x3[i] == 4.0 ) {
            x3[i] = 23.5;
            continue;
        }
        if ( x3[i] == 5.5 ) {
            x3[i] = 25.0;
            continue;
        }
        if ( x3[i] == 7.0 ) {
            x3[i] = 26.5;
            continue;
        }
        if ( x3[i] == 8.5 ) {
            x3[i] = 28.0;
            continue;
        }
        if ( x3[i] == 10.0 ) {
            x3[i] = 29.5;
            continue;
        }
        if ( x3[i] == 11.5 ) {
            x3[i] = 31.0;
            continue;
        }
        if ( x3[i] == 13.0 ) {
            x3[i] = 32.5;
            continue;
        }
        if ( x3[i] == 14.5 ) {
            x3[i] = 34.0;
            continue;
        }
    }

// for mc_140
    for (int i = 0; i < n; i++) {
        if ( x4[i] == -14.5 ) {
            x4[i] = 5.5;
            continue;
        }
        if ( x4[i] == -13.0 ) {
            x4[i] = 7.0;
            continue;
        }
        if ( x4[i] == -11.5 ) {
            x4[i] = 8.5;
            continue;
        }
        if ( x4[i] == -10.0 ) {
            x4[i] = 10.0;
            continue;
        }
        if ( x4[i] == -8.5 ) {
            x4[i] = 11.5;
            continue;
        }
        if ( x4[i] == -7.0 ) {
            x4[i] = 13.0;
            continue;
        }
        if ( x4[i] == -5.5 ) {
            x4[i] = 14.5;
            continue;
        }
        if ( x4[i] == -4.0 ) {
            x4[i] = 16.0;
            continue;
        }
        if ( x4[i] == -2.5 ) {
            x4[i] = 17.5;
            continue;
        }
        if ( x4[i] == -1.0 ) {
            x4[i] = 19.0;
            continue;
        }
        if ( x4[i] == 1.0 ) {
            x4[i] = 20.5;
            continue;
        }
        if ( x4[i] == 2.5 ) {
            x4[i] = 22.0;
            continue;
        }
        if ( x4[i] == 4.0 ) {
            x4[i] = 23.5;
            continue;
        }
        if ( x4[i] == 5.5 ) {
            x4[i] = 25.0;
            continue;
        }
        if ( x4[i] == 7.0 ) {
            x4[i] = 26.5;
            continue;
        }
        if ( x4[i] == 8.5 ) {
            x4[i] = 28.0;
            continue;
        }
        if ( x4[i] == 10.0 ) {
            x4[i] = 29.5;
            continue;
        }
        if ( x4[i] == 11.5 ) {
            x4[i] = 31.0;
            continue;
        }
        if ( x4[i] == 13.0 ) {
            x4[i] = 32.5;
            continue;
        }
        if ( x4[i] == 14.5 ) {
            x4[i] = 34.0;
            continue;
        }
    }

// for mc_60
    for (int i = 0; i < n; i++) {
        if ( x5[i] == -14.5 ) {
            x5[i] = 5.5;
            continue;
        }
        if ( x5[i] == -13.0 ) {
            x5[i] = 7.0;
            continue;
        }
        if ( x5[i] == -11.5 ) {
            x5[i] = 8.5;
            continue;
        }
        if ( x5[i] == -10.0 ) {
            x5[i] = 10.0;
            continue;
        }
        if ( x5[i] == -8.5 ) {
            x5[i] = 11.5;
            continue;
        }
        if ( x5[i] == -7.0 ) {
            x5[i] = 13.0;
            continue;
        }
        if ( x5[i] == -5.5 ) {
            x5[i] = 14.5;
            continue;
        }
        if ( x5[i] == -4.0 ) {
            x5[i] = 16.0;
            continue;
        }
        if ( x5[i] == -2.5 ) {
            x5[i] = 17.5;
            continue;
        }
        if ( x5[i] == -1.0 ) {
            x5[i] = 19.0;
            continue;
        }
        if ( x5[i] == 1.0 ) {
            x5[i] = 20.5;
            continue;
        }
        if ( x5[i] == 2.5 ) {
            x5[i] = 22.0;
            continue;
        }
        if ( x5[i] == 4.0 ) {
            x5[i] = 23.5;
            continue;
        }
        if ( x5[i] == 5.5 ) {
            x5[i] = 25.0;
            continue;
        }
        if ( x5[i] == 7.0 ) {
            x5[i] = 26.5;
            continue;
        }
        if ( x5[i] == 8.5 ) {
            x5[i] = 28.0;
            continue;
        }
        if ( x5[i] == 10.0 ) {
            x5[i] = 29.5;
            continue;
        }
        if ( x5[i] == 11.5 ) {
            x5[i] = 31.0;
            continue;
        }
        if ( x5[i] == 13.0 ) {
            x5[i] = 32.5;
            continue;
        }
        if ( x5[i] == 14.5 ) {
            x5[i] = 34.0;
            continue;
        }
    }

// for mc_38
    for (int i = 0; i < n; i++) {
        if ( x6[i] == -14.5 ) {
            x6[i] = 5.5;
            continue;
        }
        if ( x6[i] == -13.0 ) {
            x6[i] = 7.0;
            continue;
        }
        if ( x6[i] == -11.5 ) {
            x6[i] = 8.5;
            continue;
        }
        if ( x6[i] == -10.0 ) {
            x6[i] = 10.0;
            continue;
        }
        if ( x6[i] == -8.5 ) {
            x6[i] = 11.5;
            continue;
        }
        if ( x6[i] == -7.0 ) {
            x6[i] = 13.0;
            continue;
        }
        if ( x6[i] == -5.5 ) {
            x6[i] = 14.5;
            continue;
        }
        if ( x6[i] == -4.0 ) {
            x6[i] = 16.0;
            continue;
        }
        if ( x6[i] == -2.5 ) {
            x6[i] = 17.5;
            continue;
        }
        if ( x6[i] == -1.0 ) {
            x6[i] = 19.0;
            continue;
        }
        if ( x6[i] == 1.0 ) {
            x6[i] = 20.5;
            continue;
        }
        if ( x6[i] == 2.5 ) {
            x6[i] = 22.0;
            continue;
        }
        if ( x6[i] == 4.0 ) {
            x6[i] = 23.5;
            continue;
        }
        if ( x6[i] == 5.5 ) {
            x6[i] = 25.0;
            continue;
        }
        if ( x6[i] == 7.0 ) {
            x6[i] = 26.5;
            continue;
        }
        if ( x6[i] == 8.5 ) {
            x6[i] = 28.0;
            continue;
        }
        if ( x6[i] == 10.0 ) {
            x6[i] = 29.5;
            continue;
        }
        if ( x6[i] == 11.5 ) {
            x6[i] = 31.0;
            continue;
        }
        if ( x6[i] == 13.0 ) {
            x6[i] = 32.5;
            continue;
        }
        if ( x6[i] == 14.5 ) {
            x6[i] = 34.0;
            continue;
        }
    }

//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

// -----------------------------------------------------------------------------------------------------------------------

    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    int i4 = 0;
    int i5 = 0;
    int i6 = 0;
    
    int count1 = 0;
    printf( "DATA:\n" );
    for (int i = 0; i < n; i++) {
/*        if ( abs( y1[ i ] ) == 16.0 ) {
		printf( "%f %f %f %f\n", x1[i], y1[i], a1[i], ea1[i] );
        	count1++;
       		x1f[ i1 ] = x1[ i ];
        	a1f[ i1 ] = a1[ i ];
        	ea1f[ i1 ] = ea1[ i ];
		i1++;
	}
*/
        if ( abs( y1[ i ] ) == 17.5 ) {
		printf( "%f %f %f %f\n", x1[i], y1[i], a1[i], ea1[i] );
        	count1++;
       		x1f[ i1 ] = x1[ i ];
        	a1f[ i1 ] = a1[ i ];
        	ea1f[ i1 ] = ea1[ i ];
		i1++;
	}
    }
    printf( "count1 = %d\n", count1 );
    printf( "i1 = %d\n", i1 );
    
    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    
    int count2 = 0;
    printf( "MC_380:\n" );
    for (int i = 0; i < n; i++) {
        if ( y2[ i ] == 1.0 ) { // abs( y2[ i ] ) == 1.0
		printf( "%f %f %f %f\n", x2[i], y2[i], a2[i], ea2[i] );
        	count2++;
       		x2f[ i2 ] = x2[ i ];
        	a2f[ i2 ] = a2[ i ];
        	ea2f[ i2 ] = ea2[ i ];
		i2++;
	}
    }
    printf( "count2 = %d\n", count2 );
    printf( "i2 = %d\n", i2 );    

    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    
    int count3 = 0;
    printf( "MC_190:\n" );
    for (int i = 0; i < n; i++) {
        if ( y3[ i ] == 1.0 ) { // abs( y3[ i ] ) == 1.0
		printf( "%f %f %f %f\n", x3[i], y3[i], a3[i], ea3[i] );
        	count3++;
       		x3f[ i3 ] = x3[ i ];
        	a3f[ i3 ] = a3[ i ];
        	ea3f[ i3 ] = ea3[ i ];
		i3++;
	}
    }
    printf( "count3 = %d\n", count3 );
    printf( "i3 = %d\n", i3 );    

    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    
    int count4 = 0;
    printf( "MC_140:\n" );
    for (int i = 0; i < n; i++) {
        if ( y4[ i ] == 1.0 ) { // abs( y4[ i ] ) == 1.0
		printf( "%f %f %f %f\n", x4[i], y4[i], a4[i], ea4[i] );
        	count4++;
       		x4f[ i4 ] = x4[ i ];
        	a4f[ i4 ] = a4[ i ];
        	ea4f[ i4 ] = ea4[ i ];
		i4++;
	}
    }
    printf( "count4 = %d\n", count4 );
    printf( "i4 = %d\n", i4 );    

    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    
    int count5 = 0;
    printf( "MC_60:\n" );
    for (int i = 0; i < n; i++) {
        if ( y5[ i ] == 1.0 ) { // abs( y5[ i ] ) == 1.0
		printf( "%f %f %f %f\n", x5[i], y5[i], a5[i], ea5[i] );
        	count5++;
       		x5f[ i5 ] = x5[ i ];
        	a5f[ i5 ] = a5[ i ];
        	ea5f[ i5 ] = ea5[ i ];
		i5++;
	}
    }
    printf( "count5 = %d\n", count5 );
    printf( "i5 = %d\n", i5 );    

    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    
    int count6 = 0;
    printf( "MC_38:\n" );
    for (int i = 0; i < n; i++) {
        if ( y6[ i ] == 1.0 ) { // abs( y6[ i ] ) == 1.0
		printf( "%f %f %f %f\n", x6[i], y6[i], a6[i], ea6[i] );
        	count6++;
       		x6f[ i6 ] = x6[ i ];
        	a6f[ i6 ] = a6[ i ];
        	ea6f[ i6 ] = ea6[ i ];
		i6++;
	}
    }
    printf( "count6 = %d\n", count6 );
    printf( "i6 = %d\n", i6 );    

    printf( "\n" );
    printf( "\n" );
    printf( "\n" );

// -----------------------------------------------------------------------------------------------------------------------
/*
    int k1 = 0;
    int k2 = 0;
    
    int count1_f = 0;
    printf( "DATA_2:\n" );
    for (int i = 0; i < n2; i++) {
        if ( abs( [ i ] ) == 16.0 ) {
		printf( "%f %f %f\n", x1[i], y1[i], a1[i] );
        	count1++;
       		x1[ i1 ] = x1[ i ];
        	a1[ i1 ] = a1[ i ];
		i1++;
	}

        if ( abs( y1[ i ] ) == 17.5 ) {
		printf( "%f %f %f\n", x1[i], y1[i], a1[i] );
        	count1++;
       		x1[ i1 ] = x1[ i ];
        	a1[ i1 ] = a1[ i ];
		i1++;
	}
    }
    printf( "count1 = %d\n", count1 );
    printf( "i1 = %d\n", i1 );
    
    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    
    int count2_f = 0;
    printf( "MC_2:\n" );
    for (int i = 0; i < n2; i++) {
        if ( abs( y2[ i ] ) == 1.0 ) {
		printf( "%f %f %f\n", x2[i], y2[i], a2[i] );
        	count2++;
       		x2[ i2 ] = x2[ i ];
        	a2[ i2 ] = a2[ i ];
		i2++;
	}
    }
    printf( "count2 = %d\n", count2 );
    printf( "i2 = %d\n", i2 );   
*/
// -----------------------------------------------------------------------------------------------------------------------

    char fname[ 100 ];
    for ( int i = 0; i < 100; i++ ) fname[ i ] = 0;
    
    n2 = n2 - 21;

    cout << "data:" << endl;
    for (int i = 0; i < n2; i++) {
        printf( " %d %f %f %f\n", i + 1, x1f[i], a1f[i], ea1f[i] );
    }
    cout << "mc_380:" << endl;
    for (int i = 0; i < n2; i++) {
        printf( " %d %f %f %f\n", i + 1, x2f[i], a2f[i], ea2f[i] );
    }
    cout << "mc_190:" << endl;
    for (int i = 0; i < n2; i++) {
        printf( " %d %f %f %f\n", i + 1, x3f[i], a3f[i], ea3f[i] );
    }
    cout << "mc_140:" << endl;
    for (int i = 0; i < n2; i++) {
        printf( " %d %f %f %f\n", i + 1, x4f[i], a4f[i], ea4f[i] );
    }
    cout << "mc_60:" << endl;
    for (int i = 0; i < n2; i++) {
        printf( " %d %f %f %f\n", i + 1, x5f[i], a5f[i], ea5f[i] );
    }
    cout << "mc_38:" << endl;
    for (int i = 0; i < n2; i++) {
        printf( " %d %f %f %f\n", i + 1, x6f[i], a6f[i], ea6f[i] );
    }

    printf( "\n" );
    printf( "\n" );
    printf( "\n" );

    cout << "data:" << endl;
    for (int i = 0; i < n2; i++) {
        x1f[i] = x1f[i] - 4.5;
        printf( " %d %f %f %f\n", i + 1, x1f[i], a1f[i], ea1f[i] );
    }
    cout << "mc_380:" << endl;
    for (int i = 0; i < n2; i++) {
        x2f[i] = x2f[i] - 4.5;
        printf( " %d %f %f %f\n", i + 1, x2f[i], a2f[i], ea2f[i] );
    }
    cout << "mc_190:" << endl;
    for (int i = 0; i < n2; i++) {
        x3f[i] = x3f[i] - 4.5;
        printf( " %d %f %f %f\n", i + 1, x3f[i], a3f[i], ea3f[i] );
    }
    cout << "mc_140:" << endl;
    for (int i = 0; i < n2; i++) {
        x4f[i] = x4f[i] - 4.5;
        printf( " %d %f %f %f\n", i + 1, x4f[i], a4f[i], ea4f[i] );
    }
    cout << "mc_60:" << endl;
    for (int i = 0; i < n2; i++) {
        x5f[i] = x5f[i] - 4.5;
        printf( " %d %f %f %f\n", i + 1, x5f[i], a5f[i], ea5f[i] );
    }
    cout << "mc_38:" << endl;
    for (int i = 0; i < n2; i++) {
        x6f[i] = x6f[i] - 4.5;
        printf( " %d %f %f %f\n", i + 1, x6f[i], a6f[i], ea6f[i] );
    }

/*    Double_t chi2 = 0.0;
    Double_t chisl = 0.0;
    Double_t znam = 0.0;

    cout << "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ" << endl;
    for ( int i = 0; i < n2; i++ ) {  // n2 = 20 points

        chisl = a1f[i] - a2f[i];
        znam = sqrt( pow( ea1f[i], 2 ) + pow( ea2f[i], 2 ) );

        chi2 = chi2 + pow( ( chisl / znam ), 2 );

    }
    cout << "chi2 === " << chi2 << endl;
    cout << "chi2 / 20 === " << chi2 / 20 << endl;
    cout << "chi2 / n2 === " << chi2 / n2 << endl;

    cout << "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ" << endl;
*/    
    printf( "\n" );
    printf( "\n" );
    printf( "\n" );

    TGraphErrors *agr;
    TGraphErrors *bgr;
    TGraphErrors *cgr;
    TGraphErrors *dgr;
    TGraphErrors *egr;
    TGraphErrors *fgr;

    c1->cd();
    agr = new TGraphErrors( n2, x1f, a1f, errors_x, ea1f );
    bgr = new TGraphErrors( n2, x2f, a2f, errors_x, ea2f );
    cgr = new TGraphErrors( n2, x3f, a3f, errors_x, ea3f );
    dgr = new TGraphErrors( n2, x4f, a4f, errors_x, ea4f );
    egr = new TGraphErrors( n2, x5f, a5f, errors_x, ea5f );
    fgr = new TGraphErrors( n2, x6f, a6f, errors_x, ea6f );
    agr->GetYaxis()->SetTitle("Light yield, p.e.");
    agr->GetXaxis()->SetTitle("Position, mm");
    sprintf( fname, "BC-408, tile wrapped in foil" );
    agr->GetYaxis()->SetRangeUser(0.0, 80.0);
    agr->SetTitle(fname);

    agr->SetMarkerColor(kRed);
    agr->SetLineColor(kRed);
    agr->SetLineWidth(3);
    agr->SetFillColor(kRed);
    agr->SetMarkerStyle(20);
    agr->Draw("AP");
    
    bgr->SetMarkerColor(kBlue);
    bgr->SetLineColor(kBlue);
    bgr->SetLineWidth(3);
    bgr->SetFillColor(kBlue);
    bgr->SetMarkerStyle(20);
    bgr->Draw("P SAME");

    cgr->SetMarkerColor(kGreen);
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

    egr->SetMarkerColor(kCyan);
    egr->SetLineColor(kCyan);
    egr->SetLineWidth(3);
    egr->SetFillColor(kCyan);
    egr->SetMarkerStyle(20);
    egr->Draw("P SAME");

    fgr->SetMarkerColor(kViolet-7);
    fgr->SetLineColor(kViolet-7);
    fgr->SetLineWidth(3);
    fgr->SetFillColor(kViolet-7);
    fgr->SetMarkerStyle(20);
    fgr->Draw("P SAME");
    
    c1->Update();
   
    TLegend *lsc1 = new TLegend(0.55,0.62,0.90,0.92);
    lsc1->AddEntry(agr,"data","pl");
    lsc1->AddEntry(bgr,"mc, abs = 380 cm","pl");
    lsc1->AddEntry(cgr,"mc, abs = 190 cm","pl");
    lsc1->AddEntry(dgr,"mc, abs = 140 cm","pl");
    lsc1->AddEntry(egr,"mc, abs = 60 cm","pl");
    lsc1->AddEntry(fgr,"mc, abs = 38 cm","pl");
   
    c1->cd();
    lsc1->Draw();

}
