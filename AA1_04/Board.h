#pragma once
#include "Player.h"
#include <iostream>
#include "Constants.h"
#include "Types.h"

struct Board {
	char board[NUM_ROWS][NUM_COLUMNS];
	int coins = 0;
	int stones = 0;
	Player player;

	bool checkMovement(int playerPosX, int playerPosY, Movement moves) {

		switch (moves)
		{
		case Movement::UP:
			break;
		case Movement::DOWN:
			break;
		case Movement::LEFT:
			break;
		case Movement::RIGHT:
			break;
		case Movement::COUNT:
			break;
		default:
			break;
		}

	}
	
	void printBoard() {

		board[player.positionX][player.positionY] = 'P';

		for (int i = 0; i < coins; i++)
		{
			board[rand() % NUM_ROWS][rand() % NUM_COLUMNS] = '$';
		}

		for (int i = 0; i < stones; i++) {
			board[rand() % NUM_ROWS][rand() % NUM_COLUMNS] = 'O';
		}

		for (int i = 0; i < NUM_ROWS; i++)
		{
			for (int j = 0; j < NUM_COLUMNS; j++)
			{
				if (board[i][j] != '$' && board[i][j] != 'O' && board[i][j] != 'P') board[i][j] = '.';
				
				std::cout << board[i][j];
			}
			std::cout << std::endl;
		}
		
	}
	/*
	* int movePlayer(int rowY, int rowX) {
		// Moves player depending on the moveType
		switch (moves)
		{
		case Movement::UP:
			if (checkMovement()) {
				
				return 0;
			}
		case Movement::DOWN:
			if (checkMovement()) {

				std::cout << "Hell";
				return rowY--;
			}
			return rowY++;
		case Movement::LEFT:
			if (checkMovement()) {

				std::cout << "Hell";
				return rowY--;
			}
			return rowX--;
		case Movement::RIGHT:
			if (checkMovement()) {

				std::cout << "Hell";
				return rowY--;
			}
			return rowX++;
		default:
			return 0;
		}
	}
	*/
	
};

void initializeBoard(Board& board, Player& player) {
	int square = (NUM_COLUMNS) * (NUM_ROWS);

	// random stones 20% 
	board.stones = rand() % int(square * 0.2);

	// random coins 30%
	board.coins = rand() % int(square * 0.3);

	// player random 
	//max NUM_ROW, max NUM_COLUMNS
	player.setPos(rand() % NUM_COLUMNS, rand() % NUM_ROWS);
}