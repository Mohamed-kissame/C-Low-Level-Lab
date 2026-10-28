#include <stdio.h>

int ProcessStatments(int n){

    int x = 0;

    char statment[4];

    for (int i = 0; i < n; i++)
    {
       
        scanf("%3s" , statment);

        if(statment[1] == '+'){

            x++;
        }
        else{
            x--;
        }
    }

    return x;
    
}

int main(void){
   
    int n;

    scanf("%d", &n);

    int x = ProcessStatments(n);

    printf("%d\n", x);

    return 0;
}