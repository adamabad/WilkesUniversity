#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>

int main() {

	int A;
	int statloc;
	int pipeIdentification[2];

	pipe(pipeIdentification);
	int retval;
	retval=fork();
	if (retval<0) {
		return(-1); /*fork failed*/
	}
	if(retval==0) { /*child */
	/* child closes write end as it is not using it */
		close(pipeIdentification[1]); 
		printf("I am the child reading from the pipe\n");
		fflush(stdout);
		read(pipeIdentification[0],&A,sizeof(int));
		printf("%i\n",A);
	}
	else {
	/*parent closes read end as it is notusing it */
		close (pipeIdentification[0]);
		printf("I am the parent about to write to the pipe\n");
		fflush(stdout);
	/*parent send the value 10 to the child*/
		A=10;
		write(pipeIdentification[1],&A,sizeof(int));
		wait(&statloc); //parent must wait for child to terminate
	}		
}
