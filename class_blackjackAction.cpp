#include "class_blackjackAction.h"
#include <iostream>
#include <limits>
using namespace casino;
using namespace std;

blackjackAction::blackjackAction (controlType type)
{
	if ( type == TERMINAL )
	{
		unsigned int opt;
		
		do
		{
			if ( ! cin )
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			cout << "Hva vil du gjøre? (<0> for HIT, <1> STAND)" << endl;
		} while ( !(cin >> opt) || !(opt >= HIT && opt <= DOUBLE) );
		
		switch (opt)
		{
			case 0:
				actionType = HIT;
			break;
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
	/*switch (actionType)
	{
		case HIT:
			cout << "Du valgte HIT!" << endl << endl;
		break;
		
		case STAND:
			cout << "Du valgte STAND!" << endl << endl;
		break;
	}*/
}