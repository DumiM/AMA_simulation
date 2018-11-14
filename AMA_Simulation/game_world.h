#pragma once
#include <SDL.h>
#include "agent_pool.h"

class game_world
{
private:
	static game_world* instance_;

	game_world();
public:
	int max_x;
	int max_y;

	agent_pool pool;

	static  game_world* get_instance();
	void update(float);
	void render(SDL_Renderer*);

};

