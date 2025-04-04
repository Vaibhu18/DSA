#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} BT;

BT *newNode(int data)
{
    BT *node = (BT *)malloc(sizeof(BT));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BT *createBT(int arr[], int i, int n)
{
    if (i >= n)
        return NULL;
    BT *root = newNode(arr[i]);
    root->left = createBT(arr, 2 * i + 1, n);
    root->right = createBT(arr, 2 * i + 2, n);
    return root;
}

void display(BT *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    display(root->left);
    display(root->right);
}

void main()
{
    int arr[] = {5, 4, 3, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    BT *root = createBT(arr, 0, n);
    display(root);
}