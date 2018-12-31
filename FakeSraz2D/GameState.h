#pragma once
#include <vector>

class GameState {
private:
	const std::string _state_name;
	std::vector<class GameObject*> _objects_to_draw;
	class Game *_game;
public:
	GameState(class Game *game, const std::string &state_name);
	virtual const std::string& get_state_name();
	virtual const std::vector<class GameObject*>& get_objects();
	virtual class GameObject* get_object_by_index(int index);
	virtual class Game* get_game();
	virtual void add_object(class GameObject *object);
	virtual void remove_object(class GameObject *object);
	virtual void begin_state() = 0;
	virtual void reset_state() = 0;
	virtual void draw_objects();
	virtual void keyboard_functions(unsigned char key, int x, int y) = 0;
	virtual void mouse_functions(int button, int state, int x, int y) = 0;
};