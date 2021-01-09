// File: fib1.c
// Date: March 27, 2018
// Author: Adam Abad

#include <stdio.h>
#include <stdlib.h>

long fib(int n) {
  if(n == 0)
    return 0;
  else if(n == 1)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}

int main(int argc, char * argv[]) {
  long f;
  if(argv[1])
    for(int x = 0; x <= atoi(argv[1]); x++) {
      f = fib(x);
      printf("%ld\n",f);
    }
  else {
    fprintf(stderr,"%s: %s: %s\n", argv[0], argv[1],
	    "Must have a command-line areguement.");
    exit(1);
  }
}
