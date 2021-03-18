#pragma once
#include "Types.h"

struct Player
{
	//var
	std::string id;
	int **position = new int*[];
	int score;

	//pistola?

	void init(std::string name, int position) {
		id = name;
		score = 0;
	}
	Ball shoot() {

		//shoot 1 bola, la primera, la bola se elimina del cargador y la
		//función la devuelve
		
	}
};