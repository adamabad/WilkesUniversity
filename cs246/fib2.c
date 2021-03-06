// File: fib2.c
// Date: March 27, 2018
// Author: Adam Abad

#include <stdio.h>
#include <stdlib.h>

void fib(int n, long a[n]) {
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i <= n; i++)   
      a[i] = a[i - 1] + a[i - 2];
}


int main(int argc, char * argv[]) {
  static long a[100] = {-1};
  if(argv[1]) {
    if(a[0] = -1)
      fib(atoi(argv[1]),a);
    for(int x = 0; x <= atoi(argv[1]); x++)
      printf("%ld\n",a[x]);
  }
  else {
    fprintf(stderr,"%s: %s: %s\n", argv[0], argv[1],
	    "Must have a command-line areguement.");
    exit(1);
  }
}
