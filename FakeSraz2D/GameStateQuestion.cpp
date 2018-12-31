#include "stdafx.h"
#include <iostream>
#include <GL/glut.h>
#include "Game.h"
#include "GameObject.h"
#include "GameObjectQuestionBox.h"
#include "GameObjectButton.h"
#include "GameObjectPawn.h"
#include "Question.h"
#include "QuestionDB.h"
#include "Tile.h"
#include "GameState.h"
#include "GameStatePlaying.h"
#include "GameStateQuestion.h"

GameStateQuestion::GameStateQuestion(Game *game, const std::string &state_name, QuestionDB *database, GameObjectQuestionBox *question_box) : 
	GameState(game, state_name), _question_database(database), _question_box(question_box) {
	this->_question_database->read_questions();
	this->add_object(question_box);
}

QuestionDB* GameStateQuestion::get_question_database() {
	return this->_question_database;
}

GameObjectQuestionBox * GameStateQuestion::get_question_box() {
	return this->_question_box;
}

GameObjectPawn* GameStateQuestion::get_attacking_pawn() {
	return this->_attacking_pawn;
}

const std::string& GameStateQuestion::get_correct_answer() {
	return this->_correct_answer;
}

Tile* GameStateQuestion::get_attacked_tile() {
	return this->_attacked_tile;
}

void GameStateQuestion::set_question_database(QuestionDB *database) {
	this->_question_database = database;
}

void GameStateQuestion::set_random_question() {
	Question *temp = this->_question_database->get_random_question();
	
	this->_question_box->set_question_text(temp->get_question());
	
	std::vector<int> aux_vector{1, 2, 3, 4};
	std::vector<std::string> answers;
	int j = 0;
	while (!aux_vector.empty()) {
		int random_index = rand() % aux_vector.size();
		int index = aux_vector[random_index];
		if (index == 1) {
			answers.push_back(temp->get_correct_answer());
			this->_correct_answer = std::string(1, (char)(97 + j)) + ")";
		}
		else if (index == 2) {
			answers.push_back(temp->get_wrong_answer1());
		}
		else if (index == 3) {
			answers.push_back(temp->get_wrong_answer2());
		}
		else {
			answers.push_back(temp->get_wrong_answer3());
		}
		aux_vector.erase(aux_vector.begin() + random_index);
		j++;
	}
	this->_question_box->set_answer1(answers[0]);
	this->_question_box->set_answer2(answers[1]);
	this->_question_box->set_answer3(answers[2]);
	this->_question_box->set_answer4(answers[3]);
}

void GameStateQuestion::set_attacking_pawn(GameObjectPawn *attacking_pawn) {
	this->_attacking_pawn = attacking_pawn;
}

void GameStateQuestion::set_attacked_tile(Tile *attacked_tile) {
	this->_attacked_tile = attacked_tile;
}

void GameStateQuestion::begin_state() {
	this->set_random_question();
}

void GameStateQuestion::reset_state() {
	this->_attacking_pawn = nullptr;
	this->_attacked_tile = nullptr;
	this->_correct_answer.clear();
}

void GameStateQuestion::keyboard_functions(unsigned char key, int x, int y) {
}

bool GameStateQuestion::check_if_clicked(GameObjectButton *button, int x, int y) {
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

void GameStateQuestion::mouse_functions(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		std::string to_compare;
		to_compare.clear();
		if (check_if_clicked(this->_question_box->get_button1(), x, y)) {
			to_compare = "a)";
		}
		else if (check_if_clicked(this->_question_box->get_button2(), x, y)) {
			to_compare = "b)";
		}
		else if (check_if_clicked(this->_question_box->get_button3(), x, y)) {
			to_compare = "c)";
		}
		else if (check_if_clicked(this->_question_box->get_button4(), x, y)) {
			to_compare = "d)";
		}
		if (!to_compare.empty()) {
			this->_attacking_pawn->get_current_tile()->set_default_tile_color();
			if (to_compare == this->_correct_answer) {
				this->_attacking_pawn->set_current_tile(this->_attacked_tile);
			}
			GameStatePlaying *playing_state = static_cast<GameStatePlaying*>(this->get_game()->get_game_state_by_name("playing"));
			this->get_game()->set_state(playing_state);
			playing_state->turn_start();
		}
	}
}
