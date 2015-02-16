# Classic Data Structures and Algorithms Library
**This project need c++11**

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
* DAError: Store information of an error
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
In [Heap.h](https://github.com/LouYu2015/cdsal/blob/master/cdsal/Heap.h),`namespace Structure`, [more](https://github.com/LouYu2015/cdsal/blob/master/Heap.md).

### Classes
* HeapBasic
  * Top
  * Size
  * TotalSize
* InplaceHeap: Build a heap inplace
  * (extended from `HeapBasic`)
  * Insert
  * ExtractTop
  * ResetSize
* Heap: Build a auto-resizing non-inplace heap
  * (extended from `InplaceHeap`)
* RefHeap: Build a auto-resizing non-inplace heap which you can keep references
  * (extended from `Heap`)
  * Replace
  * Remove
  * GetData
