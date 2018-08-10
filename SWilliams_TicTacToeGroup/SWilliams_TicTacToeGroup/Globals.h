#pragma once



/*INCLUDE SECTION*/ //- SCW
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

/*VARIABLE SECTION*/
class State;
extern double delta; //Delta time - SCW
extern bool running; //Keeps track of whether the application is running - SCW
//bool updating; //Keeps track of the update state of the application - SCW
static int n = SDL_Init(SDL_INIT_EVERYTHING); //Initialize SDL - SCW
static int k = TTF_Init(); //Initialize true type font - SCW
extern SDL_Window* window; //Canvas - SCW
extern SDL_Renderer* ren; //Renderer - SCW
extern State* menu; //Menu State - SCW
extern State* game; //Game State - SCW
extern State* options; //Options State - SCW
extern State* highscore; //HighScore State - SCW
extern State* current; //Keeps track of the current state that is running - SCW
//typedef const Uint8 KeyType; //Key Input Save Type - SCWb (may not need)

