# Classic Data Structures and Algorithms Library

This library aims at providing programmers some useful codes of algorithms and data structures. It focuses on extensibility and readability, instead of speed, because most algorithms need extend basic algorithms.

## Basic
### Functions
* Copy
Copy a block to another block.
* Swap
Exchange two data.
### Classes
* Ascending, Descending, Maximum (=*Ascending*), Minimum (=*Descending*)
Those are comparators. They both have *operator ()* to compare two data, using *operator <* of the data.

## Sorting Algorithms
Each of the following is a function. Each of them has two template parameters, *typename Data* and *typename Comparator*, and two parameters, *`Data* first`* and *`Data* last`*. They will sort [first, last) using the comparator.
* Insertion Sort
* Selection Sort
* Bubble Sort
* Merge Sort(**Not inplace**)
* Quicksort
