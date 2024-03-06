#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

enum {
    MAX_STACK_SIZE=32,
};

struct Stack {
    int content[MAX_STACK_SIZE];
    int top; //points to the 1st EMPTY slot.
};

bool isEmpty(struct Stack s){
    return s.top == 0;
}

bool pop(struct Stack *s, int *result){

    if(s->top == 0)
        return false;

    s->top--;
    *result = s->content[s->top];

    return true;

}

bool push(struct Stack *s, int n){

    if(s->top==32)
        return false;

    s->content[s->top] = n;
    s->top++;

    return true;

}

void printStack(struct Stack *s){

    for(int i = 0; i < s->top; i++)
        printf("%d, ", s->content[i]);
    printf("\n");

}


int main(int argc, char *argv[]){
    
    struct Stack stack;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);

    printStack(&stack);

    return 0;

}