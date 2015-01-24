//This file is a part of CDSAL
//Author:		Lou Yu
//Commentary:	This file contains implementation of "DABasic.h"

namespace DABasic
{
	template<class Data>
	inline void Swap(Data& a, Data& b)
	{
		Data temp = b;
		b = a;
		a = temp;
	}
}