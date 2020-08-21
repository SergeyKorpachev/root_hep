void coord ()
{
  FILE* file = fopen("/home/root1/Desktop/diplom/data/processing/coords.txt", "r");

  std::cout << "File open... " << std::endl;
  if (!file) {
   std::cout << "[FAIL]\n" << std::endl;
   return 0;
  } else std::cout << "[OK]" << std::endl;

  FILE *x_file = fopen("x.txt", "a+");
  FILE *y_file = fopen("y.txt", "a+");
  printf("File open... ");
  if (!x_file) {
     printf("[FAIL]\n");
     return 0;
  } else printf("[OK]\n");

  printf("File open... ");
  if (!y_file) {
     printf("[FAIL]\n");
     return 0;
  } else printf("[OK]\n");

  Float_t a = 0;
  Float_t b = 0;
  Char_t buf[0xFF];
  while( feof(file) == 0 ) {
    a = b = 0;
    fscanf ( file,"%f %f", &a, &b );
    fgets( buf, 0xFF, file );
    fprintf( x_file, "%f\n", a);
    fprintf( y_file, "%f\n", b);
    
  }
  fclose(x_file);
  fclose(y_file);
  fclose( file );
}
