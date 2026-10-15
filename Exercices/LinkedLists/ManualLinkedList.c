#include <stdio.h>
#include <stdlib.h>


struct Node{

    int Value;
    struct Node *Next;
};

int main(void){


    struct Node First;
    struct Node Second;
    struct Node Third;

    First.Value = 10;
    Second.Value = 20;
    Third.Value = 30;

    First.Next = &Second;
    Second.Next = &Third;
    Third.Next = NULL;

    struct Node *head = &First;

    struct Node *Current = head;

    while(Current != NULL){

        printf("Value   = %d\n" , Current->Value);

        Current = Current->Next;
    }



    return 0;
}