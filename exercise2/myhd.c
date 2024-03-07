#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void printArray(int num){
    printf("%08x ",num);
    printf("  ");
}

int main(void){
    int c;
    int addr = 0;
    do {
        printArray(addr);
        char endStr[18];
        endStr[0] = '|';
        for(int i = 0; i < 16; i++) {
            c = getchar();

            if (c == EOF) {
                printf("   ");
                break;
            }
            printf("%02x ",c);

            if(!isprint(c)){
                endStr[i+1] = '.';
            }else {
                endStr[i+1] = c;
            }
            
            if(i == 8){
                printf(" ");
            }
            
            addr++;
        }
        endStr[17] = '|';
        for (int i = 0; i < 18; i++) {
            printf("%c", endStr[i]);    
        }
        printf("\n");
        
    }while (c != EOF);
    printArray(addr);
    printf("\n");
}