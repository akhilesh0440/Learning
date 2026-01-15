#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}NODE;

NODE* addToEmpty(int data){
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}

NODE *insertNodeBeg(NODE *tail, int data){

    NODE *temp=tail->next, *newP=(NODE *)malloc(sizeof(NODE));
    newP=addToEmpty(data);
    if(tail == NULL){
        return newP;
    }
    else{
        newP->next = temp;
        newP->prev = tail;
        tail->next = newP;
        temp->prev = newP;
        return tail;
    }
}

void print(NODE *tail){
    NODE *temp=tail;

    if(tail==NULL){
        printf("No node in the list\n");
        return;
    }

    if(temp->next == temp->prev){
        printf("%d", temp->data);
        return;
    }

    do{
        temp = temp->next;
        printf("%d ", temp->data);
    }while(temp != tail);
    printf("\n");
}

NODE *insertNodeEnd(NODE *tail, int data){
    NODE *temp=tail->next, *newp = (NODE *)malloc(sizeof(NODE));
    newp = addToEmpty(data);
    if(tail == NULL){
        return newp;
    }
    else{
        tail->next = newp;
        newp->prev = tail;
        newp->next = temp;
        temp->prev = newp;
        return newp;
    }
}

void insertBTNodes(NODE **tail, int data, int pos){
    NODE *temp=(*tail)->next, *newP=(NODE *)malloc(sizeof(NODE));
    newP = addToEmpty(data);
    
    if(pos==1){
        insertNodeBeg(*tail, 32);
        return;
    }

    if(tail == NULL){
        *tail = newP;
    }
    else{
        for(int i=1; i<pos-1; i++){
            temp = temp->next;
        }
        newP->next = temp->next;
        newP->prev = temp;
        temp->next = newP;
        newP->next->prev = newP;
        if(temp == *tail){
            *tail = (*tail)->next;
        }
    }
}

void deleteFirstNode(NODE **tail){
    NODE *temp=(*tail)->next;

    if(temp->next == (*tail)->next){
        free(tail);
        *tail = NULL;
    }
    else{
        (*tail)->next = temp->next;
        (*tail)->next->prev = *tail;
        free(temp);
        temp=NULL;
    }
}

void deleteLastNode(NODE **tail){
    NODE *temp=(*tail)->prev;
    if(temp->next == (*tail)->next){
        free(tail);
        *tail = NULL;
    }
    else{
        temp->next = (*tail)->next;
        temp->next->prev = temp;
        free(*tail);
        *tail = temp;
    }
}

void deleteNodeInBt(NODE **tail, int pos){
    NODE *temp=(*tail)->next, *ptr;
    if(temp->next == (*tail)->next){
        free(tail);
        *tail = NULL;
    }
    else{
        for(int i=1; i<pos-1; i++){
            temp=temp->next;
        }
        ptr = temp->next;
        temp->next = ptr->next;
        temp->next->prev = temp;
        free(ptr);
        ptr = NULL;
        // if(temp->next=*tail){
        //     *tail=temp;
        // }
    }
}

int main(){
    NODE *tail;
    tail = addToEmpty(34);
    tail = insertNodeBeg(tail, 6);
    tail = insertNodeEnd(tail, 7);
    tail = insertNodeEnd(tail, 76);
    tail = insertNodeEnd(tail, 101);
    insertBTNodes(&tail, 23, 1);
    print(tail);
    deleteFirstNode(&tail);
    // deleteFirstNode(&tail);
    // deleteFirstNode(&tail);
    print(tail);
    deleteLastNode(&tail);
    print(tail);
    deleteNodeInBt(&tail, 2);
    print(tail);
    return 0;
}