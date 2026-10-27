#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {

    int Value;
    struct Node *Next;
};

bool Enqueue(struct Node **Front , struct Node **Rear , int Value){

    if (Front == NULL || Rear == NULL){
        return false;
    }

    struct Node * newNode = malloc(sizeof *newNode);

    if(newNode == NULL){

        return false;
    }
    newNode->Value = Value;
    newNode->Next = NULL;

    if (*Front == NULL)
    {
        *Front = newNode;
        *Rear = newNode;

        return true;
    }

    struct Node *Current = *Rear;

    Current->Next = newNode;
    *Rear = newNode;

    return true;

}

bool IsEmpty(struct Node *Front){

    return Front == NULL;
}

bool Dequeue(struct Node **Front , struct Node **Rear , int * removedValue){


    if(Front == NULL || Rear == NULL || removedValue == NULL){

        return false;
    }

    if(*Front == NULL || *Rear == NULL){

        return false;
    }


    struct Node *Current = *Front;

    *removedValue = Current->Value;

    *Front = Current->Next;

    if(IsEmpty(*Front)){

        *Rear = NULL; 
    }

    free(Current);


    return true;


}


bool Peek(struct Node *Front , int * TargetValue){

    if(Front == NULL || TargetValue == NULL){

        return false;
    }

    *TargetValue = Front->Value;

    return true;
}

void PrintQueue(struct Node *Front)
{
    if (Front == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    struct Node *Current = Front;

    printf("\nFRONT -> ");

    while (Current != NULL)
    {
        printf("%d", Current->Value);

        if (Current->Next != NULL)
        {
            printf(" -> ");
        }

        Current = Current->Next;
    }

    printf(" <- REAR\n");
}


void FreeQueue(struct Node **Front, struct Node **Rear)
{
    if (Front == NULL || Rear == NULL)
    {
        return;
    }

    struct Node *Current = *Front;

    while (Current != NULL)
    {
        struct Node *Next = Current->Next;

        free(Current);

        Current = Next;
    }

    *Front = NULL;
    *Rear = NULL;
}

int main(void)
{
    struct Node *Front = NULL;
    struct Node *Rear = NULL;

    int value;


    // Test empty queue
    printf("Initial Queue:\n");
    PrintQueue(Front);


    // Enqueue values
    printf("\nEnqueue 10, 20, 30, 40\n");

    if (!Enqueue(&Front, &Rear, 10) ||
        !Enqueue(&Front, &Rear, 20) ||
        !Enqueue(&Front, &Rear, 30) ||
        !Enqueue(&Front, &Rear, 40))
    {
        printf("Enqueue failed.\n");

        FreeQueue(&Front, &Rear);

        return 1;
    }

    PrintQueue(Front);


    // Peek
    printf("\nPeek Front:\n");

    if (Peek(Front, &value))
    {
        printf("Front Value: %d\n", value);
    }


    // Expected Queue:
    // 10 -> 20 -> 30 -> 40


    // Dequeue first item
    printf("\nDequeue:\n");

    if (Dequeue(&Front, &Rear, &value))
    {
        printf("Removed: %d\n", value);
    }

    PrintQueue(Front);

    // Expected:
    // Removed 10
    // 20 -> 30 -> 40


    // Dequeue again
    printf("\nDequeue:\n");

    if (Dequeue(&Front, &Rear, &value))
    {
        printf("Removed: %d\n", value);
    }

    PrintQueue(Front);

    // Expected:
    // Removed 20
    // 30 -> 40


    // Add more values
    printf("\nEnqueue 50 and 60\n");

    Enqueue(&Front, &Rear, 50);
    Enqueue(&Front, &Rear, 60);

    PrintQueue(Front);

    // Expected:
    // 30 -> 40 -> 50 -> 60


    // Empty the Queue
    printf("\nRemoving all remaining items:\n");

    while (Dequeue(&Front, &Rear, &value))
    {
        printf("Removed: %d\n", value);
    }


    // Verify both pointers
    if (Front == NULL && Rear == NULL)
    {
        printf("\nQueue is completely empty.\n");
        printf("Front = NULL\n");
        printf("Rear  = NULL\n");
    }


    // Test Dequeue on empty Queue
    printf("\nTest Dequeue on empty Queue:\n");

    if (!Dequeue(&Front, &Rear, &value))
    {
        printf("Correct: cannot Dequeue from empty Queue.\n");
    }


    // Test Peek on empty Queue
    printf("\nTest Peek on empty Queue:\n");

    if (!Peek(Front, &value))
    {
        printf("Correct: cannot Peek empty Queue.\n");
    }


    // Reuse Queue after it became empty
    printf("\nReuse Queue:\n");

    Enqueue(&Front, &Rear, 100);
    Enqueue(&Front, &Rear, 200);

    PrintQueue(Front);


    // Final cleanup
    FreeQueue(&Front, &Rear);

    if (Front == NULL && Rear == NULL)
    {
        printf("\nCleanup successful.\n");
    }

    return 0;
}