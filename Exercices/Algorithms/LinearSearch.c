#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int *CreatedArray(int Count){

    if(Count <= 0){
         
        return false;

    }

    int *p = malloc(sizeof(int) * Count);
    
    if(p == NULL){

        return false;
    }

    return p;
}

bool Add(int * numbers , int Index , int Value){

    if(numbers == NULL || Index < 0){

        return false;
    }

    numbers[Index] = Value;

    return true;

}

bool LinearSearch(int * numbers , int count , int Target , int * FoundAtIndex){

    if(numbers == NULL || count < 0 || FoundAtIndex == NULL ){

        return false;
    }

      *FoundAtIndex = -1;

    for (int i = 0; i < count; i++)
    {
       if (numbers[i] == Target)
       {
           *FoundAtIndex = i;
           return true;
       }
       
    }
    
   return false;

}

int main(void)
{
    int Count = 6;

    int *numbers = CreatedArray(Count);

    if (numbers == NULL)
    {
        printf("Failed to create array.\n");
        return 1;
    }


   
    Add(numbers, 0, 10);
    Add(numbers, 1, 8);
    Add(numbers, 2, 42);
    Add(numbers, 3, 23);
    Add(numbers, 4, 4);
    Add(numbers, 5, 16);


    printf("Array: ");

    for (int i = 0; i < Count; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n\n");


    int FoundAtIndex;


    // Best Case
    printf("Searching for 15...\n");

    if (LinearSearch(numbers, Count, 15, &FoundAtIndex))
    {
        printf("Found at index: %d\n", FoundAtIndex);
    }
    else
    {
        printf("Target not found.\n");
    }


    // Middle
    printf("\nSearching for 23...\n");

    if (LinearSearch(numbers, Count, 23, &FoundAtIndex))
    {
        printf("Found at index: %d\n", FoundAtIndex);
    }
    else
    {
        printf("Target not found.\n");
    }


    // Last Element
    printf("\nSearching for 16...\n");

    if (LinearSearch(numbers, Count, 16, &FoundAtIndex))
    {
        printf("Found at index: %d\n", FoundAtIndex);
    }
    else
    {
        printf("Target not found.\n");
    }


    // Target Does Not Exist
    printf("\nSearching for 99...\n");

    if (LinearSearch(numbers, Count, 99, &FoundAtIndex))
    {
        printf("Found at index: %d\n", FoundAtIndex);
    }
    else
    {
        printf("Target not found. Index = %d\n", FoundAtIndex);
    }


    free(numbers);
    numbers = NULL;

    return 0;
}