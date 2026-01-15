#include<stdio.h>

void print(int count, int n){
    if(count > n) return;
    else printf("Hello World\n");
    return print(++count, n);
}
int main(){
    int n;
    printf("Enter the number.\n");
    scanf("%d", &n);

    print(1, n);
    return 0;
}