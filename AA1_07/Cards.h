#include <cstdlib>
#include <iostream>
#include <vector>

enum class Suit { SPADES, CLUBS, CUPS, COINS, COUNT };

class Card
{
public:
	Suit suit;
	int value;
	Card();
	~Card();
	Suit SetSuit(int value);
	std::string GetSuitString(Suit s);

private:

};

Card::Card()
{
	value = rand() % 12;
	suit = SetSuit(rand() % 4 + 1);
}

Card::~Card() {}

Suit Card::SetSuit(int value) {
	switch (value)
	{
		case 1:	return Suit::SPADES;
		case 2:	return Suit::CLUBS;
		case 3:	return Suit::CUPS;
		case 4:	return Suit::COINS;
		default: return Suit::COUNT;
	}
}

bool operator==(const Card &c1, const Card &c2) {
	return c1.suit == c2.suit && c1.value == c2.value;
}

std::string Card::GetSuitString(Suit s) {
	switch (s)
	{
	case Suit::SPADES: return "Spades";
	case Suit::CLUBS: return "Clubs";
	case Suit::CUPS: return "Cups";
	case Suit::COINS: return "Coins";
	case Suit::COUNT: return "error";
	default:
		return "error";
	}
}