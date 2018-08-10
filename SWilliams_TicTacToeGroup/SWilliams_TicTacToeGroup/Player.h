#pragma once
#include "Globals.h"
using namespace std;

class Player
{
public:
	SDL_Texture * textPlayer;
    bool isPlayerX;
    unsigned int score;
    Player(bool);
    ~Player();

    void saveScore();
    void loadScore();
	void ChangeTexture(int, string); //Changes the texture of the player (either X or O) according to the user's selection in the optrions state - SCW 
};

