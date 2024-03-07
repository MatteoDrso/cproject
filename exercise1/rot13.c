#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    int c;
    
    while (c = getchar(), c != EOF) {
        putchar(c-13);
    }
    printf("\n");
    return 0;
}