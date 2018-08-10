#include "Globals.h"
#include "State.h"
using namespace std;

int main(int argc, char **args) 
{

	//Set show cursor to false
	SDL_ShowCursor(false);

//Start/Run Application (State Machine), while running = true
	while (running)
	{
		current->update(); //Update the state
	}

	SDL_DestroyWindow(window); //Destroy the canvas/window
	SDL_Quit(); //Quit SDL Application

	return 0;
}
