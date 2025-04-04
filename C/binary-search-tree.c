#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} TREE;

TREE *createTree(TREE *root, int data)
{
    TREE *newNode = (TREE *)malloc(sizeof(TREE));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
        return root;
    }

    if (data < root->data)
        root->left = createTree(root->left, data);
    else
        root->right = createTree(root->right, data);

    return root;
}

void display(TREE *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    display(root->left);
    display(root->right);
}

void main()
{
    TREE *root = NULL;
    root = createTree(root, 10);
    root = createTree(root, 9);
    root = createTree(root, 11);
    root = createTree(root, 8);
    root = createTree(root, 12);
    display(root);
}