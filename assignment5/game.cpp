// CIS330 - Assignment 5 - Game of Livestock, game.cpp
// By: Kyle Holmberg

#include "game.hpp"

using namespace std;

typedef vector<int> Row; // One row of the matrix
typedef vector<Row> Matrix; // Matrix: a vector of rows

GameOfLivestock::GameOfLivestock(int x_size, int y_size, int numSteps) {
	theXize = x_size;
	theYsize = y_size;
	theNumSteps = numSteps;
}

void GameOfLivestock::PrintInitMatrix(Matrix aMatrixPtr) {
	int X = getX_size();
	int Y = getY_size();

	for (int i=0; i <= Y; i++){ 
		for (int j=0; j <= X; j++){ 
			if(aMatrixPtr[i][j] == 1) {
				cout <<  'S';
			} else if(aMatrixPtr[i][j] == 2) {
				cout <<  'W';
			} else if(aMatrixPtr[i][j] == 3) {
				cout <<  'F'; 
			} else {
				cout <<  '.'; 
			}
		}
		cout << endl;
	}
	cout << endl << endl;
}

void GameOfLivestock::SetMatrixValues(Matrix &aMatrix) {
	int X = getX_size();
	int Y = getY_size();

	/* initialize random seed: */
	srand(time(NULL));

	for (int i=0; i < Y+1; i++){ 
		for (int j=0; j < X+1; j++) { 
			if(X > 3 && Y > 3) {
			int randCellVal = (rand() % (max(X,Y)));  
			aMatrix[i][j] = randCellVal;
			} else {
			cout << "FATAL ERROR: SetMatrixValues = Provided X and Y Values are not greater than 3, each." << endl;
			}
		}
	}
}

