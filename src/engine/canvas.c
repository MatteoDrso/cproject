#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "canvas.h"

canvas init_canvas(int width, int height, int start_x, int start_y, int end_x, int end_y) {
  canvas c;
  c.width = width;
  c.height = height;

  c.start_x = start_x;
  c.start_y = start_y;
  c.end_x = end_x;
  c.end_y = end_y;

  c.canv = malloc(sizeof (pixel) * height * width);
  c.path = malloc(sizeof c.canv);

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      pixel p;
      p.status = UNVISITED;
      c.canv[i * width + j] = p;
    }
  }

  return c;
}

// Returns Pixels in order: North, East, South, West
void neighbours(canvas *c, int x, int y, struct pixel **n){
  n[NORTH] = at(c, x, y-1);
  n[EAST] = at(c, x+1, y);
  n[SOUTH] = at(c, x, y-1);
  n[WEST] = at(c, x-1, y);
}