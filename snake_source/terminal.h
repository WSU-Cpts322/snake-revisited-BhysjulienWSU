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
	void SetColor(bool color, int colorNum); //Set the actual color being printed (vs the global color settings). 
 	int SetCustomColor(string color, bool primary, bool assign); 
	int KeyPress(); //Take input 
	void printString(int y, int x, string str);//Prints a simple string. 
	void ClearTerminal(); //Clears the current screen.
	void UpdateTerminal();
	int GetCurrentPrimaryColor(); //Artifact 
	int GetCurrentSecondColor();  //Artifact 
	void ChangeColor(int colorChangeOne, int colorChangeTwo); //Changes the global color settings. 
	void PrintBox(int topLeftY, int topLeftX, int wDiv, int hDiv, int width, int height, int colorBoarder, int colorFill, bool divide, bool fill); //Simple function toe print box. Can print boarders only, or infill, or can be scaled.
	void Clear(int rows); //Clear specific number of rows
	//string* StringToInt(int*value, int count);//TODO release resources on function call. 
	void PrintString(int y, int x, string String); //Print a nucurses string. 
	void EraseAll(); //Clear entire terminal and all screans.  
	void Blink(bool blink);
};
#endif 

