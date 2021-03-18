#pragma once
#include "Types.h"

struct Panel
{
	int size; //tamaño del panel
	char* panel = new char[size * size];
	Ball *panel ;
	
	void init() {
		//inicializa el panel con un num_aleatorio de bolas que leido del estandar input
	}
	void insert(int position, Ball ball) {
		//inserta la bola ball en el panel de bolas en la posicio indicada. 
		//la inserción la realiza desplazando a derecha las bolas
	}

	void insertThree() {
		//inserta 3 bolas random en el panel por el final
	}
};