#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#inlcude "canvas.h"

enum {
	WEIGHT_PATH = 1;
};

// is copy of canvas as matrix, saves dist from start for each pixel
static int **distanceMatrix;

int copyMatrix(int *from[], int *to[]);

//int -1 failed, 0 when ok
int dijkstra(canvas *c){
	
	if(something){
		return -1;//algorithm failed
	}

	// init canvas, start and end
	pixel *start = at(canvas.canv, canvas.start_x, canvas.start_y);
	start->visited = true;
	
	//init a currentPixel which points always to the Pixel which we are on
	pixel *currentPixel = malloc(sizeof(pixel *currentPixel));
	currentPixel = start;

	int cPX = canvas.start_x;  
	int cPY = canvas.start_y; 
	
	int found = 1;
	while(found != 0){
		found = step2(&canvas, currentPixel, &cPX, &cPY);	
	}

	//go through distMatrix follow min path
	return 0;
}

int copyMatrix(int *from[], int *to[]){
	for(int i=0; i<canvas.width; i++){
		for(int j=0; j<canvas.height){
			to[i][j] = from[i][j];	
		}
	}	
}

int step2(canvas *c, pixel *cP, int *cpX, int *cpY){
	/*
	start: cP = prioQueue.dequeue
	1: counter += 1
	2: cp.status = counter
	3: if(cP.coords == end.coords){break;}
	4: iterate through neighbours of cP
		-> all with (n.status >= 0) in prioQueue
		-> and their distMatrix val is cP`s+1 (cP.coords are known)
	*/
	
	pixel *neigbours[4];

	/*start while(true){
		cP = prioQueue.dequeue
	
		//2:
		cP->status = counter;
	
		//3:
		if(cpX == c->end_x && cpY == c->end_y){
			break;
		}

		//4:
		//[north, east, south, west]	
		neighbours(c, cpX, cpY, &cP, neighbours);
	
		for(int i=0; i<4; i++){
			
		}
	}*/	

	return 0;
}






