#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} BST;

typedef struct queue
{
    BST *node;
    struct queue *next;
} QUE;

BST *newNode(int data)
{
    BST *node = (BST *)malloc(sizeof(BST));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

BST *insert(BST *root, int data)
{
    if (root == NULL)
    {
        return root = newNode(data);
    }
    if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    else if (root->data > data)
    {
        root->left = insert(root->left, data);
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

int nodesAtLevel(BST *root, int level)
{
    if (root == NULL)
        return 0;
    if (level == 0)
        return 1;
    return nodesAtLevel(root->left, level - 1) + nodesAtLevel(root->right, level - 1);
}

void main()
{
    BST *root = NULL;
    QUE *front = NULL;
    // int n;
    // printf("Enter the number of nodes: ");
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {
    //     int data;
    //     printf("Enter the data: ");
    //     scanf("%d", &data);
    //     root = insert(root, data);
    // }
    root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->left = newNode(14);
    root->right->right = newNode(16);
    preOrder(root);
    // printf("\nNodes at level %d : %d", 1, nodesAtLevel(root, 1));
    front = (QUE *)malloc(sizeof(QUE));
    front->node = root;
    front->next = NULL;
    front->next = (QUE *)malloc(sizeof(QUE));
    front->next->node = root->left;
    front->next->next = NULL;
    printf("\n");
    printf("%d", front->next->node->right->data);
}