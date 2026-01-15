// Write a program to revese the elements of the stacks using two stacks.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void push(int data, struct node **top){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Stack is overflow\n");
        exit(1);
    }
    ptr->data = data;
    ptr->link = *top;
    *top = ptr;
}

int pop(struct node **top){
    struct node *temp;
    temp = *top;

    if(*top == NULL){
        printf("Stack is underflow\n");
        exit(1);
    }

    *top = (*top)->link;
    return temp->data;
}

void print(struct node *top){
    struct node *temp;
    temp = top;
    printf("The stack elements are: ");
    while(temp){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void reverse(struct node **top){
    struct node *top1 = NULL;
    struct node *top2 = NULL;

    while(*top != NULL){
        push(pop(top), &top1);
    }
    while(top1 != NULL){
        push(pop(&top1), &top2);
    }
    while(top2 != NULL){
        push(pop(&top2), top);
    }
}

int main(){
    struct node *top = NULL;
    int choice, data;
    while(1){
        printf("1. Push\n");
        printf("2. Print\n");
        printf("3. Reverse the stack\n");
        printf("4. Quit\n");
        printf("Enter your choice. ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data, &top);
        case 2: 
            print(top); 
            break;
        case 3: 
            reverse(&top);
            printf("Stack is reversed");
            break;
        case 4: exit(1);
        default:
            printf("Wrong Choice\n");
            break;
        }
    }
}