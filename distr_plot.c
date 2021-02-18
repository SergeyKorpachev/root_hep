void distr_plot(const int fenergy = 5) {
    
    char name[200];

//    int nenergies = 2;

//    int ntemp = 0;

/*    Float_t a_energy[ nenergies ] = {  ,  };
    Float_t a_eecal[ nenergies ] = {  ,  };
    Float_t a_ehcal[ nenergies ] = {  ,  };
    Float_t a_pfo_energy[ nenergies ] = {  ,  };
    Float_t a_mc_energy[ nenergies ] = {  ,  };
//    Int_t a_nhits[ nenergies ] = {  ,  };
    Int_t a_nhits_ecal[ nenergies ] = {  ,  };
    Int_t a_nhits_hcal[ nenergies ] = {  ,  };
//    Float_t a_time[ nenergies ] = {  ,  };
    Float_t a_etime[ nenergies ] = {  ,  };
    Float_t a_htime[ nenergies ] = {  ,  };
//    Float_t a_radius[ nenergies ] = {  ,  };
    Float_t a_eradius[ nenergies ] = {  ,  };
    Float_t a_hradius[ nenergies ] = {  ,  };
    Float_t a_elayer[ nenergies ] = {  ,  };
    Float_t a_hlayer[ nenergies ] = {  ,  };
//    Float_t a_energy_hit[ nenergies ] = {  ,  };
    Float_t a_energy_hit_ecal[ nenergies ] = {  ,  };
    Float_t a_energy_hit_hcal[ nenergies ] = {  ,  };
    Float_t a_muon_energy[ nenergies ] = {  ,  };
    Float_t a_muon_energy_hit[ nenergies ] = {  ,  };
    Int_t a_muon_nhits[ nenergies ] = {  ,  };
    Float_t a_muon_time[ nenergies ] = {  ,  };
    Float_t a_muon_layer[ nenergies ] = {  ,  };
*/
    for (int i = 0; i < 200; i++) name[i] = 0;

    sprintf(name, "./data/gun_k0L_%dgev_FTFP_BERT_5000evt_ILD_l5_v02steel.root", fenergy);
    
    const char *fname = name;
    
    TCanvas *c_energy = new TCanvas("c_energy","c_energy",1);
    TCanvas *c_eecal = new TCanvas("c_eecal","c_eecal",1);
    TCanvas *c_ehcal = new TCanvas("c_ehcal","c_ehcal",1);
    TCanvas *c_pfo_energy = new TCanvas("c_pfo_energy","c_pfo_energy",1);
    TCanvas *c_mc_energy = new TCanvas("c_mc_energy","c_mc_energy",1);
//    TCanvas *c_nhits = new TCanvas("c_nhits","c_nhits",1);
    TCanvas *c_nhits_ecal = new TCanvas("c_nhits_ecal","c_nhits_ecal",1);
    TCanvas *c_nhits_hcal = new TCanvas("c_nhits_hcal","c_nhits_hcal",1);
//    TCanvas *c_time = new TCanvas("c_time","c_time",1);
    TCanvas *c_etime = new TCanvas("c_etime","c_etime",1);
    TCanvas *c_htime = new TCanvas("c_htime","c_htime",1);
//    TCanvas *c_radius = new TCanvas("c_radius","c_radius",1);
    TCanvas *c_eradius = new TCanvas("c_eradius","c_eradius",1);
    TCanvas *c_hradius = new TCanvas("c_hradius","c_hradius",1);
    TCanvas *c_elayer = new TCanvas("c_elayer","c_elayer",1);
    TCanvas *c_hlayer = new TCanvas("c_hlayer","c_hlayer",1);
//    TCanvas *c_energy_hit = new TCanvas("c_energy_hit","c_energy_hit",1);
    TCanvas *c_energy_hit_ecal = new TCanvas("c_energy_hit_ecal","c_energy_hit_ecal",1);
    TCanvas *c_energy_hit_hcal = new TCanvas("c_energy_hit_hcal","c_energy_hit_hcal",1);
    TCanvas *c_muon_energy = new TCanvas("c_muon_energy","c_muon_energy",1);
    TCanvas *c_muon_energy_hit = new TCanvas("c_muon_energy_hit","c_muon_energy_hit",1);
    TCanvas *c_muon_nhits = new TCanvas("c_muon_nhits","c_muon_nhits",1);
    TCanvas *c_muon_time = new TCanvas("c_muon_time","c_muon_time",1);
    TCanvas *c_muon_layer = new TCanvas("c_muon_layer","c_muon_layer",1);
    
    gStyle->SetOptStat(1110); // 110001110
/*
switch ( fenergy ) {
case 5:
  ntemp = 0;
  break;
case 90:
  ntemp = 1;
  break;
}*/

    const char *treeName = "tree";
    const int nBins = 135;
    
    const float binLo_energy = 0.0; // 0.0 for all energies
    const float binHi_energy = 20.0; // 7.0 for 1 GeV, 20.0 for 5 GeV, 36.0 for 20 GeV, 60.0 for 40 GeV, 120.0 for 90 GeV, 160.0 for 120 GeV
    
    const float binLo_eecal = 0.0; // 0.0 for all energies
    const float binHi_eecal = 16.0; // 16.0 for 5 GeV, 100.0 for 90 GeV
    
    const float binLo_ehcal = 0.0; // 0.0 for all energies
    const float binHi_ehcal = 14.0; // 14.0 for 5 GeV, 120.0 for 90 GeV
    
    const float binLo_pfo_energy = 0.0; // 0.0 for all energies
    const float binHi_pfo_energy = 19.0; // 19.0 for 5 GeV, 140.0 for 90 GeV
    
    const float binLo_mc_energy = 4.98; // 4.98 for 5 GeV, 89.3 for 90 GeV
    const float binHi_mc_energy = 5.07; // 5.07 for 5 GeV, 90.7 for 90 GeV
    
//    const float binLo_nhits = 0.0; // !!!!! 0.0 for all energies
//    const float binHi_nhits = 220.0; // !!!!! 16.0 for 5 GeV, 100.0 for 90 GeV
    
    const float binLo_nhits_ecal = 0.0; // 0.0 for all energies
    const float binHi_nhits_ecal = 225.0; // 225.0 for 5 GeV, 2000.0 for 90 GeV
    
    const float binLo_nhits_hcal = 0.0; // 0.0 for all energies
    const float binHi_nhits_hcal = 135.0; // 135.0 for 5 GeV, 1300.0 for 90 GeV
    
//    const float binLo_time = 0.0; // !!!!! 0.0 for all energies
//    const float binHi_time = 21.0; // !!!!! 16.0 for 5 GeV, 100.0 for 90 GeV
    
    const float binLo_etime = 0.0; // 0.0 for all energies
    const float binHi_etime = 110.0; // 110.0 for 5 GeV, 110.0 for 90 GeV
    
    const float binLo_htime = 0.0; // 0.0 for all energies
    const float binHi_htime = 110.0; // 110.0 for 5 GeV, 110.0 for 90 GeV
    
//    const float binLo_radius = 0.0; // !!!!! 0.0 for all energies
//    const float binHi_radius = 21.0; // !!!!! 16.0 for 5 GeV, 100.0 for 90 GeV
    
    const float binLo_eradius = 0.0; // 0.0 for all energies
    const float binHi_eradius = 3500.0; // 3500.0 for 5 GeV, 3500.0 for 90 GeV
    
    const float binLo_hradius = 0.0; // 0.0 for all energies
    const float binHi_hradius = 3500.0; // 3500.0 for 5 GeV, 900.0 for 90 GeV
    
    const float binLo_elayer = 0.0; // 0.0 for all energies
    const float binHi_elayer = 32.0; // 32.0 for 5 GeV, 32.0 for 90 GeV
    
    const float binLo_hlayer = 0.0; // 0.0 for all energies
    const float binHi_hlayer = 50.0; // 50.0 for 5 GeV, 50.0 for 90 GeV
    
//    const float binLo_energy_hit = 0.0; !!!!! // 0.0 for all energies
//    const float binHi_energy_hit = 21.0; !!!!! // 16.0 for 5 GeV, 100.0 for 90 GeV
    
    const float binLo_energy_hit_ecal = 0.0; // 0.0 for all energies
    const float binHi_energy_hit_ecal = 3.0; // 3.0 for 5 GeV, 3.0 for 90 GeV
    
    const float binLo_energy_hit_hcal = 0.0; // 0.0 for all energies
    const float binHi_energy_hit_hcal = 1.0; // 1.0 for 5 GeV, 1.0 for 90 GeV
    
    const float binLo_muon_energy = 0.0; // 0.0 for all energies
    const float binHi_muon_energy = 11.0; // 11.0 for 5 GeV, 80.0 for 90 GeV
    
    const float binLo_muon_energy_hit = 0.0; // 0.0 for all energies
    const float binHi_muon_energy_hit = 2.0; // 2.0 for 5 GeV, 2.0 for 90 GeV
    
    const float binLo_muon_nhits = 0.0; // 0.0 for all energies
    const float binHi_muon_nhits = 40.0; // 40.0 for 5 GeV, 450.0 for 90 GeV
    
    const float binLo_muon_time = 0.0; // 0.0 for all energies
    const float binHi_muon_time = 110.0; // 110.0 for 5 GeV, 110.0 for 90 GeV
    
    const float binLo_muon_layer = 0.0; // 0.0 for all energies
    const float binHi_muon_layer = 15.0; // 15.0 for 5 GeV, 15.0 for 90 GeV
 
    std::cout << "Trying to open file... ";
    TFile *file = new TFile(fname, "READ");
    if (!file) {
        std::cout << "[FAIL]" << std::endl;
        return;
    }
    std::cout << "[OK]" << std::endl;

    std::cout << "Setup a tree... ";
    TTree *tree = (TTree *)file->Get(treeName);
    TH1F *hist = (TH1F *)file->Get("fCounterSipm");
    if (!tree) {
        std::cout << "[FAIL]" << std::endl;
        file->Close();
        return;
    }
    std::cout << "[OK]" << std::endl;
    unsigned int nEvents = tree->GetEntries();

    Float_t energy = 0;
    Float_t eecal = 0;
    Float_t ehcal = 0;
    Float_t pfo_energy = 0;
    Float_t mc_energy = 0;
//    Int_t nhits = 0;
    Int_t nhits_ecal = 0;
    Int_t nhits_hcal = 0;
//    Float_t time = 0;
    Float_t etime = 0;
    Float_t htime = 0;
//    Float_t radius = 0;
    Float_t eradius = 0;
    Float_t hradius = 0;
    Float_t elayer = 0;
    Float_t hlayer = 0;
//    Float_t energy_hit = 0;
    Float_t energy_hit_ecal = 0;
    Float_t energy_hit_hcal = 0;
    Float_t muon_energy = 0;
    Float_t muon_energy_hit = 0;
    Int_t muon_nhits = 0;
    Float_t muon_time = 0;
    Float_t muon_layer = 0;
    
    tree->SetBranchAddress("energy", &energy);
    tree->SetBranchAddress("eecal", &eecal);
    tree->SetBranchAddress("ehcal", &ehcal);
    tree->SetBranchAddress("pfo_energy", &pfo_energy);
    tree->SetBranchAddress("mc_energy", &mc_energy);
//    tree->SetBranchAddress("nhits", &nhits);
    tree->SetBranchAddress("nhits_ecal", &nhits_ecal);
    tree->SetBranchAddress("nhits_hcal", &nhits_hcal);
//    tree->SetBranchAddress("time", &time);
    tree->SetBranchAddress("etime", &etime);
    tree->SetBranchAddress("htime", &htime);
//    tree->SetBranchAddress("radius", &radius);
    tree->SetBranchAddress("eradius", &eradius);
    tree->SetBranchAddress("hradius", &hradius);
    tree->SetBranchAddress("elayer", &elayer);
    tree->SetBranchAddress("hlayer", &hlayer);
//    tree->SetBranchAddress("energy_hit", &energy_hit);
    tree->SetBranchAddress("energy_hit_ecal", &energy_hit_ecal);
    tree->SetBranchAddress("energy_hit_hcal", &energy_hit_hcal);
    tree->SetBranchAddress("muon_energy", &muon_energy);
    tree->SetBranchAddress("muon_energy_hit", &muon_energy_hit);
    tree->SetBranchAddress("muon_nhits", &muon_nhits);
    tree->SetBranchAddress("muon_time", &muon_time);
    tree->SetBranchAddress("muon_layer", &muon_layer);

    TH1F *h_energy = new TH1F("h_energy", "Reconstructed energy for 5 GeV", nBins, binLo_energy, binHi_energy);
    TH1F *h_eecal = new TH1F("h_eecal", "Reconstructed energy in ecal for 5 GeV", nBins, binLo_eecal, binHi_eecal);
    TH1F *h_ehcal = new TH1F("h_ehcal", "Reconstructed energy in hcal for 5 GeV", nBins, binLo_ehcal, binHi_ehcal);
    TH1F *h_pfo_energy = new TH1F("h_pfo_energy", "PFO energy for 5 GeV", nBins, binLo_pfo_energy, binHi_pfo_energy);
    TH1F *h_mc_energy = new TH1F("h_mc_energy", "Energy from Particle Gun for 5 GeV", nBins, binLo_mc_energy, binHi_mc_energy);
//    TH1F *h_nhits = new TH1F("h_nhits", "Number of hits for 5 GeV", nBins, binLo_nhits, binHi_nhits);
    TH1F *h_nhits_ecal = new TH1F("h_nhits_ecal", "Number of hits in ecal for 5 GeV", nBins, binLo_nhits_ecal, binHi_nhits_ecal);
    TH1F *h_nhits_hcal = new TH1F("h_nhits_hcal", "Number of hits in hcal for 5 GeV", nBins, binLo_nhits_hcal, binHi_nhits_hcal);
//    TH1F *h_time = new TH1F("h_time", "Average time of hits for 5 GeV", nBins, binLo_time, binHi_time);
    TH1F *h_etime = new TH1F("h_etime", "Average time of hits in ecal for 5 GeV", nBins, binLo_etime, binHi_etime);
    TH1F *h_htime = new TH1F("h_htime", "Average time of hits in hcal for 5 GeV", nBins, binLo_htime, binHi_htime);
//    TH1F *h_radius = new TH1F("h_radius", "Radius of shower for 5 GeV", nBins, binLo_radius, binHi_radius);
    TH1F *h_eradius = new TH1F("h_eradius", "Radius of shower in ecal for 5 GeV", nBins, binLo_eradius, binHi_eradius);
    TH1F *h_hradius = new TH1F("h_hradius", "Radius of shower in hcal for 5 GeV", nBins, binLo_hradius, binHi_hradius);
    TH1F *h_elayer = new TH1F("h_elayer", "Average number of layers in ecal for 5 GeV", nBins, binLo_elayer, binHi_elayer);
    TH1F *h_hlayer = new TH1F("h_hlayer", "Average number of layers in hcal for 5 GeV", nBins, binLo_hlayer, binHi_hlayer);
//    TH1F *h_energy_hit = new TH1F("h_energy_hit", "Average energy of hits for 5 GeV", nBins, binLo_energy_hit, binHi_energy_hit);
    TH1F *h_energy_hit_ecal = new TH1F("h_energy_hit_ecal", "Average energy of hits in ecal for 5 GeV", nBins, binLo_energy_hit_ecal, binHi_energy_hit_ecal);
    TH1F *h_energy_hit_hcal = new TH1F("h_energy_hit_hcal", "Average energy of hits in hcal for 5 GeV", nBins, binLo_energy_hit_hcal, binHi_energy_hit_hcal);
    TH1F *h_muon_energy = new TH1F("h_muon_energy", "Reconstructed energy im muon system for 5 GeV", nBins, binLo_muon_energy, binHi_muon_energy);
    TH1F *h_muon_energy_hit = new TH1F("h_muon_energy_hit", "Average energy of hits in muon system for 5 GeV", nBins, binLo_muon_energy_hit, binHi_muon_energy_hit);
    TH1F *h_muon_nhits = new TH1F("h_muon_nhits", "Number of hits in muon system for 5 GeV", nBins, binLo_muon_nhits, binHi_muon_nhits);
    TH1F *h_muon_time = new TH1F("h_muon_time", "Average time of hits in muon system for 5 GeV", nBins, binLo_muon_time, binHi_muon_time);
    TH1F *h_muon_layer = new TH1F("h_muon_layer", "Average number of layers in muon system for 5 GeV", nBins, binLo_muon_layer, binHi_muon_layer);

    for (unsigned int i = 0; i < nEvents; i++) {
        tree->GetEntry(i);
        h_energy->Fill(energy);
        h_eecal->Fill(eecal);
        h_ehcal->Fill(ehcal);
        h_pfo_energy->Fill(pfo_energy);
        h_mc_energy->Fill(mc_energy);
//        h_nhits->Fill(nhits);
        h_nhits_ecal->Fill(nhits_ecal);
        h_nhits_hcal->Fill(nhits_hcal);
//        h_time->Fill(time);
        h_etime->Fill(etime);
        h_htime->Fill(htime);
//        h_radius->Fill(radius);
        h_eradius->Fill(eradius);
        h_hradius->Fill(hradius);
        h_elayer->Fill(elayer);
        h_hlayer->Fill(hlayer);
//        h_energy_hit->Fill(energy_hit);
        h_energy_hit_ecal->Fill(energy_hit_ecal);
        h_energy_hit_hcal->Fill(energy_hit_hcal);
        h_muon_energy->Fill(muon_energy);
        h_muon_energy_hit->Fill(muon_energy_hit);
        h_muon_nhits->Fill(muon_nhits);
        h_muon_time->Fill(muon_time);
        h_muon_layer->Fill(muon_layer);
    }
    
    cout << "Underflow h_energy === " << h_energy->GetBinContent(0) << endl;
    cout << "Overflow h_energy === " << h_energy->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_eecal === " << h_eecal->GetBinContent(0) << endl;
    cout << "Overflow h_eecal === " << h_eecal->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_ehcal === " << h_ehcal->GetBinContent(0) << endl;
    cout << "Overflow h_ehcal === " << h_ehcal->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_pfo_energy === " << h_pfo_energy->GetBinContent(0) << endl;
    cout << "Overflow h_pfo_energy === " << h_pfo_energy->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_mc_energy === " << h_mc_energy->GetBinContent(0) << endl;
    cout << "Overflow h_mc_energy === " << h_mc_energy->GetBinContent(nBins + 1) << endl;
    
//    cout << "Underflow h_nhits === " << h_nhits->GetBinContent(0) << endl;
//    cout << "Overflow h_nhits === " << h_nhits->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_nhits_ecal === " << h_nhits_ecal->GetBinContent(0) << endl;
    cout << "Overflow h_nhits_ecal === " << h_nhits_ecal->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_nhits_hcal === " << h_nhits_hcal->GetBinContent(0) << endl;
    cout << "Overflow h_nhits_hcal === " << h_nhits_hcal->GetBinContent(nBins + 1) << endl;
    
//    cout << "Underflow h_time === " << h_time->GetBinContent(0) << endl;
//    cout << "Overflow h_time === " << h_time->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_etime === " << h_etime->GetBinContent(0) << endl;
    cout << "Overflow h_etime === " << h_etime->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_htime === " << h_htime->GetBinContent(0) << endl;
    cout << "Overflow h_htime === " << h_htime->GetBinContent(nBins + 1) << endl;
    
//    cout << "Underflow h_radius === " << h_radius->GetBinContent(0) << endl;
//    cout << "Overflow h_radius === " << h_radius->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_eradius === " << h_eradius->GetBinContent(0) << endl;
    cout << "Overflow h_eradius === " << h_eradius->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_hradius === " << h_hradius->GetBinContent(0) << endl;
    cout << "Overflow h_hradius === " << h_hradius->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_elayer === " << h_elayer->GetBinContent(0) << endl;
    cout << "Overflow h_elayer === " << h_elayer->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_hlayer === " << h_hlayer->GetBinContent(0) << endl;
    cout << "Overflow h_hlayer === " << h_hlayer->GetBinContent(nBins + 1) << endl;
    
//    cout << "Underflow h_energy_hit === " << h_energy_hit->GetBinContent(0) << endl;
//    cout << "Overflow h_energy_hit === " << h_energy_hit->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_energy_hit_ecal === " << h_energy_hit_ecal->GetBinContent(0) << endl;
    cout << "Overflow h_energy_hit_ecal === " << h_energy_hit_ecal->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_energy_hit_hcal === " << h_energy_hit_hcal->GetBinContent(0) << endl;
    cout << "Overflow h_energy_hit_hcal === " << h_energy_hit_hcal->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_muon_energy === " << h_muon_energy->GetBinContent(0) << endl;
    cout << "Overflow h_muon_energy === " << h_muon_energy->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_muon_energy_hit === " << h_muon_energy_hit->GetBinContent(0) << endl;
    cout << "Overflow h_muon_energy_hit === " << h_muon_energy_hit->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_muon_nhits === " << h_muon_nhits->GetBinContent(0) << endl;
    cout << "Overflow h_muon_nhits === " << h_muon_nhits->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_muon_time === " << h_muon_time->GetBinContent(0) << endl;
    cout << "Overflow h_muon_time === " << h_muon_time->GetBinContent(nBins + 1) << endl;
    
    cout << "Underflow h_muon_layer === " << h_muon_layer->GetBinContent(0) << endl;
    cout << "Overflow h_muon_layer === " << h_muon_layer->GetBinContent(nBins + 1) << endl;
    
    h_energy->GetXaxis()->SetTitle("E_{reco}, GeV");
    h_energy->GetYaxis()->SetTitle("Number of events");
    h_energy->GetYaxis()->SetLabelSize(0.038);
    h_energy->GetXaxis()->SetLabelSize(0.038);
    h_energy->GetYaxis()->SetTitleSize(0.038);
    h_energy->GetXaxis()->SetTitleSize(0.038);
    
    h_eecal->GetXaxis()->SetTitle("E_{reco}, GeV");
    h_eecal->GetYaxis()->SetTitle("Number of events");
    h_eecal->GetYaxis()->SetLabelSize(0.038);
    h_eecal->GetXaxis()->SetLabelSize(0.038);
    h_eecal->GetYaxis()->SetTitleSize(0.038);
    h_eecal->GetXaxis()->SetTitleSize(0.038);
    
    h_ehcal->GetXaxis()->SetTitle("E_{reco}, GeV");
    h_ehcal->GetYaxis()->SetTitle("Number of events");
    h_ehcal->GetYaxis()->SetLabelSize(0.038);
    h_ehcal->GetXaxis()->SetLabelSize(0.038);
    h_ehcal->GetYaxis()->SetTitleSize(0.038);
    h_ehcal->GetXaxis()->SetTitleSize(0.038);
    
    h_pfo_energy->GetXaxis()->SetTitle("E_{pfo}, GeV");
    h_pfo_energy->GetYaxis()->SetTitle("Number of events");
    h_pfo_energy->GetYaxis()->SetLabelSize(0.038);
    h_pfo_energy->GetXaxis()->SetLabelSize(0.038);
    h_pfo_energy->GetYaxis()->SetTitleSize(0.038);
    h_pfo_energy->GetXaxis()->SetTitleSize(0.038);
    
    h_mc_energy->GetXaxis()->SetTitle("E_{true}, GeV");
    h_mc_energy->GetYaxis()->SetTitle("Number of events");
    h_mc_energy->GetYaxis()->SetLabelSize(0.038);
    h_mc_energy->GetXaxis()->SetLabelSize(0.038);
    h_mc_energy->GetYaxis()->SetTitleSize(0.038);
    h_mc_energy->GetXaxis()->SetTitleSize(0.038);
    
//    h_nhits->GetXaxis()->SetTitle("Number of hits");
//    h_nhits->GetYaxis()->SetTitle("Number of events");
//    h_nhits->GetYaxis()->SetLabelSize(0.038);
//    h_nhits->GetXaxis()->SetLabelSize(0.038);
//    h_nhits->GetYaxis()->SetTitleSize(0.038);
//    h_nhits->GetXaxis()->SetTitleSize(0.038);
    
    h_nhits_ecal->GetXaxis()->SetTitle("Number of hits");
    h_nhits_ecal->GetYaxis()->SetTitle("Number of events");
    h_nhits_ecal->GetYaxis()->SetLabelSize(0.038);
    h_nhits_ecal->GetXaxis()->SetLabelSize(0.038);
    h_nhits_ecal->GetYaxis()->SetTitleSize(0.038);
    h_nhits_ecal->GetXaxis()->SetTitleSize(0.038);
    
    h_nhits_hcal->GetXaxis()->SetTitle("Number of hits");
    h_nhits_hcal->GetYaxis()->SetTitle("Number of events");
    h_nhits_hcal->GetYaxis()->SetLabelSize(0.038);
    h_nhits_hcal->GetXaxis()->SetLabelSize(0.038);
    h_nhits_hcal->GetYaxis()->SetTitleSize(0.038);
    h_nhits_hcal->GetXaxis()->SetTitleSize(0.038);
    
//    h_time->GetXaxis()->SetTitle("Mean hit time, ns");
//    h_time->GetYaxis()->SetTitle("Number of events");
//    h_time->GetYaxis()->SetLabelSize(0.038);
//    h_time->GetXaxis()->SetLabelSize(0.038);
//    h_time->GetYaxis()->SetTitleSize(0.038);
//    h_time->GetXaxis()->SetTitleSize(0.038);
    
    h_etime->GetXaxis()->SetTitle("Mean hit time, ns");
    h_etime->GetYaxis()->SetTitle("Number of events");
    h_etime->GetYaxis()->SetLabelSize(0.038);
    h_etime->GetXaxis()->SetLabelSize(0.038);
    h_etime->GetYaxis()->SetTitleSize(0.038);
    h_etime->GetXaxis()->SetTitleSize(0.038);
    
    h_htime->GetXaxis()->SetTitle("Mean hit time, ns");
    h_htime->GetYaxis()->SetTitle("Number of events");
    h_htime->GetYaxis()->SetLabelSize(0.038);
    h_htime->GetXaxis()->SetLabelSize(0.038);
    h_htime->GetYaxis()->SetTitleSize(0.038);
    h_htime->GetXaxis()->SetTitleSize(0.038);
    
//    h_radius->GetXaxis()->SetTitle("Radius, mm");
//    h_radius->GetYaxis()->SetTitle("Number of events");
//    h_radius->GetYaxis()->SetLabelSize(0.038);
//    h_radius->GetXaxis()->SetLabelSize(0.038);
//    h_radius->GetYaxis()->SetTitleSize(0.038);
//    h_radius->GetXaxis()->SetTitleSize(0.038);
    
    h_eradius->GetXaxis()->SetTitle("Radius_{ecal}, mm");
    h_eradius->GetYaxis()->SetTitle("Number of events");
    h_eradius->GetYaxis()->SetLabelSize(0.038);
    h_eradius->GetXaxis()->SetLabelSize(0.038);
    h_eradius->GetYaxis()->SetTitleSize(0.038);
    h_eradius->GetXaxis()->SetTitleSize(0.038);
    
    h_hradius->GetXaxis()->SetTitle("Radius_{hcal}, mm");
    h_hradius->GetYaxis()->SetTitle("Number of events");
    h_hradius->GetYaxis()->SetLabelSize(0.038);
    h_hradius->GetXaxis()->SetLabelSize(0.038);
    h_hradius->GetYaxis()->SetTitleSize(0.038);
    h_hradius->GetXaxis()->SetTitleSize(0.038);
    
    h_elayer->GetXaxis()->SetTitle("Number of layers");
    h_elayer->GetYaxis()->SetTitle("Number of events");
    h_elayer->GetYaxis()->SetLabelSize(0.038);
    h_elayer->GetXaxis()->SetLabelSize(0.038);
    h_elayer->GetYaxis()->SetTitleSize(0.038);
    h_elayer->GetXaxis()->SetTitleSize(0.038);
    
    h_hlayer->GetXaxis()->SetTitle("Number of layers");
    h_hlayer->GetYaxis()->SetTitle("Number of events");
    h_hlayer->GetYaxis()->SetLabelSize(0.038);
    h_hlayer->GetXaxis()->SetLabelSize(0.038);
    h_hlayer->GetYaxis()->SetTitleSize(0.038);
    h_hlayer->GetXaxis()->SetTitleSize(0.038);
    
//    h_energy_hit->GetXaxis()->SetTitle("Mean hit energy, GeV");
//    h_energy_hit->GetYaxis()->SetTitle("Number of events");
//    h_energy_hit->GetYaxis()->SetLabelSize(0.038);
//    h_energy_hit->GetXaxis()->SetLabelSize(0.038);
//    h_energy_hit->GetYaxis()->SetTitleSize(0.038);
//    h_energy_hit->GetXaxis()->SetTitleSize(0.038);
    
    h_energy_hit_ecal->GetXaxis()->SetTitle("Mean hit energy, GeV");
    h_energy_hit_ecal->GetYaxis()->SetTitle("Number of events");
    h_energy_hit_ecal->GetYaxis()->SetLabelSize(0.038);
    h_energy_hit_ecal->GetXaxis()->SetLabelSize(0.038);
    h_energy_hit_ecal->GetYaxis()->SetTitleSize(0.038);
    h_energy_hit_ecal->GetXaxis()->SetTitleSize(0.038);
    
    h_energy_hit_hcal->GetXaxis()->SetTitle("Mean hit energy, GeV");
    h_energy_hit_hcal->GetYaxis()->SetTitle("Number of events");
    h_energy_hit_hcal->GetYaxis()->SetLabelSize(0.038);
    h_energy_hit_hcal->GetXaxis()->SetLabelSize(0.038);
    h_energy_hit_hcal->GetYaxis()->SetTitleSize(0.038);
    h_energy_hit_hcal->GetXaxis()->SetTitleSize(0.038);
    
    h_muon_energy->GetXaxis()->SetTitle("E_{reco}, GeV");
    h_muon_energy->GetYaxis()->SetTitle("Number of events");
    h_muon_energy->GetYaxis()->SetLabelSize(0.038);
    h_muon_energy->GetXaxis()->SetLabelSize(0.038);
    h_muon_energy->GetYaxis()->SetTitleSize(0.038);
    h_muon_energy->GetXaxis()->SetTitleSize(0.038);
    
    h_muon_energy_hit->GetXaxis()->SetTitle("Mean hit energy, GeV");
    h_muon_energy_hit->GetYaxis()->SetTitle("Number of events");
    h_muon_energy_hit->GetYaxis()->SetLabelSize(0.038);
    h_muon_energy_hit->GetXaxis()->SetLabelSize(0.038);
    h_muon_energy_hit->GetYaxis()->SetTitleSize(0.038);
    h_muon_energy_hit->GetXaxis()->SetTitleSize(0.038);
    
    h_muon_nhits->GetXaxis()->SetTitle("Number of hits");
    h_muon_nhits->GetYaxis()->SetTitle("Number of events");
    h_muon_nhits->GetYaxis()->SetLabelSize(0.038);
    h_muon_nhits->GetXaxis()->SetLabelSize(0.038);
    h_muon_nhits->GetYaxis()->SetTitleSize(0.038);
    h_muon_nhits->GetXaxis()->SetTitleSize(0.038);
    
    h_muon_time->GetXaxis()->SetTitle("Mean hit time, ns");
    h_muon_time->GetYaxis()->SetTitle("Number of events");
    h_muon_time->GetYaxis()->SetLabelSize(0.038);
    h_muon_time->GetXaxis()->SetLabelSize(0.038);
    h_muon_time->GetYaxis()->SetTitleSize(0.038);
    h_muon_time->GetXaxis()->SetTitleSize(0.038);
    
    h_muon_layer->GetXaxis()->SetTitle("Number of layers");
    h_muon_layer->GetYaxis()->SetTitle("Number of events");
    h_muon_layer->GetYaxis()->SetLabelSize(0.038);
    h_muon_layer->GetXaxis()->SetLabelSize(0.038);
    h_muon_layer->GetYaxis()->SetTitleSize(0.038);
    h_muon_layer->GetXaxis()->SetTitleSize(0.038);
    
    c_energy->cd();
    c_energy->SetTickx(1);
    c_energy->SetTicky(1);
    h_energy->SetLineColor(2);
    h_energy->SetLineWidth(1);
    h_energy->SetMarkerColor(2);
    h_energy->SetMarkerStyle(7);
    h_energy->SetMarkerSize(1);
    h_energy->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "energy_%d.png", fenergy);
    c_energy->SaveAs(name);
    
    c_eecal->cd();
    c_eecal->SetTickx(1);
    c_eecal->SetTicky(1);
    h_eecal->SetLineColor(2);
    h_eecal->SetLineWidth(1);
    h_eecal->SetMarkerColor(2);
    h_eecal->SetMarkerStyle(7);
    h_eecal->SetMarkerSize(1);
    h_eecal->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "eecal_%d.png", fenergy);
    c_eecal->SaveAs(name);
    
    c_ehcal->cd();
    c_ehcal->SetTickx(1);
    c_ehcal->SetTicky(1);
    h_ehcal->SetLineColor(2);
    h_ehcal->SetLineWidth(1);
    h_ehcal->SetMarkerColor(2);
    h_ehcal->SetMarkerStyle(7);
    h_ehcal->SetMarkerSize(1);
    h_ehcal->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "ehcal_%d.png", fenergy);
    c_ehcal->SaveAs(name);
    
    c_pfo_energy->cd();
    c_pfo_energy->SetTickx(1);
    c_pfo_energy->SetTicky(1);
    h_pfo_energy->SetLineColor(2);
    h_pfo_energy->SetLineWidth(1);
    h_pfo_energy->SetMarkerColor(2);
    h_pfo_energy->SetMarkerStyle(7);
    h_pfo_energy->SetMarkerSize(1);
    h_pfo_energy->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "pfo_energy_%d.png", fenergy);
    c_pfo_energy->SaveAs(name);
    
    c_mc_energy->cd();
    c_mc_energy->SetTickx(1);
    c_mc_energy->SetTicky(1);
    h_mc_energy->SetLineColor(2);
    h_mc_energy->SetLineWidth(1);
    h_mc_energy->SetMarkerColor(2);
    h_mc_energy->SetMarkerStyle(7);
    h_mc_energy->SetMarkerSize(1);
    h_mc_energy->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "mc_energy_%d.png", fenergy);
    c_mc_energy->SaveAs(name);
    
