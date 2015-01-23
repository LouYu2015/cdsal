//This file is a part of CDSAL
//Author:		Lou Yu
//Commentary:	This file contains implementation of "DABasic.h"

namespace DABasic
{
	template<class T>
	inline void Swap(T& a, T& b)
	{
		T temp = b;
		b = a;
		a = temp;
	}
}