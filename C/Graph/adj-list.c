#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct node
{
    int data;
    struct node *next;
} LL;

LL *adjList[N];

LL *newNode(int data)
{
    LL *node = (LL *)malloc(sizeof(LL));
    node->data = data;
    node->next = NULL;
    return node;
}

void main()
{
    int graph[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}};

    for (int i = 0; i < N; i++)
    {
        adjList[i] = newNode(i + 1);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] == 1)
            {
                LL *temp = adjList[i];
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode(j + 1);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (adjList[i]->next != NULL)
        {
            while (adjList[i] != NULL)
            {
                printf("%d ", adjList[i]->data);
                adjList[i] = adjList[i]->next;
            }
            printf("\n");
        }
        else
        {
            printf("%d ", adjList[i]->data);
        }
    }
}