void GameOfLivestock::Simulation(Matrix &theMatrix) {
	int X = getX_size();
	int Y = getY_size();

	// USE tempMatrix if you'd like to make changes on a step-by-step basis, as opposed to real-time.
	/****************************************************************************************
	 * Create and copy primary Matrix to a temporary matrix so changes can be entered into a
	 * grid WITHOUT affecting the calculations being performed cells in the primary Matix.
	****************************************************************************************/
	/*
	vector<vector<int> > tempMatrix;
	tempMatrix.resize(sizeRows); //(sizeRows+2) added 2-cell buffer at begin = 0 and end = Y+1 Rows
	for (int i = 0; i < sizeRows; ++i) {
		tempMatrix[i].resize(sizeCols); //(sizeCols+2) added 2-cell buffer at begin = 0 and end = X+1 Cols
	}
	tempMatrix = theMatrix;
	*/

	for(int i = 0; i < Y; i++) { //EACH ROW	
		for(int j = 0; j < X; j++) { //EACH COLUMN
			int sheep_neighbor_cnt = 0;
			int wolf_neighbor_cnt = 0;
			int farmer_neighbor_cnt = 0;
			int empty_neighbor_cnt = 0;

			// Prevent issues with checking neighbors when cell is in corner or along border (i.e. when neighbor count does NOT equal 8)
			int begNbrRow = (i - 1 < 0) ? i : i-1;
			int begNbrCol = (j - 1 < 0) ? j : j-1;
			int endNbrRow = (i + 1 > Y) ? i : i+1;
			int endNbrCol = (j + 1 > X) ? j : j+1;

			// arrays to store locations of empty neighbors for farmer's rules of life
			int randRowCandidates[8];
			int randColCandidates[8];

			/* Sheep */
			if (theMatrix[i][j] == 1) {
				for (int rowNum=begNbrRow; rowNum<=endNbrRow; rowNum++) {
					for (int colNum=begNbrCol; colNum<=endNbrCol; colNum++) {
						if (rowNum == i && colNum == j) {
							continue; //ignore the cell whose neighbors we are checking
						} else if (theMatrix[rowNum][colNum] == 1) { //if the neighbor being checked is a sheep
							sheep_neighbor_cnt = sheep_neighbor_cnt + 1;
						} else if (theMatrix[rowNum][colNum] == 2) { //if the neighbor being checked is a wolf
							wolf_neighbor_cnt = wolf_neighbor_cnt + 1;
						} else {
							continue; //if neighbor is empty, do nothing
						}
					}
				}
				if (sheep_neighbor_cnt > 3 || wolf_neighbor_cnt >= 1) {
					theMatrix[i][j] = 0; //sheep dies
				}
			}

			/* Wolf */
			else if (theMatrix[i][j] == 2) {
				for (int rowNum=begNbrRow; rowNum<=endNbrRow; rowNum++) {
					for (int colNum=begNbrCol; colNum<=endNbrCol; colNum++) {
						if (rowNum == i && colNum == j) {
							continue; //ignore the cell whose neighbors we are checking
						} else if (theMatrix[rowNum][colNum] == 2) { //if the neighbor being checked is a wolf
							wolf_neighbor_cnt = wolf_neighbor_cnt + 1;
						} else if (theMatrix[rowNum][colNum] == 3) { //if the neighbor being checked is a farmer
							farmer_neighbor_cnt = farmer_neighbor_cnt + 1; //gauranteed death
						} else if (theMatrix[rowNum][colNum] == 1) { //if the neighbor being checked is a sheep
							sheep_neighbor_cnt = sheep_neighbor_cnt + 1;
						} else {
							continue;
						}
					}
				}
				if (farmer_neighbor_cnt >= 1 || sheep_neighbor_cnt == 0 || wolf_neighbor_cnt > 3) {
					theMatrix[i][j] = 0; //kill the wolf
				} else if (farmer_neighbor_cnt == 0 && sheep_neighbor_cnt == 0 && wolf_neighbor_cnt == 0) { // all empty neighbors
					theMatrix[i][j] = 0;
				}
			}

			/* Farmer */
			else if (theMatrix[i][j] == 3) {
				for (int rowNum=begNbrRow; rowNum<=endNbrRow; rowNum++) {
					for (int colNum=begNbrCol; colNum<=endNbrCol; colNum++) {
						if (rowNum == i && colNum == j) {
							continue; //ignore the cell whose neighbors we are checking
						} else if (theMatrix[rowNum][colNum] == 0 || theMatrix[rowNum][colNum] > 3) { //neighbor is empty
							empty_neighbor_cnt = empty_neighbor_cnt + 1;
							randRowCandidates[empty_neighbor_cnt-1] = rowNum;
							randColCandidates[empty_neighbor_cnt-1] = colNum;
						} else {
							continue; //if neighbor is a mammal: ignore
						}
					}
				}
				if (empty_neighbor_cnt >= 1) {
					theMatrix[i][j] = 0; //remove farmer from original location
					//srand(empty_neighbor_cnt); //not size of candidate array, because there may exist empty array elements.
					int randIndex = rand() % empty_neighbor_cnt;
					theMatrix[randRowCandidates[randIndex]][randColCandidates[randIndex]] = 3; //move farmer to random empty cell
				} else {
					continue; //no empty neighbors for farmer to move to
				}
			}

			/* Empty */
			else {
				for (int rowNum=begNbrRow; rowNum<=endNbrRow; rowNum++) {
					for (int colNum=begNbrCol; colNum<=endNbrCol; colNum++) {
						if (rowNum == i && colNum == j) {
							continue; //ignore the cell whose neighbors we are checking
						} else if (theMatrix[rowNum][colNum] == 1) { //if the neighbor being checked is a sheep
							sheep_neighbor_cnt = sheep_neighbor_cnt + 1;
						} else if (theMatrix[rowNum][colNum] == 2) { //if the neighbor being checked is a wolf
							wolf_neighbor_cnt = wolf_neighbor_cnt + 1;
						} else if (theMatrix[rowNum][colNum] == 3) { //if the neighbor being checked is a farmer
							farmer_neighbor_cnt = farmer_neighbor_cnt + 1;
						} else {
							continue;
						}
					}
				}
				if (sheep_neighbor_cnt == 2) {
					theMatrix[i][j] = 1; //become a sheep
				} else if (wolf_neighbor_cnt == 2) {
					theMatrix[i][j] = 2; //become a wolf
				} else if (farmer_neighbor_cnt == 2) {
					theMatrix[i][j] = 3; //become a farmer
				} else {
					continue;
				}
			}
		}
	}

	theMatrix = theMatrix; //set actual Matrix to calculated temp array
	for (int printingRow = 0; printingRow < (Y+1); printingRow++) { //convert 2d-array into a graphical, string representation.
		for (int printingCol = 0; printingCol < (X+1); printingCol++) { 
			if(theMatrix[printingRow][printingCol] == 1) {
				cout << 'S';
			} else if(theMatrix[printingRow][printingCol] == 2) {
				cout << 'W';
			} else if(theMatrix[printingRow][printingCol] == 3) {
				cout << 'F';
			} else {
				cout << '.';
			}
		}
		cout << endl;
	}
	cout << endl;
}