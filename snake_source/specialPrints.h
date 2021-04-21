#ifndef SPECIAL
#define SPECIAL
#include "terminal.h"
#include "colors.h"
#include <iostream>
#include <sstream>

class SpecialPrint: public Terminal
{
	private:
	int paintSnake = 0;
	bool printedRev = false; 
	string gameSize = "Medium"; 
	void PrintSnake(int y);
	bool printExplode(int count, int y, int x);
	void PrintKey(int y); 

	/////TODO REMOVE! Legacy Code! 
	void PrintSnakeOptions();
	void PrintSnakePlayGame();
	void PrintHighScore();
	void PrintSnakeOld();
	void PrintSnakeNew();
	void PrintColor();
	void PrintBoardSize();
	void PrintReturn();
	void PrintEasy();
	void PrintHard();
	void Print2020();
	void PrintColor1();
	void PrintColor2();
	void PrintColor3();
	void PrintColor4();
	void PrintColor5();
	void PrintColor6();
	void PrintColor7();
	void PrintSmall();
	void PrintMedium();
	void PrintLarge();
	void PrintOptions(int selection);
	public:	
	
	void PrintSecurityOptionScreen();
	void PrintSecSelection(int selection); 	
	int GetNumbers(bool &myG, int y, int x, int color, int color2); 
	void PrintSnakeHeader();
	void PrintCustomSizeScreen();
	void Revisited(int x, int y, int length);
	bool PrintFireWorks(int count, int y, int x, bool direction);
	void PaintSnake(int y, int x);
	void PaintSnakeEasy(int y, int x);
	void PrintHighScores(string *name, int *scores);
	bool SecurityAlert();
	void MainScreen(string *names, int *scores);
	void MainScreen();
	void AdminScreen();
	void OptionsScreen(bool header);
	void DifficultyScreen(bool header);
	void PrintColorScreen(bool header);
	void PrintSizeScreen(bool header);
	void PrintHighScoreScreen(string *names, int *scores);
	void HighScoreDisplay(int scoreNum);
	string PrintSizeSelection(int selection);
	string PrintDifficultySelection(int selection);
	void PrintColorSelection(int selection);
	string GetInitials(int length, int y, int x, int color, int color2, bool pw);//TODO This probably sshould be moved to selection manager. Taking input and printing. To much function for sinle method. 
	void PrintSelected(int selection, int clear);
	bool PrintdRev();
	void PrintCurrentSettings(string gameS, string gameTypeString, string difficultyString, int mult, int x, int y);
	void SetPaintSnake(int value);


};


#endif
