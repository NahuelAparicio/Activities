#pragma once
#include "constants.h"



struct Player {
	int score;
	int posColX, posRowY;

	int addScore() {
		// Coin = score++;
		return score++;
	}
};



struct Board {

	Movement moveType;
	std::string board[NUM_ROWS][NUM_COLUMNS];
	int coins = 0;
	int stones = 0;

	int movePlayer(int rowY, int rowX) {
		// Moves player depending on the moveType
		switch (moveType)
		{
		case Movement::UP:
			if (checkMovement(rowY, rowX) == true) {
				std::cout << "Hell";
				return rowY--;
			}
		case Movement::DOWN:
			if (checkMovement(rowY, rowX) == true) {

				std::cout << "Hell";
				return rowY--;
			}
			return rowY++;
		case Movement::LEFT:
			if (checkMovement(rowY, rowX) == true) {

				std::cout << "Hell";
				return rowY--;
			}
				return rowX--;
		case Movement::RIGHT:
			if (checkMovement(rowY, rowX) == true) {

				std::cout << "Hell";
				return rowY--;
			}
				return rowX++;
		default:
			return 0;
		}
	}

	void printBoard(const Player &player) {

			//Fill array borders
			/*for (int i = 0; i < NUM_ROWS; i++)
			{
				for (int j = 0; j < NUM_COLUMNS; j++)
				{
					if (i == 0 || i == NUM_ROWS - 1) {
						board[i][j] = "__";
					}
					else if (j == 0 || j == NUM_COLUMNS - 1) {
						board[i][j] = " |";
					}
					else {
						board[i][j] = "  ";
					}
				}
			}*/
			
			

			//printArray
			for (int i = 0; i < NUM_ROWS; i++)
			{
				for (int j = 0; j < NUM_COLUMNS; j++)
				{
					//stones
					
				}
				std::cout << std::endl;
			}
			board[player.posRowY][player.posColX] = " P";

	}

	bool checkMovement(int &Y, int &X) {

		//true move   
		switch (moveType)
		{
		case Movement::UP:
			if ( board[Y--][X] == ".") {
				Y++;
				return true;
			}
		case Movement::DOWN:
			if (board[Y++][X] == "  ") {
				Y--;
				return true;
			}
		case Movement::LEFT:
			if (board[Y][X--] == "  ") {
				X++;
				return true;
			}
		case Movement::RIGHT:
			if (board[Y][X++] == "  ") {
				X--;
				return true;
			}
		default: return false;
		}
	}
};

void setPos() {

}





bool existsCoin() {
	// player pos?
	// true if next is coin depending on the movement type
	// false 
	return true;
}



bool gameOver() {
	//coins

	//!coins
	
	return true;
}


