#include <stdio.h>
#include "convert.h"

int main(void){
    
    int int_a = 97;
    char char_a = 'a';

    int out_a = myatoi(char_a);
    printf("convertion from \'a\' with myatoi(char_a) to %d\n", out_a);

    char out_char_a = myitoa(int_a);
    printf("convertion from 97 with myatoi(int_a) to %c\n", out_char_a);       

    int int_42 = 42;
    char char_42 = '*';

    int out_int_42 = myatoi(char_42);
    printf("convertion from \'*\' with myitoa(char_42) to %d\n", char_42);

    char out_char_42 = myitoa(int_42);
    printf("convertion from 42 myitoa(int_42) to %c\n", int_42);      
}