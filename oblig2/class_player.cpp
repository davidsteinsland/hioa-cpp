#ifndef CLASS_PLAYER
#define CLASS_PLAYER

#include <iostream>
#include <string>
#include "class_player.h"
#include "class_terminal_strategy.h"
#include "class_computer_strategy.h"

int player::NEXT_ID = 0;

player::player (type t) : game_strategy (NULL)
{
	player_id = NEXT_ID++;
	
	if (t == TERMINAL)
	{
		std::cout << "Spillernavn (maks 20 tegn):" << std::endl;
		while (player_name == "")
			std::getline(std::cin, player_name);
			
		do
		{
			std::cout << "Velg symbol for brikke (X er i bruk):" << std::endl;
			std::cin >> player_symbol;
		} while (player_symbol == 'X');
		
		game_strategy = new terminal_strategy();
	}
	else if (t == COMPUTER)
	{
		player_name = "Mr. Computer";
		player_symbol = 'X';
		// game_strategy = new computer_strategy();
		game_strategy = new terminal_strategy();
	}
}
		
player::~player()
{
	delete game_strategy;
}

std::string player::name()
{
	return player_name;
}

char player::symbol()
{
	return player_symbol;
}

std::pair<int,int> player::move (game_state* s)
{
	return game_strategy->move (s);
}

#endif