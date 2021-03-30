#include <string>
#include "scoreManager.h"
#include "terminal.h"
#include "snake.h"
#include "fruit.h"
#include "selectionMngr.h"
#include "gameManager.h" 
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define EASY 120
#define HARD 80
#define YR2020 40
using namespace std;
//int PlayGame(Terminal &myGame);
//string menuSelection(Terminal &myGame);
//string OptionsSelect(Terminal &myGame);
//void ChangeDirection(Snake &snake, int input, Terminal &myGame, int delay);
//void gameOverCheck(Snake &snake, Terminal &myGame, int width, int height);
//bool GameModeSelect(bool enterFlag, int position, Terminal &myGame);
//bool Compare(int y, int x, int direction, Terminal &myGame, Snake sanke);
//bool SpaceCheck(int y, int x, Terminal &myGame, char checkChar);
int StartGame(Terminal &myGame); 
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
	ScoreKeeper scores;
	string names [6]; 
	int scoresNum[6]; 
	scores.ReadStart("scores"); 
	scores.ReadStart("security"); 
	scores.GetHighScores(scoresNum, names); 
	Terminal myGame(SCREEN_HEIGHT, SCREEN_WIDTH);
	//Create a snake Object.
	//x and y are temp. 
	//Check to s:wq
	//ee if the user has selected for the game to be over. 
	int input = 0; 
	bool gameComplete = true;
	string option; 
	while(!myGame.QuitGame())
	{
		if(gameComplete)
		{
			scores.GetHighScores(scoresNum, names); 
			option = SelectionManager::menuSelection(myGame,names,scoresNum);
		}
		input = myGame.KeyPress();
		if(option == "Options")
		{
			scores.GetHighScores(scoresNum, names); 
			myGame.OptionsScreen();
			SelectionManager::OptionsSelect(myGame, scoresNum, names);
		}//Go to options game board. 
		else if(option == "High Scores")
		{
			SelectionManager::ShowScores(myGame, scores); 	
			gameComplete = true;
		}	//Go to view the high scores;; 
		else if(option == "Play Game")	//launch game with current options. 
		{
			int intScore = 	StartGame(myGame);
		       	bool check = scores.HighScoreCheck(intScore, myGame.GetGameType(), myGame.GetDifficultyStr());  	 

			if(check)// Then user needs to enter their initials
			{
				string name = myGame.GetInitials();
				if(!scores.SecurityCheck(name))
				{
					scores.AssignScore(name); 
				}
				else
				{
					myGame.SecurityAlert(); 
				}
			}
			option = "High Scores"; 
			gameComplete = false;

		}
		else if(option == "WSU")
		{
			Terminal WSUGame(35,188, "WSU");
			GameManager playGame(WSUGame.GetHeight(), WSUGame.GetWidth(), WSUGame.ScoreMultiplier(), "0", WSUGame,4, myGame.GetDifficulty());
		        WSUGame.ChangeColor(20,16);	
			playGame.PlayGame(WSUGame);

		}
		if(input == 'q')
		{
			myGame.SetQuitGame(true); 
		}
	}
	scores.PublicWrite("scores"); 
	scores.PublicWrite("security"); 
	return 0;
}
int StartGame(Terminal &myGame)
{
	int score; 
	if(myGame.GetHeight() == 20)
	{
		GameManager playGame(myGame.GetHeight(), myGame.GetWidth(), myGame.ScoreMultiplier(), "0", myGame, 1, myGame.GetDifficulty()); 
		score = playGame.PlayGame(myGame); 
	}
	else if(myGame.GetHeight() == 30)
	{
		GameManager playGame(myGame.GetHeight(), myGame.GetWidth(), myGame.ScoreMultiplier(), "0", myGame, 2, myGame.GetDifficulty()); 
		score = playGame.PlayGame(myGame); 
	}
	else if(myGame.GetHeight() == 40)
	{
		GameManager playGame(myGame.GetHeight(), myGame.GetWidth(), myGame.ScoreMultiplier(), "0", myGame, 3, myGame.GetDifficulty()); 
		score = playGame.PlayGame(myGame); 
	}
	//while(!myGame.GameOve() && !myGame.QuitGame()
	return score; 
}
