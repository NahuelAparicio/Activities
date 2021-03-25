#pragma once
#include<iostream>
#include <stdlib.h>
//colors
enum BallType { BLUE, AGUAMARINA, YELLOW, GREEN, RED, COUNT };
struct Ball 
{
	BallType color = (BallType)(rand() % (int)(BallType::COUNT));
	int GetColor() 
	{
		switch (color)
		{
		case BLUE:
			return 1 % 255;
			break;
		case AGUAMARINA:
			return 3 % 255;
			break;
		case YELLOW:
			return 6 % 255;
			break;
		case GREEN:
			return 2 % 255;
			break;
		case RED:
			return 4 % 255;
			break;
		default:
			break;
		}
	}
};

