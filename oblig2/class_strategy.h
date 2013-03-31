#ifndef CLASS_STRATEGY_H
#define CLASS_STRATEGY_H

#include <utility>
class game_state;

class strategy	
{
	public:
		virtual std::pair<int,int> move(game_state*)=0;
};

#endif