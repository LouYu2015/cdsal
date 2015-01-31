# DAException.h
`namespace DAException`.

## Types
### DASenderId
```
enum DASenderId
{
    DA_HEAP
} ;
```
Represents which code throws the exception.

### DAErrorId
```
enum DAErrorId
{
    DA_ILLEGAL_PARAMETER,
    DA_OUT_OF_RANGE,
    DA_OUT_OF_SPACE
};
```
Represents which error occurred.

## Classes
## DAError
### DAError
```
DAError(DASenderId scr, DAErrorId newError):sender(scr),errorId(newError)
```
Initialize the class with `scr` for sender id and `newError` for error id.

### ErrorInfo
```
const char* ErrorInfo();
```
Return a description of the error.

### SenderInfo
```
const char* SenderInfo();
```
Return a description of the sender.
