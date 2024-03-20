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

  int failed = breadth_first_search(&c);

  if (failed) {
    printf("BFS failed!\n");
  } else {
    printf("BFS succeeded!\n");
  } 

  draw_path_on_canvas(&c);

  printf("Canvas: \n");
  print_canvas(&c);

  print_path(&c);

  free_canvas(&c);

  return 0;
}
