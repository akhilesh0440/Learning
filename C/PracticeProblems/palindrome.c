// print whether a string or number is a palindrome or not
// 2332, 1221, 12321, 1234321

// reverse the string and compare

// use % to get the last digit
// add the digit to number * 10
// remove the last digit by dividing by 10
// repeat until number is 0

// a = 1221
// reminder = a % 10;
// result = 0

// result = result * 10 + reminder
// q = a / 10;

#include<stdio.h>

int main(){
    int input, copy, result = 0;
    int quotient, reminder;

    printf("Enter the Panlindrome number.\n");
    scanf("%d", &input);
    copy = input;

    while(copy != 0){
        reminder = copy % 10;
        result = result * 10 + reminder;
        copy = copy /10;
    }
    if (input == result){
        printf("Palindrome");
    }
    else{
        printf("Not a palindrome");
    }
    return 0;

}


