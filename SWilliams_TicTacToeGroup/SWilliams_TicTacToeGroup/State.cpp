#include "State.h"






#pragma region State
State::State()
{
}

void State::update()
{
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
	background = IMG_LoadTexture(ren, "Images/GameBackGround.png");//Load texture for the background - SCW
	cout << SDL_GetError() << endl; //Show SDL Errors - SCW




	/*Create Buttons and set there X,Y Coordinates - Kai*/
	button[MENU] = new Button(0, 0);
	button[OPTIONS] = new Button(0, 64);
	button[START] = new Button(0, 128);
	button[SCORE] = new Button(0, 192);
	

	button[START]->setXY(500, 340);
	button[OPTIONS]->setXY(500, 410);
	button[SCORE]->setXY(500, 480);

}

void Menu::update()
{
	bool updating = true; //Set update state of the application to true - SCW
	SDL_Event e; //Keeps track of the event - SCW
	
	while (updating) //To do while update state is true - SCW
	{
		while (SDL_PollEvent(&e)) //To do while there's a pending SDL Event - SCW 
		{
			switch (e.type) //Check the even type - SCW
			{
			case SDL_QUIT: //If quitting the application - SCW
				running = false; //Set the run state of the application to false = SCW
				return;
			case SDL_MOUSEBUTTONUP: //If the mouse button was released - SCW
				if (e.button.button == SDL_BUTTON_LEFT) //To do if the left button was clicked - SCW
				{
					/*CHANGE STATE ACCORDING TO BUTTON SELECTION -SCW*/
					if (button[MENU]->selected)
					{
						//Go to Menu State
						current = menu;
						updating = false;
						return;
					}
					else if (button[START]->selected)
					{
						//Go to Game State
						current = game;
						updating = false;
						return;
					}
					else if (button[OPTIONS]->selected)
					{
						//Go to Options State
						current = options;
						updating = false;
						return;
					}
					else if (button[SCORE]->selected)
					{
						//Go to ScoreBoard State
						current = highscore;
						updating = false;
						return;
					}
				}
			}

			if (e.type == SDL_QUIT)
			{
				updating = false;
			}
		}

		//Get keyboard Input
		//Update Objects
		//Check Things (mouse location, collision, etc.)
		//Call draw function(s)
		draw(); //Draw the canvas background
		int i = 0;
		for (auto n : button)
		{

			if (i == 0)
			{
				i++;
				continue;

			}
			n->draw(); //Draw the buttons (except 'MENU')
			i++;

		}
		SDL_RenderPresent(ren); // show the screen

		//Check for State Change

	}

	
}

Menu::~Menu()
{
}

#pragma endregion


#pragma region Game
Game::Game()
{
	background = IMG_LoadTexture(ren, "Images/GameBackGround.png");//Load texture for the background - SCW
	cout << SDL_GetError() << endl; //Show SDL Errors - SCW
	
	/*Create Button and set its X,Y Coordinates - Kai*/
	menubutton = new Button(0, 0);
	menubutton->setXY(500, 280);

}
void Game::update()
{	
	bool updating = true; //Set update state of the application to true - SCW
	SDL_Event e; //Keeps track of the event - SCW

	while (updating) //To do while update state is true - SCW
	{
		while (SDL_PollEvent(&e)) //To do while there's a pending SDL Event - SCW 
		{
			switch (e.type) //Check the even type - SCW
			{
			case SDL_QUIT: //If quitting the application - SCW
				running = false; //Set the run state of the application to false = SCW
				return;
			case SDL_MOUSEBUTTONUP: //If the mouse button was released - SCW
				if (e.button.button == SDL_BUTTON_LEFT) //To do if the left button was clicked - SCW
				{
					/*CHANGE STATE ACCORDING TO BUTTON SELECTION -SCW*/
					if (menubutton->selected)
					{
						//Go to Menu State
						current = menu;
						updating = false;
						return;
					}
					
				}
			}
			/*IF THE EVENT IS TO QUIT THE SDL APPLICATION - SCW*/
			if (e.type == SDL_QUIT)
			{
				updating = false;
			}
		}


		//Get keyboard Input
		const Uint8* currentKeyState = SDL_GetKeyboardState(NULL); //Setup current key state - SCW
		//Update Objects
		//Check Things (mouse location, collision, etc.)
		//Call draw function(s)
		draw(); //Draw the screen - SCW
		menubutton->draw(); //Draw the menu button - SCW

		//Check for State Change
		if (currentKeyState[SDL_SCANCODE_ESCAPE])
		{
			//Go to Menu State
			current = menu;
			updating = false;
			break;
		}
	
	}

	
}
Game::~Game()
{
}
#pragma endregion


