#pragma once

#define DEFAULT_PAWN_SIZE_X_MULTIPLIER 0.2f
#define DEFAULT_PAWN_SIZE_Y_MULTIPLIER 0.7f
#define DEFAULT_PAWN_POSITION_X_MULTIPLIER 0.4f
#define DEFAULT_PAWN_POSITION_Y_MULTIPLIER 0.15f

class GameObjectPawn : public GameObject {
private:
	uint8_t _pawn_ID;
	uint8_t _equipment_level;
	class Team *_owner_team;
	class Tile *_current_tile;
public:
	static uint8_t _global_pawn_ID;
	GameObjectPawn(class Game *game, bool is_drawable, class Team *team, class Tile *tile);
	GameObjectPawn(class Game *game, float width, float height, bool is_drawable, class Team *team, class Tile *tile);
	void set_equipment_level(uint8_t equipment_level);
	void inc_equipment_level();
	void set_owner_team(class Team *team);
	void set_current_tile(class Tile *tile);
	uint8_t get_equipment_level();
	uint8_t get_pawn_ID();
	class Team* get_owner_team();
	class Tile* get_current_tile();
	void draw_object();
};