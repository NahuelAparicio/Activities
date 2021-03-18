#pragma once
#include <iostream>
#include "Types.h"

struct Player
{
	//var
	std::string id;
	int pos_x;
	int score;
	char *gun = new char[20];

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