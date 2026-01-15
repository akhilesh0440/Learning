// Write a program to check whether the given number is perfect number or not
// Perfect number is a postive integer that is equal to sum of its divisor excluding the number itself

#include<stdio.h>

int main(){
    int n, result=0;

    printf("Enter the number\n");
    scanf("%d", &n);
    
    for(int i=1; i<n; i++){
        if(n % i == 0){
            result += i;
        }
    }
    if(result == n){
        printf("Given number '%d' is a Perfect number", n);
    }
    else{
        printf("Given number '%d' is not a Perfect number", n);
    }
    return 0;
}
