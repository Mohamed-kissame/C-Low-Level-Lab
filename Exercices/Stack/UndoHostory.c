#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ACTION_SIZE 50

struct Node
{
    char Action[ACTION_SIZE];
    struct Node *Next;
};


void CopyAction(char *Destination, const char *Source)
{
    int i = 0;

    while (Source[i] != '\0' && i < ACTION_SIZE - 1)
    {
        Destination[i] = Source[i];
        i++;
    }

    Destination[i] = '\0';
}


bool PushAction(struct Node **Top, const char *Action)
{
    if (Top == NULL || Action == NULL)
    {
        return false;
    }

    struct Node *newNode = malloc(sizeof *newNode);

    if (newNode == NULL)
    {
        return false;
    }

    CopyAction(newNode->Action, Action);

    newNode->Next = *Top;
    *Top = newNode;

    return true;
}


bool PeekLastAction(struct Node *Top, char *TopAction)
{
    if (Top == NULL || TopAction == NULL)
    {
        return false;
    }

    CopyAction(TopAction, Top->Action);

    return true;
}


bool Undo(struct Node **Top, char *UndoneAction)
{
    if (Top == NULL || *Top == NULL || UndoneAction == NULL)
    {
        return false;
    }

    struct Node *nodeToDelete = *Top;

   
    CopyAction(UndoneAction, nodeToDelete->Action);

   
    *Top = nodeToDelete->Next;

    free(nodeToDelete);

    return true;
}


bool IsEmpty(struct Node *Top)
{
    return Top == NULL;
}


void PrintHistory(struct Node *Top)
{
    if (Top == NULL)
    {
        printf("\nHistory is empty.\n");
        return;
    }

    printf("\n===== ACTION HISTORY =====\n");

    struct Node *Current = Top;
    int position = 1;

    while (Current != NULL)
    {
        printf("%d. %s\n", position, Current->Action);

        Current = Current->Next;
        position++;
    }

    printf("==========================\n");
}


void FreeHistory(struct Node **Top)
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

    /*
        User performs actions
    */

    if (!PushAction(&Top, "Type A") ||
        !PushAction(&Top, "Type B") ||
        !PushAction(&Top, "Delete B") ||
        !PushAction(&Top, "Type C"))
    {
        printf("Failed to save action.\n");

        FreeHistory(&Top);

        return 1;
    }


    /*
        Expected history:

        Type C
        Delete B
        Type B
        Type A
    */

    PrintHistory(Top);


    /*
        Peek latest action
    */

    char LastAction[ACTION_SIZE];

    if (PeekLastAction(Top, LastAction))
    {
        printf("\nLast Action: %s\n", LastAction);
    }


    /*
        Undo latest action
    */

    char UndoneAction[ACTION_SIZE];

    if (Undo(&Top, UndoneAction))
    {
        printf("\nUndoing: %s\n", UndoneAction);
    }

    PrintHistory(Top);


    /*
        Undo again
    */

    if (Undo(&Top, UndoneAction))
    {
        printf("\nUndoing: %s\n", UndoneAction);
    }

    PrintHistory(Top);


    /*
        Current expected history:

        Type B
        Type A
    */

    printf("\nUndo remaining actions:\n");

    while (Undo(&Top, UndoneAction))
    {
        printf("Undoing: %s\n", UndoneAction);
    }


    /*
        History should now be empty
    */

    if (IsEmpty(Top))
    {
        printf("\nHistory is now empty.\n");
    }


    /*
        Test Undo on empty history
    */

    if (!Undo(&Top, UndoneAction))
    {
        printf("Cannot Undo: no actions available.\n");
    }


    /*
        Test Peek on empty history
    */

    if (!PeekLastAction(Top, LastAction))
    {
        printf("Cannot Peek: history is empty.\n");
    }


    FreeHistory(&Top);

    if (Top == NULL)
    {
        printf("Cleanup successful.\n");
    }

    return 0;
}