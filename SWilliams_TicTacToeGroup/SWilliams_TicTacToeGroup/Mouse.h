#pragma once
#include "Globals.h"			//Kai
class Mouse						//Kai
{								//Kai
public:							//Kai
	SDL_Texture * mouseTexture;	//Kai
	SDL_Rect cursor;			//Kai
	SDL_Rect tip;				//Kai
	void draw();				//Kai
	Mouse();					//Kai
	~Mouse();					//Kai
};								//Kai