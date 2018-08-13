#include "Game.h"

void Piece::draw()
{
	//Implemented
	SDL_RenderDrawRect(ren, &rect);
	//SDL_ScaleSurface(texture, 200, 200);
	SDL_RenderCopy(ren, texture, NULL, &rect);
	
}

Game::Game()
{
	background = IMG_LoadTexture(ren, "GameBackGround.png");
	board = IMG_LoadTexture(ren, "CrossBoard.png");
	
	p.texture = IMG_LoadTexture(ren, "BlueX.png");

	
	

}







void Game::update()
{
	rects sq[9];
	for (int i = 0; i < 9; i++)
	{
		sq[i].square = { 0, 0, 220, 220 };
		SDL_RenderDrawRect(ren, &sq[i].square);
	}

	SDL_Event e;
	bool running = true;
	
	while (running)
	{
		p.isSelected = SDL_HasIntersection(&(mouse.tip), &(p.rect));

		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				SDL_Quit();
				break;
			
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					if (p.isSelected)
					{
						p.isDragged = !p.isDragged;
					
						break;
					}
				}
				
			} //End of the Switch
		}//End of PollEvent Loop
		p.drag(mouse);

		SDL_RenderCopy(ren, background, NULL, NULL);
		for (int i = 0; i < 9; i++)
		{
			SDL_RenderDrawRect(ren, &sq[i].square);
		}
		SDL_RenderCopy(ren, board, NULL, NULL);
		p.draw();
		SDL_RenderPresent(ren);
	}//End of Running look
}

Game::~Game()
{
}

void Piece::drag(Mouse& mouse)
{
	if (isDragged)
	{
		SDL_GetMouseState(&mouse.tip.x, &mouse.tip.y);
		rect.x = mouse.tip.x;
		rect.y = mouse.tip.y;

	}
}

void Game::draw()
{
	
}

void Mouse::draw()
{
	tip.x = cursor.x;
	tip.y = cursor.y;
	SDL_RenderCopy(ren, mouseTexture, NULL, &cursor);
}

SDL_Window * window = SDL_CreateWindow("Drag and Drop Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
SDL_Renderer * ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);