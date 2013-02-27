#include "class_deck.h"
#include "class_card.h"
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <iostream> // debug purposes

using namespace cards;
using namespace std;

deck::deck () // : deck (1) // C++11, "delegating constructors"
{
	for (int j = 0; j < 52; j++)
	{
		// fill with 52 cards for each deck
		cards.push_back ( card (t_suit(j / 13), ranks[j % 13]) );
	}
	
	shuffle();
}

deck::deck (int deckCount)
{
	for (int i = 0; i < deckCount; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			// fill with 52 cards for each deck
			cards.push_back ( card (t_suit(j / 13), ranks[j % 13]) );
		}
	}
	
	shuffle();
}

void deck::shuffle ()
{
	srand((unsigned)time(0));
	
	for (int k = size() - 1; k > 0; k--)
	{
		int r = rand() % (k + 1); // random number from [0, k]
		// int r = ((k+1) * rand()) / RAND_MAX; // [0, k]
		// swap
		card tmp = cards[k];
		cards[k] = cards[r];
		cards[r] = tmp;
	}
}

card deck::deal ()
{
	card card = cards.back();
	cards.pop_back();
	
	return card;
}

int deck::size ()
{
	return cards.size();
}