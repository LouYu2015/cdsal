#ifndef DAEXCEPTION_H_COMPILED
#define DAEXCEPTION_H_COMPILED

namespace DAException
{
    //----- Declarations -----

    enum DASenderId;
    enum DAErrorId;

    struct DAError
    {
        DASenderId sender;
        DAErrorId errorId;

        DAError(DASenderId scr, DAErrorId newError):sender(scr),errorId(newError){}
        const char* ErrorInfo();
        const char* SenderInfo();
    };

    typedef DAError HeapError;

    //----- Implementations -----

    enum DAErrorId
    {
        DA_ILLEGAL_PARAMETER,
        DA_OUT_OF_RANGE,
        DA_OUT_OF_SPACE
    };

    enum DASenderId
    {
        DA_HEAP
    } ;

    const char* DAError::ErrorInfo()
    {
        switch(errorId)
        {
        case DA_ILLEGAL_PARAMETER:
            return "Program used an illegal parameter";
        case DA_OUT_OF_RANGE:
            return "Program referred to something unavailable";
        case DA_OUT_OF_SPACE:
            return "No enough space for more data";
        default:
            retrun "Unknown";
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
