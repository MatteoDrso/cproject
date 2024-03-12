#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ppm_editor.h"

bool writeToFile(FILE *f, struct ppm_bild *img, char *format);
bool readFromFile(FILE *f, struct ppm_bild *img);
bool getFileMetadata(FILE *f, int *width, int *height, int *brightness);
bool readPixel(FILE *f, struct pixel *p);



bool writeToFile(FILE *f, struct ppm_bild *img, char *format){

    fprintf(f, "%2s\n%d %d\n%d\n", format, img->breite, img->hoehe, img->max_helligkeit);
    int pixel_num = img->breite * img->hoehe;
    for(int i = 0; i < pixel_num; i++){
        fprintf(f, "%d %d %d ", img->leinwand[i].red, img->leinwand[i].green, img->leinwand[i].blue);
    }
    fflush(f);
    fclose(f);

    return true;

}

bool readFromFile(FILE *f, struct ppm_bild *img){

    if(!getFileMetadata(f, &img->breite, &img->hoehe, &img->max_helligkeit)){
        return 1;
    }

    long int img_size = img->breite * img->hoehe;
    img->leinwand = malloc(img_size * sizeof(struct pixel));

    int isEof;

    for(int i = 0; i < img_size; i++){
        isEof = readPixel(f, &img->leinwand[i]);
        if(isEof) perror("Reached EOF while parsing");
    }
    
    //free(img->leinwand);

    return 0;
}

bool getFileMetadata(FILE *f, int *width, int *height, int *brightness){

    char format[3]; //3 bc length is 2 and it is 0 terminated

    fscanf(f, "%2s\n%d %d\n%d", format, width, height, brightness);

    if(strcmp(format,"P3")!=0){
        printf("Error! Format is not P3 but %2s\n", format);
        return false;
    }

    return true;
}

bool readPixel(FILE *f, struct pixel *p){

    int firstChar;
    int isEof;

    do{
        firstChar = getc(f);
        isEof = feof(f);
        if(isEof!=0){
            clearerr(f);
            return 1;
        }
    } while(firstChar==' ' || firstChar=='\n');

    ungetc(firstChar, f);
    fscanf(f, "%d %d %d", &p->red, &p->green, &p->blue);
    return 0;
}


int main(int argc, char *argv[]){

    FILE *f = fopen("Ohrenwarm.ppm", "r");
    struct ppm_bild img;
    struct ppm_bild *filteredImage;
    int filter[3][3];
    filter[0][0] = -1;
    filter[0][1] = -2;
    filter[0][2] = -1;
    filter[1][0] = 0;
    filter[1][1] = 0;
    filter[1][2] = 0;
    filter[2][0] = 1;
    filter[2][1] = 2;
    filter[2][2] = 1;

    readFromFile(f, &img);

    filteredImage = applyFilter(&img, filter, 'r');
    struct ppm_bild *filteredImage1 = applyFilter(filteredImage, filter, 'g');
    free(filteredImage->leinwand); free(filteredImage);
    struct ppm_bild *filteredImage2 = applyFilter(filteredImage1, filter, 'b');
    free(filteredImage1->leinwand); free(filteredImage1);

    FILE *f_filt = fopen("Ohrenwarm_filt.ppm", "w+");
    writeToFile(f_filt, filteredImage, "P3");


    return 0;
}
