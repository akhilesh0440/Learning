#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;  // indicates stack is empty

int isFull(){
    if(top >= MAX -1){
        return 1;
    }
    else return 0;
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else return 0;
}

void push(int data){
    if(isFull()){
        printf("Stack overflow\n");
        return;
    }
    else{
        top++;
        stack_arr[top] = data;
    }
}

void print(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    for(int i = top; i >= 0; i--)
    {
        printf("%d ", stack_arr[i]);
    }
}

int pop(){
    int value;
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    value = stack_arr[top];
    top--;
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
            printf("Top element of the stack is %d: \n", stack_arr[top]);
            break;
        case 4:
            print();
            break;        
        default:
            exit(1);
        }
    }

}

int main(){
    update();
    return 0;
}