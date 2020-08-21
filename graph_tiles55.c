void graph_tiles55() {
    TCanvas *c1 = new TCanvas("plot","plot",200,10,700,500);
    c1->SetGrid();

//////////////////////////////////////////////////// 1 = data, 2 = 380, 3 = 190, 4 = 140, 5 = 60, 6 = 38 /////////////////////////////////////////////////////////////
//////////////////////////////////////////////////// 2 = 60 big trigger, 3 = 60 small trigger /////////////////////////////////////////////////////////////

    const Int_t n = 1296;
    Int_t n2 = 75;

    Float_t x2[n];
    Float_t y2[n];
    Float_t a2[n];
    Float_t ea2[n];

    Float_t x3[n];
    Float_t y3[n];
    Float_t a3[n];
    Float_t ea3[n];
    

    Float_t x2f[n2];
    Float_t a2f[n2];
    Float_t ea2f[n2];

    Float_t x3f[n2];
    Float_t a3f[n2];
    Float_t ea3f[n2];
    

    Float_t errors[n2];
    Float_t errors_x[n2];
    

    for ( int i = 0; i < n; i++ ) x2[ i ] = 0;
    for ( int i = 0; i < n; i++ ) y2[ i ] = 0;
    for ( int i = 0; i < n; i++ ) a2[ i ] = 0;
    for ( int i = 0; i < n; i++ ) ea2[ i ] = 0;

    for ( int i = 0; i < n; i++ ) x3[ i ] = 0;
    for ( int i = 0; i < n; i++ ) y3[ i ] = 0;
    for ( int i = 0; i < n; i++ ) a3[ i ] = 0;
    for ( int i = 0; i < n; i++ ) ea3[ i ] = 0;


    for ( int i = 0; i < n2; i++ ) x2f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) a2f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) ea2f[ i ] = 0;

    for ( int i = 0; i < n2; i++ ) x3f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) a3f[ i ] = 0;
    for ( int i = 0; i < n2; i++ ) ea3f[ i ] = 0;


    for ( int i = 0; i < n2; i++ ) errors[ i ] = 0.0;
    for ( int i = 0; i < n2; i++ ) errors_x[ i ] = 0.75; // sqrt(1.5);
    
    FILE *file2 = fopen("mc_60_bt.txt", "r");
    if ( !(long)file2 ) return;

    FILE *file3 = fopen("mc_60_st.txt", "r");
    if ( !(long)file3 ) return;

    for ( int i = 0; i < n; i++ ) {
        fscanf( file2, "%f %f %f %f\n", &x2[i], &y2[i], &a2[i], &ea2[i]);
        if ( feof( file2 ) ) break;
    }
    for ( int i = 0; i < n; i++ ) {
        fscanf( file3, "%f %f %f %f\n", &x3[i], &y3[i], &a3[i], &ea3[i]);
        if ( feof( file3 ) ) break;
    }

    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    
    cout << "mc_60_bt:" << endl;
    for (int i = 0; i < n; i++) {
        printf( " %f %f %f %f\n", x2[i], y2[i], a2[i], ea2[i] );
    }
    cout << "mc_60_st:" << endl;
    for (int i = 0; i < n; i++) {
        printf( " %f %f %f %f\n", x3[i], y3[i], a3[i], ea3[i] );
    }

    printf( "\n" );
    printf( "\n" );
    printf( "\n" );

    int i2 = 0;
    int i3 = 0;
    
    printf( "\n" );
    printf( "\n" );
    printf( "\n" );
    
    int count2 = 0;
    printf( "MC_60_BT:\n" );
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
    printf( "MC_60_ST:\n" );
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

    char fname[ 100 ];
    for ( int i = 0; i < 100; i++ ) fname[ i ] = 0;
    
    n2 = n2 - 39;

    cout << "mc_60_bt:" << endl;
    for (int i = 0; i < n2; i++) {
        printf( " %d %f %f %f\n", i + 1, x2f[i], a2f[i], ea2f[i] );
    }
    cout << "mc_60_st:" << endl;
    for (int i = 0; i < n2; i++) {
        printf( " %d %f %f %f\n", i + 1, x3f[i], a3f[i], ea3f[i] );
    }

    printf( "\n" );
    printf( "\n" );
    printf( "\n" );

    cout << "mc_60_bt:" << endl;
    for (int i = 0; i < n2; i++) {
        x2f[i] = x2f[i] + 27.5;
        printf( " %d %f %f %f\n", i + 1, x2f[i], a2f[i], ea2f[i] );
    }
    cout << "mc_60_st:" << endl;
    for (int i = 0; i < n2; i++) {
        x3f[i] = x3f[i] + 27.5;
        printf( " %d %f %f %f\n", i + 1, x3f[i], a3f[i], ea3f[i] );
    }
  
    printf( "\n" );
    printf( "\n" );
    printf( "\n" );

    TGraphErrors *agr;
    TGraphErrors *bgr;

    c1->cd();
    agr = new TGraphErrors( n2, x2f, a2f, errors_x, ea2f );
    bgr = new TGraphErrors( n2, x3f, a3f, errors_x, ea3f );
    agr->GetYaxis()->SetTitle("Light yield, p.e.");
    agr->GetXaxis()->SetTitle("Position, mm");
    sprintf( fname, "BC-408, tile wrapped in foil, 55 mm" );
    agr->GetYaxis()->SetRangeUser(0.0, 30.0);
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

    c1->Update();
   
    TLegend *lsc1 = new TLegend(0.55,0.62,0.90,0.92);
    lsc1->AddEntry(agr,"mc, abs = 60 cm, bt","pl");
    lsc1->AddEntry(bgr,"mc, abs = 60 cm, st","pl");
   
    c1->cd();
    lsc1->Draw();

}
