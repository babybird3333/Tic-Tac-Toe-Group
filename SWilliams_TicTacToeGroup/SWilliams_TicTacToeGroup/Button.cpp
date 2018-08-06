#include "Button.h"



Button::Button(int x, int y) : sRect{ x, y, 192, 64 }, dRect{ x, y, 192, 64 }
{
	static SDL_Texture * t = IMG_LoadTexture(ren, "Images/ButtonSheet.png");
	texture = t;
	selected = false;
}

void Button::setXY(int x, int y)
{
	dRect.x = x;
	dRect.y = y;
}

void Button::checkSelected()
{
	//if (SDL_HasIntersection(/*&*/(/*mouse stuff*/), &dRect))
	//{
	//selected = true;
	//sRect.x = 192;
	//}
	//else
	//{
	//selected = false;
	//sRect.x = 0;
	//}
}
Button::~Button()
{
}