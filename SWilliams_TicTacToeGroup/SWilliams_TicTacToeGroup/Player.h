#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Player
{
public:
    bool isPlayerX;
    unsigned int score;

    Player(bool);
    ~Player();

    void saveScore();
    void loadScore();
};


