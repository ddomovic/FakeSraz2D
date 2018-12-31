#pragma once
#include <vector>

#define DEFAULT_BASE_QUESTIONS 5
#define DEFAULT_PAWN_QUESTIONS 3

class Game {
private:
	std::vector<class GameObject*> _game_objects;
	std::vector<class GameState*> _all_states;
	class GameState *_current_state;
	class TextRenderer *_text_renderer;
	class WindowData *_window_data;
public:
	Game(class WindowData *window_data);
	~Game();
	class GameState* get_current_state();
	class GameState* get_game_state_by_name(const std::string &name);
	class TextRenderer* get_text_renderer();
	void set_state_by_name(const std::string &name);
	void set_state(class GameState *state);
	void start_game();
	void render_scene();
};