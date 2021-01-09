//******************************************************************
// File: assign2.cpp
// Author: Adam Abad
// Date: 10/18/20
// Program Name: Shortest Path
// Uses a class to represent a directed, weighted graph as arrays and nodes.
// Uses functions and private functions to demonstrate various search algorithms.
//
// The code supplied works properly.
//******************************************************************

//******************************************************************
// main driver for Shortest Path algorithm
//******************************************************************

#include "shortest.h"
#include <string>

using namespace std;

void menu() {
    cout<<"Enter 1 for Dijkstra's shortest path\n";
    cout<<"Enter 2 for Floyd's shortest path\n";
    cout<<"Enter 3 to exit\n";
}

void header() {
    cout<<"\nShortest Path by Adam Abad";
    cout<<"\nUses a set of matricies and implements Dijkstra's and Floyd's shortest paths algorithms.\n\n";
}

int main() {
    header();
    shortest myShort;
    int option = 0;
    while(option != 3) {
        menu();
        while(true) {
            cout<<"Enter an option: ";
            option = myShort.getInt();
            if(option > 3 || option < 1) {
                cout<<"You entered: "<<option<<endl;
                cout<<"Please enter an integer from 1 to 3\n\n";
            }
            else {
                cout<<"You entered: "<<option<<endl;
                break;
            }
        }
        switch (option) {
            case 1:
                cout<<"You selected Dijkstra's shortest path.\n";
                myShort.dijkstra();
                break;
            case 2:
                cout<<"You selected Floyd's shortest path.\n";
                myShort.floyd2();
                break;
            case 3:
                cout<<"Exiting.\n";
                break;
            default:
                break;
        }
    }
}
