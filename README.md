# Classic Data Structures and Algorithms Library

This library aims at providing programmers some useful codes of algorithms and data structures. It focuses on extensibility and readability, rather than speed, because most algorithms need extend basic algorithms.

The following is a list of all classes and functions.

## Basic
In [DABasic.h](https://github.com/LouYu2015/cdsal/blob/master/cdsal/DABasic.h),`namespace DABasic`.[more](https://github.com/LouYu2015/cdsal/blob/master/DABasic.md)

### Types
* Index

### Functions
* Copy
* Swap

### Classes
* Ascending, Descending, Maximum (=`Ascending`), Minimum (=`Descending`)
  * operator <

## Exception
In [DAException.h](https://github.com/LouYu2015/cdsal/blob/master/cdsal/DAException.h),`namespace DAException`.[more](https://github.com/LouYu2015/cdsal/blob/master/DAException.md)

### Types
* DASenderId
* DAErrorId

### Classes
* DAError
  * ErrorInfo
  * SenderInfo

## Sorting Algorithms
In [Sorting.h](https://github.com/LouYu2015/cdsal/blob/master/cdsal/Sorting.h),`namespace Sorting`.[more](https://github.com/LouYu2015/cdsal/blob/master/Sorting.md)

### Functions
* InsertionSort
* SelectionSort
* Bubbl Sort
* MergeSort(**Not inplace**)
  * MergeSortMerge
* Quicksort
  * QuicksortPartition

## Heap
In [Heap.h](https://github.com/LouYu2015/cdsal/blob/master/cdsal/Heap.h),`namespace Structure`.

### Classes
* InplaceHeap
  * Insert
  * ExtractTop
  * ResetSize
* Heap
  * (extended from `InplaceHeap`)
* RefHeap
  * (extended from `Heap`)
  * DecreaseKey
  * Remove
  * GetData
