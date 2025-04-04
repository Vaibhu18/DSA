#include <stdio.h>

void main()
{
    int n;
    printf("Enter the size : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int j = n - i; j < n; j++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
}