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
        return root = newNode(data);

    if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    return root;
}

void postOrder(BST *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}