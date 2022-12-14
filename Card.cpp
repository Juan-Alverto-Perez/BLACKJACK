#include "Card.h"

#include <vector>

Card::Card()
{
	this->suit = 0;
	this->value = 0;
}

Card::Card(char suit, char value)
{
	this->suit = suit;
	this->value = value;
}


char Card::getSuit()
{
	return this->suit;
}

char Card::getValue()
{
	return this->value;
}
