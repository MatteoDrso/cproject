#ifndef QUEUE_STACK_DATASTRUCTURES_H
#define QUEUE_STACK_DATASTRUCTURES_H

struct stack {
    //implemented the stack as empty ascending.

    struct pixel *stack_arr;
    int length; //has to be initialized to the number of pixel in the canvas (width * height)
    int top;

};

struct queue {

    struct pixel *queue_arr;
    int length; //has to be initialized to the number of pixel in the canvas (width * height)
    int top, bot;

};

void stack_init(struct stack *s, int length);
void queue_init(struct queue *q, int length);
void stack_push(struct stack *s, struct pixel p);
void queue_push(struct queue *q, struct pixel p);
struct pixel stack_pop(struct stack *s);
struct pixel queue_pop(struct queue *q);

#endif