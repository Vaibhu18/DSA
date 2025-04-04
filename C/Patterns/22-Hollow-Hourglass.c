#include <stdio.h>

void main()
{
    int n = 6;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            printf(" ");
        }

        for (int j = i; j <= n; j++)
        {
            if (j == i || j == n || i == 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = 1; j < i; j++)
        {
            printf(" ");
        }

        for (int j = i; j <= n; j++)
        {
            if (j == i || j == n || i == 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}