#include "class_game.h"
using namespace casino;

game::game (gameType t, int players)
{
	this->t = t;
	
	// dealer has to be the last element in gamblers to be
	// able to deal left-to-right (dealer gets cards last)
	for (int i = 0; i < players; i++)
	{
		gamblers.push_back (gambler (TERMINAL));
	}
	
	gamblers.push_back (gambler ("Mr", "Dealer"));
}

gameType game::getType()
{
	return t;
}