#include <stdio.h>

void main()
{
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    int adjMatrix[vertices][edges];
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            printf("Enter the value for edge (%d, %d): ", i, j);
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("The adjacency matrix is:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}