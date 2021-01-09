//******************************************************************
// File: assign7.cpp
// Author: Adam Abad
// Date: 3/25/19
// Program Name: Binary Trees
// Assignment 7
//
// Binary Trees uses an array to implement a binary tree. This 
// iteration of the tree has traversals and can display information
// about the tree.
// 
// My program runs, however I was unable to get the postOrder transversal
// to work properly. 
//
// Resources:
// https://en.cppreference.com/w/cpp/numeric/math/pow for cmath library
//******************************************************************


#include<iostream>
#include"sbinarytree.h"
#include<string>
#include<stdlib.h>
#include<cmath>

using namespace std;

void menu() {
  cout<<"1.  Add an element.\n";
  cout<<"2.  Delete an element.\n";
  cout<<"3.  Display level i of the tree.\n";
  cout<<"4.  Inorder Traversal.\n";
  cout<<"5.  Preorder Traversal.\n"; 
  cout<<"6.  Postorder Traversal.\n";
  cout<<"7.  Height of the tree.\n";
  cout<<"8.  Number of Elements in the tree.\n";
  cout<<"9.  Is tree full?\n";
  cout<<"10. Exit.\n\n";
}

void header() {
  cout<<"\nName: Adam Abad\n";
  cout<<"Binary Trees\n";
  cout<<"Uses an array to represent a Binary Tree.\n\n";
}

int getOption() {
  int x;
  while(true) {
    cout<<"Please enter your Option: ";
    cin>>x;
    cout<<endl;
    if(cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, please reenter option.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  return x;
}

string addData(binarytree *thisTree) {
  int x;
  while(true) {
    cout<<"Please enter a positive integer: ";
    cin>>x;
    cout<<endl;
    if(cin.good() && x > 0) {
      break;
    }
    cout<<"You have entered invalid input, please reenter data.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  bool success;
  thisTree->addData(x, success);
  if(success) {
    cout<<x<<" was added successfully.\n\n";
  }
  else {
    cout<<x<<" was unable to be added to the tree.\n\n";
  }
  return "";
}

string removeData(binarytree *thisTree) {
  bool success;
  int item;
  thisTree->deleteData(item, success);
  if(success) {
    cout<<item<<" was removed from the tree.\n\n";
	}
  else {
    cout<<"No item could be removed.\n\n";
  }
  return "";
}

string getLevel(binarytree *thisTree) {
  int x;
  while(true) {
    cout<<"Please enter a level to display: ";
    cin>>x;
    cout<<endl;
    if(cin.good()) {
      break;
		}
    cout<<"You have entered invalid input, please reenter data.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  thisTree->displayLevel(x);
  return "";
}

string checkTree(binarytree *thisTree) {
  int num = thisTree->getNumberOfElements();
  int height = thisTree->getHeight();
  if(num == (pow(2, height) - 1)) {
    cout<<"The tree is full.\n\n";
  }
  else {
    cout<<"The tree is not full.\n\n";
  }
  return "";
}
int main() { 
  header();
  binarytree thisTree;
  int option = -1;
  while(option != 10) {
    menu();
    option = getOption();
    if(option > 10 or option < 1) {
      cout<<option<<" is not a valid option, please enter another option.\n\n";
    }
    else {
      cout<<"You chose option "<<option<<"\n\n";
      switch(option) {
      case 1: addData(&thisTree);
	cout<<endl;
	break;
      case 2: removeData(&thisTree);
	break;
      case 3: getLevel(&thisTree);
	break;
      case 4: thisTree.inOrder();
	break;
      case 5: thisTree.preOrder();
	break;
      case 6: thisTree.postOrder();
	break;
      case 7:
	cout<<"Height: "<<thisTree.getHeight()<<"\n\n";
	break;
      case 8: 
	cout<<"There are "<<thisTree.getNumberOfElements()<<" element(s) in the tree.\n\n";
	break;
      case 9: checkTree(&thisTree);
	break;
      case 10: break;
      default: cout<<"Error in option: "<<option<<endl;
      }
    }
  }
}
