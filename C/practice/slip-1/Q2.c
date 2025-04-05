#include <stdio.h>

void main()
{
    int graph[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nAdjecency Matrix : \n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nIndegree : \n");
    for (int i = 0; i < 6; i++)
    {
        int count = 0;
        for (int j = 0; j < 6; j++)
        {
            if (graph[j][i] == 1)
            {
                count++;
            }
        }
        printf("Indegree of %d: %d\n", i + 1, count);
    }
}

// {0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0}