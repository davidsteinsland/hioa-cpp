#ifndef CLASS_TERMINAL_STRATEGY
#define CLASS_TERMINAL_STRATEGY

#include <iostream>
#include <limits>
#include <utility>
#include "class_game_state.h"
#include "class_terminal_strategy.h"

using namespace std;

std::pair<int,int> terminal_strategy::move (game_state* s)
{
	char x;
	int y;
	do
	{
		if ( ! cin )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		cout << "Skriv inn et koordinat, type: 'A 1', 'B 3', etc." << endl;
	} while ( !(cin >> x >> y) );
	
	return make_pair (x - 'A', y - 1);
}
#endif