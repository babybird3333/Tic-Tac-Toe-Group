#include "State.h"


#pragma region State
State::State()
{

	//Set up the mouse - SCW
	static Mouse *m = new Mouse;
	mouse = m;


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
		const Uint8* currentKeyState = SDL_GetKeyboardState(NULL); //Setup current key state - SCW
		//Update Objects
		//Check Things (mouse location, collision, etc.)
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y)); //Access the location of the mouse's cursor rectangle - SCW
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
			n->checkSelected(mouse);
			i++;

		}
		mouse->draw(); //Draw the mouse
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
    playerX = new Player(true);
    playerO = new Player(false);
    currentPlayer = playerX;

	background = IMG_LoadTexture(ren, "Images/GameBackGround.png");//Load texture for the background - SCW
	cout << SDL_GetError() << endl; //Show SDL Errors - SCW
	board = IMG_LoadTexture(ren, "Images/CrossBoard.png");						//Kai

	/*Create Button and set its X,Y Coordinates - Kai*/
	menubutton = new Button(0, 0);
	menubutton->setXY(1280 - 192, 720 - 64);

    int offsetX = 325;
    int offsetY = 50;
    int sizeX = 175;
    int sizeY = 175;
    int padding = 50;
    int x = 0;
    int y = 0;
    //set squares
    for (int i = 0; i < 9; i++)
    {
        //left to right     1   2   3
        //top to bottom     4   5   6
        //                  7   8   9
        x = (sizeX + padding) * i;
        y = 0;
        while (x > (sizeX + padding) * 2)
        {
            x -= (sizeX + padding) * 3;
            y += (sizeY + padding);
        }
        sqr[i].square = { x + offsetX, y + offsetY, sizeX, sizeY };
        sqr[i].piece = NULL;
    }
}
void Game::update()
{	
    //all flag combinations of tictactor
    int ticTacToes[8]{ (1 + 2 + 4), (8 + 16 + 32), (64 + 128 + 256),
        (1 + 8 + 64), (2 + 16 + 128), (4 + 32 + 256),
        (1 + 16 + 256), (4 + 16 + 64) };


	bool updating = true; //Set update state of the application to true - SCW
	SDL_Event e; //Keeps track of the event - SCW

	while (updating) //To do while update state is true - SCW
	{
        int xFlag = 0;
        int oFlag = 0;
        int index = 0;

        for (; index < 9; index++)
        {
            //if a piece exists
            if (sqr[index].piece != NULL)
                //if it's an X
                if (sqr[index].piece->isX)
                    xFlag |= (int)pow(2, index); //add an exponential bit to the flag
                else
                    oFlag |= (int)pow(2, index); //o flag if not x
        }
        if (xFlag > 0)
            cout << xFlag << endl;
        //whether or not there's a tictactoe
        bool ticTacToe = false;

        for (auto t : ticTacToes)
        {
            int whatFlag = xFlag & t;
            if ((xFlag & t) == t)
                ticTacToe = true;
            else if ((oFlag & t) == t)
                ticTacToe = true;
        }

        if (ticTacToe)
        {
            //do things to save score
            //winningplayer = currentPlayer == playerX ? playerO : playerX;
            //winningplayer.saveScore("NAME HERE");
            updating = false;
            current = menu;
            game = new Game();
        }

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
					if (e.button.button == SDL_BUTTON_LEFT)				//Kai
					{													//Kai
                        for (auto &s : sqr)
                            if (s.piece == NULL && SDL_HasIntersection(&mouse->tip, &s.square))
                            {
                                Piece* newPiece = new Piece();
                                newPiece->texture = currentPlayer->piece.texture;
                                newPiece->isX = currentPlayer->piece.isX;
                                newPiece->rect = s.square;
                                s.piece = newPiece;

                                currentPlayer = currentPlayer == playerX ? playerO : playerX;
                            }
					}													//Kai
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

		currentPlayer->piece.drag(*mouse);													//Kai

		//Get keyboard Input
		const Uint8* currentKeyState = SDL_GetKeyboardState(NULL); //Setup current key state - SCW
		//Update Objects
		//Check Things (mouse location, collision, etc.)
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y)); //Access the location of the mouse's cursor rectangle - SCW
		//Call draw function(s)
		draw(); //Draw the screen - SCW
		for (int i = 0; i < 9; i++) //Draw the squares - Kai
		{
			SDL_RenderDrawRect(ren, &sqr[i].square);
		}

        //center the board on the screen
        int x = (1280 - 734) / 2;
        int y = (720 - 664) / 2;
        SDL_Rect dRect{ x, y, 734, 663 };
		SDL_RenderCopy(ren, board, NULL, &dRect); //Draw the crossboard - Kai

        for (auto s : sqr)
            if (s.piece != NULL)
                s.piece->draw();

		currentPlayer->piece.draw(); //Draw the piece - Kai

		menubutton->draw(); //Draw the menu button - SCW
		menubutton->checkSelected(mouse); //Check to see if the button has been selected - SCW
		mouse->draw(); //Draw the mouse - SCW
		SDL_RenderPresent(ren); // show the screen
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
	menubutton->setXY(500, 580);
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
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y)); //Access the location of the mouse's cursor rectangle - SCW
																   //Call draw function(s)
		draw(); //Draw the screen - SCW
		menubutton->draw(); //Draw the menu button - SCW
		menubutton->checkSelected(mouse); //Check to see if the button has been selected - SCW
		mouse->draw(); //Draw the mouse - SCW
		SDL_RenderPresent(ren); // show the screen

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
	menubutton->setXY(500, 580);

    ifstream input = ifstream("score.bin", ios::binary | ios::in);

    char num = 0;
    input.read((char*)num, sizeof(char));

    string names[100];
    char scores[100];

    for (int i = 0; i < num; i++)
    {
        char name[3];
        input.read((char*)name, sizeof(name));

        char score = 0;
        input.read((char*)score, sizeof(score));

        names[i] = string(name);
        scores[i] = score;
    }

    string masterString;

    char i = 0;
    for (auto name : names)
        masterString += name + " " + scores[i] + "\n";

    rect = SDL_Rect{ 20, 20, 0, 0 };
    font = TTF_OpenFont("vgafix.fon", 18);
    
    surface = TTF_RenderText_Blended_Wrapped(font, masterString.c_str(), SDL_Color{255, 50, 50, 255}, 400);
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
		SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y)); //Access the location of the mouse's cursor rectangle - SCW
																   //Call draw function(s)
		draw(); //Draw the screen - SCW
		menubutton->draw(); //Draw the menu button - SCW
		menubutton->checkSelected(mouse); //Check to see if the button has been selected - SCW
		mouse->draw(); //Draw the mouse - SCW
		SDL_RenderPresent(ren); // show the screen

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
