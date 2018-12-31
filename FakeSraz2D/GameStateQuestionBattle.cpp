#include "stdafx.h"
#include <inttypes.h>
#include <iostream>
#include <GL/glut.h>
#include "Game.h"
#include "GameObject.h"
#include "GameObjectQuestionBox.h"
#include "GameObjectPawn.h"
#include "GameObjectButton.h"
#include "QuestionDB.h"
#include "Tile.h"
#include "Team.h"
#include "GameState.h"
#include "GameStatePlaying.h"
#include "GameStateQuestion.h"
#include "GameStateQuestionBattle.h"

GameStateQuestionBattle::GameStateQuestionBattle(Game *game, const std::string& state_name, QuestionDB *database, uint8_t number_of_questions, GameObjectQuestionBox *box) :
	GameStateQuestion(game, state_name, database, box), _number_of_questions(number_of_questions), 
	_original_number_of_questions(number_of_questions) {
}

uint8_t GameStateQuestionBattle::get_number_of_questions() {
	return this->_number_of_questions;
}

void GameStateQuestionBattle::set_number_of_questions(uint8_t number_of_questions) {
	if (number_of_questions > 0) {
		this->_number_of_questions = number_of_questions;
	}
	else {
		this->_number_of_questions = 1;
	}
}

void GameStateQuestionBattle::begin_state() {
	GameStateQuestion::begin_state();
}

void GameStateQuestionBattle::reset_state() {
	GameStateQuestion::reset_state();
	this->_number_of_questions = this->_original_number_of_questions;
}

void GameStateQuestionBattle::keyboard_functions(unsigned char key, int x, int y) {
}

void GameStateQuestionBattle::mouse_functions(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		bool wrong_answer = false;
		std::string to_compare;
		to_compare.clear();
		if (this->check_if_clicked(this->get_question_box()->get_button1(), x, y)) {
			to_compare = "a)";
		}
		else if (this->check_if_clicked(this->get_question_box()->get_button2(), x, y)) {
			to_compare = "b)";
		}
		else if (this->check_if_clicked(this->get_question_box()->get_button3(), x, y)) {
			to_compare = "c)";
		}
		else if (this->check_if_clicked(this->get_question_box()->get_button4(), x, y)) {
			to_compare = "d)";
		}
		if (!to_compare.empty()) {
			this->get_attacking_pawn()->get_current_tile()->set_default_tile_color();
			if (to_compare == this->get_correct_answer()) {
				this->_number_of_questions--;
			}
			else {
				wrong_answer = true;
			}
		}
		if (this->_number_of_questions == 0 || wrong_answer) {
			GameStatePlaying *playing_state = static_cast<GameStatePlaying*>(this->get_game()->get_game_state_by_name("playing"));
			if (!wrong_answer) {
				bool kill_t = false;
				Team *temp_team = nullptr;
				if (this->get_attacked_tile()->get_current_pawn()) {
					temp_team = this->get_attacked_tile()->get_current_pawn()->get_owner_team();
					if (temp_team->get_pawns().size() == 1) {
						kill_t = true;
					}
					playing_state->kill_pawn(this->get_attacked_tile()->get_current_pawn());
				}
				if (this->get_attacked_tile()->get_owner_team()) {
					playing_state->kill_team(this->get_attacked_tile()->get_owner_team());
					kill_t = false;
				}
				if (kill_t) {
					playing_state->kill_team(temp_team);
				}
				this->get_attacking_pawn()->inc_equipment_level();
				this->get_attacking_pawn()->set_current_tile(this->get_attacked_tile());
			}
			this->get_game()->set_state(playing_state);
			playing_state->turn_start();
		}
		else {
			this->set_random_question();
		}
	}
}
