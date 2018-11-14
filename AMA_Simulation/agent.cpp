#include "pch.h"
#include "agent.h"
#include <stdlib.h> 
#include <iostream>
#include <boost/geometry/algorithms/assign.hpp>
#include <SDL2_gfxPrimitives.h>
#include <boost/numeric/ublas/io.hpp>
#include "game_world.h"


using namespace std;
using namespace boost::geometry;
using namespace boost::numeric::ublas;

agent::agent()
{
	assign_values(position, (rand() % 300 + 1), (rand() % 300 + 1));
	model = new agent_model();
	is_active = false;
}


agent::~agent()
{
}

void wrap_around()
{
}

void agent::update_pos(float d)
{

	boost::numeric::ublas::vector<double> pos(position.x(), position.y());
	model->shape_matrix(0, 0) = pos[0] - 5;
	model->shape_matrix(0, 1) = pos[1] + 3;
	model->shape_matrix(1, 0) = pos[0] + 5;
	model->shape_matrix(1, 1) = pos[1] + 0.0;
	model->shape_matrix(2, 0) = pos[0] - 5;
	model->shape_matrix(2, 1) = pos[1] - 3;
}

void agent::update(float delta)
{
	if (!is_active) return;
	cout << "UPDATE!: " << delta << endl;
	update_pos(delta);
}

void agent::render(SDL_Renderer *renderer)
{
	if (!is_active) return;
	cout << "RENDER!" << model->shape_matrix;
	filledTrigonColor(renderer, model->shape_matrix(0, 0), model->shape_matrix(0, 1), model->shape_matrix(1, 0), model->shape_matrix(1, 1), model->shape_matrix(2, 0), model->shape_matrix(2, 1), 0xFF00FFFF);
}