#pragma once
#include "agent.h"

class agent_pool
{
public:
	agent_pool();
	virtual ~agent_pool();
	static const int POOL_SIZE = 30;
	agent agents[POOL_SIZE];
	void render(SDL_Renderer*);
	void update(float);
	void create();
};


inline agent_pool::agent_pool()
{
	for (int i = 0; i < POOL_SIZE; i++)
	{
		agents[i] = agent();
	}
}

inline agent_pool::~agent_pool()
{
}

inline void agent_pool::render(SDL_Renderer* renderer)
{
	for (int i = 0; i < POOL_SIZE; i++)
	{
		agents[i].render(renderer);
	}
}

inline void agent_pool::update(float delta)
{
	for (int i = 0; i < POOL_SIZE; i++)
	{
		agents[i].update(delta);
	}
}

inline void agent_pool::create()
{
	for (int i = 0; i < POOL_SIZE; i++)
	{
		if (!agents[i].is_active)
		{
			//the init method sets the state to active
			agents[i].init();
			return;
		}
	}
}
