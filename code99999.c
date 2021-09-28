void code() {
    
    const Int_t n = 29;

    Float_t weights[n];
    
    for(int i = 0; i < n; i++) {
        weights[i] = 0.0;
    }
    
    Float_t sum = 0.0;
    
    FILE *file1 = fopen("test.txt", "r");
    if (!(long)file1) return;
    
    for (int i = 0; i < n; i++) { // or %f
      fscanf( file1, "%E\n", &weights[i]);
      if (feof(file1)) break;
    }
    
    for(int i = 0; i < n; i++) {
        printf("Weights === %E\n", weights[i]);
        sum = sum + weights[i];
    }
    
    printf("Sum === %E\n", sum);
    
        
    
    
}
