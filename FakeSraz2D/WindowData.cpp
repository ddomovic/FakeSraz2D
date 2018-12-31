#include "stdafx.h"
#include "WindowData.h"

WindowData::WindowData(GLuint width, GLuint height) : _window(0), _width(width), _height(height) {
}

GLuint WindowData::get_window() {
	return this->_window;
}

GLuint WindowData::get_width() {
	return this->_width;
}

GLuint WindowData::get_height() {
	return this->_height;
}

void WindowData::set_window(GLuint window) {
	this->_window = window;
}

void WindowData::set_width(GLuint width) {
	this->_width = width;
}

void WindowData::set_height(GLuint height) {
	this->_height = height;
}
