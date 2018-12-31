#pragma once

#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H


class TextRenderer {
private:
	FT_Library _ft;
	FT_Face _face;
	FT_GlyphSlot _g;
	uint8_t _font_size;
public:
	TextRenderer();
	bool init_text_renderer();
	bool set_font(const std::string &font_name);
	void set_font_size(uint8_t size);
	void prepare_rendering();
	void render_text(const std::string &text, float position_X, float position_Y, float scale_X, float scale_Y);
	// render_text() doesn't work, use this one instead
	// does not require initialization
	void simple_render_text(const std::string &text, float position_X, float position_Y);
};