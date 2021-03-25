//#pragma once
#include "Types.h"
#include "Constants.h"
template <typename E>


struct Panel
{
	int size; //tamaño del panel
	Ball *panel[];
	
	void init() {
		//inicializa el panel con un num_aleatorio de bolas 
		//que leido del estandar input
		int randNumBalls;
		size = PANELSIZE;
		std::cout << "Introduce el numero de bolas: \n";
		std::cin >> randNumBalls;

		for (int i = 0; i < randNumBalls; i++)
		{
			int temp = rand() % 5;
			switch (temp)
			{
			case 0:
				panel[i] = new Ball(Ball::RED);
			case 1:
				panel[i] = new Ball(Ball::BLUE);
			case 2:
				panel[i] = new Ball(Ball::YELLOW);
			case 3:
				panel[i] = new Ball(Ball::ORANGE);
			case 4:
				panel[i] = new Ball(Ball::GREEN);
			}
		}
	}
	void insert(int position, Ball ball) {
		//inserta la bola ball en el panel de bolas en la posicio indicada. 
		//la inserción la realiza desplazando a derecha las bolas
		int* temp = new int[size + 1];
		for (int i = 0; i < position - 1; i++)
		{
			temp[i] = panel[i];
		}
		for (int i = position; i < size; i++)
		{
			temp[i + 1] = panel[i];
		}
		temp[position] = ball;
		size++;
		delete[]panel;
		panel = temp;
		temp = nullptr;
	}

	int verifier(int position, Ball ball) {
		//verify if there are 3 balls and point the first one.
		if (panel[position] == panel[position + 1] == panel[position + 2]) return position;
		else if (panel[position] == panel[position + 1] == panel[position - 1]) return position - 1;
		else if (panel[position - 2] == panel[position - 1] == panel[position]) return position - 2;
		else return 0;
	}

	void deleteThree(int position) {
		//delete 3 balls 
		delete[position]panel;
		delete[position + 1]panel;
		delete[position + 2]panel;
	}

	void insertThree() {
		//inserta 3 bolas random en el panel por el final
		int* temp = new int[size];

		//size == ultima posicion

		Ball temp[3];
		for (int i = 0; i < 3; i++)
		{
			int tempType = rand() % 5;
			switch (tempType)
			{
			case 0:
				temp = new Ball(Ball::RED);
			case 1:
				temp = new Ball(Ball::BLUE);
			case 2:
				temp = new Ball(Ball::YELLOW);
			case 3:
				temp = new Ball(Ball::ORANGE);
			case 4:
				temp = new Ball(Ball::GREEN);
			}
		}
		panel[size] = temp[0];
		panel[size - i] = temp[1];
		panel[size - i] = temp[2];
	}
};

