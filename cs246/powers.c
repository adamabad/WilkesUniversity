// File: powers.c
// Date: March 16, 2018
// Author: Adam Abad

#include <stdio.h>
#include <stdlib.h>

long power(long m, int n) {
  long anw = 1;
  for(int x = 0; x < n; x++) {
    anw = anw * m;
  }
  return anw;
}

int main(int argc, char * argv[]) {
  if(argv[1] && argv[2]) {   
    long m = atol(argv[1]);
    int n = atoi(argv[2]);
    printf("%s %s\n\n","Powers of",argv[1]);
    for(int i = 1; i <= n; i++) {
      long anw = power(m,i);
      printf("%6d %ld\n", i, anw);
    }
  }
  else {
    fprintf(stderr, "Error: Must have two arguments.\n");
    exit(1);
  }
}
