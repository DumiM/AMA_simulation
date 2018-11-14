#include "pch.h"
#include "agent.h"
#include <iostream>
#include <boost/geometry/algorithms/assign.hpp>


using namespace std;


agent::agent()
{
	assign_values(position, 200,200);
	model = new agent_model();
}


agent::~agent()
{
}

void agent::update(float delta)
{
	cout << "UPDATE!: " << delta << endl;
}

void agent::render()
{
	cout << "RENDER!";
}
