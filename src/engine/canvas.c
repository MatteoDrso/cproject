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

  c.canv = malloc(sizeof (struct pixel) * height * width);

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      struct pixel p;
      p.visited = false;
      p.wall = true;
      p.name = 2;
      c.canv[i * width + j] = p;
    }
  }

  return c;
}

// Returns Pixels in order: North, East, South, West
void neighbours(canvas *c, int x, int y, struct pixel **n)
{
  if (y > 0 && y <= c->height && x >= 0 && x <= c->width) {
    n[NORTH] = at(c, x, y-1);      
    } else {
    n[NORTH] = NULL;
  }
  if (y >= 0 && y <= c->height && x >= 0 && x < c->width-1) {
    n[EAST] = at(c, x+1, y);
  } else {
    n[EAST] = NULL;
  }
  if (y >= 0 && y < c->height-1 && x >= 0 && x <= c->width) {
    n[SOUTH] = at(c, x, y+1);
  } else {
    n[SOUTH] = NULL;
  }
  if (y >= 0 && y <= c->height && x > 0 && x <= c->width) {
    n[WEST] = at(c, x-1, y);
  } else {
    n[WEST] = NULL;
  }
}