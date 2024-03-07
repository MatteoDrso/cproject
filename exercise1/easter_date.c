#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc != 2) {

    fprintf(stderr, "Please provide only a year!\n");
    return(1);

  }

  const int year = atoi(argv[1]);
  if (year == 0) {
    fprintf(stderr, "No number provided or year = 0!\n");
    return (1);
  }

  int a = year % 19;
  int b = year % 4;
  int c = year % 7;

  int k = year / 100;
  int p = k / 3;
  int q = k / 4;

  int M = (15 + k - p - q) % 30;
  int d = ((19 * a) + M) % 30;

  int N = (4 + k - q) % 7;
  int e = (2*b + 4*c + 6*d + N) % 7;

  int Ostern = (22 + d + e); 

  if (Ostern < 32) {
    printf("Easter date for %d is the %d. of March.\n", year, Ostern);
  } else {
    Ostern = Ostern % 31;
    printf("Easter date for %d is the %d. of April.\n", year, Ostern);
  }
}