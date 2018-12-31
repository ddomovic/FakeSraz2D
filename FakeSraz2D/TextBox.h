#pragma once

#include <string>
#include <vector>
#include <glm/glm.hpp>

class TextBox : public GameObject {
private:
	std::string _text;
	class TextRenderer *_text_renderer;
	int _maximum_text_X;
	int _maximum_text_Y;
	std::vector<std::string> _text_to_draw;
	glm::vec4 _border_color;
	glm::vec4 _background_color;
	glm::vec4 _text_color;
	void adjust_text_drawing_parameters();
public:
	TextBox(class Game *game, float width, float height, float position_X, float position_Y, bool is_drawable, const std::string &text);
	const std::string& get_text();
	class TextRenderer* get_text_renderer();
	int get_maximum_text_X();
	int get_maximum_text_Y();
	glm::vec4 get_border_color();
	glm::vec4 get_background_color();
	glm::vec4 get_text_color();
	void set_text(const std::string &text);
	void set_text_renderer(class TextRenderer *text_renderer);
	void set_border_color(glm::vec4 color);
	void set_border_color(glm::vec3 color);
	void set_background_color(glm::vec4 color);
	void set_background_color(glm::vec3 color);
	void set_text_color(glm::vec4 color);
	void set_text_color(glm::vec3 color);
	void set_width(float width) override;
	void set_height(float height) override;
	void draw_object();
};