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

void stack_push(struct stack *s, struct pixel p){
    if(s->top == s->length){
        printf("Tried to push to a stack that is full!\n");
        return;
    }
    s->stack_arr[s->top] = p;
    s->top++;

}

void queue_push(struct queue *q, struct pixel p){
    if(q->top >= q->length){
        q->top-=q->length;
    }
    printf("%d, %d\n", q->top, q->bot);
    if(q->top == q->bot-1 || (q->top == q->length-1 && q->bot == 0)){
        printf("Tried to push to a queue that is full!\n");
        return;
    }
    q->queue_arr[q->top] = p;
    q->top++;
}

struct pixel stack_pop(struct stack *s){
    if(s->top<=0){
        printf("Tried to pop a stack that is empty!\n");
        return;
    } 
    s->top--;
    return s->stack_arr[s->top];
}

struct pixel queue_pop(struct queue *q){
    if(q->bot == q->top){
        printf("Tried to pop a queue that is empty!\n");
        return;
    }
    struct pixel p = q->queue_arr[q->bot];
    q->bot++;
    if(q->bot>=q->length){
        q->bot-=q->length;
    }
    return p;
}

int main(int argc, char *argv[]){

    struct pixel p1, p2, p3, p4, p5;
    struct queue q;

    p1.val = 1;
    p2.val = 2;
    p3.val = 3;

    queue_init(&q, 3);
    queue_push(&q, p1);
    queue_push(&q, p2);
    queue_push(&q, p3);
    //p5 = queue_pop(&q);
    queue_push(&q, p4);
    

}