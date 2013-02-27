#include "class_blackjackAction.h"
#include <iostream>
using namespace casino;
using namespace std;

blackjackAction::blackjackAction (controlType t)
{
	if ( t == TERMINAL )
	{
		string opt;
		
		do
		{
			cout << "Hva vil du gjøre? <1> STAND, <2> for HIT?" << endl;
			cin >> opt;
		} while ( opt.compare("1") != 0 && opt.compare("2") != 0);
		
		if ( opt.compare ("1") == 0 )
			actionType = STAND;
		else
			actionType = HIT;
	}
}

blackjackAction::atype blackjackAction::getAtype ()
{
	return actionType;
}

void blackjackAction::print ()
{

}