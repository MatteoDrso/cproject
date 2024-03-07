#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int main(int argc, char *argv[]) 
{


  int c;
  int i = 0;
  int offset = 0;
  char buf[16];

  while (c = getchar(), c != EOF) {

    
    if (i == 0) {
      printf("%08x  ",offset);
    }

    printf("%x ", c);
    buf[i] = c;
    i++;
    offset++;

    if (i == 8) {
      printf(" ");
    }

    if (i == 16){
      printf(" |%s|", buf);
      memset(buf, '\0', sizeof buf);
      printf("\n");
      i = 0;
    }
  }
  for (int i = 0; i < (16 - (offset % 16)); i++) {
    printf("   ");
    if (i == 8) {
      printf(" ");
    }
  }
  printf(" |%s|", buf);
  printf("\n%08x  ", offset);

  printf("\n");
}