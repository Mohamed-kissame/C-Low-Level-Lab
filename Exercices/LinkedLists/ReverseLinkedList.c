#include <stdio.h>
#include <stdlib.h>

struct Node{

    int Value;
    struct Node *Next;

};

void Reverse(struct Node **Head){

    if(Head == NULL){

        return;
    }

    struct Node *Current = *Head;
    struct Node *Prevs = NULL;
    struct Node *Next;

    while(Current != NULL){

        Next = Current->Next;
        Current->Next = Prevs;

        Prevs = Current;
        Current = Next;

    }

    *Head = Prevs;
}

int AddFront(struct Node **Head, int Value)
{
    if (Head == NULL)
    {
        return 0;
    }

    struct Node *newNode = malloc(sizeof *newNode);

    if (newNode == NULL)
    {
        return 0;
    }

    newNode->Value = Value;
    newNode->Next = *Head;
    *Head = newNode;

    return 1;
}

void PrintList(struct Node *Head)
{
    struct Node *Current = Head;

    while (Current != NULL)
    {
        printf("%d", Current->Value);

        if (Current->Next != NULL)
        {
            printf(" -> ");
        }

        Current = Current->Next;
    }

    printf("\n");
}

void FreeList(struct Node **Head)
{
    if (Head == NULL || *Head == NULL)
    {
        return;
    }

    struct Node *Current = *Head;

    while (Current != NULL)
    {
        struct Node *Next = Current->Next;

        free(Current);

        Current = Next;
    }

    *Head = NULL;
}

int main(void)
{
    struct Node *Head = NULL;

    /*
        Build:

        10 -> 20 -> 30 -> 40 -> NULL
    */

    if (!AddFront(&Head, 40) ||
        !AddFront(&Head, 30) ||
        !AddFront(&Head, 20) ||
        !AddFront(&Head, 10))
    {
        FreeList(&Head);
        return 1;
    }

    printf("Original List:\n");
    PrintList(Head);

    printf("\nReverse List:\n");

    Reverse(&Head);

    PrintList(Head);

    /*
        Expected:

        40 -> 30 -> 20 -> 10
    */


    printf("\nReverse Again:\n");

    Reverse(&Head);

    PrintList(Head);

    /*
        Expected:

        10 -> 20 -> 30 -> 40
    */


    printf("\nTest Single Node:\n");

    FreeList(&Head);

    AddFront(&Head, 100);

    printf("Before: ");
    PrintList(Head);

    Reverse(&Head);

    printf("After:  ");
    PrintList(Head);


    printf("\nTest Empty List:\n");

    FreeList(&Head);

    Reverse(&Head);

    if (Head == NULL)
    {
        printf("Empty list handled successfully.\n");
    }


    FreeList(&Head);

    if (Head == NULL)
    {
        printf("\nCleanup successful.\n");
    }

    return 0;
}
