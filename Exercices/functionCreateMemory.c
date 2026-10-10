#include <stdio.h>
#include <stdlib.h>



void FillArray(int * arr , int size){


    for(int i = 0 ; i < size ; i++){


        printf("Number %d\n" , i + 1);

        scanf("%d" , (arr + i));

    }

}


int *CreateArray(int size){

    if(size <= 0){

        return NULL;
    }

    int *arr = malloc(size * sizeof(int));

    if(arr == NULL){

        printf("\nThe Mamory Allocation FAiled");
        return NULL;
    }

    FillArray(arr , size);

    return arr;
}

void PrintArray(int *arr , int size){

      printf("\nDynamic Array :\n");


    for (int i = 0; i < size; i++)
    {
        printf("Index   = %d   |  Value   =  %d   |  Address   = %p\n" , i , arr[i] ,(void *) &arr[i]);
    }
}

void MultiplyByTwo(int *arr, int size){


    for(int i = 0 ; i < size ; i++){

     arr[i] *= 2;
     
    }

}



int main(void){

    int count = 5;


    int *numbers = CreateArray(count);

    if (numbers == NULL)
    {
    return 1;
    }


    PrintArray(numbers , count);


    printf("\nAfter Multipl the elements by Two : \n");

     MultiplyByTwo(numbers , count);

    PrintArray(numbers , count);

    free(numbers);

    numbers = NULL;

   return 0;
}