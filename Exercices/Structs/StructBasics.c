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


    printf("ID      = %d\n" , student1.Id);
    printf("Age     = %d\n" , student1.Age);
    printf("Grade   = %.1f\n" , student1.Grade);


    printf("\nSize of Student = %zu bytes\n" , sizeof(struct Student));
 
    printf("\nAddress student1  = %p\n" , (void *)&student1);

    printf("Address id       = %p\n",
           (void *)&student1.Id);

    printf("Address age      = %p\n",
           (void *)&student1.Age);

    printf("Address grade    = %p\n",
           (void *)&student1.Grade);

    return 0;



}