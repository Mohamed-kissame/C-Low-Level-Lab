#include <stdio.h>
#include <stdlib.h>


int size;
int capacity;
int *numbers;


int Initialize(void){

    capacity = 2;
    size = 0;

    numbers = malloc(capacity * sizeof(int));

    if(numbers == NULL){

        return 0;
    }

    return 1;

}


int Resize(void){

    int newCapacity = capacity * 2;

    int *temp = realloc(numbers , newCapacity * sizeof(int));

    if(temp == NULL){

        return 0;
    }

    numbers = temp;
    capacity = newCapacity;

    return 1;
}

int Add(int value){

  
    if(size >= capacity){

       if(!Resize()){

          return 0;
       }
    }

     numbers[size] = value;
        size++;

        return 1;
}

void Print(void){

    for (int i = 0; i < size; i++)
    {
       printf("Number %d  | =  %d\n" , i + 1 , numbers[i]);
    }
    
}

void Cleanup(void){

    free(numbers);
    numbers = NULL;

}


int main(void)
{
    if (!Initialize())
    {
        printf("Failed to initialize dynamic array.\n");
        return 1;
    }

    int values[] = {10, 20, 30, 40, 50, 60};

    int count = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < count; i++)
    {
        if (!Add(values[i]))
        {
            printf("Failed to add %d.\n", values[i]);

            Cleanup();
            return 1;
        }

        printf(
            "Added: %d | Size: %d | Capacity: %d | Address: %p\n",
            values[i],
            size,
            capacity,
            (void *)numbers
        );
    }

    printf("\nFinal Array:\n");
    Print();

    Cleanup();

    return 0;
}

