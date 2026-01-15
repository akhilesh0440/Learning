// write a program to check whether a number is a Strong number or not?

// Strong number is a number in whic hthe sun of factorial of individual digitw fo a number is equal to the original number.
// 145 = 1! + 4! + 5! = 1+ 24+ 120 = 145

#include<stdio.h>

int main(){
    int number, result = 0, q, reminder;

    printf("Enter a number\n");
    scanf("%d", &number);

    q = number;

    while(q != 0){
        int factorial = 1, i = 1;
        reminder = q % 10;
        for(; i <= reminder; i++){
            factorial *= i;
        }
        result += factorial;
        q /= 10;
    }

    if(result == number){
        printf("%d is Strong number", number);
    }
    else{
        printf("%d is not a Strong number", number);

    }
    return 0;
}