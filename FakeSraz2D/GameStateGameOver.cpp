#include "stdafx.h"
#include <string>
#include <GL/glut.h>
#include "TextRenderer.h"
#include "Team.h"
#include "Game.h"
#include "GameObject.h"
#include "TextBox.h"
#include "GameState.h"
#include "GameStateGameOver.h"

GameStateGameOver::GameStateGameOver(Game *game, const std::string &name) : GameState(game, name) {
	this->add_object(new TextBox(game, 120, 30, 350, 400, true, "GAME OVER!"));
	this->_team_box = new TextBox(game, 300, 30, 300, 300, true, "");
	this->add_object(this->_team_box);
	this->add_object(new TextBox(game, 300, 30, 300, 200, true, "Click anywhere to continue..."));
}

void GameStateGameOver::set_winning_team(Team *team) {
	std::string temp = "Team " + std::to_string((int)team->get_teamID());
	temp += " wins!";
	this->_team_box->set_text_color(team->get_team_color());
	this->_team_box->set_text(temp);
}

void GameStateGameOver::begin_state() {
}

void GameStateGameOver::reset_state() {
}

void GameStateGameOver::keyboard_functions(unsigned char key, int x, int y) {
}

void GameStateGameOver::mouse_functions(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		this->get_game()->set_state_by_name("main_menu");
	}
}
