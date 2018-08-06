#pragma once
#include "Globals.h"

/*ALL OF BUTTON CLASS (.cpp, .h) = KAI*/
class Button
{
public:
	SDL_Texture * texture;	//Kai
	SDL_Rect sRect, dRect;	//Kai
	bool selected;	//Kai

	Button();	//Kai
	Button(int x, int y);	//Kai
	void setXY(int x, int y);	//Kai
	void checkSelected();
	void draw();
	~Button();
};