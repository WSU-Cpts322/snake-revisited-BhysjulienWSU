#include "settings.h"

Settings::Settings()
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

Settings::Settings(int Height, int Width, string special) 
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
void Settings::SetPrimColor(int col)
{
	colorPrim = col; 
}
void Settings::SetSecondColor(int col)
{
	colorSec = col; 
}
int Settings::GetPrimColor()
{
	return colorPrim; 
}
int Settings::GetSecondColor() 
{
	return colorSec; 
}
int Settings::ScoreMultiplier()
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
	else 
	{
		gameMultiplier = gameMultiplier * 1;	
	}
	if(gameType == 2)
	{
		gameMultiplier = gameMultiplier * 2;	
	}
	return gameMultiplier; 
}
void Settings::SetGameType(int _gameType)
{
	gameType = _gameType; 
	if(gameType == OLD_SCHOOL)
		gameTypeString = "Old School";
	else if(gameType == NEW_SCHOOL)
		gameTypeString = "New School";
}
string Settings::GetGameType()
{
	return gameTypeString; 
}
bool Settings::GameOver()
{
	return gameover; 
}
bool Settings::QuitGame()
{
	return quitgame; 
}
string Settings::GetGameSize(string s)
{
	return gameSize; 
}
int Settings::GetGameSize()
{
	return width; 
}
void Settings::SetGameSize(string size) 
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
string Settings::GetDifficultyStr() 
{
	return difficultyString; 
}
void Settings::SetDifficulty(string dif)
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
int Settings::GetGameType(int j)
{
	return gameType;
}
int Settings::GetDifficulty()
{
	return difficulty; 
}
int Settings::GetHeight()
{
	return height;
}
int Settings::GetWidth()
{
	return width;
}
void Settings::SetHeight(int _height)
{
	height = _height;
}
void Settings::SetWidth(int _width)
{
	width = _width; 
}
void Settings::SetQuitGame(bool check)
{
	if(check == true)
		quitgame = true; 
	else
		quitgame = false; 
}
void Settings::SetGameOver(bool check)
{
	if(check == true)
		gameover = true;
	else
		gameover = false; 
}

