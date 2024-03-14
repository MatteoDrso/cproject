#include <stdlib.h>
#include <stdio.h>

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

struct pixel {
    int val;
};

void stack_push(struct stack *s, struct pixel p){
    s->stack_arr[s->top] = p;
    s->top++;

}

void queue_push(struct queue *q, struct pixel p){
    if(q->top >= q->length-1){
        q->top-=q->length;
    }
    q->queue_arr[q->top] = p;
    q->top++;
}

void stack_init(struct stack *s, int length){
    s->stack_arr = malloc(s->length * sizeof(struct pixel));
    s->length = length;
    s->top = 0;
}

void queue_init(struct queue *q, int length){
    q->length = length;
    q->queue_arr = malloc(q->length * sizeof(struct pixel));
    q->bot = 0;
    q->top = 0;
}

struct pixel stack_pop(struct stack *s){
    if(s->top<=0){
        perror("Tried to pop a stack that is empty!");
    } 
    s->top--;
    return s->stack_arr[s->top];
}

struct pixel queue_pop(struct queue *q){
    if(q->bot == q->top) perror("Tried to pop a queue that is empty!");
    struct pixel p = q->queue_arr[q->bot];
    printf("%d, %d\n", q->bot, q->top);
    q->bot++;
    if(q->bot>=q->length){
        q->bot-=q->length;
    }
    return p;
}



int main(int argc, char *argv[]){

    struct queue queue;
    queue_init(&queue, 3);

    struct pixel p, p2, p3, p4, p5;
    p.val = 1;
    p2.val = 2;
    p3.val = 3;

    queue_push(&queue, p);
    queue_push(&queue, p2);
    queue_push(&queue, p3);

    p4 = queue_pop(&queue);
    p5 = queue_pop(&queue);
    p = queue_pop(&queue);
    p2 = queue_pop(&queue);
    p2 = queue_pop(&queue);
    p2 = queue_pop(&queue);

    printf("%d, %d", p4.val, p5.val);

}