// Add two number using half adder logic
// a b  add carry
// 0 0   0    0
// 0 1   1    0
// 1 0   1    0
// 1 1   0    1

#include<stdio.h>

int main(){
    int a, b, sum, carry;
    printf("Enter the numbers a and b\n");
    scanf("%d%d", &a, &b);

    while(b != 0){
        sum = a ^ b;
        carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    printf("Sum is %d", sum);
    return 0;
}