#include <iostream>
using namespace std;
#define SIZE 10
// *********************************************************
// Header file templateex.h generic list
// Pointer-based implementation.
// *********************************************************

template <class T> class templateex
{
public:
// constructors and destructor:
   templateex();                     // default constructor
     
   ~templateex();                    // destructor
  void Display();
   void Insert(T NewItem, bool& Success);
 
  templateex <T> & operator=(const templateex<T>& Rhs);
  void makeEmpty();      
private:
  T example[SIZE];
   int noValidEntries;
   
  // points to first element
};  // end class

// End of header file.
#include "templateex.cpp"
