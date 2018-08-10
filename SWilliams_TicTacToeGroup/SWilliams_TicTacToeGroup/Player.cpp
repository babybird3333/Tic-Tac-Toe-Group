#include "Player.h"

Player::Player(bool isPlayerX) : isPlayerX{ isPlayerX }
{
	
	if (isPlayerX) //To do if the player is X - SCW
	{
		//Load the "default" texture for player X - SCW
		textPlayer = IMG_LoadTexture(ren, "Images/BlueX.png");
	}
	else if (!isPlayerX) //To do if the player is Y - SCW
	{
		//Load the "default" texture for player Y - SCW
		textPlayer = IMG_LoadTexture(ren, "Images/BlueY.png");
	}


}

Player::~Player()
{
}

void Player::saveScore()
{

    ofstream output = ofstream("score.bin", ios::binary | ios::out);

    if (isPlayerX)
        output.write((char*)score, sizeof(score));
    else
    {
        output.seekp(sizeof(score));
        output.write((char*)score, sizeof(score));
    }

    output.close();
}

void Player::loadScore()
{
    ifstream input = ifstream("score.bin", ios::binary | ios::in);

    if (isPlayerX)
        input.read((char*)score, sizeof(score));
    else
    {
        input.seekg(sizeof(score));
        input.read((char*)score, sizeof(score));
    }

    input.close();
}

void Player::ChangeTexture(int texture_type, string player_type)
{
	if (player_type == "X")
	{
		//Update the texture according to the user's selection 
		switch (texture_type)
		{
		case 1:
			//Load the "blue" texture for player X - SCW
			textPlayer = IMG_LoadTexture(ren, "Images/BlueX.png");
		case 2:
			//Load the "green" texture for player X - SCW
			textPlayer = IMG_LoadTexture(ren, "Images/GreenX.png");
		case 3:
			//Load the "red" texture for player X - SCW
			textPlayer = IMG_LoadTexture(ren, "Images/RedX.png");
		default:
			//Load the "default" texture for player X - SCW
			textPlayer = IMG_LoadTexture(ren, "Images/BlueX.png");
		}
	}
	else if (player_type == "O")
	{
		//Update the texture according to the user's selection 
		switch (texture_type)
		{
		case 1:
			//Load the "blue" texture for player O - SCW
			textPlayer = IMG_LoadTexture(ren, "Images/BlueO.png");
		case 2:
			//Load the "green" texture for player O - SCW
			textPlayer = IMG_LoadTexture(ren, "Images/GreenO.png");
		case 3:
			//Load the "red" texture for player O - SCW
			textPlayer = IMG_LoadTexture(ren, "Images/RedO.png");
		default:
			//Load the "default" texture for player O - SCW
			textPlayer = IMG_LoadTexture(ren, "Images/BlueO.png");
		}
	}


}

