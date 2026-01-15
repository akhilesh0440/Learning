// WAP to  find the mid of the array using pointers

#include<stdio.h>

int *findMid(int arr[], int length)
{
    return &arr[length/2];
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr)/sizeof(arr[0]);
    int mid = *findMid(arr, length);
    printf("%d", mid);
    return 0;
}