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

void print(BST *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    print(root->left);
    print(root->right);
}

int search(BST *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return 1;
        }
        if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return 0;
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

int TN = 0;
int LN = 0;
int NLN = 0;

int totalNodes(BST *root)
{
    if (root != NULL)
    {
        TN++;
        totalNodes(root->left);
        totalNodes(root->right);
    }
    return TN;
}

int leafNodes(BST *root)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            LN++;
        }
        leafNodes(root->left);
        leafNodes(root->right);
    }
    return LN;
}

int nonLeafNodes(BST *root)
{
    if (root != NULL)
    {
        if (root->left != NULL && root->right != NULL)
        {
            NLN++;
        }
        nonLeafNodes(root->left);
        nonLeafNodes(root->right);
    }
    return NLN;
}

BST *copyBST(BST *bst1, BST *bst2)
{
    if (bst1 != NULL)
    {
        bst2 = insert(bst2, bst1->data);
        copyBST(bst1->left, bst2);
        copyBST(bst1->right, bst2);
    }
    return bst2;
}

int result = 1;
int compareBST(BST *bst1, BST *bst2)
{
    if (bst1 != NULL && bst2 != NULL)
    {
        if (bst1->data != bst2->data)
        {
            result = 0;
        }
        compareBST(bst1->left, bst2->left);
        compareBST(bst1->right, bst2->right);
    }
    else if (bst1 != NULL && bst2 == NULL)
    {
        return result = 0;
    }
    else if (bst1 == NULL && bst2 != NULL)
    {
        return result = 0;
    }
    return result;
}

void main()
{
    BST *bst1 = NULL;
    BST *bst2 = NULL;
    // int n;
    // printf("Enter the number of nodes : ");
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {
    //     int data;
    //     printf("Enter the data : ");
    //     scanf("%d", &data);
    //     bst1 = insert(bst1, data);
    // }
    bst1 = newNode(10);
    bst1->left = newNode(5);
    bst1->right = newNode(15);
    bst1->left->left = newNode(4);
    bst1->left->right = newNode(6);
    bst1->right->left = newNode(14);
    bst1->right->right = newNode(16);
    print(bst1);
    bst2 = copyBST(bst1, bst2);
    printf("\nCoppied BST : ");
    bst2->left->left->left = newNode(1);
    print(bst2);
    // printf("%d ", search(bst1, 15));
    // printf("\n Total Nodes : %d ", totalNodes(bst1));
    // printf("\n Leaf Nodes : %d ", leafNodes(bst1));
    // printf("\n Non Leaf Nodes : %d ", nonLeafNodes(bst1));
    printf("\n Compare 2 BST's : %d ", compareBST(bst1, bst2));
}