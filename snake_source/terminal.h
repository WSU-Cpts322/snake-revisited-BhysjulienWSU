#ifndef TERMINAL
#define TERMINAL
#include <ncurses.h>
#include<map>
#include<string>
#include<iostream>
#include"letters.h"
#include"colors.h"

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
class Terminal: public Letters
{
	private:
	int colorTypeOne = RR; 
	int colorTypeTwo = GB;
	string gameTypeString; 
	void SetupTerminal();
	void TeardownTerminal();

	public:
	Terminal();
	~Terminal();
	void SetColor(bool color, int colorNum);
 	int SetCustomColor(string color, bool primary, bool assign);
	int KeyPress();
	void printString(int y, int x, string str);
	void ClearTerminal();
	void UpdateTerminal();
	int GetCurrentPrimaryColor(); //Artifact 
	int GetCurrentSecondColor();  //Artifact 
	void ChangeColor(int colorChangeOne, int colorChangeTwo);
	void PrintBox(int topLeftY, int topLeftX, int wDiv, int hDiv, int width, int height, int colorBoarder, int colorFill, bool divide, bool fill);
	void Clear(int rows);
	//string* StringToInt(int*value, int count);//TODO release resources on function call. 
	void PrintString(int y, int x, string String);
	void EraseAll();
	void Blink(bool blink);
};
#endif 

