//#pragma once
#include "Types.h"
#include "Constants.h"

struct Player
{
	//var
	std::string id;
	int score;
	int playerPos;

	Ball ball;
	Ball* gunAmmo[]; //cargador


	void init(std::string name, int position) {
		id = name;
		playerPos = position;
		score = 0;

		//initialize the gunAmmo
		for (int i = 0; i < MAXBALLS - 30; i++)
		{
			int tempType = rand() % 5; // get a rand name to fill the array
			switch (tempType)
			{
			case 0:
				gunAmmo[i] = new Ball(Ball::RED);
			case 1:
				gunAmmo[i] = new Ball(Ball::BLUE);
			case 2:
				gunAmmo[i] = new Ball(Ball::YELLOW);
			case 3:
				gunAmmo[i] = new Ball(Ball::ORANGE);
			case 4:
				gunAmmo[i] = new Ball(Ball::GREEN);
			}
		}
	}
	Ball shoot() {

		//shoot 1 bola, la primera, la bola se elimina del cargador y la
		//función la devuelve
		
		Ball _firstball = *gunAmmo[0]; //get firstBall

		delete[0]gunAmmo; //delete first ball
		
		return _firstball;		
	}
};