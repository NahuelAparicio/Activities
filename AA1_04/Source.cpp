#include "Player.h"
#include "Board.h"
#include <iostream>


int main() {
	Board board;
	

	initializeBoard(board, board.player);
	board.printBoard();
}