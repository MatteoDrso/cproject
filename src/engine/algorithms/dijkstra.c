#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "canvas.h"
enum {
	WEIGHT_WALL = 1024,
	WEIGHT_PATH = 1
};

// is copy of canvas as matrix, saves 
// dist from start for each pixel
static int **distanceMatrix;

// also some structures or variable to save path to end

int copyArray(int *from[], int *to[]);

int getHeight(int *arg);
int getWidth(int *arg);

int dijkstra(canvas *c){

	// init canvas, start and end
	canvas c = init_canvas();
	pixel start = at(canvas.canv, canvas.start_x, canvas.start_y);
	start.visited = true;
	
	//init a currentPixel which points always to the Pixel which we are on
	pixel *currentPixel = malloc(sizeof(pixel *currentPixel));
	int *cPX = canvas.start_x;  
	int *cPY = canvas.start_y; 
	
	int found = 1;
	while(found != 0){
		found = step2(currentPixel);
	}

	//go through distMatrix
}

int copyMatrix(int *from[], int *to[]){
	for(int i=0; i<canvas.width; i++){
		for(int j=0; j<canvas.height){
			to[i][j] = from[i][j];	
		}
	}	
}

// also give cpX/Y and canvas
int step2(pixel *currentPixel){

	// find adjacent dist node from [top,right,bottom,left]	
	pixel neighbours[4] = getNeighbours(start);
	
	for(int i=0; i<4; i++){
		if(neighbours[i] == 1){
			*currentPixel = neighbours[i];
			distanceMatrix[][] = 
		}
	}

	// mark as visited	
	currentPixel->visited = true;

	// writed dist value to distMatrix
	
	// repeat until canvas->end is found

}






