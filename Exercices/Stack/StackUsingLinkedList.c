#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int value;
    struct Node *Next;
};


bool Push(struct Node **Top, int value)
{
    if (Top == NULL)
    {
        return false;
    }

    struct Node *newNode = malloc(sizeof *newNode);

    if (newNode == NULL)
    {
        return false;
    }

    newNode->value = value;
    newNode->Next = *Top;

    *Top = newNode;

    return true;
}


bool Pop(struct Node **Top, int *removedValue)
{
    if (Top == NULL || *Top == NULL || removedValue == NULL)
    {
        return false;
    }

    struct Node *nodeToDelete = *Top;

    
    *removedValue = nodeToDelete->value;

  
    *Top = nodeToDelete->Next;

    free(nodeToDelete);

    return true;
}


bool Peek(struct Node *Top, int *topValue)
{
    if (Top == NULL || topValue == NULL)
    {
        return false;
    }

    *topValue = Top->value;

    return true;
}


bool IsEmpty(struct Node *Top)
{
    return Top == NULL;
}


int Count(struct Node *Top)
{
    int count = 0;

    struct Node *Current = Top;

    while (Current != NULL)
    {
        count++;
        Current = Current->Next;
    }

    return count;
}


void PrintStack(struct Node *Top)
{
    if (Top == NULL)
    {
        printf("\nStack is empty.\n");
        return;
    }

    printf("\nTOP\n");
    printf(" |\n");
    printf(" v\n");

    struct Node *Current = Top;

    while (Current != NULL)
    {
        printf("%d\n", Current->value);
        Current = Current->Next;
    }
}


void FreeStack(struct Node **Top)
{
    if (Top == NULL || *Top == NULL)
    {
        return;
    }

    struct Node *Current = *Top;

    while (Current != NULL)
    {
        struct Node *Next = Current->Next;

        free(Current);

        Current = Next;
    }

    *Top = NULL;
}


int main(void)
{
    struct Node *Top = NULL;

    if (!Push(&Top, 10) ||
        !Push(&Top, 20) ||
        !Push(&Top, 30) ||
        !Push(&Top, 40))
    {
        FreeStack(&Top);
        return 1;
    }


    PrintStack(Top);

    printf("\nCount: %d\n", Count(Top));

    int topValue;

    if (Peek(Top, &topValue))
    {
        printf("Top value: %d\n", topValue);
    }


    int removedValue;

    if (Pop(&Top, &removedValue))
    {
        printf("\nPopped: %d\n", removedValue);
    }

    PrintStack(Top);


    if (Pop(&Top, &removedValue))
    {
        printf("\nPopped: %d\n", removedValue);
    }

    PrintStack(Top);


    if (Pop(&Top, &removedValue))
    {
        printf("\nPopped: %d\n", removedValue);
    }

    PrintStack(Top);


    if (Pop(&Top, &removedValue))
    {
        printf("\nPopped: %d\n", removedValue);
    }

    PrintStack(Top);


    if (IsEmpty(Top))
    {
        printf("\nYes, the Stack is empty.\n");
    }


    // Test Pop on empty stack
    if (!Pop(&Top, &removedValue))
    {
        printf("Cannot Pop: Stack is empty.\n");
    }


    // Test Peek on empty stack
    if (!Peek(Top, &topValue))
    {
        printf("Cannot Peek: Stack is empty.\n");
    }


    FreeStack(&Top);

    if (Top == NULL)
    {
        printf("Cleanup successful.\n");
    }

    return 0;
}