#include<stdio.h>

void print(int n){
    if(n == 0 ) return;
    else printf("%d ", n);
    return print(--n);
}
int main(){
    int n;
    printf("Enter the number.\n");
    scanf("%d", &n);

    print(n);
    return 0;
}