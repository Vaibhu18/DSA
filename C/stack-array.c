#include <stdio.h>
#define N 5
int Stack[N];
int top = -1;

void push()
{
    if (top == N - 1)
    {
        printf("Stack is full / Stack is Overflow\n");
        return;
    }
    else
    {
        int newNum;
        printf("Enter a new number : ");
        scanf("%d", &newNum);
        top++;
        Stack[top] = newNum;
        printf("New number is pushed in Stack \n");
        return;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty / Stack is Underflow\n");
        return;
    }
    else
    {
        top--;
        printf("Element is removed\n");
        return;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty / Stack is Underflow\n");
        return;
    }
    else
    {
        printf("Top element is %d\n", Stack[top]);
        return;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty / Stack is Underflow\n");
        return;
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", Stack[i]);
        }
        printf("\n");
        return;
    }
}

void main()
{

    int opt;
    do
    {
        printf("***** Enter the move ***** \n");
        printf("Enter 1 for push : \n");
        printf("Enter 2 for pop : \n");
        printf("Enter 3 for Stack Top : \n");
        printf("Enter 4 for Display : \n");
        printf("Enter 0 for Exit : \n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("Envalid move ");
            break;
        }

    } while (opt != 0);
}