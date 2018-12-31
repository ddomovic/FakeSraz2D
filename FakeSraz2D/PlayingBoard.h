#pragma once

#include <vector>

#define BASE_SQUARES_SIZE 7

class PlayingBoard : public GameObject {
private:
	uint8_t _tile_number_X;
	uint8_t _tile_number_Y;
	std::vector<class Tile*> _tiles;
public:
	PlayingBoard(class Game *game, float width, float height, float position_X, float position_Y, uint8_t tile_number_X, uint8_t tile_number_Y);
	class Tile* get_tile_at(uint8_t index_X, uint8_t index_Y);
	std::vector<class Tile*> get_tiles();
	uint8_t get_tile_number_X();
	uint8_t get_tile_number_Y();
	void set_tile_at(class Tile *new_tile, uint8_t index_X, uint8_t index_Y);
	void draw_object();
};