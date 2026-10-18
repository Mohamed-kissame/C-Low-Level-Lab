#include <stdio.h>
#include <stdlib.h>

struct Node {

    int Value;
    struct Node *Next;
};

int InsertAfter(struct Node *Head , int targetValue , int newValue ){

    if(Head == NULL){

        return 0;
    }

    struct Node *Current = Head;

   

    while (Current != NULL)
    {

        if(Current->Value == targetValue){

            struct Node *newNode = malloc(sizeof *newNode);

            if(newNode == NULL){

                return 0;
            }

            newNode->Value = newValue;
            newNode->Next = Current->Next;
            Current->Next = newNode;

            return 1;
        }

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


int main(void){

    struct Node *head = NULL;

  
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


    if(!InsertAfter(head , 30 , 40)){

        printf("the Target Value Not Found");

    }

    printf("Print List After Add 40 :\n");

    PrintList(head);

    
    if(!InsertAfter(head , 10 , 15)){

        printf("the Target Value Not Found");

    }

   
    printf("\nPrint List After Add 15 :\n");

    PrintList(head);

     if(!InsertAfter(head , 20 , 25)){

        printf("the Target Value Not Found");

    }

   
    printf("\nPrint List After Add 25 :\n");

    PrintList(head);

    FreeList(&head);

    if(head == NULL){

        printf("\nthe CleanUp Success\n");
    }

    return 0;

}