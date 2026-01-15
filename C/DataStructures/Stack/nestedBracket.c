// Write a program to check the validity of the expression containing nested bracktes

// Meaning
//     The total number of left brackets must be equal to the total number of right brackets
//     For every right bracket, there should be a left bracket of same type

// Algorithm 

// 1. Create an empty stack
// 2. Scan the symbols of the expression from left to right
// 3. If the symbol is a left bracket, then push that symbol onto the stack
// 4. If the symbol is a right brancket, do the following
//     a. If the stack is empty
//         Print "Invalid Expression": Right brackets are more than the left brackets
//     b. else
//         Pop an element from the stack
//             If the popped bracket does not match with right bracket
//                 Print "Invalid Expression: Mismatched brackets."
// 5. After scanning all the symbols of the expression
//     a. If stack is empty
//         Print "Valid Expression"
//     b . Else
//         Print "Invalid Expression: Left brackets are more than right brackets" 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int top = -1;
char stack[MAX];

void push(char c){
    top++;
    stack[top] = c;
}

char pop(){
    top--;
    return stack[top+1];
}

int isEmpty(){
    if(top < 0){
        return 1;
    }
    else return 0;
}

int isFull(){
    if(top == MAX-1)
        return 1;
    else 
        return 0;
}
int match_char(char a, char b){
    if(a == '[' && b == ']')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    if(a == '(' && b == ')')
        return 1;
    return 0;
}


int check_balanced(char* s){
    int i;
    char temp;
    for(i=0; i<strlen(s); i++){
        if(s[i] == '[' || s[i] == '{' || s[i] == '(')
            push(s[i]);
        
        if(s[i] == ']' || s[i] == '}' || s[i] == ')'){
            if(isEmpty()){
                printf("Right brackets are more than the left brackets.\n");
                return 0;
            }
            else{
                temp = pop();
                if(!match_char(temp, s[i])){
                    printf("Mismatched brackets.\n");
                    return 0;
                }

            }
        }
        
    }
    if(isEmpty()){
        printf("Brackets are well balanced.\n");
        return 1;
    }
    else{
        printf("Left brackets are more than the right.\n");
        return 0;
    }
}

int main(){
    char expr[MAX];
    int balanced;
    printf("Enter the algebraic expression: ");
    gets(expr);
    balanced = check_balanced(expr);
    if(balanced){
        printf("The expression is valid.\n");
    }
    else{
        printf("The expression is not valid.\n");
    }
    return 0;
}

