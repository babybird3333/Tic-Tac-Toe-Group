#pragma once
#include "Globals.h"
#include "Mouse.h"


//Implemented
struct Piece
{
	SDL_Texture * texture;
	SDL_Rect rect = {0, 0, 300, 300};
	bool isSelected = false;
	bool isDragged = false;

	void draw();
	void drag(Mouse &);
};

class Game
{	//Implemented
public:
	Game();
	void update();
	Piece p;
	SDL_Texture * background;
	SDL_Texture * board;
	void draw();
	Mouse mouse;

	~Game();
};


//Implemented
class rects
{
public:
	SDL_Rect square;
	bool piecePresent = false;
};

