//#pragma once
#include "Types.h"
#include "Constants.h"
#include <stdio.h>
#include <vector>

class Panel {

private:
	int size;
	//Ball* panel = new Ball[1000];
	std::vector<Ball> panel;

public:

	Panel(int randBalls) {
		size = randBalls;
		panel.resize(1000);
		for (int i = 0; i < randBalls; i++)
		{
			Ball newBall;
			panel[i] = newBall;
		}
	}

	//funciona
	void insert(int position, Ball ball) {
		//Ball* tempList = new Ball[1000]; PRE VECTOR
		//std::vector<Ball> tempList;
		//tempList.resize(1000);

		//panel.push_back(ball);

		panel.insert(panel.begin() + 1, ball);

		/*
		tempList[position] = ball;
		size++;
		int offset = 0;
		for (int i = 0; i < size; i++)
		{
			if (i == position)
				offset++;
			tempList[i + offset] = panel[i];
		}
		panel = tempList;*/
	}
	//funciona
	int verifier(int position, Ball ball) {
		//verify if there are 3 balls and point the first one.
		BallType color = ball.color;
		if ((panel[position].color == color) &&
			(panel[position + 1].color == color) &&
			(panel[position + 2].color == color))
			return position;
		else if ((panel[position].color == color) &&
			(panel[position + 1].color == color) &&
			(panel[position - 1].color == color))
			return position - 1;
		else if ((panel[position].color == color) &&
			(panel[position - 1].color == color) &&
			(panel[position - 2].color == color))
			return position - 2;
		else
			return -1;
	}
	//funciona
	void deleteThree(int position) {
		//delete 3 balls
		//Ball* tempList = new Ball[size -3]; PREVECTOR

		std::vector<Ball> tempList;
		tempList.resize(size - 3);
		size -= 3;
		int offset = 0;
		for (int i = 0; i < size; i++)
		{
			if (i == position)
				offset = 3;
			tempList[i] = panel[i + offset];
		}
		panel = tempList;

		//borar temp list i panel

		/*delete[]tempList;
		delete[]panel;*/

	}
	//funciona
	void insertThree() {

		//Ball* tempList = new Ball[1000]; PREVECTOR

		std::vector<Ball> tempList;
		tempList.resize(1000);
		int offset = 0;
		size += 3;
		for (int i = 0; i < 3; i++)
		{
			Ball newBall;
			tempList[i] = newBall;
		}
		for (int i = 0; i < size; i++)
		{
			tempList[i + 3] = panel[i];
		}
		panel = tempList;
	}
	//debug 
	void PrintPanelBalls()
	{
		std::cout << "Panel Balls: " << size << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << (int)panel[i].color << "";
		}
		std::cout << "\n";
	}

	void Draw(HANDLE hConsole)
	{
		std::cout << "Panel Balls: " << size << "\n";
		for (int i = 0; i < size; i++)
		{
			int color = (int)panel[i].GetColor();
			SetConsoleTextAttribute(hConsole, color); // Set console "theme"
			std::cout << 0 << "";
		}
		std::cout << "\n";
	}

};



/*
struct Panel
{
	int size; //tamaño del panel
	Ball* panel = new Ball[1000];

	void init() {
		//inicializa el panel con un num_aleatorio de bolas
		//que leido del estandar input
		int randNumBalls;
		std::cout << "Introduce el numero de bolas: \n";
		std::cin >> randNumBalls;
		size = randNumBalls;

		for (int i = 0; i < randNumBalls; i++)
		{
			Ball newBall;
			panel[i] =  newBall;
		}
	}


	//funciona
	void insert(int position, Ball ball) {
		//inserta la bola ball en el panel de bolas en la posicio indicada.
		//la inserción la realiza desplazando a derecha las bolas
		Ball* tempList = new Ball[1000];
		tempList[position] = ball;
		size++;
		int offset = 0;
		for (int i = 0 ; i < size; i++)
		{
			if (i == position)
				offset++;
			tempList[i + offset] = panel[i];
		}
		panel = tempList;
	}
	//funciona
	int verifier(int position, Ball ball) {
		//verify if there are 3 balls and point the first one.
		BallType color = ball.color;
		if ((panel[position].color == color) &&
			(panel[position + 1].color == color) &&
			(panel[position + 2].color == color))
			return position;
		else if ((panel[position].color == color) &&
			(panel[position + 1].color == color) &&
			(panel[position - 1].color == color))
			return position - 1;
		else if ((panel[position].color == color) &&
			(panel[position - 1].color == color) &&
			(panel[position - 2].color == color))
			return position - 2;
		else
			return - 1;
	}
	//funciona
	void deleteThree(int position) {
		//delete 3 balls

		Ball* tempList = new Ball[size - 3];
		size -= 3;
		int offset = 0;
		for (int i = 0; i < size; i++)
		{
			if (i == position)
				offset = 3;
			tempList[i] = panel[i + offset];
		}
		panel = tempList;

		//borar temp list i panel

		delete[]tempList;
		delete[]panel;

	}
	//funciona
	void insertThree() {

		Ball* tempList = new Ball[1000];

		int offset = 0;
		size += 3;
		for (int i = 0; i < 3; i++)
		{
			Ball newBall;
			tempList[i] = newBall;
		}
		for (int i = 0; i < size; i++)
		{
			tempList[i + 3] = panel[i];
		}
		panel = tempList;
	}
	//debug 
	void PrintPanelBalls()
	{
		std::cout << "Panel Balls: " << size << "\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << (int)panel[i].color << "";
		}
		std::cout << "\n";
	}
	void Draw(HANDLE hConsole)
	{
		std::cout << "Panel Balls: " << size << "\n";
		for (int i = 0; i < size; i++)
		{
			int color = (int)panel[i].GetColor();
			SetConsoleTextAttribute(hConsole, color); // Set console "theme"
			std::cout << 0 << "";
		}
		std::cout << "\n";
	}
};
*/


