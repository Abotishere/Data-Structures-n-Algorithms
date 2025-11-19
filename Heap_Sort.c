#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1; // left
    int r = 2*i + 2; // right

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i){
        // swap 
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    // building max heap
    for (int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    // extracting elememt them moving root to end
    for (int i = n-1; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Allocate memory on the heap
    int *myArr = (int*)malloc(n * sizeof(int));
    if (myArr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &myArr[i]);
    }

    heapSort(myArr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\n");

    free(myArr); // free the allocated memory after usage
    return 0;
}