#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int *CreatedArray(int Count){

    if (Count <= 0){

        return NULL;
    }

    int *p = malloc(Count * sizeof *p);

    if(p == NULL){

        return NULL;
    }


    return p;
}

bool Add(int * numbers , int index , int value){

      
    if (numbers == NULL || index < 0){

        return false;
    }


    numbers[index] = value;

    return true;

}

bool BinarySearch(int *numbers,int count, int target,int *foundIndex){


    if(numbers == NULL || count < 0 || foundIndex == NULL){
  
        return false;

    }

      *foundIndex = -1;
    int Low = 0;
    int High = count - 1;
  
    

    while (Low <= High)
    {
       
        int mid = Low + (High - Low) / 2;

        if (target == numbers[mid]){

            *foundIndex = mid;
            return true ;
        }

        if (target > numbers[mid])
        {
           Low = mid + 1;
        }
        else {

            High = mid - 1;
        }
        
    }
    
    return false ;

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


   Add(numbers, 0, 3);
   Add(numbers, 1, 7);
   Add(numbers, 2, 11);
   Add(numbers, 3, 18);
   Add(numbers, 4, 25);
   Add(numbers, 5, 31);

    printf("Array: ");

    for (int i = 0; i < Count; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n\n");


    int FoundAtIndex;


   
    printf("Searching for 3...\n");

    if (BinarySearch(numbers, Count, 3, &FoundAtIndex))
    {
        printf("Found at index: %d\n", FoundAtIndex);
    }
    else
    {
        printf("Target not found.\n");
    }


    // Middle
    printf("\nSearching for 11...\n");

    if (BinarySearch(numbers, Count, 11, &FoundAtIndex))
    {
        printf("Found at index: %d\n", FoundAtIndex);
    }
    else
    {
        printf("Target not found.\n");
    }


    // Last Element
    printf("\nSearching for 31...\n");

    if (BinarySearch(numbers, Count, 31, &FoundAtIndex))
    {
        printf("Found at index: %d\n", FoundAtIndex);
    }
    else
    {
        printf("Target not found.\n");
    }


    // Target Does Not Exist
    printf("\nSearching for 99...\n");

    if (BinarySearch(numbers, Count, 99, &FoundAtIndex))
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
