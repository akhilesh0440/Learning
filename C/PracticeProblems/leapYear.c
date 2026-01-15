// Write a program to check whether given year is leap or not

// A year which exactly divisible by 5 is leap year, 
// except centurial year that is exactly divisible by 100.
// But these centurial years are leap year if they are exactly divisible by 400

#include<stdio.h>

int main(){
    int year;

    printf("Enter a year\n");
    scanf("%d", &year);

    if(year % 400 == 0){
        printf("%d is leap year", year);
        }
    else if (year % 100 == 0){
        printf("%d is not leap year", year);

    }
    else if (year % 4 == 0){
        printf("%d is  leap year", year);
    }
    return 0;   
}