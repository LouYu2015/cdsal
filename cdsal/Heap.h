//This file is a part of CDSAL
//Author:		Lou Yu
//Commentary:	This file contains a  minimum heap structure

#ifndef HEAP_H_COMPILED
#define HEAP_H_COMPILED

#include "DABasic.h"
#include "DAException.h"

namespace Structure
{
	using namespace DABasic;
	using namespace DAException;

	//----- Declarations -----

	//Commonly used heap. It will automatically adjust its size.
	template <typename Data, typename Comparator = Minimum>
	class Heap;

	//Just take over part of the memory. Generally used for heap sort.
	template <typename Data, typename Comparator = Minimum>
	class InplaceHeap;

	//When you use it, you can refer to its elements by keep a "Index".
	//Note: After extracted the top element, the index of it will be used for other element!
	template <typename Data, typename Comparator = Minimum>
	class RefHeap;

	template <typename Data, typename Comparator = Minimum>
	class InplaceHeap
	{
	private:
	    Comparator less;
		Data* data;
		unsigned totalSize,//Total space of "data"
			size;//The space occupied

		void initHeap();
		void heapify(Index x);

		inline Index parent(Index x){return x/2;}
		inline Index left(Index x){return x*2;}
		inline Index right(Index x){return x*2 + 1;}

		inline bool indexCheck(Index x){return Index >= 0 && Index < size;}

		inline void swapElement(Index a, Index b){Swap(data[a], data[b]);}

	public:
		InplaceHeap();
		InplaceHeap(Data* initData, int memSize, int size);
		~InplaceHeap();

		void Insert(Data& x);
		Data ExtractTop();

		Data* Top(){if(data != NULL)return &data[0]; else return NULL;}
		unsigned Size(){return size;}
		unsigned TotalSize(){return totalSize;}
	};

	template <typename Data, typename Comparator = Minimum>
	class Heap: public InplaceHeap<Data, Comparator>
	{
	public:
		Heap();
		Heap(Data* initData, int memSize, int size);
		~Heap();

		void Insert(Data& x);
		Data ExtractTop();

		bool ResetSize(unsigned newSize);
	};

	template <typename Data, typename Comparator = Minimum>
	class RefHeap: Heap<Data, Comparator>
	{
	private:
		Data** refToData;//refToData[i] points to what index i refers to
		Index* index;//index[i] stores the index of data[i]

		inline void swapElement(Index a, Index b);
	public:
		RefHeap();
		RefHeap(Data* initData, int memSize, int size);
		~RefHeap();

		Index Insert(Data& x);
		bool DecreaseKey(Index x);
		bool DeleteKey(Index x);

		Data* GetData(Index x){if(indexCheck(x)) reuturn refToData[x]; else return NULL;}

		bool ResetSize(unsigned newSize);
	};

	//----- Implementations -----


}

#endif
