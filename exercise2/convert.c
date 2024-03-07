#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {


  if (argc != 2) {

    fprintf(stderr, "Please provide only a single argument!\n");
    return(1);

  }

  
  int c = argv[1][0];

  int result = 0;
  int i = 0;
  
  while (c != '\0') {
    int mybreak = 0;
    switch ( c ) {
      case '0':
        result = result * 10;
        break;
      case '1':
        result = (result * 10) + 1;
        break;
      case '2':
        result = (result * 10) + 2;
        break;
      case '3':
        result = (result * 10) + 3;
        break;
      case '4':
        result = (result * 10) + 4;
        break;
      case '5':
        result = (result * 10) + 5;
        break;
      case '6':
        result = (result * 10) + 6;
        break;
      case '7':
        result = (result * 10) + 7;
        break;
      case '8':
        result = (result * 10) + 8;
        break;
      case '9':
        result = (result * 10) + 9;
        break;
      default:
        mybreak = 1;
    }
    if (mybreak) {
      break;
    }
    i++;
    c = argv[1][i];
  }
  
  printf("My atoi outout: %d\n", result);
  
  int n = atoi(argv[1]);
  printf("Standard atoi output: %d\n", n);
}