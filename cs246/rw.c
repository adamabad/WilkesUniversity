// File: rw.c
// Date: April 3, 2018
// Author: Adam Abad

#include <stdlib.h>
#include "graphics.h"
#include <stdio.h>
#include <string.h>

struct options {
  int step;
  double seed;
  double backR;
  double backG;
  double backB;
  double stepR;
  double stepG;
  double stepB;
};

void draw_window(graphics_context gc, int width, int height, void *data)
{
  struct options *o = (struct options *) data;
  srand48(o->seed);
  
  //Set Backgound
  color(gc, o->backR, o->backG, o->backB);
  rectangle(gc, 0, 0, width, height);
  fill(gc);

  //sets walk color
  new_path(gc);
  color(gc, o->stepR, o->stepG, o->stepB);

  //Centers x/y cordinates
  double x;
  double y;

  x = width / 2;
  y = height / 2;

  //Runs random walk
  for(int i = 0; i < o->step; i++) {
    rectangle(gc, x, y, 1, 1);
    fill(gc);
    x = x + (drand48() - .5);
    y = y + (drand48() - .5);
  }
}

int main(int argc, char *argv[]) {

  struct options o;
  //sets defaults
  o.step = 10000;
  o.seed = getpid();
  o.backR = o.backG = o.backB = 1;
  o.stepR = o.stepG = o.stepB = 0;

  //processes any arguements
  char option;
  while((option = getopt(argc, argv, "s:S:r:g:b:R:G:B:")) != -1) {
    switch (option) {
    case 's': o.step = atoi(optarg); break;
    case 'S': o.seed = atof(optarg); break;
    case 'r': o.stepR = atof(optarg); break;
    case 'R': o.backR = atof(optarg); break;
    case 'g': o.stepG = atof(optarg); break;
    case 'G': o.backG = atof(optarg); break;
    case 'b': o.stepB = atof(optarg); break;
    case 'B': o.backB = atof(optarg); break;
    default:
      fprintf(stderr, "Usage: %s [-s] [-S] [-r] [-g] [-b] [-R] [-G] [-B] ...\n"
	      , argv[0]);
      exit(1);
    }
  }
  //Draws window
  create_window(600,600,&o);
}
