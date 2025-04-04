#include <stdio.h>

void usingLoops(int arr[], int n)
{
    int largestElement = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= largestElement)
        {
            largestElement = arr[i];
        }
    }
    printf("LE using loop : %d\n", largestElement);
}

int usingRecursion(int arr[], int start, int len, int largestElement)
{
    if (largestElement < arr[start])
    {
        largestElement = arr[start];
    }
    if (start == len - 1)
    {
        return largestElement;
    }
    return usingRecursion(arr, start + 1, len, largestElement);
}

void usingPointer(int arr[], int n, int *largestElement)
{
    for (int i = 0; i < n; i++)
    {
        if (*largestElement <= arr[i])
        {
            *largestElement = arr[i];
        }
    }
}
void main()
{
    int n = 6;
    int arr[] = {1, 2, 4, 1, 6, 14};
    usingLoops(arr, n);
    printf("LE using Recursion : %d\n", usingRecursion(arr, 0, n, 0));
    int largestElement = 0;
    usingPointer(arr, n, &largestElement);
    printf("LE using Pointer : %d", largestElement);
}