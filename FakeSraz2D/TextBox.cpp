#include "stdafx.h"
#include <GL/glut.h>
#include "Game.h"
#include "TextRenderer.h"
#include "GameObject.h"
#include "TextBox.h"

TextBox::TextBox(Game *game, float width, float height, float position_X, float position_Y, bool is_drawable, const std::string &text) :
	GameObject(game, width, height, position_X, position_Y, is_drawable), _text(text) {
	this->_text_renderer = this->get_game()->get_text_renderer();
	this->_maximum_text_X = (int)(0.8 * this->get_width() / 8.0f);
	this->_maximum_text_Y = (int)(0.8 * this->get_height() / 13.0f);
	this->_border_color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	this->_background_color = glm::vec4(0.373f, 0.412f, 0.478f, 1.0f);
	this->_text_color = glm::vec4(0.078f, 0.047f, 0.008f, 1.0f);

	this->adjust_text_drawing_parameters();
}

void TextBox::adjust_text_drawing_parameters() {
	
	this->_text_to_draw.clear();
	if (this->_maximum_text_Y > 0) {
		int i = 0, j = 0;
		while (i < this->_text.length()) {
			if (i + this->_maximum_text_X > this->_text.length()) {
				this->_text_to_draw.push_back(this->_text.substr(i));
			}
			else {
				this->_text_to_draw.push_back(this->_text.substr(i, this->_maximum_text_X));
			}
			if (j++ >= this->_maximum_text_Y) {
				break;
			}
			i += this->_maximum_text_X;
		}
	}
}

const std::string & TextBox::get_text() {
	return this->_text;
}

TextRenderer* TextBox::get_text_renderer() {
	return this->_text_renderer;
}

int TextBox::get_maximum_text_X() {
	return this->_maximum_text_X;
}

int TextBox::get_maximum_text_Y() {
	return this->_maximum_text_Y;
}

glm::vec4 TextBox::get_border_color() {
	return this->_border_color;
}

glm::vec4 TextBox::get_background_color() {
	return this->_background_color;
}

glm::vec4 TextBox::get_text_color() {
	return this->_text_color;
}

void TextBox::set_text(const std::string &text) {
	this->_text = text;
	this->adjust_text_drawing_parameters();
}

void TextBox::set_text_renderer(TextRenderer *text_renderer) {
	this->_text_renderer = text_renderer;
}

void TextBox::set_border_color(glm::vec4 color) {
	this->_border_color = color;
}

void TextBox::set_border_color(glm::vec3 color) {
	this->_border_color = glm::vec4(color, 1.0);
}

void TextBox::set_background_color(glm::vec4 color) {
	this->_background_color = color;
}

void TextBox::set_background_color(glm::vec3 color) {
	this->_background_color = glm::vec4(color, 1.0);
}

void TextBox::set_text_color(glm::vec4 color) {
	this->_text_color = color;
}

void TextBox::set_text_color(glm::vec3 color) {
	this->_text_color = glm::vec4(color, 1.0);
}

void TextBox::set_width(float width) {
	GameObject::set_width(width);
	this->_maximum_text_X = (int)(0.8 * width / 8.0f);
	this->adjust_text_drawing_parameters();
}

void TextBox::set_height(float height) {
	GameObject::set_height(height);
	this->_maximum_text_Y = (int)(0.8 * height / 13.0f);
	this->adjust_text_drawing_parameters();
}

void TextBox::draw_object() {
	glColor4f(this->_border_color.x, this->_border_color.y, this->_border_color.z, this->_border_color.w);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
	glVertex2f(this->get_X(), this->get_Y());
	glVertex2f(this->get_X(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y());
	glEnd();
	
	glColor4f(this->_background_color.x, this->_background_color.y, this->_background_color.z, this->_background_color.w);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex2f(this->get_X(), this->get_Y());
	glVertex2f(this->get_X(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y());
	glEnd();
	
	glColor4f(this->_text_color.x, this->_text_color.y, this->_text_color.z, this->_text_color.w);
	for (int i = 0; i < this->_text_to_draw.size(); i++) {
		this->_text_renderer->simple_render_text(_text_to_draw[i], 
			this->get_X() + 0.1*this->get_width(), this->get_Y() + 0.9*this->get_height() - (i + 1)*13);
	}
}
