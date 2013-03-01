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
	std::vector<cards::card> cardsv = state->myCards();
	std::vector<cards::card> dealer = state->dealersCards();
	
	// only one card visible! We choose the first one
	std::cout << "Du har: " << cardsv[0].name() << std::endl;
	std::cout << "Dealer har: " << dealer[0].name() << std::endl;
	
	return new blackjackAction (TERMINAL);
}