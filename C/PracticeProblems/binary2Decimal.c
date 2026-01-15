// hint   if bin = 1001
// 2**3 * 1 + 2**2 * 0 + 2**1 * 0 + 2**0 * 1

#include<stdio.h>

int main(){
    int binary, bit, weight=1, result=0;

    printf("Enter the binary number\n");
    scanf("%d", &binary);

    while(binary != 0){
        bit = binary % 10;
        result =  result + weight*bit;
        weight *= 2;
        binary /= 10;
    }
    printf("Decimal value of the binary number is '%d'", result);
    return 0;
}