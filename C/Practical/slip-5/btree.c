#include "btree.h"
#include <stdio.h>

void main()
{
    BST *root = NULL;
    int choice, n;
    while (1)
    {
        printf("\n\n************ Binary Search Tree ************\n");
        printf("1. Insert\n");
        printf("2. PostOrder Traversal\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to be inserted : \n");
            scanf("%d", &n);
            root = insert(root, n);
            break;
        case 2:
            printf("PostOrder Traversal of the tree is : \n");
            postOrder(root);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}