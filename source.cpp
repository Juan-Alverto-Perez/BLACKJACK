#include "Card.h"
#include <iostream>

#include <stdlib.h>     
#include <time.h>

using namespace std;

vector<Card> createDeck(int numDecks, vector <Card> Deck);

void printCards(vector <Card> Deck);

vector<Card> shuffle(vector<Card> Deck);

int getTotal(vector<Card> hand);

void giveCard(vector<Card>& hand, vector<Card>& deck);

void dealOut(vector<Card>& player, vector<Card>& dealer, vector<Card>& shuffledDeck);

void wonHand();

void lostHand();

struct ace
{
	int totalOne;
	int totaltwo;
};




int main()
{
	int numDecks{ 0 };
	vector <Card> Deck;

	//cin how mnay decks the user would like to use
	cout << "How many decks?" << endl;
	cin >> numDecks;
	cout << endl;

	//creates standard deck accoring to the amount of decks needed in order
	Deck = createDeck(numDecks, Deck);
	
	//prints deck
	printCards(Deck);


	//shuffling deck
	vector<Card> shuffledDeck = shuffle(Deck);


	//pring shuffled deck
	printCards(shuffledDeck);


	//creating dealer and player hand then dealing out two cards.
	vector<Card> player;
	vector<Card> dealer;
	dealOut(player, dealer, shuffledDeck);




}



vector<Card> createDeck(int numDecks, vector <Card> Deck)
{
	int current{ 1 };
	for (int i{ 0 }; i < ((numDecks * 52) / 4); i++)
	{
		if (current > 13)
		{
			current = 1;
		}

		Card tempD('D', current);
		Deck.push_back(tempD);
		Card tempH('H', current);
		Deck.push_back(tempH);
		Card tempS('S', current);
		Deck.push_back(tempS);
		Card tempC('C', current);
		Deck.push_back(tempC);
		current++;

	}
	return Deck;
}

void printCards(vector <Card> Deck)
{
	for (int i{ 0 }; i < Deck.size(); i++)
	{
		char suit = Deck.at(i).getSuit();
		char value = Deck.at(i).getValue();


		switch (value)
		{
		case 1:
			value = 'A';
			break;
		case 11:
			value = 'J';
			break;
		case 12:
			value = 'Q';
			break;
		case 13:
			value = 'K';
			break;
		default:
			break;
		}

		if (value < 11 && value > 1)
		{
			cout << suit << " " << static_cast<int>(value) << ", ";
		}
		else
		{
			cout << suit << " " << value << ",";
		}



	}
	cout << endl;
}

vector<Card> shuffle(vector<Card> Deck)
{
	srand(time(NULL));
	Card tempcard(0, 0);
	for (int i{ 0 }; i < (Deck.size() * 2); i++)
	{

		int first = rand() % Deck.size();
		int second = rand() % Deck.size();

		tempcard = Deck.at(first);
		Deck.at(first) = Deck.at(second);
		Deck.at(second) = tempcard;

	}
	return Deck;
}

int getTotal(vector<Card> hand)
{
	int total{ 0 };

	for (int i{ 0 }; i < hand.size(); i++)
	{
		int tempVal = hand[i].getValue();
		if (tempVal > 10)
		{
			tempVal = 10;
		}

		total += tempVal;

	}
	return total;
}
struct ace hasAce(vector<Card> hand)
{
	if (getTotal(hand) == 11)
	{

	}
	
}
void giveCard(vector<Card>& hand, vector<Card>& deck)
{
	Card temp;
	temp = deck.back();
	hand.push_back(temp);
	deck.pop_back();
}

void dealOut(vector<Card>& player, vector<Card>& dealer, vector<Card>& shuffledDeck)
{

	giveCard(player, shuffledDeck);

	giveCard(dealer, shuffledDeck);
	cout << "Dealer Hand: ";
	printCards(dealer);

	giveCard(player, shuffledDeck);
	cout << "Player Hand: ";
	printCards(player);

	giveCard(dealer, shuffledDeck);

	




}

void wonHand()
{

}

void lostHand()
{

}