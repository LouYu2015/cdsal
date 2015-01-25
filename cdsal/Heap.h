//This file is a part of CDSAL
//Author:		Lou Yu
//Commentary:	This file contains a  minimum heap structure

#ifndef HEAP_H_COMPILED
#define HEAP_H_COMPILED

#include "DABasic.h"

namespace Structure
{
	using namespace DABasic;

	//----- Declarations -----
	
	//Commonly used heap. It will automatically adjust its size.
	template <class Data>
	class Heap;

	//Just take over part of the memory. Generally used for heap sort.
	template <class Data>
	class InplaceHeap;

	//When you use it, you can refer to its elements by keep a "Index".
	//Note: After extracted the top element, the index of it will be used for other element!
	template <class Data>
	class RefHeap;
	
	template <class Data>
	class InplaceHeap
	{
	private:
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

	template <class Data>
	class Heap: public InplaceHeap<Data>
	{
	public:
		Heap();
		Heap(Data* initData, int memSize, int size);
		~Heap();

		void Insert(Data& x);
		Data ExtractTop();

		bool ResetSize(unsigned newSize);
	};

	template <class Data>
	class RefHeap: Heap<Data>
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