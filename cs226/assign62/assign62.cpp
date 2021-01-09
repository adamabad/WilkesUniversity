//******************************************************************
// File: assign62.cpp
// Author: Adam Abad
// Date: 3/19/19
// Program Name: Array Based Queue
// Assignment 6
//
// Array - Queue uses a dynamically allocated array to implement a queue
// system. This variation carries all the functions from the pointer-based
// system. Data is manually added to this array, and can be edited by a menu
// system.
// 
// I have tested this code and it works properly.
//******************************************************************


#include<iostream>
#include"queuea.h"
#include<string>
#include<stdlib.h>
using namespace std;

void menu() {
  cout<<"1. Enqueue Data.\n";
  cout<<"2. Dequeue Data and Print.\n";
  cout<<"3. Print Front without Dequeue.\n";
  cout<<"4. Print Queue.\n";
  cout<<"5. Print Empty or Non Empty.\n"; 
  cout<<"6. Exit.\n\n";
}

void header() {
  cout<<"\nName: Adam Abad\n";
  cout<<"Array Based Queue\n";
  cout<<"Uses a Dynamically allocated array to represent a queue.\n\n";
}

//Cleans cin if cin takes invalid input, returns integers
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

string enqueue(queueClass *queue) {
  int x;
  bool success;
  while(true) {
    cout<<"Please enter an integer to enqueue: ";
    cin>>x;
    cout<<endl;
    if(cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, please enter an integer.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  queue->QueueInsert(x, success);
  if(success) {
    cout<<x<<" was successfully inserted.\n";
  }
  else {
    cout<<x<<" was unable to be inserted.\n";
  }
  return "";
}
string dequeue(queueClass *queue) {
  int item;
  bool success;
  queue->QueueDelete(item, success);
  if(success) {
    cout<<item<<" was removed.\n";
  }
  else {
    cout<<"Unable to remove an item.\n";
  }
  return "";
}
string printFront(queueClass *queue) {
  int item;
  bool success;
  queue->GetQueueFront(item, success);
  if(success) {
    cout<<item<<" is at the front of the queue.\n";
  }
  else {
    cout<<"Unable to get the front of the queue.\n";
  }
  return "";
}
string printAll(queueClass *queue) {
  queue->QueuePrint();
  cout<<"\n";
  return "";
}
string isEmpty(queueClass *queue) {
  if(queue->QueueIsEmpty()) {
    cout<<"The queue is empty.\n";
  }
  else {
    cout<<"The queue is not empty.\n";
  }
  return "";
}

int main() {
  header();
  
  queueClass queue;
  int option = -1;
  while(option != 6) {
    menu();
    option = getOption();
    if(option < 0 or option > 6) {
      cout<<option<<" is not a valid option, please enter another option.\n\n";
    }
    else {
      cout<<"You chose option "<<option<<"\n\n";
      switch(option) {
      case 1: enqueue(&queue);
	break;
      case 2: dequeue(&queue);
	break;
      case 3: printFront(&queue);
	break;
      case 4: printAll(&queue);
	break;
      case 5: isEmpty(&queue);
	break;
      case 6:  
	cout<<"Exiting...\n";
	break;
      default: cout<<"Error in option: "<<option<<endl;
      }
    }
  } 
}
