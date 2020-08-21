
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
#include <TF1.h>
#include <TH1F.h>
#include <TGraph.h>
#include <TStopwatch.h>
#include <TTree.h>

using namespace std;


void code()
{

   TCanvas *c1 = new TCanvas("c1", "c1", 1);

   c1->Divide(1 , 2);

   TFile *file = new TFile("flat_scint3_box15_gap01_x_z_1.5_1.5mm_e200.root");

   TH1F* hist = (TH1F *)file->Get("fCounterSipm");

   TTree* tree = (TTree *)file->Get("DRTile");

   Double_t photonsInSipm = 0;

   tree->SetBranchAddress("photonsInSipm" , &photonsInSipm);

   TH1F *h_file = new TH1F("h_file","h_file",200,0.,1600.);

//   Double_t xmin = tree->GetMinimum();
 //  xmin = 0;
  
 //  Double width = tree->GetLineWidth();
 //  width = 0;

   Double_t x = 0;

   Int_t nentries = (Int_t)tree->GetEntries();

   for (int i= 0 ;i < nentries ; i++)
   {
      Double_t x = tree->GetEntry(i);
      x += gRandom->Gaus(0.,3.);
      h_file->Fill(x);
   } 
 
   c1->cd(1);

   hist->GetYaxis()->SetTitle("Number of events");
   hist->GetXaxis()->SetTitle("Number of photons");
   hist->Draw();

   c1->cd(2); 

   h_file->SetTitle("Number of photons in SIPM (Convolution)");
   h_file->GetYaxis()->SetTitle("Number of events");
   h_file->GetXaxis()->SetTitle("Number of photons");
   h_file->Draw();

}
