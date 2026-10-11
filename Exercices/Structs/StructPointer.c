#include <stdio.h>


struct Student {

    int Id;
    int Age;
    float Grade;
};


int main(void){

    struct Student student1;

    student1.Id = 1;
    student1.Age = 23;
    student1.Grade = 18.5f;


    struct Student *pStudent = &student1;

    printf("ID       = %d\n" , pStudent->Id);
    printf("Age      = %d\n" , pStudent->Age);
    printf("Grade    = %1.f\n" , pStudent->Grade);


    printf("student1 address = %p\n", (void *)&student1);
    printf("pStudent value   = %p\n", (void *)pStudent);


    printf("age address = %p\n", (void *)&student1.Age);
    printf("age through pointer = %p\n", (void *)&pStudent->Age);

    return 0;

}