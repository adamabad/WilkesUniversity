//******************************************************************
// File: general.h
// Author: Adam Abad
// Date: 4/4/2019
// Program Name: General Trees
// Assignment 9
//******************************************************************

// ********************************************************
// Header file general.h for the generaltree class
// Linked List implementation.
// ********************************************************

using namespace std;
struct gennode {
  int item;
  gennode *firstchild;
  gennode *siblinglist;
  gennode *prevsibling;
  gennode *parent;
};

class generalTree {
 public:
  //Constructor and destructor:
  generalTree();
  
  //Tree Operations
  bool nodeSearch(int item);
  //Node search calls the private search to see if the node is in the tree
  //Returns true is the node is located, false if it is not in the tree.
  bool insert();
  //Insert asks the user for a node to insert after
  //If this node is NULL, insert returns false
  //If the node is valid, insert will ask the user for an item to be added
  //If the item to be added is already in the tree, the insert function will
  // continue to loop until valid input is accepted.
  //Returns true on successful insert.
  bool printChildren(int item);
  //Takes an integer item that can be located in the tree.
  //If the item is not in the tree, returns false.
  //If the item is in the tree, the function will print the children
  // then return true.
  bool printSiblings(int item);
  //Takes and integer item that can be located in the tree.
  //If the item is not in the tree, returns false.
  //If the item is in the tree, the function will print the siblings
  // of the node, and return true.
  bool printLeft(int item);
  //Takes and integer item that can be located in the tree.
  //If the item is not in the tree, returns false.
  //If the item is in the tree, the function will print the siblings
  // of the node to the left, and return true.
  bool printRight(int item);
  //Takes and integer item that can be located in the tree.
  //If the item is not in the tree, returns false.
  //If the item is in the tree, the function will print the siblings
  // of the node to the right, and return true.
  bool printParent(int item);
  //Takes and integer item that can be located in the tree.
  //If the item is not in the tree, returns false.
  //If the item is in the tree, the function will print the parent
  // of the node, and return true.
  
 private:
  gennode *root;
  gennode* privateSearch(gennode *root, int item);
};
