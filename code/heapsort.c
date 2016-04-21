#include <stdio.h>
#include "heapsort.h"


#define _left(i)   (i<<1)
#define _right(i)  (i<<1)+1
#define _parent(i) (i>>1)

// max-heap
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
void max_heapify_loop_(int *arr, const int size, int i)
{
    char flag;
    int l, r, largest;

    flag = 1;
    while(flag == 1)
    {
        l = _left(i);
        r = _right(i);

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
            arr[largest] = arr[i];
            i = largest;    // update index of new tree
        }
        else
            flag = 0;
    }
}
void build_max_heap_(int *arr, const int size)
{
    int root;
    root = (size>>1)-1;

    int i;
    for(i=root; i>=0; i--)
        max_heapify_(arr, size, i);
}

// min-heap
void min_heapify_(int *arr, const int size, int i)
{
    int l = _left(i);
    int r = _right(i);

    int smallest;
    if(l < size && arr[l] < arr[i])
        smallest = l;
    else
        smallest = i;

    if(r < size && arr[r] < arr[smallest])
        smallest = r;

    int tmp;
    if(smallest != i)
    {
        tmp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = tmp;
        min_heapify_(arr, size, smallest);
    }
}
void min_heapify_loop_(int *arr, const int size, int i)
{
    char flag;
    int l, r, smallest;

    flag = 1;
    while(flag == 1)
    {
        l = _left(i);
        r = _right(i);

        if(l < size && arr[l] < arr[i])
            smallest = l;
        else
            smallest = i;

        if(r < size && arr[r] < arr[smallest])
            smallest = r;

        int tmp;
        if(smallest != i)
        {
            tmp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = tmp;
            i = smallest;
        }
        else
            flag = 0;
    }
}
void build_min_heap_(int *arr, const int size)
{
    int root;
    root = (size>>1)-1;

    int i;
    for(i=root; i>=0; i--)
        min_heapify_(arr, size, i);
}


int main()
{
    int i;
    int arr[10] = {23,17,14,6,12,20,40,50,22,20};

    build_max_heap_(arr, 10);
    for(i=0; i<10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
