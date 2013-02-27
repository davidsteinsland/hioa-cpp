#include <iostream>
#include <string>
#include "class_card.h"
#include "class_deck.h"
using namespace cards;
using namespace std;

int main ()
{
	int players = 5;
	
	deck deck;
	deck.shuffle();
	for (int i = 0, cards = players * 2; i < cards; i++)
	{
		card card = deck.deal();
		cout << "Player #" << (i % players) << " --> " << card.name() << endl;
	}
}