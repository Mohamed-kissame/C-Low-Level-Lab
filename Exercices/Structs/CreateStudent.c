#include <stdio.h>
#include <stdlib.h>

struct Student {

    int Id;
    int Age;
    float Grade;
};

struct Student *CreateStudent(int Id , int Age , float Grade ){

    if(Id <= 0 || Age <= 0){

        return NULL;
    }

    struct Student * student = malloc(sizeof(struct Student));

    if(student == NULL){

        return NULL;
    }

    student->Id = Id;
    student->Age = Age;
    student->Grade = Grade;

    return student;

}

void PrintStudent(struct Student *student){

    if(student == NULL){

        printf("No student found to print");
        return;
       
    }

    printf("ID       = %d\n" , student->Id);
    printf("Age      = %d\n" , student->Age);
    printf("Grade    = %.1f\n" , student->Grade);

}

int main(void){


    struct Student *student = CreateStudent(1 , 23 , 18.5f);

    if(student == NULL){

        return 1;
    }

    PrintStudent(student);

    free(student);
    student = NULL;

    return 0;
}