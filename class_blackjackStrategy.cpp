#include "class_blackjackStrategy.h"
#include "class_blackjackAction.h"
using namespace casino;

blackjackStrategy::blackjackStrategy (controlType type)
{
	if ( type == TERMINAL )
	{
		
	}
}

action* blackjackStrategy::takeAction (gameState *g)
{
	return new blackjackAction (TERMINAL);
}