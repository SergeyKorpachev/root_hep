void graph_fraction1( const int fenergy = 5 ) {
   TCanvas *c1 = new TCanvas("graph1","graph1",200,10,700,500);

   //c1->SetFillColor(42);
   //gStyle->SetPalette(52);
   c1->SetGrid();
   //c1->GetFrame()->SetFillColor(21);
   //c1->GetFrame()->SetBorderSize(12);
    
   char fname[ 100 ];
   for ( int i = 0; i < 100; i++ ) fname[ i ] = 0;

   const Int_t n = 16;

   Float_t energy[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t step[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t range[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t chi[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t integral[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
   Float_t fraction[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

/*
   for (int i = 0; i < n; i++) {
     printf( " %f ", energy[i] );
     printf( " %f ", step[i] );
     printf( " %f ", range[i] );
     printf( " %f ", chi[i] );
     printf( " %f ", integral[i] );
     printf( " %f ", fraction[i] );
     printf( "\n" );
   }
*/
   sprintf( fname, "%d_out_data.txt", fenergy );
    
   FILE *file1 = fopen(fname, "r");
   if ( !(long)file1 ) return;
    
   cout << "FILE: " << fname << endl;

   for ( int i = 0; i < n; i++ ) {
    fscanf( file1, "%f %f %f %E %f %f\n", &energy[i], &step[i], &range[i], &chi[i], &integral[i], &fraction[i] );
    if ( feof( file1 ) ) break;
   }

   printf( "\n" );
   for (int i = 0; i < n; i++) {
     printf( " %f ", energy[i] );
     printf( " %f ", step[i] );
     printf( " %f ", range[i] );
     printf( " %f ", chi[i] );
     printf( " %f ", integral[i] );
     printf( " %f ", fraction[i] );
     printf( "\n" );
   }

   TGraphErrors *agr;

   char fname2[ 100 ];
   for ( int i = 0; i < 100; i++ ) fname2[ i ] = 0;

   c1->cd();
   agr = new TGraphErrors( n, fraction, chi, 0, 0 );
   agr->GetYaxis()->SetTitle("Chi^{2} / NDF");
   agr->GetXaxis()->SetTitle("Fraction");
   sprintf( fname2, "%d GeV", fenergy ); // Linearity energy resolution // Absolute energy resolution // Relative energy resolution
   agr->SetTitle(fname2);

   agr->SetMarkerColor(kBlue); // kBlue // 12
   agr->SetLineColor(kBlue);
   agr->SetLineWidth(3);
   agr->SetMarkerStyle(34); // 21
//   agr->SetMarkerSize(2);
   agr->Draw("ALP");
   c1->Update();
    
   char fname3[ 100 ];
   for ( int i = 0; i < 100; i++ ) fname3[ i ] = 0;
    
   sprintf( fname3, "fraction%d.jpg", fenergy );
   c1->SaveAs( fname3 );

//   TLegend *lsc = new TLegend(0.55,0.62,0.90,0.92);
//   lsc->AddEntry(agr,"without ANN","pl");

//   c1->cd();
//   lsc->Draw();
    
   fclose( file1 );
   delete c1;

}

void graph_fraction( ) {

//  int mass[] = { 1, 2, 3, 4, 5, 10, 15, 20, 25, 30, 40, 50, 60, 70, 80, 90 };
  int mass[] = { 5, 10, 15, 20, 25, 30, 40, 50, 60 };
  int dim = 9; // 16

  for ( int i = 0; i < dim; i++ ) {
      graph_fraction1( mass[ i ] );
  }
    
}
