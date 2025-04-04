#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *insertNode(NODE *root, int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
        return root;
    }

    if (root->data < data)
    {
        root->right = insertNode(root->right, data);
    }
    else if (root->data > data)
    {
        root->left = insertNode(root->left, data);
    }
    return root;
}

void inorderTraversal(NODE *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(NODE *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(NODE *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void main()
{
    NODE *root = NULL;
    int choice, n;
    while (1)
    {
        printf("\n\n************ Binary Search Tree ************\n");
        printf("1. Insert\n");
        printf("2. Serach\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("How much node you want to insert : ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                int data;
                printf("Enter data for %d node : ", i + 1);
                scanf("%d", &data);
                root = insertNode(root, data);
            }
            break;
        case 2:
            printf("Search");
            break;
        case 3:
            inorderTraversal(root);
            break;
        case 4:
            preorderTraversal(root);
            break;
        case 5:
            postorderTraversal(root);
            break;
        case 6:
            printf("Exit");
            break;
        }
    }
}