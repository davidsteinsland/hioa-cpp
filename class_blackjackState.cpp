#include "class_blackjackState.h"
#include <iostream>
#include <vector>
using namespace casino;
using namespace std;

blackjackState::blackjackState (vector<vector<cards::card> > cardv, int iHero, int iDealer)
{
	ourHero = iHero;
	dealer = iDealer;
	
	cardsDealt = cardv;
}

void blackjackState::print ()
{
	vector<cards::card> cardsv = myCards();
	vector<cards::card> dealer = dealersCards();
	
	cout << "Du har: ";
	for (vector<cards::card>::iterator it = cardsv.begin(); it < cardsv.end(); it++)
		cout << it->name() << " ";
	cout << endl;
	
	// we're only allowed to see one of the dealer's cards.
	cout << "Dealer har: " << dealer[0].name() << endl;
}

vector<cards::card> blackjackState::dealersCards ()
{
	return cardsDealt.at(dealer);
}

vector<cards::card> blackjackState::myCards()
{
	return cardsDealt.at(ourHero);
}

vector<cards::card> blackjackState::cardsI(int i )
{
	return cardsDealt.at(i);
}

int blackjackState::getOurHero ()
{
	return ourHero;
}

int blackjackState::getDealer ()
{
	return dealer;
}