#include <stdio.h>
int facto(int arr[], int start, int len, int sum)
{
    sum += arr[start];
    if (start == len - 1)
    {
        return sum;
    }
    return facto(arr, start + 1, len, sum);
}
void main()
{
    int num = 5;
    int arr[] = {1, 2, 3, 4, 5};
    printf("Factorial of 5 is : %d", facto(arr, 0, 5, 0));
}