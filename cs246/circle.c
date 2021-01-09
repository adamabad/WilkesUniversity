// File: circle.c
// Author: Adam Abad
// Date: 2/27/2018

#include <stdio.h>
#include <math.h>

int main(){
  double radius;
  printf("Enter the raidus of a circle: ");
  scanf("%lf",&radius);
  printf("The circumference is: %0.6f \n", (radius * 2 * M_PI));
  printf("The area is: %0.6f \n ", (radius * radius * M_PI));
}
