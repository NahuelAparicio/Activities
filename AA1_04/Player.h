#pragma once

struct Player {
	
	int Score;
	int positionX, positionY;

	void addScore(int points) {

		Score += points;
	}

	void setPos(int posx, int posy) {
		positionX = posx;
		positionY = posy;
	}

};