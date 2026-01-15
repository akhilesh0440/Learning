// write a program to find whether a given binary tree is BST or not

#include "BST_Global.h"
#include<stdio.h>
#include<stdlib.h>
 
int IsSubTreeLesser(BstNode *root, int value){
    if(root == NULL) return 1;
    if(root->data <= value && IsSubTreeLesser(root->right, value) && IsSubTreeLesser(root->left, value)){
        return 1;
    }
    else return 0;

};
int IsSubTreeGreater(BstNode *root, int value){
    if(root == NULL) return 1;
    if(root->data > value && IsSubTreeGreater(root->right, value) && IsSubTreeGreater(root->left, value)){
        return 1;
    }
    else return 0;
};


int isBinarySearchTree(BstNode *root, int minValue, int maxValue){
    if(root == NULL) return 1;
        
    if( root->data < minValue && root->data > maxValue
     && isBinarySearchTree(root->left, minValue, root->data) 
     && isBinarySearchTree(root->right, root->data, maxValue)){
        return 1;
     }
     else return 0;
}