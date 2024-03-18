objects = main.o engine/canvas.o engine/data_structures.o engine/algorithms/breadth_first_search.o engine/algorithms/depth_first_search.o \
					engine/algorithms/a_star.o 

includes = -I./engine -I./engine/algorithms

CFLAGS= -std=c99 -Wall -Wextra -pedantic $(includes)

all: main

main: $(objects)

clean: 
	rm -f main $(objects)

.PHONY: all