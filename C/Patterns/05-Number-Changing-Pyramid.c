#include <stdio.h>

void main()
{
    int n;
    printf("Enter the size : ");
    scanf("%d", &n);
    int num = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", num++);
        }
        printf("\n");
    }
}