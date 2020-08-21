/*
void f4(const TH1F *const pTH1F, float &resolution, float &resolutionError, bool fixDistributionCentre, bool print)
{
    static const float FLOAT_MAX(std::numeric_limits<float>::max());

    if (NULL == pTH1F)
        return;

    if (5 > pTH1F->GetEntries())
    {
        std::cout << pTH1F->GetName() << " (" << pTH1F->GetEntries() << " entries) - skipped" << std::endl;
        return;
    }

    // Calculate raw properties of distribution
    float sum = 0., total = 0.;
    double sx = 0., sxx = 0.;
    const unsigned int nbins(pTH1F->GetNbinsX());

    for (unsigned int i = 0; i <= nbins; ++i)
    {
        const float binx(pTH1F->GetBinLowEdge(i) + (0.5 * pTH1F->GetBinWidth(i)));
        const float yi(pTH1F->GetBinContent(i));
        sx += yi * binx;
        sxx += yi * binx * binx;
        total += yi;
    }

    const float rawMean(sx / total);
    const float rawMeanSquared(sxx / total);
    const float rawRms(std::sqrt(rawMeanSquared - rawMean * rawMean));

    sum = 0.;
    unsigned int is0 = 0;

    for (unsigned int i = 0; (i <= nbins) && (sum < total / 10.); ++i)
    {
        sum += pTH1F->GetBinContent(i);
        is0 = i;
    }

    // Calculate truncated properties
    float rmsmin(FLOAT_MAX), sigma(FLOAT_MAX), sigmasigma(FLOAT_MAX), frac(FLOAT_MAX), efrac(FLOAT_MAX), mean(FLOAT_MAX), low(FLOAT_MAX), rms(FLOAT_MAX);
    float high(0.f);

    for (unsigned int istart = 0; istart <= is0; ++istart)
    {
        double sumn = 0.;
        double csum = 0.;
        double sumx = 0.;
        double sumxx = 0.;
        unsigned int iend = 0;

        for (unsigned int i = istart; (i <= nbins) && (csum < 0.9 * total); ++i)
        {
            const float binx(pTH1F->GetBinLowEdge(i) + (0.5 * pTH1F->GetBinWidth(i)));
            const float yi(pTH1F->GetBinContent(i));
            csum += yi;

            if (sumn < 0.9 * total)
            {
                sumn += yi;
                sumx += yi * binx;
                sumxx+= yi * binx * binx;
                iend = i;
            }
        }

        const float localMean(sumx / sumn);
        const float localMeanSquared(sumxx / sumn);
        const float localRms(std::sqrt(localMeanSquared - localMean * localMean));

        if (localRms < rmsmin)
        {
            mean = localMean;
            rms = localRms;
            low = pTH1F->GetBinLowEdge(istart);
            high = pTH1F->GetBinLowEdge(iend);
            rmsmin = localRms;

            if (fixDistributionCentre)
            {
                float centre = 91.2;

                if (mean > 3500.)
                {
                    //throw InvalidEnergyException();
                    cout << "QWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQWQW" << endl;
                }

                if ((mean > 2500.) && (mean < 3500.))
                    centre = 3000.;

                if ((mean > 1500.) && (mean < 2500.))
                    centre = 2000.;

                if ((mean > 700.) && (mean < 1500.))
                    centre = 1000.;

                if ((mean > 400.) && (mean < 700.))
                    centre = 500.;

                if ((mean > 250.) && (mean < 400.))
                    centre = 360.;

                if ((mean > 150.) && (mean < 250.))
                    centre = 200.;

                sigma = rms / mean * sqrt(centre);
                sigmasigma = sigma / std::sqrt(total);

                frac = rms / mean * std::sqrt(2) * 100.;
                efrac = frac / std::sqrt(total);
            }
            else
            {
                sigma = rms;
                sigmasigma = sigma / std::sqrt(total);
            }
        }
    }

    if (print)
    {
        std::cout << pTH1F->GetName() << " (" << pTH1F->GetEntries() << " entries), rawrms: " << rawRms << ", rms90: " << rmsmin
                  << " (" << low << "-" << high << "), mean: " << mean << ", sigma: " << sigma << "+-" << sigmasigma;
        (fixDistributionCentre) ? (std::cout << ", sE/E: " << frac << "+-" << efrac << std::endl) : (std::cout << std::endl);
    }

    resolution = frac;
    resolutionError = efrac;
}

void f3(const TH1F *const m_histogram)
{
    static const float FLOAT_MAX(std::numeric_limits<float>::max());
    
    float m_fitRangeLow(std::numeric_limits<float>::max());
    float m_fitRangeHigh(std::numeric_limits<float>::max());
    float m_rMSFitRange(std::numeric_limits<float>::max());
    
    float m_fitPercentage = 90.0;

    if (NULL == m_histogram)
        return;

    if (5 > m_histogram->GetEntries())
    {
        std::cout << m_histogram->GetName() << " (" << m_histogram->GetEntries() << " entries) - skipped" << std::endl;
        return;
    }

    // Calculate raw properties of distribution (ie rms100)
    float sum = 0., total = 0.;
    double sx = 0., sxx = 0.;
    const unsigned int nbins(m_histogram->GetNbinsX());

    for (unsigned int i = 0; i <= nbins; ++i)
    {
        const float binx(m_histogram->GetBinLowEdge(i) + (0.5 * m_histogram->GetBinWidth(i)));
        const float yi(m_histogram->GetBinContent(i));
        sx += yi * binx;
        sxx += yi * binx * binx;
        total += yi;
    }

    const float rawMean(sx / total);
    const float rawMeanSquared(sxx / total);
    const float rawRms(std::sqrt(rawMeanSquared - rawMean * rawMean));

    sum = 0.;
    unsigned int is0 = 0;
    
    //  The /10 comes from the fact that for rms 90 the start point for the fit must occur in the first 10% of the data.
    float frac = (1 - (m_fitPercentage/100.0));
    for (unsigned int i = 0; (i <= nbins) && (sum < total * frac); ++i)
    {
        sum += m_histogram->GetBinContent(i);
        is0 = i;
    }

    // Calculate truncated properties
    float rmsmin(FLOAT_MAX), mean(FLOAT_MAX), low(FLOAT_MAX);
    float high(0.f);

    for (unsigned int istart = 0; istart <= is0; ++istart)
    {
        double sumn = 0.;
        double csum = 0.;
        double sumx = 0.;
        double sumxx = 0.;
        unsigned int iend = 0;

        for (unsigned int i = istart; (i <= nbins) && (csum < (m_fitPercentage/100) * total); ++i)
        {
            const float binx(m_histogram->GetBinLowEdge(i) + (0.5 * m_histogram->GetBinWidth(i)));
            const float yi(m_histogram->GetBinContent(i));
            //csum is the sum of yi from istart and is used to stop the sum when this exceeds X% of data.
            csum += yi;

            if (sumn < (m_fitPercentage/100) * total)
            {
                // These variables define the final sums required once we have considered X% of data, anything else is
                // continuously overwritten.
                sumn += yi;
                sumx += yi * binx;
                sumxx+= yi * binx * binx;
                iend = i;
            }
        }

        const float localMean(sumx / sumn);
        const float localMeanSquared(sumxx / sumn);
        // Standard deviation formula
        const float localRms(std::sqrt(localMeanSquared - localMean * localMean));

        if (localRms < rmsmin)
        {
            mean = localMean;
            if (istart==0)
            {
                low = 0;
                m_fitRangeLow = 0;
            }
            else
            {
                low = m_histogram->GetBinLowEdge(istart);
                m_fitRangeLow=m_histogram->GetBinLowEdge(istart) + (0.5 * m_histogram->GetBinWidth(istart));
            }
            
            high = m_histogram->GetBinLowEdge(iend);
            rmsmin = localRms;
            m_fitRangeHigh=m_histogram->GetBinLowEdge(iend) + (0.5 * m_histogram->GetBinWidth(iend));
        }
    }
    
    m_rMSFitRange = rmsmin;
    
    std::cout << m_histogram->GetName() << " (" << m_histogram->GetEntries() << " entries), rawrms: " << rawRms << ", rmsx: " << rmsmin
              << " (" << low << "-" << high << "), low_fit and high_fit " << " (" << m_fitRangeLow << "-" << m_fitRangeHigh
              << "), << mean: " << mean << std::endl;
}

void f2(const TH1F *const pTH1F, float &resolution, float &resolutionError, float &scale, float &scaleError, bool print)
{
    static const float FLOAT_MAX(std::numeric_limits<float>::max());

    if (NULL == pTH1F)
        return;

    if (5 > pTH1F->GetEntries())
    {
        std::cout << pTH1F->GetName() << " (" << pTH1F->GetEntries() << " entries) - skipped" << std::endl;
        return;
    }

    // Calculate raw properties of distribution
    float sum = 0., total = 0.;
    double sx = 0., sxx = 0.;
    const unsigned int nbins(pTH1F->GetNbinsX());

    for (unsigned int i = 0; i <= nbins; ++i)
    {
        const float binx(pTH1F->GetBinLowEdge(i) + (0.5 * pTH1F->GetBinWidth(i)));
        const float yi(pTH1F->GetBinContent(i));
        sx += yi * binx;
        sxx += yi * binx * binx;
        total += yi;
    }

    const float rawMean(sx / total);
    const float rawMeanSquared(sxx / total);
    const float rawRms(std::sqrt(rawMeanSquared - rawMean * rawMean));

    sum = 0.;
    unsigned int is0 = 0;

    for (unsigned int i = 0; (i <= nbins) && (sum < total / 10.); ++i)
    {
        sum += pTH1F->GetBinContent(i);
        is0 = i;
    }

    // Calculate truncated properties
    float rmsmin(FLOAT_MAX), sigma(FLOAT_MAX), sigmasigma(FLOAT_MAX), frac(FLOAT_MAX), efrac(FLOAT_MAX), mean(FLOAT_MAX), low(FLOAT_MAX), rms(FLOAT_MAX);
    float high(0.f);

    for (unsigned int istart = 0; istart <= is0; ++istart)
    {
        double sumn = 0.;
        double csum = 0.;
        double sumx = 0.;
        double sumxx = 0.;
        unsigned int iend = 0;

        for (unsigned int i = istart; (i <= nbins) && (csum < 0.9 * total); ++i)
        {
            const float binx(pTH1F->GetBinLowEdge(i) + (0.5 * pTH1F->GetBinWidth(i)));
            const float yi(pTH1F->GetBinContent(i));
            csum += yi;

            if (sumn < 0.9 * total)
            {
                sumn += yi;
                sumx += yi * binx;
                sumxx+= yi * binx * binx;
                iend = i;
            }
        }

        const float localMean(sumx / sumn);
        const float localMeanSquared(sumxx / sumn);
        const float localRms(std::sqrt(localMeanSquared - localMean * localMean));

        if (localRms < rmsmin)
        {
            mean = localMean;
            rms = localRms;
            low = pTH1F->GetBinLowEdge(istart);
            high = pTH1F->GetBinLowEdge(iend);
            rmsmin = localRms;

            sigma = rms;
            sigmasigma = sigma / std::sqrt(total);
            
            frac = rms / mean * std::sqrt(2) * 100.;
            efrac = frac / std::sqrt(total);
        }
    }

    if (print)
    {
        std::cout << pTH1F->GetName() << " (" << pTH1F->GetEntries() << " entries), rawrms: " << rawRms << ", rms90: " << rmsmin
                  << " (" << low << "-" << high << "), mean: " << mean << ", sigma: " << sigma << "+-" << sigmasigma;
        std::cout << ", sE/E: " << frac << "+-" << efrac << std::endl;
    }

    resolution = frac;
    resolutionError = efrac;
    scale = mean;
    scaleError = sigma;
}
*/

