#include<stdio.h>

void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int *arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i] <= pivot && i<=high-1){
            i++;
        }

        while(arr[j] > pivot && i >= low+1){
            j--;
        }
        if(i<j) swap(arr, i, j);
    }
    swap(arr, low, j);
    return j;
}

void quick_sort(int *arr, int low, int high){
    if(low<high){
        int pIndex = partition(arr, low, high);
        quick_sort(arr, low, pIndex-1);
        quick_sort(arr, pIndex+1, high);
    }
}

int main(){
    int arr[5] = {5, 6, 4, 1, 3};
    quick_sort(arr, 0, 4);
    for(int i=0; i<5; i++){
        printf("%d", arr[i]);
    }
    return 0;
}