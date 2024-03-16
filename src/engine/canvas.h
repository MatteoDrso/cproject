#include <stdbool.h>

#ifndef PATHFIND_CANVAS_H
#define PATHFIND_CANVAS_H

typedef struct pixel{
  int status;
  int x, y;
} pixel;

typedef struct canvas{
  int width, height;

  pixel *start, *end;

  pixel *canv;

  int *path; //array of offsets
}canvas;

//imported as static, to fasten up runtime as function is inserted inline (ask Robert lol).
static inline struct pixel *at(canvas *c, int x, int y)
{
  return &c->canv[y * c->width + x];
}

static inline bool is(pixel *p, int status){
  return p->status == status;
}

static inline struct pixel *at_offset(canvas *c, int o)
{
  // if you want to calculate coords using offset:
  // int y = o % c->width;
  // int x = o - (c->width * y) 
  return &c->canv[o];
}


canvas init_canvas(int width, int height, int start_x, int start_y, int end_x, int end_y);
void print_canvas(canvas *c);
void neighbours(canvas *c, int x, int y, struct pixel **n);


enum directions {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

enum status {
    WALL = -2,
    UNVISITED = -1,
    START = 0,
    END = -3,
};

#endif
