//******************************************************************
// File: assign43.cpp
// Author: Adam Abad
// Date: 3/13/19
// Program Name: Josephus Problem
// Assignment 4
//
// Implements a circular list to perform the Josephus game.
// First prompts the user for a size of list, then the step.
// Afterwards, the program steps through the list to find the winner
// with the given parameters.
// 
// I have tested the program and it works properly.
//******************************************************************



//******************************************************************
// Driver program for Josephus Problem
// Uses a for loop to insert data, then asks the user for a value to step.
//******************************************************************



//******************************************************************
// Main driver program for testing listj.cpp
// Uses a Circular list to execute the Josephus problem.
//******************************************************************

#include "listj.h"
#include <string>

using namespace std;

void header() {
  cout<<"\nName: Adam Abad\n";
  cout<<"Josephus Problem\n";
  cout<<"Uses a cicularly singly linked list to perform the Josephus Problem.\n\n";
}

//Cleans cin if cin takes invalid input, returns integers
int getInt() {
  int x;
  while(true) {
    cout<<"Please enter an Integer: ";
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

int main() {
  header();

  cout<<"What size would you like to make the list (n)?\n";
  int n = getInt();
  cout<<"\nThe list will be size "<<n<<endl;
  list josephus;
  for(int x = 1; x <= n; x++) {
    josephus.insertElement(x);
  }
  cout<<"The list is: \n";
  josephus.displayList();

  cout<<"What step would you like to use (m)?\n";
  int m = getInt();
  cout<<"\nThe size of the step chosen will be "<<m<<endl;

  int winner = josephus.Josephus(m);
  cout<<"With n = "<<n<<" and m = "<<m<<", the winner is "<<winner<<endl;
}
