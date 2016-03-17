// CIS330 - Assignment 5 - Game of Livestock, game.hpp
// By: Kyle Holmberg

// Here is a description of the rules:
// The universe of the Game of Livestock is an infinite two-dimensional orthogonal grid of square cells, 
// each of which is in one of four possible states: 

      // A cell can be empty or dead
      // A cell can have a sheep in it
      // A cell can have a wolf in it
      // A cell can have a farmer in it

// Every cell interacts with its eight neighbors, which are the cells that are horizontally, vertically, or diagonally adjacent. 
// At each step in time, the following transitions occur:
      // If a cell contains a sheep and is surrounded by more than three sheep neighbors, the cell dies (becomes empty) by overpopulation. 
      // Similarly, if a cell contains a wolf and has more than three wolf neighbors, it becomes empty.
      // If a cell contains a sheep and has at least one wolf as neighbor, the cell dies (becomes empty) by predation.
      // If a cell is empty and surrounded by exactly two neighbors of the same species, 
      // it is modified to contain a new instance of that species (reproduction). 
      // If a cell has two neighbors of more than one species, then the order in which they should be considered is sheep, wolf, and finally farmer.
      // If a cell contains a wolf and has at least one neighbor who is a farmer, the cell dies (becomes empty).
      // If a cell contains a wolf and has only wolf and empty neighbors, the cell dies (becomes empty) due to starvation.
      // If a cell contains a farmer and has at least one empty neighbor cell, it moves to a randomly selected empty neighbor cell. If there is no empty neighbor cell, the farmer cell remains the same.

#ifndef  GAME_OF_LIVESTOCK_H
#define  GAME_OF_LIVESTOCK_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>

class GameOfLivestock {
	typedef std::vector<int> Row; // One row of the matrix
	typedef std::vector<Row> Matrix; // Matrix: a vector of rows

public:
  GameOfLivestock(const int x_size, int y_size, int numSteps); // Constructor

  // include accessor fcns in this class .h . .hpp file
  int get_my_matrix_Zero_size() const { return size; } 	// The initial matrix 
  int get_my_matrix_New1_size() const { return size; } 	// The new working matrix 
  int get_my_matrix_Bkup_size() const { return size; } 	// The backup matrix 

  // user input methods
  int getX_size() const { return theXize; }
  int getY_size() const { return theYsize; }
  int getNumSteps() const { return theNumSteps; }

  // process functions
  void SetMatrixValues(Matrix &aMatrix);
  void Simulation(Matrix &theMarix);
  void PrintCurrentGol();
  void PrintInitMatrix(Matrix aMatrixPtr);


  int theXize; // theXize = number of columns in 2D Vector
  int theYsize; // theXize = number of rows    in 2D Vector
  int theNumSteps; // the Number of Game Iterations = Steps
  int currentStep; // currentStep
  int size;	// current size -- NOT Capacity -- of vector

};

#endif /* GAME_H_ */

