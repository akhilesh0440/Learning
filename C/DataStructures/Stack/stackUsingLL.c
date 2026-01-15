#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*top = NULL;

void push(int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Stack is overflow\n");
        exit(1);
    }
    ptr->data = data;
    ptr->link = top;
    top = ptr;
}

int pop(){
    struct node *temp;
    temp = top;
    int value = temp->data;

    if(top == NULL){
        printf("Stack is underflow\n");
        exit(1);
    }

    top = top->link;
    free(temp);
    return value;
}

void print(){
    struct node *temp;
    temp = top;
    printf("The stack elements are: ");
    while(temp){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    int choice, data;
    while(1){
        printf("1. Push\n");
        printf("2. Print\n");
        printf("3. Quit\n");
        printf("Enter your choice. ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data);
        case 2: print(); break;
        case 3: exit(1);
        default:
            printf("Wrong Choice\n");
            break;
        }
    }
}