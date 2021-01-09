//******************************************************************
// File: BTstack.cpp
// Author: Adam Abad
// Date: 3/25/2019
// Program Name: Binary Trees
// Assignment 7
//******************************************************************

// ********************************************************
// Implementation file BTstack.h for the the binary stack.
// Linked List implementation.
// ********************************************************

#include "BTstack.h"
#include <stddef.h>
#include <iostream>

linkedStack::linkedStack() {
  head = NULL;
}

linkedStack::~linkedStack() {
  bool success;
  int item, index;
  while(head != NULL) {
    pop(item, index, success);
  }
}

void linkedStack::push(int newItem, int index, bool& success) {
  //cout<<"Pushed: "<<newItem<<" "<<index<<endl; // Debugging line
  btitem *newNode;
  newNode = new btitem;
  newNode->next = head;
  newNode->treeitem = newItem;
  newNode->treeindex = index;
  head = newNode;
}

void linkedStack::pop(int &popItem, int &index, bool& success) {
  if(head == NULL) {
    success = false;
  }
  else {
    btitem *tempNode;
    success = true;
    popItem = head->treeitem;
    index = head->treeindex;
    tempNode = head->next;
    delete(head);
    head = tempNode;
  }
}

bool linkedStack::isEmpty() const {
  return (head == NULL);
}

void linkedStack::printStack() const {
  btitem *curr;
  curr = head;
  while (curr != NULL) {
    cout<<"Index: "<<curr->treeindex<<"   Item: "<<curr->treeitem<<endl;
    curr = curr->next;
  }
}
