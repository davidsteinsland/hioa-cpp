#ifndef CLASS_TICTACTOE
#define CLASS_TICTACTOE

#include <iostream>
#include <limits>
#include <string>
#include <stdlib.h> /* rand() */
#include "class_tictactoe.h"
#include "class_player.h"
#include "class_game_state.h"

#define LOWER_LIMIT 3
#define UPPER_LIMIT 26

using namespace std;

/**
 * Tic Tac Toe:
 * Given a NxN matrix:
 * - There are 2N + 2 possible ways of winning
 * - There are N^2 different positions
 */

int* add_matrix(int, int*, int*);
int* subtract_matrix(int, int*, int*);

tictactoe::tictactoe()
{
	cout << "Welcome to Tic-Tac-Toe!" << endl;
	
	do
	{
		if ( ! cin )
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		cout << "Select board size (a number between " << LOWER_LIMIT << " and " << UPPER_LIMIT << "):" << endl;
	} while ( !(cin >> matrix_size) || !(matrix_size >= LOWER_LIMIT && matrix_size <= UPPER_LIMIT) );
	
	cout << "Selected board size: " << matrix_size << "x" << matrix_size << endl;
	
	pos_matrix = gen_pos_matrices(matrix_size);
	game_matrix = gen_array (2 * matrix_size + 2, 0);
	player_selections = gen_array (matrix_size * matrix_size, -1);
	
	players.push_back (new player(TERMINAL));
	players.push_back (new player (COMPUTER));
}

tictactoe::~tictactoe()
{
	delete player_selections;
	for (int i = 0; i < 2 * matrix_size + 2; i++)
		delete [] pos_matrix[i];
	for (vector<player*>::iterator it = players.begin(); it != players.end(); it++)
		delete *it;
	delete [] pos_matrix;
	delete [] game_matrix;
}

int** tictactoe::gen_pos_matrices(int k)
{
	// create 2D array
	int** matrix = new int*[k * k];
	for (int i = 0; i < k * k; i++)
	{
		matrix[i] = gen_array (2 * k + 2, 0);
		
		int x = i / k,
			y = i % k;
		
		// horizontal contribution
		matrix[i][1 + x] = 1;
		// vertical contribution
		matrix[i][1 + k + y] = 1;
		// diagonal 1 contribution
		if (x == y)
			matrix[i][0] = 1;
		// diagonal 2 contribution
		for (int j = 0; j < k; j++)
			if (x == k - j - 1 && y == j)
			{
				matrix[i][2*k+1] = 1;
				break;
			}
	}
	
	return matrix;
}

int* tictactoe::gen_array(int k, int v)
{
	int* a = new int[k];
	for (int i = 0; i < k; i++)
		a[i] = v;
	return a;
}

void tictactoe::start()
{
	int random = rand(),
		pid = random++ % 2;
	player* p = NULL;
	game_state* state = new game_state (matrix_size, game_matrix, player_selections, players, pid);
	
	while (state->game_finished() == 0)
	{
		p = players[pid];
		
		state->print();
		
		pair<int,int> coords;
		do
		{
			coords = p->move(state);
		} while ( ! state->valid_move (coords));
		
		int x = coords.first,
			y = coords.second,
			pos_idx = matrix_size * x + y;
			
		player_selections[pos_idx] = pid;
		int* pos = pos_matrix[pos_idx];
		
		if (pid == 0)
			game_matrix = add_matrix (matrix_size, game_matrix, pos);
		else
			game_matrix = subtract_matrix (matrix_size, game_matrix, pos);
		
		pid = random++ % 2;
		state = new game_state (matrix_size, game_matrix, player_selections, players, pid);
		
		cout << "=============================" << endl;
	}
	
	state->print();
}

/** helper functions */
int* add_matrix (int k, int* a, int* b)
{
	int* c = new int[2*k+2];
	for (int i = 0; i < 2*k+2; i++)
		c[i] = a[i] + b[i];
	return c;
}

int* subtract_matrix (int k, int* a, int* b)
{
	int* c = new int[2*k+2];
	for (int i = 0; i < 2*k+2; i++)
		c[i] = *(a+i) - *(b+i);
	return c;
}

#endif