/*    c_nhits->cd();
    c_nhits->SetTickx(1);
    c_nhits->SetTicky(1);
    h_nhits->SetLineColor(2);
    h_nhits->SetLineWidth(1);
    h_nhits->SetMarkerColor(2);
    h_nhits->SetMarkerStyle(7);
    h_nhits->SetMarkerSize(1);
    h_nhits->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "nhits_%d.png", fenergy);
    c_nhits->SaveAs(name);
*/    
    c_nhits_ecal->cd();
    c_nhits_ecal->SetTickx(1);
    c_nhits_ecal->SetTicky(1);
    h_nhits_ecal->SetLineColor(2);
    h_nhits_ecal->SetLineWidth(1);
    h_nhits_ecal->SetMarkerColor(2);
    h_nhits_ecal->SetMarkerStyle(7);
    h_nhits_ecal->SetMarkerSize(1);
    h_nhits_ecal->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "nhits_ecal_%d.png", fenergy);
    c_nhits_ecal->SaveAs(name);
    
    c_nhits_hcal->cd();
    c_nhits_hcal->SetTickx(1);
    c_nhits_hcal->SetTicky(1);
    h_nhits_hcal->SetLineColor(2);
    h_nhits_hcal->SetLineWidth(1);
    h_nhits_hcal->SetMarkerColor(2);
    h_nhits_hcal->SetMarkerStyle(7);
    h_nhits_hcal->SetMarkerSize(1);
    h_nhits_hcal->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "nhits_hcal_%d.png", fenergy);
    c_nhits_hcal->SaveAs(name);
    
