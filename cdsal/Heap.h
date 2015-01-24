//This file is a part of CDSAL
//Author:		Lou Yu
//Commentary:	This file contains a  minimum heap structure

#ifndef HEAP_H_COMPILED
#define HEAP_H_COMPILED

#include "DABasic.h"

namespace Structure
{
	using namespace DABasic;
	
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

		inline swapElement(Index a, Index b){Swap(data[a], data[b]);}

	public:
		Heap();
		Heap(Data* initData, int memSize, int size);
		~Heap();

		void insert(Data& x);
		Data extractTop();

		Data* top(){if(data != NULL)return &data[0]; else return NULL;}
		unsigned size(){return size;}
		unsigned totalSize(){return totalSize;}
	};

	template <class Data>
	class Heap: public InplaceHeap<Data>
	{
	public:
		Heap(Data* initData, int memSize, int size);
		~Heap();

		void insert(Data& x);
		Data extractTop();

		bool resetSize(unsigned newSize);
	};

	template <class Data>
	class RefHeap: Heap<Data>
	{
	private:
		Data** refToData;//refToData[i] points to what index i refers to
		Index* index;//index[i] stores the index of data[i]

		inline swapElement(Index a, Index b)
		/*{
			Heap::swapElement(a, b);
			Swap(index[a], index[b])
			refToData[index[a]] = &data[a];
			refToData[index[b]] = &data[b];
		}*/
	public:
		Heap();
		Heap(Data* initData, int memSize, int size);
		~Heap();

		Index insert(Data& x);
		bool decreaseKey(Index x);
		bool deleteKey(Index x);

		Data* GetData(Index x){if(indexCheck(x)) reuturn refToData[x]; else return NULL;}

		bool resetSize(unsigned newSize);
	};
}

#endif