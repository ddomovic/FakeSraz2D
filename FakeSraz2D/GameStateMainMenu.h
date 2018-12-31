#pragma once

#include <string>

class GameStateMainMenu : public GameState {
private:
	std::vector<class GameObjectButton*> _buttons;
	virtual bool check_if_clicked(class GameObjectButton *button, int x, int y);
public:
	GameStateMainMenu(class Game *game, const std::string &state_name);
	void begin_state();
	void reset_state();
	void keyboard_functions(unsigned char key, int x, int y);
	void mouse_functions(int button, int state, int x, int y);
};