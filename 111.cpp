
#include <stdio.h>
#include <TMath.h>
#include <TCanvas.h>
#include <iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TObject.h>
#include <TRandom.h>
#include <TFile.h>
#include <math.h>
#include <TF1Convolution.h>
#include <TF1.h>
#include <TH1F.h>
#include <TGraph.h>
#include <TStopwatch.h>


using namespace std;


void 111()
{

   TFile *file = new TFile("flat_scint3_box15_gap01_x_z_1.5_1.5mm_e200.root");

   TH1F* hist = (TH1F *)file->Get("fCounterSipm");

   TH1F *h_file = new TH1F("h_file","h_file",200,0.,1600.);

   Int_t nentries = (Int_t)hist->GetEntries();

   for (int i=0;i < nentries; i++)
   {
      Double_t x = hist->GetBinContent();
      x += gRandom->Gaus(0.,3.);
      h_file->Fill(x);
   }

   TF1Convolution *f_conv = new TF1Convolution("fCounterSipm","gaus",0.,1600.,true);
   f_conv->SetRange(0.,1600.);
  // f_conv->SetNofPointsFFT(1000);
   TF1   *f = new TF1("f",*f_conv, 0., 1600., f_conv->GetNpar());
   f->SetParameters(1.,-0.3,0.,1.);
   

   new TCanvas("c","c",800,1000);
   h_ExpGauss -> Fit("f");
   h_ExpGauss->Draw();
  
}
