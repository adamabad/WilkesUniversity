//******************************************************************
// File: assign41.cpp
// Author: Adam Abad
// Date: 2/20/19
// Program Name: List
// Assignment 3
//
// List uses a singly linked list to order integer data inputs
// from a user. The data can be manipulated by a menu driven option
// menu. After a user inputs the correct option from the menu, 
// the program displays guidance messages for their choice.
//
// I have tested the program and it works properly.
//******************************************************************



//******************************************************************
// Main driver program for testing list.cpp
// Uses a linked list to order input data.
//******************************************************************

#include "list.h"
#include <string>

using namespace std;

void menu() {
	cout<<"1. Display the list.\n";
	cout<<"2. Find an item in the list.\n";
	cout<<"3. Insert an item into the list.\n";
	cout<<"4. Delete an item from the list.\n";
	cout<<"5. Display number of elements in the list.\n";
	cout<<"6. Exit.\n\n";
}

void header() {
	cout<<"\nName: Adam Abad\n";
	cout<<"Introduction to Linked Lists\n";
	cout<<"List uses a simple singly linked list to order data.\n\n";
}

//Cleans cin if cin takes invalid input, returns integers
int getOption() {
	int x;
	while(true) {
		cout<<"Please enter your Option: ";
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

//Prompts the user for an item to search for, displays the position or if it was unable to be found.
string findItem(list* thislist) {
	int x;
	while(true) {
		cout<<"Please enter an integer to search for: ";
		cin>>x;
		cout<<endl;
		if(cin.good()) {
			break;
		}
		cout<<"You have not entered a valid integer, please reenter.\n";
		cin.clear();
		cin.ignore(120,'\n');
	}
	int place = thislist->findElement(x);
	if(place == 0) {
		cout<<"The element "<<x<<" is not in the list.\n\n";
	}
	else {
		cout<<"The element "<<x<<" is in position "<<place<<" in the list.\n\n";
	}
	return "";
}

//Promts the user for an item to add to the list.
string insertItem(list* thislist) {
	int x;
	while(true) {
		cout<<"Please enter an integer to add to the list: ";
		cin>>x;
		cout<<endl;
		if(cin.good()) {
			break;
		}
		cout<<"You have not entered a valid integer, please reenter.\n";
		cin.clear();
		cin.ignore(120,'\n');
	}
	thislist->insertElement(x);
	return "";
}

//Promts the user for an item to be deleted. If found the item is deleted, otherwise and error message is displayed.
string deleteItem(list* thislist) {
	int x;
	while(true) {
		cout<<"Please enter an integer to remove from the list: ";
		cin>>x;
		cout<<endl;
		if(cin.good()) {
			break;
		}
		cout<<"You have not entered a valid integer, please reenter.\n";
		cin.clear();
		cin.ignore(120,'\n');
	}
	bool success = thislist->deleteElement(x);
	if(success) {
		cout<<x<<" was successfully removed from the list.\n\n";
	}
	else {
		cout<<x<<" was not in the list, could not remove value.\n\n";
	}
	return "";
}

int main() {
	list thislist;  
	header();
	int option = -1;
	while(option != 6) {
		menu();
		option = getOption();
		if(option > 6 or option < 1) {
			cout<<option<<" is not a valid option, please enter another option.\n\n";
		}
		else {
			cout<<"You chose option "<<option<<"\n\n";
			switch(option) {
				case 1: thislist.displayList();
					break;
				case 2: findItem(&thislist);
					break;
				case 3: insertItem(&thislist);
					break;
				case 4: deleteItem(&thislist);
					break;
				case 5: 
					cout<<"There are "<<thislist.numberOfElements()<<" element(s) in the list.\n\n";
					break;
				case 6: break;
				default: cout<<"Error in option: "<<option<<endl;
			}
		}
	}
}
