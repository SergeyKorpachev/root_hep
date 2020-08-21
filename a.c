#include <stdio.h>

int main (void)
{
FILE *file = fopen("aaaaa", "r");
if (!(long)file) return 1;

printf("\n");

float a = 0;
while(1) {
    fscanf(file, "%f", &a);
    if (feof(file)) break;
    printf("%f\n", a * 0.2);
  }
return 0;
}
