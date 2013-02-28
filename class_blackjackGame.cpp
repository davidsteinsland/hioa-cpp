#include <iostream>
#include <cstdlib>
#include "class_blackjackGame.h"
#include "class_deck.h"
#include "class_blackjackState.h"
#include "class_blackjackAction.h"
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
	
	cash bets[gamblers.size()];
	
	/*for (int i = 0; i < gamblers.size(); i++)
	{
		cout << gamblers.at(i).name() << endl;
		bets[i] = gamblers.at(i).placeBet();
	}*/
	
	cards::deck deck;
	deck.shuffle();
	
	// the players' cards
	vector<vector<cards::card> > cardsv;
		
	// making sure every player is dealt one card
	// before we're giving the second (from dealer's left-to-right)
	for (int i = 0, numCards = gamblers.size() * 2; i < numCards; i++)
	{
		cards::card card = deck.deal();
		
		int playerNr = i % gamblers.size();
		
		// insert a vector if cards vector is empty, or not initialized to the player
		if (cardsv.size() <= playerNr )
			cardsv.push_back (vector<cards::card>());
		
		cardsv.at (i % gamblers.size()).push_back (card);
	}
	
	cout << "Checking for blackjack" << endl;
	
	// blackjack test
	for (int i = 0; i < gamblers.size(); i++)
	{
		vector<cards::card> playerCards = cardsv[i];
		int cardsValue = 0;
		
		for (int j = 0; j < 2; j++)
		{
			cards::t_rank rank = playerCards.at(j).getRank();
			int v = (v = atoi ( &rank )) > 0 ? v : 10;
			cardsValue += v;
		}
		
		if ( cardsValue == 21 )
		{
			// BLACKJACK !!!!!!!!!!!!
			cout << "Spilleren " << gamblers.at(i).name() << " fikk blackjack" << endl;
			// gamblers.at(i).giveMoney ( 1.5 * bets[i] );
		}
	}
	
	cout << "Cards dealt; getting actions" << endl;
	
	// we are skipping the dealer
	for (int i = 0; i < gamblers.size() - 1; i++)
	{
		cout << "Spiller " << gamblers.at(i).name() << " sin tur" << endl;
		blackjackState state(cardsv, i, gamblers.size() - 1);
		blackjackAction *action = (blackjackAction*) (gamblers.at(i).takeAction (&state));
		
		switch (action->getAtype())
		{
			case blackjackAction::HIT:
				cout << "Du valgte HIT!" << endl;
			break;
			
			case blackjackAction::STAND:
				cout << "Du valgte STAND!" << endl;
				
				// her må dealer gjøre noe. HIT viss < 17 og STAND >= 17
			break;
			
			default:
				cout << "Ukjent handling" << endl;
			break;
		}
		
		// cout << "Du valgte: " << action->getAtype() << endl;
		
		// action->print();
	}
}