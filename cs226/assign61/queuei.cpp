//******************************************************************
// File: queuei.cpp
// Author: Adam Abad
// Date: 3/19/2019
// Program Name: Queues
// Assignment 6
//******************************************************************

// *********************************************************
// Implementation file QueueP.cpp for the ADT queue.
// Pointer-based implementation.
// *********************************************************

#include "queuei.h"  // header file
#include <stddef.h>  // for NULL
#include <iostream>

// The queue is implemented as a circular linked list
// with one external pointer to the back of the queue.
struct queueNode {
  queueItemType Item;
  ptrType Next;
};  // end struct

queueClass::queueClass() {
  numberofqueueelements = 0;
  BackPtr = NULL;
  LastPtr = NULL;
}  // end default constructor



queueClass::~queueClass() {
  while(BackPtr != NULL) {
    bool success;
    QueueDelete(success);
  }
}  // end destructor

bool queueClass::QueueIsEmpty() const {
  return bool(BackPtr == NULL);
}  // end QueueIsEmpty

void queueClass::QueueInsert(queueItemType NewItem, bool& Success) {
  Success = false;
  queueNode *newNode;
  newNode = new queueNode;
  newNode->Item = NewItem;
  if(BackPtr == NULL) {
    newNode->Next = newNode;
    LastPtr = newNode;
    BackPtr = newNode;
  }
  else {
    newNode->Next = BackPtr;
    LastPtr->Next = newNode;
    BackPtr = newNode;
  }
  numberofqueueelements++;
  Success = true;
}  // end QueueInsert

void queueClass::QueueDelete(bool& Success) {
  Success = false;
  if(BackPtr != NULL) {
    if(BackPtr == BackPtr->Next) {
      BackPtr = NULL;
    }
    else {
      BackPtr = BackPtr->Next;
      delete(LastPtr->Next);
      LastPtr->Next = BackPtr;
    }
    Success = true;
    numberofqueueelements--;
  }
}  // end QueueDelete

void queueClass::QueueDelete(queueItemType& QueueFront, bool& Success) {
  if(BackPtr != NULL) {
    QueueFront = BackPtr->Item;
  }
  QueueDelete(Success);
}  // end QueueDelete

void queueClass::GetQueueFront(queueItemType& QueueFront, bool& Success) const {
  Success = false;
  if(BackPtr != NULL) {
    QueueFront = BackPtr->Item;
    Success = true;
  }
}  // end GetQueueFront

void queueClass::QueuePrint() const {
  queueNode *cur;
  cur = BackPtr;
  for(int x = 1; x <= NumberOfQueueElements(); x++) {
    cout<<"Item "<<x<<": "<<cur->Item<<endl;
    cur = cur->Next;
  }
}
int queueClass::NumberOfQueueElements() const {
  return numberofqueueelements;    
}
// End of implementation file.
