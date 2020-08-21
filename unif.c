void unif() {
  const char *AMP = "results_ped.txt";
   
  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);
  TCanvas *c2 = new TCanvas("c2", "c2", 600, 600);
 
  TH1F* uniformity = new TH1F("Uniformity", "Uniformity", 100, 0, 5);
  TH1F* uniformity2 = new TH1F("Uniformity2", "Uniformity2", 100, 0, 5);

  float amp, amp2;
  FILE *file_amp = fopen(AMP, "r");  
  
  if (!((long)file_amp)) return;

  while(1) {
    float t1 = 0.0;
    float t2 = 0.0;
    fscanf(file_amp, "%f %f %f %f", &amp, &amp2, &t1, &t2);
    if (feof(file_amp)) break;

    printf("%f %f %f %f\n", amp, amp2, t1, t2);

    uniformity->Fill( amp );
    uniformity2->Fill( amp2 );
  }
 
  float mean_uniformity = uniformity->GetMean();
  float rms_uniformity = uniformity->GetRMS();
  printf("Uniformity === %f / %f === %f\n", rms_uniformity, mean_uniformity, rms_uniformity / mean_uniformity );
  printf("Number of values === %f\n", float( uniformity->GetEntries() ) );

  float mean_uniformity2 = uniformity2->GetMean();
  float rms_uniformity2 = uniformity2->GetRMS();
  printf("Uniformity2 === %f / %f === %f\n", rms_uniformity2, mean_uniformity2, rms_uniformity2 / mean_uniformity2 );
  printf("Number of values === %f\n", float( uniformity2->GetEntries() ) );

//  gStyle->SetOptStat(0);

  c1->cd();

  uniformity->GetXaxis()->SetTitle("pedestal p.e.");
  uniformity->GetYaxis()->SetTitle("number of events");
  uniformity->Draw();

  c2->cd();
  
  uniformity2->GetXaxis()->SetTitle("pedestal p.e.");
  uniformity2->GetYaxis()->SetTitle("number of events");
  uniformity2->Draw();
 
//  c1->SaveAs("final.jpg");
  
}
