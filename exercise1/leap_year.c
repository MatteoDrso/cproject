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

  if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
    printf("Leap year\n");
    return (0);
  } else {
    printf("No Leap year\n");
  }

}