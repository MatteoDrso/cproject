#include <stdio.h>
#include <stdlib.h>

int main(void){
    int c;

    while (c = getchar(), c != EOF) {
        if((c >= 78 && c <= 103) || (c >= 110 && c <= 127)){
            putchar(c+13);
        }
    }
    printf("\n");
    return 0; 
}