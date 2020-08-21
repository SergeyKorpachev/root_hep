void plot( void ) {

  TCanvas *c = new TCanvas("plot","plot",200,10,700,500);

  const int n = 8;

  float a[ n ] = { 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 };
  float s[ n ] = { 0.503526, 0.690554, 0.793196, 0.846576, 0.884059, 0.90816, 0.92675, 0.946129 };

  TGraph *g = new TGraph( n, a, s );
  g -> SetLineColor(2);
  g -> SetLineWidth(4);
  g -> SetMarkerColor(4);
  g -> SetMarkerStyle(21);
//  g -> SetTitle("a simple graph");
  g -> GetXaxis()->SetTitle("alpha");
  g -> GetYaxis()->SetTitle("ratio");
  g -> Draw("ACP");

//  c->Update();
//  c->GetFrame()->SetFillColor(21);
//  c->GetFrame()->SetBorderSize(12);
//  c->Modified();
}

