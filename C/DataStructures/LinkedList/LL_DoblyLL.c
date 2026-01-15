#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}NODE;

NODE* addToEmpty(NODE* head, int data){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
    return head;
}

NODE* insertionAtBegining(NODE* head, int data){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;
    
    head->prev = temp;

    head = temp;
    return head;
}

void insertionAtend(NODE* head, int data){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    NODE* ptr;

    ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->data = data;
    temp->prev = ptr;
    temp->next = NULL;
}

void insertionBTNodes(NODE* head, int data, int pos){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    NODE* ptr=head;

    temp->data = data;
    temp->next = NULL;
    for(int i=1; i<pos-1; i++){
        ptr= ptr->next;
    }
    temp->prev = ptr;
    temp->next = ptr->next;
    ptr->next = temp;
}

NODE* createList(NODE* head){
    int n, data, i;

    printf("Enter the number of node: ");
    scanf("%d", &n);

    if(n==0)
        return head;

    printf("Enter the element for node 1: ");
    scanf("%d", &data);
    head = addToEmpty(head, data);

    for(i=1; i<n; i++){
        printf("Enter the element for node %d: ", i+1);
        scanf("%d", &data);
        insertionAtend(head, data);
    }
    return head;
}

void deletingFirstNode(NODE **head){
    NODE* ptr=*head;
    ptr = ptr->next;
    ptr->prev = NULL;

    free(*head);
    // *head = NULL;
    **head = *ptr;
}

void deletingLastNode(NODE* head){
    // NODE* temp= head;

    while(head->next->next != NULL){
        head = head->next;
    }
    free(head->next);
    head->next = NULL;
}

void print(NODE *ptr){
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void deleteNodeInBTW(NODE *head, int pos){
    NODE *temp=head;

    if(pos == 1){
        deletingFirstNode(&head);
    }

    for(int i=1; i<pos-1; i++){
        head = head->next;
    }
    if(head->next->next == NULL){
        deletingLastNode(temp);
    }
    else{
        temp = head->next;
        free(temp);
        head->next = temp->next;
        temp->prev = head;
        temp = NULL;
    }
}

NODE *reverseList(NODE *head){
    NODE *temp=head;
    NODE *temp1=temp->next;

    temp->next = NULL;
    temp->prev = temp1;

    while(temp1 != NULL){
        temp1->prev = temp1->next;
        temp1->next = temp;
        temp = temp1;
        temp1 = temp1->prev;
    }
    head = temp;
    return head;
}

int main(){
    NODE* head = NULL;
    head = addToEmpty(head, 45);
    head = insertionAtBegining(head, 1);
    insertionAtend(head, 777);
    insertionBTNodes(head, 34, 3);
    insertionBTNodes(head, 343, 3);
    insertionBTNodes(head, 386, 3);

    // head = createList(head);
    // deletingFirstNode(&head);
    // deletingLastNode(head);
    print(head);
    // deleteNodeInBTW(head, 3);
    head = reverseList(head);
    print(head);



    return 0;
}