#include "stdafx.h"
#include <inttypes.h>
#include <GL/glut.h>
#include "Game.h"
#include "GameObject.h"
#include "Tile.h"
#include "Team.h"
#include "PlayingBoard.h"

PlayingBoard::PlayingBoard(Game *game, float width, float height, float position_X, float position_Y, uint8_t tile_number_X, uint8_t tile_number_Y) : 
	GameObject(game, width, height, position_X, position_Y, true), _tile_number_X(tile_number_X), _tile_number_Y(tile_number_Y) {
	
	if (_tile_number_X < 4) {
		_tile_number_X = 4;
	}
	if (_tile_number_Y < 4) {
		_tile_number_Y = 4;
	}

	float size_x = width / tile_number_X;
	float size_y = height / tile_number_Y;
	for (int i = 0; i < _tile_number_Y; i++) {
		for (int j = 0; j < _tile_number_X; j++) {
			this->_tiles.push_back(new Tile(size_x, size_y, this->get_X() + size_x * j, this->get_Y() + size_y * i, j, i, this));
		}
	}
}

Tile* PlayingBoard::get_tile_at(uint8_t index_X, uint8_t index_Y) {
	return this->_tiles.at(this->_tile_number_X * index_Y + index_X);
}

std::vector<Tile*> PlayingBoard::get_tiles() {
	return this->_tiles;
}

uint8_t PlayingBoard::get_tile_number_X() {
	return this->_tile_number_X;
}

uint8_t PlayingBoard::get_tile_number_Y() {
	return this->_tile_number_Y;
}

void PlayingBoard::set_tile_at(Tile * new_tile, uint8_t index_X, uint8_t index_Y) {
	this->_tiles.at(this->_tile_number_X * index_Y + index_X) = new_tile;
}

void PlayingBoard::draw_object() {
	glColor3f(0.721f, 0.745f, 0.776f);
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glVertex2f(this->get_X(), this->get_Y());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X() + this->get_width(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X(), this->get_Y() + this->get_height());
	glVertex2f(this->get_X(), this->get_Y());
	glEnd();
	glLineWidth(1.0f);
	for (std::vector<Tile*>::iterator it = this->_tiles.begin(); it != this->_tiles.end(); ++it) {
		glm::vec4 c = (*it)->get_tile_color();
		glColor4f(c.x, c.y, c.z, c.w);
		glBegin(GL_QUADS);
		glVertex2f((*it)->get_position_X(), (*it)->get_position_Y());
		glVertex2f((*it)->get_position_X(), (*it)->get_position_Y() + (*it)->get_height());
		glVertex2f((*it)->get_position_X() + (*it)->get_height(), (*it)->get_position_Y() + (*it)->get_height());
		glVertex2f((*it)->get_position_X() + (*it)->get_height(), (*it)->get_position_Y());
		glEnd();
		
		glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_QUADS);
		glVertex2f((*it)->get_position_X(), (*it)->get_position_Y());
		glVertex2f((*it)->get_position_X(), (*it)->get_position_Y() + (*it)->get_height());
		glVertex2f((*it)->get_position_X() + (*it)->get_height(), (*it)->get_position_Y() + (*it)->get_height());
		glVertex2f((*it)->get_position_X() + (*it)->get_height(), (*it)->get_position_Y());
		glEnd();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		if ((*it)->get_owner_team()) {
			c = (*it)->get_owner_team()->get_team_color();
			glColor4f(c.x, c.y, c.z, c.w);
			glBegin(GL_QUADS);
			glVertex2f((*it)->get_position_X(), (*it)->get_position_Y());
			glVertex2f((*it)->get_position_X(), (*it)->get_position_Y() + BASE_SQUARES_SIZE);
			glVertex2f((*it)->get_position_X() + BASE_SQUARES_SIZE, (*it)->get_position_Y() + BASE_SQUARES_SIZE);
			glVertex2f((*it)->get_position_X() + BASE_SQUARES_SIZE, (*it)->get_position_Y());

			glVertex2f((*it)->get_position_X() + (*it)->get_width(), (*it)->get_position_Y());
			glVertex2f((*it)->get_position_X() + (*it)->get_width(), (*it)->get_position_Y() + BASE_SQUARES_SIZE);
			glVertex2f((*it)->get_position_X() + (*it)->get_width() - BASE_SQUARES_SIZE, (*it)->get_position_Y() + BASE_SQUARES_SIZE);
			glVertex2f((*it)->get_position_X() + (*it)->get_width() - BASE_SQUARES_SIZE, (*it)->get_position_Y());

			glVertex2f((*it)->get_position_X() + (*it)->get_width(), (*it)->get_position_Y() + (*it)->get_height());
			glVertex2f((*it)->get_position_X() + (*it)->get_width(), (*it)->get_position_Y() + (*it)->get_height() - BASE_SQUARES_SIZE);
			glVertex2f((*it)->get_position_X() + (*it)->get_width() - BASE_SQUARES_SIZE, (*it)->get_position_Y() + (*it)->get_height() - BASE_SQUARES_SIZE);
			glVertex2f((*it)->get_position_X() + (*it)->get_width() - BASE_SQUARES_SIZE, (*it)->get_position_Y() + (*it)->get_height());

			glVertex2f((*it)->get_position_X(), (*it)->get_position_Y() + (*it)->get_height());
			glVertex2f((*it)->get_position_X(), (*it)->get_position_Y() + (*it)->get_height() - BASE_SQUARES_SIZE);
			glVertex2f((*it)->get_position_X() + BASE_SQUARES_SIZE, (*it)->get_position_Y() + (*it)->get_height() - BASE_SQUARES_SIZE);
			glVertex2f((*it)->get_position_X() + BASE_SQUARES_SIZE, (*it)->get_position_Y() + (*it)->get_height());
			glEnd();
		}
	}
}