#include <iostream>
#include <cstdlib>
#include <utility>
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
	cout << "Starting round with " << gamblers.size() << " players" << endl << endl;
	
	/*cash bets[gamblers.size()];
	for (vector<gambler>::iterator it = gamblers.begin() ; it != gamblers.end(); ++it)
		bets[it - gamblers.begin()] = it->placeBet();
	*/
	
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
	
	// blackjack test
	for (vector<gambler>::iterator it = gamblers.begin() ; it != gamblers.end(); ++it)
		if ( checkBlackjack ( cardsv[it - gamblers.begin()] ) == 0 )
		{
			cout << it->name() << " fikk blackjack!" << endl;
			return;
		}
	
	// we are storing the results in an array for quick access
	vector<pair<gambler, int> > results;
	
	// we are skipping the dealer (last entry in vector)
	for (vector<gambler>::iterator it = gamblers.begin(); it != gamblers.end() - 1; it++)
	{
		int idx = it - gamblers.begin();
		cout << "Spiller " << it->name() << " sin tur" << endl;
		
		blackjackAction* action;
		do
		{
			blackjackState state(cardsv, idx, gamblers.size() - 1);
			state.print();
			
			action = (blackjackAction*) (it->takeAction (&state));
			action->print();
			
			switch (action->getAtype())
			{
				case blackjackAction::HIT:
					cardsv[idx].push_back (deck.deal());
				break;
			}
		} while ( (action->getAtype() != blackjackAction::STAND) && (checkBlackjack (cardsv[idx]) < 1) );
		
		int res = getCardsValue (cardsv[idx]);
		results.push_back ( make_pair (*it, res) );
	}
	
	/**
	 * her må dealer gjøre noe. HIT viss < 17 og STAND >= 17
	 */
	if ( getCardsValue ( cardsv[gamblers.size() - 1] ) < 17 )
	{
		// HIT
		cardsv[gamblers.size() - 1].push_back (deck.deal());
	}
	
	// dealer's score
	int res = getCardsValue (cardsv[gamblers.size() - 1]);
	results.push_back ( make_pair (gamblers.back(), res));
	
	/**
	 * Loop through results vector and pops values that are lower than max
	 * The result is a vector<pair<gambler, int>> with the winner(s)
	 */
	int m = -1;
	for (vector<pair<gambler, int> >::iterator it = results.begin(); it < results.end(); it++)
	{
		int v = it->second;
		if (v > 21 )
		{
			// we have to decrease the iterator by one, because
			// if the vector contains two players with both having > 21;
			// then the first one will be erased, and the iterator == results.end(), thus
			// the last player will not be deleted.
			results.erase (it--);
			continue;
		}
		
		if ( v > m )
		{
			m = v;
			// erase all elements up to this one
			it = results.erase (results.begin(), it);
		}
		
		if (v >= m)
			// pop values lower than m
			for (vector<pair<gambler, int> >::iterator k = it; k < results.end(); k++)
				if (k->second < m)
					results.erase (k);
	}
	
	if ( results.size() == 0 || results.size() > 1)
		cout << "Ingen vinnere. PUSH!" << endl;
	else
	{
		cout << endl << "Vinner:" << endl;
		for (vector<pair<gambler, int> >::iterator it = results.begin(); it != results.end(); it++)
			cout << it->first.name() << " med " << it->second << endl;
	}
}

void blackjackGame::start ()
{
	string opt;
	do
	{
		playRound();
		cout << "One more round? Y/N" << endl;
		cin >> opt;
	} while ( opt.compare ("Y") == 0 || opt.compare("y") == 0);
}

/**
 * Custom methods added by David.
 * Somce of the methods would be more applicable some where else; but this
 * is the only file allowed to edit atm.
 */

int blackjackGame::getCardValue (cards::card c)
{
	cards::t_rank rank = c.getRank();
		
	int v = (v = atoi ( &rank )) > 0 ? v : 10;
	if (rank == 'A')
		v = 11;
	return v;
}

int blackjackGame::getCardsValue (vector<cards::card> cardsv)
{
	int cardsValue = 0;
	
	for (vector<cards::card>::iterator it = cardsv.begin(); it < cardsv.end(); it++)
	{
		// Ace is automatically 1 if the result is larger than 21.
		if (it->getRank() == 'A' && cardsValue + 11 > 21 )
			cardsValue += 1;
		else
			cardsValue += getCardValue(*it);
	}
	
	return cardsValue;
}

int blackjackGame::checkBlackjack (vector<cards::card> cardsv)
{
	int cardsValue = getCardsValue (cardsv);
	
	if (cardsValue > 21 )
		return 1;
	if ( cardsValue < 21 )
		return -1;
	return 0;
}