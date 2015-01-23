//This file is a part of CDSAL
//Author:		Lou Yu
//Commentary:	This file contains implementation of "Sorting.h"

namespace Sorting
{
	template <class T>
	void InsertionSort(T* first, T* last)
	{
		T key;
		int i, j,
			length = last - first;
		for(i = 1; i < length; i++)
		{
			key = first[i];
			for(j = i - 1; j >= 0 && key < first[j]; j--)
				first[j + 1] = first[j];
			first[j + 1] = key;
		}
		return;
	}

	template <class T>
	void SelectionSort(T* first, T* last)
	{
		int i, j, min,
			length = last - first;
		for(i = 0; i < length - 1; i++)
		{
			min = i;
			for(j = i + 1; j < length; j++)
				if(first[j] < first[min])
					min = j;
			Swap(first[i], first[min]);
		}
	}

	template <class T>
	void Bubblesort(T* first, T* last)
	{
		int i, j,
			length = last - first;
		for(i = 1; i < length; i++)
			for(j = length - 1; j >= i; j--)
				if(first[j] < first[j - 1])
					Swap(first[j], first[j - 1]);
	}

	template <class T>
	void MergeSort(T* first, T* last)
	{
		T *i, *j, *k;
		if(last - first > 1)
		{
			T *mid = first + (last - first)/2;
			MergeSort(first, mid);
			MergeSort(mid, last);
		
			//Prepare for merging
			T *left = new T[mid - first],
				*right = new T[last - mid],
				*Llast = left + (mid - first),
				*Rlast = right + (last - mid);
			i = left;
			j = right;
			k = first;
			while(i < Llast)
				*i++ = *k++;
			while(j < Rlast)
				 *j++ = *k++;

			MergeSortMerge(left, Llast, right, Rlast, first);

			delete[] left;
			delete[] right;
		}
	}

	template <class T>
	void MergeSortMerge(T* Lfirst, T* Llast, T* Rfirst, T* Rlast, T* dest)
	{
		T* i = Lfirst,
			*j = Rfirst,
			*k = dest;
		while(i < Llast && j < Rlast)
			if(*j < *i)
				*k++ = *j++;
			else
				*k++ = *i++;
		while(i < Llast)
			*k++ = *i++;
		while(j < Rlast)
			*k++ = *j++;
	}

	template <class T>
	void Quicksort(T* first, T* last)
	{
		if(last - first > 1)
		{
			T *mid = QuicksortPartition(first, last);
			Quicksort(first, mid);
			Quicksort(mid + 1, last);
		}
	}

	template <class T>
	T* QuicksortPartition(T* first, T* last)
	{
		T *key = first,
			*i, *j;

		for(i = j = first + 1; j < last; j++)
			if(*j < *key)
				Swap(*i++, *j);
		Swap(*key, *(i - 1));
		return i - 1;
	}
}