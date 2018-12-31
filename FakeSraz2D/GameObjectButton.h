#pragma once

#include <string>

class GameObjectButton : public GameObject {
private:
	std::string _text;
	class TextRenderer *_text_renderer;
	int _maximum_text_X;
public:
	GameObjectButton(class Game *game, float width, float height, float position_X, float position_Y, bool is_drawable, const std::string &text);
	void set_text(const std::string &text);
	void set_width(float width) override;
	const std::string& get_text();
	void on_pressed();
	void draw_object();
};