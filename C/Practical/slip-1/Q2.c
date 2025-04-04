#include <stdio.h>
void main()
{
    int arr[6][6] = {{0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 1, 0}, {0, 0, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0}};
    int n = 6;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] == 1)
            {
                count++;
            }
        }
        printf("\n%d -> %d\n", i + 1, count);
    }
}