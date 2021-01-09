//******************************************************************
// File: BTstack.h
// Author: Adam Abad
// Date: 3/25/2019
// Program Name: Binary Trees
// Assignment 7
//******************************************************************

// ********************************************************
// Header file BTstack.h for the the stack implementation.
// Linked List implementation.
// ********************************************************

using namespace std;
struct btitem {
  int treeitem;
  int treeindex;
  btitem *next;
};

class linkedStack {
 public:
  // constructor and destructor:
  linkedStack();
  ~linkedStack();
  
  //Stack Operations:
  void push(int newItem, int index, bool& Success);
  //Inserts an item at the head of the stack
  //Returns true is push is successful
  void pop(int &popItem, int &index, bool& Success);
  //Removes topmost item of the stack.
  //Returns true is pop is successful
  void printStack() const;
  //Prints the contents of the stack from
  // top to bottom.
  bool isEmpty() const;
  //returns true if stack is empty
  //returns false if the stack is not empty
 private:
  btitem *head;
};
