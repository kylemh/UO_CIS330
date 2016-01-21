#include <stdlib.h>
#include <stdio.h>

void allocateNumberTriangle(const int height, int ***triangle) {
  int i, j;

  /* Allocate memory for a 2-D array */
  (*triangle) = (int **) malloc(height * sizeof(int*));
  for (i = 0; i < height*2+1; i++) 
    (*triangle)[i] = (int *) malloc(height * sizeof(int));

}

void initializeNumberTriangle(const int height, int **triangle) {
  int i, j;
  /* Fill the allocated space with values */
  for (i = 0; i < height; i++) 
    for (j = 0; j < (2*height-1); j++) 
      triangle[i][j] = j; //Convert space to value of column
}

void deallocateNumberTriangle(const int height, int ***triangle) {
  int i;
  // Free allocated memory
  for (i = 0; i < height; i++) 
    free((*triangle)[i]);
  free(*triangle);
}

void printNumberTriangle(const int height, int **triangle) {
  int i, j;
  for (i = 0; i < height; i++) {
    /* Print spaces */
    for (j = 0; j < height-i; j++) {
      printf("  ");
    }
    /* Print numbers */
    for (j = 0; j < (2*i + 1); j++) {
      printf("%d ", triangle[i][j]);
    } 
    printf("\n");
  }
}
  
