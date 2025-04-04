#include "btree.h"

void main()
{
    BST *root = NULL;
    int choice, n;
    while (1)
    {
        printf("\n\n************ Binary Search Tree ************\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
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
                root = insert(root, data);
            }
            break;
        case 2:
            inorderTraversal(root);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}