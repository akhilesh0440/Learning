// Given an integer array nums that may contin duplicatss, return all possible subsets(the power set).
// The solution set must not contain duplicate subsets. Return the solution is any order.

// Example 1: 
// Input: nums = [1, 2, 2]
// Output: [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]

#include<stdio.h>

void subSetsum2(int index, int *arr, int size, int *ds, int dsSize, int ans[][3], int *anscol, int *ansSize){
    int row = *ansSize;
    for(int i=0; i<dsSize; i++){
        ans[row][i] = ds[i];
    }
    (*ansSize)++;
    anscol[row] = dsSize;

    for(int i=index; i<size; i++){
        if(i > index && arr[i] == arr[i-1]) continue;
        ds[dsSize] = arr[i];
        dsSize++;
        subSetsum2(i+1, arr, size, ds, dsSize, ans, anscol, ansSize);
        dsSize--;
    }

}

int main(){
    int arr[] = {1, 2, 2};
    int ans[8][3];
    int ansSize=0;
    int ansCol[50];
    int ds[3];
    int dsSize=0;

    subSetsum2(0, arr, 3, ds, dsSize, ans, ansCol, &ansSize);
    printf("[");
    for(int i=0; i<8; i++){
        printf("[");
        for(int j=0; j<ansCol[i]-1; j++){
            printf("%d, ", ans[i][j]);
        }
        printf("%d],", ans[i][ansCol[i]-1]);
    }
    printf("]");
    return 0;
}