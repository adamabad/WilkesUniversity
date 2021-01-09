//******************************************************************
// File: sbinarytree.cpp
// Author: Adam Abad
// Date: 3/25/2019
// Program Name: Binary Trees
// Assignment 7
//******************************************************************

// ********************************************************
// Implementation file sbinarytree.h for the the Binary Tree class.
// Array based implementation.
// ********************************************************

#include "sbinarytree.h"
#include <stddef.h>
#include <iostream>
#include <cmath>

binarytree::binarytree() {
  height = 0;
  numberOfElements = 0;
  for(int x = 0; x < 100; x++) {
    tree[x] = -1;
  }
}

binarytree::~binarytree() {
}

void binarytree::addData(int newData, bool & success) {
  if(numberOfElements >= 100) {
    success = false;
  }
  else {
    if(numberOfElements >= (pow(2, height) - 1))
      height++;
    tree[numberOfElements] = newData;
    numberOfElements++;
    success = true;
  }
}

void binarytree::deleteData(int &item, bool &success) {
  if(numberOfElements <= 0) {
    success = false;
  }
  else {
    if((numberOfElements - 1) <= (pow(2, height - 1) - 1)) {
      height--;
    }
    numberOfElements--;
    item = tree[numberOfElements];
    tree[numberOfElements] = -1;
    success = true;
  }
}


void binarytree::displayLevel(int level) const {
  if(level > height) {
    cout<<"The tree does not have level "<<level<<".\n\n";
  }
  else {
    int start = -1;
    for(int x = 0; x < level; x++) {
      start = start + pow(2, x - 1);
    }
    cout<<"Level "<<level<<":";
    for(int x = start; x < (start + pow(2, level - 1)); x++) {
      if(tree[x] > 0) {
	cout<<" "<<tree[x];
      }
    }
    cout<<"\n\n";
  }
  
}

void binarytree::inOrder() const {
  cout<<"In order traversal: \n";
  bool success;
  int item, index;
  if(numberOfElements != 0) {
    linkedStack *stack = new linkedStack;
    stack->push(tree[0], 0, success); //push root
    while(!stack->isEmpty()) {
      stack->pop(item, index, success);
      if(item != -1) {
	stack->push(tree[(index + 1) * 2],(index + 1) * 2,success); //push right
	stack->push(tree[index],index,success); //push root
	stack->push(tree[((index + 1) * 2) - 1], ((index + 1) * 2) - 1,success); //push left
      }
      else {
	if(!stack->isEmpty()) {
	  stack->pop(item, index, success);
	  cout<<item<<" ";
	}
      }
    }
  }
  cout<<endl;
}

void binarytree::preOrder() const{
  cout<<"Pre order traversal: \n";
  bool success;
  int item, index;
  if (numberOfElements != 0) {
    linkedStack *stack = new linkedStack;
    stack->push(tree[0], 0, success); //push root
    while(!stack->isEmpty()) {
      stack->pop(item, index, success);
      if(item != -1) {
	cout<<item<<" ";	
	stack->push(tree[(index + 1) * 2],(index + 1) * 2,success); //push right
	stack->push(tree[((index + 1) * 2) - 1], ((index + 1) * 2) - 1,success); //push left
      }
    }  
  }
  cout<<endl;
}

void binarytree::postOrder() const {
  //cout<<"Post order traversal: \n";
  //bool success;
  //int item, index;
  //linkedStack *stack = new linkedStack;
  //stack->push(tree[0], 0, success);
  //while(!stack->isEmpty()) {
  //	stack->pop(item, index, success);
  //	if(item != -1) {
  //		stack->push(tree[(index + 1) * 2],(index + 1) * 2,success); //push right
  //		stack->push(item, index, success);
  //		stack->push(tree[((index + 1) * 2) - 1], ((index + 1) * 2) - 1,success); //push left
  //	}
  //	stack->pop(item, index, success);
  //	if(item != -1) {
  //		if(tree[(index + 1) * 2] != -1) {
  //			stack->push(tree[(index + 1) * 2],(index + 1) * 2,success);
  //			stack->push(item, index, success);
  //		}
  //		else {
  //			cout<<item<<" ";
  //		}
  //	}
  //}
  //cout<<endl;
  cout<<"Unable to get post order to work.\n\n";
}

int binarytree::getHeight() const {
  return height;
}

int binarytree::getNumberOfElements() const {
  return numberOfElements;
}
