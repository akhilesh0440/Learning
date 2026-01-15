// Queue - Circular Array Implementation

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int rear = -1;
int front = -1;
int arr[MAX];

int Front(){
    return arr[front];
}

int isFull(){
    if(rear == MAX-1){
        return 1;
    }
    else return 0;
}

int isEmpty(){
    if((rear == -1) && (front == -1)) return 1;
    else return 0;
}

void enQueue(int data){
    if((rear+1)%MAX == front){
        printf("The Queue size has reached to maximum.\n");
        exit(1);
    }
    else if(isEmpty()){
        front = rear = 0;
    }
    else{
        rear = (rear+1)%MAX;
    }
    arr[rear] = data;
}

int deQueue(){
    if(isEmpty()){
        printf("The Queue is empty.\n");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front+1)%MAX;
    }

}

void print(){
    if(isEmpty()){
        printf("The queue is empty.\n");
        exit(1);
    }
    for(int i=0; i<=rear; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    enQueue(5);
    enQueue(2);
    print();
}
