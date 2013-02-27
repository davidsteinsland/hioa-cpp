#include "class_blackjackState.h"
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

}

vector<cards::card> blackjackState::dealersCards ()
{
	return cardsv.at(dealer);
}

vector<cards::card> blackjackState::myCards()
{
	return cardsv.at(ourHero);
}

vector<cards::card> blackjackState::cardsI(int i )
{
	return cardsv.at(ourHero).at(i);
}

int blackjackState::getOurHero ()
{
	return ourHero;
}

int blackjackState::getDealer ()
{
	return dealer;
}