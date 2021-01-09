//******************************************************************
// File: color.cpp
// Author: Adam Abad
// Date: 5/2/2019
// Program Name: Graph Coloring
// https://www.thecrazyprogrammer.com/2014/12/insertion-sort.html
// Used for implementing the sort algorithm
//******************************************************************

// ********************************************************
// Implementation file color.cpp for the the color Class.
// ********************************************************

#include "color.h"

color::color() {
  string fn;
  cout<<"Enter the file name: ";
  cin>>fn;
  cout<<endl;
  ifstream inFile;
  inFile.open(fn.c_str());
  assert(inFile.is_open());
  cout<<"The file "<<fn<<endl;
  int node1, node2;
  inFile>>size;
  cout<<"N = nodes in graph. . . n = "<<size<<endl;
  
  adjacency = new node*[size];
  inDegreeList = new inDegree*[size];
  colorArray = new int[size];
  
  for(int x = 0; x < size; x++) {
    adjacency[x] = NULL;
    inDegree* newIn;
    newIn = new inDegree;
    newIn->nodename = x;
    newIn->indegreeOfNode = 0;
    inDegreeList[x] = newIn;
    colorArray[x] = 0;
  }
  
  while(true) {
    inFile>>node1;
    if(inFile.eof()) {
      break;
    }
    if(!inFile.good()) {
      inFile.clear();
      inFile.ignore(120, '\n');
    }
    inFile>>node2;
    if(!inFile.good()) {
      inFile.clear();
      inFile.ignore(120, '\n');
    }
    node *inNode1, *inNode2;
    inNode1 = new node;
    inNode2 = new node;
    inNode1->name = node2;
    inNode2->name = node1;
    inNode1->next = inNode2->next = NULL;
    if(adjacency[node1] == NULL) {
      adjacency[node1] = inNode1;
    }
    else {
      inNode1->next = adjacency[node1];
      adjacency[node1] = inNode1;
    }
    if(adjacency[node2] == NULL) {
      adjacency[node2] = inNode2;
    }
    else {
      inNode2->next = adjacency[node2];
      adjacency[node2] = inNode2;
    }
    inDegreeList[node1]->indegreeOfNode++;
    inDegreeList[node2]->indegreeOfNode++;
  }
  inFile.close();
  cout<<"Constructor checking adjacency list: \n";
  node *search;
  for(int x = 0; x < size; x++) {
    search = adjacency[x];
    cout<<"Adjacency List of "<<x<<endl;
    while(search != NULL) {
      cout<<"Next node in the list: "<<search->name<<endl;
      search = search->next;
    }
  }
  cout<<"Constructor checking the indegree list: \n";
  for(int x = 0; x < size; x++) {
    cout<<"Node Name: "<<x<<" ";
    cout<<"Indegree: "<<inDegreeList[x]->indegreeOfNode<<endl;
  }
}


color::~color() {
  //To Destroy: adjacency, inDegreeList, colorArray
  cout<<"Destructor Executing.\n";
  delete(colorArray);
  for(int x = 0; x < size; x++) {
    delete(inDegreeList[x]);
  }
  delete(inDegreeList);
  node *search, *temp;
  for(int x = 0; x < size; x++) {
    search = adjacency[x];
    while(search != NULL) {
      temp = search;
      search = search->next;
      delete(temp);
    }
  }
  delete(adjacency);
}
int color::Colorit() {
  int colors = 1;
  int currentInDegree = 0;
  bool colored, loopColor, nodeAdjacent = false;
  // colored Tracks if the entire graph is colored
  // loopColor tracks if the while loop colored a node. If so, the loop increments
  //  colors at the end
  // nodeAdjacent tracks if a node is adjacent to the current coloring or current node.
  node *search;
  cout<<"Sorting by inDegree...\n";
  InsertionSort();
  cout<<"ColorIt printing the sorted degree list: \n";
  for(int x = 0; x < size; x++) { 
    cout<<"Node Name: "<<inDegreeList[x]->nodename<<" ";
    cout<<"Indegree: "<<inDegreeList[x]->indegreeOfNode<<endl;
  }
  cout<<"Coloring the graph.\n";
  while(colored == false) { //Full while for all nodes to be colored
    int currentNode = inDegreeList[currentInDegree++]->nodename;	
    loopColor = false; //Tracks if loop colored a node
    if(colorArray[currentNode] == 0) { //Checks if current node is colored
      colorArray[currentNode] = colors;
      loopColor = true;
    }
    for(int x = 0; x < size; x++) { //Assigns current color to all non-adjacent nodes
      if(colorArray[x] == 0) {
	search = adjacency[currentNode]; //Sets Search to current node's adjacency
	nodeAdjacent = false;
	while((search != NULL) && nodeAdjacent == false) {
	  if(x == search->name) {
	    nodeAdjacent = true;
	  }
	  search = search->next;
	}
	search = adjacency[x];
	while((search != NULL) && nodeAdjacent == false) {
	  if(search->name != currentNode) { //Ignore Current Node
	    if(colorArray[search->name] == colors) {
	      nodeAdjacent = true;
	    }
	  }
	  search = search->next;
	}
	if(nodeAdjacent == false) { //If the node is not in the adjecent list, colors current color
	  colorArray[x] = colors;
	  loopColor = true;
	}				
      }
    }
    if(loopColor == true) {
      colors++; //Only Increments colors if this loop colored a node.
    }
    colored = true;
    for(int x = 0; x < size; x++) { //Checks to see if each vertex is colored
      if(colorArray[x] == 0) {
	colored = false;
      }
    }
  }
  return colors - 1;
}


void color::InsertionSort() {
  inDegree* current;
  for(int x = 1; x < size; x++) {
    current = inDegreeList[x];
    int i = x - 1;
    while((i >= 0) && (current->indegreeOfNode > inDegreeList[i]->indegreeOfNode)) {
      inDegreeList[i + 1] = inDegreeList[i];
      i = i - 1;
    }
    inDegreeList[i + 1] = current;
    // Debugging
    //for(int x = 0; x < size; x++) {
    //	cout<<inDegreeList[x]->indegreeOfNode;
    //}
    //cout<<endl;
  }
}

void color::Printcolor() {
  for(int x = 0; x < size; x++) {
    cout<<"Node: "<<x<<" Color: "<<colorArray[x]<<endl;
  }
}
