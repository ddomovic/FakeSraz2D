#pragma once

#include <string>

class GameStateQuestionBattle : public GameStateQuestion {
private:
	uint8_t _number_of_questions;
	uint8_t _original_number_of_questions;
public:
	GameStateQuestionBattle(Game *game, const std::string& state_name, class QuestionDB *database, uint8_t number_of_questions, class GameObjectQuestionBox *box);
	uint8_t get_number_of_questions();
	void set_number_of_questions(uint8_t number_of_questions);
	void begin_state();
	void reset_state();
	void keyboard_functions(unsigned char key, int x, int y);
	void mouse_functions(int button, int state, int x, int y);
};