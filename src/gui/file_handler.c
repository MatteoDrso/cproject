#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "file_handler.h"
#include "../engine/canvas.h"

enum {
    MAX_HEIGHT = 256,
    MAX_WIDTH = 256,
};

int read_canvas_from_file(char *file_name, canvas *return_canvas){

    FILE *f = fopen(file_name, "r");
    if (f == NULL) {
        perror(file_name);
        return -1;
    }

    int c;
    int width, height;
    pixel *new_pixel_canvas;

    // This function reads in the first row of the canvas which has to consists exclusivley of '#' and implies by that the width of the canvas.
    short int width_counter = 0;
    for(;;){
        c = fgetc(f);
        if(c=='#'){
            if(width_counter<MAX_WIDTH){
                width_counter++;
            } else {
                return MAX_CANVAS_WIDTH_EXCEEDED;
            }
        } else if (c=='\n') {
            width = width_counter;
            break;
        } else {
            return ILLEGAL_BORDER_ELEMENT;
        }     
    }

    pixel p;

    new_pixel_canvas = calloc(width, sizeof(pixel));
    for(int i = 0; i < width; i++){
        p.x = i;
        p.y = 0;
        p.status = WALL;
        new_pixel_canvas[i] = p;
    }

    width_counter =  0;
    short int height_counter = 1;
    int start_count = 0;
    int end_count = 0;
    bool last_row_border = true;
    bool map_read = false;
    int start_x, start_y, end_x, end_y;

    new_pixel_canvas = reallocarray(new_pixel_canvas, width*(height_counter+1), sizeof(pixel));

    while(!map_read){
        c = fgetc(f);
        //printf("%d, %d\n", width_counter, height_counter);
        //printf("c: %d (%c)", c, c);

        switch(c){
            case '#':
                p.status = WALL;
                break;
            case 'S':
                if(start_count != 0) return ILLEGAL_START_COUNT;
                if(width_counter == 0 || width_counter == width) return ILLEGAL_BORDER_ELEMENT;
                p.status = START;
                start_x = width_counter;
                start_y = height_counter;
                start_count++;
                last_row_border = false;
                break;
            case 'E': 
                if(end_count != 0) return ILLEGAL_END_COUNT;
                if(width_counter == 0 || width_counter == width) return ILLEGAL_BORDER_ELEMENT;
                p.status = END;
                end_x = width_counter;
                end_y = height_counter;
                end_count++;
                last_row_border = false;
                break;
            case ' ':
                if(width_counter == 0 || width_counter == width) return ILLEGAL_BORDER_ELEMENT;
                p.status = UNVISITED;
                last_row_border = false;
                break;
            case '\n':
                height_counter++;
                if(width_counter != width) return INCONSISTENT_CANVAS_SIZE;
                c = fgetc(f);
                if (c != 'E' && c != 'S' && c != ' ' && c != '#'){
                    if(!last_row_border) return ILLEGAL_BORDER_ELEMENT;
                    height = height_counter;
                    map_read = true;
                    if(end_count != 1) return ILLEGAL_END_COUNT;
                    if(start_count != 1) return ILLEGAL_START_COUNT;
                }else{
                    if(height_counter>MAX_HEIGHT) return MAX_CANVAS_HEIGHT_EXCEEDED;
                    ungetc(c, f);
                    c = '\n';
                    last_row_border = true;
                    new_pixel_canvas = reallocarray(new_pixel_canvas, width*(height_counter+1), sizeof(pixel));
                    if(new_pixel_canvas == NULL) return CANVAS_FILE_READ_REALLOC_FAILURE;
                    width_counter=0;
                }
                break;
            default:
                return ILLEGAL_ELEMENT;
        }
        if(c != '\n'){
            p.x = width_counter;
            p.y = height_counter;
            new_pixel_canvas[height_counter*width+width_counter] = p;
            width_counter++;
        }

    }

    /*
    for(;;){
        bits_read = getline(temp, width+1, f);
        if(bits_read == 1 && temp[0] == '\n'){
            height = counter;
            break;
        }
        if(bits_read-1 != width || temp[width-1]!='\n') return INCONSISTENT_CANVAS_SIZE;

        new_canv = reallocarray(new_canv, width, sizeof(pixel));
        if(new_canv == NULL) return CANVAS_FILE_READ_REALLOC_FAILURE;
        for(int i = 0; i < width-1; i++) new_canv[counter*width+i] = temp[i];
        counter++;

    }*/
    *return_canvas = init_canvas(width, height, start_x, start_y, end_x, end_y);
    pixel *return_val = memcpy(return_canvas->canv, new_pixel_canvas, height*width*sizeof(pixel));
    if(return_val == NULL){
        return CANVAS_PIXEL_ARRAY_MEMCPY_FAILURE;
    }

    free(new_pixel_canvas);
    fclose(f);

    print_canvas(return_canvas);

    return 0;
}


int main(int argc, char *argv[]){
    
    canvas c;

    int err = read_canvas_from_file(argv[1], &c);
    printf("%d\n", err);
    
    free(c.canv);
    free(c.path);

}