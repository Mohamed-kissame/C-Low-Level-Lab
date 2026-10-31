#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int * CreatedArray(int count){

    if (count <= 0){
        return NULL;
    }

    int *p = malloc(count * sizeof *p);

    if(p == NULL){

        return NULL;
    }

    return p;
}

bool Add(int * array , int count , int value){

    if (array == NULL || count < 0 ){

        return false;
    }

    array[count] = value;

    return true;
}

bool Swap(int * a , int * b){

    if(a == NULL || b == NULL){

        return false;
    }

    int temp = *a;
    *a = *b;
    *b = temp;

    return true;
}

void BubbleSort(int * array , int count){

    if(array == NULL){

        return; 
    }

    if (count <= 1){
          return;
    }

    int n = count  - 1;
    int Left;
    int Right;

    for(int i = 0 ; i < n ; i++){

        bool IsSwapped = false;

        for(int j = 0 ; j < n - i ; j++)
        {
            Left = j;
            Right = j + 1;

            if (array[j] > array[j + 1]){

                if(Swap( &array[Left] , &array[Right])){

                    IsSwapped = true;
                }
                else{

                    IsSwapped = false;
                }


            }

        }

        if(!IsSwapped){

            return;
        }
    }
}

int main(void)
{
    // Test 1: Unsorted array
    int numbers1[] = {7, 3, 5, 2};
    int count1 = sizeof(numbers1) / sizeof(numbers1[0]);

    printf("Test 1 - Unsorted Array\n");

    printf("Before: ");
    for (int i = 0; i < count1; i++)
    {
        printf("%d ", numbers1[i]);
    }

    BubbleSort(numbers1, count1);

    printf("\nAfter : ");
    for (int i = 0; i < count1; i++)
    {
        printf("%d ", numbers1[i]);
    }

    printf("\n\n");


    // Test 2: Already sorted array
    int numbers2[] = {1, 2, 3, 4, 5};
    int count2 = sizeof(numbers2) / sizeof(numbers2[0]);

    printf("Test 2 - Already Sorted\n");

    printf("Before: ");
    for (int i = 0; i < count2; i++)
    {
        printf("%d ", numbers2[i]);
    }

    BubbleSort(numbers2, count2);

    printf("\nAfter : ");
    for (int i = 0; i < count2; i++)
    {
        printf("%d ", numbers2[i]);
    }

    printf("\n\n");


    // Test 3: Reverse sorted array
    int numbers3[] = {5, 4, 3, 2, 1};
    int count3 = sizeof(numbers3) / sizeof(numbers3[0]);

    printf("Test 3 - Reverse Sorted\n");

    printf("Before: ");
    for (int i = 0; i < count3; i++)
    {
        printf("%d ", numbers3[i]);
    }

    BubbleSort(numbers3, count3);

    printf("\nAfter : ");
    for (int i = 0; i < count3; i++)
    {
        printf("%d ", numbers3[i]);
    }

    printf("\n\n");


    // Test 4: Duplicate values
    int numbers4[] = {4, 2, 4, 1, 2};
    int count4 = sizeof(numbers4) / sizeof(numbers4[0]);

    printf("Test 4 - Duplicates\n");

    printf("Before: ");
    for (int i = 0; i < count4; i++)
    {
        printf("%d ", numbers4[i]);
    }

    BubbleSort(numbers4, count4);

    printf("\nAfter : ");
    for (int i = 0; i < count4; i++)
    {
        printf("%d ", numbers4[i]);
    }

    printf("\n\n");


    // Test 5: One element
    int numbers5[] = {42};
    int count5 = sizeof(numbers5) / sizeof(numbers5[0]);

    printf("Test 5 - One Element\n");

    BubbleSort(numbers5, count5);

    printf("Result: %d\n\n", numbers5[0]);


    // Test 6: Empty input
    printf("Test 6 - Empty Array\n");

    BubbleSort(NULL, 0);

    printf("Handled safely.\n");

    return 0;
}