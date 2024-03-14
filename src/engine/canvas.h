#include <stdbool.h>

#ifndef PATHFIND_CANVAS_H
#define PATHFIND_CANVAS_H

typedef struct {
  bool visited, wall;
} pixel;

typedef struct {
  int width, height;

  int start_x, start_y;
  int end_x, end_y;

  char *path;

  struct pixel *canv;
}canvas;

//imported as static, to fasten up runtime as function is inserted inline (ask Robert lol).
static struct pixel *at(canvas *c, int x, int y)
{
  return &c->canv[y * c->width + x];
}

static struct pixel *at_offset(canvas *c, int o)
{
  // if you want to calculate coords using offset:
  // int y = o % c->width;
  // int x = o - (c->width * y)
  return &c->canv[o];
}

canvas init_canvas(int width, int height, int start_x, int start_y, int end_x, int end_y);
void neighbours(canvas *c, int x, int y, struct pixel **n);

enum directions {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

#endif