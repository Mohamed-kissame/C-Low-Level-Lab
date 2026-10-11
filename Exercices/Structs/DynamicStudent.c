#include <stdio.h>
#include <stdlib.h>

struct Student {

    int Id;
    int Age;
    float Grade;
};


int main(void){


   
    struct Student *student;
 
  
    student = malloc(sizeof(struct Student));

   
    if(student == NULL){
        return 1;
    }

    student->Id = 1;
    student->Age = 23;
    student->Grade = 16.5f;

    printf("ID       = %d\n" , student->Id);
    printf("Age      = %d\n" , student->Age);
    printf("Grade    = %.1f\n" , student->Grade);

    printf("Address of student  = %p\n" , (void *)student);
    printf("Address of Id       = %p\n" , (void *)&student->Id);
    printf("Address of Age      = %p\n" , (void *)&student->Age);
    printf("Address of Grade    = %p\n" , (void *)&student->Grade); 

    free(student);
    student = NULL;

    return 0;

}