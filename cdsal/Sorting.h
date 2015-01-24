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
	template <class Data>
	void InsertionSort(Data* first, Data* last);

	//Selection Sort
	template <class Data>
	void SelectionSort(Data* first, Data* last);

	//Bubblesort
	template <class Data>
	void Bubblesort(Data* first, Data* last);

	//Merge Sort
	template <class Data>
	void MergeSort(Data* first, Data* last);

	template <class Data>
	void MergeSortMerge(Data* first, Data* mid, Data* last, Data* dest);//Merge [first, mid) and [mid, last), and store result in "dest"

	//Quicksort
	template <class Data>
	void Quicksort(Data* first, Data* last);

	template <class Data>
	Data* QuicksortPartition(Data* first, Data* last);//Return a pointer to "key"
}
#endif
