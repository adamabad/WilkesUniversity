//******************************************************************
// File: prodcon.c
// Author: Adam Abad
// Date: 10/6/19
// Program Name: Synchronization: Single Producer/Single Consumer
//
// Single Producer/Single Consumer problem solved by using 3 semaphores
//  and 1 shared memory. The loops cycle through the buffer, while the producer
//  and consumer process the data. At the end of the program, the sum of the
//  consecutive integers 1-1000 is displayed and all OS resources are returned.
//******************************************************************

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/errno.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>

//Definitions
#define SHMPERM 0600
#define SEMPERM 0600//Semaphore Union
union {
  int val;
  struct semid_ds *buffer;
  ushort *array;
} semnum;

void header() {
  printf("Name: Adam Abad\n");
  printf("Single Producer Single Consumer Problem\n");
  printf("Implements the prodcon problem using semaphores and shared memory.\n\n");
  fflush(stdout);
}

//semaphore wait
void p(int semid) {
  struct sembuf p_buf;
  p_buf.sem_num = 0;
  p_buf.sem_op = -1;
  p_buf.sem_flg = 0;
  if(semop(semid, &p_buf,1) < 0) {
    printf("fatal p error on semaphore %i",semid);
    fflush(stdout);
  }
}

//semaphore signal
void v(int semid) {
  struct sembuf v_buf;
  v_buf.sem_num = 0;
  v_buf.sem_op = 1;
  v_buf.sem_flg = 0;
  if(semop(semid, &v_buf, 1) < 0) {
    printf("fatal v error on semaphore %i", semid);
    fflush(stdout);
  }
}

int main() {
  
  header(); //Header comments
  
  //Semaphore declaration:
  //sem_id1 - designates how many objects are in the buffer.
  //sem_id2 - designates how many more objects can be produced.
  //mutex   - provides mutual exclusion and protects access to the buffer.
  
  int sem_id1, sem_id2, mutex;
  sem_id1 = semget(IPC_PRIVATE,1,SEMPERM|IPC_CREAT|IPC_EXCL);
  semnum.val = 0;
  semctl(sem_id1,0,SETVAL,semnum); 
  sem_id2 = semget(IPC_PRIVATE,1,SEMPERM|IPC_CREAT|IPC_EXCL);
  semnum.val = 10;
  semctl(sem_id2,0,SETVAL,semnum); 
  mutex = semget(IPC_PRIVATE,1,SEMPERM|IPC_CREAT|IPC_EXCL);
  semnum.val = 1;
  semctl(mutex,0,SETVAL,semnum); 
  
  //Shared memory declaration
  int seg_id;
  seg_id = shmget(IPC_PRIVATE, sizeof(int)*10,IPC_CREAT|IPC_EXCL|SHMPERM);
  int *buf;
  
  //Fork
  int pid;
  int process;
  pid = fork();
  int statloc;
  
  if(pid < 0) { //Failed
    return(-1);
  }
  else if(pid == 0) { //Child (Consumer)
    process = getpid();
    printf("I am the child. pid = %i\n",process);
    fflush(stdout);
    int sum = 0;
    
    buf = (int *)shmat(seg_id, (int *)0,0);
    for(int x = 0; x < 1000; x++) {
      p(sem_id1);
      p(mutex);
      sum += buf[x%10];
      v(mutex);
      v(sem_id2);
    }
    printf("Sum: %i\nConsumer terminating.\n",sum);
    fflush(stdout);
  }
  else { //Parent (Producer)
    process = getpid();
    printf("I am the parent. pid = %i\n",process);
    fflush(stdout);
    
    buf = (int *)shmat(seg_id, (int *)0,0);
    for(int x = 0; x < 1000; x++) {
      p(sem_id2);
      p(mutex);
      buf[x%10] = (x + 1);
      v(mutex);
      v(sem_id1);
    }
    printf("\nParent Finished producing.\n");
    fflush(stdout);
    
    //Ending Squence
    wait(&statloc);
    printf("\nChild finished, cleaning up memory and semaphores.\n");
    shmctl(seg_id,IPC_RMID,NULL);
    semctl(sem_id1,0,IPC_RMID,NULL);
    semctl(sem_id2,0,IPC_RMID,NULL);
    semctl(mutex,0,IPC_RMID,NULL);
    printf("Shared resources terminated, exiting program.\n");
    fflush(stdout);
  }
}
