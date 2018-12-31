#pragma once

class GameObjectQuestionBox : public GameObject {
private:
	class TextBox *_question_text;
	class TextBox *_answer1;
	class TextBox *_answer2;
	class TextBox *_answer3;
	class TextBox *_answer4;
	class GameObjectButton *_button1;
	class GameObjectButton *_button2;
	class GameObjectButton *_button3;
	class GameObjectButton *_button4;
public:
	GameObjectQuestionBox(class Game *game, float width, float height, float position_X, float position_Y, bool is_drawable);
	~GameObjectQuestionBox();
	void set_question_text(const std::string &question);
	void set_answer1(const std::string &answer);
	void set_answer2(const std::string &answer);
	void set_answer3(const std::string &answer);
	void set_answer4(const std::string &answer);
	const std::string& get_answer1();
	const std::string& get_answer2();
	const std::string& get_answer3();
	const std::string& get_answer4();
	class GameObjectButton* get_button1();
	class GameObjectButton* get_button2();
	class GameObjectButton* get_button3();
	class GameObjectButton* get_button4();
	void draw_object();
};