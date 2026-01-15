// Program to check whether the number is armstrong of not
// ArmStrong of nth number is a number in which each number will be multiplied by it own number nth times and added together
// 371, n=3 
// result 3*3*3 + 7*7*7 + 1*1*1 = 371

#include<stdio.h>

int main(){
    int n=0, number, reminder, result=0, q;

    printf("Enter the n number\n");
    scanf("%d", &number);
    
    q = number;
    while(q != 0){
        q /= 10;
        n ++;
    }
    
    while(number !=0 ){
        reminder = number % 10;
        int multiply = 1;
        for(int i=0; i < n; i++){
            multiply = multiply * reminder;                   
        }
        result += multiply;
        number /= 10;
    }
    printf("%d", result);
    return 0;
}