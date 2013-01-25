// test.c - A simple C program to test the preformance of using a 1D array as a 2D array vs actually using a 2D array

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HEIGHT 10000
#define WIDTH 1000
#define DATA(r, c) (data[(r)*1000 + (c)])

int main(int argc, char *argv[]) {
  //int *data = (int *)malloc(sizeof(int) * WIDTH * HEIGHT);
  int colNdx, rowNdx;

  for(rowNdx = 0; rowNdx < HEIGHT; rowNdx++)
    for(colNdx = 0; colNdx < WIDTH; colNdx++)
      DATA(rowNdx, colNdx) = 5;

  free(data);
  return 0;
}
