#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    float coeffi;
    int exponent;
    struct node *link;  
}NODE;

// |5|3|Next pointer| ---> |-3|2|next pointer| ---> |2|1|next pointer| ---> |1|0|NULL|

NODE *insert(NODE *head, float co, int ex){
    NODE *temp, *newP=(NODE *)malloc(sizeof(NODE));
    
    newP->coeffi = co;
    newP->exponent = ex;
    newP->link = NULL;
    
    if(head==NULL || ex > head->exponent){
        newP->link = head;
        return newP;
    }
    else{
        temp=head;
        while(temp->link != NULL && temp->link->exponent >= ex)
            temp = temp->link; 
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}

void print(NODE *head){
    NODE *temp;
    if (head==NULL)
        printf("No polynomial");
    else{
        temp=head;
        while(temp != NULL){
            printf("(%.1fx^%d)", temp->coeffi, temp->exponent);
            temp = temp->link;

            if(temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

NODE *create(NODE *head){
    int n, i;
    float coeff;
    int expo;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter the coefficient and exponent for term %d: ", i+1);
        scanf("%f %d", &coeff, &expo);
        head = insert(head, coeff, expo);
    }
    return head;
}

void additionOfPolynomial(NODE *firstP, NODE *SecondP){
    NODE *ptr1=firstP, *ptr2=SecondP, *result=NULL;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->exponent == ptr2->exponent){
            result = insert(result, ptr1->coeffi + ptr2->coeffi, ptr1->exponent);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->exponent > ptr2->exponent){
            result = insert(result, ptr1->coeffi, ptr1->exponent);
            ptr1 = ptr1->link;
        }
        else if(ptr2->exponent > ptr1->exponent){
            result = insert(result, ptr2->coeffi, ptr2->exponent);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1 != NULL){
        result = insert(result, ptr1->coeffi, ptr1->exponent);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL){
        result = insert(result, ptr2->coeffi, ptr2->exponent);
        ptr2 = ptr2->link;
    }
    printf("\nResult polynomial:\n");
    print(result);
}

void multiplicatonOfPolynomial(NODE *firstP, NODE *secondP){
    NODE *ptr1=firstP, *ptr2=secondP, *result=NULL, *ptr3=NULL, *temp = NULL;
    float coeff;
    int expo;

    if(ptr1 == NULL && ptr2 == NULL){
        printf("Zero Polynomial");
        return;
    }

    while(ptr1 != NULL){
        ptr2 = secondP;
        while(ptr2 != NULL){
            coeff = ptr1->coeffi * ptr2->coeffi;
            expo = ptr1->exponent + ptr2->exponent;
            result = insert(result, coeff, expo);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }

    printf("\nBefore polynomial:\n");
    print(result);

    ptr3 = result;
    while(ptr3->link != NULL){
        if(ptr3->exponent == ptr3->link->exponent){
            ptr3->coeffi = ptr3->coeffi + ptr3->link->coeffi;
            temp = ptr3->link;
            ptr3->link = temp->link;
            free(temp);
            temp = NULL;
        }
        else{
            ptr3 = ptr3->link;
        }
    }
    printf("\nResult polynomial:\n");
    print(result);
}


int main(){
    NODE *head1 = NULL, *head2=NULL, *result=NULL;
    printf("Enter the first polynomial\n");
    head1 = create(head1);
    print(head1);
    printf("\nEnter the Second polynomial\n");
    head2 = create(head2);
    print(head2);

    // additionOfPolynomial(head1, head2);
    multiplicatonOfPolynomial(head1, head2);
    return 0;
}