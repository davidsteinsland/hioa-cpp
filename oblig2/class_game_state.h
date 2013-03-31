#ifndef CLASS_GAME_STATE_H
#define CLASS_GAME_STATE_H

#include <vector>

class player;

class game_state
{
	private:
		int matrix_size;
		int* game_matrix;
		int* player_selections;
		std::vector<player*> players;
		player* current_player;
	public:
		game_state(int,int*,int*,std::vector<player*>,int);
		~game_state();
		
		void print();
		
		int game_finished();
		bool valid_move(std::pair<int,int>);
		
		int* get_player_selections()
		{
			return player_selections;
		}
		
		int* get_game_matrix()
		{
			return game_matrix;
		}
		
		int get_game_matrix_size()
		{
			return 2*matrix_size+2;
		}
		
		int get_matrix_size()
		{
			return matrix_size;
		}
};

#endif