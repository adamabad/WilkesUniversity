//******************************************************************
// File: list.cpp
// Author: Adam Abad
// Date: 3/13/19
// Program Name: Advanced
// Assignment 4
//******************************************************************

//******************************************************************
// Implementation file for list.cpp with implementation for copying
// and files
//******************************************************************

#include "list.h"

list::list() {
  head = NULL;
  numberofelements = 0;
}

list::list(list *inList) {
  head = NULL;
  numberofelements = 0;
  node *next = inList->head;
  while(next != NULL) {
    insertElement(next->item);
    next = next->next;
  }
}

list::list(string fileName) {
  ifstream inFile;
  inFile.open(fileName.c_str());
  assert(inFile.is_open());
  
  head = NULL;
  numberofelements = 0;
  int inData;
  while(true) {
    inFile>>inData;
    if (!inFile.good()) {
      inFile.clear();
      inFile.ignore(120,'\n');
    }
    if (inFile.eof()) {
      break;
    }
    insertElement(inData);
  }
  inFile.close();
}

list::~list() {
  while (numberofelements>0) {
    deleteElement(head->item); //delete next element
  }
}

//list operations
//Steps through the list and displays all the elements.
void list::displayList() const {
  node *next = head;
  while(next != NULL) {
    cout<<next->item<<endl;
    next = next->next;
  }
}
//Steps through the list to find the element, if the element is not in the list, returns 0.
int list::findElement(int element) const {
  node *next = head;
  for(int x = 1; x <= numberofelements; x++) {
    if(next->item == element) {
      return x;
    }
    else {
      next = next->next;
    }
  }
  return 0;
}

//Inserts the element, such that the list is always in increasing order.
void list::insertElement(int element) {
  node *temp, *current, *previous;
  temp = new node;
  temp->item = element;
  temp->next = NULL;
  current = head;
  previous = NULL;
  
  if(current == NULL) {
    head = temp;
  }
  else {
    while(current != NULL) { //Find first element larger than insert element
      if(current->item >= element) {
	if(previous == NULL) { //Inserting into the new head of a list
	  head = temp;
	}
	else {
	  previous->next = temp;
	}
	temp->next = current;
	break; //Breaking out of while loop
      }
      previous = current;
      current = current->next;
    }
    if(current == NULL) { //New Largest Element
      previous->next = temp;
    }
  }
  cout<<"Inserted: "<<element<<endl;
  numberofelements++;
}

void list::insertFromFile(string fileName) {
  ifstream inFile;
  inFile.open(fileName.c_str());
  assert(inFile.is_open());
  
  int inData;
  
  while(true) {
    inFile>>inData;
    if (!inFile.good()) {
      inFile.clear();
      inFile.ignore(120,'\n');
    }
    if (inFile.eof()) {
      break;
    }
    insertElement(inData);
  }
  inFile.close();
}
//Returns true if the element was found and deleted, returns false if the element could not be located.
bool list::deleteElement(int element) {
  bool value = false;
  node *current, *previous;
  current = head;
  previous = NULL;
  
  if(current != NULL && current->item == element) { //Removes Head of List
    head = current->next;
    delete(current);
    value = true;
    numberofelements--;
  }
  else { //Finds Element in list to remove
    while(current != NULL) {
      if(current->item == element) {
	previous->next = current->next;
	delete(current);
	value = true;
	numberofelements--;
      }
      previous = current;
      current = current->next;
    }
  }
  return value;
}
//Returns the value of the number of elements in the list.
int list::numberOfElements() const {
  return(numberofelements);
}
