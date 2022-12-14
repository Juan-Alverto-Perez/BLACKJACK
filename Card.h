#pragma once
#include <vector>
class Card
{
private:
	char suit;
	char value;
public: 
	
	Card();
	Card(char suit, char value);
	char getSuit();
	char getValue();
	

};

