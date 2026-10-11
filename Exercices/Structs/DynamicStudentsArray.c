#include <stdio.h>
#include <stdlib.h>


struct Student {

    int Id;
    int Age;
    float Grade;
};

void FillStudents(struct Student *students , int count){

    if(students == NULL || count <= 0){
        printf("No students found to Fill");
        return;
    }

    float Grade = 10.5;

    for (int i = 0; i < count; i++)
    {
       students[i].Id = i + 1;
       students[i].Age = i + 20;
       students[i].Grade = Grade;

       Grade++;
    }
    
}

struct Student *CreateStudents(int count){

    if (count <= 0)
    {
       return NULL;
    }

    struct Student *students = malloc(count * sizeof * students);

    if(students == NULL){

        return NULL;
    }

    return students;
    
}

void PrintStudents(struct Student *students , int count ){


    if(students == NULL || count <= 0){

        printf("No students found to print");
        return;
    }

    for (int i = 0; i < count; i++)
    {
       printf("\nStudent  %d\n" , i + 1);
       printf("Student address = %p\n", (void *)&students[i]);
       printf("ID             = %d\n" , students[i].Id );
       printf("Age            = %d\n" , students[i].Age );
       printf("Grade          = %.1f\n" , students[i].Grade );
    }
    
}

int main(void){


    int count = 5;
    struct Student *students = CreateStudents(count);

    if(students == NULL){

        return 1;
    }

    FillStudents(students , count);

    PrintStudents(students , count);

    free(students);
    students = NULL;

    return 0;

}