
void gaus( void ) {

  float a = 0.0;
  
  for ( a = 0.1; a < 1.1; a += 0.1 ) {  
  
    float l = 30.0;
    float amp = 1.0;
    float step = 1.5;
  
    float x = 0.0;
    float y = 0.0;
    float f = 0.0;
  
    float t1 = 0.0;
    float t2 = 0.0;
    float t3 = 0.0;
  
    TH1F* hist = new TH1F("hist", "hist", 10, 0.0, 2.0);
  
    float mean = 0.0;
    float rms = 0.0;
    float uniformity = 0.0;
  
    for ( x = 0.0; x <= l; x += step ) {
      for ( y = 0.0; y <= l; y += step ) {
       
        t1 = 2.0 * a * a * l * l;
        t2 = ( x - ( 0.5 * l )  ) * ( x - ( 0.5 * l ) );
        t3 = ( y - ( 0.5 * l )  ) * ( y - ( 0.5 * l ) );
  
        f = amp * exp( -1.0 * ( ( t2 / t1 ) + ( t3 / t1 ) ) );
        hist -> Fill( f );
   
//      printf( "%f %f %f %f\n", a, x, y, f );   
       
        t1 = t2 = t3 = 0;
      }
    }

    mean = hist->GetMean();
    rms = hist->GetRMS();
    uniformity = rms / mean;
   
    printf( "%f %f\n", a, uniformity );   
   
    delete hist;
   
  }

}
