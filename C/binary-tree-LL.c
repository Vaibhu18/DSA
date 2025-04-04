#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} BT;

BT *createBT()
{
    BT *newNode = (BT *)malloc(sizeof(BT));
    printf("Enter data (-1 for no node): ");
    int data;
    scanf("%d", &data);
    if (data == -1)
        return NULL;

    newNode->data = data;
    printf("Enter data for left of %d : ", data);
    newNode->left = createBT();
    printf("Enter data for right of %d : ", data);
    newNode->right = createBT();
    return newNode;
}

void display(BT *tree)
{
    if (tree == NULL)
        return;

    printf("%d ", tree->data);
    display(tree->left);
    display(tree->right);
}
void main()
{
    BT *root = NULL;
    root = createBT();
    display(root);
}