/*    c_time->cd();
    c_time->SetTickx(1);
    c_time->SetTicky(1);
    h_time->SetLineColor(2);
    h_time->SetLineWidth(1);
    h_time->SetMarkerColor(2);
    h_time->SetMarkerStyle(7);
    h_time->SetMarkerSize(1);
    h_time->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "time_%d.png", fenergy);
    c_time->SaveAs(name);
*/    
    c_etime->cd();
    c_etime->SetTickx(1);
    c_etime->SetTicky(1);
    h_etime->SetLineColor(2);
    h_etime->SetLineWidth(1);
    h_etime->SetMarkerColor(2);
    h_etime->SetMarkerStyle(7);
    h_etime->SetMarkerSize(1);
    h_etime->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "etime_%d.png", fenergy);
    c_etime->SaveAs(name);
    
    c_htime->cd();
    c_htime->SetTickx(1);
    c_htime->SetTicky(1);
    h_htime->SetLineColor(2);
    h_htime->SetLineWidth(1);
    h_htime->SetMarkerColor(2);
    h_htime->SetMarkerStyle(7);
    h_htime->SetMarkerSize(1);
    h_htime->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "htime_%d.png", fenergy);
    c_htime->SaveAs(name);
    
/*    c_radius->cd();
    c_radius->SetTickx(1);
    c_radius->SetTicky(1);
    h_radius->SetLineColor(2);
    h_radius->SetLineWidth(1);
    h_radius->SetMarkerColor(2);
    h_radius->SetMarkerStyle(7);
    h_radius->SetMarkerSize(1);
    h_radius->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "radius_%d.png", fenergy);
    c_radius->SaveAs(name);
*/    
    c_eradius->cd();
    c_eradius->SetTickx(1);
    c_eradius->SetTicky(1);
    h_eradius->SetLineColor(2);
    h_eradius->SetLineWidth(1);
    h_eradius->SetMarkerColor(2);
    h_eradius->SetMarkerStyle(7);
    h_eradius->SetMarkerSize(1);
    h_eradius->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "eradius_%d.png", fenergy);
    c_eradius->SaveAs(name);
    
    c_hradius->cd();
    c_hradius->SetTickx(1);
    c_hradius->SetTicky(1);
    h_hradius->SetLineColor(2);
    h_hradius->SetLineWidth(1);
    h_hradius->SetMarkerColor(2);
    h_hradius->SetMarkerStyle(7);
    h_hradius->SetMarkerSize(1);
    h_hradius->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "hradius_%d.png", fenergy);
    c_hradius->SaveAs(name);
    
    c_elayer->cd();
    c_elayer->SetTickx(1);
    c_elayer->SetTicky(1);
    h_elayer->SetLineColor(2);
    h_elayer->SetLineWidth(1);
    h_elayer->SetMarkerColor(2);
    h_elayer->SetMarkerStyle(7);
    h_elayer->SetMarkerSize(1);
    h_elayer->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "elayer_%d.png", fenergy);
    c_elayer->SaveAs(name);
    
    c_hlayer->cd();
    c_hlayer->SetTickx(1);
    c_hlayer->SetTicky(1);
    h_hlayer->SetLineColor(2);
    h_hlayer->SetLineWidth(1);
    h_hlayer->SetMarkerColor(2);
    h_hlayer->SetMarkerStyle(7);
    h_hlayer->SetMarkerSize(1);
    h_hlayer->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "hlayer_%d.png", fenergy);
    c_hlayer->SaveAs(name);
    
