#pragma once

#include <string>

class GameStateQuestion : public GameState {
private:
	class QuestionDB *_question_database;
	class GameObjectQuestionBox *_question_box;
	class GameObjectPawn *_attacking_pawn;
	class Tile *_attacked_tile;
	std::string _correct_answer;
protected:
	virtual bool check_if_clicked(class GameObjectButton *button, int x, int y);
public:
	GameStateQuestion(class Game *game, const std::string &state_name, class QuestionDB *database, class GameObjectQuestionBox *question_box);
	virtual class QuestionDB* get_question_database();
	virtual class GameObjectQuestionBox* get_question_box();
	virtual class GameObjectPawn* get_attacking_pawn();
	virtual const std::string& get_correct_answer();
	virtual Tile* get_attacked_tile();
	virtual void set_question_database(class QuestionDB *database);
	virtual void set_random_question();
	virtual void set_attacking_pawn(class GameObjectPawn *attacking_pawn);
	virtual void set_attacked_tile(class Tile *attacked_tile);
	virtual void begin_state();
	virtual void reset_state();
	virtual void keyboard_functions(unsigned char key, int x, int y);
	virtual void mouse_functions(int button, int state, int x, int y);
};