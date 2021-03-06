//******************************************************************
// File: listj.cpp
// Author: Adam Abad
// Date: 3/13/19
// Program Name: Josephus Problem,
// Assignment 4
//******************************************************************



//******************************************************************
// Implementation file for listj.h with circular list implementation
//******************************************************************
#include "listj.h"

list::list() {
  head = NULL;
  tail = NULL;
  numberofelements = 0;
}

list::list(list *inList) {
  head = NULL;
  tail = NULL;
  numberofelements = 0;
  node *next = inList->head;
  while(next != inList->tail) {
    insertElement(next->item);
    next = next->next;
  }
  insertElement(inList->tail->item);
}

list::list(string fileName) {
  ifstream inFile;
  inFile.open(fileName.c_str());
  assert(inFile.is_open());
  
  head = NULL;
  tail = NULL;
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
  while (head!=NULL) {
    deleteElement(head->item); //delete next element
  }
}

//list operations
//Steps through the list and displays all the elements.
void list::displayList() const {
  node *next = head;
  while(next != tail) {
    cout<<next->item<<endl;
    next = next->next;
  }
  cout<<tail->item<<endl;
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
  
  if (current == NULL) { //Inserting into empty list
    head = temp;
    tail = temp;
    temp->next = temp;
  } 
  else if(element <= head->item) { //Inserting into new Head
    temp->next = head;
    head = temp;
    tail->next = head;
  }
  else if(element >= tail->item) { //Inserting into new Tail
    tail->next = temp;
    temp->next = head;
    tail = temp;
  }
  else { //Inserting into middle
    while(true) {
      if(current->item >= element) {
	previous->next = temp;
	temp->next = current;
	break;
      }
      previous = current;
      current = current->next;
    }
	}
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
  
  if(current != NULL && current->item == element) { //Removes head
    if(head == tail) { //Check for size 1
      head = NULL;
      tail = NULL;
    } 
    else {
      tail->next = head->next;
      head = head->next;
    }
    delete(current);
    value = true;
    numberofelements--;
  }
  else {
    previous = current;
    current = current->next;
    while(current != head) { //checks for head if full loop
      if(current->item == element) {
	if(current == tail) {
	  tail = previous;
	}
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

int list::Josephus(int m) {
  node *current, *temp;
  current = head;
  while(numberofelements != 1) {
    for(int x = 0; x < m; x++) {
      current = current->next;
    }
    cout<<"Deleting "<<current->item<<endl;
    temp = current->next;
    deleteElement(current->item);
    current = temp;
  }
  return current->item;
}
//Returns the value of the number of elements in the list.
int list::numberOfElements() const {
  return(numberofelements);
}
