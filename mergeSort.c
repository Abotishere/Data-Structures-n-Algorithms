#include <stdio.h>
#include <stdlib.h>

// merges two halves of the array
void merge(int arr[], int left, int mid, int right){
    // left, mid, right- leftmost, middle, rightmost element of an array
    int n1 = mid - left + 1; // size of left half
    int n2 = right - mid; // size of right half

    // temporary arrays
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    if (L == NULL || R == NULL){
        printf("Error: Memory allocation failed.\n");
        return;
    }
    /* We can use VLAs like L[n1] and R[n2] to define them but
    MSVC doesn't support them. They are optional feature in the
    C11 standard. They can also cause Stack overflow if input
    array is very large.*/

    // copy data to temporary array
    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    // merge two halves into arr[]
    while (i < n1 && j < n2){
        if (L[i] < R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy remaining elements from L[] and R[] if any
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

    // free allocated memory
    free(L);
    free(R);
}

// recursive merge sort
void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// main
int main(){
    int myArr[6];
    printf("Enter 6 integers:\n");
    for (int i = 0; i < 6; i++){
        scanf("%d", &myArr[i]);
    }
    mergeSort(myArr, 0, 5); // sorts array from index 0 through 5

    printf("Sorted array:\n");
    for (int p = 0; p < 6; p++){
        printf("%d ", myArr[p]);
    }
    printf("\nArray has been sorted.\n");
    return 0;
}