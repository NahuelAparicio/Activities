#pragma once
#include "Types.h"
#include "Constants.h"
template <typename E>


struct Panel
{
	int **size = new int* []; //tamaño del panel
	Ball *panel ;
	int num_balls;
	
	void init() {
		//inicializa el panel con un num_aleatorio de bolas 
		//que leido del estandar input
		std::cout << "Introduce el numero de bolas: \n";
		std::cin >> ; 
	}
	void insert(int position, Ball ball) {
		//inserta la bola ball en el panel de bolas en la posicio indicada. 
		//la inserción la realiza desplazando a derecha las bolas
	}

	void insertThree() {
		//inserta 3 bolas random en el panel por el final
	}
};

