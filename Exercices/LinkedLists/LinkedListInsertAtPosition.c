#include <stdio.h>
#include <stdlib.h>

struct Node{

    int Value;
    struct Node *Next;

};

int InsertAtPosition(struct Node **Head, int newValue, int Position)
{
    if (Head == NULL || Position < 0)
    {
        return 0;
    }

   
    if (Position == 0)
    {
        struct Node *newNode = malloc(sizeof *newNode);

        if (newNode == NULL)
        {
            return 0;
        }

        newNode->Value = newValue;
        newNode->Next = *Head;

        *Head = newNode;

        return 1;
    }

    
    struct Node *Current = *Head;

    int currentPosition = 0;

    while (Current != NULL && currentPosition < Position - 1)
    {
        Current = Current->Next;
        currentPosition++;
    }

   
    if (Current == NULL)
    {
        return 0;
    }

   
    struct Node *newNode = malloc(sizeof *newNode);

    if (newNode == NULL)
    {
        return 0;
    }

    newNode->Value = newValue;

    newNode->Next = Current->Next;
    Current->Next = newNode;

    return 1;
}

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

    if (headptr == NULL || *headptr == NULL)
    {
       return;
    }

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

   
    // 10 -> 20 -> 30
    if (!AddFront(&head, 30) ||
        !AddFront(&head, 20) ||
        !AddFront(&head, 10))
    {
        FreeList(&head);
        return 1;
    }

    printf("Initial List:\n");
    PrintList(head);
    printf("\n\n");


    
    printf("Insert 5 at position 0:\n");

    if (!InsertAtPosition(&head, 5, 0))
    {
        printf("Insertion failed.\n");
    }

    PrintList(head);
    printf("\n\n");


    // Expected:
    // 5 -> 10 -> 20 -> 30


   
    printf("Insert 15 at position 2:\n");

    if (!InsertAtPosition(&head, 15, 2))
    {
        printf("Insertion failed.\n");
    }

    PrintList(head);
    printf("\n\n");


    // Expected:
    // 5 -> 10 -> 15 -> 20 -> 30


   
    printf("Insert 40 at position 5:\n");

    if (!InsertAtPosition(&head, 40, 5))
    {
        printf("Insertion failed.\n");
    }

    PrintList(head);
    printf("\n\n");


    // Expected:
    // 5 -> 10 -> 15 -> 20 -> 30 -> 40


    
    printf("Insert 99 at invalid position 20:\n");

    if (!InsertAtPosition(&head, 99, 20))
    {
        printf("Insertion correctly failed.\n");
    }

    PrintList(head);
    printf("\n\n");


   
    // 5 -> 10 -> 15 -> 20 -> 30 -> 40


    // Cleanup current list
    FreeList(&head);

    printf("After cleanup:\n");

    if (head == NULL)
    {
        printf("List is empty.\n");
    }


   
    printf("\nInsert 100 at position 0 into empty list:\n");

    if (!InsertAtPosition(&head, 100, 0))
    {
        printf("Insertion failed.\n");
    }

    PrintList(head);
    printf("\n\n");


    FreeList(&head);


   
    printf("Insert 200 at position 1 into empty list:\n");

    if (!InsertAtPosition(&head, 200, 1))
    {
        printf("Insertion correctly failed.\n");
    }

    if (head == NULL)
    {
        printf("List remains empty.\n");
    }


    FreeList(&head);

    return 0;
}