#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Value;
    struct Node *Next;
};

int main(void)
{
    struct Node *First = malloc(sizeof *First);

    if (First == NULL)
    {
        return 1;
    }

    struct Node *Second = malloc(sizeof *Second);

    if (Second == NULL)
    {
        free(First);
        First = NULL;
        return 1;
    }

    struct Node *Third = malloc(sizeof *Third);

    if (Third == NULL)
    {
        free(First);
        free(Second);

        First = NULL;
        Second = NULL;

        return 1;
    }

    First->Value = 10;
    Second->Value = 20;
    Third->Value = 30;

    First->Next = Second;
    Second->Next = Third;
    Third->Next = NULL;

    struct Node *head = First;

    struct Node *Current = head;

    while (Current != NULL)
    {
        printf("%d", Current->Value);

        if (Current->Next != NULL)
        {
            printf(" -> ");
        }

        Current = Current->Next;
    }


    free(First);
    free(Second);
    free(Third);

    First = NULL;
    Second = NULL;
    Third = NULL;
    head = NULL;

    return 0;
}