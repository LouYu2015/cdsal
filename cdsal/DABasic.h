//This file is a part of CDSAL
//Author:		Lou Yu
//Commentary:	This file contains some sorting algorithms

#ifndef DABASIC_H_COMPILED
#define DABASIC_H_COMPILED

namespace DABasic
{
	//----- Declarations -----

	//*Types

	typedef unsigned Index;//For storing an index.

	//*Functions

	//Exchange a and b
	template<typename Data>
	inline void Swap(Data& a, Data& b);

	//Copy [begin, end) to dir, return the end if dir
	template<typename Data>
	inline Data* Copy(Data* begin, Data* end, Data* dir);

	//*Comparators

	template<typename Data>
	struct Ascending
	{
		inline bool operator ()(Data& a, Data& b){return b < a;}
	};

	template<typename Data>
	struct Descending
	{
		inline bool operator ()(Data& a, Data& b){return a < b;}
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
	inline Data* Copy(Data* begin, Data* end, Data* dir)
	{
		while(begin < end)
			*dir++ = *begin++;
		return dir;
	}
}
#endif

