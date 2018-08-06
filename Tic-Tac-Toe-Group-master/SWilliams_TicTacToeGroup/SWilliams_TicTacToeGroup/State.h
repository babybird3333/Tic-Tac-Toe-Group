#pragma once
#include "Button.h"


#pragma region Includes and Usings
#include "Globals.h"
using namespace std;
#pragma endregion







#pragma region Class Declarations
class State //State Class - SCW
{
public:
	SDL_Texture * background;
	State();
	virtual void update();
	void CheckEvents(SDL_Event);
	void draw();
	virtual ~State();
};

class Menu : public State { //Menu Class (derived from State) - SCW

public:
	enum Buttons { MENU, OPTIONS, START, SCORE};
	Button * button[5];
	Menu();
	virtual void update();
	virtual  ~Menu();
	
};

class Game : public State { //Game Class (derived from State) - SCW

public:
	Game();
	virtual void update();
	virtual  ~Game();

};

class Options : public State { //Options Class (derived from State) - SCW

public:
	Options();
	virtual void update();
	virtual  ~Options();

};


class HighScore : public State { //HighScore Class (derived from State) - SCW
 
public:
	HighScore();
	virtual void update();
	virtual  ~HighScore();

};
#pragma endregion