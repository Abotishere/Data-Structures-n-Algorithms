// Binary Search Tree
// created by inserting values into the BST
// then printed with inorder traversal

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNew(int val){
    node* newNode = (node*) malloc(sizeof(node));
    if (!newNode) return NULL;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node* root, int value){
    if (root == NULL)
        return createNew(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    
    else if (value > root->data)
        root->right = insert(root->right, value);
    
    return root;
}

void inorder(node* root){
    if (root != NULL){
        // inorder: left -> root -> right
        inorder(root->left);

        printf("%d, ", root->data);

        inorder(root->right);
    }
}

int main(){
    node* root = NULL;
    int n, value;
    printf("Enter number or nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input! Enter a positive number");
        return 0;
    }

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder traversal of the Binary Search Tree:\n");
    inorder(root);
    printf("\n");
    
    return 0;
}