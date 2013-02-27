#include "class_gambler.h"
#include "class_blackjackStrategy.h"
#include <iostream>
#include <cstdlib>

using namespace casino;
using namespace std;

int gambler::gamblerNr = 0;

gambler::gambler (string fname, string lname)
{
	gamblerId = ++gamblerNr;
	
	this->firstName = fname;
	this->lastName = lname;
}

gambler::gambler (controlType t )
{
	gamblerId = ++gamblerNr;
	
	if (t == TERMINAL)
	{
		cout << "Hva er fornavnet ditt?" << endl;
		cin >> firstName;
		cout << "Hva er etternavnet ditt?" << endl;
		cin >> lastName;
	}
	
	// how many strategies should we add?
	strategies.push_back (new blackjackStrategy(t));
}

void gambler::giveMoney (cash amount)
{
	this->wallet += amount;
}

cash gambler::placeBet()
{
	// using cstrings because of atof()
	char *bet;
	cash fbet = 0;
	
	do
	{
		// if the user typed in a valid bet, only more
		// than he can afford
		if (fbet > 0 && fbet > wallet)
			cout << "For mye!" << endl;
			
		cout << "Hvor mye vil du satse?" << endl;
		cin >> bet;
		fbet = atof(bet);
		
		// the user tried to push a negative number, but we just 
		// convert it to a positive
		if (fbet < 0)
			fbet *= -1;
		else if (fbet == 0) // the user have typed a non-numeric character, or zero
			cout << "Ugyldig beløp" << endl;;
	}
	while ( fbet == 0 || fbet > wallet );
	
	return fbet;
}

string gambler::name()
{
	return this->firstName + " " + this->lastName;
}

bool gambler::ready ()
{
	return readyToPlay;
}

action* gambler::takeAction (gameState *g)
{
	// for (int i = 0; i < strategies.size(); i++)
	return strategies.at(0)->takeAction (g);
}

void gambler::joinGame (game &g)
{

}