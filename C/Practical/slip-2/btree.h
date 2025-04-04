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

BST *create(BST *root, int data)
{
    if (root == NULL)
        return newNode(data);

    if (root->data > data)
    {
        root->left = create(root->left, data);
    }
    if (root->data < data)
    {
        root->right = create(root->right, data);
    }
    return root;
}

int search(BST *root, int key)
{
    if (root == NULL)
        return -1;

    if (root->data == key)
        return root->data;

    if (root->data > key)
        return search(root->left, key);
    if (root->data < key)
        return search(root->right, key);
}

void preorderTraversal(BST *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}