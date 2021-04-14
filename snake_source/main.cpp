#include <string>
#include "security.h"
#include "colors.h"
#include "fileIO.h"
#include "scoreManager.h"
#include "terminal.h"
#include "specialPrints.h"
#include "settings.h"
#include "snake.h"
#include "fruit.h"
#include "badSnake.h"
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
int StartGame(Settings &myGame); 

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
	Security scores;
	string names [6]; 
	int scoresNum[6]; 
	scores.ReadStart("scores"); 
	scores.ReadStart("security"); 
	scores.GetHighScores(scoresNum, names); 
	Settings myGame(SCREEN_HEIGHT, SCREEN_WIDTH);
	myGame.SetPrimColor(BW);
	myGame.SetSecondColor(BLBL); 
	SpecialPrint terminal;
	int input = 0; 
	bool gameComplete = true;
	string option;
	move(0,0); 
	while(!myGame.QuitGame())
	{
		if(gameComplete)
		{
			SelectionManager select;
			scores.GetHighScores(scoresNum, names); 
			option = select.menuSelection(myGame, names,scoresNum);
		}
		input = terminal.KeyPress();
		if(option == "Options")
		{
			SelectionManager select;
			scores.GetHighScores(scoresNum, names); 
			terminal.OptionsScreen(true);
			option = select.OptionsSelect(myGame, scoresNum, names);
		}//Go to options game board. 
		else if(option == "High Scores")
		{
			SelectionManager select; 
			myGame.SetQuitGame(select.ShowScores(myGame, scores)); 	
			gameComplete = true;
		}	//Go to view the high scores;; 
		else if(option == "Play Game")	//launch game with current options. 
		{
			int intScore = 	StartGame(myGame);
		       	bool check = scores.HighScoreCheck(intScore, myGame.GetGameType(1), myGame.GetDifficultyStr());  	 

			if(check)// Then user needs to enter their initials
			{
				int delay = 0; 
				int congrts = -1;
				terminal.HighScoreDisplay(intScore); 
				int count = 0; 
				bool fireWorks1 = true;
				bool fireWorks2 = false;
				bool fireWorks3 = false;
				int currentCount1 = 0; 
				int currentCount2 = 0; 
				while(congrts == -1)
				{
					congrts = terminal.KeyPress(); 	
					if(delay == 7000)
					{
						count++;
						delay = 0;
					}	
					delay++;

					if(fireWorks1 == true) 
					{					
						terminal.SetColor(true, BLR); 
						fireWorks2 = terminal.PrintFireWorks(count,37+2,78, true); 	
						congrts = terminal.KeyPress(); 
					}
					if(fireWorks2 == true) 
					{
						if(fireWorks1 == true)
						{
							currentCount1 = count;
							fireWorks1 = false;
						}	
						terminal.SetColor(true, GR); 
						fireWorks3 = terminal.PrintFireWorks(count-currentCount1,37+2,78, true); 	
						congrts = terminal.KeyPress(); 
					}
					if(fireWorks3 == true) 
					{
						if(fireWorks2 == true)
						{
							currentCount2 = count;
							fireWorks2 = false;
						}	
						terminal.SetColor(true, MR); 
						fireWorks1 = terminal.PrintFireWorks(count-currentCount2,37+2,78, true); 	
						congrts = terminal.KeyPress(); 
					}
					if(count > 850 && fireWorks3 == true)
					{
						fireWorks1 = true; 
						fireWorks2 = false; 
						fireWorks3 = false;
						count = 0; 
					}
				}
				terminal.EraseAll();
			       	SelectionManager select; 	
				string name = select.GetInit(3);
				if(!scores.SecurityCheck(name))
				{
					scores.AssignScore(name); 
				}
				else
				{
					myGame.SetQuitGame(terminal.SecurityAlert());
					

				}
			}
			option = "High Scores"; 
			gameComplete = false;

		}
		else if(option == "WSU")
		{
			Settings WSUGame(35,188, "WSU");
			GameManager playGame(WSUGame.GetHeight(), WSUGame.GetWidth(), WSUGame.ScoreMultiplier(), "0", 10, myGame.GetDifficulty());
		        terminal.ChangeColor(BR,RW);
			WSUGame.SetPrimColor(BR); 
			WSUGame.SetSecondColor(RW); 
			playGame.PlayGame(WSUGame);
		}
		else if(option == "admin")
		{
			SelectionManager select; 
			select.AdminSettings(scores); 
		}
		if(input == 'q')
		{
			myGame.SetQuitGame(true); 
		}
		terminal.PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
	}
	scores.PublicWrite("scores"); 
	scores.PublicWrite("security"); 
	return 0;
}
int StartGame(Settings &myGame)
{
	int score; 
	if(myGame.GetHeight() == 20)
	{
		GameManager playGame(myGame.GetHeight(), myGame.GetWidth(), myGame.ScoreMultiplier(), "0", 1, myGame.GetDifficulty()); 
		score = playGame.PlayGame(myGame); 
	}
	else if(myGame.GetHeight() == 30)
	{
		GameManager playGame(myGame.GetHeight(), myGame.GetWidth(), myGame.ScoreMultiplier(), "0", 2, myGame.GetDifficulty()); 
		score = playGame.PlayGame(myGame); 
	}
	else if(myGame.GetHeight() == 40)
	{
		GameManager playGame(myGame.GetHeight(), myGame.GetWidth(), myGame.ScoreMultiplier(), "0", 3, myGame.GetDifficulty()); 
		score = playGame.PlayGame(myGame); 
	}
	else 
	{
		GameManager playGame(myGame.GetHeight(), myGame.GetWidth(), myGame.ScoreMultiplier(), "0", 1, myGame.GetDifficulty()); 
		score = playGame.PlayGame(myGame); 
	}

	//while(!myGame.GameOve() && !myGame.QuitGame()
	return score; 
}
