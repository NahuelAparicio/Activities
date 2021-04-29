#include "Player.h"


Player::Player() { id = 0; }

Player::~Player() {}

void Player::InsertCard(Card c) { hand.push_back(c); }

Card Player::GetCard() {
	//returns random card 
	//elegir un numero del size del vector
	//recorrer vector if exist return card if not chose another num
	Card temp;
	return temp;
}

Card Player::GetCard(Suit s) {
	//Card with higher value in s
	Card temp;
	return temp;
}

void Player::PrintHand() {
	//printea por pantalla las cartas del jugador

	for (int i = 0; i < hand.size(); i++)
	{
		std::cout << hand[i].value << std::endl << hand[i].GetSuitString(hand[i].suit) << std::endl << std::endl;
	}
}


