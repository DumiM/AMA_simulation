// AMA_Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <iostream>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/algorithms/distance.hpp>
#include <boost/geometry/algorithms/append.hpp>
#include <boost/geometry/geometries/linestring.hpp>
#include  <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/geometry/arithmetic/dot_product.hpp>
#include <SDL2_gfxPrimitives.h>
#include <SDL.h>
#include <stdio.h>
#include "game_world.h"
#include <ctime> //Needed to give the time seed to the rand() function

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


using namespace boost::geometry;
using namespace boost::numeric::ublas;
using namespace std;


game_world* world = game_world::get_instance();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;


//typedef model::d2::point_xy<double> point_2d;
//point_2d pos(200, 200);

boost::numeric::ublas::vector<double> pos(200, 200);

void update_mat(SDL_Renderer* renderer)
{
	boost::numeric::ublas::vector<double> v(1, 2);
	matrix<double> m2(3, 2);
	m2(0, 0) = pos[0] - 5;
	m2(0, 1) = pos[1] + 3;
	m2(1, 0) = pos[0] + 5;
	m2(1, 1) = pos[1] + 0.0;
	m2(2, 0) = pos[0] - 5;
	m2(2, 1) = pos[1] - 3;

	//filledTrigonColor(renderer, m2(0, 0), m2(0, 1), m2(1, 0), m2(1, 1), m2(2, 0), m2(2, 1), 0xFF00FFFF);
}

int main(int argc, char* args[])
{
	//**POINT, VECTOR AND MATRIX MANIPULATION**//
	/*
	//define point_2d, and linestring
	typedef model::d2::point_xy<double> point_2d;
	typedef model::linestring<point_2d> linestring_2d;
	typedef model::linestring<point_2d> linestring_2d;

	point_2d p1 (1,2);
	point_2d p2(4, 5);

	double pos = 300;
	matrix<double> m2(3, 2);
	m2(0, 0) = pos-5;
	m2(0, 1) = pos+3;
	m2(1, 0) = pos + 5;
	m2(1, 1) = pos+0.0;
	m2(2, 0) = pos -5;
	m2(2, 1) = pos -3;
	
	linestring_2d l1;
	append(l1, p1);
	append(l1, p2);

	std::cout << "Point 1 (x,y): " << p1.x() << "," << p1.y() << endl;
	std::cout << "Point 2 (x,y): " << p2.x() << "," << p2.y() << endl;	
	cout << "Distance b/w p1 and p2: " << distance(p1, p2) << endl;
	std::cout << "Length of line created by points p1 and p2: " << length(l1) << std::endl;
	std::cout << "Dot product of points p1 and p2: " << dot_product(p1, p2) << std::endl;
	*/


	world->max_x = SCREEN_WIDTH;
	world->max_y = SCREEN_HEIGHT;

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("SDL_Init Error: %s", SDL_GetError());
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("SDL2_gfx test", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
	if (window == NULL)
	{
		printf("SDL_CreateWindow Error: %s", SDL_GetError());
		SDL_Quit();
		return 2;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		SDL_DestroyWindow(window);
		printf("SDL_CreateRenderer Error: %s", SDL_GetError());
		SDL_Quit();
		return 3;
	}

	SDL_Event e;


	srand(time(NULL)); //srand is used to give a seed to the rand() function that gives us a random number, we give it the current time
	float time = SDL_GetTicks() / 1000; //Get the current time in milliseconds and divide by 1000 to convert it to seconds

	int quit = 0;
	while (!quit)
	{
		/*
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = 1;
		}*/
		/*
		SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
		thickLineColor(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 20, 0xFF00FFFF);
		thickLineColor(renderer, 0, SCREEN_HEIGHT, SCREEN_WIDTH, 0, 20, 0xFF00FFFF);
		circleColor(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 33, 0xff00ff00);
		filledCircleColor(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 30, 0xff00ffcc);
		*/

		float newTime = SDL_GetTicks() / 1; 
		float delta = newTime - time; 
		time = newTime; //Set the previous time to the current time


		//Handle events on queue
		if (SDL_PollEvent(&e))
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			//User presses a key
			else if (e.type == SDL_KEYDOWN)
			{

				SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, 0xFF);
				SDL_RenderClear(renderer);
				//Select surfaces based on key press
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					pos[1] -= 1;
					update_mat(renderer);
					break;

				case SDLK_DOWN:
					pos[1] += 1;
					update_mat(renderer);
					break;

				case SDLK_LEFT:
					pos[0] -= 1;
					update_mat(renderer);
					break;

				case SDLK_RIGHT:
					pos[0] = pos[0] +1;
					update_mat(renderer);
					break;

				case SDLK_a:
					world->pool.create();
					break;

				default:
					update_mat(renderer);
					break;
				}
			}
		}

		world->update(delta);
		world->render(renderer);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
