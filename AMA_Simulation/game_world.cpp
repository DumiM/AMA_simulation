#include "pch.h"
#include "game_world.h"
#include <iostream>
#include "agent_pool.h"
#include <SDL.h>

game_world* game_world::instance_ = nullptr;
bool quit = false;




game_world* game_world::get_instance()
{
	if (instance_ == nullptr)
	{
		instance_ = new game_world();
	}

	return instance_;
}

void game_world::update(float d)
{
	//std::cout << "UPDATE!" << std::endl;
	pool.update(d);
}

void game_world::render(SDL_Renderer* renderer)
{
	//std::cout << "RENDER!" << std::endl;
	pool.render(renderer);
}

game_world::game_world()
{
	pool = agent_pool();
	//pool.create();
}
