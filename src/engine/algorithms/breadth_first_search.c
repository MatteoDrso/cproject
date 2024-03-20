#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "canvas.h"
#include "data_structures.h"

int breadth_first_search(canvas *c){
  queue q;
  queue_init(&q, (c->width * c-> height));

  c->start->status = START;
  bool end_found = false;

  queue_push(&q, c->start);

  int time_stamp = 1;
  while(!queue_is_empty(&q)) {
    pixel *p = queue_pop(&q);
    // printf("Visiting: %d, %d\n\n", p->x, p->y);

    if (p->status == END) {
      // printf("\nEnd reached.\n\n");
      int i = 0;
      while (p->status != START) {
        c->path[i] = p;
        
        p = p->parent;
        i++;
      }
      c->path[i] = p; 

      free(q.queue_arr);
      // Success, path found and stored in c->path
      return 0;
    }

    struct pixel *nb[4];

    neighbours(c, p, nb);
    for (int i = 0; i < 4; i++) {
      if (nb[i]->status == UNVISITED) {
        // printf("Looking at neighbour[%d]: %d, %d status: %d\n", i, nb[i]->x, nb[i]->y, nb[i]->status);
        nb[i]->parent = p;
        nb[i]->status = time_stamp;
        queue_push(&q, nb[i]);

        time_stamp++;
      } else if (nb[i]->status == END && !end_found) {
        // printf("End found at: %d, %d!\n", nb[i]->x, nb[i]->y);
        end_found = true;
        nb[i]->parent = p;
        queue_push(&q, nb[i]);

        time_stamp++;
      } 
      else {
        // printf("Not looking at neighbour[%d]. Reason: neighbour[%d]->status == %d\n", i, i, nb[i]->status);
      }
    }

  }

  // Something went wrong, path not found
  free(q.queue_arr);
  return 1;
}
