#include <stdio.h>

char inc(int a, int b)
{
    return a<b;
}
char dec(int a, int b)
{
    return a>b;
}

int partition_(int *arr, int s, int e, char (*cmp)(int , int))
{
    int x;
    int i, j, t;

    i = s - 1;
    x = arr[e];
    for(j=s; j<e; j++)
    {
        if(arr[j]<=x)
        {
            i = i+1;

            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    arr[e] = arr[i+1];
    arr[i+1] = x;

    return i+1;
}

void quicksort_(int *arr, int s, int e)
{
    int q;
    if(s<e)
    {
        q = partition_(arr, s, e, inc);
        quicksort_(arr, s, q);
        quicksort_(arr, q+1, e);
    }
}

int main()
{
    int i;
    int a[10] = {4,7,2,86,456,35,743,732,46,76};
    quicksort_(a, 0, 10);
    for(i=0; i<10; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}

