void f2( TH1F* h, float &value, float &a, float &b, int &l, int &r )
{
    static const float FLOAT_MAX(std::numeric_limits<float>::max());
    
    cout << "Value2 === " << value << endl;
    cout << "Value2 / 100.0 === " << value / 100.0 << endl;

    if (NULL == h)
        return;

    if (5 > h->GetEntries())
    {
        std::cout << h->GetName() << " (" << h->GetEntries() << " entries) - skipped" << std::endl;
        return;
    }

    // Calculate raw properties of distribution
    float sum = 0., total = 0.;
    double sx = 0., sxx = 0.;
    const unsigned int nbins(h->GetNbinsX());

    for (unsigned int i = 0; i <= nbins; ++i)
    {
        const float binx(h->GetBinLowEdge(i) + (0.5 * h->GetBinWidth(i)));
        const float yi(h->GetBinContent(i));
        sx += yi * binx;
        sxx += yi * binx * binx;
        total += yi;
    }

    const float rawMean(sx / total);
    const float rawMeanSquared(sxx / total);
    const float rawRms(std::sqrt(rawMeanSquared - rawMean * rawMean));

    sum = 0.;
    unsigned int is0 = 0;

    for (unsigned int i = 0; (i <= nbins) && (sum < total * ( 1.0 - (value)/(100.0) ) ); ++i)
    {
        sum += h->GetBinContent(i);
        is0 = i;
    }

    // Calculate truncated properties
    float rmsmin(FLOAT_MAX), sigma(FLOAT_MAX), sigmasigma(FLOAT_MAX), frac(FLOAT_MAX), efrac(FLOAT_MAX), mean(FLOAT_MAX), low(FLOAT_MAX), rms(FLOAT_MAX);
    float high(0.f);

    for (unsigned int istart = 0; istart <= is0; ++istart)
    {
        double sumn = 0.;
        double csum = 0.;
        double sumx = 0.;
        double sumxx = 0.;
        unsigned int iend = 0;

        for (unsigned int i = istart; (i <= nbins) && (csum < ( value / 100.0 ) * total); ++i)
        {
            const float binx(h->GetBinLowEdge(i) + (0.5 * h->GetBinWidth(i)));
            const float yi(h->GetBinContent(i));
            csum += yi;

            if (sumn < ( value / 100.0 ) * total)
            {
                sumn += yi;
                sumx += yi * binx;
                sumxx+= yi * binx * binx;
                iend = i;
            }
        }

        const float localMean(sumx / sumn);
        const float localMeanSquared(sumxx / sumn);
        const float localRms(std::sqrt(localMeanSquared - localMean * localMean));

        if (localRms < rmsmin)
        {
            mean = localMean;
            rms = localRms;
            low = h->GetBinLowEdge(istart);
            l = istart;
            high = h->GetBinLowEdge(iend);
            r = iend;
            rmsmin = localRms;

            sigma = rms;
            sigmasigma = sigma / std::sqrt(total);
            
            frac = rms / mean * std::sqrt(2) * 100.;
            efrac = frac / std::sqrt(total);
        }
    }

/*    if (1)
    {
        std::cout << h->GetName() << " (" << h->GetEntries() << " entries), rawrms: " << rawRms << ", rms90: " << rmsmin
                  << " (" << low << "-" << high << "), mean: " << mean << ", sigma: " << sigma << "+-" << sigmasigma;
        std::cout << ", sE/E: " << frac << "+-" << efrac << std::endl;
    }
 
    resolution = frac;
    resolutionError = efrac;
    scale = mean;
    scaleError = sigma; */
    
    printf( "RMS of central %0.f%% = %f, RMS total = %f, Mean of central %.f%% = %f, Mean total = %f\n", value, rmsmin, h -> GetRMS(), value, mean, h -> GetMean() );
    a = mean;
    b = rmsmin;
}
 
