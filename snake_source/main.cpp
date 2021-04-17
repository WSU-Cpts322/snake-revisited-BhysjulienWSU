
#include "stateControl.h"

int main()

{
	bool closeGame = false;
	while(!closeGame)
	{
		StateManager gameLaunch;
		closeGame = gameLaunch.GameState(); 

	}

}	
