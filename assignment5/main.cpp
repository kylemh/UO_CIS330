// CIS330 - Assignment 5 - Game of Livestock, main
// By: Kyle Holmberg

#include "game.hpp"

using namespace std;

typedef vector<int> Row; // One row of the matrix
typedef vector<Row> Matrix; // Matrix: a vector of rows

int main() { // main function for Testing	
	int X_grid_size = 0;
	int Y_grid_size = 0;
	int stepNums = 0;
	int currentStep = 0;

	cout << "Please enter the size of the grid (int int): "; // NOTE: int  -- also restrict to 50+2 
		  cin >> X_grid_size; 
		  cin >> Y_grid_size;
	cout << "Please enter the number of steps (int): "; // NOTE: int -- also restrict to 10 
		  cin >> stepNums;

	GameOfLivestock GoL(X_grid_size, Y_grid_size, stepNums);

    // Make 2D vector arrays == Matrices +2 rows and +2 columns to facilitate processing 
    Matrix *InitMatrixPtr = new Matrix(Y_grid_size+1,Row(X_grid_size+1)); // Initial Automatically Zeroe-Out Matrix - MatrixPtr Passed to SetMatrixValues() randomized initializtion function / method
    Matrix *New1MatrixPtr = new Matrix(Y_grid_size+1,Row(X_grid_size+1)); // MatrixPtr Passed to: GoL.Simulation(*New1MatrixPtr); 
    Matrix *BkupMatrixPtr = new Matrix(Y_grid_size+1,Row(X_grid_size+1)); // OPTIONAL Comparison of Current Matrix to Bkup in order to see if Matrix is 'Steady-State'
	
    GoL.SetMatrixValues(*InitMatrixPtr);
    GoL.PrintInitMatrix(*InitMatrixPtr);
    cout << endl;

    //Loop of user-specified amount of steps.
	currentStep = 1;
	int compareLoop = 1;
	while(currentStep <= stepNums) {	
     	cout << "Step "  << currentStep << ":" << endl;
     	compareLoop = 1;
		if(currentStep == 1){
     		*New1MatrixPtr = *InitMatrixPtr;
     		*BkupMatrixPtr = *New1MatrixPtr;
		} else {
			*BkupMatrixPtr = *New1MatrixPtr;
		}
		GoL.Simulation(*New1MatrixPtr); 

		compareLoop = 2;
		currentStep++;
	}
	return EXIT_SUCCESS; //successful execution
}