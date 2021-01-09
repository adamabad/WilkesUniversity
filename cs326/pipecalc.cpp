//******************************************************************
// File: pipecalc.cpp
// Author: Adam Abad
// Date: 9/19/19
// Program Name: Fork, Processes, and Pipes
//******************************************************************

/* Description:
   Pipecalc forks the parent process and sets a child to handle 
   calculations using data retrieved from a pipe from the parent.
   The child then sends the result back over through a seperate pipe to
   the parent.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void header() {
  printf("\nName: Adam Abad\n");
  printf("Fork, Processes, and Pipes\n");
  printf("Uses two pipes to communicate between a parent and child.\n\n");
}

void menu() {
  printf("+ For addition\n");
  printf("- For subtraction\n");
  printf("* For multiplication\n");
  printf("/ For division\n");
  printf("X To Exit\n\n");
}

//getInteger() processes input to assure an integer is entered.
// returns int
int getInteger() {
  int x;
  while(true) {
    printf("Enter an Integer: ");
    cin>>x;
    printf("\n");
    if(cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, please reenter integer.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  printf("You entered %i\n",x);
  return x;
}

//getSymbol() processes input to retrieve a char
// returns char
char getSymbol() {
  char x;
  while(true) {
    printf("Enter a Symbol: ");
    cin>>x;
    printf("\n");
    if(cin.good()) {
      break;
    }
    cout<<"You have entered invalid input, please reenter symbol.\n";
    cin.clear();
    cin.ignore(120,'\n');
  }
  printf("You entered %c\n",x);
  return x;
}

int main() {
  header();
  char symbol;
  int integer1, integer2, result, statloc, retval;
  int childPipe[2]; //Pipe that the CHILD will write to.
  int parentPipe[2]; //Pipe that the PARENT will write to.
  
  pipe(childPipe);
  pipe(parentPipe);
  retval=fork();
  
  if (retval<0) {//Failed Fork
    return(-1);
  }
  
  if(retval==0) { //Child Process
    close(childPipe[0]); //Child process closes read for its pipe.	
    close(parentPipe[1]); //Child process closes write for parent pipe.
    fflush(stdout);
    read(parentPipe[0], &symbol, sizeof(char));
    while(symbol != 'X') {
      read(parentPipe[0], &integer1, sizeof(int));
      read(parentPipe[0], &integer2, sizeof(int));
      switch(symbol) {
      case '+':
	result = integer1 + integer2;
	break;
      case '-':
	result = integer1 - integer2;
	break;
      case '*':
	result = integer1 * integer2;
	break;
      case '/':
	result = integer1 / integer2;
	break;
      default:
	printf("Error in reading symbol.\n");
      }
      write(childPipe[1], &result, sizeof(int));
      read(parentPipe[0], &symbol, sizeof(char));
    }
  }
  
  else { //Parent Process
    close(parentPipe[0]); //Parent processes closes read for its pipe.
    close(childPipe[1]); //Parent process closes write for its pipe.
    symbol = ' ';
    
    while(symbol != 'X') {
      fflush(stdout);
      menu();
      symbol = getSymbol();
      
      //+, -, * symbols
      if(symbol == '+' or symbol == '-' or symbol == '*') {
	write(parentPipe[1], &symbol, sizeof(char));
	integer1 = getInteger();
	write(parentPipe[1], &integer1, sizeof(int));
	integer2 = getInteger();
	write(parentPipe[1], &integer2, sizeof(int));
	read(childPipe[0], &result, sizeof(int)); //Read result from child pipe.
	printf("%i %c %i = %i\n\n", integer1, symbol, integer2, result);
      }
      //Special conditions for / to avoid divide by 0.
      else if(symbol == '/') {
	write(parentPipe[1], &symbol, sizeof(char));
	integer1 = getInteger();
	write(parentPipe[1], &integer1, sizeof(int));
	integer2 = getInteger();
	while(integer2 == 0) {
	  printf("Cannot divide by 0, please reenter.\n");
	  integer2 = getInteger();
	}
	write(parentPipe[1], &integer2, sizeof(int));
	read(childPipe[0], &result, sizeof(int)); //Read result from child pipe.
	printf("%i %c %i = %i\n\n", integer1, symbol, integer2, result);
      }
      else if(symbol == 'X') { //Exit program
	write(parentPipe[1], &symbol, sizeof(char));
	printf("%c entered, exiting program.\n", symbol);
      }
      else { //Invalid symbol entered
	printf("Invalid symbol, enter again.\n");
      }
    }
    wait(&statloc); //Parent wait.
  }
}
