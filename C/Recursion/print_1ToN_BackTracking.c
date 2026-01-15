#include<stdio.h>

void print(int n){
    if(n < 1 ) return;
    
    print(n-1);
    printf("%d ", n);
}
int main(){
    int n;
    printf("Enter the number.\n");
    scanf("%d", &n);

    print(n);
    return 0;
}