#include<stdio.h>

void merge(int *arr, int low, int mid, int high){
    int temp[high];
    int temp_ptr=0;
    int left = low;
    int right = mid+1;

    while((left <= mid) && (right <= high)){
        if(arr[left]<= arr[right]){
            temp[temp_ptr] = arr[left];
            left++;
        }
        else{
            temp[temp_ptr] = arr[right];
            right++;
        }
        temp_ptr++;

    }

    while (left <= mid)
    {
        temp[temp_ptr] = arr[left];
        left++;
        temp_ptr++;
    }

    while (right <= high)
    {
        temp[temp_ptr] = arr[right];
        right++;
        temp_ptr++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
    
}

void merge_sort(int *arr, int low, int high){
    if(low >= high) return;
    int mid = (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    int arr[5] = {5, 2, 4, 1, 3};
    merge_sort(arr, 0, 4);
    for(int i=0; i<5; i++){
        printf("%d", arr[i]);
    }
    return 0;
}