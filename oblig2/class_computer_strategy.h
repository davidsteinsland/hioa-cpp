#ifndef CLASS_COMPUTER_STRATEGY_H
#define CLASS_COMPUTER_STRATEGY_H

#include "class_strategy.h"
class game_state;

class computer_strategy : public strategy
{
	public:
		virtual std::pair<int,int> move (game_state* s);
};

#endif