// eg. fibonacci number
#include<stdio.h>

int fibonacci(int n){
    if(n<=1) return n;
    int last = fibonacci(n-1);
    int sLast = fibonacci(n-2);
    return last+sLast;
}
int main(){
    int n;
    printf("Enter the n\n");
    scanf("%d", &n);
    int sum = fibonacci(n);
    printf("The %dth value in the fibonacci series is %d", n, sum);
}