#include "stdafx.h"
#include <iostream>
#include <inttypes.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "TextRenderer.h"

TextRenderer::TextRenderer() {
}

bool TextRenderer::init_text_renderer() {
	/*if (FT_Init_FreeType(&_ft)) {
		std::cerr << "Could not init FreeType lib!" << std::endl;
		return false;
	}*/
	return true;
}

bool TextRenderer::set_font(const std::string &font_name) {
	/*if (FT_New_Face(this->_ft, font_name.c_str(), 0, &_face)) {
		std::cerr << "Could not open font: " << font_name << std::endl;
		return false;
	}*/
	return true;
}

void TextRenderer::set_font_size(uint8_t size) {
	/*this->_font_size = size;
	FT_Set_Pixel_Sizes(this->_face, 0, size);*/
}

void TextRenderer::prepare_rendering() {
	
	/*this->_g = this->_face->glyph;

	GLuint tex;
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glUniform1i(0, 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);*/
}

void TextRenderer::render_text(const std::string &text, float position_X, float position_Y, float scale_X, float scale_Y) {
	/*const char *p;
	const char *temp = text.c_str();

	for (p = temp; *p; p++) {
		if (FT_Load_Char(this->_face, *p, FT_LOAD_RENDER))
			continue;

		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			this->_g->bitmap.width,
			this->_g->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			this->_g->bitmap.buffer
		);

		float x2 = position_X + this->_g->bitmap_left * scale_X;
		float y2 = -position_Y - this->_g->bitmap_top * scale_Y;
		float w = this->_g->bitmap.width * scale_X;
		float h = this->_g->bitmap.rows * scale_Y;

		GLfloat box[4][4] = {
			{x2,     -y2    , 0, 0},
			{x2 + w, -y2    , 1, 0},
			{x2,     -y2 - h, 0, 1},
			{x2 + w, -y2 - h, 1, 1},
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof box, box, GL_DYNAMIC_DRAW);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		position_X += (this->_g->advance.x / 64) * scale_X;
		position_Y += (this->_g->advance.y / 64) * scale_Y;
	}*/
}

void TextRenderer::simple_render_text(const std::string &text, float position_X, float position_Y) {
	glRasterPos2f(position_X, position_Y);
	int len = (int)text.length();
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	}
}
