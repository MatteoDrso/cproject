#include <stdlib.h>
#include <stdio.h>
#include "canvas.h"
#include "data_structures.h"

void stack_init(struct stack *s, int length){
    s->length = length;
    s->stack_arr = malloc(s->length * sizeof(__intptr_t));
    s->top = 0;
}

void stack_push(struct stack *s, struct pixel *p){
    if(stack_is_full(s)){
        printf("Tried to push to a stack that is full!\n");
        abort();
    }
    s->stack_arr[s->top] = p;
    s->top++;

}

struct pixel *stack_pop(struct stack *s){
    if(stack_is_empty(s)){
        printf("Tried to pop a stack that is empty!\n");
        abort();
    } 
    s->top--;
    return s->stack_arr[s->top];
}

void queue_init(struct queue *q, int length){
    q->length = length;
    q->queue_arr = malloc(q->length * sizeof(struct pixel));
    q->bot = 0;
    q->top = 0;
}


void queue_push(struct queue *q, struct pixel p){
    if(q->top >= q->length){
        q->top-=q->length;
    }
    printf("%d, %d\n", q->top, q->bot);
    if(queue_is_full(q)){
        printf("Tried to push to a queue that is full!\n");
        abort();
    }
    q->queue_arr[q->top] = p;
    q->top++;
}

struct pixel queue_pop(struct queue *q){
    if(queue_is_empty(q)){
        printf("Tried to pop a queue that is empty!\n");
        abort();
    }
    struct pixel p = q->queue_arr[q->bot];
    q->bot++;
    if(q->bot>=q->length){
        q->bot-=q->length;
    }
    return p;
}

void min_Heap_init(struct min_Heap *h, int size){
    h->size = size;
    h->min_Heap_arr = malloc(h->size * sizeof(node *));//min_Heap_arr is **
    h->bot = 0;
    h->top = 0;
}

void min_Heap_insert(struct min_Heap *h, pixel *value, int key){
    if(h->bot == h->size){
        printf("Tried to push to a full heap!\n");
        return;
    }
    node *n = malloc(sizeof(struct node));
    n->key = key;
    n->value = value;

    h->min_Heap_arr[h->bot] = n;
    bubble_up(h, n);
    h->bot++;
}

struct pixel *min_Heap_pop(struct min_Heap *h){
     if(h->bot == 0){
        printf("Tried to push to a full heap!\n");
        abort();
    }
    pixel *p = h->min_Heap_arr[h->top]->value;
    free(h->min_Heap_arr[h->top]);
    h->min_Heap_arr[h->top] = h->min_Heap_arr[h->bot]; 
    // then bubble new root down
    bubble_down(h, h->min_Heap_arr[h->top]);
    h->bot--;
    return p; 
}

//helper functions for heap
static void bubble_up(min_Heap *h, node *n){
    int idx_parent = h->bot;
    node *parent = h->min_Heap_arr[idx_parent];
    int idx_child = idx_parent;
    while(n->key < parent->key){
        swap(h, idx_parent, idx_child);   
        idx_child = idx_parent; 
        idx_parent = get_parent(idx_child);
        parent = h->min_Heap_arr[idx_parent];
    }
}

static void bubble_down(min_Heap *h, node *n){
    int idx_parent = 0; 
    int idx_child = 0;
    while(1){
        idx_child = get_smallest_child(h, idx_parent);
        if(idx_child == idx_parent){
            break;
        }
        swap(h, idx_parent, idx_child);   
        idx_parent = idx_child;
    }
}

static int get_smallest_child(min_Heap *h, int index_node){
    node *leftChild = h->min_Heap_arr[2*index_node+1];
    node *rightChild = h->min_Heap_arr[2*index_node+2];
    node *parent = h->min_Heap_arr[index_node];
    //if [north,east,south,west] should be mantained then <=-> < 
    if((parent->key <= leftChild->key) && (parent->key <= rightChild->key)){
        return index_node;
    }

    if(rightChild->key < leftChild->key){
        return (2*index_node+2);
    }
    return (2*index_node+1);
}

static int get_parent(int index_node){
    return ((index_node-1)/2);
}

static void swap(min_Heap *h, int index_parent, int index_child){
    node *temp = h->min_Heap_arr[index_parent];
    h->min_Heap_arr[index_parent] = h->min_Heap_arr[index_child];
    h->min_Heap_arr[index_child] = temp;
}


