// Write a program to find a fibonacci series upto n number
// In fibonacci series, next term is obtained by taking sum of previous two terms

#include<stdio.h>

int main(){
    int a = 0, b = 1, n, fib;
    printf("Enter the nth value\n");
    scanf("%d", &n);

    printf("%d %d ", a, b);

    for(int i = 1; i <= n - 2; i++){
        fib = a + b;
        a = b;
        b = fib;
        printf("%d ", fib);
    }
    return 0;
}