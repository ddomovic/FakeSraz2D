#include "stdafx.h"
#include <string>
#include "Game.h"
#include "GameObject.h"
#include "GameState.h"

GameState::GameState(Game *game, const std::string &state_name) : _game(game), _state_name(state_name) {
}

const std::string& GameState::get_state_name() {
	return this->_state_name;
}

const std::vector<GameObject*>& GameState::get_objects() {
	return this->_objects_to_draw;
}

GameObject* GameState::get_object_by_index(int index) {
	return this->_objects_to_draw[index];
}

Game* GameState::get_game() {
	return this->_game;
}

void GameState::add_object(GameObject *object) {
	this->_objects_to_draw.push_back(object);
}

void GameState::remove_object(GameObject *object) {
	for (int i = 0; i < this->_objects_to_draw.size(); i++) {
		if (object == this->_objects_to_draw[i]) {
			this->_objects_to_draw.erase(this->_objects_to_draw.begin() + i);
			break;
		}
	}
}

void GameState::draw_objects() {
	for (std::vector<GameObject*>::iterator it = this->_objects_to_draw.begin(); it != this->_objects_to_draw.end(); ++it) {
		(*it)->draw_object();
	}
}