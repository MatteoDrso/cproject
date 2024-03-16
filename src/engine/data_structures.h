#ifndef QUEUE_STACK_DATASTRUCTURES_H
#define QUEUE_STACK_DATASTRUCTURES_H

typedef struct stack {
    //implemented the stack as empty ascending.

    struct pixel *stack_arr;
    int length; //has to be initialized to the number of pixel in the canvas (width * height)
    int top;

}stack;

typedef struct queue {

    struct pixel *queue_arr;
    int length; //has to be initialized to the number of pixel in the canvas (width * height)
    int top, bot;

}queue;

typedef struct minHeap {

    struct pixel *minHeap_arr;
    int length; //has to be initialized to the number of pixel in the canvas (width * height)
    int top, bot;

}minHeap;


void stack_init(struct stack *s, int length);
void queue_init(struct queue *q, int length);
void minHeap_init(struct minHeap *q, int length);
void stack_push(struct stack *s, struct pixel p);
void queue_push(struct queue *q, struct pixel p);
void minHeap_push(struct minHeap *q, struct pixel p);
struct pixel stack_pop(struct stack *s);
struct pixel queue_pop(struct queue *q);
struct pixel minHeap_pop(struct minHeap *q);

#endif
