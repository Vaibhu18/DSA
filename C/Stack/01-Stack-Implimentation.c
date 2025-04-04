#include <stdio.h>

typedef struct
{
    int arr[5];
    int top;
} STACK;

void initializeStack(STACK *stack)
{
    stack->top = -1;
}

int isStackEmpty(STACK *stack)
{
    return stack->top == -1;
}

int isStackFull(STACK *stack)
{
    return stack->top == (sizeof(stack->arr) / sizeof(stack->arr[0]) - 1);
}

void insertElement(STACK *stack, int data)
{
    if (!isStackFull(stack))
    {
        stack->top = stack->top + 1;
        stack->arr[stack->top] = data;
    }
    else
    {
        printf("Stack is full\n");
        return;
    }
}

int deleteElement(STACK *stack)
{
    if (!isStackEmpty(stack))
    {
        int data = stack->arr[stack->top];
        stack->top = stack->top - 1;
        return data;
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

void displayStack(STACK *stack)
{
    if (!isStackEmpty(stack))
    {

        for (int i = 0; i <= stack->top; i++)
        {
            printf("%d ", stack->arr[i]);
        }
    }
    else
    {
        printf("Stack is empty\n");
        return;
    }
}

void main()
{
    STACK stack;
    initializeStack(&stack);
    for (int i = 0; i < 5; i++)
    {
        // insertElement(&stack, (i + 1) * 10);
    }
    displayStack(&stack);
    printf("\nDeleted element is : %d\n", deleteElement(&stack));
    displayStack(&stack);
}