#ifndef PATHFIND_ALGORITHMS_H
#define PATHFIND_ALGORITHMS_H
#include "../canvas.h"
#include <stdbool.h>

int dijkstra(canvas *c);
int a_star(canvas *c);
int breadth_first_search(canvas *c);
int depth_first_search(canvas *c);

#endif
