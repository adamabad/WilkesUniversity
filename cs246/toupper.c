// File: toupper.c
// Date: March 13, 2018
// Author: Adam Abad

#include <stdio.h>
#include <ctype.h>

int main() {

  int c;
  printf("Enter characters: ");
  while((c = getchar()) != EOF){
    if(isalpha(c))
      printf("%c",toupper(c));
      else
	printf("%c",c);
  }
}
