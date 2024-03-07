#include <stdio.h>

int main(void)
{

  for (int i = 0; i < 100; i++) {
    int a = i * i;

    int b = 1;
    for (int y = i; y > 0; y--) {
      b = b * 2;
    }
    
    int c = 1; 
    for (int x = i; x > 0; x--) {
      c = c * x;
    }

    printf("%4d %11d %11d\n",a,b,c);
  
  }

}

