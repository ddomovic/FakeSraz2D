#include "stdafx.h"
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <GL/glut.h>
#include "Game.h"
#include "GameObject.h"
#include "GameObjectPawn.h"
#include "PlayingBoard.h"
#include "Team.h"
#include "Tile.h"
#include "GameState.h"
#include "GameStateGameOver.h"
#include "GameStatePlaying.h"

GameStatePlaying::GameStatePlaying(class Game *game, const std::string &name, PlayingBoard *board) : 
	GameState(game, name), _playing_board(board) {
	this->add_object(board);
}

void GameStatePlaying::begin_state() {
	Team *team_red = new Team(0, glm::vec3(0.639f, 0.043f, 0.043f));
	Team *team_blue = new Team(1, glm::vec3(0.043f, 0.035f, 0.6f));
	Team *team_green = new Team(2, glm::vec3(0.024f, 0.357f, 0.063f));
	Team *team_yellow = new Team(3, glm::vec3(0.627f, 0.627f, 0.024f));

	team_red->add_pawn(new GameObjectPawn(this->get_game(), true, team_red, this->_playing_board->get_tile_at(0, 0)));
	team_red->add_pawn(new GameObjectPawn(this->get_game(), true, team_red, this->_playing_board->get_tile_at(0, 1)));
	team_red->add_pawn(new GameObjectPawn(this->get_game(), true, team_red, this->_playing_board->get_tile_at(1, 0)));
	team_red->add_pawn(new GameObjectPawn(this->get_game(), true, team_red, this->_playing_board->get_tile_at(1, 1)));

	team_blue->add_pawn(new GameObjectPawn(this->get_game(), true, team_blue, this->_playing_board->get_tile_at(this->_playing_board->get_tile_number_X() - 1, 0)));
	team_blue->add_pawn(new GameObjectPawn(this->get_game(), true, team_blue, this->_playing_board->get_tile_at(this->_playing_board->get_tile_number_X() - 1, 1)));
	team_blue->add_pawn(new GameObjectPawn(this->get_game(), true, team_blue, this->_playing_board->get_tile_at(this->_playing_board->get_tile_number_X() - 2, 0)));
	team_blue->add_pawn(new GameObjectPawn(this->get_game(), true, team_blue, this->_playing_board->get_tile_at(this->_playing_board->get_tile_number_X() - 2, 1)));

	team_green->add_pawn(new GameObjectPawn(this->get_game(), true, team_green, this->_playing_board->get_tile_at(0, this->_playing_board->get_tile_number_Y() - 1)));
	team_green->add_pawn(new GameObjectPawn(this->get_game(), true, team_green, this->_playing_board->get_tile_at(0, this->_playing_board->get_tile_number_Y() - 2)));
	team_green->add_pawn(new GameObjectPawn(this->get_game(), true, team_green, this->_playing_board->get_tile_at(1, this->_playing_board->get_tile_number_Y() - 1)));
	team_green->add_pawn(new GameObjectPawn(this->get_game(), true, team_green, this->_playing_board->get_tile_at(1, this->_playing_board->get_tile_number_Y() - 2)));

	team_yellow->add_pawn(new GameObjectPawn(this->get_game(), true, team_yellow, this->_playing_board->get_tile_at(this->_playing_board->get_tile_number_X() - 1, this->_playing_board->get_tile_number_Y() - 1)));
	team_yellow->add_pawn(new GameObjectPawn(this->get_game(), true, team_yellow, this->_playing_board->get_tile_at(this->_playing_board->get_tile_number_X() - 1, this->_playing_board->get_tile_number_Y() - 2)));
	team_yellow->add_pawn(new GameObjectPawn(this->get_game(), true, team_yellow, this->_playing_board->get_tile_at(this->_playing_board->get_tile_number_X() - 2, this->_playing_board->get_tile_number_Y() - 1)));
	team_yellow->add_pawn(new GameObjectPawn(this->get_game(), true, team_yellow, this->_playing_board->get_tile_at(this->_playing_board->get_tile_number_X() - 2, this->_playing_board->get_tile_number_Y() - 2)));

	this->add_object(team_red->get_pawn_by_index(0));
	this->add_object(team_red->get_pawn_by_index(1));
	this->add_object(team_red->get_pawn_by_index(2));
	this->add_object(team_red->get_pawn_by_index(3));

	this->add_object(team_blue->get_pawn_by_index(0));
	this->add_object(team_blue->get_pawn_by_index(1));
	this->add_object(team_blue->get_pawn_by_index(2));
	this->add_object(team_blue->get_pawn_by_index(3));

	this->add_object(team_green->get_pawn_by_index(0));
	this->add_object(team_green->get_pawn_by_index(1));
	this->add_object(team_green->get_pawn_by_index(2));
	this->add_object(team_green->get_pawn_by_index(3));

	this->add_object(team_yellow->get_pawn_by_index(0));
	this->add_object(team_yellow->get_pawn_by_index(1));
	this->add_object(team_yellow->get_pawn_by_index(2));
	this->add_object(team_yellow->get_pawn_by_index(3));

	this->_teams.push_back(team_red);
	this->_teams.push_back(team_blue);
	this->_teams.push_back(team_green);
	this->_teams.push_back(team_yellow);
	this->_playing_board->get_tile_at(0, 0)->set_owner_team(team_red);
	this->_playing_board->get_tile_at(this->_playing_board->get_tile_number_X() - 1, 0)->set_owner_team(team_blue);
	this->_playing_board->get_tile_at(0, this->_playing_board->get_tile_number_Y() - 1)->set_owner_team(team_green);
	this->_playing_board->get_tile_at(this->_playing_board->get_tile_number_X() - 1, this->_playing_board->get_tile_number_Y() - 1)->set_owner_team(team_yellow);

	this->_current_team_index = rand() % this->_teams.size();
	this->_current_pawn_by_team.push_back(0);
	this->_current_pawn_by_team.push_back(0);
	this->_current_pawn_by_team.push_back(0);
	this->_current_pawn_by_team.push_back(0);

	this->_teams[0]->set_base_tile(this->_playing_board->get_tile_at(0, 0));
	this->_teams[1]->set_base_tile(this->_playing_board->get_tile_at(this->_playing_board->get_tile_number_X() - 1, 0));
	this->_teams[2]->set_base_tile(this->_playing_board->get_tile_at(0, this->_playing_board->get_tile_number_Y() - 1));
	this->_teams[3]->set_base_tile(this->_playing_board->get_tile_at(this->_playing_board->get_tile_number_X() - 1, this->_playing_board->get_tile_number_Y() - 1));

	this->turn_start();
}

