//******************************************************************
// File: wrestler.c
// Author: Adam Abad
// Date: 11/7/2019
// Program Name: The Arm Wrestler Problem
//******************************************************************

/* Description:
   wrestler.c uses semaphores and shared memory to simulate a variation
   of the sleeping barber problem. This implementation includes a random
   outcome and is able to allocate winnnings based on the wrestler process.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/errno.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>

//Definitions
#define SHMPERM 0600
#define SEMPERM 0600
#define CAPACITY 3
#define PATRONS 5
#define LIMIT 20
#define OPEN 1
#define CLOSED 0
#define MATCHESREMAINING 0
#define CLOSEDSTATUS 1
#define WAITING 2
#define CASHPATRONS 3
#define CASHWRESTLER 4
 
void header() {
  printf("Name: Adam Abad\n");  
  fflush(stdout);
  printf("The Arm Wrestler Problem\n");
  fflush(stdout);
  printf("Implements the arm wrestler problem using semaphores and shared memory.\n\n");
  fflush(stdout);
}

//Semaphore wait
void p(int semid) {
  struct sembuf p_buf;
  p_buf.sem_num = 0;
  p_buf.sem_op = -1;
  p_buf.sem_flg = 0;
  if(semop(semid, &p_buf,1) < 0) {
    printf("fatal p error on semaphore %i\n", semid);
    fflush(stdout);
  }
}

//Semaphore signal
void v(int semid) {
  struct sembuf v_buf;
  v_buf.sem_num = 0;
  v_buf.sem_op = 1;
  v_buf.sem_flg = 0;
  if(semop(semid, &v_buf,1) < 0) {
    printf("fatal v error on semaphore %i\n", semid);
    fflush(stdout);
  }
}

//Wrestler takes the seg_id for sharedmemory
//Also takes the 5 semaphores associated with the process
void wrestler(int seg_id, int sem_Wrestler,
	      int sem_Patron, int cs_Wrestling,
	      int mutex, int sync) {
  int * sharedmemory; //Pointer to the shared memory
  int result; //Integer to save the results of the match
  sharedmemory = (int *)shmat(seg_id, (int *)0,0); //Process Attachment

  while(sharedmemory[MATCHESREMAINING] > 0) { //Continue while under remaining matches
    p(sem_Patron); //Wait for patron to arrive
    p(mutex); //Moves the patron from waiting to the tent
      v(sem_Wrestler);
      sharedmemory[WAITING]--;
    v(mutex); //Ends ME
    p(cs_Wrestling); //Entering Wrestler CS (Ends by "handshake" in patron)
      printf("Wrestler    :             Wwrestling\n");
      fflush(stdout);
      result = rand() % 4;
      p(mutex);
        sharedmemory[MATCHESREMAINING]--;
      v(mutex);
      if(result) { //If not 0, wrestler win                                           
	printf("Wrestler    : wrestler win\n");
	fflush(stdout);
	sharedmemory[CASHWRESTLER] += 10;
      }
      else { //Is 0 = patron win                                           
	printf("Wrestler    : patron win\n");
	sharedmemory[CASHPATRONS] += 25;
      }
    v(sync); //Handshake with patron
  }

  p(mutex);
    sharedmemory[CLOSEDSTATUS] = CLOSED; //Close the tent after the limit
    printf("Wrestler    : Tent Closed\n");
    fflush(stdout);
  v(mutex);
  for(int x = 0; x < PATRONS; x++) { //Loop wakeup to the 5 child processes
    v(sem_Wrestler);
  }
  printf("Wrestler terminating.\n");
  fflush(stdout);
  exit(0);
}

//Patron takes the seg_id for the shared memory
//Also takes the 5 semaphores associated with the process
void patron(int seg_id, int sem_Wrestler,
	     int sem_Patron, int cs_Wrestling,
	      int mutex, int sync) {
  int * sharedmemory; // Pointer to shared memory
  sharedmemory = (int *)shmat(seg_id, (int *)0,0);

  while(sharedmemory[CLOSEDSTATUS] != CLOSED) {
    p(mutex);
    //Check if there is space for 1 patron or the tent is closed
    if(sharedmemory[WAITING] >= CAPACITY || sharedmemory[CLOSED] == CLOSED) {
      v(mutex);
    }
    else {
      //There is space for atleast 1, admit to tent
      sharedmemory[WAITING]++;
      printf("Patron %5i: waiting\n",getpid());
      fflush(stdout);
      v(sem_Patron); //Signal to wrestler that a patron is waiting
      v(mutex);
      p(sem_Wrestler); //Wait for wrestler to let into tent.
      if(sharedmemory[CLOSEDSTATUS] == CLOSED) {
      //If the wrestler lets patron in but tent is closed, release the patron
        break;
      }
      printf("Patron %5i:             Pwrestling\n",getpid());
      fflush(stdout);
      p(sync); //Wait for wrestler to sync
      v(cs_Wrestling); //"Handshake" to finish sync
    }						
  }
  printf("Patron %5i: terminating.\n",getpid());
  fflush(stdout);
  exit(0);
}

int main() {

  header();
  
  //Semaphore union

  union {
    int val;
    struct semid_ds *buffer;
    ushort *array;
  } semnum;
	
  //Semaphore Declaration:
  int semWrestler, semPatron, csWrestling, mutex, syncronization;
  
  //Wrestler semaphore, used to signal the patron if the wrestler is ready
  semWrestler = semget(IPC_PRIVATE,1,SEMPERM|IPC_CREAT|IPC_EXCL);
  semnum.val = 0;
  semctl(semWrestler,0,SETVAL,semnum);
  
  //Patron semaphore, used to signal the wrestler that a patron is waiting
  semPatron = semget(IPC_PRIVATE,1,SEMPERM|IPC_CREAT|IPC_EXCL);
  semnum.val = 0;
  semctl(semPatron,0,SETVAL,semnum);
  
  //Critical Section for wrestling, used in combination with syncronization to
  // manage the critical sections of the patron and the wrestler
  csWrestling = semget(IPC_PRIVATE,1,SEMPERM|IPC_CREAT|IPC_EXCL);
  semnum.val = 1;
  semctl(csWrestling,0,SETVAL,semnum);
  
  //Mutex to shared memory, used to protect access to the shared memory and
  // certain semaphores
  mutex = semget(IPC_PRIVATE,1,SEMPERM|IPC_CREAT|IPC_EXCL);
  semnum.val = 1;
  semctl(mutex,0,SETVAL,semnum);
  
  //Sync semaphore used with csWrestling to manage the critical sections
  syncronization = semget(IPC_PRIVATE,1,SEMPERM|IPC_CREAT|IPC_EXCL);
  semnum.val = 0;
  semctl(semWrestler,0,SETVAL,semnum);
  
  //Shared memory
  int seg_id;
  seg_id = shmget(IPC_PRIVATE,sizeof(int)*5,IPC_CREAT|IPC_EXCL|SHMPERM);
  int * sharedmemory;
  
  //Attaching to main process
  sharedmemory = (int *)shmat(seg_id, (int *)0,0);
  
  //Setting shared memory values
  sharedmemory[MATCHESREMAINING] = LIMIT;
  sharedmemory[CLOSEDSTATUS] = OPEN; 
  sharedmemory[WAITING] = 0;
  sharedmemory[CASHWRESTLER] = 0;
  sharedmemory[CASHPATRONS] = 0;
  
  //Random number seed:
  srand(getpid());
  
  int pid;
  pid = fork();
  int statloc;
  
  if(pid < 0) { 
    return (-1); //Failed Fork
  }
  else if(pid == 0) { //First child = wrestler fork
    wrestler(seg_id, semWrestler,
	     semPatron, csWrestling, mutex, syncronization);
  }
  else { //Main process
    //5 Patron forks
    for(int x = 0; x < 5; x++) {
      pid = fork();
      if(pid < 0) { //Failed Work
	return (-1);
      }
      else if(pid == 0) { //Child = new patron
	patron(seg_id, semWrestler,
	       semPatron, csWrestling, mutex, syncronization);
      }
    }
  } //patron else
  
  for(int x = 0; x < 6; x++) {
    wait(&statloc);	
  }
  //Main process displays the results of wrestlings
  printf("\nAfter the wrestling day, the wrestler made %i\n",
	 sharedmemory[CASHWRESTLER]);
  printf("After the wrestling day, the patrons made %i\n\n",
	 sharedmemory[CASHPATRONS]);


  //Returning shared memory and semaphores
  if(!semctl(semWrestler,0,IPC_RMID,NULL)) {
    printf("Semaphore Destroyed Successfully: semWrestler\n");
    fflush(stdout);
  }
  else {
    printf("There was an error destroying: semWrestler\n");
    fflush(stdout);
  }

  if(!semctl(semPatron,0,IPC_RMID,NULL)) {
    printf("Semaphore Destroyed Successfully: semPatron\n");
    fflush(stdout);
  }
  else {
    printf("There was an error destroying: semPatron\n");
    fflush(stdout);
  }

  if(!semctl(csWrestling,0,IPC_RMID,NULL)) {
    printf("Semaphore Destroyed Successfully: csWrestling\n");
    fflush(stdout);
  }
  else {
    printf("There was an error destroying: csWrestling\n");
    fflush(stdout);
  }

  if(!semctl(mutex,0,IPC_RMID,NULL)) {
    printf("Semaphore Destroyed Successfully: mutex\n");
    fflush(stdout);
  }
  else {
    printf("There was an error destroying: mutex\n");
    fflush(stdout);
  }

  if(!semctl(syncronization,0,IPC_RMID,NULL)) {
    printf("Semaphore Destroyed Successfully: syncronization\n");
    fflush(stdout);
  }
  else {
    printf("There was an error destroying: syncronization\n");
    fflush(stdout);
  }

  if(!shmctl(seg_id,IPC_RMID,NULL)) {
    printf("Sharedmem Destroyed Successfully: seg_id\n");
    fflush(stdout);
  }
  else {
    printf("There was an error destroying: seg_id\n");
    fflush(stdout);
  }
} //End main
