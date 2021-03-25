#include "Player.h"
#include "Panel.h"
#include <conio.h>
#include <time.h>
#include <string>
#include <iostream>
#include "InputData.h"

Player player;
Panel panel;



//Print debug colors
void printColors(HANDLE console)
{
	// you can loop k higher to see more color choices
	for (int k = 1; k < 255; k++)
	{
		// pick the colorattribute k you want
		SetConsoleTextAttribute(console, k);
		std::cout << k << " Test color Theme" << std::endl;
	}
}

int main(int argc, char** argv)
{
	srand(time(NULL));
	player.init("Jordi", 10);
	panel.init();
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//-*-*- CONSOLE COLOR TEST -*-*-
	//printColors(hConsole);
	//system("pause");


	InputData input; //Data structure that manages and stores all inputs that we want.
	int theme = 1; // Actual console "theme" (appearance)
	bool fire = false; //Fire flag to check fire key

	while (!input.Keyboard[(int)InputKey::ESCAPE])
	{
		//--INPUT
		input.Update();

		//--UPDATE
		std::string output = "";
		output += "UP: " + std::to_string(input.Keyboard[(int)InputKey::UP]) + "\n";
		output += "DOWN: " + std::to_string(input.Keyboard[(int)InputKey::DOWN]) + "\n";
		output += "LEFT: " + std::to_string(input.Keyboard[(int)InputKey::LEFT]) + "\n";
		output += "RIGHT: " + std::to_string(input.Keyboard[(int)InputKey::RIGHT]) + "\n";

		//Check if fire key is pressed in this frame and set
		if (input.Keyboard[(int)InputKey::FIRE] && !fire)
		{
			theme = (theme++) % 255; //Range between 0 and 254
			player.shoot();
			fire = true;
		}
		else if (!input.Keyboard[(int)InputKey::FIRE] && fire)
		{
			fire = false;
		}
		system("cls");
//limpiar estaba arriba
		//--DRAW
		theme = 1 % 255;
		SetConsoleTextAttribute(hConsole, theme); // Set console "theme"
		std::cout << output;
		panel.Draw(hConsole);
		player.Draw(hConsole);

	}
}
//para probar las funciones a mano
void ClassicDebug()
{
	//debug
	while (true)
	{
		Ball newBall;
		char key;
		std::cout << "introducir tecla" << "\n";
		key = _getch();
		int n;
		int color;

		switch (key) {
		case 'q':
			player.shoot();
			break;
		case '1':
			player.PrintBalls();
			break;
		case '2':
			panel.PrintPanelBalls();
			break;
		case 'w':
			std::cout << "insert new ball in: " << "\n";
			std::cin >> n;
			panel.insert(n - 1, newBall);
			break;
		case 'e':
			std::cout << "Check 3 ball same color in : " << "\n";
			std::cin >> n;
			std::cout << "with color(number) : " << "\n";
			std::cin >> color;
			newBall.color = (BallType)color;
			std::cout << "Comprobacion: " << panel.verifier(n - 1, newBall) << "\n";
			break;
		case 'r':
			std::cout << "delete 3 balls in: " << "\n";
			std::cin >> n;
			panel.deleteThree(n - 1);
			break;
		case 't':
			std::cout << "add 3 balls at the end: " << "\n";
			panel.insertThree();
			break;
		default:
			break;
		}
	}
}