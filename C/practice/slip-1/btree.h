#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} BST;

BST *newNode(int data)
{
    BST *node = (BST *)malloc(sizeof(BST));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BST *insert(BST *root, int data)
{
    if (root == NULL)
    {
        return root = newNode(data);
    }
    if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(BST *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}