// Sum of array using array

#include<stdio.h>

int main(){

    int arr[7] = {3, 2, 64, 6, 23, 6, 23};
    int sum=0, *p = &arr[0];

    
    for(p=&arr[0]; p<&arr[7]; p++)
    {
        sum = sum + *p;
    }
    printf("Sum is %d", sum);
    
    return 0;

}
