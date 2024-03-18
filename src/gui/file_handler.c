#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "file_handler.h"
#include "../engine/canvas.h"

int read_canvas_from_file(char *file_name){

    FILE *f = fopen(file_name, "r");
    char c;
    canvas *canvas;
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
            canvas->width = counter;
            break;
        } else {
            return ILLEGAL_BORDER_ELEMENT;
        }     
    }

    counter =  0;
    canvas->canv = NULL;

    for(;;){
        canvas->canv = reallocarray(canvas->canv, canvas->width, sizeof(pixel))
        for(int i = 0; i < canvas->width; i++){

        }
    }
}