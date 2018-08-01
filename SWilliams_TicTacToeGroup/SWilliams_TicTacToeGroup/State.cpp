#include "State.h"






#pragma region State
State::State()
{
}

void State::update()
{
}


void State::draw()
{
	SDL_RenderCopy(ren, background, NULL, NULL); //Draw the canvas - SCW
}

State::~State()
{
}

#pragma endregion


#pragma region Menu
Menu::Menu()
{
}

void Menu::update()
{




}

Menu::~Menu()
{
}

#pragma endregion


#pragma region Game
Game::Game()
{
}
void Game::update()
{
}
Game::~Game()
{
}
#pragma endregion


#pragma region Options
Options::Options()
{
}
void Options::update()
{
}
Options::~Options()
{
}
#pragma endregion


#pragma region HighScore
HighScore::HighScore()
{
}

void HighScore::update()
{
}

HighScore::~HighScore()
{
}

#pragma endregion


/*VARIABLE SECTION*/ //-SCW
//State Pointers
State *menu = new Menu;
State *game = new Game;
State *options = new Options;
State *highscore = new HighScore;
State*current = menu; //Application starts off in the 'Menu' State
