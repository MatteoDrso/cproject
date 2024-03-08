#include "stack_jk.h"
#include <stdbool.h>
#include <stdio.h>

int main(void){
    struct Stack stack1, *stackptr = &stack1;
    for (int i = 0; i < 20; i++) {
        stackptr->array[i] = i;
        stackptr->top = i;
    }
    
    pop(stackptr);
    bool result = peek(stackptr) == 1;

    printf("top is after pop equal to 1: %d\n", result);

    return 0; 
}