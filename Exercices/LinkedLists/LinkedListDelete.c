#include <stdio.h>
#include <stdlib.h>


struct Node{

    int Value;
    struct Node *Next;
};

int DeleteValue(struct Node **Head , int Value){

    if(Head == NULL || *Head == NULL){

        return 0;
    }

    struct Node *Current = *Head;
    struct Node *Next;

    if(Current->Value == Value){

        Next = Current->Next;
        free(Current);
        Current = Next;
        *Head = Current;

        return 1;
    }

    struct Node *Previous = Current;

    while(Current != NULL){

        if(Current->Value == Value){

            Previous->Next = Current->Next;
            free(Current);
            return 1;
        }

        Previous = Current;
        Current = Current->Next;
       

    }

    return 0;

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

  
    if (!AddFront(&head, 40) ||
        !AddFront(&head, 30) ||
        !AddFront(&head, 20) ||
        !AddFront(&head, 10))
    {
        FreeList(&head);
        return 1;
    }

    printf("Initial List:\n");
    PrintList(head);
    printf("\n\n");

    
    printf("Delete 30 (Middle):\n");

    if (DeleteValue(&head, 30))
    {
        printf("30 deleted successfully.\n");
    }
    else
    {
        printf("30 not found.\n");
    }

    PrintList(head);
    printf("\n\n");


    
    printf("Delete 10 (Head):\n");

    if (DeleteValue(&head, 10))
    {
        printf("10 deleted successfully.\n");
    }
    else
    {
        printf("10 not found.\n");
    }

    PrintList(head);
    printf("\n\n");


   
    printf("Delete 40 (Last):\n");

    if (DeleteValue(&head, 40))
    {
        printf("40 deleted successfully.\n");
    }
    else
    {
        printf("40 not found.\n");
    }

    PrintList(head);
    printf("\n\n");


     printf("Delete 99 (Not Found):\n");

    if (DeleteValue(&head, 99))
    {
        printf("99 deleted successfully.\n");
    }
    else
    {
        printf("99 not found.\n");
    }

    PrintList(head);
    printf("\n\n");


   
    printf("Delete 20 (Only Remaining Node):\n");

    if (DeleteValue(&head, 20))
    {
        printf("20 deleted successfully.\n");
    }
    else
    {
        printf("20 not found.\n");
    }

    if (head == NULL)
    {
        printf("List is now empty.\n");
    }


    
    printf("\nDelete from Empty List:\n");

    if (!DeleteValue(&head, 50))
    {
        printf("Delete correctly returned failure because list is empty.\n");
    }


    FreeList(&head);

    if (head == NULL)
    {
        printf("\nCleanup succeeded.\n");
    }

    return 0;
}