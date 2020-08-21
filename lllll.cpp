void lllll(){
    TFile *f = new TFile("RealData12_Znunugjj_periodA_v4.root");
    TTree *t1 = (TTree*)f->Get("tree_cutflow");

    TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);

    c1->Divide(2 , 2);
 
    UInt_t num_of_muon = 0;
    UInt_t num_of_elec = 0;
    Double_t met_pt  =0;

    t1->SetBranchAddress("num_of_muon" , &num_of_muon);
    t1->SetBranchAddress("num_of_elec" , &num_of_elec);
    t1->SetBranchAddress("met_pt", &met_pt);
 
    TH2F *hpxpy1 = new TH2F("hpxpy1"," num_of_muon  vs num_of_elec - 1",3,-0.5,2.5, 3, -0.5, 2.5);
    TH2F *hpxpy2 = new TH2F("hpxpy2"," num_of_muon  vs num_of_elec - 2",3,-0.5,2.5, 3, -0.5, 2.5);
    Int_t nentries = (Int_t)t1->GetEntries();
    for (Int_t i = 0; i < nentries; i++) {   
       t1->GetEntry(i);
       hpxpy1->Fill(num_of_muon, num_of_elec);   
       if (met_pt > 100) {
         hpxpy2->Fill(num_of_muon, num_of_elec); 
       }     
       
    }
    c1->cd(1);
    hpxpy1->Draw();
    c1->cd(2);
    hpxpy2->Draw();
}
