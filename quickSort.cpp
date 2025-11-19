#include <stdio.h>

void partition(int arr[], int lb, int ub, int j){

}

void quickSort(int arr[], int a, int b){

}

int main(){
    int arr[] = {};
    int lb;
    int ub;
    if (lb >= ub){
        return;
    }
    int j;
    partition(arr, lb, ub, j);

    quickSort(arr, lb, j-1);
    quickSort(arr, j+1, ub);
    // print sorted array
}