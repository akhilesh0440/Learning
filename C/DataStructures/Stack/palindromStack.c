// Write a program check the string is palindrome

#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *link;
};

void push(char data, struct node **top){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Stack is overflow");
        exit(1);
    }
    newNode->data = data;
    newNode->link = *top;
    *top = newNode;
}

char pop(struct node **top){
    struct node *temp=*top;
    if(*top == NULL){
        printf("Stack is underflow");
    }
    *top = (*top)->link;
    return temp->data;
}
void reversedTop(struct node **top, struct node **reversedTop){
    struct node *temp = *top;
    while(temp != NULL){
        push(pop(&temp), reversedTop);
    }
}

void print(struct node **top){
    struct node *temp = *top;
    printf("The stack elements are: ");
    while(temp != NULL){
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int compare(struct node **top, struct node **rTop){
    struct node *ptr = *top, *ptr1 = *rTop;
    while((ptr != NULL) && (ptr1 != NULL)){
        if(ptr->data != ptr1->data){
            return 1;
        }
        ptr = ptr->link;
        ptr1 = ptr1->link;
    }
    return 0;
}

// void palindrome_check(char *s){
//     int size, n, i=0;
//     size = sizeof(s)/sizeof(s[0]);
//     n = size/2;

//     while(i<size){
//         if(i != n){
//             push()
//         }
//     }

// }

int main(){
    struct node *top=NULL; 
    struct node *rTop=NULL; 
    int flag;
    char* s;
    printf("Enter the word: ");
    scanf("%s", s);
    

    palindrome_check(s);

    push('a', &top);
    push('b', &top);
    push('c', &top);
    push('c', &top);
    push('a', &top);
    print(&top);
    reversedTop(&top, &rTop);
    print(&rTop);
    flag = compare(&top, &rTop);
    if(!flag){
        printf("The word is palindrome");
    }
    else{
        printf("The word is not palindrome");
    }

}
