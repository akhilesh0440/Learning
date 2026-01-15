typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}BstNode;

int isBinarySearchTree(BstNode *);
