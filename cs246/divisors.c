// File: divisors.c
// Author: Adam Abad
// Date: 2/27/2018

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  int number = atoi(argv[1]);
  for(int x = 1; x <= number; x++){
    if((number % x) == 0)
      printf("%d\n",x);
  }
}
