#ifndef EXERCISE3_PPM_EDITOR_H
#define EXERCISE3_PPM_EDITOR_H

#include <stdio.h>

struct pixel{
    int red, green, blue;
};

struct pixel_gs{
    int gval;
};

struct ppm_bild{
    int breite, hoehe;
    int max_helligkeit;

    struct pixel *leinwand;
};

struct ppm_gs_bild{
    int breite, hoehe;
    int max_helligkeit;

    struct pixel_gs *leinwand;
};

void convertToGrayscale(struct ppm_bild *img);
struct ppm_bild* applyFilter(struct ppm_bild *img, int filter[3][3], char color);

#endif