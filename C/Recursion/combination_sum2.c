// give a collection of candidate numbers(candidates) and a target number (target), find all unique combinations in candidates
// where the candidate numbers sum to target.
// Each number in candidates may only  be used once in the combination
// Note: The solution set must not contain duplicate combinations.

// Example: 
// Input: candidates = [10, 1, 2, 7, 6, 1, 5], target = 8
// output:
// [
//     [1, 1, 6],
//     [1, 2, 5],
//     [1, 7]
//     [2, 6]
// ]

#include<stdio.h>

void findCombination(int index, int target, int *candidates, int ans[][7], int *ansSize, int *ansCol, int *ds, int dsSize, int size){
    if(target == 0){
        int row = *ansSize;
        for(int j=0; j<dsSize; j++){
            ans[row][j] = ds[j];
        }
        ansCol[row] = dsSize;
        (*ansSize)++;
        return;
    }
    
    for(int i = index; i<size; i++){
        if(i>index && candidates[i] == candidates[i-1]) continue;
        if(candidates[i]>target) break;
        ds[dsSize] = candidates[i];
        dsSize++;
        findCombination(i+1, target-candidates[i], candidates, ans, ansSize, ansCol, ds, dsSize, size);
        dsSize--;
    }

}

int main(){
    int candidates[5] = {1, 1, 1, 2, 2};
    int target = 4;
    int ans[4][7];
    int ds[4];
    int ansSize=0;
    int ansCol[150];   // length of each combination
    findCombination(0, target, candidates, ans, &ansSize, ansCol, ds, 0, 5);
    
    for (int i = 0; i < ansSize; i++) {
        printf("[");
        for (int j = 0; j < ansCol[i]; j++) {
            printf("%d", ans[i][j]);
            if (j < ansCol[i] - 1) printf(", ");
        }
        printf("]\n");
    }
}