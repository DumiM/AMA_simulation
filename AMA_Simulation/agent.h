#pragma once
#include "agent_base.h"
#include <SDL.h>


class agent :
	public agent_base
{
public:
	agent();
	virtual ~agent();
	void update(float);
	void render(SDL_Renderer*);
	void update_pos(float);
};