void f( TH1F* h, float &value, float &a, float &b, int &l, int &r ) {
  cout << "Value === " << value << endl;
  cout << "Value / 100.0 === " << value / 100.0 << endl;
  TAxis* axis = h -> GetXaxis();
  Int_t nbins = axis -> GetNbins();
  Int_t imean = axis -> FindBin( h -> GetMean() );
  Double_t entries = ( value / 100.0 ) * ( h -> GetEntries() );
  Double_t w = h -> GetBinContent( imean );
  Double_t x = h -> GetBinCenter( imean );
  Double_t sumw = w;
  Double_t sumwx = w*x;
  Double_t sumwx2 = w*x*x;
  for ( Int_t i = 1; i < nbins; i++ ) {
    if ( i > 0 ) {
    w = h -> GetBinContent( imean - i );
    x = h -> GetBinCenter( imean - i );
    l = imean - i;
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( i <= nbins ) {
    w = h -> GetBinContent( imean + i );
    x = h -> GetBinCenter( imean + i );
    r = imean + i;
    sumw += w;
    sumwx += w*x;
    sumwx2 += w*x*x;
    }
    if ( sumw > entries ) break;
  }
  x = sumwx / sumw;
  Double_t rms2 = TMath::Abs( ( sumwx2 / sumw ) - ( x * x ) );
  Double_t result = TMath::Sqrt( rms2 );
  printf( "RMS of central %0.f%% = %f, RMS total = %f, Mean of central %.f%% = %f, Mean total = %f\n", value, result, h -> GetRMS(), value, x, h -> GetMean() );
  a = x;
  b = result;
}

void fit_data( const int fenergy = 5, const int nBins = 1000 ) {
    
  float FFF = 90.0;
    
  char fname_out[ 200 ];
  for ( int i = 0; i < 200; i++ ) fname_out[ i ] = 0;

  char fname[ 200 ];
  char ftempname[ 200 ];
  char fname2[ 200 ];

  for ( int i = 0; i < 200; i++ ) fname[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) ftempname[ i ] = 0;
  for ( int i = 0; i < 200; i++ ) fname2[ i ] = 0;

  sprintf( ftempname, "gun_k0L_%dgev_FTFP_BERT_5000evt_ILD_l5_v02steel", fenergy );
  sprintf( fname, "%s.root", ftempname );

  TH1F *hist;
    
  TH1F *hist2;
  TH1F *hist3;

  TCanvas *c1 = new TCanvas("c1", "c1", 1);
/*  TCanvas *c2 = new TCanvas("c2", "c2", 1);
  TCanvas *c3 = new TCanvas("c3", "c3", 1);
  TCanvas *c4 = new TCanvas("c4", "c4", 1);
    
  TCanvas *c5 = new TCanvas("c5", "c5", 1);
  TCanvas *c6 = new TCanvas("c6", "c6", 1);
  TCanvas *c7 = new TCanvas("c7", "c7", 1);
  TCanvas *c8 = new TCanvas("c8", "c8", 1);
  */
  gStyle->SetOptStat(0);

  const char *treeName = "tree";
  const float binLo = 0.0;
  const float binHi = fenergy + 30.0;

  //
  // Open data file
  //
  std::cout << "Trying to open data file... ";
  TFile *file = new TFile(fname, "READ");
  if (!file) { // if error occure then exit
    std::cout << "[FAIL]" << std::endl;
    return;
  }
  std::cout << "[OK]" << std::endl;

  //
  // Open file for output
  //
    
  sprintf( fname_out, "out_diff_rms_%0.f.txt", FFF );
    
   FILE *out = fopen(fname_out, "a+");
       printf("File open... ");
       if (!out) {
          printf("[FAIL]\n");
          return;
       } else printf("[OK]\n");

  //
  // Setup a TTree
  //
  std::cout << "Setup a tree... ";
  TTree *tree = (TTree *)file->Get(treeName);
  if (!tree) {
    std::cout << "[FAIL]" << std::endl;
    file->Close();
    return;
  }
  std::cout << "[OK]" << std::endl;

  unsigned int nEvents = tree->GetEntries();

  //
  // Setup a branch
  //
  Float_t energy = 0;
  tree->SetBranchAddress("energy", &energy);

  //
  // Create a histogram and random generator
  //
  hist = new TH1F("hist", "hist", nBins, binLo, binHi);

  for ( int i = 0; i <nEvents; i++ ) {
    tree -> GetEntry(i);
    if ( energy > 0 ) hist -> Fill( energy );
  }
    
//  cout << "Underflow hist === " << hist->GetBinContent( 0 ) << endl;
//  cout << "Overflow hist === " << hist->GetBinContent( nBins + 1 ) << endl;

  float mean = hist -> GetMean();
  float meanerror = hist -> GetMeanError();
  float rms = hist -> GetRMS();
  float rmserror = hist -> GetRMSError();
  cout << " 0:"
    << "  Mean: " << mean
    << "  Mean error: " << meanerror
    << "  RMS: " << rms
    << "  RMS error: " << rmserror
    << endl;
    
  cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
  cout << "f2:" << endl;
  float f2value = FFF;
  float f2mean = 0;
  float f2rms = 0;
  int f2left = 0;
  int f2right = 0;
  f2( hist, f2value, f2mean, f2rms, f2left, f2right );
  cout << "f2mean = " << f2mean << " and f2rms = " << f2rms << endl;
  cout << "f2left = " << f2left << " and f2right = " << f2right << endl;
  cout << "Left value f2 = " << hist->GetBinCenter( f2left ) << " and right value f2 = " << hist->GetBinCenter( f2right ) << endl;
  cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;

  cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
  cout << "f:" << endl;
  float fvalue = FFF;
  float fmean = 0;
  float frms = 0;
  int fleft = 0;
  int fright = 0;
  f( hist, fvalue, fmean, frms, fleft, fright );
  cout << "fmean = " << fmean << " and frms = " << frms << endl;
  cout << "fleft = " << fleft << " and fright = " << fright << endl;
  cout << "Left value f = " << hist->GetBinCenter( fleft ) << " and right value f = " << hist->GetBinCenter( fright ) << endl;
  cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;

  hist2 = (TH1F*)hist->Clone();
  hist3 = (TH1F*)hist->Clone();
    
  hist2->GetXaxis()->SetRange(fleft, fright);
  hist3->GetXaxis()->SetRange(f2left, f2right);
        
  cout << "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ" << endl;
    
  cout << "Underflow hist2 === " << hist2->GetBinContent( 0 ) << endl;
  cout << "Overflow hist2 === " << hist2->GetBinContent( nBins + 1 ) << endl;
  float mean_hist2 = hist2 -> GetMean();
  float meanerror_hist2 = hist2 -> GetMeanError();
  float rms_hist2 = hist2 -> GetRMS();
  float rmserror_hist2 = hist2 -> GetRMSError();
  cout << " 0:"
    << "  Mean2: " << mean_hist2
    << "  Mean2 error: " << meanerror_hist2
    << "  RMS2: " << rms_hist2
    << "  RMS2 error: " << rmserror_hist2
    << endl;
    
  cout << "Underflow hist3 === " << hist3->GetBinContent( 0 ) << endl;
  cout << "Overflow hist3 === " << hist3->GetBinContent( nBins + 1 ) << endl;
  float mean_hist3 = hist3 -> GetMean();
  float meanerror_hist3 = hist3 -> GetMeanError();
  float rms_hist3 = hist3 -> GetRMS();
  float rmserror_hist3 = hist3 -> GetRMSError();
  cout << " 0:"
    << "  Mean3: " << mean_hist3
    << "  Mean3 error: " << meanerror_hist3
    << "  RMS3: " << rms_hist3
    << "  RMS3 error: " << rmserror_hist3
    << endl;
    
  cout << "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ" << endl;
  
/*
  c2 -> cd();
  hist -> SetMarkerStyle(20);
  hist -> SetMarkerColor(kBlue);
  hist -> SetLineColor(kBlue);
  hist -> Draw("p e");
  c3 -> cd();
  hist90 -> SetMarkerStyle(20);
  hist90 -> SetMarkerColor(kRed);
  hist90 -> SetLineColor(kRed);
  hist90 -> Draw("p e");
  c4 -> cd();
  hist95 -> SetMarkerStyle(20);
  hist95 -> SetMarkerColor(kGreen);
  hist95 -> SetLineColor(kGreen);
  hist95 -> Draw("p e");
    
  c5 -> cd();
  hist2 -> SetMarkerStyle(20);
  hist2 -> SetMarkerColor(kRed);
  hist2 -> SetLineColor(kRed);
  hist2 -> Draw("p e");
  c6 -> cd();
  hist3 -> SetMarkerStyle(20);
  hist3 -> SetMarkerColor(kGreen);
  hist3 -> SetLineColor(kGreen);
  hist3 -> Draw("p e");
    
       c7 -> cd();
    hist->SetTitle("1");
    hist->GetYaxis()->SetTitle("Number of events");
    hist->GetXaxis()->SetTitle("Energy, GeV");
    hist -> SetMarkerStyle(20);
    hist -> SetMarkerColor(kBlue);
    hist -> SetLineColor(kBlue);
    hist -> Draw("p e");
    hist2 -> SetMarkerStyle(20);
    hist2 -> SetMarkerColor(kRed);
    hist2 -> SetLineColor(kRed);
    hist2 -> Draw("p e SAME");
//    hist3 -> SetMarkerStyle(20);
//    hist3 -> SetMarkerColor(kGreen);
//    hist3 -> SetLineColor(kGreen);
//    hist3 -> Draw("p e SAME");

        c8 -> cd();
    c8->Update();
        hist->SetTitle("Full distribution and 95% of the distribution");
        hist->GetYaxis()->SetTitle("Number of events");
        hist->GetXaxis()->SetTitle("Energy, GeV");
        hist -> SetMarkerStyle(20);
        hist -> SetMarkerColor(kBlue);
        hist -> SetLineColor(kBlue);
        hist -> Draw("p e");
//        hist2 -> SetMarkerStyle(20);
//        hist2 -> SetMarkerColor(kRed);
//        hist2 -> SetLineColor(kRed);
//        hist2 -> Draw("p e SAME");
        hist3 -> SetMarkerStyle(20);
        hist3 -> SetMarkerColor(kGreen);
        hist3 -> SetLineColor(kGreen);
        hist3 -> Draw("p e SAME");
*/
 
  fprintf( out, "%d %E %E %E %E %E %E %E %E\n", fenergy, mean_hist2, meanerror_hist2, rms_hist2, rmserror_hist2, mean_hist3, meanerror_hist3, rms_hist3, rmserror_hist3 );
  delete hist;
  fclose( out );
  file -> Close();

}

void diff_rms( const int bins = 1000 ) {

//  int mass[] = { 1, 2, 3, 4, 5, 10, 15, 20, 25, 30, 40, 50, 60, 70, 80, 90 };
  int mass[] = { 5, 10, 15, 20, 25, 30, 40, 50, 60 };
  int dim = 9; // 16

  for (int i = 0; i < dim; i++ ) {
      fit_data( mass[ i ], bins );
  }
    
}
