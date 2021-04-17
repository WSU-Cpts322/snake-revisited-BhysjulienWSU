#ifndef SETTINGS
#define SETTINGS 
#include <string>

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
	int colorPrim;
	int colorSec; 

	public: 
	
	Settings();
	Settings(int Height, int Width, string special);
	void SetPrimColor(int col);
	void SetSecondColor(int col);
	int GetPrimColor();
	int GetSecondColor(); 
	int ScoreMultiplier();
	void SetGameType(int _gameType);
	string GetGameType();
	bool GameOver();
	bool QuitGame();
	string GetGameSize(string s);
	int GetGameSize();
	void SetGameSize(string size);
	string GetDifficultyStr();
	void SetDifficulty(string dif);
	int GetGameType(int j);
	int GetDifficulty();
	int GetHeight();
	int GetWidth();
	void SetHeight(int _height);
	void SetWidth(int _width);
	void SetQuitGame(bool check);
	void SetGameOver(bool check);
};
#endif 
