#include "Globals.h"
#include "State.h"
using namespace std;

void main() 
{

//Start/Run Application (State Machine), while running = true
	while (running)
	{
		current->update(); //Update the state
	}

	SDL_DestroyWindow(window); //Destroy the canvas/window
	SDL_Quit(); //Quit SDL Application

}
