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

}

vector<cards::card> blackjackState::myCards()
{

}

vector<cards::card> blackjackState::cardsI(int i )
{

}

int blackjackState::getOurHero ()
{
	return ourHero;
}

int blackjackState::getDealer ()
{
	return dealer;
}