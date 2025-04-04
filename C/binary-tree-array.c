/*
    case 1: array start index start from 0
        left child = [(2*i)+1]
        right child = [(2*i)+2]
        parrent = [(i-1)/2]

    case 2: array start index start from 1
        left child = [2*i]
        right child = [(2*i)+1]
        parrent = [i/2]
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
} BT;

BT *newNode(char data)
{
    BT *newNode = (BT *)malloc(sizeof(BT));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BT *createBT(char arr[], int i, int n)
{
    if (i >= n)
        return NULL;

    BT *root = newNode(arr[i]);
    root->left = createBT(arr, 2 * i + 1, n);
    root->right = createBT(arr, 2 * i + 2, n);
    return root;
}

void preOrder(BT *root)
{
    if (root == NULL)

    {
        return;
    }
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void main()
{
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    int n = sizeof(arr) / sizeof(arr[0]);
    BT *root = createBT(arr, 0, n);
    preOrder(root);
}