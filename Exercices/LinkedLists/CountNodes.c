#include <stdio.h>
#include <stdlib.h>


struct Node {

    int Value;
    struct Node *Next;
};


int AddEnd(struct Node **Head , int Value){

    if(Head == NULL){
        return 0;
    }

    struct Node *newNode = malloc(sizeof *newNode);

    if(newNode == NULL){

        return 0;
    }

    newNode->Value = Value;
    newNode->Next = NULL;

    if(*Head == NULL){

        *Head = newNode;
        return 1;
    }

    struct Node *Current;

    Current = *Head;

    while (Current->Next != NULL)
    {
        Current = Current->Next;
    }

    Current->Next = newNode;

    return 1;
    
}

int CountNodes(struct Node *Head){

    if(Head == NULL){
        return 0;
    }

    struct Node *Current = Head;

    int Count = 0;

    while(Current != NULL){

        Count++;

        Current = Current->Next;
    }

    return Count;
}

void PrintList(struct Node *Head){

    if(Head == NULL){

        return;
    }


    struct Node *Current = Head;

    while(Current != NULL){

        printf("%d" , Current->Value);
        if(Current->Next != NULL){
            printf(" -> ");
        }

        Current = Current->Next;
    }
}

void FreeList(struct Node **Head){

    if(Head == NULL || *Head == NULL){

        return;
    }

    struct Node *Current;

    Current = *Head;

    struct Node *Next;

    while(Current != NULL){

        Next = Current->Next;

        free(Current);

        Current = Next;
    }

    *Head = NULL;
}

int main(void){

      struct Node *Head = NULL;

    if(!AddEnd(&Head , 10)){

        FreeList(&Head);
        return 1;
    }

    PrintList(Head);
    printf("\n");

      if(!AddEnd(&Head , 20)){

        FreeList(&Head);
        return 1;
    }

     PrintList(Head);
    printf("\n");

      if(!AddEnd(&Head , 30)){

        FreeList(&Head);
        return 1;
    }

     PrintList(Head);
    printf("\n");

      if(!AddEnd(&Head , 40)){

        FreeList(&Head);
        return 1;
    }

     PrintList(Head);
    printf("\n");

    int Count = CountNodes(Head);

    printf("\nThe Count of Nodes inside this List is : %d " , Count);

    FreeList(&Head);

    if(Head == NULL){

        printf("\nThe CleanUp success");
    }

    return 0;
}