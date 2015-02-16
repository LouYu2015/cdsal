# Heap.h
`namespace Structure`

##Classes

## HeapBasic

### Member variables

* less: A comparator
* data: Pointer to a block of memory that stores the data
* totalSize: The Size of the block of memory that `data` points to
* size: How many place in `data` is occupied

### Protected member functions

#### InitHeap

Heapify all elements

#### Heapify

Move an element down to the right place.

#### MoveUp

Move an element up to the right place.

#### Parent, Left, Right

Get the index of related node.

#### Check

Check whether an index is available.

#### ToIndex

Return the index of data.

#### ToPointer

Return a pointer to data.

#### SwapElement(virtual functrion)

Swap two element.

### Public functions

#### HeapBasic

Initialize a empty heap.

#### Top

Return the element on the top.

#### Size

Return `size`.

#### TotalSize

Return `totalSize`.