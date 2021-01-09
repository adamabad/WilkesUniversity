//******************************************************************
// File: assign61.cpp
// Author: Adam Abad
// Date: 3/19/2019
// Program Name: Queues
// Assignment 6
//
// Queues uses a circular linked list to implement a queue. This 
// program adds integer data from a file, sums the values, and 
// calculates the average of the data. After the average is calculated,
// the queue is reorganized such that the original queue is not changed.
//
// I have tested the program and it works properly.
//******************************************************************

#include<fstream>
#include<cassert>
#include<iostream>
#include"queuei.h"
#include<string>

int sum(queueClass* queue1) {
  int item, total;
  queueClass queue2;
  total = 0;
  bool success = true;
  bool successThrow = true;
  while(success) {
    queue1->QueueDelete(item, success);
    if(success) {
      total = total + item;
      queue2.QueueInsert(item, successThrow);
    }
  }
  success = true;
  while(success) {
    queue2.QueueDelete(item, success);
    if(success) {
      queue1->QueueInsert(item, successThrow);
    }
  }
  return total;
}

void header() {
  cout<<"\nName: Adam Abad\n";
  cout<<"Queues\n";
  cout<<"Queues uses and circular singly linked list to implement a queue.\n\n";
}

int main() {
  header();
  string fn;
  ifstream fin;
  int newitem, total;
  double average;
  bool success;
  total = 0;
  queueClass queue1;
  cout<<"please enter the name of the file containing your data"<<endl;
  cin>>fn;
  cout<<"\nThe file name entered is "<<fn<<endl;
  fin.open(fn.c_str());
  assert(fin.is_open());
  while(true) {
    fin>>newitem;
    if(fin.eof()) {
      break;	
    }
    cout<<"About to insert "<<newitem<<" into the queue "<<endl;
    queue1.QueueInsert(newitem, success);
  }//end of input loop
  queue1.QueuePrint(); //Print Before Sum/Average
  cout<<endl;
  if(!queue1.QueueIsEmpty()) {
    //calculate sum and average
    total = sum(&queue1);
    average = (double)total / (double)queue1.NumberOfQueueElements();
  }
  else {
    //empty queue
    cout<<"The Queue is Empty\n";
    total = average = 0;
  }
  
  cout<<"The Sum is    : "<<total<<endl;
  cout<<"The Average is: "<<average<<"\n\n";
  
  queue1.QueuePrint(); //Final Print
}//end of main
