//This file is a part of CDSAL
//Author:		Lou Yu
//Commentary:	This file contains implementation of "Sorting.h"

namespace Sorting
{
	template <class Data>
	void InsertionSort(Data* first, Data* last)
	{
		Data key;
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

	template <class Data>
	void SelectionSort(Data* first, Data* last)
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

	template <class Data>
	void Bubblesort(Data* first, Data* last)
	{
		int i, j,
			length = last - first;
		for(i = 1; i < length; i++)
			for(j = length - 1; j >= i; j--)
				if(first[j] < first[j - 1])
					Swap(first[j], first[j - 1]);
	}

	template <class Data>
	void MergeSort(Data* first, Data* last)
	{
		Data *i, *j, *k;
		if(last - first > 1)
		{
			Data *mid = first + (last - first)/2;
			MergeSort(first, mid);
			MergeSort(mid, last);
		
			//Prepare for merging
			Data *left = new Data[mid - first],
				*right = new Data[last - mid],
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

	template <class Data>
	void MergeSortMerge(Data* Lfirst, Data* Llast, Data* Rfirst, Data* Rlast, Data* dest)
	{
		Data* i = Lfirst,
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

	template <class Data>
	void Quicksort(Data* first, Data* last)
	{
		if(last - first > 1)
		{
			Data *mid = QuicksortPartition(first, last);
			Quicksort(first, mid);
			Quicksort(mid + 1, last);
		}
	}

	template <class Data>
	Data* QuicksortPartition(Data* first, Data* last)
	{
		Data *key = first,
			*i, *j;

		for(i = j = first + 1; j < last; j++)
			if(*j < *key)
				Swap(*i++, *j);
		Swap(*key, *(i - 1));
		return i - 1;
	}
}