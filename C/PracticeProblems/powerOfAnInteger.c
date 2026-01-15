// Calculate the power of the integer.

#include<stdio.h>

int main(){
    int base, exponent;
    float result=1.0;

    printf("Enter the base and exponent\n");
    scanf("%d%d", &base, &exponent);
    
    if(exponent > 0){
        for(int i = 0; i < exponent; i++){
            result *= base;
        }
    }
    else{
        for(int i = 0; i > exponent; i--){
            result *= base;
        }
        result = 1/result;
    }
    printf("%f", result);
    return 0;
}