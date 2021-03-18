#pragma once
#include "Types.h"

struct Player
{
	//var
	std::string id;
	int posX, posY;
	int score;
	char gun;

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