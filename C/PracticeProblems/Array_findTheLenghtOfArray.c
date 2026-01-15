// WAP to find the lenght of the array

#include<stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 5, 6, 7, 3, 23, 353, 63, 1, 4, 3, 6, 2};
    printf("%d", sizeof(arr)/sizeof(arr[0]));

    return 0;
}