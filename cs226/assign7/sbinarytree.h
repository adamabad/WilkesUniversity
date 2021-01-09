//******************************************************************
// File: sbinarytree.h
// Author: Adam Abad
// Date: 3/25/2019
// Program Name: Binary Trees
// Assignment 7
//******************************************************************

// ********************************************************
// Header file sbinarytree.h for the the Binary Tree class.
// Array based implementation.
// ********************************************************

using namespace std;
#include "BTstack.h"

class binarytree {
 public:
  // constructor and destructor:
  binarytree();
  ~binarytree();
  
  //Tree Operations:
  void addData(int newData, bool &Success);
  // Add to the left most free leaf in the tree.
  // If the tree is full, the item will not be added and success
  // will be set to false.
  void deleteData(int &item, bool &Success);
  // Removes the right most data element in the tree. 
  // If the tree is empty, item is unchanged and success if set to false.
  void displayLevel(int level) const;
  // Takes an integer and prints the data elements that correspond
  // to the level selected. If the level is not valid, returns an error.
  
  void inOrder() const;
  // Does an in order traversal of the tree using the stack.
  void preOrder() const;
  // Does a pre order traversal of the tree using the stack.
  void postOrder() const;
  // Dose a post order traversal of the tree using the stack.
  
  int getHeight() const;
  // Returns the current height of the tree.
  int getNumberOfElements() const;
  // Returns the number of elements in the tree.
  
 private:
  int tree[100];
  int height;
  int numberOfElements;
};
