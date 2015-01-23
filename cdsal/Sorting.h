//This file is a part of CDSAL
//Author:		Lou Yu
//Commentary:	This file contains all sorting algorithms of CDSAL
//				If not special specified, all following functions will sort [first, last)

#ifndef SORTING_H_COMPILED
#define SORTING_H_COMPILED

#include "DABasic.h"

namespace Sorting
{
	using namespace DABasic;
	//-----Simple Sorting Algorithms-----

	//Insertion Sort
	template <class T>
	void InsertionSort(T* first, T* last);

	//Selection Sort
	template <class T>
	void SelectionSort(T* first, T* last);

	//Bubblesort
	template <class T>
	void Bubblesort(T* first, T* last);

	//Merge Sort
	template <class T>
	void MergeSort(T* first, T* last);

	template <class T>
	void MergeSortMerge(T* first, T* mid, T* last, T* dest);//Merge [first, mid) and [mid, last), and store result in "dest"

	//Quicksort
	template <class T>
	void Quicksort(T* first, T* last);

	template <class T>
	T* QuicksortPartition(T* first, T* last);//Return a pointer to "key"
}
#endif
