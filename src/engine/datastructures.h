#ifndef QUEUE_STACK_DATASTRUCTURES_H
#define QUEUE_STACK_DATASTRUCTURES_H

void stack_init(struct stack *s, int length);
void queue_init(struct queue *q, int length);
void stack_push(struct stack *s, struct pixel p);
void queue_push(struct queue *q, struct pixel p);
struct pixel stack_pop(struct stack *s);
struct pixel queue_pop(struct queue *q);

#endif