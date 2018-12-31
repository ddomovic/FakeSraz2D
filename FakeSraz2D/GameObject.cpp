#include "stdafx.h"
#include "Game.h"
#include "GameObject.h"

GameObject::GameObject() : _width(10), _height(10), _position_X(0), _position_Y(0), _is_drawable(false) {
}

GameObject::GameObject(Game *game, float width, float height, bool is_drawable) : _game(game), _width(width), 
	_height(height), _position_X(0), _position_Y(0), _is_drawable(is_drawable) {
}

GameObject::GameObject(Game *game, float width, float height, float position_X, float position_Y, bool is_drawable) : 
	_game(game), _width(width), _height(height), _position_X(position_X), _position_Y(position_Y), 
	_is_drawable(is_drawable) {
}

float GameObject::get_width() {
	return this->_width;
}

float GameObject::get_height() {
	return this->_height;
}

float GameObject::get_Y() {
	return this->_position_Y;
}

float GameObject::get_X() {
	return this->_position_X;
}

std::pair<float, float> GameObject::get_position() {
	return std::make_pair(this->_position_X, this->_position_Y);
}

bool GameObject::is_drawable() {
	return this->_is_drawable;
}

Game* GameObject::get_game() {
	return this->_game;
}

void GameObject::set_width(float width) {
	this->_width = width;
}

void GameObject::set_height(float height) {
	this->_height = height;
}

void GameObject::set_Y(float y) {
	this->_position_Y = y;
}

void GameObject::set_X(float x) {
	this->_position_X = x;
}

void GameObject::set_position(float x, float y) {
	this->_position_X = x;
	this->_position_Y = y;
}

void GameObject::set_position(std::pair<float, float> &position) {
	this->_position_X = position.first;
	this->_position_Y = position.second;
}

void GameObject::set_drawable(bool is_drawable) {
	this->_is_drawable = is_drawable;
}
