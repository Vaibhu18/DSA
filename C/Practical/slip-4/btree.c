#include "btree.h"
#include <stdio.h>

void main()
{
    BST *root = NULL;
    int choice, n, key;
    while (1)
    {
        printf("\n\n************ Binary Search Tree ************\n");
        printf("1. Insert\n");
        printf("2. PreOrder Traversal\n");
        printf("3. Search\n");
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
            preOrder(root);
            break;
        case 3:
            printf("Enter element you want to search : ");
            scanf("%d", &key);
            if (search(root, key))
            {
                printf("Element found in the tree\n");
            }
            else
            {
                printf("Element not found in the tree\n");
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}