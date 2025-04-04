#include <stdio.h>
#define MAX_SIZE 5

typedef struct
{
    int first;
    int last;
    int arr[MAX_SIZE];
} Queue;

int isQueueFull(Queue *queue)
{
    return queue->last == MAX_SIZE - 1;
}

int isQueueEmpty(Queue *queue)
{
    return queue->first == -1 || queue->first > queue->last;
}

void initializeQueue(Queue *queue)
{
    queue->first = -1;
    queue->last = -1;
}

void insertElement(Queue *queue, int data)
{
    if (!isQueueFull(queue))
    {
        if (queue->last == -1 && queue->first == -1)
        {
            queue->first = 0;
        }

        queue->last = queue->last + 1;
        queue->arr[queue->last] = data;
    }
    else
    {
        printf("Queue is full\n");
        return;
    }
}

void displayQueue(Queue *queue)
{
    if (!isQueueEmpty(queue))
    {
        for (int i = queue->first; i <= queue->last; i++)
        {
            printf("%d ", queue->arr[i]);
        }
    }
    else
    {
        printf("Queue is empty\n");
        return;
    }
}

void queuePeek(Queue *queue)
{
    if (!isQueueEmpty(queue))
    {
        printf("Peek: %d\n", queue->arr[queue->first]);
    }
    else
    {
        printf("Queue is empty\n");
        return;
    }
}

void deleteElement(Queue *queue)
{
    if (!isQueueEmpty(queue))
    {
        printf("\nDeleted Element : %d\n", queue->arr[queue->first]);
        queue->first = queue->first + 1;
    }
    else
    {
        printf("Queue is empty\n");
        return;
    }
}

void main()
{
    Queue queue;
    initializeQueue(&queue);
    for (int i = 1; i <= 5; i++)
    {
        insertElement(&queue, i * 10);
    }
    displayQueue(&queue);
    deleteElement(&queue);
    displayQueue(&queue);
    // queuePeek(&queue);
    // Enqueue
    // Dequeue
    // Peek
    // IsFull
    // IsEmpty
}