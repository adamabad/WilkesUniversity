//******************************************************************
// File: list.h
// Author: Adam Abad
// Date: 3/13/19
// Program Name: List Advanced
// Assignment 4
//******************************************************************



//******************************************************************
// Header file for list.cpp
//******************************************************************


#include<cassert>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;
struct node {
  int item;
  node *next;
};
class list {
 public:
  list();
  list(list *inList);
  list(string infile);		
  ~list();
  
  //list operations
  void displayList() const;
  int findElement(int element) const;
  void insertElement(int element);
  bool deleteElement(int element);
  int numberOfElements() const;
  void insertFromFile(string infile);
		
 private:
  node *head;
  int numberofelements;
};
