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

BST *createBST(BST *root, int data)
{

    if (root == NULL)
    {
        root = newNode(data);
    }
    else
    {
        if (data < root->data)
            root->left = createBST(root->left, data);
        else if (data > root->data)
            root->right = createBST(root->right, data);
    }
    return root;
}

void displayBST(BST *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    displayBST(root->left);
    displayBST(root->right);
}
void main()
{
    BST *root = NULL;
    int option;
    int n;
    int data;
    do
    {
        printf("\n\n1. Create or Insert node");
        printf("\n2. Display");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the number of nodes you want to insert: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("\nEnter data for new node : ");
                scanf("%d", &data);
                root = createBST(root, data);
            }
            break;
        case 2:
            displayBST(root);
            break;
        }

    } while (option != 0);
}