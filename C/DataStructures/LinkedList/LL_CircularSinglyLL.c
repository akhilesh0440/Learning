#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;

NODE* addToEmpty(int data){
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = temp;
    return temp;
}

void insertNewNodeBeg(NODE *tail, int data){
    NODE *temp = (NODE *)malloc(sizeof(NODE));

    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;
}

void print(NODE *tail){
    NODE *temp=tail;

    if(temp==NULL){
        printf("No nodes are exists");
    }
    do
    {
        temp = temp->next;
        printf("%d ", temp->data);
    } while(temp != tail);
 
    printf("\n");
}

void insertionAtEnd(NODE **tail, int data){
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = (*tail)->next;
    (*tail)->next = temp;

    *tail = temp;
}

void insertNodeInBtw(NODE *tail, int data, int pos){
    NODE *temp = (NODE *)malloc(sizeof(NODE));

    temp->data = data;

    for(int i=0; i<pos-1; i++){
        tail = tail->next;
    }

    temp->next = tail->next;
    tail->next = temp;
}

NODE *createList(NODE *tail){
    int i, n, data;
    printf("Enter the number of node: ");
    scanf("%d", &n);
    
    if(n==0) return tail;

    printf("Enter the element 1: ");
    scanf("%d", &data);

    tail = addToEmpty(data);

    for(i=1; i<n; i++){
        printf("Enter the element %d: ", i+1);
        scanf("%d", &data);
        insertionAtEnd(&tail, data);
    }
    return tail;
}

NODE *deleteFistNode(NODE *tail){
    NODE *temp=tail->next;

    if(tail->next == temp->next){
        free(tail);
        tail=NULL;
        return tail;
    }
    else{
        tail->next = temp->next;
        free(temp);
    }
    return tail;
}

void deleteLastNode(NODE **tail){
    NODE *temp=(*tail)->next;

    if(temp->next == (*tail)->next){
        free(*tail);
        *tail = NULL;
        return;
    }

    while(temp->next != *tail){
        temp = temp->next;
    }
    temp->next = (*tail)->next;
    free(*tail);
    *tail = temp;
}

void deleteInBTWNode(NODE **tail, int pos){
    NODE *temp=(*tail)->next, *ptr;

    if(temp->next == (*tail)->next){
        free(*tail);
        *tail = NULL;
        return;
    }

    while(pos > 2){
        temp = temp->next;
        pos--;
    }
    ptr = temp->next->next;
    free(temp->next);
    temp->next = ptr;

    if(temp == *tail){
        *tail = temp;
    }
}

void countList(NODE *tail){
    NODE *temp=tail->next;
    int count = 0;

    while(temp != tail){
        temp = temp->next;
        count++;
    }
    count++;
    printf("Total number of elements are %d\n", count);

}

void findTheElement(NODE *tail, int data){
    NODE *temp=tail->next;
    int index=0;
    if(temp->data == data){
        printf("Element %d is stored in the first index\n", data);
    }
    while(temp->data != data){
        index++;
        temp = temp->next;
    }
    index++;
    if(index == 1){

    }
    printf("Element %d is stored in the index %d\n", data, index);
}

int main(){
    NODE *tail;
    // tail = createList(tail);
    tail = addToEmpty(34);
    // insertNewNodeBeg(tail, 6);
    insertNewNodeBeg(tail, 5);
    // insertNewNodeBeg(tail, 4);
    insertionAtEnd(&tail, 100);
    insertNewNodeBeg(tail, 3);
    insertNewNodeBeg(tail, 2);
    insertNewNodeBeg(tail, 1);
    insertNodeInBtw(tail, 10, 8);
    insertNodeInBtw(tail, 10, 5);
    insertionAtEnd(&tail, 89);
    print(tail);

    tail = deleteFistNode(tail);
    deleteLastNode(&tail);

    print(tail);
    deleteInBTWNode(&tail, 2);
    print(tail);
    int count;
    countList(tail);
    findTheElement(tail, 100);
    return 0;
}