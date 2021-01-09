//******************************************************************
// File: shortest.cpp
// Author: Adam Abad
// Date: 10/18/20
// Program Name: Shortest Path
// Uses a class to represent a directed, weighted graph as arrays and nodes.
// Uses functions and private functions to demonstrate various search algorithms.
//******************************************************************

//******************************************************************
// Class file for shortest
//******************************************************************

#include "shortest.h"

shortest::shortest() {
    cout<<"How many vertices are in the graph?\n\n";
    n = getInt();
    cout<<"Number of vertices entered = "<<n<<endl;

    //Initalization of W, P, D
    w = new int*[n];
    p = new int*[n];
    d = new int*[n];
    f = NULL;

    for(int x = 0; x < n; x++) {
        w[x] = new int[n];
        p[x] = new int[n];
        d[x] = new int[n];
    }

    //Setting up intial W matrix and 0ing P and D.
    for(int x = 0; x < n; x++) {
        for(int i = 0; i < n; i ++) {
            w[x][i] = INF;
            p[x][i] = 0;
            d[x][i] = 0;
        }
    }
    //Sets the diagonal to 0
    for(int x = 0; x < n; x++) {
        w[x][x] = 0;
    }

    //Loop to ask user for edges in the graph.
    char flag = 'Y';
    cout<<"Enter 'Y' to enter a node, 'N' to stop.\n";
    cin>>flag;    
    int parent = 0;
    int child = 0;
    int weight = 0;
    while(flag == 'Y' || flag == 'y') {
        cout<<"Enter an integer from 1 to "<<n<<" as the parent: \n";
        parent = getInt();
        while(parent > n || parent < 1) {
            cout<<"You entered: "<<parent<<endl;
            cout<<"Invalid parent node, please enter another parent value: \n";
            parent = getInt();
        }
        cout<<"Parent Node: "<<parent<<endl;
        cout<<"Enter an integer from 1 to "<<n<<" as the child: \n";
        child = getInt();
        while(child > n || child < 1) {
            cout<<"You entered: "<<child<<endl;
            cout<<"Invalid child node, please enter another child value: \n";
            child = getInt();
        }
        cout<<"Child Node: "<<child<<endl;
        cout<<"Enter an integer to represent the weight of the edge: \n";
        weight = getInt();
        cout<<"Node Weight: "<<weight<<endl;

        //Setting the W matrix value (-1 for offset)
        w[parent - 1][child - 1] = weight;
        cout<<"Enter 'Y' to enter a node, 'N' to stop.\n";
        cin>>flag;
    }
    cout<<"Here is the adjacency matrix: \n";
    
    //Displays the adjacency matrix to the user.
    for(int x = 0; x < n; x++) {
        for(int i = 0; i < n; i++) {
            cout<<"    "<<w[x][i];
        }
        cout<<endl;
    }
}

shortest::~shortest() {
    cout<<"Destructor Executing.\n";

    delete(w);
    delete(d);
    delete(p);
    
    edgenode *search, *temp;
    search = f;
    while(search != NULL) {
        temp = search;
        search = search->next;
        delete(temp);
    }     
    f = NULL;
}

