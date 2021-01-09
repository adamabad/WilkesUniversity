// File: pascal.c
// Date: March 27, 2018
// Author: Adam Abad

#include <stdio.h>
#include <stdlib.h>

long factorial(int n) {
  long val = 1;
    for(int i = 0; i <= n; i++)
      if(i != 0)
	val = val * i;
  return val;
}

long binomial(int n, int k) {
  return factorial(n) / (factorial(k) * (factorial(n - k)));
}

int main(int argc, char * argv[]) {
  if(argv[1]) {
    int size = atoi(argv[1]);
    for(int n = 0; n < size; n++) {
      for(int space = n; space < size; space++)
	printf("    ");
      for(int k = 0; k <= n; k++) {
	printf("%8ld",binomial(n,k));
      }
      printf("\n");
    }
  }
  else {
    fprintf(stderr,"%s: %s: %s\n", argv[0], argv[1],
	    "Must have a command-line areguement.");
    exit(1);
  }
}
