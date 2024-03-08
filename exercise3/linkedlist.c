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
void printReverse(int counter, struct node *root);

int main(void){
    int currentRead = 0;
    int counter = 0;

    struct node *root = NULL;
    struct node *lastNode;

    scanf("%d", &currentRead);
    while(currentRead != (-1)){
        makeNewNode(&root, &lastNode, currentRead); 
        counter++;
        scanf("%d", &currentRead);
    };
    printReverse(counter, root);
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

void printReverse(int counter, struct node *root){

    int buf[MAX_BUFF_SIZE];
    int count2 = 0;
    for(int i = 0; i < counter; i++) {
        buf[i] = (*root).value;
        free(root); // not tested
        root = (*root).next;
        count2++;
    }

    while (count2 > 0) {
        printf("%d\n",buf[count2-1]);
        count2--;
    }
}
