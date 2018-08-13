#pragma once


#pragma region Includes and Usings
#include "Globals.h"
#include "Button.h"
#include "Mouse.h"
#include "Player.h"
using namespace std;
#pragma endregion







#pragma region Class Declarations
class State //State Class - SCW
{
public:
	SDL_Texture * background;
	Mouse *mouse;
	State();
	virtual void update();
	void draw();
	virtual ~State();
};

class Menu : public State { //Menu Class (derived from State) - SCW

public:
	//Insert Button Information - Kai
	enum Buttons {MENU, OPTIONS, START, SCORE };
	Button * button[4];	
	Menu();
	virtual void update();
	virtual  ~Menu();
	
};


struct SnapRects				//Kai
{								//Kai
public:							//Kai
    Piece* piece;
    SDL_Rect square;			//Kai
};

class Game : public State { //Game Class (derived from State) - SCW

public:
    Player* playerX;
    Player* playerO;
    Player* currentPlayer;
    SnapRects sqr[9];        //Kai
	Button * menubutton; //Insert Button Information - Kai
	SDL_Texture * board;	//Kai
	Game();
	virtual void update();
	virtual  ~Game();

};


class Options : public State { //Options Class (derived from State) - SCW

public:
	//Insert Button Information - Kai
	Button * menubutton;
	Options();
	virtual void update();
	virtual  ~Options();

};


class HighScore : public State { //HighScore Class (derived from State) - SCW
 
public:
	//Insert Button Information - Kai
	Button * menubutton;
    SDL_Texture* texture;
    SDL_Surface* surface;
    SDL_Rect rect;
    TTF_Font* font;
    string players[10];

	HighScore();
	virtual void update();
	virtual  ~HighScore();
};



class WinLose : public State { //WinLose Class (derived from State) - SCW

public:
	//Insert Button Information - Kai
	Button * menubutton;
	WinLose();
	virtual void update();
	virtual  ~WinLose();

};


#pragma endregion