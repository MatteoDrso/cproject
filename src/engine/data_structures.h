#ifndef QUEUE_STACK_DATASTRUCTURES_H
#define QUEUE_STACK_DATASTRUCTURES_H

typedef struct stack {
    //implemented the stack as empty ascending.

    struct pixel **stack_arr;
    int length; //has to be initialized to the number of pixel in the canvas (width * height)
    int top;

}stack;

typedef struct queue {

    struct pixel **queue_arr; // Should be an array of pointers to pixel
    int length; //has to be initialized to the number of pixel in the canvas (width * height)
    int top, bot;

}queue;

typedef struct node{
    pixel *value;//pointer to pixel
    int key;//distance
}node;

typedef struct min_Heap {

    node *min_Heap_arr;
    int size; //has to be initialized to the number of pixel in the canvas (width * height)
    int len;

}min_Heap;


void stack_init(struct stack *s, int length);
void queue_init(struct queue *q, int length);
void min_Heap_init(struct min_Heap *h, int size);

void stack_push(struct stack *s, struct pixel *p);
void queue_push(struct queue *q, struct pixel *p);
void min_Heap_insert(struct min_Heap *h, pixel *p, int key);
struct pixel *stack_pop(struct stack *s);
struct pixel *queue_pop(struct queue *q);
struct pixel *min_Heap_pop(struct min_Heap *h);
void min_Heap_clear(min_Heap *h);

/*
static void swap(min_Heap *h, int index_parent, int index_child);
static int get_parent(int index_node);
static int get_smallest_child(min_Heap *h, int index_node); 
static void bubble_up(min_Heap *h, node *n);
static void bubble_down(min_Heap *h);
static void printHeap(min_Heap *h);
*/

static inline bool stack_is_empty(stack *s){
    return s->top<=0;
} 

static inline bool stack_is_full(stack *s){
    return s->top == s->length;
}  

static inline bool queue_is_full(queue *q){
    return q->top == q->bot-1 || (q->top == q->length-1 && q->bot == 0);
}  

static inline bool queue_is_empty(queue *q){
    return q->bot == q->top;
}  

#endif
