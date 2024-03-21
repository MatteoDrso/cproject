objects = main.o engine/canvas.o engine/data_structures.o \
				 engine/algorithms/breadth_first_search.o engine/algorithms/depth_first_search.o \
				 gui/file_handler.o

includes = -I./engine -I./engine/algorithms -I./gui

CFLAGS= -g -O0 -std=c99 -Wall -Wextra -pedantic $(includes) -lm 

ASAN_FLAGS= -fsanitize=address,undefined

MSAN_FLAGS= -fsanitize=memory,undefined

all: main

main: $(objects)

a_sanitize: $(objects)
	clang $(CFLAGS) $(ASAN_FLAGS) -o main $(objects)

m_sanitize: $(objects)
	clang $(CFLAGS) $(MSAN_FLAGS) -o main $(objects)

clean: 
	rm -f main $(objects)

.PHONY: all
