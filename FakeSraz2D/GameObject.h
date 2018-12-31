#pragma once

#include <utility>

class GameObject {
private:
	float _width;
	float _height;
	float _position_X;
	float _position_Y;
	bool _is_drawable;
	class Game *_game;
public:
	GameObject();
	GameObject(class Game *game, float width, float height, bool is_drawable);
	GameObject(class Game *game, float width, float height, float position_X, float position_Y, bool is_drawable);
	virtual float get_width();
	virtual float get_height();
	virtual float get_Y();
	virtual float get_X();
	virtual std::pair<float, float> get_position();
	virtual bool is_drawable();
	virtual class Game* get_game();
	virtual void set_width(float width);
	virtual void set_height(float height);
	virtual void set_Y(float y);
	virtual void set_X(float x);
	virtual void set_position(float x, float y);
	virtual void set_position(std::pair<float, float> &position);
	virtual void set_drawable(bool is_drawable);
	virtual void draw_object() = 0;
};