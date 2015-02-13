#ifndef DAEXCEPTION_H_COMPILED
#define DAEXCEPTION_H_COMPILED

namespace DAException
{
	//----- Declarations -----

	enum DAErrorId
	{
		DA_ILLEGAL_PARAMETER,
		DA_OUT_OF_RANGE,
		DA_OVERFLOW,
		DA_UNDERFLOW
	};

	enum DASenderId
	{
		DA_HEAP
	} ;

	struct DAError
	{
		DASenderId sender;
		DAErrorId errorId;

		DAError(DASenderId scr, DAErrorId newError):sender(scr),errorId(newError){}
		const char* ErrorInfo();
		const char* SenderInfo();
	};

	//----- Implementations -----



	const char* DAError::ErrorInfo()
	{
		switch(errorId)
		{
		case DA_ILLEGAL_PARAMETER:
			return "Program used an illegal parameter";
		case DA_OUT_OF_RANGE:
			return "Program referred to something unavailable";
		case DA_OVERFLOW:
			return "Overflowed";
		case DA_UNDERFLOW:
			return "Underflowed";
		default:
			return "Unknown";
		}
	}

	const char* DAError::SenderInfo()
	{
		switch(sender)
		{
		case DA_HEAP:
			return "Heap Structure";
		default:
			return "Unknown";
		}
	}
}

#endif // DAEXCEPTION_H_COMPILED
