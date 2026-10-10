#include <stdio.h>


int main(void){

    int numbers[4] = {10, 20 , 30 ,40};

    int *P = numbers;

    printf("\nTraversal using array Indexing : \n");

    for (int i = 0; i < 4; i++)
    {
       printf("numbers[%d] = %d  |  Address = %p\n" , i , numbers[i] , (void *)&numbers[i]);
    }


    printf("\nTraversal using Pointer : \n");

    for (int i = 0; i < 4; i++)
    {
       printf("*P  = %d  | Address = %p\n" , *P , P);

       P++;
    }
    

    return 0; 
    

}