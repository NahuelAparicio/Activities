#pragma once
#include "Types.h"
#include "Constants.h"
struct Player
{
	//var

	int numBalls;
	std::string id;
	Ball ball;
	int score;
	int playerPos;

	Ball* gunAmmo[];

	void init(std::string name, int position) {
		id = name;
		playerPos = position;
		score = 0;
		numBalls = MAXBALLS;


		for (int i = 0; i < numBalls; i++)
		{
			int temp = rand() % 5; // get a rand name to fill the array
			switch (temp)
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
		
		Ball myBallWas = gunAmmo[0];

		delete[0]gunAmmo;

		int* temp = new int[size];
		
	}
};