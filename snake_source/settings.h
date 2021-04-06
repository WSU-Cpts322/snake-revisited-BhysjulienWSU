#ifndef SETTINGS
#define SETTINGS 

#define EASY 120
#define HARD 80
#define YR2020 40
#define SMALLX 40 
#define SMALLY 20
#define MEDIUMX 60
#define MEDIUMY 30
#define LARGEX  80
#define LARGEY  40
#define OLD_SCHOOL 1
#define NEW_SCHOOL 2

using namespace std; 
//Class to handle keeping track of game settings. 
class Settings
{

	private: 
	bool gameover = false; 
	bool quitgame = false; 
	int height; 
	int width; 
	int difficulty = 1; 
	string gameSize = "Medium"; 
	int gameType = 1; 
	string difficultyString; 
	string gameTypeString; 

	public: 
	
	Settings(int Height, int Width)
	{
		height = MEDIUMY;
		width = MEDIUMX;
	       	gameSize = "Medium";
		difficultyString = "Easy"; 
		difficulty = EASY; 
		gameType = 1;
		gameTypeString = "Old School";
		gameover = false; 
		quitgame = false; 
	}

	Settings(int Height, int Width, string special) 
	{
		height = Height; 
		width = Width; 
		gameSize = special;
		difficultyString = "Special";
		difficulty = HARD; 
		gameType = 2; 
		gameTypeString = special + " School";
		//colorTypeOne = BR2;
		//colorTypeTwo = RR; 
		gameover = false; 
		quitgame = false; 
	}
	int ScoreMultiplier()
	{
	   	int gameMultiplier = 1; 
		if(difficulty == EASY)
		{
			gameMultiplier = 10; 
		}
		else if (difficulty == HARD)
		{
			gameMultiplier = 15;
		}
		else if(difficulty == YR2020)
		{
			gameMultiplier = 20;
		}
		if(gameSize == "Small")
		{
			gameMultiplier = gameMultiplier * 5;
		}
		else if(gameSize == "Medium")
		{
			gameMultiplier = gameMultiplier * 2;
		}
		else if(gameSize =="Large")
		{
			gameMultiplier = gameMultiplier * 1;	
		}
		if(gameType == 2)
		{
			gameMultiplier = gameMultiplier * 2;	
		}
		return gameMultiplier; 
	}
	void SetGameType(int _gameType)
	{
		gameType = _gameType; 
		if(gameType == OLD_SCHOOL)
			gameTypeString = "Old School";
		else if(gameType == NEW_SCHOOL)
			gameTypeString = "New School";
	}
	string GetGameType()
	{
		return gameTypeString; 
	}
	bool GameOver()
	{
		return gameover; 
	}
	bool QuitGame()
	{
		return quitgame; 
	}
	string GetGameSize(string s)
	{
		return gameSize; 
	}
	int GetGameSize()
	{
		return width; 
	//	int size = 0; 
	//	if(gameSize == "Medium")
	//		size = MEDIUMX;
	//	else if(gameSize == "Small")
	//		size = SMALLX; 
	//	else if(gameSize == "Large")
	//		size = LARGEX; 
	//	else
	//		size = LARGEX;
	//	return size; 
	}
	void SetGameSize(string size) 
	{
		gameSize = size;
		if(gameSize == "Small")
		{
			height = SMALLY;
			width = SMALLX; 	
		}	
		else if(gameSize == "Medium")
		{
			height = MEDIUMY;
			width = MEDIUMX; 	
		}	
		else if(gameSize == "Large")
		{
			height = LARGEY;
			width = LARGEX; 	
		}	
	}
	string GetDifficultyStr() 
	{
		return difficultyString; 
	}
	void SetDifficulty(string dif)
	{
		difficultyString = dif;
	        if(dif == "Easy")
	        {
	        	difficulty = EASY; 
	        }
		else if(dif == "Hard")
		{
			difficulty = HARD; 
		}
		else if(dif == "2020")
		{
			difficulty = YR2020;
		}
	}
	int GetGameType(int j)
	{
		return gameType;
	}
	int GetDifficulty()
	{
		return difficulty; 
	}
	int GetHeight()
	{
		return height;
	}
	int GetWidth()
	{
		return width;
	}
	void SetHeight(int _height)
	{
		height = _height;
	}
	void SetWidth(int _width)
	{
		width = _width; 
	}
	void SetQuitGame(bool check)
	{
		if(check == true)
			quitgame = true; 
		else
			quitgame = false; 
	}
	void SetGameOver(bool check)
	{
		if(check == true)
			gameover = true;
		else
			gameover = false; 
	}

};
#endif 
