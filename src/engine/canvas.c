#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct pixel {
  bool visited, wall;
};

struct canvas {
  int width, height;

  struct pixel *start;
  struct pixel *end;

  struct pixel *canv;
};

struct canvas init_canvas(int width, int height) {
  struct canvas c;
  c.width = width;
  c.height = height;
  c.canv = malloc(sizeof(struct pixel) * width * height);

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      struct pixel p;
      p.visited = false;
      p.wall = true;
      c.canv[i * j] = p;
    }
  }

  return c;
}

int main(void) {
  struct canvas c = init_canvas(3, 2);
  printf("%d %d\n",c.canv[0].visited, c.canv[0].wall);

  return 0;
}