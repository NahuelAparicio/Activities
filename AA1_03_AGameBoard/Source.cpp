#include "functions.h"
#include <time.h>



int main() {
	srand(time(NULL));
	Player _player;
	Board _board;

	initializeBoard(_board, _player);

	_board.printBoard(_player);

	_board.movePlayer(_player.posRowY, _player.posColX);

}