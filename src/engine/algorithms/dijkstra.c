#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../canvas.h"
#include "../data_structures.h"


// is copy of canvas as matrix, saves dist from start for each pixel
static int *distance_matrix;
static void init_dist_matrix(canvas *canvas);
static int find_end(canvas *c, pixel *cP, min_Heap *h);
static void get_path(canvas *canvas, pixel *current_pix, int *dist_matrix);
static pixel *get_min_neighbour(canvas *c, pixel *cP, pixel **n, int *dm);
static int get_dist(pixel *p1, pixel *p2);
static int canvas_empty(canvas *c);

//int main(void){return 0;}// for compiling

//int -1 failed, 0 when ok
int dijkstra(canvas *canvas){
	
	int exit_var = -1;	
	if(canvas_empty(canvas)){
		return exit_var;//algorithm failed
	}
	//init distance matrix
	init_dist_matrix(canvas);
	
	canvas->start->status = 0;//may not be necessary	
	min_Heap min_heap;
	min_Heap_init(&min_heap, canvas->height*canvas->width);
	min_Heap_insert(&min_heap, canvas->start, 0);

	//init a current_pixel which points always to the Pixel which we are on
	pixel *current_pixel = malloc(sizeof(pixel *));
	
	int found = find_end(canvas, current_pixel, &min_heap);		
	min_Heap_clear(&min_heap);//frees all allocated memory for this structure

	if(found)
	{
		//go through distMatrix follow min path
		get_path(canvas, current_pixel, distance_matrix);
		exit_var = 0;
	}
	
	free(current_pixel);
	return exit_var;
}

static int find_end(canvas *c, pixel *cP, min_Heap *h){
	
	int status_counter = -1;
	int dist_to_start = 0;
	pixel *n[4];
	int found = 0;
	int canv_size = c->height*c->width;

	for(int i=0; i<canv_size; i++){
		cP = min_Heap_pop(h);
		dist_to_start = get_dist(c->start, cP);//start.coords - cP.coords	
		distance_matrix[cP->y * c->width + cP->y] = dist_to_start;
	
		//neighbours of end not relevant, dist are
		if(cP->status == -3){
			found = 1;
			break;
		}

		status_counter++;
		cP->status = status_counter;
	
		//[north, east, south, west]	
		neighbours(c, cP, n);
	
		for(int i=0; i<4; i++){
			if(n[i]->status == UNVISITED){
				distance_matrix[n[i]->y * c->width + n[i]->x] = dist_to_start+1;
				min_Heap_insert(h, cP, dist_to_start+1);
			}	
		}
	}	
	
	return found;
}

static void get_path(canvas *canvas, pixel *current_pix, int *dist_matrix){
	int counter = 0;
	pixel *n[4];
	pixel *min_neighbour;

	current_pix = canvas->end;

	while(current_pix->status != 0){
		min_neighbour = get_min_neighbour(canvas, current_pix, n, dist_matrix);    
		canvas->path[counter] = min_neighbour;
		current_pix = min_neighbour;
	}
}

static pixel *get_min_neighbour(canvas *c, pixel *cP, pixel **n, int *dm){
	neighbours(c, cP, n);
	pixel *min_n = n[0];
	for(int i=1; i<4; i++){
		// this will return first node from [north, east, south, west] with smallest dist
		if(dm[min_n->y * c->width + min_n->x] > dm[n[i]->y * c->width + n[i]->x]){
			min_n = n[i];
		}
	}
	return min_n;
}

static int canvas_empty(canvas *c){
	if(c->start == NULL || c->end == NULL || c->canv == NULL){
		return 1;
	}
	return 0;
}

static int get_dist(pixel *p1, pixel *p2){
	unsigned int x_dist = p1->x - p2->x; 
	unsigned int y_dist = p1->y - p2->y; 
	return x_dist+y_dist;
}

static void init_dist_matrix(canvas *canvas){
	int matrix_size =  canvas->height * canvas->width;	
	distance_matrix = malloc(sizeof (int) * matrix_size);
	for(int i=0; i<canvas->height; i++){
		for(int j=0; j<canvas->width; j++){
			distance_matrix[i * canvas->width + j] = (int)pow(2,32)-1;
		}
	}
}




