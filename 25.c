#include <stdio.h>

int main (void)
{
FILE *file = fopen("out.txt", "r");
if (!(long)file) return 1;

printf("\n");

int dd = 0;
float a = 0;
float b = 0;
float c = 0;
int d = 0;
while(1) {
    fscanf(file, "%i %f %f %f %i,", &dd , &a , &b , &c , &d);
    if (feof(file)) break;
    printf("%f\n", a * 0.25);
  }
return 0;
}
