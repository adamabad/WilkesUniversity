//******************************************************************
// File: graph.cpp
// Author: Adam Abad
// Date: 4/30/2019
// Program Name: Graphs
//******************************************************************

// ********************************************************
// Implementation file graph.cpp for the the Graph Class.
// ********************************************************

#include "graph.h"

graph::graph() {
  n = 0;
  head = NULL;
  cycle = false;
  cout<<"How many nodes will be in the graph? ";
  cin>>n;
  cout<<"\nAllocating an array sized "<<n<<"\n\n";
  array = new node*[n];
  for(int x = 0; x < n; x++) {
    array[x] = NULL;
  }
  while(true) {
    char option;
    cout<<"Enter an edge? (Y = yes, N = no) ";
    cin>>option;
    cout<<endl;
    cout<<"You entered: "<<option<<endl;
    if(option == 'n' || option == 'N') {
      break;
    }
    else if(option == 'y' || option == 'Y') {
      int n1,n2;
      node *newNode;
      newNode = new node;
      
      cout<<"Creating new edge.\n";
      cout<<"Enter an integer from 0 to "<<n-1<<" for the parent";
      n1 = edgeEnter(n);
      cout<<"\nParent: "<<n1<<endl;
      cout<<"Enter an integer from 0 to "<<n-1<<" for the child";
      n2 = edgeEnter(n);
      cout<<"\nChild:   "<<n2<<endl;
      
      newNode->name = n2;
      if(array[n1] == NULL) {
	array[n1] = newNode;
      }
      else {
	newNode->next = array[n1];
	array[n1] = newNode;
      }
    }
    else {
      cout<<"Invalid Option.\n";
    }
  }
  cout<<"Constructor Ending, checking adjacency list: \n";
  for(int x = 0; x < n; x++) {
    cout<<"Adjacency List for "<<x<<endl;
    node *search;
    search = array[x];
    while(search != NULL) {
      cout<<"Adjacent to: "<<search->name<<endl;
      search = search->next;
    }
  }
  cout<<endl;
}

int graph::edgeEnter(int n) {
  int x;
  while(true) {
    cin>>x;	
    if(x >= n) {
      cout<<"\nNode too large for graph, please reenter.\n";
      cin.clear();
      cin.ignore(120,'\n');
    }
    else {
      return x;
    }
  }
}

graph::graph(const graph &inGraph) {
  n = inGraph.n;
  cout<<"n = "<<n<<endl;
  array = new node*[n];
  cycle = false;
  head = NULL;
  for(int x = 0; x < n; x++) {
    node *search, *previous;
    search = inGraph.array[x];
    if(search != NULL) { //Insert First
      node *newNode = new node;
      newNode->name = search->name;
      newNode->next = NULL;
      search = search->next;
      previous = newNode;
      array[x] = newNode;
    }	
    while(search != NULL) { //Insert Sequence
      node *newNode = new node;
      newNode->name = search->name;
      newNode->next = NULL;
      search = search->next;
      previous->next = newNode;
      previous = newNode;
    }
  }
}

graph::~graph() {
  node *search,*current;
  for(int x= 0; x < n;x++) {
    search = array[x];
    while(search != NULL) {
      current = search;
      search = search->next;
      delete(current);
    }
  }
  search = head;
  while(search != NULL) {
    current = search;
    search = search->next;
    delete(current);
    head = NULL;
  }
  delete(array);
}

bool graph::depth(int V) {
  if(V >= n) {
    return false;
  }
  else {
    cycle = false; //Cycle to False
    if(head != NULL) { //Empties Topological Sort List
      node *search, *current;
      search = head;
      while(search != NULL) {
	current = search;
	search = search->next;
	delete(current);
      }
      head = NULL;
    }
    int visited[n];
    for(int x = 0; x < n;x++) {
      visited[x] = 0;
    }
    for(int x = V; x < n;x++) {
      if (visited[x] == 0) {
	DFS_Visit(x, visited);
      }
    }
    for(int x = 0; x < V; x++) {
      if (visited[x] == 0) {
	DFS_Visit(x, visited);
      }
    }
    return true;
  }
}

bool graph::DFS_Visit(int x, int *visited) {
  cout<<"DFS_Visit visiting: "<<x<<endl;
  visited[x] = 1;
  node* search;
  search = array[x];
  while(search != NULL) {
    if(visited[search->name] == 0) {
      DFS_Visit(search->name, visited);
    }
    else if(visited[search->name] == 1) {
      cycle = true;
    }
    search = search->next;
  }
  visited[x] = 2;
  if(cycle != true) {
    node *newNode = new node;
    newNode->name = x;
    newNode->next = NULL;
    search = head;
    if(search == NULL) {
      head = newNode;
    }
    else {
      newNode->next = head;
      head = newNode;
    }
  }
  return true;
}

bool graph::breadth(int V) {
  if(V >= n) {
    return false;
  }
  else {
    node *queue, *newNode, *search, *tail, *temp;
    int visited[n]; 
    
    for(int x = 0; x < n; x++) {
      visited[x] = 0;
    }
    newNode = new node;
    newNode->name = V;
    newNode->next = NULL;
    queue = tail = newNode;
    visited[V] = 1;
    cout<<"BFS Visiting: "<<V<<endl;
    while(queue != NULL) {
      search = array[queue->name];
      while(search != NULL) {
	//debuging
	//for(int x = 0; x < n; x++) {
	//  cout<<visited[x];
	//}
	//cout<<endl;
	//debugging end
	if(visited[search->name] != 1) {
	  visited[search->name] = 1;
	  cout<<"BFS Visiting: "<<search->name<<endl;
	  newNode = new node;
	  newNode->name = search->name;
	  newNode->next = NULL;
	  tail->next = newNode;
	  tail = newNode;
	}
	search = search->next;
      }
      temp = queue;
      queue = queue->next;
      delete(temp);
    }
    return true;
  }
}

bool graph::topo() {
  cout<<"Topological Sort calling DFS...\n";
  depth(0);
  if(cycle == false) {
    cout<<"\nTopological Sort Results: \n";
    node *search;
    search = head;
    while(search != NULL) {
      cout<<"next node is "<<search->name<<endl;
      search = search->next;
    }
  }
  else {
    cout<<"Cycle detected, unable to topological sort.\n";
  }
  return false;
}
