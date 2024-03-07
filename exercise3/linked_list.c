#include <stdio.h>
#include <stdlib.h>


int main(void) {
  
  struct node {
    int value;
    struct node *next;
  };
    
  int n = 0;

  struct node *head = malloc (sizeof *head);
  head->next = NULL;
  head->value = -1;

  
  while (1) {
      printf("Enter a number: ");
      scanf("%i", &n);
      if (n == -1)
        break;
      
      struct node *temp = head;
      struct node *current = malloc (sizeof *current);
      current->value = n;
      current->next = NULL;

      while (temp->next != NULL) {
        temp = temp->next;
      }

      temp->next = current;

  }

  printf("Your input in reverse order: \n");

  while (head->next != NULL) {

    struct node *temp = head;
    struct node *prev = head;

    while (temp->next != NULL) {
      if(temp->next->next != NULL) {
        prev = prev->next;
        temp = temp->next;
      } else {
        temp = temp->next;
      }
    }


    printf("%i", temp->value);
    free(temp);
    prev->next = NULL;
  }

  free(head);
  printf("\nFinished.\n");
  return 0;
}