#include "stdafx.h"
#include <GL\glut.h>
#include "Game.h"
#include "TextRenderer.h"
#include "GameObject.h"
#include "GameObjectButton.h"

GameObjectButton::GameObjectButton(Game *game, float width, float height, float position_X, float position_Y, bool is_drawable, const std::string &text) : 
	GameObject(game, width, height, position_X, position_Y, is_drawable), _text(text) {	
	this->_text_renderer = this->get_game()->get_text_renderer();
	this->_maximum_text_X = (int)(width * 0.8 / 8.0f);
}

void GameObjectButton::set_text(const std::string &text) {
	this->_text = text;
}

void GameObjectButton::set_width(float width) {
	GameObject::set_width(width);
	this->_maximum_text_X = (int)(width * 0.8 / 8.0f);
}

const std::string& GameObjectButton::get_text() {
	return this->_text;
}

void GameObjectButton::on_pressed() {

}

void GameObjectButton::draw_object() {
	glColor3f(0.8f, 0.8f, 0.8f);
	glBegin(GL_QUADS);
	glVertex2f(this->get_X(), this->get_Y());
	glVertex2f(this->get_X(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y());
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
	glVertex2f(this->get_X() + 2, this->get_Y() + 2);
	glVertex2f(this->get_X() + 2, this->get_Y() + this->get_height() - 2);
	glVertex2f(this->get_X() - 2 + this->get_width(), this->get_Y() + this->get_height() - 2);
	glVertex2f(this->get_X() - 2 + this->get_width(), this->get_Y() + 2);
	glEnd();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (this->get_height() < 13 / 0.8) {
		return;
	}
	glColor3f(0.0f, 0.0f, 0.0f);
	int aux;
	if (this->_maximum_text_X > this->_text.length()) {
		this->_text_renderer->simple_render_text(this->_text.substr(0),
			0.1*this->get_width() + this->get_X(), 0.5*this->get_height() - 6 + this->get_Y());
	}
	else {
		this->_text_renderer->simple_render_text(this->_text.substr(0, this->_maximum_text_X),
			0.1*this->get_width() + this->get_X(), 0.5*this->get_height() - 6 + this->get_Y());
	}	
}
