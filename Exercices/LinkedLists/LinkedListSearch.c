#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node{

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

    struct Node *Current = *Head;

    while(Current->Next != NULL){

        Current = Current->Next;
    }

    Current->Next = newNode;

    return 1;
}

bool Search(struct Node *Head , int Value){

    if(Head == NULL) {
        return false;
    }

    struct Node *Current = Head;

    while(Current != NULL){

        if(Current->Value == Value){

            return true;
        }

        Current = Current->Next;
    }

    return false;
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

    struct Node *Next ;

    while (Current != NULL)
    {
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


    int Value = 99;

    printf("\nSearch About the %d if exists inside the List : " , Value);
    if(Search(Head , Value)){

       printf(" Yes , the Value %d is exists inside the List" , Value);

      
    }
    else{

        printf("The value %d Not Found inside the List ." , Value);
    }

    FreeList(&Head);

    if(Head == NULL){

        printf("\nThe CleanUp success");
    }

    return 0;

}