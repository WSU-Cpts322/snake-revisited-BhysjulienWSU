#include <string>
#include "terminal.h"
#include "snake.h"
#include "fruit.h"
#include "selectionMngr.h"
#include "gameManager.h" 
#define HARD_MODE 4
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
using namespace std;
int PlayGame(Terminal &myGame);
string menuSelection(Terminal &myGame);
string OptionsSelect(Terminal &myGame);
void ChangeDirection(Snake &snake, int input, Terminal &myGame, int delay);
void gameOverCheck(Snake &snake, Terminal &myGame, int width, int height);
bool GameModeSelect(bool enterFlag, int position, Terminal &myGame);
bool Compare(int y, int x, int direction, Terminal &myGame, Snake sanke);
bool SpaceCheck(int y, int x, Terminal &myGame, char checkChar);
int main()

{
	//TODO PlayGame is working. Move to its own class and makee it modular for added functionality. 
	//TODO Move game status out of terminal.h (game over, game type, etc) and into PlayGame. Make Terminal a terminal specific class. 
	//TODO Create termina.cpp file and move class over. 
	//TODO Use function pointers to reduce redundency in selectionMng.h. 
	//TODO Add high score class. Takes two arguments for a consstructor???? Score & name List? Maybe an object per player? Think more about this. 
	//TODO track and print HighScores 
	//TODO balance difficulties a little more. Easy to slow, fast stll to fast. 
	//TODO Add boxes on Gamemode 2
	//TODO ADD WSU Logo 
	const int SCREEN_WIDTH = 25;
	const int SCREEN_HEIGHT = 25; 
	//Create a Terminal Object wrapper. 
	Terminal myGame(SCREEN_HEIGHT, SCREEN_WIDTH);
	//Create a snake Object.
	//x and y are temp. 
	//Check to see if the user has selected for the game to be over. 
	int input = 0; 
	while(!myGame.QuitGame())
	{
		string option = SelectionManager::menuSelection(myGame);
		input = myGame.KeyPress();
		if(option == "Options")
		{
			myGame.OptionsScreen();
			SelectionManager::OptionsSelect(myGame);
		}//Go to options game board. 
		else if(option == "High Scores")
		{
		
		}	//Go to view the high scores;; 
		else if(option == "Play Game")	//launch game with current options. 
		{
			PlayGame(myGame);
		}
		else if(option == "WSU")
		{
			Terminal WSUGame(35,188, "WSU"); 
			PlayGame(WSUGame); 	
		}
		if(input == 'q')
		{
			myGame.SetQuitGame(true); 
		}
	}
	return 0;
}
