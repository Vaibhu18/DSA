#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} TREE;

TREE *newNode(int data)
{
    TREE *node = (TREE *)malloc(sizeof(TREE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TREE *createTree()
{

    int data;
    printf("\nEnter data (-1 for no data): ");
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    TREE *root = newNode(data);
    printf("\nEnter data for left of %d : ", root->data);
    root->left = createTree();
    printf("\nEnter data for right of %d : ", root->data);
    root->right = createTree();
    return root;
}

void display(TREE *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    display(root->left);
    display(root->right);
}
void main()
{
    TREE *root = NULL;
    int option;
    do
    {
        printf("\n\n1. Create Tree");
        printf("\n2. Display");
        printf("\n3. Exist");
        printf("\nEnter your choice : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            root = createTree();
            break;
        case 2:
            display(root);
            break;
        }

    } while (option != 0);
}