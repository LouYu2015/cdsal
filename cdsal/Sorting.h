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

	//----- Declarations -----

	//Insertion Sort
	template <typename Data, typename Comparator = Descending<Data> >
	void InsertionSort(Data* first, Data* last);

	//Selection Sort
	template <typename Data, typename Comparator = Descending<Data> >
	void SelectionSort(Data* first, Data* last);

	//Bubblesort
	template <typename Data, typename Comparator = Descending<Data> >
	void Bubblesort(Data* first, Data* last);

	//Merge Sort
	template <typename Data, typename Comparator = Descending<Data> >
	void MergeSort(Data* first, Data* last);

	template <typename Data, typename Comparator = Descending<Data> >
	void MergeSortMerge(Data* Lfirst, Data* Llast, Data* Rfirst, Data* Rlast, Data* dest);//Merge [first, mid) and [mid, last), and store result in "dest"

	//Quicksort
	template <typename Data, typename Comparator = Descending<Data> >
	void Quicksort(Data* first, Data* last);

	template <typename Data, typename Comparator = Descending<Data> >
	Data* QuicksortPartition(Data* first, Data* last);//Return a pointer to "key"

	//----- Implementations -----

	template <typename Data, typename Comparator>
	void InsertionSort(Data* first, Data* last)
	{
	    Comparator less;
		Data key;
		int i, j,
			length = last - first;
		for(i = 1; i < length; i++)
		{
			key = first[i];
			for(j = i - 1; j >= 0 && less(key, first[j]);j--)
				first[j + 1] = first[j];
			first[j + 1] = key;
		}
		return;
	}

	template <typename Data, typename Comparator>
	void SelectionSort(Data* first, Data* last)
	{
		Comparator less;
		int i, j, min,
			length = last - first;
		for(i = 0; i < length - 1; i++)
		{
			min = i;
			for(j = i + 1; j < length; j++)
				if(less(first[j], first[min]))
					min = j;
			Swap(first[i], first[min]);
		}
	}

	template <typename Data, typename Comparator>
	void Bubblesort(Data* first, Data* last)
	{
	    Comparator less;
		int i, j,
			length = last - first;
		for(i = 1; i < length; i++)
			for(j = length - 1; j >= i; j--)
				if(less(first[j], first[j - 1]))
					Swap(first[j], first[j - 1]);
	}

	template <typename Data, typename Comparator>
	void MergeSort(Data* first, Data* last)
	{
		if(last - first > 1)
		{
			Data *mid = first + (last - first)/2;
			MergeSort<Data, Comparator>(first, mid);
			MergeSort<Data, Comparator>(mid, last);

			//Prepare for merging
			Data *left = new Data[mid - first],
				*right = new Data[last - mid],
				*Llast = left + (mid - first),
				*Rlast = right + (last - mid);
			Copy(first, mid, left);
			Copy(mid, last, right);

			MergeSortMerge<Data, Comparator>(left, Llast, right, Rlast, first);

			delete[] left;
			delete[] right;
		}
	}

	template <typename Data, typename Comparator>
	void MergeSortMerge(Data* Lfirst, Data* Llast, Data* Rfirst, Data* Rlast, Data* dest)
	{
	    Comparator less;
		Data *i = Lfirst,
			*j = Rfirst,
			*k = dest;
		while(i < Llast && j < Rlast)
			if(less(*j, *i))
				*k++ = *j++;
			else
				*k++ = *i++;
		k = Copy(i, Llast, k);
		Copy(j, Rlast, k);
	}

	template <typename Data, typename Comparator>
	void Quicksort(Data* first, Data* last)
	{
		if(last - first > 1)
		{
			Data *mid = QuicksortPartition<Data, Comparator>(first, last);
			Quicksort<Data, Comparator>(first, mid);
			Quicksort<Data, Comparator>(mid + 1, last);
		}
	}

	template <typename Data, typename Comparator>
	Data* QuicksortPartition(Data* first, Data* last)
	{
	    Comparator less;
		Data *key = first,
			*i, *j;

		for(i = j = first + 1; j < last; j++)
			if(less(*j, *key))
				Swap(*i++, *j);
		Swap(*key, *(i - 1));
		return i - 1;
	}
}
#endif
