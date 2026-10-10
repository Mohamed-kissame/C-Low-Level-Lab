#include <stdio.h>
#include <stdlib.h>


void FillArray(int * arr , int size){


    for (int i = 0; i < size; i++)
    {
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


int *CopyArray(int *source, int size){

   if (source == NULL || size <= 0)
   {
    return NULL;
   }

    int *copy = malloc(size * sizeof(int));

    if(copy == NULL){

        printf("\nThe Mamory Allocation FAiled");
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
       copy[i] = *(source + i);
    }

    return copy;
    
}

void PrintArray(int * arr , int size){


    printf("[ ");

    for (int i = 0; i < size; i++)
    {
      
        printf("%d" , arr[i]);

        if(i < size - 1){
        printf(" , ");
       }
    }
    
    printf(" ]");
}

int main(void){

    int * original = CreateArray(5);

    if(original == NULL){

        return 1;
    }

    int * copy = CopyArray(original , 5);

    if(copy == NULL){

        return 1;
    }

    copy[0] = 999;

    printf("\nOriginal : " );
    PrintArray(original , 5);

    
    printf("\nCopy     : " );
    PrintArray(copy , 5);

    free(original);
    free(copy);

    original = NULL;
    copy = NULL;

    return 0;


}