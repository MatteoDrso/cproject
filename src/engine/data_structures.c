#include <stdlib.h>
#include <stdio.h>
#include "canvas.h"
#include "data_structures.h"



void stack_init(struct stack *s, int length){
    s->length = length;
    s->stack_arr = malloc(s->length * sizeof(uintptr_t));
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
    //for (int i = 0; i < length; i++) {
    //  q->queue_arr[i] = malloc(sizeof(struct pixel)); 
    //}
    q->bot = 0;
    q->top = 0;
}


void queue_push(struct queue *q, struct pixel *p){
    if(q->top >= q->length){
        q->top-=q->length;
    }
    if(queue_is_full(q)){
        printf("Tried to push to a queue that is full!\n");
        abort();
    }
    q->queue_arr[q->top] = p;
    q->top++;
}

struct pixel *queue_pop(struct queue *q){
    if(queue_is_empty(q)){
        printf("Tried to pop a queue that is empty!\n");
        abort();
    }
    struct pixel *p = q->queue_arr[q->bot];
    q->bot++;
    if(q->bot>=q->length){
        q->bot-=q->length;
    }
    return p;
}


void min_Heap_init(struct min_Heap *h, int size){
    h->size = size;
    h->min_Heap_arr = calloc(h->size, sizeof(struct node));//min_Heap_arr is **
    h->len = 0;
}

void min_Heap_insert(struct min_Heap *h, pixel *value, int key){
    if(h->len == h->size){
        printf("Tried to push to a full heap!\n");
        return;
    }
    //printf("inserted pixel x: %d, y: %d\n", value->x, value->y);
    node n;
    n.key = key;
    n.value = value;
    h->len++;
    h->min_Heap_arr[h->len-1] = n;

    bubble_up(h, &(h->min_Heap_arr[h->len-1]));
    //printHeap(h);
}

struct pixel *min_Heap_pop(struct min_Heap *h){
     if(h->len == 0){
        printf("Tried to pop from empty heap!\n");
        abort();
    }
    pixel *p = h->min_Heap_arr[0].value;
    h->min_Heap_arr[0] = h->min_Heap_arr[h->len-1]; 
    // then bubble new root down

    bubble_down(h); 

    h->len--;
    //printHeap(h);
    return p;
}

void min_Heap_clear(min_Heap *h){ 
    free(h->min_Heap_arr);
}

//helper functions for heap
static void bubble_up(min_Heap *h, node *n){
    int idx_parent = get_parent(h->len-1);
    node *parent = &(h->min_Heap_arr[idx_parent]);
    int idx_child = idx_parent;
    //printf("bubble_up before loop\n");
    while(n->key < parent->key){
        swap(h, idx_parent, idx_child);   
        idx_child = idx_parent; 
        idx_parent = get_parent(idx_child);
        parent = &(h->min_Heap_arr[idx_parent]);
    }
    //    printf("bubble_up after loop, top_value_x : %d, top_value_y : %d\n", h->min_Heap_arr[0].value->x, h->min_Heap_arr[0].value->y);
    //printf("idx_parent: %d\n", idx_parent);
}

static void bubble_down(min_Heap *h){//rm node *n
    int idx_parent = 0; 
    int idx_child = 0;
    //printf("bubble_down before loop\n");
    while(1){
        idx_child = get_smallest_child(h, idx_parent);
        //printf("idx_child: %d, idx_parent: %d\n", idx_child, idx_parent);
        if(h->min_Heap_arr[idx_parent].key <= h->min_Heap_arr[idx_child].key){
            break;
        }
        swap(h, idx_parent, idx_child);   
        idx_parent = idx_child;
    }
    //printf("bubble_down after loop\n");
}

static int get_smallest_child(min_Heap *h, int index_node){
    if(2*index_node+1 >= h->len){
            return index_node;
    }
    node *leftChild = &(h->min_Heap_arr[2*index_node+1]);

    if(2*index_node+2 >= h->len){
        return (2*index_node+1);
    }
    node *rightChild = &(h->min_Heap_arr[2*index_node+2]);
    //printf("leftChild.key: %d, rightChild.key: %d", leftChild->key, rightChild->key);
    if(rightChild->key < leftChild->key){
        return (2*index_node+2);
    }
        return (2*index_node+1);
}

static int get_parent(int index_node){
    return ((index_node-1)/2);
}

static void swap(min_Heap *h, int index_parent, int index_child){
    node temp = h->min_Heap_arr[index_parent];
    h->min_Heap_arr[index_parent] = h->min_Heap_arr[index_child];
    h->min_Heap_arr[index_child] = temp;
}

static void printHeap(min_Heap *h){
    int i = 0;
    puts("printing current heap: ");
    printf("len: %d, last node: key: %d, valueX: %d, valueY: %d\n", h->len);//, h->min_Heap_arr[h->len-1].key, h->min_Heap_arr[h->len-1].value->x, h->min_Heap_arr[h->len-1].value->y);
    while (i < h->len) {
        printf("node %d, key: %d, value: x:%d y:%d\n", i, h->min_Heap_arr[i].key, h->min_Heap_arr[i].value->x, h->min_Heap_arr[i].value->y);
        i++;
    }
    puts("done");
}


