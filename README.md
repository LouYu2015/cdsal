# Classic Data Structures and Algorithms Library

This library aims at providing programmers some useful codes of algorithms and data structures. It focuses on extensibility and readability, instead of speed, because most algorithms need extend basic algorithms.

## Basic
### Functions
* Copy
  * Copy a block to another block.
* Swap
  * Exchange two data.

### Classes
* Ascending, Descending, Maximum (=_Ascending_), Minimum (=_Descending_)
  * Those are comparators. They both have _operator ()_ to compare two data, using _operator <_ of the data.

## Sorting Algorithms
Each of the following is a function. Each of them has two template parameters, _typename Data_ and _typename Comparator_, and two parameters, _Data* first_ and _Data* last_. They will sort [first, last) using the comparator.
* Insertion Sort
* Selection Sort
* Bubble Sort
* Merge Sort(__Not inplace__)
* Quicksort
