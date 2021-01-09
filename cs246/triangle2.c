// File: triangle2.c
// Date: March 16, 2018
// Author: Adam Abad

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  if(argv[1] && argv[2]){
    int type = atoi(argv[1]);
    int n = atoi(argv[2]);
    switch(type) {
      case 1:
	for(int x = 1; x <= n; x++){
	  for(int width = 1; width <= x; width++) {
	    if((width == 1) || (width == x) || (x == n))
	      printf("*");
	    else
	      printf(" ");
	  }
	  printf("\n");
	}
	break;
	
      case 2:
	for(int x = 1; x <= n; x++){
	  for(int width = 1; width <= n; width++){
	    if((width == n) || (width == (n - x + 1)) || (x == n))
	      printf("*");
	    else
	      printf(" ");
	  }
	  printf("\n");
       }
       break;

    case 3:
      for(int x = n; x > 0; x--){
	for(int width = 1; width <= x; width++) {
	  if((width == 1) || (width == x) || (x == n))
	    printf("*");
	  else
	    printf(" ");
	}
	printf("\n");
      }
      break;
      
    case 4:
      for(int x = n; x > 0; x--){
	for(int width = 1; width <= n; width++) {
	  if((width == n) || (width == (n - x + 1)) || (x == n))
	    printf("*");
	  else
	    printf(" ");
	}
	printf("\n");
      }
      break;

    } 
  }    
  else{
    
    //https://stackoverflow.com/questions/39002052/how-i-can-print-to-stderr-in-c
    
    fprintf(stderr,"Must have 2 command-line arguements\n");
    exit(1);
  }
}
