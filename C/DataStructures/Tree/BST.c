// Binary search tree - Implementation

// BST is a tree where value left node of the tree is lesser than value of nodes of right of the tree

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "BST_Global.h"

#define max(a, b)((a > b)? a : b)

typedef struct QNode{
    BstNode *data;
    struct QNode *link;
}NODE;

NODE *front = NULL;
NODE *rear = NULL;

int isEmpty(){
    return (front == NULL);
}

void enQueue(BstNode *root){
    NODE *temp = (NODE *)malloc(sizeof(NODE));

    if(temp == NULL){
        printf("The size of Queue has reached to its maximum limit.\n");
        exit(1);
    }

    temp->data = root;
    temp->link = NULL;

    if(isEmpty()){
        front = rear = temp;
    }
    else{
        rear->link = temp;
        rear = temp;
    }
}

void deQueue(){

    if((front == NULL) && (rear == NULL)){
        printf("The Queue is empty.\n");
    }
    
    NODE *temp = front;
    if(front->link == NULL){
        front = NULL;
        rear = NULL;
    }
    else{
        front = front->link;
    }
    free(temp);

}

BstNode *creatNode(int data){
    BstNode *newNode = (BstNode *)malloc(sizeof(BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BstNode *insertNode(BstNode *root, int data){
    if(root == NULL){
        root = creatNode(data);
        return root;
    }
    else if(data <= root->data){
        root->left = insertNode(root->left, data);
    }
    else{
        root->right = insertNode(root->right, data);
    }
    return root;
}

bool search(BstNode* root, int data){
    if(root == NULL) return false;
    else if(data == root->data) return true;
    else if(data < root->data) return search(root->left, data);
    else return search(root->right, data);
}

int findMin(BstNode* root){
    if(root->left == NULL){
        return root->data;
    }
    else return findMin(root->left);
}

int findMax(BstNode* root){
    if(root->right == NULL){
        return root->data;
    }
    else return findMax(root->right);
}

int findHeight(BstNode *root){
    if(root == NULL) return -1;
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void levelOrderTraversal(BstNode *root){
    // Breadth first search
    if(root == NULL) return;
    enQueue(root);
    
    while(!isEmpty()){

        BstNode *current = front->data;
        printf("%d ", current->data);
        if(current->left != NULL) enQueue(current->left);
        if(current->right != NULL) enQueue(current->right);
        deQueue();
    }

}

void PreOrder(BstNode *root){
    if(root == NULL) return;
    printf("%d ", root->data);
    if(root->left != NULL) PreOrder(root->left);
    if(root->right != NULL) PreOrder(root->right);
}

void postOrder(BstNode *root){
    if(root == NULL) return;
    if(root->left != NULL) postOrder(root->left);
    if(root->right != NULL) postOrder(root->right);
    printf("%d ", root->data);

}

void inOrder(BstNode *root){
    if(root == NULL) return;
    if(root->left != NULL) inOrder(root->left);
    printf("%d ", root->data);
    if(root->right != NULL) inOrder(root->right);
}

BstNode *delete(BstNode *root, int data){
    if(root = NULL) return root;
    else if(data < root->data) root->left =  delete(root->left, data);
    else if(data > root->data) root->right =  delete(root->right, data);
    else{
        // Case 1: No childe
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        // Case 2: One child
        else if(root->left == NULL){
            BstNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            BstNode *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: 2 children
        else{
            BstNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// BstNode *GetSuccesor(BstNode *root, int data){

//     BstNode *current = find(root, data);
//     if(current == NULL)
// }

int main(){
    BstNode *root = NULL;
    int min, max, height;
    root = insertNode(root, 16);
    root = insertNode(root, 14);
    root = insertNode(root, 19);
    root = insertNode(root, 9);
    root = insertNode(root, 15);
    root = insertNode(root, 17);
    root = insertNode(root, 20);

    // height = findHeight(root);
    // printf("The height of the tree is %d\n", height);

    // levelOrderTraversal(root);
    postOrder(root);
    if(isBinarySearchTree(root)){
        printf("The given tree is binary search tree\n");
    }
    else{
        printf("The given tree is not binary search tree\n");
    }

    return 0;

}