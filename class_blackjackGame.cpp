#include "class_blackjackGame.h"
using namespace casino;


blackjackGame::blackjackGame (int players) : game::game (blackjack, players)
{
	for (int i = 0; i < players; i++)
	{
		gamblers.push_back (gambler (TERMINAL));
	}
}

void blackjackGame::playRound ()
{
	
}

void blackjackGame::start ()
{
	// deck.shuffle();
}