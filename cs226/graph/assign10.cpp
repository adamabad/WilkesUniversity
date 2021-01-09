//******************************************************************
// File: assign10.cpp
// Author: Adam Abad
// Date: 4/30/19
// Program Name: Graphs
//
// Graphs uses an array of nodes to simluate a graph with 
//  directional edges. This program is menu driven and will output
//  the depth-first search, topological sort, and the breadth-first
//  search.
// 
// The Program has been tested and works properly, both DFS and BFS search
//  work. The implementation of BFS uses a queue, however does not implement a
//  queue class. The queue used in place of the queuei.h and queuei.cpp is a 
//  linked list with head and tail pointers. To satisfy the complier, a blank
//  queuei.h and queuei.cpp are included.
//******************************************************************

//******************************************************************
// Driver program for The Graph Program
// Uses a for loop to insert data, then uses a menu for several options
//******************************************************************

#include "graph.h"
#include <string>

using namespace std;


void header() {
  cout<<"\nName: Adam Abad\n";
  cout<<"Graphs\n";
  cout<<"Uses an array of pointers to represent a graph and perform actions to it.\n\n";
}

void menu() {
  cout<<"1. Depth First Search.\n";
  cout<<"2. Topological Sort.\n";
  cout<<"3. Breadth-First Search.\n";
  cout<<"4. Exit.\n\n";
}

int getOption() {
  int x;
  while(true) {
    cout<<"Please enter an Option: ";
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

string dfs(graph *thisGraph) {
  cout<<"Executing Depth-First Search: \n";
  int x = 0;
  cout<<"Enter an item to start the DFS: ";
  cin>>x;
  cout<<"\nStarting DFS at "<<x<<"...\n";
  bool success = thisGraph->depth(x);
  if(success) {
    cout<<"Depth-First Search for "<<x<<" was successful.\n\n";
  }
  else {
    cout<<"Unable to Depth-First Search for "<<x<<".\n\n";
  }
  return "";
}

string topo(graph *thisGraph) {
  cout<<"Executing Topological Sort: \n";
  thisGraph->topo();
  cout<<endl;
  return "";
}

string bfs(graph *thisGraph) {
  cout<<"Executing Breadth-First Search: \n";
  int x = 0;
  cout<<"Enter an item to start the BFS: ";
  cin>>x;
  cout<<"\nStarting BFS at "<<x<<"...\n";
  bool success = thisGraph->breadth(x);
  if(success) {
    cout<<"Breadth-First Search for "<<x<<" was successful.\n\n";
  }
  else {
    cout<<"Unable to Breadth-First Search for "<<x<<".\n\n";
  }
  return "";
}
int main() {
  header();
  graph thisGraph;
  int option = -1;
  while(option != 4) {
    menu();
    option = getOption();
    if(option > 4 or option < 1) {
      cout<<option<<" is not a valid option, please enter another option.\n\n";
    }
    else {
      cout<<"You chose option "<<option<<"\n\n";
      switch(option) {
      case 1: dfs(&thisGraph);
	break;
      case 2: topo(&thisGraph);
	break;
      case 3: bfs(&thisGraph);
	break;
      case 4: break;
      default: cout<<"Error in option: "<<option<<endl;
      }
    }
  }
  cout<<"Copying Graph...\n";
  graph graph2 = thisGraph;
  cout<<"Executing DFS at 0 for Graph 2.\n";
  graph2.depth(0);
}
