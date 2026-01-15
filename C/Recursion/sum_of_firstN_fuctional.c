#include<stdio.h>

int findSum(int n){
    if(n == 1 ) {
        return 1;
    }
    
    return n * findSum(n-1);
    
}
int main(){
    int n;
    printf("Enter the number.\n");
    scanf("%d", &n);

    int sum = findSum(n);
    printf("%d", sum);
    return 0;
}