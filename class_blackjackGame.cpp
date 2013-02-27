#include <iostream>
#include "class_blackjackGame.h"
#include "class_deck.h"
#include "class_blackjackState.h"
using namespace casino;
using namespace std;

blackjackGame::blackjackGame (int players) : game (blackjack, players)
{
	
}

void blackjackGame::playRound ()
{
	
}

void blackjackGame::start ()
{
	cout << "Starting round with " << gamblers.size() << " players" << endl;
	
	cards::deck deck;
	deck.shuffle();
	
	// the players' cards
	vector<vector<cards::card> > cardsv;
	
	cout << "Dealing cards ..." << endl;
	
	// making sure every player is dealt one card
	// before we're giving the second (from dealer's left-to-right)
	for (int i = 0, numCards = gamblers.size() * 2; i < numCards; i++)
	{
		cards::card card = deck.deal();
		cout << "cardsv.size() = " << cardsv.size() << endl;
		cout << "Dealing to player " << (i % gamblers.size()) << endl;
		
		int playerNr = i % gamblers.size();
		
		// insert a vector if cards vector is empty, or not initialized to the player
		if (cardsv.size() <= playerNr )
			cardsv.push_back (vector<cards::card>());
		
		vector<cards::card> c = cardsv.at (i % gamblers.size());
		c.push_back (card);
	}
	
	cout << "Cards dealt; setting game state" << endl;
	
	// blackjackState(std::vector<std::vector<cards::card> >, int, int);
	blackjackState state(cardsv, 0, gamblers.size() - 1);
	
	cout << "State set; calling actions" << endl;
	
	// place bets
	for (int i = 0; i < gamblers.size(); i++)
		action *action = gamblers.at(i).takeAction (&state);
}