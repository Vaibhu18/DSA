#include <stdio.h>

void findTwoLargestNumbers(int arr[], int n)
{
    int firstLargest = 0;
    int secondLargest = 0;

    for (int i = 0; i < n; i++)
    {
        if (firstLargest < arr[i])
        {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        }
        else if (arr[i] < firstLargest && arr[i] > secondLargest)
        {
            secondLargest = arr[i];
        }
    }
    printf("First Largest is : %d and Second Largest is : %d", firstLargest, secondLargest);
}

void main()
{
    int n = 5;
    int arr[] = {2, 4, 5, 8, 7};
    findTwoLargestNumbers(arr, n);
}