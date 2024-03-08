#include "len.h"
#include <stdio.h>

#ifndef convert
#define convert

int myatoi(char c[]){
    int lengthStr = lenChar(c);
    int y;

    for(int i = 0; i < lengthStr; i++){
        int x = c[i];
        printf("x: %d \n", x);
        if(x >= 48 && x <= 57){
            y = y+(x-48);
        }

        if(!(i == lengthStr-1)){
            y *= 10;
        }   
    }
    return y;
}

char myitoa(int i){
    char c = i;
    return c;
}

#endif
