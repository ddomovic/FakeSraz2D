#include "stdafx.h"
#include <vector>
#include <GL/glut.h>
#include "TextRenderer.h"
#include "Game.h"
#include "GameObject.h"
#include "GameObjectButton.h"
#include "GameState.h"
#include "GameStatePlaying.h"
#include "GameStateMainMenu.h"

GameStateMainMenu::GameStateMainMenu(Game *game, const std::string &state_name) : GameState(game, state_name) {
	this->_buttons.push_back(new GameObjectButton(game, 100, 50, 300, 200, true, "NEW GAME"));
	this->_buttons.push_back(new GameObjectButton(game, 100, 50, 300, 100, true, "QUIT"));
	this->add_object(this->_buttons[0]);
	this->add_object(this->_buttons[1]);
}

void GameStateMainMenu::begin_state() {
}

void GameStateMainMenu::reset_state() {
}

void GameStateMainMenu::keyboard_functions(unsigned char key, int x, int y) {
}

bool GameStateMainMenu::check_if_clicked(GameObjectButton *button, int x, int y) {
	float tile_x = button->get_X();
	float tile_y = button->get_Y();
	float tile_width = button->get_width();
	float tile_height = button->get_height();

	if (x >= tile_x && x <= tile_x + tile_width) {
		if (y >= tile_y && y <= tile_y + tile_height) {
			return true;
		}
	}
	return false;
}

void GameStateMainMenu::mouse_functions(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		for (std::vector<GameObjectButton*>::iterator it = this->_buttons.begin(); it != this->_buttons.end(); ++it) {
			if (check_if_clicked(*it, x, y)) {
				if ((*it)->get_text() == "NEW GAME") {
					GameStatePlaying *playing_state = static_cast<GameStatePlaying*>(this->get_game()->get_game_state_by_name("playing"));
					playing_state->begin_state();
					this->get_game()->set_state(playing_state);
				}
				else {
					exit(0);
				}
			}
		}
	}
}
