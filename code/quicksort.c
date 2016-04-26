#include <stdio.h>

void partition_(int *arr, int p, int r)
{
    int tmp, j;
    int x = arr[r];
    int i = p - 1;

    for(j = p; j < r-1; j++)
    {
        if(arr[j] <= x)
        {
            i = i+1;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    tmp = arr[i+1];
    arr[i+1] = arr[j];
    arr[j] = tmp;

    return i+1;
}
