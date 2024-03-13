#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

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

struct pixel *at(canvas *c, int x, int y)
{
  return &c->canv[y * c->width + x];
}

// Returns Pixels in order: North, East, South, West
void neighbours(canvas *c, int x, int y, struct pixel **n)
{
  if (y > 0 && y <= c->height && x >= 0 && x <= c->width) {
    n[0] = at(c, x, y-1);      
    } else {
    n[0] = NULL;
  }
  if (y >= 0 && y <= c->height && x >= 0 && x < c->width-1) {
    n[1] = at(c, x+1, y);
  } else {
    n[1] = NULL;
  }
  if (y >= 0 && y < c->height-1 && x >= 0 && x <= c->width) {
    n[2] = at(c, x, y+1);
  } else {
    n[2] = NULL;
  }
  if (y >= 0 && y <= c->height && x > 0 && x <= c->width) {
    n[3] = at(c, x-1, y);
  } else {
    n[3] = NULL;
  }
}


int main(void) {
  canvas c = init_canvas(3, 3, 0, 0, 1, 1);

  printf("Coordinate[2,2] %d\n", at(&c,2,2)->name );
  printf("visited[2,2] %d\n", at(&c,2,2)->visited );
  printf("wall[2,2] %d\n", at(&c,2,2)->wall);

  struct pixel *n[4];
  neighbours(&c, 2, 2, n);
  for (int i = 0; i < 4; i++) {
    if (n[i] != NULL) {
      printf("Nachbar %d: %d\n",i, n[i]->name);
    }
  }

  return 0;
}