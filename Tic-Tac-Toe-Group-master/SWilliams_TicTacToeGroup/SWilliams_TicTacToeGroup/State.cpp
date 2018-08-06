#include "State.h"






#pragma region State
State::State()
{
}

void State::update()
{
}

void State::CheckEvents(SDL_Event e)
{
	
		switch (e.type) //Check the even type - SCW
		{
		case SDL_QUIT: //If quitting the application - SCW
			running = false; //Set the run state of the application to false = SCW
			return;
		case SDL_MOUSEBUTTONUP: //If the mouse button was released - SCW
			if (e.button.button == SDL_BUTTON_LEFT) //To do if the left button was clicked - SCW
			{
				//TODO ONCE BUTTONS HAVE BEEN CREATED - SCW
				//if (button[MENU]->selected)
				//{
				//	//Go to Menu State
				//	current = menu;
				//	updating = false;
				//	return;
				//}
				//else if (button[START]->selected)
				//{
				//	//Go to Game State
				//	current = game;
				//	updating = false;
				//	return;
				//}
				//else if (button[OPTIONS]->selected)
				//{
				//	//Go to Options State
				//	current = options;
				//	updating = false;
				//	return;
				//}
				//else if (button[HIGHSCORE]->selected)
				//{
				//	//Go to ScoreBoard State
				//	current = highscore;
				//	updating = false;
				//	return;
				//}
			}
		}
	
}


void State::draw()
{
	SDL_RenderCopy(ren, background, NULL, NULL); //Draw the canvas - SCW
}

State::~State()
{
}

#pragma endregion


#pragma region Menu
Menu::Menu()
{
	background = IMG_LoadTexture(ren, "Images/GameBackGround,png");//Load texture for the background - SCW
	//button[MENU] = new Button(0, 64);
	button[OPTIONS] = new Button(0, 128);
	button[START] = new Button(0, 192);
	button[SCORE] = new Button(0, 256);

	button[OPTIONS]->setXY(100, 100);
	button[START]->setXY(200, 200);
	button[SCORE]->setXY(300, 300);
}

void Menu::update()
{
	bool updating = true; //Set update state of the application to true - SCW
	SDL_Event e; //Keeps track of the event - SCW
	
	while (updating) //To do while update state is true - SCW
	{
		while (SDL_PollEvent(&e)) //To do while there's a pending SDL Event - SCW 
		{
			CheckEvents(e); //Call function to check SDL events - SCW
			if (e.type == SDL_QUIT)
			{
				updating = false;
			}
		}
	}

	//Get keyboard Input
	//Update Objects
	//Check Things (mouse location, collision, etc.)
	//Call draw function(s)
	draw();
	//Check for State Change
}

Menu::~Menu()
{
}

#pragma endregion


#pragma region Game
Game::Game()
{
	//background = IMG_LoadTexture(ren, "Images/BG_Game.png");//Load texture for the background - SCW
}
void Game::update()
{	
	bool updating = true; //Set update state of the application to true - SCW
	SDL_Event e; //Keeps track of the event - SCW

	while (updating) //To do while update state is true - SCW
	{
		while (SDL_PollEvent(&e)) //To do while there's a pending SDL Event - SCW 
		{
			CheckEvents(e); //Call function to check SDL events - SCW
			if (e.type == SDL_QUIT)
			{
				updating = false;
			}
		}
	}

	//Get keyboard Input
	//Update Objects
	//Check Things (mouse location, collision, etc.)
	//Call draw function(s)
	draw();
	//Check for State Change
}
Game::~Game()
{
}
#pragma endregion


#pragma region Options
Options::Options()
{
	//background = IMG_LoadTexture(ren, "Images/BG_Options.png");//Load texture for the background - SCW
}
void Options::update()
{
	bool updating = true; //Set update state of the application to true - SCW
	SDL_Event e; //Keeps track of the event - SCW

	while (updating) //To do while update state is true - SCW
	{
		while (SDL_PollEvent(&e)) //To do while there's a pending SDL Event - SCW 
		{
			CheckEvents(e); //Call function to check SDL events - SCW
			if (e.type == SDL_QUIT)
			{
				updating = false;
			}
		}
	}

	//Get keyboard Input
	//Update Objects
	//Check Things (mouse location, collision, etc.)
	//Call draw function(s)
	draw();
	//Check for State Change
}
Options::~Options()
{
}
#pragma endregion


#pragma region HighScore
HighScore::HighScore()
{
	//background = IMG_LoadTexture(ren, "Images/BG_HighScore.png");//Load texture for the background - SCW
}

void HighScore::update()
{
	bool updating = true; //Set update state of the application to true - SCW
	SDL_Event e; //Keeps track of the event - SCW

	while (updating) //To do while update state is true - SCW
	{
		while (SDL_PollEvent(&e)) //To do while there's a pending SDL Event - SCW 
		{
			CheckEvents(e); //Call function to check SDL events - SCW
			if (e.type == SDL_QUIT)
			{
				updating = false;
			}
		}
	}

	//Get keyboard Input
	//Update Objects
	//Check Things (mouse location, collision, etc.)
	//Call draw function(s)
	draw();
	//Check for State Change
}

HighScore::~HighScore()
{
}

#pragma endregion


/*VARIABLE SECTION*/ //-SCW

//State Pointers - SCW
State *menu = new Menu;
State *game = new Game;
State *options = new Options;
State *highscore = new HighScore;
State *current = menu; //Application starts off in the 'Menu' State - SCW
SDL_Window *window = SDL_CreateWindow("TIC-TAC-TOE: The Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN); //Initialize SDL window (set loactions, dimensions, and error flag) - SCW
SDL_Renderer *ren = SDL_CreateRenderer(window, - 1, SDL_RENDERER_ACCELERATED); //Initialize SDL Renderer - SCW
bool running = true; //Set running state to true - SCW
