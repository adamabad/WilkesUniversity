//******************************************************************
// File: queuea.cpp
// Author: Adam Abad
// Date: 3/19/2019
// Program Name: Array Queues
// Assignment 6
//
//http://www.cplusplus.com/reference/cstdlib/malloc/ used for 
// malloc reference for dynamic arrays.
//******************************************************************

// ********************************************************
// Implmentation file Queuea.h for the ADT queue.
// Array-based implementation.
// ********************************************************

#include "queuea.h"
#include <stddef.h>
#include <iostream>

queueClass::queueClass() {
  numberofqueueelements=0;
  currentSize = 10;
  array = (int*)malloc(currentSize*sizeof(int));
}  // end default constructor

queueClass::~queueClass() {
  free(array);
}  // end destructor

bool queueClass::QueueIsEmpty() const {
  return (numberofqueueelements == 0);
}  // end QueueIsEmpty

void queueClass::QueueInsert(int NewItem, bool& Success) {
  Success = false;
  if(numberofqueueelements == currentSize) {
    currentSize = currentSize + 5;
    int *temp = (int*)malloc(currentSize*sizeof(int));
    for(int x = 0; x < numberofqueueelements; x++) {
      temp[x] = array[x];
    }
    free(array);
    array = temp;
    array[numberofqueueelements] = NewItem;
    Success = true;
  }
  else {
    array[numberofqueueelements] = NewItem;
    Success = true;
  }
  numberofqueueelements++;
}  // end QueueInsert

void queueClass::QueueDelete(bool& Success) {
  Success = false;
  if(numberofqueueelements == 1) {
    free(array);
    numberofqueueelements = 0;
    currentSize = 10;
    array = (int*)malloc(currentSize*sizeof(int));
    Success = true;
  }
  else if(numberofqueueelements > 1) {
    numberofqueueelements--;
    Success = true;
  }
}  // end QueueDelete

void queueClass::QueueDelete(int& QueueFront, bool& Success) {
  GetQueueFront(QueueFront, Success);
  QueueDelete(Success);
}  // end QueueDelete

void queueClass::GetQueueFront(int& QueueFront, bool& Success) const {
  Success = false;
  if(numberofqueueelements != 0) {
    QueueFront = array[numberofqueueelements - 1];
    Success = true;
  }
}  // end GetQueueFront

void queueClass::QueuePrint() const {
  for(int x = numberofqueueelements - 1; x >= 0; x--) {
    cout<<"Item "<<numberofqueueelements - x<<": "<<array[x]<<endl;
  }
}
int queueClass::NumberOfQueueElements() const {
  return numberofqueueelements;
}
// End of implementation file.
