#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int c;

    while (c = getchar(), c != EOF) {
        if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)){
            putchar(c-13);   
        }
    }
    printf("\n");
    return 0;
}