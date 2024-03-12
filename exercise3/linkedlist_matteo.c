#include <stdlib.h>
#include <stdio.h>

struct Node {
    int val;
    struct Node *successor;
};

void printList(struct Node *head);

int main(int argc, char *argv[]){

    struct Node *head = malloc(sizeof *head); 
    struct Node *ptr = malloc(sizeof *ptr); 
    head->successor = NULL;
    ptr->successor = head;

    int input;

    do {
        puts("Append a value (-1 to exit): ");
        scanf("%d", &input);
        struct Node *newNode = malloc(sizeof *newNode);
        ptr->successor->successor = newNode;
        ptr->successor = newNode;
        newNode->val = input;
        newNode->successor = NULL;
    } while (input != -1);

    printList(head);

    return 0;

}

void printList(struct Node *head){

    struct Node *ptr = malloc(sizeof *ptr);
    ptr->successor = head->successor;
    if(ptr->successor == NULL){
        printf("List is empty!");
    }

    while(ptr->successor->successor != NULL) {
        printf("%d ",ptr->successor->val);
        ptr = ptr->successor;
    }

}