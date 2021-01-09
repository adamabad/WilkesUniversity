// File: diamonds.c
// Date: April 3, 2018
// Author: Adam Abad

#include <stdlib.h>
#include "graphics.h"

void draw_diamond(graphics_context gc, double x, double y, double size) {
  size = size / 2;
  new_path(gc);
  color(gc, drand48(), drand48(), drand48());
  stroke(gc);
  move_to(gc, x - size, y); //left point
  line_to(gc, x, y + size); //top point
  line_to(gc, x + size, y); //right point
  line_to(gc, x, y - size); //bottom point
  close_path(gc);
  fill(gc);
}

void draw_window(graphics_context gc, int width, int height, void *data) {
  double dia_size;
  double space_size;
  double x;
  double y;
  double positionFactor;
  double startX;
  double startY;
  
  //Background set
  color(gc, 1, 1, 1);
  rectangle(gc, 0, 0, width, height);
  fill(gc);
  
  if(width > height){
    dia_size = height * .8 / 10;
    space_size = height * .1 / 10;
    startX = width / 2 - ((dia_size + space_size) * 5); //centers hor.
    startY = positionFactor = dia_size + space_size; //sets startY
  }
  else {
    dia_size = width * .8 / 10;
    space_size = width * .1 / 9;
    startY = height / 2 - ((dia_size + space_size) * 5); //centers vert.
    startX = positionFactor = dia_size + space_size; //sets startX
  }

  x = startX;
  y = startY;
  
  for(int i = 0; i < 10; i++) {
    
    for(int w = 0; w < 10; w++){
      draw_diamond(gc,x,y,dia_size);
      x = x + positionFactor;
    }
    
    x = startX;
    y = y + positionFactor;
  }
}


int main() {
  srand48(getpid());
  create_window(600,600, NULL);
}
