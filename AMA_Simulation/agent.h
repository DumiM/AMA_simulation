#pragma once
#include "agent_base.h"


class agent :
	public agent_base
{
public:
	agent();
	virtual ~agent();
	void update(float);
	void render();
};

