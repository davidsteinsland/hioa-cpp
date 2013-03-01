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
	for (int i = 0; i < gamblers.size(); i++)
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
	
	// blackjack test
	for (int i = 0; i < gamblers.size(); i++)
	{
		if ( checkBlackjack ( cardsv[i] ) == 0 )
		{
			// BLACKJACK !!!!!!!!!!!!
			cout << gamblers.at(i).name() << " fikk blackjack!" << endl;
			// gamblers.at(i).giveMoney ( 1.5 * bets[i] );
			
			return;
		}
	}
	
	// we are storing the results in an array for quick access
	int results[gamblers.size()];
	
	// we are skipping the dealer
	for (int i = 0; i < gamblers.size() - 1; i++)
	{
		cout << "Spiller " << gamblers.at(i).name() << " sin tur" << endl;
		
		blackjackState state(cardsv, i, gamblers.size() - 1);
		blackjackAction *action = (blackjackAction*) (gamblers.at(i).takeAction (&state));
		
		action->print();
		
		switch (action->getAtype())
		{
			case blackjackAction::HIT:
				cardsv[i].push_back (deck.deal());
			break;
			
			case blackjackAction::STAND:
				// her må dealer gjøre noe. HIT viss < 17 og STAND >= 17
				// denne operasjonen må flyttes ut av loop når spillere > 1
				if ( getCardsValue ( cardsv[gamblers.size() - 1] ) < 17 )
				{
					// HIT
					cardsv[gamblers.size() - 1].push_back (deck.deal());
				}
			break;
		}
		
		int res = getCardsValue (cardsv[i]);
		results[i] = res;
	}
	
	// dealer's score
	int res = getCardsValue (cardsv[gamblers.size() - 1]);
	results[gamblers.size() - 1] = res;
	
	vector<pair<gambler, int> > winners;
	int m = -1; // the current max score
	
	// loop through all results
	for (int i = 0; i < gamblers.size(); i++)
	{
		cout << gamblers[i].name() << " fikk " << results[i] << endl;
		
		if ( results[i] > 21 )
			continue;
			
		if ( results[i] >= m )
		{
			// new score; erase previous list
			if (results[i] > m)
			{
				winners.erase (winners.begin(), winners.end());
				m = results[i];
			}
			
			winners.push_back (make_pair (gamblers[i], results[i]));
		}
	}
	
	cout << endl << "Vinnere:" << endl;
	for (int i = 0; i < winners.size(); i++)
	{
		cout << winners[i].first.name() << " with " << winners[i].second << endl;
	}
}

void blackjackGame::start ()
{
	playRound();
}

int blackjackGame::getCardsValue (vector<cards::card> cardsv)
{
	int cardsValue = 0;
	
	for (int j = 0; j < cardsv.size(); j++)
	{
		cards::t_rank rank = cardsv[j].getRank();
		int v = (v = atoi ( &rank )) > 0 ? v : 10;
		cardsValue += v;
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