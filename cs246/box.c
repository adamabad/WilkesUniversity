// File: box.c
// Author: Adam Abad
// Date: 2/27/2018

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
  
  int n = atoi(argv[1]);
  for(int x = 1; x <= n; x++){
    if((x == 1) || (x == n)){
      for(int q = 1; q < n; q++){
	printf("*");
      }
      printf("*\n");
    }
    else
    {
      printf("*");
      for(int space = 2; space < n; space++){
	printf(" ");
      }
      printf("*\n");
    }
  }
}
