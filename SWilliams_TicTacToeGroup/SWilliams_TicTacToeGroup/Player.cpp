#include "Player.h"

Player::Player(bool isPlayerX) : isPlayerX{ isPlayerX }
{
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

