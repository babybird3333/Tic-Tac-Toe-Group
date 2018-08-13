#pragma once
#include "Globals.h"
#include "Mouse.h"
using namespace std;



struct Piece							//Kai
{										//Kai
	SDL_Texture * texture;				//Kai
	SDL_Rect rect = { 0, 0, 300, 300 };	//Kai
	bool isSelected = false;			//Kai
	bool isDragged = false;				//Kai
	bool isX = true;					//Kai
	void draw();						//Kai
	void drag(Mouse &);					//Kai
};										//Kai





class Player
{
public:
	SDL_Texture * textPlayer;
    bool isPlayerX;
    unsigned int score;
    Player(bool);
    ~Player();

    void saveScore(string);
	void ChangeTexture(int); //Changes the texture of the player (either X or O) according to the user's selection in the optrions state - SCW 
};


