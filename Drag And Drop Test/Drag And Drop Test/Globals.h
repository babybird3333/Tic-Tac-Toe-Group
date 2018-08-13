#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <SDL_image.h>

using namespace std;

static int n = SDL_Init(SDL_INIT_EVERYTHING);
extern SDL_Window * win;
extern SDL_Renderer * ren;

class Globals
{
public:
	Globals();
	~Globals();
};

