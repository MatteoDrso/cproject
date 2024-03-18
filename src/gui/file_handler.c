#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "file_handler.h"
#include "../engine/canvas.h"

int read_canvas_from_file(char *file_name){

    FILE *f = fopen(file_name, "r");
    char c;
    int width;
    char *new_canv;
    //canvas->canv = 

    // This function reads in the first row of the canvas which has to consists exclusivley of '#' and implies by that the width of the canvas.
    short int counter = 0;
    for(;;){
        c = fgetc(f);
        if(c=='#'){
            if(counter<256){
                counter++;
            } else {
                return MAX_CANVAS_WIDTH_EXCEEDED;
            }
        } else if (c=='\n') {
            width = counter;
            break;
        } else {
            return ILLEGAL_BORDER_ELEMENT;
        }     
    }

    counter =  0;
    char temp[width];
    char *curr_row;

    for(;;){
        curr_row = fgets(temp, width+2, f);
        if(curr_row[width+1]!='\0' || curr_row[width]!='\n') return INCONSISTENT_CANVAS_WIDTH;

        new_canv = reallocarray(new_canv, width, sizeof(pixel));
        if(new_canv == NULL) return CANVAS_FILE_READ_REALLOC_FAILURE; 
        canvas->canv = new_canv;
        for(int i = 0; i < canvas->width; i++){
            canvas->canv[canvas->width*counter+i] = fgetc(f);

        }
    }
}