void shortest::dijkstra() {
    cout<<"Enter a starting vertex: \n";
    int v = getInt();
    while(v > n || v < 0) {
        cout<<"You entered: "<<v<<endl;
        cout<<"Please enter a value from 1 - "<<n<<endl;
        v = getInt();
    }
    cout<<"You entered: "<<v<<endl;
    cout<<"Executing Dijkstra's shortest path with vertex V"<<v<<endl;
    
    int i, min;
    int vnear = 0;
    int touch[n + 1];                    //Generates array with indicies 0 to n
    int length[n + 1];                   //Generates array with indicies 0 to n
    for(int x = 0; x < n + 1; x++) {
        touch[x] = 0;
        length[x] = 0;
    }                          

    edgenode *search, *temp;             //Nulling F
    search = f;
    while(search != NULL) {
        temp = search;
        search = search->next;
        delete(temp);
    }
    f = NULL;
    for(i = 1; i <= n; i++) {            // For all verticies, initialize V(v) to be the last
        touch[i] = v;                    // vertex on the current shortest path from V(v) 
                                         // (which is the starting vertex here)
        length[i] = w[v - 1][i - 1];     // n - 1 shift as W begins at [0][0]
                                         // Set the weight to the weight from node v to the current node
    }
    
    for(int x = 0; x < (n - 1); x++) {   // add all n - 1 vertices to Y.
        min = INF;                       // Sets the minimum path to infinity
        for(i = 1; i <= n; i++) {        // Check each vertex for having the current shortest path
            if(i != v) {                 // Ignore the starting vertex
                                         // If the current length is the shortest, and NOT -1 (already added),
                                         // update the current min and vnear to the appropriate values.
                if(length[i] > 0 && length[i] <= min) {
                    min = length[i];
                    vnear = i;
                }
            }
        }

        if(min != INF) {
            edgenode *e = new edgenode;
            e->e1 = touch[vnear];         // Sets e.e1 to the vertex indexed by touch[vnear]
            e->e2 = vnear;                // Sets e.e2 to the vertex indexed by touch
            e->next = f;                  // Sets e.next to the current list of nodes
            f = e;                        // adds e to F
        }
        
        for(i = 1; i <= n; i++) {     // Go through each path to see if it contains a new short path, update it
            if(i != v) {              
                if(length[vnear] + w[vnear - 1][i - 1] < length[i]) {
                    length[i] = length[vnear] + w[vnear - 1][i - 1];
                    touch[i] = vnear;
                }
            }
        }
        length[vnear] = -1;          // Add vertex indexted by vnear to Y
    } 

    cout<<"\nF: \n";
    search = f;
    while(search != NULL) {
        cout<<"V"<<search->e1<<" V"<<search->e2<<endl;
        search = search->next;
    }

    cout<<"\nTouch:\n";
    for(i = 1; i <= n; i++) {
        if(i != v) {
            cout<<i<<" "<<touch[i]<<endl;
        }
    }
    cout<<"\nDijkstra Complete.\n";
}

//From p108 in text Algorithm 3.4
// Utilizes a D matrix to find the shortest path by using various
//  intermediate nodes.
void shortest::floyd2() {
    for(int x = 0; x < n; x++) {
        for(int i = 0; i < n; i++) {
            d[x][i] = w[x][i];
        }
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(d[i][k] + d[k][j] < d[i][j]) {
                    p[i][j] = k + 1;
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    cout<<"\nD matrix: \n";
    //Print out D matrix
    for(int x = 0; x < n; x++) {
        for(int i = 0; i < n; i++) {
            cout<<"    "<<d[x][i];
        }
        cout<<endl;
    }
    cout<<"\nP matrix: \n";
    //Print out P matrix
    for(int x = 0; x < n; x++) {
        for(int i = 0; i < n; i++) {
            cout<<"    "<<(p[x][i]);
        }
        cout<<endl;
    }
    
    cout<<"\nPaths: \n";
    //Call to path function to pring the path from each vertex to every other vertex.
    for(int x = 0; x < n; x++) {
        for(int i = 0; i < n; i++) {
            cout<<"Calling path "<<x + 1<<" to "<<i + 1<<endl;
            path(x, i);
            cout<<endl;
        }
    }

    cout<<"Floyd2 Complete.\n";
}

//Implemetned from p109 in text, recursively calls itself to trace the path from
// one node to another. 
void shortest::path(int q, int r) {
    if(p[q][r] != 0) {
        path(q, (p[q][r] - 1));
        cout<<"v"<<p[q][r]<<" ";
        path((p[q][r] - 1), r);
    }
}

int shortest::getInt() {
    int x;
    while(true) {
        cin>>x;
        cout<<endl;
        if(cin.good()) {
            break;
        }
        cout<<"You have entered invalid input, please reenter integer.\n";
        cin.clear();
        cin.ignore(120,'\n');
    }
    return x;
}
