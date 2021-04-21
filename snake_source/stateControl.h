#ifndef STATE_MGN
#define STATE_MGN

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

class StateManager
{
	private:

	Settings myGame;
	Security scores;
	string names [6]; 
	int scoresNum[6]; 
	SpecialPrint terminal;
	int input = 0; 
	bool gameComplete = true;
	string option;

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

	public:
	StateManager()
	{
		myGame.SetPrimColor(BW);
		myGame.SetSecondColor(BLBL); 
		scores.ReadStart("scores"); 
		scores.ReadStart("security"); 
		scores.GetHighScores(scoresNum, names); 
		move(0,0);
	}
 	bool GameState()
	{	
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
				bool check = false; 
				SelectionManager select; 
				string pw = scores.getPassword();
				if(pw != "")
				{
					//Ask for password 
					check = select.PasswordInput(pw); 
				}
				else
				{
					check = true; 
					scores.setPassword(select.SetPassword(true)); 
					//Set Password
				}
				if(check == true)
				{
					select.AdminSettings(scores); 
				}
				else 
				{
					int temp = -1; 
					//PasswordFailed 
					terminal.Blink(true); 
					terminal.PrintMultiChars("WRONG!,YOU,SUCK",25,2); 
					terminal.Blink(false); 
					terminal.PrintString(30,2, "Just kidding! It happens to everyone. We're still not letting you in."); 
					terminal.PrintString(32,2, "Select Enter to return to the main menu"); 
					terminal.UpdateTerminal(); 	
					while(temp == -1)
					{
						temp = terminal.KeyPress(); 
					}
					terminal.EraseAll(); 
				}
			}
			if(input == 'q')
			{
				myGame.SetQuitGame(true); 
			}
			terminal.PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
		}
		scores.PublicWrite("scores"); 
		scores.PublicWrite("security"); 
		return true;
	}
		
};



#endif 
