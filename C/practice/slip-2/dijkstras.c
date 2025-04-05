#include <stdio.h>
#define INF 999

int cost[6][6] = {
    {0, 2, 4, INF, INF, INF},
    {INF, 0, 1, 7, INF, INF},
    {INF, INF, 0, INF, 3, INF},
    {INF, INF, INF, 0, INF, 1},
    {INF, INF, INF, 2, 0, 5},
    {INF, INF, INF, INF, INF, 0}};

void dijk(int src, int n)
{
    int dist[n];
    int visited[6] = {0};

    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[src][i];
    }
    visited[src] = 1;
    int count = 1;

    while (count < n)
    {
        int min = INF, u = -1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }
        visited[u] = 1;
        for (int i = 0; i < n; i++)
        {
            if (dist[u] + cost[u][i] < dist[i])
            {
                dist[i] = dist[u] + cost[u][i];
            }
        }
        count++;
    }
    printf("\nShortest distances from vertex %d:\n", src);
    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d: %d\n", i, dist[i]);
    }
}

void main()
{
    dijk(0, 6);
}