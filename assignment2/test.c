#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "triangle.h"

void clearInputBuffer() {
  while (getchar() != '\n');
}

int main() {
  int height = 0, num=0;
  int **triangle;

  printf("Problem 1 (a triangle of size 5):\n"); /* Fixed-size triangle */
  print5Triangle();
  
  printf("\nProblem 2:\n");
  while (num != 1 || size < 2 || size > 5) {
    printf("Please enter the height of the triangle [1-5]: ");
    num = scanf("%d", &height);
    clearInputBuffer();
  }
  
  allocateNumberTriangle(height, &triangle);
  initializeNumberTriangle((const int) height, triangle);
  printNumberTriangle((const int) height, triangle);
  
  // Free memory allocated earlier
  deallocateNumberTriangle(height, &triangle);

  return 0;
}
