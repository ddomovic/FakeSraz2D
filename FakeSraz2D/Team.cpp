#include "stdafx.h"
#include <inttypes.h>
#include <vector>
#include "GameObject.h"
#include "GameObjectPawn.h"
#include "Tile.h"
#include "Team.h"

Team::Team(uint8_t teamID, glm::vec4 team_color) : _teamID(teamID), _team_color(team_color) {
}

Team::Team(uint8_t teamID, glm::vec3 team_color) : _teamID(teamID) {
	this->_team_color = glm::vec4(team_color.x, team_color.y, team_color.z, 1.0);
}

uint8_t Team::get_teamID() {
	return this->_teamID;
}

glm::vec4 Team::get_team_color() {
	return this->_team_color;
}

std::vector<GameObjectPawn*>& Team::get_pawns() {
	return this->_pawns;
}

GameObjectPawn* Team::get_pawn_by_index(int index) {
	return this->_pawns[index];
}

Tile* Team::get_base_tile() {
	return this->_base_tile;
}

void Team::set_teamID(uint8_t teamID) {
	this->_teamID = teamID;
}

void Team::set_team_color(glm::vec4 team_color) {
	this->_team_color = team_color;
}

void Team::set_team_color(glm::vec3 team_color) {
	this->_team_color = glm::vec4(team_color.x, team_color.y, team_color.z, 1.0);
}

void Team::set_pawns(std::vector<GameObjectPawn*> &pawns) {
	this->_pawns = pawns;
}

void Team::set_base_tile(Tile *base_tile) {
	this->_base_tile = base_tile;
}

void Team::add_pawn(GameObjectPawn *new_pawn) {
	this->_pawns.push_back(new_pawn);
}
