# Sorting.h
`namespace Sorting`.

This file contains all basic sorting algorithms.
If no specifically stated, all sorting functions' parameter list is `(Data* first, Data* last)`, and they will sort [`first`, `last`).

## Functions
### InsertionSort
### SelectionSort
### Bubbl Sort
### MergeSort
### MergeSortMerge
```
template <typename Data, typename Comparator>
void MergeSortMerge(Data* Lfirst, Data* Llast, Data* Rfirst, Data* Rlast, Data* dest)
```
Merge sorted array [`Lfirst`, `Llast`) and [`Rfirst`, `Rlast`), and store the result in `dest`.
### Quicksort
### QuicksortPartition
```
template <typename Data, typename Comparator>
Data* QuicksortPartition(Data* first, Data* last)
```
Do partition inplace with the first data as the key, and after partition, return a pointer to the key.
