// File: factor.c
// Date: April 24, 2018
// Author: Adam Abad

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void sieve(char *num) {

  long max;
  long number = atol(num);
  max = floor(sqrt(atol(num)));
  char *prime = malloc(max + 1);

  for (long i = 2; i <= max; i++) {
    prime[i] = 1;
  }

  long k = 2;
  while(k <= max) {
    for(int j = 2 * k; j <= max; j+= k) {
      prime[j] = 0;
    }
    k++;
    while(k <= max && !prime[k]) {
      k++;
    }
  }

  int count = 1;
  for(long i = 2; i <= max; i++) {
    if(prime[i])
      count++;
  }
  
  long *pArray = calloc(count,sizeof(long));
  long arrayPosition = 0;
  
  for(long i = 2; i <= max; i++) {
    if(prime[i]){
      pArray[arrayPosition++] = i;     
    }
  }
  
  free(prime);
  
  for(long i = 0; i < arrayPosition; i++) {
    int power = 0;
    while(number % pArray[i] == 0) {
      power++;
      number = number / pArray[i];
    }
    if(power > 1)
      printf("%ld^%d ",pArray[i],power);
    else if(power == 1)
      printf("%ld ",pArray[i]);
  }
  if((number != 0) && (number != 1))
    printf("%ld",number);
  printf("\n");
  free(pArray);
}
  
int main(int argc, char *argv[]) {
  if(argc == 2) {
    sieve(argv[1]);
  }
  else {
    fprintf(stderr, "%s: %s\n", argv[0], "Must have a single command-line arguement.");
    exit(1);
  }
}
