// WAP to reverse an array

#include<stdio.h>

int main(){
    int array[5] = {1, 2, 3, 4, 5};
    int reverse[5];

    for(int i=4; i>=0; i--)
    {
        reverse[4-i] = array[i];
    }

    for(int i=0; i<=4; i++)
    {
        printf("%d ", reverse[i]);
    }
    return 0;

}