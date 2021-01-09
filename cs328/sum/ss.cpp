//******************************************************************
// File: ss.cpp
// Author: Adam Abad
// Date: 10/24/20
// Program Name: Sum of Subsets
//
// Sum of Subsets utilized algorithm 5.4 to find subsets within a larger set
//  that, when added, equal a specific value. This version of the code removes
//  global variables aside from a count variable which is not used in calculations.
//  
// I have test the code below and it does work correctly.
//  *Aid from Prof. Bracken in diagnosing a bug in the read loop
//******************************************************************

#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;


// Global variable count to count the number of times promising is called.
int count = 0;

// Header function, prints name and program title.
void header() {
    cout<<"Name: Adam Abad\n";
    cout<<"Analysis of the Sum of Subsets Algorithm\n";
    cout<<"P224 Algorithm 5.4\n\n";
}

// Promising returns a boolean value denoting if the path indicated contains a promising solution
//  'Promising' is defined as a path that could contain a subset solution for the given paramenters
//  In this algorithm, if the remaining indicies are greater or equal to the searched W, or
//  the current total is equal to OR the current total + the next element is lessthan or equal to
//  the searched W value, than the path is considered promising. 

bool promising(int i, int weight, int total, int* w, int W) {
    count++;                          //Increment global 'count' each time promising is called.
    return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}

// sum_of_subsets is a modification of algorithm 5.4 found on p224 of the test.
// This version does not rely on global variables W, w, include, or n. To handle the
// global variable version, this iteration of the algorithm passes the values as arguements.
// include and w are treated as array pointers to preserver their data across the paths.
// i is index of the current value being considered.
// weight is the current total of the values being added
// total is the total (or remaining total) of values left in the array
// W is the sum being searched for
// include is a string array used to tell the user which values are included in the subset
// w is an integer array that holds all the values initial array for the problem

void sum_of_subsets(int i, int weight, int total, int W, string *include, int *w) {
    if(promising(i, weight, total, w, W)) {
        if(weight == W) {
            //Solution Found
            cout<<"\nSolution found for W = "<<W<<endl;
            for(int x = 1; x <= i; x++) {
                cout<<w[x]<<" "<<include[x]<<endl;
            }
        }
        else {
            include[i + 1] = "yes";
            sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1], W, include, w);
            include[i + 1] = "no";
            sum_of_subsets(i + 1, weight, total - w[i + 1], W, include, w);
        }
    }
}

// Main function
int main() {
    
    //Prints the header
    header();

    //Retrieves the name and opens the file
    string fn;
    ifstream myfile;
    cout<<"Enter the name of the file: \n";
    cin>>fn;
    cout<<"Opening: "<<fn<<endl;
    myfile.open(fn);
    //Assert to check if the file opened successfully
    assert(myfile.good());

    //Variable declarations
    int n;                  // n - number of elements in the file
    int W;                  // W - value to be summed up to
    int total;              // total - the sum of all elements in the array
    int *w;                 // w[] - array of values read in from the file in nondecreasing order
    string *include;           // include[] - array of yes/no values to indicate the inclusion of values in the sum
    int inData;             // inData - variable used to read integer values in from the file
    
    //Retrieve n from file
    myfile>>inData;
    if(!myfile.good()) {
        myfile.clear();
        myfile.ignore(120, '\n');
    }
    if(!myfile.eof()) {
        n = inData;         //Assign first value read in as n
        cout<<"\nn = "<<n<<" elements in the array.\n";
    } 
    else {
        cout<<"The file was empty.\n";
        myfile.close();
        return 1;
    }

    //Retrieve W from file
    myfile>>inData;
    if(!myfile.good()) {
        myfile.clear();
        myfile.ignore(120, '\n');
    }
    if(!myfile.eof()) {
        W = inData;         //Assign second value read in as W
        cout<<"W = "<<W<<" sum of elements to be searched\n";
    } 
    else {
        cout<<"Invalid file format, second value needs to be W.\n";
        myfile.close();
        return 1;
    }

    //Initialization of arrays
    w = new int [n + 1];
    include = new string [n + 1];
    for(int x = 1; x <= n; x++) {
        w[x] = 0;
        include[x] = "no";
    }

    //Adding values from file to the array
    int iter = 1;
    while(true) {
        myfile>>inData;
        if(!myfile.good()) {
            myfile.clear();
            myfile.ignore(120, '\n');
        }
        if(myfile.eof()) {
            break;
        }  
        w[iter] = inData;
        iter++;      
    }

    // Echoing values from the array to the user and calculating total
    cout<<"\nThe array: \n";
    for(int x = 1; x <= n; x++) {
        cout<<w[x]<<endl;
        total = total + w[x];
    }
    //cout<<"\nClosing file\n";
    //Close file after finishing data collection
    //myfile.close();
    cout<<"\nCalling sum_of_subsets\n";
    //Calling sum_of_subsets with initial values
    sum_of_subsets(0, 0, total, W, include, w);
    
    //Echo to user the number of times promising was called using global variable 'count'
    cout<<"\nNumber of promising calculations: "<<count<<endl;
}
