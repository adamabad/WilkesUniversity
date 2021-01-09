//*********************************************************
// File: graph.h
// Author: Adam Abad
// Date: 4/30/2019
// Program Name: Graphs
//*********************************************************

// ********************************************************
// Header file graph.h for the Graph Class.
// ********************************************************

#include<iostream>
#include<string>

using namespace std;
struct node {
  int name;
  node *next;
};
class graph {
 public:
  graph(); //Constructor
  graph(const graph &inGraph); //Copy Constructor
  ~graph(); //Destructor
  
  //Graph Operations
  bool depth(int V);
  // Deapth First Search
  // Takes an integer V and performs a 
  // depth-first search of the current graph
  // using the given node as the origin.
  bool breadth(int V);
  // Breadth First Search
  // Takes an integer V and performs a 
  // breadth-first search of the current graph
  // using the given node as the origin.
  bool topo();
  // Topological Sort
  // sorts the graph into its topological sort
  // Creates a linked list stored in private to store the
  // topological sort.
 private:
  int edgeEnter(int x);
  int n;
  bool cycle;
  bool DFS_Visit(int x, int *visited);
  node** array;
  node* head;
};
