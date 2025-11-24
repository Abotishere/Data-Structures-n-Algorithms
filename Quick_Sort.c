#include <stdio.h>

void quickSort(int arr[], int low, int high){
    // low - front or lower element of array
    // high - rear or higher element of the array
    if (low < high){
        int pivot = arr[low]; // first element chosen as pivot
        int i = low + 1;
        int j = high;

        // partition
        while (i <= j){
            while (i <= high && arr[i] <= pivot)
                i++;
            
            while (arr[j] > pivot)
                j--;
            
            // swap element if they are out of place
            if (i < j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // place pivot in correct position
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        // recursively sort left and right
        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

// main
int main(){
    int myArr[10];
    printf("Enter 10 elements:\n");
    for (int d = 0; d < 10; d++){
        scanf("%d", &myArr[d]);
    }

    quickSort(myArr, 0, 9); // hardcoded here

    printf("Sorted array:\n");
    for (int f = 0; f < 10; f++){
        printf("%d ", myArr[f]);
    }
    printf("\nArray has been sorted.\n");
    return 0;
}