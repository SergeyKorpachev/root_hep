void aaa1 ()
{
  TF1 *fitFunc;

  Int_t iter = 1;
 
  TCanvas *c1 = new TCanvas("c1", "c1", 1);

  FILE* in = fopen( "aaaaa.txt", "r" );

  TH1F* hist = new TH1F("hist","hist",200,0.,1600.);

  std::cout << "1File open... " << std::endl;
  if (!in) {
   std::cout << "[FAIL]\n" << std::endl;
   return 0;
  } else std::cout << "[OK]" << std::endl;

  Char_t a = 0;
  Int_t i = 0;
  Int_t j = 0;
  Bool_t flag = false;
  Char_t buf[0xFF];
  memset(buf, 0, 0xFF);
  while( feof(in) == 0 ) {
   // fscanf ( in, "%s", buf );
    fgets( buf, 0xFF, in );
    FILE* file = fopen( buf, "r" );
    Char_t buffer[0xFF];
    memset(buffer, 0, 0xFF);
    for (i = 0; i < 0xFF; i++) {
       if ( flag == true ) break;
       buffer[i] = buf[i];
       if ( ( buf[i] == 't' ) && ( buf[i-1] == 'x' ) ) flag = true;
    } 
    flag = false;  
    printf("%s\n", buffer);
    FILE* file = fopen( buffer, "r" );

    std::cout << "2File open... " << std::endl;
    if (!file) {
     std::cout << "[FAIL]\n" << std::endl;
     return 0;
    } else std::cout << "[OK]" << std::endl;
    
    Int_t b = 0;
    Int_t c = 0;
    Char_t buf1[0xFF];
    memset(buf1, 0, 0xFF);
    while( feof(file) == 0 ) {
       fscanf ( file,"%d %d", &b, &c );
       fgets( buf1, 0xFF, file );
       if ( b == 4  ) hist->Fill( c );
       b = c = 0;
    }

    hist->GetXaxis()->SetRangeUser(300, 1600);

    fitFunc = new TF1("fitFunc", "gaus");
    hist->Fit(fitFunc);

    Float_t mean = fitFunc->GetParameter(1);
    Float_t sigma = fitFunc->GetParameter(2);
    //Double_t chi2 = 0;
    //chi2 = fitFunc->GetChisquare() / fitFunc->GetNDF();
    FILE *out = fopen("out.txt", "a+");
       printf("3File open... ");
       if (!out) {
          printf("[FAIL]\n");
          return 0;
       } else printf("[OK]\n");
    fprintf(out,"%E		%d\n", mean, iter);
    iter++;
    fclose(out);

    hist->Draw();
//    c1->SaveAs("pic.jpg");
    
    fclose(file);
    printf("Final of iteration!!!!!\n");
//    break;
    }
  printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
  fclose( in );
  printf("General final!!!!!!!!!\n");
  iter = 1;
}
