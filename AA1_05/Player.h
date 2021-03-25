//#pragma once
#include "Types.h"
#include "Constants.h"
#include <Windows.h>

struct Player
{
	//var
	std::string id;
	int score;
	int playerPos;

	Ball ball;
	Ball *gunAmmo = new Ball[MAXBALLS]; //cargador de 50
	int currentAmmo = 0;
	int initAmmo;

	//funciona
	void init(std::string name, int position) {
		initAmmo = MAXBALLS - 30;
		id = name;
		playerPos = position;
		score = 0;

		//initialize the gunAmmo
		for (int i = 0; i < initAmmo; i++)
		{
			Ball newBall;
			gunAmmo[i] = newBall;
		}
		currentAmmo = initAmmo;
	}
	//funciona
	Ball shoot() {

		//shoot 1 bola, la primera, la bola se elimina del cargador y la
		//función la devuelve
		Ball _firstball = gunAmmo[currentAmmo - 1]; //get firstBall

		//delete(&gunAmmo[currentAmmo - 1]); //delete first ball
		currentAmmo--;
		return _firstball;		
	}
	//funciona
	void PrintBalls() 
	{
		std::cout <<"Current ammo: " << currentAmmo <<"\n";
		for (int i = 0; i < currentAmmo; i++)
		{
			std::cout << (int)gunAmmo[i].color << "";
		}
		std::cout << "\n";
	}
	void Draw(HANDLE hConsole)
	{
		std::cout << "Current ammo: " << currentAmmo << "\n";
		for (int i = 0; i < currentAmmo; i++)
		{
				int color = (int)gunAmmo[i].GetColor() ;
			SetConsoleTextAttribute(hConsole,color); // Set console "theme"
			std::cout << 0 << "\n";
		}
		
	}
};