// A contiqous or noncontiqous sequences, which folls the order.
// arr = [3, 1, 2]
// [3, 1]
// [3, 2]
// [3, 1, 2]

#include<stdio.h>

void subSequnce(int index, int arr[], int *arr1, int n, int arr1_len){
    if(index >=n){
        for(int k=0; k<arr1_len; k++ ){
            printf("%d ", arr1[k]);
        }
        printf("\n");
        return;
    }

    arr1[arr1_len] = arr[index];
    subSequnce(index+1, arr, arr1, n, arr1_len+1);
    subSequnce(index+1, arr, arr1, n, arr1_len);
}

void sumSubSequnce(int index, int arr[], int s, int sum, int *arr1, int n, int arr1_len){
    if(index >=n){
        if(s == sum){
            for(int k=0; k<arr1_len; k++ ) printf("%d ", arr1[k]);
            printf("\n");
        }
        return;
    }

    arr1[arr1_len] = arr[index];
    s += arr1[arr1_len];
    sumSubSequnce(index+1, arr, s, sum, arr1, n, arr1_len+1);

    s -= arr1[arr1_len];
    sumSubSequnce(index+1, arr, s, sum, arr1, n, arr1_len);
}

int printOneTimesumSubSequnce(int index, int arr[], int s, int sum, int *arr1, int n, int arr1_len){
    if(index >=n){
        if(s == sum){
            for(int k=0; k<arr1_len; k++ ) printf("%d ", arr1[k]);
            printf("\n");
            return 1;
        }
        return 0;
    }

    arr1[arr1_len] = arr[index];
    s += arr1[arr1_len];
    if(printOneTimesumSubSequnce(index+1, arr, s, sum, arr1, n, arr1_len+1) == 1) return 1;

    s -= arr1[arr1_len];
    if(printOneTimesumSubSequnce(index+1, arr, s, sum, arr1, n, arr1_len) == 1) return 1;
    return 0;
}

int noOfSequencesumSubSequnce(int index, int arr[], int s, int sum, int n, int arr1_len){
    // printf how subSequnces equal to sum
    if(index >=n){
        if(s == sum){
            return 1;
        }
        return 0;
    }

    s += arr[arr1_len];
    int l = noOfSequencesumSubSequnce(index+1, arr, s, sum, n, arr1_len+1);

    s -= arr[arr1_len];
    int r = noOfSequencesumSubSequnce(index+1, arr, s, sum, n, arr1_len+1);
    
    return l+r;
}

int main(){
    int n;
    printf("Enter the size of array.\n");
    scanf("%d", &n);

    int arr[n], arr1[n];
    int sum = 10;

    printf("Enter the elements of array.\n");
    for(int i=0; i<n; i++){
        scanf("%d", arr+i);
    }

    printf("\nThe subsequence is: \n");
    // subSequnce(0, arr, arr1, n, 0);
    // printOneTimesumSubSequnce(0, arr, 0, sum, arr1, n, 0);
    int numberOfSequence = noOfSequencesumSubSequnce(0, arr, 0, sum, n, 0);
    printf("There are %d subsequences where sum is %d", numberOfSequence, sum);
}