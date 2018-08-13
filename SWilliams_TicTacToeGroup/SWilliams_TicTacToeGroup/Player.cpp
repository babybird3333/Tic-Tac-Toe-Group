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

//get the player name(3 characters) and call this to add 1 to their score
void Player::saveScore(string playerName)
{
    //open input file stream
    ifstream input = ifstream("score.bin", ios::binary | ios::in);

    //read the total numbe of score entries
    char num = 0;
    input.read((char*)num, sizeof(char));

    //arrays to score all of the read data
    string names[100];
    char scores[100];

    //for (the number of score entries) and read name/score pairs into the data arrays
    for (int i = 0; i < num; i++)
    {
        char name[3];
        input.read((char*)name, sizeof(name));

        char score = 0;
        input.read((char*)score, sizeof(score));

        names[i] = string(name);
        scores[i] = score;
    }

    //output file stream
    ofstream output = ofstream("score.bin", ios::binary | ios::out);

    char i = 0;
    bool exists = false;

    //loop through all names, if the given player name already exists, add 1 to it's score
    for (auto name : names)
    {
        if (name == playerName)
        {
            exists = true;
            scores[i]++;
            break;
        }
        i++;
    }
    
    //if that player doesnt exist, add it to the end of the data arrays with a score of 1
    if (!exists)
    {
        i++;
        names[i] = playerName;
        scores[i] = 1;
    }

    //write the total number of scores
    output.write(&i, sizeof(i));
    i = 0;

    //loop through all the scores and write the name/score pairs
    for (auto name : names)
    {
        output.write(names[i].c_str(), sizeof(names[i]));
        output.write(&scores[i], sizeof(scores[i]));
        i++;
    }
}


void Player::ChangeTexture(int texture_type)
{
	if (isPlayerX)
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
	else
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



void Piece::drag(Mouse& mouse)							//Kai
{														//Kai
	if (isDragged)										//Kai
	{													//Kai
		SDL_GetMouseState(&mouse.tip.x, &mouse.tip.y);	//Kai
		rect.x = mouse.tip.x;							//Kai
		rect.y = mouse.tip.y;							//Kai
	}													//Kai
}														//Kai
void Piece::draw()										//Kai
{														//Kai
	SDL_RenderDrawRect(ren, &rect);						//Kai
	SDL_RenderCopy(ren, texture, NULL, &rect);			//Kai
}														//Kai

