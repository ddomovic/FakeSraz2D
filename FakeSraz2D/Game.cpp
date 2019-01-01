#include "stdafx.h"
#include <iostream>
#include "GameObject.h"
#include "GameState.h"
#include "GameStateMainMenu.h"
#include "GameStateGameOver.h"
#include "GameStatePlaying.h"
#include "GameStateQuestion.h"
#include "GameStateQuestionBattle.h"
#include "GameObjectPawn.h"
#include "GameObjectButton.h"
#include "TextBox.h"
#include "GameObjectQuestionBox.h"
#include "PlayingBoard.h"
#include "QuestionDB.h"
#include "Team.h"
#include "WindowData.h"
#include "TextRenderer.h"
#include "Game.h"

Game::Game(WindowData *window_data) {
	this->_window_data = window_data;
	this->_text_renderer = new TextRenderer();
}

Game::~Game() {
	delete this->_text_renderer;
}

class GameState* Game::get_current_state() {
	return this->_current_state;
}

void Game::set_state_by_name(const std::string &name) {
	for (std::vector<GameState*>::iterator it = this->_all_states.begin(); it != this->_all_states.end(); ++it) {
		if ((*it)->get_state_name() == name) {
			this->_current_state = *it;
			return;
		}
	}
	std::cerr << "No such state!" << std::endl;
}

void Game::set_state(class GameState *state) {
	this->_current_state = state;
}

class GameState* Game::get_game_state_by_name(const std::string &name) {

	for (std::vector<GameState*>::iterator it = this->_all_states.begin(); it != this->_all_states.end(); ++it) {
		if ((*it)->get_state_name() == name) {
			return *it;
		}
	}
	return nullptr;
}

TextRenderer* Game::get_text_renderer() {
	return this->_text_renderer;
}

void Game::start_game() {
	QuestionDB *qdb = new QuestionDB("qst\\questions.bin");
	GameObjectQuestionBox *box = new GameObjectQuestionBox(this, 400, 400, 100, 100, true);
	if (!qdb->read_questions()) {
		std::cout << "EXITING!\n";
		exit(2);
	}
	
	this->_all_states.push_back(new GameStateMainMenu(this, "main_menu"));
	this->_all_states.push_back(new GameStatePlaying(this, "playing", new PlayingBoard(this, 500, 500, 150, 50, 7, 7)));
	this->_all_states.push_back(new GameStateGameOver(this, "game_over"));
	this->_all_states.push_back(new GameStateQuestion(this, "question", qdb, box));
	this->_all_states.push_back(new GameStateQuestionBattle(this, "base_battle", qdb, DEFAULT_BASE_QUESTIONS, box));
	this->_all_states.push_back(new GameStateQuestionBattle(this, "pawn_battle", qdb, DEFAULT_PAWN_QUESTIONS, box));
	this->_all_states.push_back(new GameStateQuestionBattle(this, "base_pawn_battle", qdb, DEFAULT_BASE_QUESTIONS + DEFAULT_PAWN_QUESTIONS, box));

	this->_current_state = this->_all_states[0];	
	this->_current_state->begin_state();
}

void Game::render_scene() {
	
	std::vector<GameObject*> temp_vec = this->_current_state->get_objects();

	for (std::vector<GameObject*>::iterator it = temp_vec.begin(); it != temp_vec.end(); ++it) {
		(*it)->draw_object();
	}
}