#include<stdio.h>

void findSum(int n, int sum){
    if(n < 1 ) {
        printf("%d", sum);
        return;
    }
    
    findSum(n-1, sum+n);
    
}
int main(){
    int n;
    printf("Enter the number.\n");
    scanf("%d", &n);

    findSum(n, 0);
    return 0;
}