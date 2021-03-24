#pragma once
#include "Types.h"
#include "Constants.h"
template <typename E>


struct Panel
{
	int size; //tamaño del panel
	Ball *panel ;
	
	void init() {
		//inicializa el panel con un num_aleatorio de bolas 
		//que leido del estandar input
		size = PANELSIZE;
		Ball ball;
		std::cout << "Introduce el numero de bolas: \n";
		std::cin >> size; 

		for (int i = 0; i < size; i++)
		{
			int temp = rand() % 5;
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
		else return size;
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
		for (int i = 0; i < position; i++)
		{
			temp[i] = panel[i];
		}
		for (int i = position + 3; i < size; i++)
		{
			temp[i - 3] = panel[i];
		}
		for (int i = size - 3; i < position; i++)
		{
			int tempType = rand() % 5;
			switch (tempType)
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
		size++;
		delete[]panel;
		panel = temp;
		temp = nullptr;
	}
};

