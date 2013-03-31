#ifndef CLASS_PLAYER_H
#define CLASS_PLAYER_H

#include <string>
#include "class_strategy.h"

typedef enum{TERMINAL,COMPUTER} type;

class game_state;
// class strategy;

class player
{
	static int NEXT_ID;
	
	private:
		std::string player_name;
		char player_symbol;
		int player_id;
		strategy* game_strategy;
	public:
		player (type t);
		~player();
		
		std::string name();
		char symbol();
		std::pair<int,int> move (game_state*);
};

#endif