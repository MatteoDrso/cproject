#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "len.h"

struct Stack{
    int array[20];
    bool empty;
    int top;
};

void pop(struct Stack *stack){
    if(stack->empty){
        return;
    }
    int arrayLength = lenInt(stack->array);
    for(int i = stack->top; i < arrayLength-1; i++){
        stack->array[i] = stack->array[i+1];
    }
}

int peek(struct Stack *stack){
    if(stack->empty){
        return stack->top;
    }
    return stack->array[stack->top];
}

void push(struct Stack *stack,int x){
    if (stack->top == 0) {
        return;
    }
    stack->array[stack->top-1] = x;
    stack->top -= 1;
}