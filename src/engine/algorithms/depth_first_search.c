#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../canvas.h"
#include "../data_structures.h"

static int step(canvas *c, struct stack *s, pixel *p);

int depth_first_search(canvas *c){
  
  struct stack s;
  pixel *p = c->start;
  bool found = false;

  stack_init(&s, c->height*c->width);
  stack_push(&s, p);

  while(!stack_is_empty(&s) && !found){
    p = stack_pop(&s);
    if (p->status == END) {
      found = true;
      continue;
    }
    if(p->status<START){
      printf("This (x: %d, y: %d) is not a unvisited pixel. It has status %d.\n", p->x, p->y, p->status);
      abort();
    }
    step(c, &s, p);
  }

  if(found){
    printf("Found goal at %d, %d\n", p->x, p->y);
  } else {
    printf("Goal unreachable\n");
  }
}

static int step(canvas *c, struct stack *s, pixel *p){

    pixel *n[4];
    pixel *temp;
    neighbours(c, p, n); 

    for(int i = 0; i < 4; i++){
        temp = n[i];
        if(is(temp, UNVISITED)){
            temp->status = p->status + 1;
            stack_push(s, temp);
        } else if (is(temp, END)){
            stack_push(s, temp);
        }
    } 
}
