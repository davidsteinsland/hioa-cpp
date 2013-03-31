#include "class_tictactoe.h"

int main()
{
	tictactoe* game = new tictactoe();
	game->start();
	
	delete game;
}