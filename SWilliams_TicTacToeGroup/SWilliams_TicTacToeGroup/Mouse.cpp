#include "Mouse.h"



Mouse::Mouse()				//Kai
{							//Kai
	mouseTexture = IMG_LoadTexture(ren, "Images/CUR_Hand.png");//Kai
	cursor = { 0,0,50,50 };	//Kai
	tip = { 0,0,1,1 };		//Kai
}							//Kai



void Mouse::draw()
{
	//Set the mouse's tip coordinates to the mouse's cursor coordinates (in order to set the selected state) - SCW
	tip.x = cursor.x;
	tip.y = cursor.y;

	SDL_RenderCopy(ren, mouseTexture, NULL, &cursor);

}

Mouse::~Mouse()				//Kai
{							//Kai
}							//Kai