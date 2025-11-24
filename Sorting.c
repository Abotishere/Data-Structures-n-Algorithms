#include <stdio.h>

void selectionSort(int arr[], int length){
    for (int i = 0; i <= length - 2; i++)
    {
        int minIndex = i; // first elem as min elem
        for (int j = i + 1; j <= length - 1; j++)
        {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        // swap new min elem with 1st elem of unsorted array
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    // sorted
}

void insertionSort(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    // sorted
}

void bubbleSort(int arr[], int length){
    for (int i = 0; i <= length-2; i++)
    {
        for (int j = 0; j <= length - i - 2; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap them
                arr[j] = arr[j] + arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] = arr[j] - arr[j + 1];
            }
        }
    }
    // sorted
}

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int myArr1[] = {1, 8, 9, 4, 5, 7, 1, 4, 5, 2, 9, 3}; // length = 12
    int myArr2[] = {4, 1, 9, 5, 2, 8, 3, 1, 7, 4, 9, 5}; // length = 12
    int myArr3[] = {7, 3, 1, 9, 4, 2, 8, 5, 1, 9, 4, 5}; // length = 12

    printf("Selection Sort:\n");
    selectionSort(myArr1, 12);
    printArray(myArr1, 12);

    printf("Insertion Sort:\n");
    insertionSort(myArr2, 12);
    printArray(myArr2, 12);
    
    printf("Bubble Sort:\n");
    bubbleSort(myArr3, 12);
    printArray(myArr3, 12);
}
