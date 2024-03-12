#include "ppm_editor.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void convertToGrayscale(struct ppm_bild *img){

    int numPixel = img->hoehe * img->breite;

    struct pixel *p;

    for(int i = 0; i<numPixel; i++){
        p = &img->leinwand[i];

        //source: https://support.ptc.com/help/mathcad/r9.0/en/index.html#page/PTC_Mathcad_Help/example_grayscale_and_color_in_images.html
        p->red = p->green = p->blue = (int) round(0.299 * p->red) + (int) round(0.587 * p->green) + (int) round(0.114 * p->blue);
    }

}

struct coord {
    int x, y;
};

struct ppm_bild* applyFilter(struct ppm_bild *img, int filter[3][3], char color){
    int imgSize = img->breite * img->hoehe;
    struct ppm_bild *filteredImage = malloc(sizeof(struct ppm_bild));
    filteredImage->leinwand = malloc(imgSize * sizeof(struct pixel));
    filteredImage->hoehe = img->hoehe;
    filteredImage->breite = img->breite;
    filteredImage->max_helligkeit = img->max_helligkeit;

    struct coord c;
    int currSum = 0;
    int absoluteX, absoluteY;

    for(int i = 0; i < img->breite; i++){
        for(int j = 0; j < img->hoehe; j++){
            c.x = i;
            c.y = j;
            for(int w = -1; w<=1; w++){
                for(int h = -1; h<=1; h++){
                    absoluteX = c.x+w;
                    absoluteX = absoluteX < 0 || absoluteX > img->breite-1 ? -1 : absoluteX;

                    absoluteY = c.y+h;
                    absoluteY = absoluteY < 0 || absoluteY > img->hoehe-1 ? -1 : absoluteY;

                    if(absoluteX < 0 || absoluteY < 0){
                        continue;
                    }

                    switch (color){
                    case 'r':
                        currSum = currSum + (filter[w+1][h+1] * (img->leinwand[absoluteY*j+absoluteX].red));
                        break;
                    case 'g':
                        currSum = currSum + (filter[w+1][h+1] * (img->leinwand[absoluteY*j+absoluteX].green));
                        break;
                    case 'b':
                        currSum = currSum + (filter[w+1][h+1] * (img->leinwand[absoluteY*j+absoluteX].blue));
                        break;
                    default:
                        perror("Color has to be of 'r', 'g' or 'b'.");
                    }
                }
            }
            switch (color){
                    case 'r':
                        filteredImage->leinwand[c.y*img->hoehe+c.x].red = currSum;
                        break;
                    case 'g':
                        filteredImage->leinwand[c.y*img->hoehe+c.x].green = currSum;
                        break;
                    case 'b':
                        filteredImage->leinwand[c.y*img->hoehe+c.x].blue = currSum;
                        break;
                    default:
                        perror("Color has to be of 'r', 'g' or 'b'.");
                    }
            currSum=0;
        }
    }

    return filteredImage;
}
