// AMA_Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <algorithm> // for reverse, unique
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/algorithms/assign.hpp>
#include <boost/geometry/algorithms/distance.hpp>
#include <boost/geometry/algorithms/append.hpp>
#include <boost/geometry/arithmetic/normalize.hpp>
#include <boost/geometry/geometries/linestring.hpp>
#include <iterator>
#include  <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/geometry/arithmetic/arithmetic.hpp>
#include <boost/geometry/arithmetic/dot_product.hpp>
#include <boost/geometry/util/math.hpp>
#include <SDL2_gfxPrimitives.h>
#include <boost/numeric/ublas/storage.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


using namespace boost::geometry;
using namespace boost::numeric::ublas;
using namespace std;



//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gXOut = SDL_LoadBMP("hello_world.bmp");
	if (gXOut == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "03_event_driven_programming/x.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gXOut);
	gXOut = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}



int main(int argc, char* args[])
{
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

	int quit = 0;
	while (!quit)
	{
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = 1;
		}
		/*
		SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
		thickLineColor(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 20, 0xFF00FFFF);
		thickLineColor(renderer, 0, SCREEN_HEIGHT, SCREEN_WIDTH, 0, 20, 0xFF00FFFF);
		circleColor(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 33, 0xff00ff00);
		filledCircleColor(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 30, 0xff00ffcc);
		*/
		filledTrigonColor(renderer, m2(0,0), m2(0,1), m2(1, 0), m2(1, 1), m2(2, 0), m2(2, 1), 0xFF00FFFF);
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
