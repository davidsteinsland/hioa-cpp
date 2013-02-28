#include "class_blackjackStrategy.h"
#include "class_blackjackAction.h"
#include "class_blackjackState.h"
#include <iostream>
using namespace casino;

blackjackStrategy::blackjackStrategy (controlType type)
{
	if ( type == TERMINAL )
	{
		// std::cout << "controlType er visst terminal. Hva skal jeg gjøre her da?" << std::endl;
	}
}

action* blackjackStrategy::takeAction (gameState *g)
{
	// std::cout << "Jeg returnerer nå en action" << std::endl;
	blackjackState *state = (blackjackState*)g;
	if ( state->getOurHero() == state->getDealer() )
	{
		
	}
	
	return new blackjackAction (TERMINAL);
}