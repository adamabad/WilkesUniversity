//******************************************************************
// File: list.h
// Author: Adam Abad
// Date: 2/20/19
// Program Name: List
// Assignment 3
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
		~list();
  
		//list operations
		void displayList() const;
		int findElement(int element) const;
		void insertElement(int element);
		bool deleteElement(int element);
		int numberOfElements() const;

	private:
		node *head;
		int numberofelements;
};
