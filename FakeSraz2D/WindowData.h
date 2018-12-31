#pragma once

#include <GL/glut.h>

class WindowData {
private:
	GLuint _window;
	GLuint _width, _height;
public:
	WindowData(GLuint width, GLuint height);
	GLuint get_window();
	GLuint get_width();
	GLuint get_height();
	void set_window(GLuint window);
	void set_width(GLuint width);
	void set_height(GLuint height);
};