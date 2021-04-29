#include "Cards.h"

class Player
{
public:
	Player();
	~Player();
	void InsertCard(Card c);
	Card GetCard();
	Card GetCard(Suit s);
	void PrintHand();
	int id;
	std::vector<Card> hand;

private:

};
