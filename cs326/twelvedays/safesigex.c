//******************************************************************
// File: safesigex.c
// Author: Adam Abad
// Date: 11/25/19
// Program Name: Unix Signals Programming Assignment 
//******************************************************************

/* Description:
	Modification of the safesigex code supplied to fork 2 children using a loop.
	The 2nd child signals the 1st child.
*/

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define CHILDCOUNT 2

void sig_user (int signo);
void child();


/* please note the use of global variables. Global variables are 
 * very dangerous and should only be used when absolutely necessary.
 * this simple example does not justify the use of global variables.
 * It was, however, taken from a much more complicated program, 
 * complicated enough to justify the use of global variables.
 */
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
	for(int x = 0; x < CHILDCOUNT; x++) {
		pid = fork();
		if (pid < 0) {
			printf("Fork Failed.\n");
			exit(-1);
		}
		else if(pid == 0) { //Is child
			child(previousChild, x); //Sends previous child's pid and childnumber
			exit(0); //Exit for child to terminate process after compleation
		}
		previousChild = pid;
	}
	
	
	printf("parent signalling child \n");
	fflush(stdout);
    kill(pid, SIGUSR1);

    printf("parent waiting for child to terminate\n");
	fflush(stdout);
	for(int x = 0; x < CHILDCOUNT; x++) {
		if(pid=wait(&status)<0) {
			printf("waitpid error\n");
		}	
	}
	printf("parent terminating \n");
} /* end of main*/

void child(int previousChild, int childno) {   
	printf("child %2i has control  %i\n", childno, getpid());
	fflush(stdout);
	/* parent created  signal handler */
   
	//wait for the signal   
	sigsuspend(&zeromask); /*wait */
	if(previousChild != -1) { //Signal next child
		kill(previousChild, SIGUSR1);
	}
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL)<0) {
		printf("sigmask error \n");
	}
	printf("child %i terminating after signal  %i\n", childno, getpid());
}

void sig_user (int signo) {
	int sing, index;
	if (signo == SIGUSR1) {
		printf("signal 1 received by signal handler %i child  \n", getpid());
		fflush(stdout);
	}/* end if */
}/* end of signal handler */
