//******************************************************************
// File: collection.cpp
// Author: Adam Abad
// Date: 2/10/19
// Program Name: Collection
// Assignment 2
// Collection uses a template class to set up a generic array 
//      and perform various actions to alter data in it.
// Collection sets up two arrays then promts the user for an 
//      action using the option menu. Then, the corresponding 
//      message will appear and promt the user for aditional 
//      input regarding their choice.
//******************************************************************


//******************************************************************
// Implementation file collection.cpp
//******************************************************************

#include <stddef.h>

//Constructor and Destructor
template<class T>
collection<T>::collection() {
  //cout<<"Constructor Executing\n";
  currentValue = 0;
}

template<class T>
collection<T>::~collection() {
  //cout<<"Destructor Executing\n";
  makeEmpty();
}

//isEmpty() returns false if the array is not empty, and true if it is.
template<class T>
bool collection<T>::isEmpty() {
  if (currentValue >= 1) return false;
  else return true;
}

//makeEmpty() makes the array empty by setting the currentValue to 0.
template<class T>
void collection<T>::makeEmpty() {
  currentValue = 0;
}

//Insert() adds an item to the end of the array if there is space, 
// returns true if it was able to add an item, and false if unsuccessful.
template<class T>
void collection<T>::Insert(T item, bool& Success) {
  if (currentValue >= ARRAYSIZE) {
    Success = false;
  }
	else {
	  mainArray[currentValue++] = item;
	  Success = true;
	}
}

//Remove() removes the last item from the array, returns true and the item 
// if successful, and false if the array is empty.
template<class T>
void collection<T>::Remove(T& item, bool& Success) {
  if (currentValue >= 1) {
    item = mainArray[currentValue - 1];
    currentValue--;
    Success = true;
  }
  else {
    Success = false;
  }
}

//Contains() uses linear search to search for the item passed to it,
// returns true if the item is in the array, and false if it is not.
template<class T>
bool collection<T>::Contains(T item) {
  for (int i = 0; i < currentValue; i++) {
    if (item == mainArray[i]) {
      return true;
    }
  }
  return false;
}

//Display() outputs the contents of an array, 1 item per line.
template<class T>
void collection<T>::Display() {
  for (int i = 0; i < currentValue; i++) {
    cout<<mainArray[i]<<endl;
  }
}

//= Overload, sets the item on the right side of '=' to the left.
// 2/11/19 Unable to successfully fire the overload
template<class T>
collection<T>& collection<T>::operator= (const collection<T>& Rhs) {
  if(Rhs.mainArray != mainArray) {
    mainArray = Rhs.mainArray;
    return *mainArray;
  } 
  else {
    return *Rhs.mainArray;
  } 
}

//== Overload compares the content of two arrays by first comparing their
// sizes, then the content in each.
// returns true if the arrays are equal in size and contents
// returns false if the arrays have different sizes or different elements
// 2/11/19 Unable to successfully fire the overload
template<class T>
bool collection<T>::operator== (const collection<T>& Rhs) {
  bool isequal = true;
  if(currentValue == Rhs.currentValue) {
    for(int i = 0; i < 20; i++) {
      if (mainArray[i] != Rhs.mainArray[i]) {
	isequal = false;
      }
    }
  }
  else {
    isequal = false;
  }
  return isequal;
}

//end of implementation file
