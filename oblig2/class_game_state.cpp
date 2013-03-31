#ifndef CLASS_GAME_STATE
#define CLASS_GAME_STATE

#include <iostream>
#include <vector>
#include <stdio.h> /* printf */
#include "class_game_state.h"
#include "class_player.h"

using namespace std;

game_state::game_state (int size, int* g, int* ps, std::vector<player*> pls, int current_p) : matrix_size(size), game_matrix(g), player_selections(ps), players(pls)
{
	current_player = pls[current_p];
}

game_state::~game_state()
{
	delete game_matrix;
	delete player_selections;
}

/**
 * -1 => draft
 * 0  => still in progress
 * 1  => finished, with a winner
 */
int game_state::game_finished()
{
	int num_ones = 0;
	
	for (int i = 0; i < 2 * matrix_size + 2; i++)
		if ( *(game_matrix + i) == matrix_size || *(game_matrix + i) == (matrix_size * -1) )
			return 1;
	
	for (int i = 0; i < 2 * matrix_size + 2; i++)
		if ( player_selections[i] == -1 )
			return 0;
	
	return -1;
}

bool game_state::valid_move (std::pair<int,int> coords)
{
	int x = coords.first,
		y = coords.second;
	
	if ( !(x >= 0 && x < matrix_size))
	{
		cout << "x er ikke gyldig" << endl;
		return false;
	}
	
	if ( !(y >= 0 && y < matrix_size))
	{
		cout << "y er ikke gyldig" << endl;
		return false;
	}
	
	if (player_selections[matrix_size * x + y] != -1)
	{
		cout << "Feltet er tatt!" << endl;
		return false;
	}
	
	return true;
}

void game_state::print ()
{
	int s = game_finished();
	
	if (s == 1)
	{
		cout << "Game over, and the winner is: " << current_player->name() << "!" << endl;
	}
	else if (s == -1)
	{
		cout << "Game draft!" << endl;
	}
	else
	{
		cout << current_player->name() << "'s turn" << endl;
	}
	
	// skriver ut kolonner
	cout << "     ";
	for (int i = 0; i < matrix_size; i++)
		printf ("%-5d", (i + 1));
	cout << endl;
	
	// skriver ut rader
	char row = 'A';
	for (int i = 0; i < matrix_size; i++)
	{
		printf ("%-5c", row++);
		
		for (int j = 0; j < matrix_size; j++)
		{
			int player = player_selections[matrix_size * i + j];
			if ( player != -1)
				printf ("%-5c", players[player]->symbol());
			else
				cout << "-    ";
		}
		
		cout << endl;
	}
}

#endif