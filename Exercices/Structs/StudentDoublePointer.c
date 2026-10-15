#include <stdio.h>
#include <stdlib.h>


struct Student {

    int Id;
    int Age;
    float Grade;
};

int main(void){


    struct Student *student = malloc(sizeof(struct Student));

    if(student == NULL){

        return 1;
    }

    struct Student **ppStudent = &student;

    student->Id = 1;
    student->Age = 23;
    student->Grade = 18.5f;


    printf("Print Student using Student Pointer :\n");
    printf("Id      = %d\n" , student->Id);
    printf("Age     = %d\n" , student->Age);
    printf("Grade   = %.1f\n" , student->Grade );


    printf("\nPrint Student Using ppStudent Pointer :\n");
    printf("ppStudent ID      = %d\n " , (*ppStudent)->Id);
    printf("ppStudent Age     = %d\n " , (*ppStudent)->Age);
    printf("ppStudent Grdae   = %.1f\n " , (*ppStudent)->Grade);


    (**ppStudent).Age = 24;



    printf("\nPrint Student Age After Modify:\n");
    printf("Age      = %d\n " , student->Age);


    free(student);
    student = NULL;

    return 0;
   


}