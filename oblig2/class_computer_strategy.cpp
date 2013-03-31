#ifndef CLASS_COMPUTER_STRATEGY
#define CLASS_COMPUTER_STRATEGY

#include "class_computer_strategy.h"
#include "class_game_state.h"
#include <vector>
using namespace std;

/**
 * NOT COMPLETED.
 */
pair<int,int> computer_strategy::move (game_state* s)
{
	int game_size = s->get_matrix_size(),
		matrix_size = s->get_game_matrix_size();

	int* game_matrix = s->get_game_matrix(),
		 *player_selections = s->get_player_selections();
	
	/**
	 * Order of priority:
	 * 1) Get a field to be -MATRIX_SIZE in game_matrix to win (the other player wins when a field is MATRIX_SIZE)
	 * 2) Make as many -(MATRIX_SIZE - 1)s as possible without leaving any (MATRIX_SIZE - 1)s.
	 *    If you leave two -(MATRIX_SIZE - 1)s, you've made a fork (win no matter what).
	 *    If you leave a (MATRIX_SIZE - 1), then the other player will win next turn
	 * 3) Make as many (MATRIX_SIZE - 1)s into (MATRIX_SIZE - 2)s if you cannot do any of that, to prevent the other player from winning
	 */
	
	for (int i = 0; i < 2 * matrix_size + 2; i++)
	{
		int x = i / matrix_size,
			y = i % matrix_size;
		
		/*
		Rememeber:
		game_matrix[0]											Diagonal 1
		game_matrix[1...1 + matrix_size]						Horizontal wins
		game_matrix[1 + matrix_size + 1...2*(1 + matrix_size)]	Vertical wins
		game_matrix[2 * matrix_size + 1]						Diagonal 2
		*/
		
		vector<pair<int,int> > points;
		
		// We're 1 away from winning, or the opponent is.
		if ( game_matrix[i] == 1 - game_size || game_matrix[i] == game_size - 1)
		{
			for (int j = 0; j < matrix_size; j++)
			{
				if (game_size
				// find out which point we must select in order to win
				if (i == 0)
				{
					// diagonal 1
					points.push_back (make_pair (j, j));
				}
				else if (i >= 1 && i <= 1 + matrix_size)
				{
					// horizontals
					points.push_back (make_pair (j, y));
				}
				else if (i >= 2 + matrix_size && i <= 2 + 2 * matrix_size)
				{
					// verticals
					points.push_back (make_pair (x, j));
				}
				else
				{
					// diagonal 2
					points.push_back (make_pair (matrix_size - j - 1, j - 1));
				}
			}
		}
		
		for (vector<pair<int,int> >::iterator it = points.begin(); it != points.end(); it++)
		{
			if ( player_selections[matrix_size * it->first + it->second] == -1 )
				return *it;
		}
	}
}

#endif