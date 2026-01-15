// Given an arroy of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates
// where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of time. Two combinations are unique i the frequncy of at least one
// of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target is less than 150 cominations for the given input.

// Example 1:

// Input: Candidates = [2, 3, 6, 7], target = 7
// output: [[2, 2, 3], [7]]
// Explanation:
// 2 and 3 are cnadidates and 2+2+3=7. Note that 2 can be useed multiple time.
// 7 is a candidate, and 7=7
// These are the only two combinations

#include<stdio.h>

void findCombination(int index, int target, int *candidates, int ans[][7], int ansSize, int *ds, int dsSize, int size){
    if(index == size-1){
        if(target == 0){
            ansSize++;
            for(int i=0; i<ansSize; i++){
                for(int j=0; j<dsSize; j++){
                    ans[i][j] = ds[j];
                }
            }
            ansSize++;
        }
        return;
    }
    if(candidates[index] <= target){
        ds[dsSize] = candidates[index];
        dsSize++;
        findCombination(index, target-candidates[index], candidates, ans, ansSize, ds, dsSize, size);
        dsSize--;
    }
    findCombination(index+1, target, candidates, ans, ansSize, ds, dsSize, size);
}

int main(){
    int candidates[4] = {2, 3, 6, 7};
    int target = 7;
    int ans[4][7];
    int ds[4];
    findCombination(0, target, candidates, ans, 0, ds, 0, 4);
    for(int i=0; i<4; i++){
        printf("[");
        for(int j=0; j<7; j++){
            printf("%d, ", ans[i][j]);
        }
        printf("]\n");
    }
}