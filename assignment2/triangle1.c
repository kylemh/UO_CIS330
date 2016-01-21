#include <stdio.h>

void print5Triangle() {
  int row, col;
   int triangle[5][9];

  /* Initialize space for characters */
  for (row = 0; row < 5; row++) {
    for (col = 0; col < (2*row+1); col++) {
      triangle[row][col] = col; //Convert space to value of column 
    }
  }

  /* Print a size-5 triangle  */
  for (row = 0; row < 5; row++) {
    /* Print spaces */
    for (col = 0; col < 5-row; col++) {
      printf("  ");
    }
    /* Print numbers */
    for (col = 0; col < (2*row+1); col++) {
      printf("%d ", triangle[row][col]);
    } 
    printf("\n");
  }
}