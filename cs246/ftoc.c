// File: ftoc.c
// Date: March 13, 2018
// Author: Adam Abad

#include <stdio.h>

int main(){
  double fahr;
  printf("Enter a temperature in Fahrenheit: ");
  scanf("%lf",&fahr);
  double cel;
  cel = (fahr - 32) * 5.0 / 9.0;
  printf("The temperature %.1fF, is %.1fC.\n", fahr, cel);
}
