void plus ()
{
  FILE* file = fopen("/home/root1/processing/out_scan3.txt", "r");
  std::cout << "File open... " << std::endl;
  if (!file) {
   std::cout << "[FAIL]\n" << std::endl;
   return 0;
  } else std::cout << "[OK]" << std::endl;

  FILE *plus = fopen("out_scan3_plus.txt", "a+");
  printf("File open... ");
  if (!plus) {
     printf("[FAIL]\n");
     return 0;
  } else printf("[OK]\n");

  Float_t a = 0;
  Char_t buf[0xFF];
  while( feof(file) == 0 ) {
    a = 0;
    fscanf ( file,"%f", &a );
    fgets( buf, 0xFF, file );
    if ( a < 0 ) a = 0;
    fprintf( plus, "%f\n", a);
    }
  fclose( plus );
  fclose( file );
}
