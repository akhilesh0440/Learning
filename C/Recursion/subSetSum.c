// Given a list(Arr) of N itegers, print sums of all subsets in it output should be printed in increasing order of sums.

// Example: 
// Input :
// n=2
// arr = [2, 3]
// output: 0 2 3 5

#include<stdio.h>

void subset_sum(int index, int sum, int *arr, int size, int *ds, int *dsSize){
    if(index == size){
        ds[*dsSize] = sum;
        (*dsSize)++;
        return;
    }
    subset_sum(index+1, sum+arr[index], arr, size, ds, dsSize);
    subset_sum(index+1, sum, arr, size, ds, dsSize);
}

int main(){
    // int n=3;
    int arr[3] = {3, 1, 2};
    int dsSize = 0;
    int ds[8];
    subset_sum(0, 0, arr, 3, ds, &dsSize);
    for(int i=0; i<7; i++){
        printf("%d, ", ds[i]);
    }
    printf("%d", ds[7]);
    return 0;
}