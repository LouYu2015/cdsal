//This file is a part of CDSAL
//Author:		Lou Yu
//Commentary:	This file contains some sorting algorithms

#ifndef DABASIC_H_COMPILED
#define DABASIC_H_COMPILED

namespace DABasic
{
	//----- Declarations -----

	//*Types

	//Handle to data
	template <typename Data>
	using HData = Data**;

	typedef int Index;

	//*Functions

	//Exchange a and b
	template<typename Data>
	inline void Swap(Data& a, Data& b);

	//Copy [begin, end) to dir, return the end if dir
	template<typename Data>
	inline Data* Copy(const Data* begin, const Data* end, Data* dir);

	template<typename Data>
	inline void Init(Data* begin, Data* end, Data& fill);

	template<typename Data>
	inline Data Min(const Data& a,const  Data& b);

	template<typename Data>
	inline Data Max(const Data& a,const  Data& b);

	template<typename Data>
	inline const Data& GetData(HData x);

	//*Comparators

	template<typename Data>
	struct Ascending
	{
		inline bool operator ()(const Data& a, const Data& b){return b < a;}
	};

	template<typename Data>
	struct Descending
	{
		inline bool operator ()(const Data& a, const Data& b){return a < b;}
	};

	template<typename Data>
	using Minimum = Descending<Data>;

	template<typename Data>
	using Maximum = Ascending<Data>;

	//----- Implementations -----

	template<typename Data>
	inline void Swap(Data& a, Data& b)
	{
		Data temp = b;
		b = a;
		a = temp;
	}

	template<typename Data>
	inline Data* Copy(const Data* begin, const  Data* end, Data* dir)
	{
		while(begin < end)
			*dir++ = *begin++;
		return dir;
	}

	template<typename Data>
	inline void Init(Data* begin, Data* end, Data& fill)
	{
		for(Data* i = begin; i < end; i++)
			*i = fill;
	}

	template<typename Data>
	inline Data Min(const Data& a, const Data& b)
	{return a<b?a:b;}

	template<typename Data>
	inline Data Max(const Data& a, const Data& b)
	{return a<b?b:a;}

	template<typename Data>
	inline const Data& GetData(HData x)
	{return **x;}
}
#endif

