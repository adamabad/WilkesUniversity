//******************************************************************
// File: shortest.h
// Author: Adam Abad
// Date: 10/18/20
// Program Name: Shortest Path
// Uses a class to represent a directed, weighted graph as arrays and nodes.
// Uses functions and private functions to demonstrate various search algorithms.
//******************************************************************

//******************************************************************
// Header file shortest.h for shortest.cpp
//******************************************************************

#include <iostream>
using namespace std;
#define INF 1000000

struct edgenode {
    int e1;
    int e2;
    edgenode* next;
};

class shortest {
    public:
        //Default Constructor and Destructor
        shortest();
        ~shortest();
        
        //Operations
        //Dijkstra takes an integer V from 1 - n (where n is the number of
        // vertices in the graph) And calculates the shortest path from V to every
        //  other vertex in the graph. 
        void dijkstra();

        //Floyd2 is an implementation of algorithm 3.4 from the text. Upon compleation, it calculates the
        // D matrix
        void floyd2();

        //getInt is a function that retrieves an input and checks to see if the input is a valid integer.
        int getInt();
    private:

        //Get the path needed for floyd2
        void path(int q, int r);
        int n;
        int** w;
        int** d;
        int** p;    
        edgenode* f;
};
