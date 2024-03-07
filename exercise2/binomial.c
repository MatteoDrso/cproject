#include <stdio.h>
#include <stdlib.h> 

unsigned long binomial (unsigned long n, unsigned long k);

int main(int argc, char *argv[])
{
    if (argc != 3) {

    fprintf(stderr, "Please call the program as '%s n k' \n", argv[0]);
    return(1);

  }

  char *endptr;

  unsigned long n = strtoul(argv[1], &endptr, 10);
  if (*endptr != '\0') {
    printf("conversion error: %s\n", argv[1]);
    return 1;
  }

  unsigned long k = strtoul(argv[2], &endptr, 10);
  if (*endptr != '\0') {
    printf("conversion error: %s\n", argv[2]);
    return 1;
  }

  unsigned long result = binomial (n, k);
  printf("%lu\n", result);

  return 0;
}

  unsigned long binomial (unsigned long n, unsigned long k) {
    if (n < k || n == 0) {
      printf("n is smaller than k or n is zero.\n");
      return 0;
    }

    if (k == 0) {
      return 1;
    }

    unsigned long product1 = 1;
    for (unsigned long i = 1; i <= n; i++) {
      product1 *= i;
      printf("Product1: %d\n", product1);
    }

    unsigned long product2 = 1;
    for (unsigned long i = 1; i <= k; i++) {
      product2 *= i;
      printf("Product2: %d\n", product2);
    }

    unsigned long product3 = 1;
    for (unsigned long i = 1; i <= (n-k); i++) {
      product3 *= i;
      printf("Product3: %d\n", product3);
    }

    product2 *= product3;

    return (product1 / product2);
  
  }