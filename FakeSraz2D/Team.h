#pragma once

#include <glm/glm.hpp>
#include <vector>

class Team {
private:
	uint8_t _teamID;
	glm::vec4 _team_color;
	std::vector<class GameObjectPawn*> _pawns;
	class Tile *_base_tile;
public:
	Team(uint8_t teamID, glm::vec4 team_color);
	Team(uint8_t teamID, glm::vec3 team_color);
	uint8_t get_teamID();
	glm::vec4 get_team_color();
	std::vector<class GameObjectPawn*>& get_pawns();
	class GameObjectPawn* get_pawn_by_index(int index);
	class Tile* get_base_tile();
	void set_teamID(uint8_t teamID);
	void set_team_color(glm::vec4 team_color);
	void set_team_color(glm::vec3 team_color);
	void set_pawns(std::vector<class GameObjectPawn*> &pawns);
	void set_base_tile(class Tile *base_tile);
	void add_pawn(class GameObjectPawn *new_pawn);
};