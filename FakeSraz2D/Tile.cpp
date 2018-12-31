#include "stdafx.h"
#include <iostream>
#include <inttypes.h>
#include <utility>
#include "Question.h"
#include "Game.h"
#include "GameObject.h"
#include "PlayingBoard.h"
#include "GameState.h"
#include "GameObjectPawn.h"
#include "GameStateQuestion.h"
#include "GameStateQuestionBattle.h"
#include "Team.h"
#include "Tile.h"

Tile::Tile(float width, float height, float position_X, float position_Y, uint8_t index_X, uint8_t index_Y, PlayingBoard *owner_board) : 
	_width(width), _height(height), _position_X(position_X), _position_Y(position_Y), _index_X(index_X), _index_Y(index_Y), _owner_team(nullptr), 
	_current_pawn(nullptr), _owner_board(owner_board) {
	this->_tile_color = glm::vec4(0.659f, 0.698f, 0.757f, 1.0f);
}

Tile::~Tile() {
}

float Tile::get_position_X() {
	return this->_position_X;
}

float Tile::get_position_Y() {
	return this->_position_Y;
}

std::pair<float, float> Tile::get_position() {
	return std::make_pair(this->_position_X, this->_position_Y);
}

float Tile::get_width() {
	return this->_width;
}

float Tile::get_height() {
	return this->_height;
}

uint8_t Tile::get_index_X() {
	return this->_index_X;
}

uint8_t Tile::get_index_Y() {
	return this->_index_Y;
}

glm::vec4& Tile::get_tile_color() {
	return this->_tile_color;
}

Team* Tile::get_owner_team() {
	return this->_owner_team;
}

GameObjectPawn* Tile::get_current_pawn() {
	return this->_current_pawn;
}

PlayingBoard* Tile::get_owner_board() {
	return this->_owner_board;
}

void Tile::set_position_X(float position_X) {
	this->_position_X = position_X;
}

void Tile::set_position_Y(float position_Y) {
	this->_position_Y = position_Y;
}

void Tile::set_position(float position_X, float position_Y) {
	this->_position_X = position_X;
	this->_position_Y = position_Y;
}

void Tile::set_width(float width) {
	this->_width = width;
}

void Tile::set_height(float height) {
	this->_height = height;
}

void Tile::set_index_X(uint8_t index) {
	this->_index_X = index;
}

void Tile::set_index_Y(uint8_t index) {
	this->_index_Y = index;
}

void Tile::set_tile_color(const glm::vec3 &tile_color) {
	this->_tile_color = glm::vec4(tile_color, 1.0);
}

void Tile::set_tile_color(const glm::vec4 &tile_color) {
	this->_tile_color = tile_color;
}

void Tile::set_default_tile_color() {
	this->_tile_color = glm::vec4(0.659f, 0.698f, 0.757f, 1.0f);
}

void Tile::set_owner_team(Team* new_owner_team) {
	this->_owner_team = new_owner_team;
}

void Tile::set_current_pawn(GameObjectPawn *pawn) {
	this->_current_pawn = pawn;
}

void Tile::set_owner_board(PlayingBoard *owner_board) {
	this->_owner_board = owner_board;
}

void Tile::action(GameObjectPawn *attacking_pawn) {
	if (this->_current_pawn == nullptr) {
		if (this->_owner_team == nullptr || this->_owner_team->get_teamID() == attacking_pawn->get_owner_team()->get_teamID()) {
			GameStateQuestion *temp = static_cast<GameStateQuestion*>(this->get_owner_board()->get_game()->get_game_state_by_name("question"));
			temp->reset_state();
			temp->set_attacking_pawn(attacking_pawn);
			temp->set_attacked_tile(this);
			this->get_owner_board()->get_game()->set_state(temp);
			temp->begin_state();
		}
		else {
			GameStateQuestionBattle *temp = static_cast<GameStateQuestionBattle*>(this->get_owner_board()->get_game()->get_game_state_by_name("base_battle"));
			temp->reset_state();
			temp->set_number_of_questions(temp->get_number_of_questions() - attacking_pawn->get_equipment_level());
			temp->set_attacking_pawn(attacking_pawn);
			temp->set_attacked_tile(this);
			this->get_owner_board()->get_game()->set_state(temp);
			temp->begin_state();
		}
	}
	else {
		if (this->_owner_team == nullptr) {
			GameStateQuestionBattle *temp = static_cast<GameStateQuestionBattle*>(this->get_owner_board()->get_game()->get_game_state_by_name("pawn_battle"));
			temp->reset_state();
			temp->set_number_of_questions(temp->get_number_of_questions() - attacking_pawn->get_equipment_level() + this->_current_pawn->get_equipment_level());
			temp->set_attacking_pawn(attacking_pawn);
			temp->set_attacked_tile(this);
			this->get_owner_board()->get_game()->set_state(temp);
			temp->begin_state();
		}
		else {
			GameStateQuestionBattle *temp = static_cast<GameStateQuestionBattle*>(this->get_owner_board()->get_game()->get_game_state_by_name("base_pawn_battle"));
			temp->reset_state();
			temp->set_number_of_questions(temp->get_number_of_questions() - attacking_pawn->get_equipment_level() + this->_current_pawn->get_equipment_level());
			temp->set_attacking_pawn(attacking_pawn);
			temp->set_attacked_tile(this);
			this->get_owner_board()->get_game()->set_state(temp);
			temp->begin_state();
		}
	}
}