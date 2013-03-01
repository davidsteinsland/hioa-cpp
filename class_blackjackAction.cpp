#include "class_blackjackAction.h"
#include <iostream>
using namespace casino;
using namespace std;

blackjackAction::blackjackAction (controlType type)
{
	if ( type == TERMINAL )
	{
		int opt;
		
		do
		{
			cout << "Hva vil du gjøre? <1> STAND, <2> for HIT?" << endl;
			cin >> opt;
		} while ( !(opt >= HIT && opt <= DOUBLE) );
		
		switch (opt)
		{
			case 0:
				actionType = HIT;
			case 1:
				actionType = STAND;
			break;
		}
	}
}

blackjackAction::atype blackjackAction::getAtype ()
{
	return actionType;
}

void blackjackAction::print ()
{
	switch (actionType)
	{
		case HIT:
			cout << "Du valgte HIT!" << endl << endl;
		break;
		
		case STAND:
			cout << "Du valgte STAND!" << endl << endl;
		break;
	}
}