//******************************************************************
// File: assign2.cpp
// Author: Adam Abad
// Date: 2/10/19
// Program Name: Collection
// Assignment 2
// Collection uses a template class to set up a generic array 
//      and perform various actions to alter data in it.
// Collection sets up two arrays then promts the user for an 
//      action using the option menu. Then, the corresponding 
//      message will appear and promt the user for aditional 
//      input regarding their choice.
// Resources used:
//      https://en.cppreference.com/w/cpp/language/switch for switch syntax
//		http://www.cplusplus.com/forum/beginner/83884/ for return void issues in functions that 
// 		use cout.
// 
// I have tested my code and it contains errors that I was unable to locate as follows:
//      Overloading '=' and '=='
//           I have coded the overloads to the best of my ability however, I was unable
//           to get them to activate or return proper values to the driver program. I have
//           tried to place testing cout statements to confirm activation and was unable
//           to get the operation functions to fire. Otherwise, I have included the proper
//           output if statements for the proper return values.
//
//******************************************************************



//******************************************************************
// Main driver program for testing collection.cpp
// Sets up two interger arrays using collection
//******************************************************************

#include "collection.h"
#include <string>

void menu() {
  cout<<"1.  Add an item to Collection 1.\n";
  cout<<"2.  Add an item to Collection 2.\n";
  cout<<"3.  Remove an item from Collection 1.\n";
  cout<<"4.  Remove an item from Collection 2.\n";
  cout<<"5.  Display Collection 1\n";
  cout<<"6.  Display Collection 2.\n";
  cout<<"7.  Check if Collection 1 is equal to Collection 2.\n";
  cout<<"8.  Set Collection 1 to Collection 2.\n";
  cout<<"9.  Set Collection 2 to Collection 1.\n";
  cout<<"10. Check if Collection 1 is empty.\n";
  cout<<"11. Check if Collection 2 is empty.\n";
  cout<<"12. Empty Collection 1\n";
  cout<<"13. Empty Collection 2.\n";
  cout<<"14. Find an item in Collection 1.\n";
  cout<<"15. Find an item in Collection 2.\n";
  cout<<"16. Exit.\n\n";
}

void header() {
  cout<<"\nName: Adam Abad\n";
  cout<<"Class Templates\n";
  cout<<"Collection uses a template class to store data in an array.\n\n";
}

int getOption() {
  int x;
  while (true) { 
    cout<<"Please enter your Option: ";
    cin>>x;
    cout<<endl;
    if (cin.good()) {
      break;
    }	
    cout<<"You have entered invalid input, reenter an option.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  return x;
}

string add(collection<int>* array) {
  int value;
  bool check;
  while (true) {
    cout<<"Please enter your value to add: ";
    cin>>value;
    cout<<endl;
    if (cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, reenter an option.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  
  array->Insert(value, check);
  if(check) 
    cout<<"Value: "<<value<<" was added successfully.\n\n";
  else
    {
      cout<<"Value: "<<value<<" was unable to be added,";
      cout<<" array full.\n\n";
    }
  return "";
}

string rm(collection<int>* array) {
  int returned;
  bool check;
  array->Remove(returned, check);
  if(check)
    cout<<"Value: "<<returned<<" was removed successfully.\n\n";
  else
    {
      cout<<"No data was able to be removed.\n\n";
    }
  return "";
}

void display(collection<int>* array) {
  cout<<endl;
  array->Display();
  cout<<endl;
}
//equality() does not evaluate the equality of the two arrays.
// 2/11/19
string equality(collection<int>* array1, collection<int>* array2) {
  if(array1 == array2) {
    cout<<"The two arrays are equal to each other.\n\n";
  }
  else {
    cout<<"The two arrays are not equal to each other.\n\n";
  }
  return "";
}

//equalSet() does not set the RHS array to the LHS array.
// 2/11/19
void equalSet(collection<int>* array1, collection<int>* array2) {
  array1 = array2;
}

string isEmpty(collection<int>* array) {
  if(array->isEmpty()) {
    cout<<"The array is empty.\n\n";
  }
  else {
    cout<<"The array is not empty.\n\n";
  }
  return "";
}	

string makeEmpty(collection<int>* array) {
  array->makeEmpty();
  cout<<"The array was emptied.\n\n";
  return "";
}

string isIn(collection<int>* array, int num) {
  int value;
  bool check;
  while (true) {
    cout<<"Value to search for: ";
    cin>>value;
    cout<<endl;
    if (cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, reenter an option.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  if(array->Contains(value)) {
    cout<<value<<" is in array "<<num<<"\n\n";
  }
  else {
    cout<<value<<" is not in array "<<num<<"\n\n";
  }
  return "";
}

int main() {
  header();
  collection<int>array1;
  collection<int>array2;
  
  int option = -1;
  while (option != 16) {
    menu();
    option = getOption();
    if (option > 16 or option < 1) {
      cout<<option<<" option is not valid, please enter another option.\n";
    }
    else {
      cout<<"You chose option: "<<option<<endl;
      switch(option) {
      case 1: add(&array1);
	break;
      case 2: add(&array2);
	break;
      case 3: rm(&array1);
	break;
      case 4: rm(&array2);
	break;
      case 5: display(&array1);
	break;
      case 6: display(&array2);
	break;
      case 7: equality(&array1, &array2);
	break;
      case 8: equalSet(&array1, &array2);
	cout<<"Array 1 was copied to array 2.\n\n";
	  break;
      case 9: equalSet(&array2, &array1);
	cout<<"Array 2 was copied to array 1.\n\n";
	  break;
      case 10: isEmpty(&array1);
	break;
      case 11: isEmpty(&array2);
	break;
      case 12: makeEmpty(&array1);
	break;
      case 13: makeEmpty(&array2);
	break;
      case 14: isIn(&array1, 1);
	break;
      case 15: isIn(&array2, 2);
	break;
      case 16: break;
      default: cout<<"Error in option: "<<option<<endl;
      }
    }
  }
}
