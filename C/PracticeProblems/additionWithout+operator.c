// write a number to add a two numbers without using '+' operator

// x = 3, y = 4
// x++, y-- repeat this until y = 0

#include<stdio.h>

int main(){
    int x, y;

    printf("Enter X and Y\n");
    scanf("%d%d", &x, &y);
    
    for(; y != 0; y--){
        x++;
    }
    printf("%d", x);
    return 0;
}