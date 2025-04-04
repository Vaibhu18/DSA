#include <stdio.h>
#include <limits.h>

void secondLargestAndSmallest(int arr[], int n)
{
    int firstLargest = INT_MIN;
    int secondLargest = INT_MIN;
    int firstSmallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > firstLargest)
        {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        }
        else if (arr[i] < firstLargest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }

        if (arr[i] < firstSmallest)
        {
            secondSmallest = firstSmallest;
            firstSmallest = arr[i];
        }
    }
    printf("Second Largest : %d and Second Smallest: %d", secondLargest, secondSmallest);
}

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Second Largest : %d and Second Smallest: %d", arr[1], arr[n - 2]);
}

void main()
{
    int arr[] = {450, 340, 120, 670, 475};
    int n = sizeof(arr) / sizeof(arr[0]);
    // secondLargestAndSmallest(arr, n);
    sort(arr, n);
}