void GameStatePlaying::reset_state() {
	for (std::vector<Team*>::iterator it = this->_teams.begin(); it != this->_teams.end(); ++it) {
		for (std::vector<GameObjectPawn*>::iterator it2 = (*it)->get_pawns().begin(); it2 != (*it)->get_pawns().end(); ++it2) {
			delete *it2;
		}
		delete *it;
	}

	this->_teams.clear();
	this->_current_pawn_by_team.clear();
	GameObjectPawn::_global_pawn_ID = 0;
}

bool GameStatePlaying::check_if_tile_available(int x_to_check, int y_to_check, uint8_t current_team_ID) {
	if (x_to_check < this->_playing_board->get_tile_number_X() && x_to_check >= 0 && 
		y_to_check < this->_playing_board->get_tile_number_Y() && y_to_check >= 0) {
		GameObjectPawn *aux_pawn = this->_playing_board->get_tile_at(x_to_check, y_to_check)->get_current_pawn();
		if (aux_pawn && (aux_pawn->get_owner_team()->get_teamID() == current_team_ID)) {
			return false;
		}
		else {
			return true;
		}
	}
	return false;
}

void GameStatePlaying::turn_start() {

	for (std::vector<Tile*>::iterator it = this->_tiles_to_check.begin(); it != this->_tiles_to_check.end(); ++it) {
		(*it)->set_default_tile_color();
	}
	if (this->_teams.size() == 1) {
		GameStateGameOver *g_o = static_cast<GameStateGameOver*>(this->get_game()->get_game_state_by_name("game_over"));
		g_o->set_winning_team(this->_teams[0]);
		this->reset_state();
		this->get_game()->set_state(g_o);
		return;
	}
	this->_tiles_to_check.clear();
	this->_current_team_index = (this->_current_team_index + 1) % this->_teams.size();
	this->_current_pawn_by_team[this->_current_team_index] = (this->_current_pawn_by_team[this->_current_team_index] + 1) % 
		this->_teams[this->_current_team_index]->get_pawns().size();

	GameObjectPawn *current_pawn = this->_teams[this->_current_team_index]->get_pawn_by_index(
		this->_current_pawn_by_team[this->_current_team_index]);
	current_pawn->get_current_tile()->set_tile_color(glm::vec3(0.569f, 0.31f, 0.302f));
	uint8_t current_X = current_pawn->get_current_tile()->get_index_X();
	uint8_t current_Y = current_pawn->get_current_tile()->get_index_Y();
	if (this->check_if_tile_available(current_X + 1, current_Y, current_pawn->get_owner_team()->get_teamID())) {
		this->_tiles_to_check.push_back(this->_playing_board->get_tile_at(current_X + 1, current_Y));
		this->_playing_board->get_tile_at(current_X + 1, current_Y)->set_tile_color(glm::vec3(0.392f, 0.569f, 0.369f));
	}
	if (this->check_if_tile_available(current_X - 1, current_Y, current_pawn->get_owner_team()->get_teamID())) {
		this->_tiles_to_check.push_back(this->_playing_board->get_tile_at(current_X - 1, current_Y));
		this->_playing_board->get_tile_at(current_X - 1, current_Y)->set_tile_color(glm::vec3(0.392f, 0.569f, 0.369f));
	}
	if (this->check_if_tile_available(current_X, current_Y + 1, current_pawn->get_owner_team()->get_teamID())) {
		this->_tiles_to_check.push_back(this->_playing_board->get_tile_at(current_X, current_Y + 1));
		this->_playing_board->get_tile_at(current_X, current_Y + 1)->set_tile_color(glm::vec3(0.392f, 0.569f, 0.369f));
	}
	if (this->check_if_tile_available(current_X, current_Y - 1, current_pawn->get_owner_team()->get_teamID())) {
		this->_tiles_to_check.push_back(this->_playing_board->get_tile_at(current_X, current_Y - 1));
		this->_playing_board->get_tile_at(current_X, current_Y - 1)->set_tile_color(glm::vec3(0.392f, 0.569f, 0.369f));
	}

	if (this->_tiles_to_check.empty()) {
		current_pawn->get_current_tile()->set_tile_color(glm::vec3(0.0f, 0.0f, 0.0f));
		this->turn_start();
		current_pawn->get_current_tile()->set_default_tile_color();
	}
}

