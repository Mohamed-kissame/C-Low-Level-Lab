#include <stdio.h>
#include <stdlib.h>


struct Student {

    int Id;
    int Age;
    float Grade;
};


int main(void){


    int count = 3;

   
   struct Student **students = malloc(count * sizeof *students);


    
    if(students == NULL){

        return 1;
    }

   for (int i = 0; i < count; i++)
{
    students[i] = malloc(sizeof *students[i]);

    if (students[i] == NULL)
    {
        
        for (int j = 0; j < i; j++)
        {
            free(students[j]);
            students[j] = NULL;
        }

      
        free(students);
        students = NULL;

        return 1;
    }
}

    for(int i = 0 ; i < count ; i++){

        students[i]->Id = i + 1;
        students[i]->Age = 20 + i;
        students[i]->Grade = 10.5 + i;
    }

    printf("Print All Students  : \n");

    for (int i = 0; i < count; i++)
    {
       printf(" \nStudent %d\n" , i + 1);
       printf("Id        =  %d\n" , students[i]->Id);
       printf("Age       =  %d\n" , students[i]->Age);
       printf("Grade     =  %.1f\n" , students[i]->Grade); 

    }

    for(int i = 0 ; i < count ; i++){

        free(students[i]);
        students[i] = NULL;
    }
    
    free(students);
    students = NULL;
    

    return 0;
}