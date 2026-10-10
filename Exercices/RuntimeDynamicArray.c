#include <stdio.h>
#include <stdlib.h>


int ReadNumbers(void){

    int input;

    printf("How many numbers do you want :\n");

     while (scanf("%d", &input) != 1) {
        printf("Invalid input! Please enter a valid integer: ");
        
      
        while (getchar() != '\n'); 
    }

    return input;
}

int *CreateMemoryAllocated(int count){


    if(count <= 0){

        printf("The Count should be Greater than 0 to be valid please enter a valid input");
        return NULL;
    }

    int *arr = malloc(count * sizeof(int));

    if(arr == NULL){

        printf("Failed To create the Memory Allocation");
        return NULL;
    }

    return arr;

}

void FillArray(int *arr , int size){


    for (int i = 0; i < size; i++)
    {
     
        printf("Enter Element %d\n" , i + 1);

        scanf("%d" , (arr + i));

    }
    
}
 
int SumElementsOfArray(int *arr , int size){

    int sum = 0;

    for (int i = 0; i < size; i++)
    {
       sum += *(arr + i);
    }

    return sum;
    
}

void PrintValueAndAddressOfTheArrayElements(int *arr , int size){


    printf("\nDynamic Array :\n");


    for (int i = 0; i < size; i++)
    {
        printf("Index   = %d   |  Value   =  %d   |  Address   = %p\n" , i , arr[i] ,(void *) &arr[i]);
    }
    
    int sum = SumElementsOfArray(arr , size);

    printf("Sum  = %d\n" , sum);
}

int main(void){


    int count = ReadNumbers();

    int *numbers = CreateMemoryAllocated(count);

    if(numbers == NULL){

        return 1;
    }

    FillArray(numbers , count);

    PrintValueAndAddressOfTheArrayElements(numbers , count);

    free(numbers);
  
    numbers = NULL;
 
    return 0;
}