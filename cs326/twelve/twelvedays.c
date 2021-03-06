//******************************************************************
// File: twelvedays.c
// Author: Adam Abad
// Date: 11/30/19
// Program Name: Unix Signals Programming Assignment, The Twelve Days of Christmas 
// Total Gifts Given: 
//					The Sum of n = 1 to 12 of the Sum of i = 1 to n of i
//                  Total Gifts Given: 364
//******************************************************************

/* Description:
   Modification of the safesigex code supplied to fork 12 children and
   have each child print out the twelve days of chirstmas
*/

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define CHILDCOUNT 12
#define DAYSOFCHRISTMAS 12

void sig_user (int signo);
void child();

const char *thedays[DAYSOFCHRISTMAS] = {
  "twelfth",
  "eleventh",
  "tenth",
  "ninth",
  "eigth",
  "seventh",
  "sixth",
  "fifth",
  "fourth",
  "third",
  "second",
  "first"
};

const char *gifts[DAYSOFCHRISTMAS]={
  "Twelve Drummers Drumming",
  "Eleven Pipers Piping",
  "Ten Lords a Leaping",
  "Nine Ladies Dancing",
  "Eight Maids a Milking",
  "Seven Swands a Swimming",
  "Six Geese a Laying",
  "Five Golden Rings",
  "Four Calling Birds",
  "Three French Hens",
  "Two Turtle Doves",
  "A Partridge in a Pear Tree"
};

static sigset_t newmask, oldmask, zeromask;


int main (void) {
  int pid, status;
  
  /*  stuff for blocking signals */
  if (signal(SIGUSR1, sig_user) == SIG_ERR) {
    printf("error creating signal handler \n");
  }
  sigemptyset(&zeromask);
  sigemptyset(&newmask);
  sigaddset(&newmask,SIGUSR1);
  if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0) {
    printf("error in sigprocmask \n");
  }
  
  int previousChild = -1;
  for(int x = 0; x < CHILDCOUNT; x++) { //Loop fork for children
    pid = fork();
    if (pid < 0) { //Fork Failed
      printf("Fork Failed.\n");
      exit(-1);
    }
    else if(pid == 0) { //Is child
      child(previousChild, x); //Sends previous child's pid and childnumber
      exit(0); //Exit for child to terminate process after compleation
    }
    previousChild = pid; //Sets the variable to send the next child the current child's pid
  }
  
  printf("parent signalling child \n");
  fflush(stdout);
  kill(pid, SIGUSR1);
  
  printf("parent waiting for child to terminate\n");
  fflush(stdout);
  for(int x = 0; x < CHILDCOUNT; x++) { //Loop waiting for the children to terminate
    if(pid=wait(&status)<0) {
      printf("waitpid error\n");
    }	
  }
  printf("parent terminating \n");
} /* end of main*/

void child(int previousChild, int childno) {      
  //wait for the signal   
  sigsuspend(&zeromask); /*wait */
  printf("\nChild %i:\n\n", childno + 1);
  fflush(stdout);
  
  printf("On the %s day of Christmas\nmy true love sent to me:\n", thedays[childno]);
  fflush(stdout);
  for(int x = childno; x < 12; x++) { //Loop through the array of lines and days
    if(x == 11 && childno != 11) { //If x=11 and is not the 12th child, insert and to the last line
      printf("and %s\n", gifts[x]);
      fflush(stdout);
    }
    else {
      printf("%s\n", gifts[x]);
      fflush(stdout);
    }
  }
  if(previousChild != -1) { //Signal next child
    kill(previousChild, SIGUSR1);
  }
  if (sigprocmask(SIG_SETMASK, &oldmask, NULL)<0) {
    printf("sigmask error \n");
  }
}

void sig_user (int signo) {
  int sing, index;
  if (signo == SIGUSR1) {
    fflush(stdout);
  }/* end if */
}/* end of signal handler */
