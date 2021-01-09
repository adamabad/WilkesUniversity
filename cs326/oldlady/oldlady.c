//******************************************************************
// File: oldlady.c
// Author: Adam Abad
// Date: 11/18/19
// Program Name: Unix Message Queues
//******************************************************************

/* Description:
   Utilizes message queues to create a child system to handle multiple processes.
   Child processes construct a verse of the poem and send it to the assembler.
   The Assembler process loops to recieve the messages then displays the entire poem.
*/

#include <string.h>         
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <wait.h>
#include <sys/msg.h>
#include <sys/errno.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBEROFVERSES 8
#define MSGPERM 0600

//Msgqueue ID declaration
int sendverseid;

//Msgqueue struct
struct sendverse {
  long mtype;
  struct verse {  
    int childno;
    char sheswalloweda[30];
    char  theverse[200];
  }verse;
}qentry;

//Header function
void header() {
  printf("Name: Adam Abad\n");  
  fflush(stdout);
  printf("The Old Lady Message Queues\n");
  fflush(stdout);
  printf("Reconstructs the old lady who swallowed a fly rhyme using seperate processes and message queues.\n\n");
  fflush(stdout);
}

//Const char array for each child function (animal)
const char *swallowed[NUMBEROFVERSES] = {
  "fly; ",
  "spider",
  "bird",
  "cat",
  "dog",
  "goat",
  "cow",
  "horse"
};

//Const char array for each child function (verse)
const char *thewords[200]={
  "I don't know why she swallowed a fly, perhaps she'll die!",
  "It wriggled and jiggled and tickled inside her! \n She swallowed the spider to catch the fly;",
  "How absurd to swallow a bird! She swallowed the bird to catch the spider; ",
  "Imagine that! She swallowed a cat! She swallowed the cat to catch the bird, ",
  "What a hog, to swallow a dog! She swallowed the dog to catch the cat, ",
  "She just opened her throat and swallowed a goat! \n She swallowed the goat to catch the dog, ",
  "I do not know how she swallowed the cow! \n She swallowed the cow to catch the goat, ",
  "She is dead of course!!! \n She swallowed the horse to catch the cow, "
};

//Child function with exit(), recieves a number from main and constructs a message to send on the 
//  msgqueue
void childsender(int childnumber) {
  struct sendverse recite;
  //Print a message with control and child no.
  //call getpid and print pid
  //Build a message with the child no, swallowed, and verse
  recite.mtype = 1;
  recite.verse.childno = childnumber;
  strcpy(recite.verse.sheswalloweda, swallowed[childnumber-1]);
  strcpy(recite.verse.theverse, thewords[childnumber-1]);
  //Send message onto the queue
  printf("Child: %i    pid: %i    Has control.\n", childnumber, getpid());
  fflush(stdout);
  msgsnd(sendverseid, &recite, sizeof(recite.verse), 0);
  //Terminate
  exit(1);
}

//Child(0), the assmebler function loops to receive each message and displays the rhyme
void assembler() {
  struct sendverse recite;
  //print stating control
  //execute getpid and print pid
  printf("Child: 0    pid: %i    Has control.\n", getpid());
  fflush(stdout);
  /*
    Declare 2 2D arrays
    1. Verses recieved
    2. What was swallowed 
  */	
  char verseR[8][200];
  char swallowR[8][30];
  /*
    2 loops 8 times each
    1. receive a message, pring the child number it received it from and copy the verse into the appropriate 
    entry into the verse character array and what was swallowed
    2. nested for loops to display the line with what follows.
  */
  for(int x = 0; x < 8; x++) {
    msgrcv(sendverseid, &recite, sizeof(recite.verse), 0, 0);
    printf("Recieved from child %i\n", recite.verse.childno);
    fflush(stdout);
    strcpy(verseR[recite.verse.childno - 1], recite.verse.theverse);
    strcpy(swallowR[recite.verse.childno - 1], recite.verse.sheswalloweda);
  }
  for(int x = 0; x < 8; x++) {
    printf("There was an old lady who swallowed a %s\n",swallowR[x]);
    fflush(stdout);
    printf("%s\n",verseR[x]);
    fflush(stdout);
    for(int i = x - 1; i >= 0; i--) {
      printf("%s\n",verseR[i]);
      fflush(stdout);
    }
  }
  //Terminate
  exit(1);
}
int main() {
  //Obtain message Queue
  sendverseid = msgget(IPC_PRIVATE,MSGPERM|IPC_CREAT|IPC_EXCL);
  //Fork First Child (assembler)
  int pid;
  pid = fork();
  int statloc;
  if(pid < 0) {
    return (-1); //Failed Fork
  }
  else if(pid == 0) { //0th Child = Assembler process
    assembler();
  }
  else { //Is the parent
    //Fork 8 additional children (function)
    for(int x = 1; x < 9; x++) { //Loop for 1-8 children
      pid = fork();
      if(pid < 0) { //Failed Fork
	return(-1);
      }
      else if(pid == 0) { //Is the child
	childsender(x);
      }
    }
  }
  
  //Wait for 9 children to terminate
  for(int x = 0; x < 9; x++) {
    wait(&statloc);
  }
  
  printf("\nChildren processes terminated, cleaning message queue.\n");
  fflush(stdout);
  //Return message queue
  if(!msgctl(sendverseid,IPC_RMID,NULL)) {
    printf("Message queue cleaned successfully\n");
  }
  else {
    printf("Message queue not cleaned successfully\n");
  }
  printf("Ending program.\n");
}
