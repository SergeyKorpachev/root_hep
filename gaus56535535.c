
void gaus( float aa, float mm, float sigL ) {

  float a = 0.0;
TCanvas *c = new TCanvas("plot","plot",200,10,700,500);
    float l = 30.0;
    float amp = 1.0;
    float step = 1.5;
  
  for ( a = 0.1; a < 1.1; a += 0.1 ) {  
  
  
    float x = 0.0;
    float y = 0.0;
    float f = 0.0;
  
    float t1 = 0.0;
    float t2 = 0.0;
    float t3 = 0.0;
  
    TH1F* hist = new TH1F("hist", "hist", 1000, 0.0, 2.0);
  
    float mean = 0.0;
    float rms = 0.0;
    float uniformity = 0.0;
  
    for ( x = 0.0; x <= l; x += step ) {
      for ( y = 0.0; y <= l; y += step ) {
       
        t1 = 2.0 * a * a * l * l;
        t2 = ( x - ( 0.5 * l )  ) * ( x - ( 0.5 * l ) );
        t3 = ( y - ( 0.5 * l )  ) * ( y - ( 0.5 * l ) );
  
        f = amp * exp( -1.0 * ( ( t2 / t1 ) + ( t3 / t1 ) ) ); ///( a * l);
        hist -> Fill( f );
   
	//printf( "%f %f %f %f\n", a, x, y, f );   
       
        t1 = t2 = t3 = 0;
      }
    }

    mean = hist->GetMean();
    rms = hist->GetRMS();
    uniformity = rms / mean;
   
    printf( "%f  %f  %f\n", a, mean, uniformity );   

    //hist->DrawCopy();
   
    delete hist;
   
  }

  TRandom2 r(0);
  TH1F* h = new TH1F("h", "h", 100, 0.0, 5.0);
  TH1F* h1 = new TH1F("h1", "h1", 100, 0.0, 5.0);
  TH1F* h2 = new TH1F("h2", "h2", 100, 0.0, 5.0);

  for ( int i = 0; i < 10000; i++ ) {
    float z = r.Landau(1,sigL);
    h->Fill(z);
    
    float xx = r.Uniform(l);
    float yy = r.Uniform(l);

        float tt1 = 2.0 * aa * aa * l * l;
        float tt2 = ( xx - ( 0.5 * l )  ) * ( xx - ( 0.5 * l ) );
        float tt3 = ( yy - ( 0.5 * l )  ) * ( yy - ( 0.5 * l ) );
	float cc = exp( -1.0 * ( ( tt2 / tt1 ) + ( tt3 / tt1 ) ) ) / mm;
	h1->Fill(cc*z);
	h2->Fill(cc*z*mm);
  }
  h->DrawCopy();
  h1->SetLineColor(2);
  h1->DrawCopy("same");
  h2->SetLineColor(3);
  h2->DrawCopy("same");
  delete h;
  delete h1;
  delete h2;
}