/*    c_energy_hit->cd();
    c_energy_hit->SetTickx(1);
    c_energy_hit->SetTicky(1);
    h_energy_hit->SetLineColor(2);
    h_energy_hit->SetLineWidth(1);
    h_energy_hit->SetMarkerColor(2);
    h_energy_hit->SetMarkerStyle(7);
    h_energy_hit->SetMarkerSize(1);
    h_energy_hit->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "energy_hit_%d.png", fenergy);
    c_energy_hit->SaveAs(name);
*/    
    c_energy_hit_ecal->cd();
    c_energy_hit_ecal->SetTickx(1);
    c_energy_hit_ecal->SetTicky(1);
    h_energy_hit_ecal->SetLineColor(2);
    h_energy_hit_ecal->SetLineWidth(1);
    h_energy_hit_ecal->SetMarkerColor(2);
    h_energy_hit_ecal->SetMarkerStyle(7);
    h_energy_hit_ecal->SetMarkerSize(1);
    h_energy_hit_ecal->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "energy_hit_ecal_%d.png", fenergy);
    c_energy_hit_ecal->SaveAs(name);
    
    c_energy_hit_hcal->cd();
    c_energy_hit_hcal->SetTickx(1);
    c_energy_hit_hcal->SetTicky(1);
    h_energy_hit_hcal->SetLineColor(2);
    h_energy_hit_hcal->SetLineWidth(1);
    h_energy_hit_hcal->SetMarkerColor(2);
    h_energy_hit_hcal->SetMarkerStyle(7);
    h_energy_hit_hcal->SetMarkerSize(1);
    h_energy_hit_hcal->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "energy_hit_hcal_%d.png", fenergy);
    c_energy_hit_hcal->SaveAs(name);
    
    c_muon_energy->cd();
    c_muon_energy->SetTickx(1);
    c_muon_energy->SetTicky(1);
    c_muon_energy->SetLogy();
    h_muon_energy->SetLineColor(2);
    h_muon_energy->SetLineWidth(1);
    h_muon_energy->SetMarkerColor(2);
    h_muon_energy->SetMarkerStyle(7);
    h_muon_energy->SetMarkerSize(1);
    h_muon_energy->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "muon_energy_%d.png", fenergy);
    c_muon_energy->SaveAs(name);
    
    c_muon_energy_hit->cd();
    c_muon_energy_hit->SetTickx(1);
    c_muon_energy_hit->SetTicky(1);
    c_muon_energy_hit->SetLogy();
    h_muon_energy_hit->SetLineColor(2);
    h_muon_energy_hit->SetLineWidth(1);
    h_muon_energy_hit->SetMarkerColor(2);
    h_muon_energy_hit->SetMarkerStyle(7);
    h_muon_energy_hit->SetMarkerSize(1);
    h_muon_energy_hit->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "muon_energy_hit_%d.png", fenergy);
    c_muon_energy_hit->SaveAs(name);
    
    c_muon_nhits->cd();
    c_muon_nhits->SetTickx(1);
    c_muon_nhits->SetTicky(1);
    c_muon_nhits->SetLogy();
    h_muon_nhits->SetLineColor(2);
    h_muon_nhits->SetLineWidth(1);
    h_muon_nhits->SetMarkerColor(2);
    h_muon_nhits->SetMarkerStyle(7);
    h_muon_nhits->SetMarkerSize(1);
    h_muon_nhits->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "muon_nhits_%d.png", fenergy);
    c_muon_nhits->SaveAs(name);
    
    c_muon_time->cd();
    c_muon_time->SetTickx(1);
    c_muon_time->SetTicky(1);
    c_muon_time->SetLogy();
    h_muon_time->SetLineColor(2);
    h_muon_time->SetLineWidth(1);
    h_muon_time->SetMarkerColor(2);
    h_muon_time->SetMarkerStyle(7);
    h_muon_time->SetMarkerSize(1);
    h_muon_time->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "muon_time_%d.png", fenergy);
    c_muon_time->SaveAs(name);
    
    c_muon_layer->cd();
    c_muon_layer->SetTickx(1);
    c_muon_layer->SetTicky(1);
    c_muon_layer->SetLogy();
    h_muon_layer->SetLineColor(2);
    h_muon_layer->SetLineWidth(1);
    h_muon_layer->SetMarkerColor(2);
    h_muon_layer->SetMarkerStyle(7);
    h_muon_layer->SetMarkerSize(1);
    h_muon_layer->Draw("ehist");
    
    for (int i = 0; i < 200; i++) name[i] = 0;
    sprintf(name, "muon_layer_%d.png", fenergy);
    c_muon_layer->SaveAs(name);
    
//    file->Close();
}
