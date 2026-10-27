#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ACTION_SIZE 30

struct PrintJob {

    int Id;
    char FileName[30];
    int Page;
};

struct Node {

   struct PrintJob job;
   struct Node *Next;

};

void CopyFileName(char * Destination , const char * Source){

    int i = 0;

    while (Source[i] != '\0' && i < ACTION_SIZE - 1)
    {
        Destination[i] = Source[i];
        i++;
    }

    Destination[i] = '\0';
    
}

bool AddPrintJob(struct Node **Front , struct Node **Rear , int ID , const char * FileName , int Page){

    if(Front == NULL || Rear == NULL || FileName == NULL){
        return false;
    }

    struct Node *newNode = malloc(sizeof *newNode );

    if(newNode == NULL){
        return false;
    }

    newNode->job.Id = ID;
    CopyFileName(newNode->job.FileName , FileName);
    newNode->job.Page = Page;
    newNode->Next = NULL;

    if(*Front == NULL){

        *Front = newNode;
        *Rear  = newNode;

        return true;
    }

    struct Node *Current = *Rear;

    Current->Next = newNode;
    *Rear = newNode;

    return true;

}

bool ProcessNextJob(struct Node **Front , struct Node **Rear , struct PrintJob * removedJob){

    if(Front == NULL || Rear == NULL || removedJob == NULL ){
        return false;
    }

    if(*Front == NULL || *Rear == NULL){
        return false;
    }

    struct Node *Current = *Front;

    *removedJob = Current->job;

    *Front = Current->Next;

    if(*Front == NULL){

        *Rear = NULL;
    }

    free(Current);

    return true;
}

bool PeekNextJob(struct Node *Front , struct PrintJob * Job){

    if (Front == NULL || Job == NULL)
    {
       return false;
    }

    *Job = Front->job;

    return true;
    
}

bool IsEmpty(struct Node *Front){
    return Front == NULL;
}

void PrintPendingJobs(struct Node *Front)
{
    if (Front == NULL)
    {
        printf("\nNo pending print jobs.\n");
        return;
    }

    printf("\n====================================================\n");
    printf("                PENDING PRINT JOBS\n");
    printf("====================================================\n");
    printf("%-5s %-8s %-25s %-8s\n",
           "No.", "ID", "File Name", "Pages");

    printf("----------------------------------------------------\n");

    struct Node *Current = Front;
    int Count = 1;

    while (Current != NULL)
    {
        printf("%-5d %-8d %-25s %-8d\n",
               Count,
               Current->job.Id,
               Current->job.FileName,
               Current->job.Page);

        Current = Current->Next;
        Count++;
    }

    printf("====================================================\n");
}

void FreeQueue(struct Node **Front , struct Node **Rear){

    if (Front == NULL || Rear == NULL )
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
    *Rear  = NULL;
    
    
}

int main(void)
{
    struct Node *Front = NULL;
    struct Node *Rear = NULL;

    struct PrintJob job;


    printf("=== Add Print Jobs ===\n");

    if (!AddPrintJob(&Front, &Rear, 101, "CV.pdf", 2) ||
        !AddPrintJob(&Front, &Rear, 102, "Report.pdf", 15) ||
        !AddPrintJob(&Front, &Rear, 103, "Invoice.pdf", 3) ||
        !AddPrintJob(&Front, &Rear, 104, "Project.pdf", 20))
    {
        printf("Failed to add print job.\n");

        FreeQueue(&Front, &Rear);
        return 1;
    }

    PrintPendingJobs(Front);


    printf("\n=== Peek Next Job ===\n");

    if (PeekNextJob(Front, &job))
    {
        printf(
            "Next Job: ID=%d | %s | %d pages\n",
            job.Id,
            job.FileName,
            job.Page
        );
    }


    printf("\n=== Process First Job ===\n");

    if (ProcessNextJob(&Front, &Rear, &job))
    {
        printf(
            "Printing: ID=%d | %s | %d pages\n",
            job.Id,
            job.FileName,
            job.Page
        );
    }

    PrintPendingJobs(Front);


    printf("\n=== Process Second Job ===\n");

    if (ProcessNextJob(&Front, &Rear, &job))
    {
        printf(
            "Printing: ID=%d | %s | %d pages\n",
            job.Id,
            job.FileName,
            job.Page
        );
    }

    PrintPendingJobs(Front);


    printf("\n=== Add Another Job ===\n");

    AddPrintJob(&Front, &Rear, 105, "Notes.pdf", 5);

    PrintPendingJobs(Front);


    printf("\n=== Process All Remaining Jobs ===\n");

    while (ProcessNextJob(&Front, &Rear, &job))
    {
        printf(
            "Printing: ID=%d | %s | %d pages\n",
            job.Id,
            job.FileName,
            job.Page
        );
    }


    if (IsEmpty(Front))
    {
        printf("\nQueue is empty.\n");
    }

    if (Front == NULL && Rear == NULL)
    {
        printf("Front = NULL\n");
        printf("Rear  = NULL\n");
    }


    printf("\n=== Process Empty Queue ===\n");

    if (!ProcessNextJob(&Front, &Rear, &job))
    {
        printf("Correct: no print jobs available.\n");
    }


    printf("\n=== Peek Empty Queue ===\n");

    if (!PeekNextJob(Front, &job))
    {
        printf("Correct: Queue is empty.\n");
    }


    printf("\n=== Reuse Queue ===\n");

    AddPrintJob(&Front, &Rear, 201, "NewFile.pdf", 7);
    AddPrintJob(&Front, &Rear, 202, "FinalReport.pdf", 12);

    PrintPendingJobs(Front);


    FreeQueue(&Front, &Rear);

    if (Front == NULL && Rear == NULL)
    {
        printf("\nCleanup successful.\n");
    }

    return 0;
}

