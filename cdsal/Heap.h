//This file is a part of CDSAL
//Author:		Lou Yu
//Commentary:	This file contains a  minimum heap structure

#ifndef HEAP_H_COMPILED
#define HEAP_H_COMPILED

#include "DABasic.h"

namespace Structure
{
	using namespace DABasic;

	template <class T, bool needDestoryData = true>//If "needDestoryData" is true, this class will release "data" before been released.
	class Heap
	{
	private:
		T* data;
		unsigned memSize,//Total space of "data"
			size;//The space occupied

		void initHeap();
		void heapify(T* x);

		Index parent(Index x);
		Index left(Index x);
		Index right(Index x);

	public:
		Heap();
		Heap(T* initData, int memSize, int size){};
		~Heap(){};

		Index insert(T x);
		T extractMin();

		unsigned getSize();
		unsigned getTotalSize();
		bool resetSize(unsigned newSize);
	};
}

#endif