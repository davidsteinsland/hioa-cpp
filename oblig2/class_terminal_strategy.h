#ifndef CLASS_TERMINAL_STRATEGY_H
#define CLASS_TERMINAL_STRATEGY_H

#include "class_game_state.h"
#include "class_strategy.h"

class terminal_strategy : public strategy
{
	public:
		virtual std::pair<int,int> move (game_state* s);
};

#endif