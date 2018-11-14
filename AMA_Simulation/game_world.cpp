#include "pch.h"
#include "game_world.h"
#include <iostream>
#include "agent.h"

game_world* game_world::instance_ = nullptr;
bool quit = false;
agent a;

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
	a.update(d);
}

void game_world::render()
{
	//std::cout << "RENDER!" << std::endl;
	a.render();
}

game_world::game_world()
{
	a = agent();
}
