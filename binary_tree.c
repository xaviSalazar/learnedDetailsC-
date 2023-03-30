#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

// create new node in binary tree
struct node* create(value) 
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// insert on the leff of the node
struct node* insertLeft(struct node* root, int value)
{
    root->left = create(value);
    return root->left;
}

// insert right of the node 
struct node* insertRight(struct node* root, int value)
{
    root->right = create(value);
    return root->right;
}

// preorder traversal
void preorderTraversal(struct node* root)
{
    if(root == NULL) return;
    // print parent
    printf("%d -> ", root->data);
    // print left 
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// inorder traversal
void inorderTraversal(struct node* root)
{
    if(root == NULL) return;
    inorderTraversal(root->left);
    printf("%d -> ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(struct node* root)
{
    if(root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ", root->data);
}