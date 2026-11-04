#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int *CreatedArray(int count){

    if(count <= 0 ){
        return NULL;
    }

    int *p = malloc(count * sizeof *p);

    if(p == NULL){

        return NULL;
    }


    return p;
}

void Swap(int *a , int *b){

    if(a == NULL || b == NULL){

        return;
    }
    
    int temp = *a;
    *a = *b;
    *b = temp;
}


bool Add(int * arr , int count , int value){

    if(arr == NULL || count < 0){

        return false;
    }
    
    arr[count] = value;

    return true;

}

void SelectionSort(int * arr , int count){

    if(arr == NULL || count <= 1){

        return;
    }

    int MinIndex;

    for (int i = 0; i < count; i++)
    {

        MinIndex = i;

       for (int j = i + 1 ; j < count ; j++)
       {

           if(arr[j] < arr[MinIndex]){

              MinIndex = j;
           } 
        }

        if(i != MinIndex){

           Swap(&arr[i] , &arr[MinIndex]);
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

    SelectionSort(numbers1, count1);

    printf("\nAfter : ");
    for (int i = 0; i < count1; i++)
    {
        printf("%d ", numbers1[i]);
    }

    printf("\n\n");


    // Test 2: Already sorted
    int numbers2[] = {1, 2, 3, 4, 5};
    int count2 = sizeof(numbers2) / sizeof(numbers2[0]);

    printf("Test 2 - Already Sorted\n");

    SelectionSort(numbers2, count2);

    for (int i = 0; i < count2; i++)
    {
        printf("%d ", numbers2[i]);
    }

    printf("\n\n");


    // Test 3: Reverse sorted
    int numbers3[] = {5, 4, 3, 2, 1};
    int count3 = sizeof(numbers3) / sizeof(numbers3[0]);

    printf("Test 3 - Reverse Sorted\n");

    SelectionSort(numbers3, count3);

    for (int i = 0; i < count3; i++)
    {
        printf("%d ", numbers3[i]);
    }

    printf("\n\n");


    // Test 4: Duplicate values
    int numbers4[] = {4, 2, 4, 1, 2};
    int count4 = sizeof(numbers4) / sizeof(numbers4[0]);

    printf("Test 4 - Duplicates\n");

    SelectionSort(numbers4, count4);

    for (int i = 0; i < count4; i++)
    {
        printf("%d ", numbers4[i]);
    }

    printf("\n\n");


    // Test 5: Negative values
    int numbers5[] = {-3, 7, -10, 2, 0};
    int count5 = sizeof(numbers5) / sizeof(numbers5[0]);

    printf("Test 5 - Negative Values\n");

    SelectionSort(numbers5, count5);

    for (int i = 0; i < count5; i++)
    {
        printf("%d ", numbers5[i]);
    }

    printf("\n\n");


    // Test 6: One element
    int numbers6[] = {42};

    printf("Test 6 - One Element\n");

    SelectionSort(numbers6, 1);

    printf("%d\n\n", numbers6[0]);


    // Test 7: NULL / Empty
    printf("Test 7 - NULL Array\n");

    SelectionSort(NULL, 0);

    printf("Handled safely.\n");

    return 0;
}