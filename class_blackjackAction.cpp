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
			cout << "Hva vil du gjøre? HIT, STAND?" << endl;
			cin >> opt;
		} while ( opt.compare("HIT") != 0 && opt.compare("STAND") != 0); // case sensitive. Fix!
		
		if ( opt.compare ("HIT") == 0 )
			actionType = HIT;
		else
			actionType = STAND;
	}
}

atype blackjackAction::getAtype ()
{
	return actionType;
}

void blackjackAction::print ()
{

}