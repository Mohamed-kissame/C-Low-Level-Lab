#include <stdio.h>

void Swap(int *a , int *b ){

    int temp = *a;
    *a = *b;
    *b = temp;

}


int main(void){


    int x = 10;
    int y = 20;

    printf("\nThe Value of X and Y before Swap them\n");
    printf("X value = %d\n" , x);
    printf("Y value = %d\n" , y);

    Swap(&x , &y);


    printf("\nThe Value of X and Y After Swap them\n");
    printf("X value = %d\n" , x);
    printf("Y value = %d\n" , y);

   return 0;

}