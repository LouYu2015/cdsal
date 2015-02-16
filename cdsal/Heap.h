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

	//Base class of heap
	template <typename Data, typename Comparator = Minimum<Data>>
	class HeapBasic;

	//Commonly used heap. It will automatically adjust its size.
	template <typename Data, typename Comparator = Minimum<Data>>
	class Heap;

	//Just take over part of the memory. Generally used for heap sort.
	template <typename Data, typename Comparator = Minimum<Data>>
	class InplaceHeap;

	//When you use it, you can refer to its elements.
	template <typename Data, typename Comparator = Minimum<Data>>
	class RefHeap;

	template <typename Data, typename Comparator>
	class HeapBasic
	{
	protected:
		Comparator less;
		Data* data;
		int totalSize,//Total space of "data"
			size;//The space occupied

		void InitHeap();//Heapify all elements
		void Heapify(Index x);//Move an element down to Right place
		void MoveUp(Index x);//Move an element up to Right place

		//Get related index
		inline Index Parent(Index x){return (x - 1)/2;}
		inline Index Left(Index x){return x*2 + 1;}
		inline Index Right(Index x){return x*2 + 2;}

		//Check whether an index is available
		inline bool Check(Index x){return x >= 0 && x < size;}


		inline Index ToIndex(Data* a){return (Index)(a-data);}
		inline Data* ToPointer(Index a){return &data[a];}

		virtual void SwapElement(Index a, Index b){}

	public:
		HeapBasic(): data(NULL), totalSize(0), size(0){}

		const Data* Top(){if(data != NULL && size != 0)return &data[0]; else return NULL;}
		unsigned Size(){return size;}
		unsigned TotalSize(){return totalSize;}
	};

	template <typename Data, typename Comparator>
	class InplaceHeap: virtual public HeapBasic<Data, Comparator>
	{
		using HeapBasic<Data, Comparator>::data;
		using HeapBasic<Data, Comparator>::less;
		using HeapBasic<Data, Comparator>::size;
		using HeapBasic<Data, Comparator>::totalSize;

	protected:
		void SwapElement(Index a, Index b){Swap(data[a], data[b]);}

	public:
		InplaceHeap(){typename HeapBasic<Data, Comparator>::HeapBasic();}
		InplaceHeap(Data* initData, int initDataSize, int heapSize);

		void Insert(const Data& x);
		Data ExtractTop();
	};

	template <typename Data, typename Comparator>
	class Heap: public InplaceHeap<Data, Comparator>, virtual public HeapBasic<Data, Comparator>
	{
		using HeapBasic<Data, Comparator>::data;
		using HeapBasic<Data, Comparator>::less;
		using HeapBasic<Data, Comparator>::size;
		using HeapBasic<Data, Comparator>::totalSize;

	public:
		Heap(){typename InplaceHeap<Data, Comparator>::InplaceHeap();}
		Heap(const Data* initData, int initDataSize, int heapSize);
		~Heap(){delete [] data;}

		void Insert(const Data& x);
		Data ExtractTop();

		void Resize(int newSize);
	};

	template <typename Data, typename Comparator>
	class RefHeap: public Heap<Data, Comparator>, virtual public HeapBasic<Data, Comparator>
	{
		using HeapBasic<Data, Comparator>::data;
		using HeapBasic<Data, Comparator>::less;
		using HeapBasic<Data, Comparator>::size;
		using HeapBasic<Data, Comparator>::totalSize;

	protected:
		Data*** refToRef;//refToRef[i] points to reference of data[i]
		virtual void SwapElement(Index a, Index b);

	public:
		RefHeap():refToRef(NULL){}
		RefHeap(const Data* initData, int initDataSize, int heapSize, HData<Data>* ref = NULL);
		~RefHeap();

		HData<Data> Insert(const Data& x, bool creatRef = true);
		Data ExtractTop();

		void Replace(HData<Data> x, const Data& newKey);
		void Remove(HData<Data> x);

		void Resize(unsigned newSize);
	};

	//----- Implementations -----

	//class HeapBasic
	template <typename Data, typename Comparator>
	void HeapBasic<Data, Comparator>::InitHeap()
	{
		for(Index i = (Index)(size - 1); i >= (Index)0; i--)
			Heapify(i);
	}

	template <typename Data, typename Comparator>
	void HeapBasic<Data, Comparator>::Heapify(Index x)
	{
		Index iMin, iLeft, iRight;
		while(true)
		{
			iMin = x;
			iLeft = Left(x);
			iRight = Right(x);

			if(Check(iLeft) && less(data[iLeft], data[iMin]))
				iMin = iLeft;
			if(Check(iRight) && less(data[iRight], data[iMin]))
				iMin = iRight;

			if(x != iMin)
			{
				SwapElement(x, iMin);
				x = iMin;
			}
			else
				break;
		}
	}

	template <typename Data, typename Comparator>
	void HeapBasic<Data, Comparator>::MoveUp(Index x)
	{
		while(x != (Index)0 && less(data[x], data[Parent(x)]))
		{
			SwapElement(x, Parent(x));
			x = Parent(x);
		}
	}

	//class Inplace Heap
	template <typename Data, typename Comparator>
	InplaceHeap<Data, Comparator>::InplaceHeap(Data* initData, int initDataSize, int heapSize)
	{
		if(initDataSize > heapSize)
			throw DAError(DA_HEAP, DA_ILLEGAL_PARAMETER);
		data = initData;
		size = initDataSize;
		totalSize = heapSize;
		HeapBasic<Data, Comparator>::InitHeap();
	}


	template <typename Data, typename Comparator>
	void InplaceHeap<Data, Comparator>::Insert(const Data& x)
	{
		if(size == totalSize)
			throw DAError(DA_HEAP, DA_OVERFLOW);
		data[size++] = x;
		this->MoveUp((Index)(size-1));
	}

	template <typename Data, typename Comparator>
	Data InplaceHeap<Data, Comparator>::ExtractTop()
	{
		if(size == 0)
			throw DAError(DA_HEAP, DA_UNDERFLOW);
		Data top = data[0];
		SwapElement((Index)0, (Index)(size - 1));
		size--;
		this->Heapify((Index)0);
		return top;
	}

	//class Heap
	template <typename Data, typename Comparator>
	Heap<Data, Comparator>::Heap(const Data* initData, int initDataSize, int heapSize)
	{
		if(initDataSize > heapSize)
			throw DAError(DA_HEAP, DA_ILLEGAL_PARAMETER);

		data = new Data[heapSize];
		Copy(initData, initData + initDataSize, data);
		size = initDataSize;
		totalSize = heapSize;
		this->InitHeap();
	}

	template <typename Data, typename Comparator>
	void Heap<Data, Comparator>::Insert(const Data& x)
	{
		if(totalSize == 0)
			Resize(1);
		if(size == totalSize)
			Resize(totalSize*2);
		InplaceHeap<Data, Comparator>::Insert(x);
	}

	template <typename Data, typename Comparator>
	Data Heap<Data, Comparator>::ExtractTop()
	{
		Data top = InplaceHeap<Data, Comparator>::ExtractTop();
		if(size < totalSize/4)
			Resize(totalSize/2);
		return top;
	}

	template <typename Data, typename Comparator>
	void Heap<Data, Comparator>::Resize(int newSize)
	{
		if(newSize < size)
			throw DAError(DA_HEAP, DA_ILLEGAL_PARAMETER);

		Data* newMem = new Data[newSize];
		Copy(data, data + size, newMem);
		delete data;
		data = newMem;
		totalSize = newSize;
	}

	//class RefHeap
	template <typename Data, typename Comparator>
	RefHeap<Data, Comparator>::RefHeap(const Data* initData, int initDataSize, int heapSize, HData<Data>* ref)
	{
		Heap<Data, Comparator>::Heap(initData, initDataSize, heapSize);
		refToRef = new Data**[heapSize];
		Init(ref, ref + heapSize, NULL);

		if(ref != NULL)
			for(int i = 0; i < initDataSize; i++)
				ref[i] = refToRef[i] = new Data*(&data[i]);

		initHeap();
	}

	template <typename Data, typename Comparator>
	RefHeap<Data, Comparator>::~RefHeap()
	{
		for(int i = 0; i < size; i++)
			delete refToRef[i];
		delete [] refToRef;
	}

	template <typename Data, typename Comparator>
	void RefHeap<Data, Comparator>::SwapElement(Index a, Index b)
	{
		Heap<Data, Comparator>::SwapElement(a, b);
		Swap(refToRef[a], refToRef[b]);
		if(refToRef[a] != NULL)
			*refToRef[a] = &data[a];
		if(refToRef[b] != NULL)
			*refToRef[b] = &data[b];
	}

	template <typename Data, typename Comparator>
	HData<Data> RefHeap<Data, Comparator>::Insert(const Data& x, bool creatRef)
	{
		if(totalSize == 0)
			Resize(1);
		if(size == totalSize)
			Resize(totalSize*2);
		Data **result = NULL;
		if(creatRef)
			result = refToRef[size] = new Data*(&data[size]);
		Heap<Data, Comparator>::Insert(x);

		return result;
	}

	template <typename Data, typename Comparator>
	Data RefHeap<Data, Comparator>::ExtractTop()
	{
		delete refToRef[0];
		refToRef[0] = NULL;
		return Heap<Data, Comparator>::ExtractTop();
	}

	template <typename Data, typename Comparator>
	void RefHeap<Data, Comparator>::Replace(HData<Data> x, const Data& newKey)
	{
		Index i = this->ToIndex(*x);
		if(!this->Check(i))
			throw DAError(DA_HEAP, DA_ILLEGAL_PARAMETER);

		data[i] = newKey;
		this->Heapify(i);
		this->MoveUp(i);
	}

	template <typename Data, typename Comparator>
	void RefHeap<Data, Comparator>::Remove(HData<Data> x)
	{
		Index i = this->ToIndex(*x);//Convert to index of "data"
		if(!this->Check(i))
			throw DAError(DA_HEAP, DA_ILLEGAL_PARAMETER);

		delete refToRef[i];
		refToRef[i] = NULL;
		SwapElement(i, size-1);
		size--;

		this->Heapify(i);
		this->MoveUp(i);

		if(size < totalSize/4)
			Resize(totalSize/2);
	}

	template <typename Data, typename Comparator>
	void RefHeap<Data, Comparator>::Resize(unsigned newSize)
	{
		Data* oldData = data;
		Heap<Data, Comparator>::Resize(newSize);

		Data ***newRefToRef = new Data**[newSize];
		Copy(refToRef, refToRef + size, newRefToRef);
		for(unsigned i = size; i < newSize; i++)
			newRefToRef[i] = NULL;
		refToRef = newRefToRef;

		for(int i = 0; i < size; i++)
			if(refToRef[i] != NULL)
				*refToRef[i] += data - oldData;
	}
}

#endif
