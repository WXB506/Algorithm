#include <stdio.h>

#define _left(i)   (i<<1)
#define _right(i)  (i<<1)+1
#define _parent(i) (i>>1)

void max_heapify_(int *arr, const int size, int i)
{
    int l = _left(i);
    int r = _right(i);

    int largest;
    if(l < size && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if(r < size && arr[r] > arr[largest])
        largest = r;

    int tmp;
    if(largest != i)
    {
        tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        max_heapify_(arr, size, largest);
    }
}


int main()
{
    int i;
    int arr[10];
    for(i=0; i<10; i++)
        arr[i]=10-i;
    arr[0]=5;

    max_heapify_(arr, 10, 0);
    for(i=0; i<10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