#pragma region Options
Options::Options()
{
	background = IMG_LoadTexture(ren, "Images/GameBackGround.png");//Load texture for the background - SCW
	cout << SDL_GetError() << endl; //Show SDL Errors - SCW
	
	/*Create Button and set its X,Y Coordinates - Kai*/
	menubutton = new Button(0, 0);
	menubutton->setXY(500, 680);
}
void Options::update()
{
	bool updating = true; //Set update state of the application to true - SCW
	SDL_Event e; //Keeps track of the event - SCW

	while (updating) //To do while update state is true - SCW
	{
		while (SDL_PollEvent(&e)) //To do while there's a pending SDL Event - SCW 
		{
			switch (e.type) //Check the even type - SCW
			{
			case SDL_QUIT: //If quitting the application - SCW
				running = false; //Set the run state of the application to false = SCW
				return;
			case SDL_MOUSEBUTTONUP: //If the mouse button was released - SCW
				if (e.button.button == SDL_BUTTON_LEFT) //To do if the left button was clicked - SCW
				{
					/*CHANGE STATE ACCORDING TO BUTTON SELECTION -SCW*/
					if (menubutton->selected)
					{
						//Go to Menu State
						current = menu;
						updating = false;
						return;
					}

				}
			}
			/*IF THE EVENT IS TO QUIT THE SDL APPLICATION - SCW*/
			if (e.type == SDL_QUIT)
			{
				updating = false;
			}
		}


		//Get keyboard Input
		const Uint8* currentKeyState = SDL_GetKeyboardState(NULL); //Setup current key state - SCW
																   //Update Objects
																   //Check Things (mouse location, collision, etc.)
																   //Call draw function(s)
		draw(); //Draw the screen - SCW
		menubutton->draw(); //Draw the menu button - SCW

							//Check for State Change
		if (currentKeyState[SDL_SCANCODE_ESCAPE])
		{
			//Go to Menu State
			current = menu;
			updating = false;
			break;
		}

	}
}
Options::~Options()
{
}
#pragma endregion


#pragma region HighScore
HighScore::HighScore()
{

	background = IMG_LoadTexture(ren, "Images/GameBackGround.png");//Load texture for the background - SCW
	cout << SDL_GetError() << endl; //Show SDL Errors - SCW

	/*Create Button and set its X,Y Coordinates - Kai*/
	menubutton = new Button(0, 0);
	menubutton->setXY(500, 680);




    rect = SDL_Rect{ 20, 20, 0, 0 };
    font = TTF_OpenFont("vgafix.fon", 18);
    
    surface = TTF_RenderText_Blended_Wrapped(font, "i like\n peanuts", SDL_Color{255, 50, 50, 255}, 400);
    texture = SDL_CreateTextureFromSurface(ren, surface);

    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(ren, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void HighScore::update()
{
	bool updating = true; //Set update state of the application to true - SCW
	SDL_Event e; //Keeps track of the event - SCW

	while (updating) //To do while update state is true - SCW
	{
		while (SDL_PollEvent(&e)) //To do while there's a pending SDL Event - SCW 
		{
			switch (e.type) //Check the even type - SCW
			{
			case SDL_QUIT: //If quitting the application - SCW
				running = false; //Set the run state of the application to false = SCW
				return;
			case SDL_MOUSEBUTTONUP: //If the mouse button was released - SCW
				if (e.button.button == SDL_BUTTON_LEFT) //To do if the left button was clicked - SCW
				{
					/*CHANGE STATE ACCORDING TO BUTTON SELECTION -SCW*/
					if (menubutton->selected)
					{
						//Go to Menu State
						current = menu;
						updating = false;
						return;
					}

				}
			}
			/*IF THE EVENT IS TO QUIT THE SDL APPLICATION - SCW*/
			if (e.type == SDL_QUIT)
			{
				updating = false;
			}
		}


		//Get keyboard Input
		const Uint8* currentKeyState = SDL_GetKeyboardState(NULL); //Setup current key state - SCW
																   //Update Objects
																   //Check Things (mouse location, collision, etc.)
																   //Call draw function(s)
		draw(); //Draw the screen - SCW
		menubutton->draw(); //Draw the menu button - SCW

							//Check for State Change
		if (currentKeyState[SDL_SCANCODE_ESCAPE])
		{
			//Go to Menu State
			current = menu;
			updating = false;
			break;
		}

	}
}

HighScore::~HighScore()
{
}

#pragma endregion


/*VARIABLE SECTION*/ //-SCW
SDL_Window *window = SDL_CreateWindow("TIC-TAC-TOE: The Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN); //Initialize SDL window (set loactions, dimensions, and error flag) - SCW
SDL_Renderer *ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); //Initialize SDL Renderer - SCW
//State Pointers - SCW
State *menu = new Menu;
State *game = new Game;
State *options = new Options;
State *highscore = new HighScore;
State *current = menu; //Application starts off in the 'Menu' State - SCW
bool running = true; //Set running state to true - SCW
