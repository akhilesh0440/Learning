#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}NODE;

NODE *front = NULL;
NODE *rear = NULL;

void enQueue(int data){
    NODE *temp = (NODE *)malloc(sizeof(NODE *));
    temp->data = data;
    temp->link = NULL;

    if(temp == NULL){
        printf("The size of Queue has reached to its maximum limit.\n");
        exit(1);
    }

    if((front == NULL) && (rear == NULL)){
        front = rear = temp;
    }
    else{
        rear->link = temp;
        rear = temp;
    }
}

int deQueue(){
    NODE *temp = front;
    int value = temp->data;

    if((front == NULL) && (rear == NULL)){
        printf("The Queue is empty.\n");
    }

    if(front->link == NULL){
        front = NULL;
        rear = NULL;
    }
    else{
        front = front->link;
        free(temp);
    }

    return value;
}

void print(){
    if((front == NULL) && (rear == NULL)){
        printf("The Queue is empty.\n");
        return;
    }
    else{
        NODE *temp = front;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main(){
    enQueue(1);
    enQueue(5);
    enQueue(5);
    enQueue(5);
    enQueue(5);
    enQueue(5);
    print();
    deQueue();
    print();
    return 0;
    
}