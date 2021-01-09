//******************************************************************
// File: general.cpp
// Author: Adam Abad
// Date: 4/4/2019
// Program Name: General Trees
// Assignment 9
//******************************************************************

// ********************************************************
// Implementation file general.cpp for the the general tree.
// Linked List implementation.
// ********************************************************

#include "general.h"
#include <stddef.h>
#include <iostream>

generalTree::generalTree() {
  root = NULL;
  int x;
  char startFlag = 'y';
  gennode *newNode;
  newNode = new gennode;
  bool insertSuccess;
  
  while(true) {
    cout<<"To use the general tree, please enter an inital root: ";
    cin>>x;
    cout<<endl;
    if(cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, please reenter root.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  
  newNode->item = x;
  newNode->firstchild = NULL;
  newNode->siblinglist = NULL;
  newNode->prevsibling = NULL;
  newNode->parent = NULL;
  root = newNode;
  cout<<x<<" was made the root of the tree.\n";
  
  while(startFlag == 'y') {
    cout<<"Please enter 'y' to continue adding nodes, or 'n' to stop: ";
    while(true) {
      cin>>startFlag;
      cout<<endl;
      if(startFlag == 'y' || startFlag == 'n') {
	break;
      }
      cout<<"Please reenter condition, 'y' or 'n': ";
      cin.clear();
      cin.ignore(120,'\n');
    }
    if(startFlag == 'y') {
      cout<<"You pressed 'y'.\n";
      insertSuccess = insert();
      if(!insertSuccess) {
	cout<<"The node could not be added.\n";
      }
    }
  }
}

bool generalTree::nodeSearch(int item) {
  return (privateSearch(root, item) != NULL);
}

bool generalTree::insert() {
  int item;
  while(true) {
    cout<<"Enter the parent of the node you want to make: ";
    cin>>item;
    cout<<endl;
    if(cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, please reenter item.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  cout<<"You have set "<<item<<" as the parent.\n";
  if(nodeSearch(item)) {
    //making new node
    gennode *parent, *temp, *newNode;
    newNode = new gennode;
    newNode->firstchild = NULL;
    newNode->siblinglist = NULL;
    
    parent = privateSearch(root, item);
    newNode->parent = parent;
    
    if(parent->firstchild != NULL) {
      //Is not parent's first child
      temp = parent->firstchild;
      while(temp->siblinglist != NULL) {
	temp = temp->siblinglist;
      }
      temp->siblinglist = newNode;
      newNode->prevsibling = temp;
      }
    //Is parent's first child
    else {
      parent->firstchild = newNode;
      newNode->prevsibling = NULL;
    }
    
    //setting item loops
    while(true) {
      while(true) {
	cout<<"Enter the node you want to make: ";
	cin>>item;
	cout<<endl;
	if(cin.good()) {
	  break;
	}
	cout<<"You have entered invalid input, please reenter item.\n";
	cin.clear();
	cin.ignore(120,'\n');
      }
      if(nodeSearch(item)) {
	cout<<item<<" is already in the tree.\n";
	cout<<"Please reenter an item to add.\n\n";
      }
      else {
	//setting newNode item
	newNode->item = item;
	cout<<item<<" was inserted into the tree.\n";
	return true;	  
      }
    }
  }
  //parent does not exist
  else {
    return false;
  }
}

bool generalTree::printChildren(int item) {
  gennode *temp;
  temp = privateSearch(root, item);
  if(temp == NULL) {
    return false;
  }
  else {
    cout<<"Node "<<item<<"'s children: ";
    if(temp->firstchild != NULL) {
      temp = temp->firstchild;
      cout<<temp->item<<" ";
      while(temp->siblinglist != NULL) {
	temp = temp->siblinglist;
	cout<<temp->item<<" ";
      }
    }
    cout<<"\n\n";
    return true;
  }
}

bool generalTree::printSiblings(int item) {
  gennode *temp;
  temp = privateSearch(root, item);
  if(temp == NULL) {
    return false;
  }
  else {
    cout<<"Node "<<item<<"'s siblings: ";
    if(temp->parent != NULL) {
      temp = temp->parent->firstchild;
      if(temp->item != item) {
	cout<<temp->item<<" ";
      }
      while(temp->siblinglist != NULL) {
	temp = temp->siblinglist;
	if(temp->item != item) {
	  cout<<temp->item<<" ";
	}
      }
    }
    cout<<"\n\n";
    return true;
  }
}

bool generalTree::printLeft(int item) {
  gennode *temp;
  temp = privateSearch(root, item);
  if(temp == NULL) {
    return false;
  }
  else {
    cout<<"Node "<<item<<"'s left siblings: ";
    while(temp->prevsibling != NULL) {
      temp = temp->prevsibling;
      cout<<temp->item<<" ";
    }
    cout<<"\n\n";
    return true;
  }
}

bool generalTree::printRight(int item) {
  gennode *temp;
  temp = privateSearch(root, item);
  if(temp == NULL) {
    return false;
  }
  else {
    cout<<"Node "<<item<<"'s right siblings: ";
    while(temp->siblinglist != NULL) {
      temp = temp->siblinglist;
      cout<<temp->item<<" ";
    }
    cout<<"\n\n";
    return true;
  }
}

bool generalTree::printParent(int item) {
  gennode *temp;
  temp = privateSearch(root, item);
  if(temp == NULL) {
    return false;
  }
  else {
    if(temp->parent == NULL) {
      cout<<"Item "<<item<<" is the root, it does not have a parent.\n\n";
    } 
    else {
      cout<<"Item "<<item<<"'s parent is "<<temp->parent->item<<".\n\n";
    }
    return true;
  }
}

gennode* generalTree::privateSearch(gennode *root, int item) {
  if(root == NULL) {
    return NULL;
  }
  else if(root->item == item) {
    return root;
  }
  else {
    gennode *temp = NULL;
    temp = privateSearch(root->firstchild, item);
    if(temp != NULL) {
      return temp;
    }
    else {
      temp = privateSearch(root->siblinglist, item);
      if(temp != NULL) {
	return temp;
      }
    }
    return temp;
  }
}
