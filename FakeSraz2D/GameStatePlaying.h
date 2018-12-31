#pragma once

#include <vector>

class GameStatePlaying : public GameState {
private:
	class PlayingBoard *_playing_board;
	std::vector<class Team*> _teams;
	uint8_t _current_team_index;
	std::vector<uint8_t> _current_pawn_by_team;
	std::vector<class Tile*> _tiles_to_check;
	bool check_if_tile_available(int x_to_check, int y_to_check, uint8_t current_team_ID);
public:
	GameStatePlaying(class Game *game, const std::string &name, class PlayingBoard *board);
	void begin_state();
	void reset_state();
	void turn_start();
	void keyboard_functions(unsigned char key, int x, int y);
	void mouse_functions(int button, int state, int x, int y);
	void kill_pawn(class GameObjectPawn *pawn_to_kill);
	void kill_team(class Team *team_to_kill);
};