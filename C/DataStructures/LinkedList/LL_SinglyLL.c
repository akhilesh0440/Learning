#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void count_of_nodes(struct node *head){ //counting number of nodes present in the linked list
    struct node *ptr;
    ptr = head;
    int count = 0;
    if(head == NULL){
        printf("Linked list doesn't have any data\n");
        return;
    }
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
}

void print_data(struct node *head){ //Traversing the linked list to print the data
    if(head == NULL)
        printf("Linked list is empty");
    
    struct node *ptr = head;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

struct node* addAtEndOofN(struct node *ptr, int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;

    /* main function create struct node *ptr save the address of the node returning by this fuct each time 
    In this, time complexity reduced O(1)
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr = head;
    ptr = addAtEndOofN(ptr, 73);
    ptr = addAtEndOofN(ptr, 3);
    ptr = addAtEndOofN(ptr, 53);
    */
}
void addDataAtEnd(struct node *head, int data){
    struct node *temp, *ptr;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->link = NULL;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

struct node* addAtBegining(struct node *head, int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = head;
    return ptr;
}

void addAtBeginingWOReturning(struct node **head, int data){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = *head;

    *head = ptr;
}

void insertANode(struct node *head, int data, int pos){
    struct node *ptr, *ptr1 = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    for(int i=1; i<(pos-1); i++){
        ptr = ptr->link;
    }

    ptr1->data = data;
    ptr1->link = ptr->link;

    ptr->link = ptr1;
}

void deleteFirstNode(struct node **head){
    struct node *temp;
    temp = *head;

    if(*head == NULL){
        printf("List is empty\n");
        return;
    }

    *head = (*head)->link;
    free(temp);
}

void deleteLastNode(struct node *head){ //deleting last node using two and one pointer
    struct node *temp=head; //, *temp1;
    
    if(head == NULL){
        printf("List is already empty");
    }
    else if(head->link == NULL){
        free(head);
        head = NULL;
    }
    else{
        while(temp->link->link != NULL){
            //temp1 = temp;
            temp = temp->link;
        }
        free(temp->link->link);
        temp->link = NULL;
        // temp = NULL;
    }
}

void deleteNodeAtPosition(struct node **head, int pos){
    struct node *current = *head;
    struct node *previous = *head;
    if(head == NULL){
        printf("List is already empty");
    }
    else if(pos==1){
        *head = current->link;
        free(current);
        current = NULL;
    }
    else{
        while(pos != 1){
            // previous = current;
            previous = current;
            current = current->link;
            pos--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}

struct node* deleteLinkList(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        free(head);
        temp = temp->link;
        head = temp;
    }
    return head;
}

struct node* reverseLinkList(struct node *head){
    struct node *prev = NULL, *next = NULL;
    while(head != NULL){
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    return prev;
    
}

int main(){
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    addDataAtEnd(head, 5);
    head = addAtBegining(head, 232);
    addAtBeginingWOReturning(&head, 233);
    print_data(head);
    insertANode(head, 78, 2);
    print_data(head);
    // deleteNodeAtPosition(&head, 2);
    // print_data(head);
    // deleteFirstNode(&head);
    // print_data(head);
    // deleteLastNode(head);
    // print_data(head);
    // head = deleteLinkList(head);
    head = reverseLinkList(head);
    print_data(head);


    return 0;
}