#include <stdio.h>

int arr[5][5] = {{0, 0, 1, 1, 0},
                 {0, 0, 1, 0, 1},
                 {0, 1, 0, 0, 0},
                 {0, 0, 0, 0, 1},
                 {0, 0, 0, 0, 0}};
int n = 5;
int visited[5] = {0};

void dfs(int src)
{
    visited[src] = 1;
    printf("v%d ", src + 1);
    for (int i = 0; i < n; i++)
    {
        if (arr[src][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

void main()
{
    dfs(0);
}