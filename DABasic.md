# DABasic.h
`namespace DABasic`.

This file contains things that this library will frequently use.

## Types

###　HData
```
template <typename Data>
using HData = Data**;
```
Store a handle of a element.
All handle of a certain data will point to a unique pointer that points to the data. When the data is moved, the pointer will be updated too.

### Index
```
typedef unsigned Index;
```
It is usually used to store an index.

## Functions
### Copy
```
template<typename Data>
inline Data* Copy(Data* begin, Data* end, Data* dir);
```
Copy data from [`begin`, `end`) to `dir`, using `operator =` of the data.

### Swap
```
template<typename Data>
inline void Swap(Data& a, Data& b);
```
Exchange `a` and `b`, using `operator =` of the data.

### Min
```
template<typename Data>
inline Data Min(const Data& a,const  Data& b);
```
Return the less

### Max
```
template<typename Data>
inline Data Max(const Data& a,const  Data& b);
```
Return the greater

### GetData
```
template<typename Data>
inline const Data& GetData(HData x);
```
Get what a handle points to.

## Classes
## Ascending(Maximum), Descending(Minimum)
```
class Ascending;
class Descending;

template<typename Data>
using Minimum = Descending<Data>;

template<typename Data>
using Maximum = Ascending<Data>;
```
#### operator <
```
inline bool operator ()(Data& a, Data& b)
```
Compare `a` and `b`, using `operator <` of the data. For `Ascending`, return whether `a` is greater than `b`. For `Descending`, return whether `a` is less than b.