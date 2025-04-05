#include "btree.h"
#include <stdio.h>

void main()
{
    BST *root = NULL;
    int choice, n;
    while (1)
    {
        printf("\n\n1. Insert\n2. Inorder\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                int data;
                printf("Enter data for node %d: ", i + 1);
                scanf("%d", &data);
                root = insert(root, data);
            }
            break;
        case 2:
            inorder(root);
            break;
        }
    }
}