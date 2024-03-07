#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_LENGTH 16

int main (int argc, char *argv[]){

    int c;
    int counter = 0;
    int row_counter = 0;
    int row_content[MAX_ROW_LENGTH];
    memset(row_content, ' ', sizeof(row_content)/sizeof('a'));

    printf("%x | ", row_counter);

    while(c = getchar(), c != EOF){

        if(counter<MAX_ROW_LENGTH){
            printf("%x, ", c);
            row_content[counter] = c;
            counter++;
        } else {
            row_counter++;
            printf("%x | ", c);
            for(int i = 0; i < MAX_ROW_LENGTH; i++)
                printf("%c", row_content[i]);
            printf("\n%x | ", row_counter*MAX_ROW_LENGTH);
            counter=0;
            memset(row_content, ' ', sizeof(row_content)/sizeof('a'));
        }
    }

    printf(" | ");

    for(int i = 0; i < MAX_ROW_LENGTH; i++)
        printf("%c", row_content[i]);

    putchar(10);

    return 0;
}