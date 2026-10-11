#include <stdio.h>


struct Student {

    int Id;
    int Age;
    float Grade;
};

void ChangeByValue(struct Student student){

    student.Age = 30;

    printf("Inside ChangeByValue : age = %d\n" , student.Age);
}

void ChangeByPointer(struct Student *student){

    student->Age = 30;

     printf("Inside ChangeByPointer : age = %d\n" , student->Age);
}


int main(void){

    struct Student student1;

    student1.Id = 1;
    student1.Age = 23;
    student1.Grade = 15.5f;

    printf("Original age = %d\n\n" , student1.Age);

    ChangeByValue(student1);

    printf("After ChangeByValue = %d\n\n" , student1.Age);

    ChangeByPointer(&student1);

    printf("After ChangeByPointer = %d\n" , student1.Age);

    return 0;

}


