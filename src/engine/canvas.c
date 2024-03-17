#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "canvas.h"

canvas init_canvas(int width, int height, int start_x, int start_y, int end_x, int end_y) {
  canvas c;
  c.width = width;
  c.height = height;

  c.canv = malloc(sizeof (pixel) * height * width);
  c.path = malloc(sizeof c.canv);

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      pixel p;
      p.x = j;
      p.y = i;
      if(i == 0 || j == 0 || i == height-1 || j == width-1) {
        p.status = WALL;
      } else {
        p.status = UNVISITED;
      }
      c.canv[i * width + j] = p;
    }
  }

  c.start = at(&c, start_x, start_y);
  c.end = at(&c, end_x, end_y);

  if(is(c.start, WALL)){
    printf("Illegal start point. The start has to be inbounds. Start at: [%d, %d]\n", c.start->x, c.start->y);
    abort();
  } else {
    c.start->status = START;
  }
if(is(c.end, WALL)){
    printf("Illegal end point. The end has to be inbounds. End at: [%d, %d]\n", c.start->x, c.start->y);
    abort();
  } else {
    c.start->status = END;
  }

  return c;
}


void print_canvas(canvas *c){

  pixel *p;

  for (int i = 0; i < c->height; i++) {
    for (int j = 0; j < c->width; j++) {
      p = at(c, i, j);
      switch (p->status){
        case WALL:
          printf(" # ");
          break;
        case START:
          printf(" S ");
          break;
        case UNVISITED:
          printf("   ");
          break;
        case END:
          printf(" E ");
          break;
        default:
          if(p->status > 0){
            printf(" x ");
          } else {
            printf(" ? ");
          }
      }
    }
    printf("\n");
  }

}

// Returns Pixels in order: North, East, South, West
void neighbours(canvas *c, pixel *current_pixel, struct pixel **n){
  int x = current_pixel->x;
  int y = current_pixel->y;
  n[NORTH] = at(c, x, y-1);
  n[EAST] = at(c, x+1, y);
  n[SOUTH] = at(c, x, y-1);
  n[WEST] = at(c, x-1, y);
}
