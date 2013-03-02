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
	blackjackState *state = (blackjackState*)g;
	std::vector<cards::card> cardsv = state->myCards();
	std::vector<cards::card> dealer = state->dealersCards();
	
	std::cout << "Du har: ";
	for (std::vector<cards::card>::iterator it = cardsv.begin(); it < cardsv.end(); it++)
		std::cout << it->name() << " ";
	std::cout << std::endl;
	
	// we're only allowed to see one of the dealer's cards.
	std::cout << "Dealer har: " << dealer[0].name() << std::endl;
	
	return new blackjackAction (TERMINAL);
}