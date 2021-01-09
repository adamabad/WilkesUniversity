//**********************************************************
// File: PQHeap.h
// Author: Adam Abad
// Date: 4/22/2019
// Program Name: Huffman Code
//**********************************************************

// *********************************************************
// Header file Heap.h for the ADT heap.
// *********************************************************

#include<iostream>
using namespace std;
// Must define MAX_HEAP before compilation
// const int MAX_HEAP = maximum-size-of-heap;
const int MAX_HEAP = 100;
const int leaf = 1;
const int nonleaf = 0;

struct huffmannode{
  char symbol;
  int	 frequency;
  int nodetype;
  huffmannode * left;
  huffmannode *right;
};

class Heap {
 public:	
  Heap(); 
  // default constructor		
  // copy constructor and destructor are
  // supplied by the compiler
  
  // Heap operations:
  bool heapIsEmpty() const;
  // Determines whether a heap is empty.
  // Precondition: None.
  // Postcondition: Returns true if the heap is empty;
  // otherwise returns false.
  
  void heapInsert(const huffmannode& newItem);
  // Inserts an item into a heap.
  // Precondition: newItem is the item to be inserted.
  // Postcondition: If the heap was not full, newItem is
  // in its proper position; otherwise HeapException is
  // thrown.
  
  void heapDelete(huffmannode& rootItem);
  // Retrieves and deletes the item in the root of a heap.
  // This item has the largest search key in the heap.
  // Precondition: None.
  // Postcondition: If the heap was not empty, rootItem 
  // is the retrieved item, the item is deleted from the
  // heap. However, if the heap is empty, removal is
  // impossible and the function throws HeapException.
  
  void heapDisplay();
  int heapSize();
  
  
 private:
  huffmannode items[MAX_HEAP];  // array of heap items
  int size;             // number of heap items
  void heapRebuild(int root);
  // Converts the semiheap rooted at index root 
  // into a heap.
};  // end class
// End of header file.
