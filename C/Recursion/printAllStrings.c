// Given an array nums of distinct integers, return all the possible permutations. You can retrun the answer in any __ORDER_BIG_ENDIAN__

// Example 1:

// Input: nums = [1, 2, 3]
// output: [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]

#include<stdio.h>

void recuPermute(int *nums, int *map, int *ds, int *dsSize, int ans[][3], int *ansCol, int *ansSize, int size){
    if(*dsSize == size){
        int row = *ansSize;
        for(int i=0; i<*dsSize; i++){
            ans[row][i] = ds[i];
        }
        (*ansSize)++;
        ansCol[row] = *dsSize;
        return;
    }
    for(int i=0; i<size; i++){
        if(!map[i]){
            ds[*dsSize] = nums[i];
            (*dsSize)++;
            map[i] = 1;
            recuPermute(nums, map, ds, dsSize, ans, ansCol, ansSize, size);
            map[i] = 0;
            (*dsSize)--;
        }
    }
}

int main(){
    int nums[3] = {1, 2, 3};
    int n = 3;
    int ds[n];
    int map[3] = {0, 0, 0};
    int dsSize = 0;
    int ansSize = 0;

    int ans[6][3];
    int ansCol[50];
    recuPermute(nums, map, ds, &dsSize, ans, ansCol, &ansSize, n);

    printf("[");
    for(int i=0; i<6; i++){
        printf("[");
        for(int j=0; j<ansCol[i]-1; j++){
            printf("%d,", ans[i][j]);
        }
        printf("%d],", ans[i][ansCol[i]-1]);
    }
    printf("]");
    return 0;

}