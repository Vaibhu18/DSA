#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
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

void preOrder(BST *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int search(BST *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
    {
        return 1;
    }

    if (root->data < key)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}