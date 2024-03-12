struct stack {
    //implemented the stack as empty ascending.

    struct pixel *stack_arr;
    int top;

};

struct queue {

    struct pixel *queue_arr;
    int top, bot;

};

struct pixel {

};

void stack_push(struct stack *s, struct pixel p){
    s->stack_arr[s->top] = p;
    s->top++;

}

void queue_push(struct queue *q, struct pixel p){
    q->queue_arr[q->top] = p;
    q->top++;
}

struct pixel stack_pop(struct stack *s){
    s->top--;
    if(s->top<=0) perror("Tried to pop a stack that is empty!");
    return s->stack_arr[s->top];
}

struct pixel queue_pop(struct queue *q){
    q->bot++;
    if(q->bot == q->top) perror("Tried to pop a queue that is empty!");
    return q->queue_arr[q->bot-1];
}

static void stack_realloc(struct stack *s){

}

static void queue_realloc(struct queue *q){

}