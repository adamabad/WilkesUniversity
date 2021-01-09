//******************************************************************
// File: assign9.cpp
// Author: Adam Abad
// Date: 4/4/19
// Program Name: General Trees
// Assignment 9
//
// General Trees implements a linked structure to represent a tree.
// Several pointers are used at each node to give the tree structure.
// This program uses the general tree class to add nodes and display various
// partitians of the tree.
// 
// I have tested the program and it works properly.
//
//******************************************************************

#include<iostream>
#include"general.h"
#include<string>
#include<stdlib.h>

using namespace std;

void menu() {
  cout<<"1. Search for Item\n";
  cout<<"2. Display all Children\n";
  cout<<"3. Display all siblings\n";
  cout<<"4. Display Left Siblings\n";
  cout<<"5. Display Right Siblings\n";
  cout<<"6. Display Parent\n";
  cout<<"7. Add Node\n";
  cout<<"8. Exit\n";
}

void header() {
  cout<<"\nName: Adam Abad\n";
  cout<<"General Trees\n";
  cout<<"Uses a linked list to create and navigate a general tree.\n\n";
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

string search(generalTree *thisTree) {
  int x;
  while(true) {
    cout<<"Enter an item to search for: ";
    cin>>x;
    cout<<endl;
    if(cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, please reenter item.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  if(thisTree->nodeSearch(x)) {
    cout<<x<<" is in the tree.\n\n";
  }
  else {
    cout<<x<<" is not in the tree.\n\n";
  }
  return "";
}

string allChildren(generalTree *thisTree) {
  int x;
  while(true) {
    cout<<"Enter a node to print children from: ";
    cin>>x;
    cout<<endl;
    if(cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, please reenter item.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  if(!thisTree->printChildren(x)) {
    cout<<"The node does not exist.\n\n";
  }
  return "";
}

string allSiblings(generalTree *thisTree) {
  int x;
  while(true) {
    cout<<"Enter a node to print siblings of: ";
    cin>>x;
    cout<<endl;
    if(cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, please reenter item.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  if(!thisTree->printSiblings(x)) {
    cout<<"The node does not exist.\n\n";
  }
  return "";
}

string leftSiblings(generalTree *thisTree) {
  int x;
  while(true) {
    cout<<"Enter a node to print left siblings of: ";
    cin>>x;
    cout<<endl;
    if(cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, please reenter item.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  if(!thisTree->printLeft(x)) {
		cout<<"The node does not exist.\n\n";
  }
  return "";
}

string rightSiblings(generalTree *thisTree) {
  int x;
  while(true) {
    cout<<"Enter a node to print right siblings of: ";
    cin>>x;
    cout<<endl;
    if(cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, please reenter item.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  if(!thisTree->printRight(x)) {
    cout<<"The node does not exist.\n\n";
  }
  return "";
}

string getParent(generalTree *thisTree) {
  int x;
  while(true) {
    cout<<"Enter a node to print the parent of: ";
    cin>>x;
    cout<<endl;
    if(cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, please reenter item.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  if(!thisTree->printParent(x)) {
    cout<<"The node does not exist.\n\n";
  }
  return "";
}

string addNode(generalTree *thisTree) {
  thisTree->insert();
  return "";
}

int main() { 
  header();
  generalTree thisTree;
  int option = -1;
  while(option != 8) {
    menu();
    option = getOption();
    if(option > 8 or option < 1) {
      cout<<option<<" is not a valid option, please enter another option.\n\n";
    }
    else {
      cout<<"You chose option "<<option<<"\n\n";
      switch(option) {
      case 1: search(&thisTree);
	break;
      case 2: allChildren(&thisTree);
	break;
      case 3: allSiblings(&thisTree);
	break;
      case 4: leftSiblings(&thisTree);
	break;
      case 5: rightSiblings(&thisTree);
	break;
      case 6: getParent(&thisTree);
	break;
      case 7: addNode(&thisTree);
	break;
      case 8: break;
      default: cout<<"Error in option: "<<option<<endl;
      }
    }
  }
}
