#pragma once

class GameStateGameOver : public GameState {
private:
	class TextRenderer *_text_renderer;
	class Team *_winning_team;
	class TextBox *_team_box;
public:
	GameStateGameOver(class Game *game, const std::string &name);
	void set_winning_team(class Team *team);
	void begin_state();
	void reset_state();
	void keyboard_functions(unsigned char key, int x, int y);
	void mouse_functions(int button, int state, int x, int y);
};