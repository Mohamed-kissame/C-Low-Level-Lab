#include <stdio.h>
#include <stdlib.h>



void FillArray(int *arr , int size){

    for (int i = 0; i < size; i++)
    {
        arr[i] = (i + 1) * 10;
    }
    
    
}

int *CreateArray(int size){

    if(size <= 0){

        return NULL;
    }

    int *arr = malloc(size * sizeof(int));

    if(arr == NULL) {

         printf("\nThe Mamory Allocation FAiled");
        return NULL;
    }

    FillArray(arr , size);

    return arr;

}

void Print(int * arr , int size){

    for (int i = 0; i < size; i++)
    {
        printf("Index  %d   |  Value  = %d\n" , i  , *(arr + i));
    }
    
}

int *ShrinkArray(int * arr , int newSize){

    if(arr == NULL || newSize <= 0 ){

        return NULL;
    }

    int *temp = realloc(arr , newSize * sizeof(int));

    if(temp == NULL){

        return NULL;
    }

    return temp;
}

int main(void){


    int oldSize = 5;
    int newSize = 3;

    int * numbers = CreateArray(oldSize);

    if(numbers == NULL){

        return 1;
    }

     printf("Base Address of Numbers = %p\n" , (void *)numbers);
     Print(numbers , oldSize);


     int *temp = ShrinkArray(numbers , newSize);

     if(temp == NULL){

        free(numbers);
        numbers = NULL;
        return 1;
     }

     numbers = temp;


     printf("\nBase Address of Numbers = %p\n" , (void *)numbers);
     Print(numbers , newSize);

     free(numbers);
     numbers = NULL;

    return 0;



}