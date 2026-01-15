// 3 6 8 7
// + 5 6 7
// -------
// 4 2 5  4

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}NODE;

NODE *add_node(NODE *head, int data){
    NODE *newP=(NODE *)malloc(sizeof(NODE));
    
    newP->data = data;
    newP->link = head;
    head = newP;
    return newP;

}

NODE *input(NODE *head, int n){
    while(n != 0){
        head = add_node(head, n%10);
        n = n/10;
    }
    return head;
}

NODE *reverseLL(NODE *head){
    NODE *current=head, *next=head->link;
    head->link = NULL;
    
    while(next != NULL){
        current = next;
        next = next->link;
        current->link = head;
        head = current;
    }
    return head;
}

void print(NODE *head){
    NODE *temp=head;
    while(temp->link != NULL){
        printf("%d ->", temp->data);
        temp = temp->link;
    }
    printf("%d\n", temp->data);
}

NODE *addTwoLL(NODE *result, NODE *head1, NODE *head2){
    NODE *ptr1=head1, *ptr2=head2;
    int carry=0, sum=0;

    while(ptr1 || ptr2){
        sum = 0;
        if(ptr1)
            sum += ptr1->data;
        if(ptr2)
            sum += ptr2->data;
        sum += carry;
        result = add_node(result, sum%10);
        carry = sum/10;
        if(ptr1) 
            ptr1 = ptr1->link;
        if(ptr2)
            ptr2 = ptr2->link;
    }
    if(carry)
        result = add_node(result, carry);

    return result;
}
int main(){
    int firstN, secondN;
    printf("Enter the two numbers to be added:\n");
    scanf("%d%d", &firstN, &secondN);
    NODE *head1=NULL, *head2=NULL, *added=NULL;
    head1 = reverseLL(input(head1, firstN));
    print(head1);
    head2 = reverseLL(input(head2, secondN));
    print(head2);
    added = addTwoLL(added, head1, head2);
    print(added);
    return 0;
}