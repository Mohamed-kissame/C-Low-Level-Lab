#include <stdio.h>
#include <stdlib.h>


struct Node{

    int Value;
    struct Node *Next;
};

int AddFront(struct Node **headptr , int value){

    if(headptr == NULL ){

        return 0;
    }

   struct Node *newNode = malloc(sizeof *newNode);

   if(newNode == NULL){

      return 0;
   }

   newNode->Value = value;
   newNode->Next = *headptr;
   *headptr = newNode;

   return 1;
}

void PrintList(struct Node *head){

    if(head == NULL){

        return;
    }

    struct Node *Current = head;

    while(Current != NULL){

        printf("%d" , Current->Value);

        if(Current->Next != NULL){

            printf(" -> ");
        }

        Current = Current->Next;
    }

}


void FreeList(struct Node **headptr){

    struct Node *Current;
    struct Node *Next;

    Current = *headptr;

    while(Current != NULL){

        Next = Current->Next;

        free(Current);

        Current = Next;
    }

    *headptr = NULL;

}

int main(void)
{
    struct Node *head = NULL;

    if (!AddFront(&head, 10))
    {
        FreeList(&head);
        return 1;
    }

     PrintList(head);
     printf("\n");

    if (!AddFront(&head, 20))
    {
        FreeList(&head);
        return 1;
    }

      PrintList(head);
      printf("\n");

    if (!AddFront(&head, 30))
    {
        FreeList(&head);
        return 1;
    }

    PrintList(head);

    FreeList(&head);

    if (head == NULL)
    {
        printf("\nThe cleanup succeeded.\n");
    }

    return 0;
}