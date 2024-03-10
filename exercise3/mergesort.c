#include <stdio.h>
#include <stdlib.h>

enum{
    MAX_BUFF_SIZE = 128,
};
struct node {
    int value;
    struct node *next;
};

void makeNewNode(struct node **root, struct node **pointerToLast, int value);
int mergsort(struct node *rootpointer, struct node *pointerToLast);

int main(void){
    int currentRead = 0;

    struct node *root = NULL;
    struct node *lastNode;

    scanf("%d", &currentRead);
    while(currentRead != (-1)){
        makeNewNode(&root, &lastNode, currentRead); 
        scanf("%d", &currentRead);
    };

    mergsort(root, lastNode);
}

void makeNewNode(struct node **rootpointer, struct node **pointerToLast, int value){
    if (*rootpointer == NULL) {//then rootpointer not initialized
        *rootpointer = malloc(sizeof(**rootpointer));
        (**rootpointer).value = value;
        *pointerToLast = *rootpointer;
       (**rootpointer).next = NULL;
    }else {
        struct node *newNodePointer = malloc(sizeof(*newNodePointer));
        (*pointerToLast)->next = newNodePointer;
        *pointerToLast = newNodePointer;
        (*newNodePointer).value = value;
    }
}

int lenLinkedList(struct node *rootpointer){
    if (rootpointer == NULL) {
        return 0;
    }

    struct node *next = (*rootpointer).next;
    int length = 1;
    
    while(next != NULL){
        next = (*next).next; 
        length++;  
    }
    return length;
}

int mergsort(struct node *rootpointer, struct node *pointerToLast){
    if (rootpointer == NULL) {
        return 0;
    }
    int len = lenLinkedList(rootpointer);

    for (int i = 0; i < len / 2; i++) {

    }
}