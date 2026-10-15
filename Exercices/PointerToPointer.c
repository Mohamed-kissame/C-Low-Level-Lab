#include <stdio.h>

int main(void){


    int x = 10;
    int * P = &x;
    int  **pp = &P;


    printf("X Value    = %d\n" , x);
    printf("*P Value   = %d\n" , *P);
    printf("**PP Value = %d\n" , **pp);


    printf("X Address = %p\n" , (void *) &x);
    printf("P         = %p\n" , (void *)  P);
    printf("*PP        = %p\n" , (void *) *pp);

    printf("P address  = %p\n" , (void *)&P);
    printf("PP address = %p\n" , (void *)&pp);

    return 0;
}