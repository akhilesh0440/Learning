// WAP to find Largerst ans smallest numbers in the array using pointers

#include<stdio.h>

void minMax(int length, int arr[], int *min, int *max)
{
    for(int i=1; i<length; i++){
        if(arr[i] < *min){
            *min = arr[i];
        }
        else if(arr[i] > *max){
            *max = arr[i];
        }
    }
}

int main()
{
    int arr[] = {353, 21, 53, 134, 64, 75, 34, 45, 232, 77, 77, 34, 23, 75};
    int min, max;
    min=max=arr[0];

    int length = sizeof(arr)/sizeof(arr[0]);

    minMax(length, arr, &min, &max);
    printf("Smallest value in the list is %d and Largest value in the list %d", min, max);
    return 0;
}