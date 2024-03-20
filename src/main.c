#include <stdio.h>
#include "canvas.h"
#include "data_structures.h"
#include "algorithms.h"

int main(void) {
  printf("This is an interactive Pathfinding visualizer.\n");
  printf("Please enter the width and height of the Canvas in which the algorithms should search:\n");

  int height;
  printf("Height: ");
  while(scanf("%d", &height) != 1)
  {
    //clear input buffer
    while (getchar() != '\n');

    printf("Invalid input. Please enter an integer.\n");
    printf("Height: ");
  }

  int width;
  printf("Width: ");
  while(scanf("%d", &width) != 1)
  {
    //clear input buffer
    while (getchar() != '\n');

    printf("Invalid input. Please enter an integer.\n");
    printf("Width: ");
  }

  printf("Thank you! Now enter the coordinates where the algorithm should start.\n");
  int start_x = 0;
  printf("x: ");
  while(scanf("%d", &start_x) != 1)
  {
    //clear input buffer
    while (getchar() != '\n');

    printf("Invalid input. Please enter an integer >= 1 and <= width-2.\n");
    printf("x: ");
  }

  int start_y;
  printf("y: ");
  while(scanf("%d", &start_y) != 1)
  {
    //clear input buffer
    while (getchar() != '\n');

    printf("Invalid input. Please enter an integer >= 1 and <= height-2.\n");
    printf("y: ");
  }


  canvas c = init_canvas(width,height, start_x, start_y, 1,1);

  printf("Canvas: \n");
  print_canvas(&c);

  int algorithm = 0;
  puts("What Algorithm do you want to see? \n1 -> BFS\n2 -> DFS\n3 -> Dijkstra\n4 -> A*");//\n4 -> A*
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
            } else {
              printf("BFS succeeded!\n");
            }
            break;
    case 2: failed = depth_first_search(&c);
            if (failed) {
              printf("DFS failed!\n");
            } else {
              printf("DFS succeeded!\n");
            }
            break;
    case 3: failed = dijkstra(&c);
            if (failed) {
              printf("Dijkstra failed!\n");
            } else {
              printf("Dijkstra succeeded!\n");
            }
            break;
    case 4: failed = a_star(&c);
            if (failed) {
              printf("A* failed!\n");
            } else {
              printf("A* succeeded!\n");
            }
            break;
   default: puts("How did you get here?");
            break;
  }

  draw_path_on_canvas(&c);

  failed = canv_to_file(&c, "found_canv.txt");
  if (failed) {
    printf("canv_to_file failed. Errorcode: %d", failed);
  }

  printf("Canvas: \n");
  print_canvas(&c);

  print_path(&c);

  free_canvas(&c);

  return 0;
}
