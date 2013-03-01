#include "class_blackjackAction.h"
#include <iostream>
using namespace casino;
using namespace std;

blackjackAction::blackjackAction (controlType type)
{
	if ( type == TERMINAL )
	{
		string opt;
		
		// cout << "Vi er i TERMINAL, i blackjackAction" << endl;
		
		do
		{
			cout << "Hva vil du gjøre? <1> STAND, <2> for HIT?" << endl;
			cin >> opt;
			// cout << "Svar mottat!" << endl;
		} while ( opt.compare("1") != 0 && opt.compare("2") != 0);
		
		// cout << "Sammenligner svaret ditt..." << endl;
		
		if ( opt.compare ("1") == 0 )
			actionType = STAND;
		else
			actionType = HIT;
		
		// cout << "Svar registrert!" << endl;
	}
}

blackjackAction::atype blackjackAction::getAtype ()
{
	return actionType;
}

void blackjackAction::print ()
{
	switch (getAtype())
	{
		case HIT:
			cout << "Du valgte HIT!" << endl << endl;
		break;
		
		case STAND:
			cout << "Du valgte STAND!" << endl << endl;
		break;
	}
}