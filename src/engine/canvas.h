#ifndef PATHFIND_CANVAS_H
#define PATHFIND_CANVAS_H

struct pixel {
  bool visited, wall;
  int name;
};

typedef struct {
  int width, height;

  int start_x, start_y;
  int end_x, end_y;

  struct pixel *canv;
}canvas;

//imported as static, to fasten up runtime as function is inserted inline (ask Robert lol).
static struct pixel *at(canvas *c, int x, int y)
{
  return &c->canv[y * c->width + x];
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