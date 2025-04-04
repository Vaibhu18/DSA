#include <stdio.h>

typedef struct
{
    int start, end;
    int arr[100];
} Q;

void initQ(Q *queue)
{
    queue->start = -1;
    queue->end = -1;
}

int isEmpty(Q *queue)
{
    if (queue->start > queue->end)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQ(Q *queue, int data)
{
    if (queue->start == -1)
    {
        queue->start = 0;
    }
    queue->end++;
    queue->arr[queue->end] = data;
}

int deQ(Q *queue)
{
    int data = queue->arr[queue->start];
    queue->start++;
    return data;
}

void main()
{
    Q queue;
    initQ(&queue);
    int arr[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    int graph[4][4] = {
        {0, 1, 0, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 0},
        {1, 1, 1, 0}};
    int src = 0;
    int visited[4] = {0};

    printf("%d ", src);
    visited[src] = 1;
    enQ(&queue, src);

    while (!isEmpty(&queue))
    {
        int peek = deQ(&queue);
        for (int i = 0; i < 4; i++)
        {
            if (graph[peek][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                enQ(&queue, i);
                printf("%d ", i);
            }
        }
    }
}