#pragma once

#include <glm/glm.hpp>

class Tile {
private:
	float _position_X;
	float _position_Y;
	float _width;
	float _height;
	uint8_t _index_X;
	uint8_t _index_Y;
	glm::vec4 _tile_color;
	class Team* _owner_team;
	class GameObjectPawn *_current_pawn;
	class PlayingBoard* _owner_board;
public:
	Tile(float width, float height, float position_X, float position_Y, uint8_t index_X, uint8_t index_Y, class PlayingBoard* owner_board);
	~Tile();
	float get_position_X();
	float get_position_Y();
	std::pair<float, float> get_position();
	float get_width();
	float get_height();
	uint8_t get_index_X();
	uint8_t get_index_Y();
	glm::vec4& get_tile_color();
	class Team* get_owner_team();
	class GameObjectPawn* get_current_pawn();
	class PlayingBoard* get_owner_board();
	void set_position_X(float position_X);
	void set_position_Y(float position_Y);
	void set_position(float position_X, float position_Y);
	void set_width(float width);
	void set_height(float height);
	void set_index_X(uint8_t index);
	void set_index_Y(uint8_t index);
	void set_tile_color(const glm::vec3 &tile_color);
	void set_tile_color(const glm::vec4 &tile_color);
	void set_default_tile_color();
	void set_owner_team(class Team *new_owner_team);
	void set_current_pawn(class GameObjectPawn *pawn);
	void set_owner_board(class PlayingBoard *owner_board);
	virtual void action(class GameObjectPawn *attacking_pawn);
};