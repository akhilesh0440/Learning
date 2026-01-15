// Infix notation: A+B 
// The operators are written in between there operands.

// Postfix: AB+(Basically for computers)
// The operators are written after ther operands.

// ABC /+

// The order of evaluation of operatores is left to rigt with no brackets in the expression to chagne the order

// Division must be performed before addition


// Infix Expression                                            
// A + B / C * D - E / (F + G)  

// Postfix conversion
// A + B / C * D - E / (FG+)  
// A + BC/ * D - E / (FG+)  
// A + BC/D*  - E / (FG+)  
// A + BC/D*  - EFG+/
// ABC/D*+  - EFG+/
// ABC/D*+EFG+/-

// Postfix doesn't require multiple scans.(A signle scan is required) AND is, Therefore Efficient in time

// Note: The expressio will be scanned from left to right and as soon as we will encounter an operator, we will apply it to the last two operands.

// Eg:
// 854^2+*6293*/-
// 8, 6252+
// 8 627*
// 5016 62 27/-
// 5016 6-2/27

// How to use stack to convert the given infix expression to its equivlent postfix expression?

//     Scan the symbols of the expression from left to right and for each symbol, do the following:
//     a. If symbol is an operand
//         Print that symbol onto the screen.
//     b. If symbol is a left parenthesis
//         Push it on the stack
//     c. If symbol is a right parenthesis
//         Pop all the operators from the stack upto the first left parenthersis and print them on the screen
//         Discard the left and right parentheses
//     d. If symbol is an operator 
//         If the precedence of the operators in the stack are greater than or equal to the current operator, the 
//             Pop the operators out of the stack and print them onto the screen, and push the current operator onto the stack.
//         else
//             Push the current operator onto the stack

// Eg: 7+5*3/5^1+(3-2)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100

int top = -1;
int space(char);
int stack[MAX];
char infix[MAX], postfix[MAX];

void push(int val){
    if(top == MAX - 1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop(){
    return stack[top--];
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

int precedence(char symbol){
    switch (symbol)
    {
    // Higher value means greater precedence
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void print(char *s){
    printf("The elements are: ");
    for(int i=0; i<strlen(s); i++){
        printf("%c", s[i]);
    }
    printf("\n");
}

void inToPost(){
    // Conver infist to post fix expression
    int i=0, j=0;
    char symbol, next;
    for(; i < strlen(infix); i++){
        symbol = infix[i];
        if(!space(symbol)){
            switch(symbol){
                case '(':
                    push(symbol);
                    break;
                case ')':
                    while((next=pop()) != '(')
                        postfix[j++] = next;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                        postfix[j++] = pop();
                    push(symbol);
                    break;
                default:
                    postfix[j++] = symbol;
            }
        }
    }
    while(!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int space(char c){
    if(c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}

int post_val(){
    int i=0, a, b;
    for(; i < strlen(postfix); i++){
        if(postfix[i] >= '0' && postfix[i] <= '9')
            push(postfix[i] - '0');
        else{
            a = pop();
            b = pop();
            switch (postfix[i]){
            case '+':
                push(b+a); 
                break;
            case '-':
                push(b-a); break;
            case '*':
                push(b*a); break;
            case '/':
                push(b/a); break;
            case '^':
                push(pow(b, a)); break;
            }
        }
    }
    // a = pop();
    return pop();
}

int main(){
    int result;
    printf("Enter the infix expression: ");
    gets(infix);
    inToPost();
    print(postfix);
    result = post_val();
    printf("%d", result);
}

// Computing the postfix expression

// Scan the symbols of the fien postfix expression from left to right and for each symbol, do the following
//     1. If symbol is an operand
//         Push it to the stack
//     2. If symbol is an operator 
//         Pop two symbols out of the stack and apply the operator on these symbols.
//         Push the resul on the stack
//     3. After scannig all the symbols of the postfix expression po the remaining symbol out of the stak and print it on the screen. The remaining symbol is
//     the result obtained after evaluating the postfix expression.
        