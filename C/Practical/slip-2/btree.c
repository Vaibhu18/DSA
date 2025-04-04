#include "btree.h"
#include <stdio.h>

void main()
{
    BST *root = NULL;
    int choice, n;
    while (1)
    {
        printf("\n\n************ Binary Search Tree ************\n");
        printf("1. Create\n");
        printf("2. Preorder Traversal\n");
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
                root = create(root, data);
            }
            break;
        case 2:
            preorderTraversal(root);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}