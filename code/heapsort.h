#ifndef _HEAPSORT_H_
#define _HEADSORT_H_

void max_heapify_(int *arr, const int size, int i);
void max_heapify_loop_(int *arr, const int size, int i);
void build_max_heap_(int *arr, const int size);

void min_heapify_(int *arr, const int size, int i);
void min_heapify_loop_(int *arr, const int size, int i);
void build_min_heap_(int *arr, const int size);

#endif
