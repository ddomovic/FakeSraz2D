#include "stdafx.h"
#include <inttypes.h>
#include <GL/glut.h>
#include <glm/glm.hpp>
#include "Game.h"
#include "Tile.h"
#include "Team.h"
#include "GameObject.h"
#include "GameObjectPawn.h"

GameObjectPawn::GameObjectPawn(Game *game, bool is_drawable, Team *team, Tile *tile) : GameObject(game, 0, 0, is_drawable), 
	_pawn_ID(++_global_pawn_ID), _owner_team(team), _current_tile(tile) {
	this->set_X(tile->get_position_X() + tile->get_width() * DEFAULT_PAWN_POSITION_X_MULTIPLIER);
	this->set_Y(tile->get_position_Y() + tile->get_height() * DEFAULT_PAWN_POSITION_Y_MULTIPLIER);
	this->set_width(tile->get_width() * DEFAULT_PAWN_SIZE_X_MULTIPLIER);
	this->set_height(tile->get_height() * DEFAULT_PAWN_SIZE_Y_MULTIPLIER);
	this->_current_tile->set_current_pawn(this);
}

GameObjectPawn::GameObjectPawn(Game *game, float width, float height, bool is_drawable, Team *team, Tile *tile) :
	GameObject(game, width, height, is_drawable), _pawn_ID(++_global_pawn_ID), _owner_team(team), _equipment_level(0) {
}

uint8_t GameObjectPawn::_global_pawn_ID = 0;

uint8_t GameObjectPawn::get_equipment_level() {
	return this->_equipment_level;
}

uint8_t GameObjectPawn::get_pawn_ID() {
	return this->_pawn_ID;
}

Team* GameObjectPawn::get_owner_team() {
	return this->_owner_team;
}

Tile* GameObjectPawn::get_current_tile() {
	return this->_current_tile;
}

void GameObjectPawn::set_equipment_level(uint8_t equipment_level) {
	this->_equipment_level = equipment_level;
}

void GameObjectPawn::inc_equipment_level() {
	if (this->_equipment_level >= 2) {
		return;
	}
	this->_equipment_level++;
}

void GameObjectPawn::set_owner_team(Team *team) {
	this->_owner_team = team;
}

void GameObjectPawn::set_current_tile(Tile *tile) {
	this->_current_tile->set_current_pawn(nullptr);
	this->_current_tile = tile;
	this->_current_tile->set_current_pawn(this);
	this->set_X(tile->get_position_X() + tile->get_width() * DEFAULT_PAWN_POSITION_X_MULTIPLIER);
	this->set_Y(tile->get_position_Y() + tile->get_height() * DEFAULT_PAWN_POSITION_Y_MULTIPLIER);
}

void GameObjectPawn::draw_object() {
	glm::vec4 color = this->_owner_team->get_team_color();
	glColor4f(color.x, color.y, color.z, color.w);
	glBegin(GL_QUADS);
	glVertex2f(this->get_X(), this->get_Y());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X(), this->get_Y() + this->get_height());

	glVertex2f(this->get_X() - 2, this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width() + 2, this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width() + 2, this->get_Y() - this->get_width() + this->get_height());
	glVertex2f(this->get_X() - 2, this->get_Y() - this->get_width() + this->get_height());

	if (this->_equipment_level > 0) {
		glVertex2f(this->get_X(), this->get_Y() + this->get_height() * 0.5f);
		glVertex2f(this->get_X() - 4, this->get_Y() + this->get_height() * 0.5f);
		glVertex2f(this->get_X() - 4, this->get_Y() + this->get_height() * 0.5f + 2);
		glVertex2f(this->get_X(), this->get_Y() + this->get_height() * 0.5f + 2);

		glVertex2f(this->get_X() - 4, this->get_Y() + this->get_height() * 0.45f);
		glVertex2f(this->get_X() - 4, this->get_Y() + this->get_height() - 2);
		glVertex2f(this->get_X() - 6, this->get_Y() + this->get_height() - 2);
		glVertex2f(this->get_X() - 6, this->get_Y() + this->get_height() * 0.45f);
	}
	if (this->_equipment_level > 1) {
		glVertex2f(this->get_X() + this->get_width() - 2, this->get_Y() + this->get_height() * 0.65f);
		glVertex2f(this->get_X() + this->get_width() + 5, this->get_Y() + this->get_height() * 0.65f);
		glVertex2f(this->get_X() + this->get_width() + 5, this->get_Y() + this->get_height() * 0.35f);
		glVertex2f(this->get_X() + this->get_width() - 2, this->get_Y() + this->get_height() * 0.35f);
	}

	glEnd();
}
