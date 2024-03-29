#include <stdio.h>
#include <stdlib.h>
#include "canvas.h"
#include "data_structures.h"
#include "algorithms.h"
#include "gui/file_handler.h"

int main(int argc, char *argv[]) {
  printf("This is an interactive Pathfinding visualizer.\n");
  printf("Reading this file: %s\n", argv[1]);

  canvas c;

  int ret = read_canvas_from_file(argv[1], &c);
  if(ret != 0){
    printf("error occured: %d\n", ret);
    abort();
  }

  printf("Canvas: \n");
  print_canvas(&c);

  int algorithm = 0;
  puts("What Algorithm do you want to see? \n1 -> BFS\n2 -> DFS");//\n4 -> A*
  printf("Algorithm: ");
  while(scanf("%d", &algorithm), algorithm < 0 || algorithm > 3){
    //clear input buffer
    while (getchar() != '\n');

    printf("Invalid input. Please enter a number from one of the algorithms above.\n");
    printf("Algorithm: ");
  }
  
  int failed = 1;

  switch(algorithm){
    case 1: failed = breadth_first_search(&c);
            if (failed) {
              printf("BFS failed!\n");
              abort();
            } else {
              printf("BFS succeeded!\n");
            }
            break;
    case 2: failed = depth_first_search(&c);
            if (failed) {
              printf("DFS failed!\n");
              abort();
            } else {
              printf("DFS succeeded!\n");
            }
            break;
/*  case 3: failed = dijkstra(&c);
            if (failed) {
              printf("Dijkstra failed!\n");
              abort();
            } else {
              printf("Dijkstra succeeded!\n");
            }
            break;
    case 4: failed = a_star(&c);
            if (failed) {
              printf("A* failed!\n");
              abort();
            } else {
              printf("A* succeeded!\n");
            }
            break;*/
   default: puts("How did you get here?");
            break;
  }

    draw_path_on_canvas(&c);

    printf("Canvas: \n");
    print_canvas(&c);
    print_path(&c);

    free_canvas(&c);

  return 0;
}
