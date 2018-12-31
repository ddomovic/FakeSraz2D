#include "stdafx.h"
#include <GL/glut.h>
#include "Game.h"
#include "GameObject.h"
#include "TextBox.h"
#include "GameObjectButton.h"
#include "GameObjectQuestionBox.h"

GameObjectQuestionBox::GameObjectQuestionBox(Game *game, float width, float height, float position_X, float position_Y, bool is_drawable) : 
	GameObject(game, width, height, position_X, position_Y, is_drawable) {

	this->_question_text = new TextBox(game, width - 6, height * 0.5f - 6, position_X + 3, height * 0.5f + position_Y + 3, true, "");
	this->_button1 = new GameObjectButton(game, 25, 20, position_X + 3, position_Y + height * 0.5f - 3, true, "a)");
	this->_button2 = new GameObjectButton(game, 25, 20, position_X + 3, position_Y + height * 0.5f - 24, true, "b)");
	this->_button3 = new GameObjectButton(game, 25, 20, position_X + 3, position_Y + height * 0.5f - 45, true, "c)");
	this->_button4 = new GameObjectButton(game, 25, 20, position_X + 3, position_Y + height * 0.5f - 66, true, "d)");
	this->_answer1 = new TextBox(game, width - 25 - 6, 20, position_X + 3 + 25, position_Y + height * 0.5f - 3, true, "");
	this->_answer2 = new TextBox(game, width - 25 - 6, 20, position_X + 3 + 25, position_Y + height * 0.5f - 24, true, "");
	this->_answer3 = new TextBox(game, width - 25 - 6, 20, position_X + 3 + 25, position_Y + height * 0.5f - 45, true, "");
	this->_answer4 = new TextBox(game, width - 25 - 6, 20, position_X + 3 + 25, position_Y + height * 0.5f - 66, true, "");
}

GameObjectQuestionBox::~GameObjectQuestionBox() {
	delete _question_text;
	delete _answer1;
	delete _answer2;
	delete _answer3;
	delete _answer4;
	delete _button1;
	delete _button2;
	delete _button3;
	delete _button4;
}

void GameObjectQuestionBox::set_question_text(const std::string &question) {
	this->_question_text->set_text(question);
}

void GameObjectQuestionBox::set_answer1(const std::string &answer) {
	this->_answer1->set_text(answer);
}

void GameObjectQuestionBox::set_answer2(const std::string &answer) {
	this->_answer2->set_text(answer);
}

void GameObjectQuestionBox::set_answer3(const std::string &answer) {
	this->_answer3->set_text(answer);
}

void GameObjectQuestionBox::set_answer4(const std::string &answer) {
	this->_answer4->set_text(answer);
}

const std::string& GameObjectQuestionBox::get_answer1() {
	return this->_answer1->get_text();
}

const std::string& GameObjectQuestionBox::get_answer2() {
	return this->_answer2->get_text();
}

const std::string& GameObjectQuestionBox::get_answer3() {
	return this->_answer3->get_text();
}

const std::string& GameObjectQuestionBox::get_answer4() {
	return this->_answer4->get_text();
}

GameObjectButton * GameObjectQuestionBox::get_button1() {
	return this->_button1;
}

GameObjectButton * GameObjectQuestionBox::get_button2() {
	return this->_button2;
}

GameObjectButton * GameObjectQuestionBox::get_button3() {
	return this->_button3;
}

GameObjectButton * GameObjectQuestionBox::get_button4() {
	return this->_button4;
}

void GameObjectQuestionBox::draw_object() {
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
	glVertex2f(this->get_X(), this->get_Y());
	glVertex2f(this->get_X(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y());
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex2f(this->get_X(), this->get_Y());
	glVertex2f(this->get_X(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y());
	glEnd();
	this->_question_text->draw_object();
	this->_answer1->draw_object();
	this->_answer2->draw_object();
	this->_answer3->draw_object();
	this->_answer4->draw_object();
	this->_button1->draw_object();
	this->_button2->draw_object();
	this->_button3->draw_object();
	this->_button4->draw_object();
}
