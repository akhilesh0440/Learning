// WAP to find the nth fibbonacci series number

#include<stdio.h>

int fibbonacci(int);
int main(){
    int n;
    printf("Enter the nth value: ");
    scanf("%d", &n);

    int result = fibbonacci(n-1);
    printf("%d value in the fibbonacci series is %d", n, result);
    return 0;
}

int fibbonacci(int n){
    if(n<1) return 0;
    else if(n==1) return 1;
    else return fibbonacci(n-1)+fibbonacci(n-2);
}