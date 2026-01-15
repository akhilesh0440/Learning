#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int stack_arr[MAX];
int first = -1;  // tracking first inserted element

int isFull(){
    if(first >= MAX -1){
        return 1;
    }
    else return 0;
}

int isEmpty(){
    if(first == -1){
        return 1;
    }
    else return 0;
}

void push(int data){
    if(isFull()){
        printf("Stack Overflow\n");
        exit(1);
    }
    first++;
    for(int i=first; i>0; i--){
        stack_arr[i] = stack_arr[i-1];
    }
    stack_arr[0] =  data;
}

int pop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    else{
        int value = stack_arr[0];
        for(int i=0; i<first; i++)
            stack_arr[i] = stack_arr[i+1];
        first--;
        return value;
    }
}

void print(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    for(int i = 0; i <= first; i++)
    {
        printf("%d ", stack_arr[i]);
    }
}

int peek(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[0];
}

void primeFactor(int num){
    int i = 2;
    while(num != 1){
        while(num % i == 0){
            push(i);
            num = num/i;
        }
        i++;
    }

    while(first != -1){
        printf("%d ", pop());
    }
}

void update(){
    int choice, data;
    while(1){
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements of the stack\n");
        printf("5. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            printf("\n");
            push(data);
            break;
        case 2:
            data = pop(data);
            printf("Deleted data is %d: \n", data);
            break;
        case 3:
            printf("Top element of the stack is %d: \n", stack_arr[0]);
            break;
        case 4:
            print();
            break;        
        default:
            printf("Wrong choice.");
            exit(1);
        }
    }

}

void binaryToDecimal(int num){
    while(num != 0){
        push(num%2);
        num /= 2;
    }
    while(!isEmpty()){
        printf("%d", pop());
    }
}

int main(){
    int num;
    printf("Enter the number\n");
    scanf("%d", &num);
    binaryToDecimal(num);
    return 0;
}