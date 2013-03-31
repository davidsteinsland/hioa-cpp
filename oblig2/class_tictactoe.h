#ifndef CLASS_TICTACTOE_H
#define CLASS_TICTACTOE_H

#include <vector>
#include "class_player.h"

class tictactoe
{
	private:
		int matrix_size;
		int** pos_matrix;
		int* game_matrix;
		int* player_selections;
		
		std::vector<player*> players;
		
		/**
		 * Creates a matrix for each win position. Zero means the position will not contribute
		 * to a win, and a 1 means it will.
		 *
		 * For each position, a matrix of NxN is given as follows:
		 * [D1, H1, H2, ..., HN, V1, V2, ..., VN, D2].
		 * D1 and D2 are the two diagonals, H1-HN is the horizontal wins and V1-VN is the vertical wins.
		 * Given a 3x3 matrix, the resulting win matrix will be a 9x8 matrix.
		 * The point (0, 0) will have the following matrix: [1, 1, 0, 0, 1, 0, 0, 0]:
		 * - It contributes to a diagonal win (D1), a horizontal win (H1) and a vertical win (V1).
		 * - It does not contribute to the rest.
		 *
		 * For each given point (x,y), the following rules apply:
		 * - it will contribute to the horizontal win Hy and the vertical win Vx.
		 * - if (x,y) = (i, i) where i = [0, n - 1] it will contribute to the D1 win.
		 * - if (x,y) = (n - i, i - 1), where i = [1, n]  it will contribute to the D2 win.
		 */
		int** gen_pos_matrices(int);
		/**
		 * Creates an int array with values initialized to a specified value.
		 */
		int* gen_array (int,int);
	
	
	public:
		tictactoe ();
		~tictactoe();
		void start ();
};

#endif