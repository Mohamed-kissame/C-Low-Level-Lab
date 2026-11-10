#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int *CreatdArray(int count){

    if(count <= 0){

        return NULL;
    }

    int * p = malloc(count * sizeof *p);

    if (p == NULL){

        return NULL;
    }

    return p;
}

bool Add(int * array , int index , int value){

    if(array == NULL || index < 0 ){

        return false;
    }

    array[index] = value;

    return true;

}

void InsertionSort(int * array , int count){

    if(array == NULL || count <= 1){
        return ;
    }

    int n = count;

    int j = 0;

    for (int i = 1; i < n; i++)
    {

        int key = array[i];

         j = i - 1;

        while (j >= 0 && array[j] > key)
        {
           
           array[j + 1] = array[j];
          
           j--;

        }
        
        array[j + 1] = key;
    }
    
}

void PrintArray(int *array, int count)
{
    if (array == NULL)
        return;

    for (int i = 0; i < count; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main(void)
{
    // =========================
    // Test 1: Normal unsorted
    // =========================

    int count1 = 5;

    int *array1 = CreatdArray(count1);

    if (array1 == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    Add(array1, 0, 7);
    Add(array1, 1, 3);
    Add(array1, 2, 8);
    Add(array1, 3, 2);
    Add(array1, 4, 6);

    printf("Test 1 - Before sorting:\n");
    PrintArray(array1, count1);

    InsertionSort(array1, count1);

    printf("Test 1 - After sorting:\n");
    PrintArray(array1, count1);

    free(array1);
    array1 = NULL;


    // =========================
    // Test 2: Already sorted
    // =========================

    int array2[] = {1, 2, 3, 4, 5};
    int count2 = sizeof(array2) / sizeof(array2[0]);

    printf("\nTest 2 - Already sorted:\n");

    InsertionSort(array2, count2);

    PrintArray(array2, count2);


    // =========================
    // Test 3: Reverse sorted
    // =========================

    int array3[] = {5, 4, 3, 2, 1};
    int count3 = sizeof(array3) / sizeof(array3[0]);

    printf("\nTest 3 - Reverse sorted:\n");

    InsertionSort(array3, count3);

    PrintArray(array3, count3);


    // =========================
    // Test 4: Duplicates
    // =========================

    int array4[] = {4, 2, 4, 1, 2, 4};
    int count4 = sizeof(array4) / sizeof(array4[0]);

    printf("\nTest 4 - Duplicates:\n");

    InsertionSort(array4, count4);

    PrintArray(array4, count4);


    // =========================
    // Test 5: Negative numbers
    // =========================

    int array5[] = {-3, 5, -10, 7, 0, -1};
    int count5 = sizeof(array5) / sizeof(array5[0]);

    printf("\nTest 5 - Negative values:\n");

    InsertionSort(array5, count5);

    PrintArray(array5, count5);


    // =========================
    // Test 6: One element
    // =========================

    int array6[] = {99};

    printf("\nTest 6 - One element:\n");

    InsertionSort(array6, 1);

    PrintArray(array6, 1);


    // =========================
    // Test 7: NULL
    // =========================

    printf("\nTest 7 - NULL:\n");

    InsertionSort(NULL, 5);

    printf("NULL handled successfully.\n");


    return 0;
}