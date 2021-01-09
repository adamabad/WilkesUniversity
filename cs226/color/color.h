//*********************************************************
// File: color.h
// Author: Adam Abad
// Date: 5/2/2019
// Program Name: Graph Coloring
//*********************************************************

// ********************************************************
// Header file color.h for the Color Class.
// ********************************************************

#include<cassert>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;
typedef int nodetype; 

struct node { 
  nodetype name; 
  node *next; 
}; 
struct inDegree{ 
  nodetype nodename; 
  int indegreeOfNode; 
}; 
class color {
 public:
  color(); //Constructor
  ~color(); //Destructor
  //Class functions
  int Colorit();
  void Printcolor();
 private:
  node** adjacency;
  inDegree** inDegreeList;
  int* colorArray;
  int size;
  void InsertionSort();
};
