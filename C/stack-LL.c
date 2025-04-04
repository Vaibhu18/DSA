#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

void push(NODE **stack, int n)
{
    // printf("\nEnter new element : ");
    // int n;
    // scanf("%d", &n);
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = n;
    newNode->next = *stack;
    *stack = newNode;
    printf("\nNew element is inserted : %d", n);
}

void pop(NODE **stack)
{
    if (*stack == NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nPopped Element is : %d", (*stack)->data);
        *stack = (*stack)->next;
    }
}

void peek(NODE *stack)
{
    if (stack == NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nTop element is : %d", stack->data);
    }
}

void display(NODE *stack)
{
    printf("\nStack Elements : ");
    while (stack != NULL)
    {
        printf("%d ", stack->data);
        stack = stack->next;
    }
}

void main()
{
    NODE *top = NULL;

    int opt = 0;
    do
    {
        printf("\n1. Push\n2. Pop\n3. Top\n4. Display\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            for (int i = 0; i < 5; i++)
            {
                push(&top, 10 * (i + 1));
            }
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            peek(top);
            break;
        case 4:
            display(top);
            break;
        case 0:
            printf("Exit");
            break;
        default:
            printf("Invalid Option");
        }
    } while (opt != 0);
}