objects = main.o engine/canvas.o engine/data_structures.o engine/algorithms/breadth_first_search.o engine/algorithms/depth_first_search.o engine/algorithms/dijkstra.o
			\ engine/algorithms/a_star.o  

CFLAGS= -std=c99 -Wall -Wextra -pedantic
all: main

main: $(objects)

clean: 
	rm main $(objects)

.PHONY: all