void GameStatePlaying::keyboard_functions(unsigned char key, int x, int y) {
}

bool check_if_clicked(Tile *tile, int x, int y) {
	float tile_x = tile->get_position_X();
	float tile_y = tile->get_position_Y();
	float tile_width = tile->get_width();
	float tile_height = tile->get_height();

	if (x >= tile_x && x <= tile_x + tile_width) {
		if (y >= tile_y && y <= tile_y + tile_height) {
			return true;
		}
	}
	return false;
}

void GameStatePlaying::mouse_functions(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		for (std::vector<Tile*>::iterator it = this->_tiles_to_check.begin(); it != this->_tiles_to_check.end(); ++it) {
			if (check_if_clicked(*it, x, y)) {
				GameObjectPawn *p = this->_teams[this->_current_team_index]->get_pawn_by_index(
					this->_current_pawn_by_team[this->_current_team_index]);
				(*it)->action(p);
				break;
			}
		}
	}
}

void GameStatePlaying::kill_pawn(GameObjectPawn *pawn_to_kill) {
	Team *temp = pawn_to_kill->get_owner_team();
	for (int i = 0; i < temp->get_pawns().size(); i++) {
		if (temp->get_pawns()[i]->get_pawn_ID() == pawn_to_kill->get_pawn_ID()) {
			temp->get_pawns().erase(temp->get_pawns().begin() + i);
			break;
		}
	}
	pawn_to_kill->get_current_tile()->set_current_pawn(nullptr);
	this->remove_object(pawn_to_kill);
	delete pawn_to_kill;
}

void GameStatePlaying::kill_team(Team *team_to_kill) {
	while (team_to_kill->get_pawns().size() > 0) {
		this->kill_pawn(team_to_kill->get_pawns()[0]);
	}
	for (int i = 0; i < this->_teams.size(); i++) {
		if (this->_teams[i]->get_teamID() == team_to_kill->get_teamID()) {
			this->_teams[i]->get_base_tile()->set_owner_team(nullptr);
			this->_teams.erase(this->_teams.begin() + i);
			break;
		}
	}
	delete team_to_kill;
}
