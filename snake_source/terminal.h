#ifndef TERMINAL
#define TERMINAL
#include <ncurses.h>
#include<map>
#include<string>
#include<iostream>
#include"letters.h"

//#define BW 1
//#define CB 2
//#define RW 3
//#define MC 4
//#define BR 5
//#define BG 6
//#define GY 7
//#define RB 8
//#define RR 9
//#define GG 10
//#define BB 11
//#define BBL 12
//#define MM 13
//#define RR1 14
//#define CC 15
//#define WW 16
//#define GY22 17
//#define WB 18
//#define WR 19
//#define BR2 20
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
	bool printedRev = false; 
	int paintSnake = 0; 
	bool gameover;
	bool quitgame;	
	int height;
	int width; 
	int difficulty = 1;
	string gameSize = "Medium"; 
	int gameType = 1;
//	int colorTypeOne = RR; 
	int colorTypeOne = RR; 
	int colorTypeTwo = GB;
	string difficultyString; 
	string gameTypeString; 
	//map<string,int> m_colors;

	public:
	Terminal()
	{
		SetupTerminal(); 
	}
	~Terminal()
	{
		TeardownTerminal();
	}
	//Function for printing game settings. 
	void PrintCurrentSettings(string gameS, string gameTypeString, string difficultyString, int mult, int x, int y)
	{
		gameSize = gameS; 
		string Color 		= "Color:       " + to_string(colorTypeOne); 
		string gameSizeTemp     = "Game Size:   " + gameSize; 
		string gameTyTemp	= "Game Type:   " + gameTypeString;
		string difTemp		= "Difficulty:  " + difficultyString; 
		string scoreMulti	= "Score Multi: " + to_string(mult); 
		PrintString(y, x, Color); 
		PrintString(y+1, x, gameSizeTemp); 
		PrintString(y+2, x, gameTyTemp);
		PrintString(y+3, x, difTemp); 
		PrintString(y+4, x, scoreMulti); 
		//mvprintw(1, 60, Color.c_str());
		//mvprintw(2, 60, gameSizeTemp.c_str());
		//v
		//v
		//mvprintw(3, 60, gameTyTemp.c_str());
		//mvprintw(4, 60, difTemp.c_str());
		//mvprintw(5, 60, scoreMulti.c_str()); 
		move(0,0); 
	}
	//This one needs to move to slection menus. 
	void SetColor(bool color, int colorNum)
	{
		switch(colorNum)
		{
			case BB:
				if(color ==true)
				{
					attron(COLOR_PAIR(BB));
				}
				else
				{
					attroff(COLOR_PAIR(BB));
				}
				break;
			case BR:
				if(color ==true)
				{
					attron(COLOR_PAIR(BR));
				}
				else
				{
					attroff(COLOR_PAIR(BR));
				}
				break;
			case BG:
				if(color ==true)
				{
					attron(COLOR_PAIR(BG));
				}
				else
				{
					attroff(COLOR_PAIR(BG));

				}
				break;
			case BY:
				if(color ==true)
				{
					attron(COLOR_PAIR(BY));
				}
				else
				{
					attroff(COLOR_PAIR(BY));
				}
				break;
			case BBL:
				if(color ==true)
				{
					attron(COLOR_PAIR(BBL));
				}
				else
				{
					attroff(COLOR_PAIR(BBL));

				}
				break;
			case BM:
				if(color ==true)
				{
					attron(COLOR_PAIR(BM));
				}
				else
				{
					attroff(COLOR_PAIR(BM));
				}
				break;
			case BC:
				if(color ==true)
				{
					attron(COLOR_PAIR(BC));
				}
				else
				{
					attroff(COLOR_PAIR(BC));
				}
				break;
			case BW:
				if(color ==true)
				{
					attron(COLOR_PAIR(BW));
				}
				else
				{
					attroff(COLOR_PAIR(BW));
				}
				break;
			case RB:
				if(color ==true)
				{
					attron(COLOR_PAIR(RB));
				}
				else
				{
					attroff(COLOR_PAIR(RB));
				}
				break;
			case RR:
				if(color ==true)
				{
					attron(COLOR_PAIR(RR));
				}
				else
				{
					attroff(COLOR_PAIR(RR));
				}
				break;
			case RG:
				if(color ==true)
				{
					attron(COLOR_PAIR(RG));
				}
				else
				{
					attroff(COLOR_PAIR(RG));
				}
				break;
			case RY:
				if(color ==true)
				{
					attron(COLOR_PAIR(RY));
				}
				else
				{
					attroff(COLOR_PAIR(RY));
				}
				break;
			case RBL:
				if(color ==true)
				{
					attron(COLOR_PAIR(RBL));
				}
				else
				{
					attroff(COLOR_PAIR(RBL));
				}
				break;
			case RM:
				if(color ==true)
				{
					attron(COLOR_PAIR(RM));
				}
				else
				{
					attroff(COLOR_PAIR(RM));
				}
				break;
			case RC:
				if(color ==true)
				{
					attron(COLOR_PAIR(RC));
				}
				else
				{
					attroff(COLOR_PAIR(RC));
				}
				break;
			case RW:
				if(color ==true)
				{
					attron(COLOR_PAIR(RW));
				}
				else
				{
					attroff(COLOR_PAIR(RW));
				}
				break;
			case GB:
				if(color ==true)
				{
					attron(COLOR_PAIR(GB));
				}
				else
				{
					attroff(COLOR_PAIR(GB));
				}
				break;
			case GR:
				if(color ==true)
				{
					attron(COLOR_PAIR(GR));
				}
				else
				{
					attroff(COLOR_PAIR(GR));
				}
				break;
			case GG:
				if(color ==true)
				{
					attron(COLOR_PAIR(GG));
				}
				else
				{
					attroff(COLOR_PAIR(GG));
				}
				break; 
			case GY:
				if(color == true)
				{
					attron(COLOR_PAIR(GY));
				}
				else
				{
					attroff(COLOR_PAIR(GY)); 
				}
				break;
			case GBL:
				if(color ==true)
				{
					attron(COLOR_PAIR(GBL));
				}
				else
				{
					attroff(COLOR_PAIR(GBL));
				}
				break;
			case GM:
				if(color ==true)
				{
					attron(COLOR_PAIR(GM));
				}
				else
				{
					attroff(COLOR_PAIR(GM));
				}
				break;
			case GC:
				if(color ==true)
				{
					attron(COLOR_PAIR(GC));
				}
				else
				{
					attroff(COLOR_PAIR(GC));
				}
				break;
			case GW:
				if(color ==true)
				{
					attron(COLOR_PAIR(GW));
				}
				else
				{
					attroff(COLOR_PAIR(GW));
				}
				break;
			case YB:
				if(color ==true)
				{
					attron(COLOR_PAIR(YB));
				}
				else
				{
					attroff(COLOR_PAIR(YB));
				}
				break;
			case YR:
				if(color ==true)
				{
					attron(COLOR_PAIR(YR));
				}
				else
				{
					attroff(COLOR_PAIR(YR));
				}
				break;
			case YG:
				if(color ==true)
				{
					attron(COLOR_PAIR(YG));
				}
				else
				{
					attroff(COLOR_PAIR(YG));
				}
				break;
			case YY:
				if(color ==true)
				{
					attron(COLOR_PAIR(YY));
				}
				else
				{
					attroff(COLOR_PAIR(YY));
				}
				break;
			case YBL:
				if(color ==true)
				{
					attron(COLOR_PAIR(YBL));
				}
				else
				{
					attroff(COLOR_PAIR(YBL));
				}
				break;
			case YM:
				if(color ==true)
				{
					attron(COLOR_PAIR(YM));
				}
				else
				{
					attroff(COLOR_PAIR(YM));
				}
				break;
			case YC:
				if(color ==true)
				{
					attron(COLOR_PAIR(YC));
				}
				else
				{
					attroff(COLOR_PAIR(YC));
				}
				break;
			case YW:
				if(color ==true)
				{
					attron(COLOR_PAIR(YW));
				}
				else
				{
					attroff(COLOR_PAIR(YW));
				}
				break;
			case BLB:
				if(color ==true)
				{
					attron(COLOR_PAIR(BLB));
				}
				else
				{
					attroff(COLOR_PAIR(BLB));
				}
				break;
			case BLR:
				if(color ==true)
				{
					attron(COLOR_PAIR(BLR));
				}
				else
				{
					attroff(COLOR_PAIR(BLR));
				}
				break;
			case BLG:
				if(color ==true)
				{
					attron(COLOR_PAIR(BLG));
				}
				else
				{
					attroff(COLOR_PAIR(BLG));
				}
				break;
			case BLY:
				if(color ==true)
				{
					attron(COLOR_PAIR(BLY));
				}
				else
				{
					attroff(COLOR_PAIR(BLY));
				}
				break;
			case BLBL:
				if(color ==true)
				{
					attron(COLOR_PAIR(BLBL));
				}
				else
				{
					attroff(COLOR_PAIR(BLBL));
				}
				break;
			case BLM:
				if(color ==true)
				{
					attron(COLOR_PAIR(BLM));
				}
				else
				{
					attroff(COLOR_PAIR(BLM));
				}
				break;
			case BLC:
				if(color ==true)
				{
					attron(COLOR_PAIR(BLC));
				}
				else
				{
					attroff(COLOR_PAIR(BLC));
				}
				break;
			case BLW:
				if(color == true)
				{
					attron(COLOR_PAIR(BLW));
				}
				else
				{
					attroff(COLOR_PAIR(BLW)); 
				}
				break; 
			case MB:
				if(color ==true)
				{
					attron(COLOR_PAIR(MB));
				}
				else
				{
					attroff(COLOR_PAIR(MB));
				}
				break;
			case MR:
				if(color ==true)
				{
					attron(COLOR_PAIR(MR));
				}
				else
				{
					attroff(COLOR_PAIR(MR));
				}
				break;
			case MG:
				if(color ==true)
				{
					attron(COLOR_PAIR(MG));
				}
				else
				{
					attroff(COLOR_PAIR(MG));

				}
				break;
			case MY:
				if(color ==true)
				{
					attron(COLOR_PAIR(MY));
				}
				else
				{
					attroff(COLOR_PAIR(MY));
				}
				break;
			case MBL:
				if(color ==true)
				{
					attron(COLOR_PAIR(MBL));
				}
				else
				{
					attroff(COLOR_PAIR(MBL));

				}
				break;
			case MM:
				if(color ==true)
				{
					attron(COLOR_PAIR(MM));
				}
				else
				{
					attroff(COLOR_PAIR(MM));
				}
				break;
			case MC:
				if(color ==true)
				{
					attron(COLOR_PAIR(MC));
				}
				else
				{
					attroff(COLOR_PAIR(MC));
				}
				break;
			case MW:
				if(color ==true)
				{
					attron(COLOR_PAIR(MW));
				}
				else
				{
					attroff(COLOR_PAIR(MW));
				}
				break;
			case CB:
				if(color ==true)
				{
					attron(COLOR_PAIR(CB));
				}
				else
				{
					attroff(COLOR_PAIR(CB));
				}
				break;
			case CR:
				if(color ==true)
				{
					attron(COLOR_PAIR(CR));
				}
				else
				{
					attroff(COLOR_PAIR(CR));
				}
				break;
			case CG:
				if(color ==true)
				{
					attron(COLOR_PAIR(CG));
				}
				else
				{
					attroff(COLOR_PAIR(CG));
				}
				break;
			case CY:
				if(color ==true)
				{
					attron(COLOR_PAIR(CY));
				}
				else
				{
					attroff(COLOR_PAIR(CY));
				}
				break;
			case CBL:
				if(color ==true)
				{
					attron(COLOR_PAIR(CBL));
				}
				else
				{
					attroff(COLOR_PAIR(CBL));
				}
				break;
			case CM:
				if(color ==true)
				{
					attron(COLOR_PAIR(CM));
				}
				else
				{
					attroff(COLOR_PAIR(CM));
				}
				break;
			case CC:
				if(color ==true)
				{
					attron(COLOR_PAIR(CC));
				}
				else
				{
					attroff(COLOR_PAIR(CC));
				}
				break;
			case CW:
				if(color ==true)
				{
					attron(COLOR_PAIR(CW));
				}
				else
				{
					attroff(COLOR_PAIR(CW));
				}
				break;
			case WB:
				if(color ==true)
				{
					attron(COLOR_PAIR(WB));
				}
				else
				{
					attroff(COLOR_PAIR(WB));
				}
				break;
			case WR:
				if(color ==true)
				{
					attron(COLOR_PAIR(WR));
				}
				else
				{
					attroff(COLOR_PAIR(WR));
				}
				break;
			case WG:
				if(color ==true)
				{
					attron(COLOR_PAIR(WG));
				}
				else
				{
					attroff(COLOR_PAIR(WG));
				}
				break;
			case WY:
				if(color == true)
				{
					attron(COLOR_PAIR(WY));
				}
				else
				{
					attroff(COLOR_PAIR(WY)); 
				}
				break; 
			case WBL:
				if(color ==true)
				{
					attron(COLOR_PAIR(WBL));
				}
				else
				{
					attroff(COLOR_PAIR(WBL));
				}
				break;
			case WM:
				if(color ==true)
				{
					attron(COLOR_PAIR(WM));
				}
				else
				{
					attroff(COLOR_PAIR(WM));
				}
				break;
			case WC:
				if(color ==true)
				{
					attron(COLOR_PAIR(WC));
				}
				else
				{
					attroff(COLOR_PAIR(WC));
				}
				break;
			case WW:
				if(color == true)
				{
					attron(COLOR_PAIR(WW));
				}
				else
				{
					attroff(COLOR_PAIR(WW)); 
				}
				break; 
			default:
				break; 

		}
	}
	void SetPaintSnake(int value)
	{
		paintSnake = value; 
	}
	//Setup Object 
	void SetupTerminal()
	{
		initscr(); 
		scrollok(stdscr, TRUE);
		nodelay(stdscr,TRUE);
		cbreak();
		noecho(); 
	        //ChangeColor(); 
		curs_set(0);
		start_color(); 
		//First is forground second is background
		int counter = 1; 
		for(int fg =0; fg<8; fg++)
		{
			for(int bg =0; bg<8; bg++)
			{
				init_pair(counter, fg, bg); 
				counter++;
			}
		}
	}
 	int SetCustomColor(string color, bool primary, bool assign)
	{
		int temp; 
		if(color == "BB")	
			temp = 1;
		else if(color == "BR")	
			temp = 2;
		else if(color == "BG")	
			temp = 3;
		else if(color == "BY")	
			temp = 4;
		else if(color == "BBL")	
			temp = 5;
		else if(color == "BM")	
			temp = 6;
		else if(color == "BC")	
			temp = 7;
		else if(color == "BW")	
			temp = 8;
		else if(color == "RB")	
			temp = 9;
		else if(color == "RR")	
			temp = 10;
		else if(color == "RG")	
			temp = 11;
		else if(color == "RY")	
			temp = 12;
		else if(color == "RBL")	
			temp = 13;
		else if(color == "RM")	
			temp = 14;
		else if(color == "RC")	
			temp = 15;
		else if(color == "RW")	
			temp = 16;
		else if(color == "GB")	
			temp = 17;
		else if(color == "GR")	
			temp = 18;
		else if(color == "GG")	
			temp = 19;
		else if(color == "GY")	
			temp = 20;
		else if(color == "GBL")	
			temp = 21;
		else if(color == "GM")	
			temp = 22;
		else if(color == "GC")	
			temp = 23;
		else if(color == "GW")	
			temp = 24;
		else if(color == "YB")	
			temp = 25;
		else if(color == "YR")	
			temp = 26;
		else if(color == "YG")	
			temp = 27;
		else if(color == "YY")	
			temp = 28;
		else if(color == "YBL")	
			temp = 29;
		else if(color == "YM")	
			temp = 30;
		else if(color == "YC")	
			temp = 31;
		else if(color == "YW")	
			temp = 32;
		else if(color == "BLB")	
			temp = 33;
		else if(color == "BLR")	
			temp = 34;
		else if(color == "BLG")	
			temp = 35;
		else if(color == "BLY")	
			temp = 36;
		else if(color == "BLBL")	
			temp = 37;
		else if(color == "BLM")	
			temp = 38;
		else if(color == "BLC")	
			temp = 39;
		else if(color == "BLW")	
			temp = 40;
		else if(color == "MB")	
			temp = 41;
		else if(color == "MR")	
			temp = 42;
		else if(color == "MG")	
			temp = 43;
		else if(color == "MY")	
			temp = 44;
		else if(color == "MBL")	
			temp = 45;
		else if(color == "MM")	
			temp = 46;
		else if(color == "MC")	
			temp = 47;
		else if(color == "MW")	
			temp = 48;
		else if(color == "CB")	
			temp = 49;
		else if(color == "CR")	
			temp = 50;
		else if(color == "CG")	
			temp = 51;
		else if(color == "CY")	
			temp = 52;
		else if(color == "CBL")	
			temp = 53;
		else if(color == "CM")	
			temp = 54;
		else if(color == "CC")	
			temp = 55;
		else if(color == "CW")	
			temp = 56;
		else if(color == "WB")	
			temp = 57;
		else if(color == "WR")	
			temp = 58;
		else if(color == "WG")	
			temp = 59;
		else if(color == "WY")	
			temp = 60;
		else if(color == "WBL")	
			temp = 61;
		else if(color == "WM")	
			temp = 62;
		else if(color == "WC")	
			temp = 63;
		else if(color == "WW")	
			temp = 64;
		else 
		{
			if(primary)
			{
				temp = BC; 
			}
			else 
			{
				temp = WC;
			}
		}
		if(assign)
		{
			if(primary)
				colorTypeOne = temp; 
			else 
				colorTypeTwo = temp; 
		}
		return temp; 
	}	
	int KeyPress()
	{
		return getch(); 
	}
	void TeardownTerminal()
	{
		endwin(); 
	}
	//This function could take specific characters to only refresh changed points on gameboard???? 
	void ClearTerminal()
	{
		clear(); 
	}
	void UpdateTerminal()
	{
		refresh(); 
	}
	int GetCurrentPrimaryColor()
	{
		return colorTypeOne;
	}
	int GetCurrentSecondColor()
	{
		return colorTypeTwo;
	}
	void ChangeColor(int colorChangeOne, int colorChangeTwo)
	{
		colorTypeOne = colorChangeOne; 
		colorTypeTwo = colorChangeTwo;
	}	
	void PrintBoard(string gameTypeString, int width, int height)
	{
		if(gameTypeString == "WSU School")
		{
			//Call print WSU gameboard. 
			PrintWSUGameBoard(); 	
		}
		else
		{
			PrintBox(1,1,1,1,width, height, GetCurrentSecondColor(), GetCurrentPrimaryColor(), true, true); //myGame.GetCurrentColor()); 
		}
	}
	void PrintBox(int topLeftY, int topLeftX, int wDiv, int hDiv, int width, int height, int colorBoarder, int colorFill, bool divide, bool fill)
	{
	
		int boxWidth;
		int boxHeight; 
		int topRightY;
		int topRightX;
		int bottomLeftX;
		int bottomLeftY; 

		if(divide)
		{
			boxWidth = width/wDiv;
			boxHeight = height/hDiv;
		}
		else
		{
			boxWidth = wDiv;
			boxHeight = hDiv;
		}
		topRightY = topLeftY; 
		topRightX = topLeftX+boxWidth-1; 
		bottomLeftX = topLeftX; 
		bottomLeftY = topLeftY + boxHeight; 
		//Preserve previous color Settings. TODO: Make ColorSelect take int argument for modularity. 
		SetColor(true, colorBoarder);
		//Draw Outline of Box 
		mvhline(topLeftY,topLeftX,'X',boxWidth); 
		mvvline(topLeftY,topLeftX,'X',boxHeight);
		mvvline(topRightY,topRightX,'X',boxHeight); 
		mvhline(bottomLeftY,bottomLeftX,'X',boxWidth); 
		SetColor(false, colorBoarder); 
		if(fill == true)
		{
			SetColor(true, colorFill);
			//Drop interior of box. 
			for(int topTemp =topLeftY+1; bottomLeftY-1>=topTemp; topTemp++)
			{
				mvhline(topTemp,topLeftX+1, ' ',boxWidth-2); 
			}
			SetColor(false, colorFill);
		}
				
	}
	void PrintSnakeHeader()
	{
		attron(COLOR_PAIR(RB));
		printw("\n\n     XXXX   XX     XX    XXX    XX  XX  XXXXXX  XX\n   XX   XX  XXX    XX   XX XX   XX XX   XX      XX\n   XX       XX X   XX  XX   XX  XXX     XX      XX \n      XX    XX  X  XX  XX   XX  XXX     XXXXXX  XX\n        XX  XX   X XX  XX   XX  XX XX   XX      XX\n   XX   XX  XX    XXX  XX   XX  XX  XX  XX     \n     XXX    XX     XX  XX   XX  XX   XX XXXXXX  XX __\n   ===============================================|__*|--- \n\n\n");
		attroff(COLOR_PAIR(RB));	
	}
	void PrintSnakeOptions()
	{
		printw(" XXX  XXX  XXXXX XXXXX  XXX   X  X  XXXX\nX   X X  X   X     X   X   X  XX X  X\nX   X XXX    X     X   X   X  X  X  XXXX\nX   X X      X     X   X   X  X XX     X\n XXX  X      X   XXXXX  XXX   X  X  XXXX\n\n");
	}
	void PrintSnakePlayGame()
	{
		printw("XXX  X      X   X   X   XXX    X    X     X  X X X\nX  X X     X X   X X   X      X X   XX   XX  X\nXXX  X    X   X   X    X XX  X   X  X X X X  X X\nX    X    X X X   X    X  X  X X X  X  X  X  X\nX    XXXX X   X   X     XX   X   X  X  X  X  X X X\n\n");

	}
	void PrintHighScore()
	{
		printw("X   X XXXXX  XXX  X   X  XXXX  XXX   XXX   XXX  XXXXX\nX   X   X   X     X   X  X    X   X X   X X   X X\nXXXXX   X   X  XX XXXXX  XXX  X     X   X XXXX  XXX\nX   X   X   X   X X   X    X  X   X X   X X X   X\nX   X XXXXX  XXX  X   X  XXXX  XXX   XXX  X  X  XXXXX\n\n");
	}
	void PrintSnakeOld()
	{
		printw(" XXX  X    XXX     XXXXX  XXX  X   X  XXX   XXX  X\nX   X X    X  X    X     X   X X   X X   X X   X X\nX   X X    X   X   XXXXX X     XXXXX X   X X   X X\nX   X X    X  X        X X   X X   X X   X X   X X\n XX   XXXX XXX     XXXXX  XXX  X   X  XXX   XXX  XXXXX\n\n");
	}
	void PrintSnakeNew()
	{
		printw("X   X XXXXX X   X  XXXXX  XXX  X   X  XXX   XXX  X\nXX  X X     X   X  X     X   X X   X X   X X   X X\nX X X XXX   X X X  XXXXX X     XXXXX X   X X   X X\nX  XX X     XX XX      X X   X X   X X   X X   X X\nX   X XXXXX X   X  XXXXX  XXX  X   X  XXX   XXX  XXXXX\n\n");
	} 
	void PrintColor()
	{
		printw(" XXX   XXX  X     XXX  XXX\nX   X X   X X    X   X X  X\nX   X X   X X    X   X XXX\nX   X X   X X    X   X X X\n XXX   XXX  XXXX  XXX  X  X\n\n");
	}
	void PrintBoardSize()
	{
		printw(" XXX   XXX  X   X XXXXX  XXXXX XXXXX XXXXX XXXXXX\nX     X   X XX XX X      X       X      X  X\nX  XX X   X X X X XXX    XXXXX   X     X   XXXX\nX   X XXXXX X   X X          X   X    X    X\n XXX  X   X X   X XXXXX  XXXXX XXXXX XXXXX XXXXXX\n\n");
	}
	void PrintReturn()
	{
		printw("XXXX  XXXXX XXXXX X   X XXXX  X   X\nX   X X       X   X   X X   X XX  X\nXXXX  XXX     X   X   x XXXX  X X X\nX  X  X       X   X   X X  X  X  XX\nX   X XXXXX   X    XXX  X   X X   X\n\n");
	}
	void PrintEasy()
	{
		printw("XXXXX   XXX   XXXXX  X   X\nX      X   X  X      X   X\nXXX    XXXXX  XXXXX   XXX\nX      X   X      X    X\nXXXXX  X   X  XXXXX    X\n\n");
	}
	void PrintHard()
	{
		printw("X   X   XXX   XXXX   XXXX\nX   X  X   X  X   X  X   X\nXXXXX  XXXXX  XXXX   X   X\nX   X  X   X  X  X   X   X\nX   X  X   X  X   X  XXXX\n\n");
	}
	void Print2020()
	{
		printw(" XXXX    XXXX    XXXX    XXXX\nX   XX  XX  XX  X   XX  XX  XX\n   XX   XX  XX     XX   XX  XX\n  XX    XX  XX    XX    XX  XX\nXXXXXX   XXXX   XXXXXX   XXXX\n(For Expert Snake Players Only)\n\n");
	}
	void PrintColor1()
	{
		printw(" XXX    XXX   X      XXX   XXXX      X\nX   X  X   X  X     X   X  X   X    XX\nX      X   X  X     X   X  XXXX    x X\nX   X  X   X  X     X   X  X  X      X\n XXX    XXX   XXXXX  XXX   X   X   XXXXX\n\n");		
	}
	void PrintColor2()
	{
		printw(" XXX    XXX   X      XXX   XXXX    XXX\nX   X  X   X  X     X   X  X   X  X   X\nX      X   X  X     X   X  XXXX      X\nX   X  X   X  X     X   X  X  X     X\n XXX    XXX   XXXXX  XXX   X   X   XXXX\n\n");
	}
	void PrintColor3()
	{
		printw(" XXX    XXX   X      XXX   XXXX   XXXXX\nX   X  X   X  X     X   X  X   X      X\nX      X   X  X     X   X  XXXX    XXX\nX   X  X   X  X     X   X  X  X       X \n XXX    XXX   XXXXX  XXX   X   X  XXXXX \n\n");
	}
	void PrintColor4()
	{
		printw(" XXX    XXX   X      XXX   XXXX    X  X\nX   X  X   X  X     X   X  X   X   X  X\nX      X   X  X     X   X  XXXX    XXXXX\nX   X  X   X  X     X   X  X  X       X\n XXX    XXX   XXXXX  XXX   X   X      X\n\n");
	}
	void PrintColor5()
	{
		printw(" XXX    XXX   X      XXX   XXXX    XXXXX\nX   X  X   X  X     X   X  X   X   X\nX      X   X  X     X   X  XXXX    XXXX\nX   X  X   X  X     X   X  X  X        X\n XXX    XXX   XXXXX  XXX   X   X   XXXX \n\n");
	}
	void PrintColor6()
	{
		printw(" XXX    XXX   X      XXX   XXXX     XXX\nX   X  X   X  X     X   X  X   X   X \nX      X   X  X     X   X  XXXX    XXXX\nX   X  X   X  X     X   X  X  X    X   X\n XXX    XXX   XXXXX  XXX   X   X    XXX\n\n");
	}
	void PrintColor7()
	{
		printw(" XXX    XXX   X      XXX   XXXX    XXXXX\nX   X  X   X  X     X   X  X   X       X\nX      X   X  X     X   X  XXXX       X\nX   X  X   X  X     X   X  X  X      X\n XXX    XXX   XXXXX  XXX   X   X    X\n\n");
	}
	void PrintSmall()
	{
		printw("XXXXX  X   X   XXX   X     X\nX      XX XX  X   X  X     X\nXXXXX  X X X  XXXXX  X     X\n    X  X   X  X   X  X     X\nXXXXX  X   X  X   X  XXXXX XXXXXX\n\n");
	}
	void PrintMedium()
	{
		printw("X   X  XXXXX  XXXX  XXXXX  X   X  X   X\nXX XX  X      X   X   X    X   X  XX XX\nX X X  XXX    X   X   X    X   X  X X X\nX   X  X      X   X   X    X   X  X   X\nX   X  XXXXX  XXXX  XXXXX   XXX   X   X\n\n");
	}
	void PrintLarge()
	{
		printw("X      XXX   XXXX   XXXXX  XXXXX\nX     X   X  X   X  X      X\nX     XXXXX  XXXX   X XXX  XXXX\nX     X   X  X  X   X   X  X\nXXXXX X   X  X   X  XXXXX  XXXXX\n\n");
	}
	void PrintSnake(int y)
	{
		int j = 65; 
		string layer1       = "    ____                        "; 
		string layer2       = "   /. . \\                       ";
		string layer3	    = ">-----  /                       ";
		string layer4       = "   \\   /              __     /\\ ";
		string layer5       = "    \\  \\_____________/  \\___/ / ";
		string layer6       = "     \\________________/\\_____/  ";

		mvprintw(y,j, layer1.c_str()); 
		mvprintw(y+1,j, layer2.c_str());
		mvprintw(y+2,j, layer3.c_str());
		mvprintw(y+3,j, layer4.c_str());
		mvprintw(y+4,j, layer5.c_str());
		mvprintw(y+5,j, layer6.c_str());
	}
	void PrintWSUGameBoard()
	{
		SetColor(true, WR); 

		for(int i = 2; i<=21; i++)
		{
			mvvline(2,i,' ',34); 
		}
		for(int i = 0; i<=19; i++)
		{
			mvvline(2,38+i,' ',34); 
		}
		for(int i = 0; i<3; i++)
		{
			mvvline(2,79+i,' ',8); 
			mvvline(14,79+i,' ',10); 
			mvvline(28,79+i,' ',8); 
		}
		for(int i = 0; i<12;i++)
		{
			mvvline(28,126+i,' ',8); 
		}

		for(int i = 0; i< 4; i++)
		{
			mvvline(28-i, 22+i, ' ', 8+i);
			mvvline(28-i, 37-i, ' ', 8+i);
			mvvline(24-i, 26+i, ' ', 11);
			mvvline(24-i, 33-i, ' ', 11);
		}
		for(int i = 58; i<=57; i++)
		{
			mvvline(2,i,' ',34); 
		}
		for(int i = 0; i<5; i++)
		{
			mvvline(28,58+i,' ',8); 
			mvvline(2,98+i,' ',8); 
		}
		for(int i = 0; i<16; i++)
		{
			mvvline(2,63+i,' ',22); 
			mvvline(2,82+i,' ',8); 
			mvvline(28,63+i,' ',8); 
			mvvline(14,82+i,' ',22); 
		}
		for(int i = 0; i<23; i++)
		{
			mvvline(2,103+i,' ',34); 
		}
		for(int i = 0; i<24; i++)
		{
			mvvline(2,138+i,' ',34); 
		}
		SetColor(false, WR); 
		SetColor(true, WW); 
//Boarder. Print in RR
		mvhline(1,1,'X',22); //Top W
		mvhline(1,37,'X',22);//Top W
		mvhline(1,62,'X',65);//Top S
		mvhline(1,137,'X',26);//Top U
		mvvline(2,1,'X',34); //Left W
		mvvline(2,22,'X',26); //Mid Left W
		mvvline(2,37,'X',26); //Mid rigt W
		mvvline(2,58,'X',25); //Right W
		mvvline(2,62,'X',22);//Left S
		mvvline(25,81,'X',2); // Middle bottom S
		mvvline(11,79,'X',2); // Middle top S
		mvhline(27,58,'X',24);//Middle BottomS
		mvhline(24,62,'X',20);//Middle Bottom S
		mvhline(10,79,'X',24);//Middle BottomS
		mvhline(13,79,'X',20);//Middle Bottom S
		mvvline(14,98,'X',22); //Right S
		mvvline(11,102,'X',25); //left U
		mvvline(2,126,'X',25); //Middle Left U 
		mvvline(2,137,'X',25); //Middel Right U
		mvvline(2,162,'X',34); //Right U
		mvhline(27,126,'X',12);//Middle U
		mvhline(36,1,'X',25);//Bottom W
		mvhline(36,34,'X',65);//Bottom W/S
		mvhline(36,102,'X',61);//Bottom W/S
		mvhline(26,23,'X',1);//W
		mvhline(25,24,'X',1);//W
		mvhline(24,25,'X',1);//W
		mvhline(23,26,'X',1);//W
		mvhline(22,27,'X',1);//W
		mvhline(21,28,'X',1);//W
		mvhline(20,29,'X',2);//W
		mvhline(21,31,'X',1);//W
		mvhline(22,32,'X',1);//W
		mvhline(23,33,'X',1);//W
		mvhline(24,34,'X',1);//W
		mvhline(25,35,'X',1);//W
		mvhline(26,36,'X',1);//W
		mvhline(35,26,'X',1);//W
		mvhline(34,27,'X',1);//W
		mvhline(33,28,'X',1);//W

		mvhline(32,29,'X',2);//W
		mvhline(33,31,'X',1);//W
		mvhline(34,32,'X',1);//W
		mvhline(35,33,'X',1);//W
		mvhline(25,333,'X',1);//W

		SetColor(false, WW);
	        SetColor(true, BB);
		mvhline(26-2,36+25,'X',1);//W
		mvhline(26-1-12,40+1+34+24,'X',1);//W
		SetColor(false,BB); 	
	} 
	void Clear(int rows)
	{
		string clear        = "                                       ";
		for(int i = 0; i<rows; i++)
		{
			mvprintw(10+i,65,clear.c_str()); 
		}
	}
	void PrintOptions(int selection)
	{     
		if(selection == 1)
		{
			SetColor(true, GB);	
			Clear(20); 
			PrintSnake(10); 
			SetColor(false, GB);	
		}
		if(selection ==2)
		{
			SetColor(true, GB);	
			Clear(20); 
			PrintSnake(16); 
			SetColor(false, GB);	
		}
	}
	//Function that prints game size based on index and returns a string based on that selection. 
	string PrintSizeSelection(int selection)
	{
		string gameSize = "Large";
		if(selection == 1)
		{
			SetColor(true, GB);	
			Clear(18);
			PrintSnake(10);
			gameSize = "Small";
			height = SMALLY;
			width = SMALLX; 
			SetColor(false, GB);	
		}
		if(selection == 2)
		{
			SetColor(true, GB);	
			Clear(18);
			PrintSnake(16);
			gameSize = "Medium";
			height = MEDIUMY;
			width = MEDIUMX;
			SetColor(false, GB);	

		}
		if(selection == 3)
		{
			SetColor(true, GB);	
			Clear(18);
			PrintSnake(22);
			gameSize ="Large";
			height = LARGEY;
			width = LARGEX; 
			SetColor(false, GB);	
		}
		return gameSize; 
	}	
	string PrintDifficultySelection(int selection)
	{
		string dif; 
		difficulty = selection; 
		if(selection == 1)
		{
			SetColor(true, GB);	
			dif = "Easy";
			Clear(18);
			PrintSnake(10); 
			SetColor(false, GB);	
		}	
		if(selection == 2)
		{
			SetColor(true, GB);	
			dif = "Hard";
			Clear(18); 
			PrintSnake(16); 
			SetColor(false, GB);	
		}
		if(selection ==3)
		{
			SetColor(true, GB);	
			dif = "2020"; 
			Clear(18);
			PrintSnake(22);
			SetColor(false, GB);	
		}
		return dif; 
	}
	void PrintColorSelection(int selection)
	{
		if(selection == 1)
		{
			colorTypeOne = BW;
			colorTypeTwo = WB;
			Clear(37); 
			attron(COLOR_PAIR(BW)); 
			PrintSnake(10);
			attroff(COLOR_PAIR(BW));
			//SetColor(selection);
		}
		else if(selection == 2)
		{
			colorTypeOne = CBL;
			Clear(37); 
			colorTypeTwo = CC; 
			attron(COLOR_PAIR(CBL)); 
			PrintSnake(16);
			attroff(COLOR_PAIR(CBL));
			//SetColor(selection);
		}
		else if(selection ==3)
		{
			colorTypeOne = RW;
			Clear(37); 
			colorTypeTwo =RR;
			attron(COLOR_PAIR(RW)); 
			PrintSnake(22);
			attroff(COLOR_PAIR(RW));
			//SetColor(selection);
		}
		else if(selection ==4)
		{
			colorTypeOne = MC;
			Clear(37);
			colorTypeTwo = MM; 
			attron(COLOR_PAIR(MC)); 
			PrintSnake(28);	
			attroff(COLOR_PAIR(MC));
			//SetColor(selection);
		}
		else if(selection ==5)
		{
			colorTypeOne = BR;
			colorTypeTwo = BBL;
			Clear(37);
			attron(COLOR_PAIR(BR)); 
			PrintSnake(34);
			attroff(COLOR_PAIR(BR));
			//SetColor(selection);
		}
		else if(selection == 6)
		{
			Clear(37);
			colorTypeOne = BW;
			colorTypeTwo = WB; 
			SetColor(true, BW);
			PrintSnake(40); 
			SetColor(false, BW); 
		}
	}
	string GetInitials()//TODO This probably sshould be moved to selection manager. Taking input and printing. To much function for sinle method. 
	{
		PrintSnakeHeader(); 
		Revisited(0, 24, 0);
		PaintSnakeEasy(24,56); 	
		PrintString(12,2, "Congratulations, you have achived a highscore. Please enter your initials:");
		int input;
	       	string initials; 
		bool enterFlag = false; 
		int i = 0; 
		while(!enterFlag)
		{
			input = KeyPress();
			if(i<3)
			{
				if(input >= 97 && input <= 122) //Then its uppercase 
				{
					char temp = input;
					temp = toupper(temp);	
					initials+=temp; 
					i++;
				}
				if(input >= 65 && input <= 90)
				{
					char temp = input;
					temp = input;
					initials+=temp;
					i++; 
				}
			}
			if(input == 8 || input == 127) 
			{
				string temp = initials.substr(0,initials.length()-1);
				initials = temp; 
				PrintMultiChars("     ",14,2); 
				//PrintString(14,2, "             "); 
				i--; 
			}
			if(input == '\n')
			{
				if(i == 0)
				{
					PrintString(16,2, "Please enter at least one character before continuing"); 
				}
				else
				{
					enterFlag = true; 
				}
			}
			
			PrintMultiChars(initials, 14,2); 
	//		PrintString(14,2, initials); 
		
		}
		return initials; 
	}
	string* StringToInt(int*value, int count)//TODO release resources on function call. 
	{
		string *temp = new string[count]; 
		for(int i = 0; i<count; i++)
		{
			temp[i] = to_string(value[i]);
		}
		return temp; 
	}
	void PrintString(int y, int x, string String)
	{	
  		mvprintw(y,x, String.c_str()); 
	}
	void PrintSelection(int selection, int clear)
	{
		if(selection == 1)
		{
			SetColor(true, GB); 
			Clear(clear); 
			PrintSnake(10);
			SetColor(false, GB); 
		}
		else if(selection == 2)
		{
			SetColor(true, GB); 
			Clear(clear); 
			PrintSnake(16);
			SetColor(false, GB); 
		}
		else if(selection ==3)
		{
			SetColor(true, GB); 
			Clear(clear); 
			PrintSnake(22);
			SetColor(false, GB); 
		}
		else if(selection ==4)
		{
			SetColor(true, GB); 
			Clear(clear);
			PrintSnake(28);	
			SetColor(false, GB); 
		}
		else if(selection ==5)
		{
			SetColor(true, GB); 
			Clear(clear);
			PrintSnake(34);
			SetColor(false, GB); 
		}
	}
	void EraseAll()
	{
		erase(); 
	}
	void PrintHighScores(string *name, int *scores)
	{
		string *stgScores = StringToInt(scores, 6);
		string tempForPrinting[6] = {"Easy: ", "Hard: ", "2020: ", "Easy: ", "Hard: ", "2020: "};
		PrintString(1, 100, "~High Scores~"); 
		PrintString(2,88,"Old School"); 
		PrintString(2,113, "New School"); 
		for(int j =0; j<6; j++)
		{
			string gap(7-stgScores[j].length(), ' ');
			string temp;
			if(name[j] != "")
			{
				temp = stgScores[j] + gap +" (" +name[j] + ")";
			}
			else
			{
				temp = ""; 
			}
			tempForPrinting[j] += temp; 
		}
		PrintString(3,88, tempForPrinting[0]); 
		PrintString(4,88, tempForPrinting[1]); 
		PrintString(5,88, tempForPrinting[2]); 
		PrintString(3,113, tempForPrinting[3]); 
		PrintString(4,113, tempForPrinting[4]); 
		PrintString(5,113, tempForPrinting[5]); 
	
	}
	bool SecurityAlert()
	{
		int i = -1; 
		while(i ==-1)
		{
			i = KeyPress(); 
			erase(); 
			PrintSnakeHeader();
			SetColor(true, RR); 
			PrintMultiChars("SECURITY,,ALERT!!!", 10,3);
			SetColor(true, RB); 
			PrintString(16,2, "SECURITY ALERT: Your initials have been evaluated by the highly advance onboard \"Snake AI.\"");
			PrintString(17,2,  "Basd on your initals it was determined you are a generaly shady individual and not to be trusted."); 
			PrintString(18,2, "While we understand you didn't cheat on this game, our AI has determined it is only a matter of time before you do.");  
			PrintString(19,2, "As a result, your score has been deleted. Can't argue with Science!!!");
			PrintString(21,2, "Sincerely, Mr. Snake"); 
			PrintString(26,2, "          ----------------------------GOOD BYE-----------------------------------          "); 
			SetColor(false, RB);
		}	
		return true; 
	}

	void MainScreen(string *names, int *scores)
	{
		PrintSnakeHeader();
		
		SetColor(true,GBL); 
		PrintMultiChars("PLAY,GAME", 11,2); 
		PrintMultiChars("OPTIONS", 11+6,2); 
		PrintMultiChars("HIGH,SCORES", 11+12,2);
		SetColor(false, GBL); 
		PrintHighScores(names, scores);
	}
	void MainScreen()
	{
		SetColor(true,GBL); 
		PrintMultiChars("PLAY,GAME", 11,2); 
		PrintMultiChars("OPTIONS", 11+6,2); 
		PrintMultiChars("HIGH,SCORES", 11+12,2);
		SetColor(false, GBL); 
	}
	void OptionsScreen(bool header)
	{
		if(header)
		{
			PrintSnakeHeader(); 
		}
		SetColor(true,GBL); 
		PrintMultiChars("OLD,SCHOOL", 11,2); 
		PrintMultiChars("NEW,SCHOOL", 11+6,2); 
		PrintMultiChars("COLOR", 11+12,2); 
		PrintMultiChars("GAME,SIZE", 11+18,2); 
		PrintMultiChars("RETURN", 11+24,2); 
		SetColor(false, GBL); 
	}
	void DifficultyScreen(bool header)
	{
		if(header)
		{
			PrintSnakeHeader(); 
		}
		SetColor(true,GBL); 
		PrintMultiChars("EASIEST", 11,2); 
		PrintMultiChars("HARDEST", 11+6,2); 
		PrintMultiChars("YR,2020", 11+12,2); 
		PrintString(11+13+4,2,"Warning: For expert players only");	
		SetColor(false, GBL); 
	}
	void PrintColorScreen(bool header) 
	{
		if(header)
		{
			PrintSnakeHeader(); 
		}
		PrintMultiChars("BLACK/WHT", 11,2); 
		PrintMultiChars("BLUE/BLUE", 11+6,2); 
		PrintMultiChars("RED/WHITE", 11+12,2); 
		PrintMultiChars("RED/CYAN", 11+18,2); 
		PrintMultiChars("BLUE/RED", 11+24,2); 
		PrintMultiChars("CUSTOM", 11+30,2); 
		SetColor(false, GBL); 
	}
	void PrintSizeScreen(bool header)
	{
		if(header)
		{
			PrintSnakeHeader(); 
		}
		SetColor(true,GBL); 
		PrintMultiChars("SMALL", 11,2); 
		PrintMultiChars("MEDIUM", 11+6,2); 
		PrintMultiChars("LARGE", 11+12,2); 
	}
	void PrintHighScoreScreen(string *names, int *scores)
	{
		erase();
		PrintSnakeHeader(); 
		PrintMultiChars("HIGH SCORES!!!", 11,3); 		
		//PrintHighScore(); 
		UpdateTerminal(); 
		PrintHighScores(names, scores);
	}
	void HighScoreDisplay(int scoreNum)
	{
		int x;
		int y; 
		PrintSnakeHeader(); 
		string *scoreStr = StringToInt(&scoreNum, 1);
		getyx(stdscr, y, x);
		PrintBox(y, 1, 109,26,109,26, GG,RR,false, true); 
		SetColor(true,GG); 
		PrintMultiChars("CONGRATULATIONS,...", y+2,3); 
		PrintMultiChars("NEW,,HIGHSCORE!!!",y+8,8); 
		SetColor(false,GG); 
		SetColor(true,BLBL); 
		PrintMultiChars("YOUR,,SCORE:", y+14,8); 
		SetColor(true, WW); 
		PrintMultiChars(*scoreStr, y+20,8);
		SetColor(false,WW); 
		getyx(stdscr, y, x);
		Revisited(2,y+4, 0); 
		PaintSnakeEasy(y+4, 56+2); 
	}
	void Revisited(int x, int y, int length)
	{
		SetColor(true, RB); 
		PrintString(y,x,"                                                             XXXXXXXXXX                                            ");
		PrintString(y+1,x,"XXXXXXXXX     XXXXXXXXXXXX XXX        XX  XXXXXXXXX      XXXXXXXXXXXXXXXXX       XXXXXXXXXXXXX             XXXXXXXX ");
		PrintString(y+2,x,"XXXXXXXXXXX   XXXXXXXXXXXX XXX        XX  XXXXXXXXXXXXX XXXXXXXXXXXXXXX        XXXXXXXXXXXXXXXXX           XXXXXXXXXX ");
		PrintString(y+3,x,"XX       XXX  XXX          XXX        XX     XXXX       XXX              XXXX         XXX                  XX       XXX ");
		PrintString(y+4,x,"XX        XX  XX           XXX        XX      XXX       XX               XXXX         XXX         XXXX     XX        XXX ");
		PrintString(y+5,x,"XX       XX   XXX          XXX        XX      XXX       XXXXXXXXXX                    XXX       XXXXXXXXX  XX         XXX ");
		PrintString(y+6,x,"XXXXXXXXXXX   XXXXXXXXXX   XXX        XX      XXX        XXXXXXXXXX                   XXX      XX      XXX XX         XXX ");
		PrintString(y+7,x,"XXXXXXXX      XXX          XXX       XXX      XXX               XXXX      XX          XXX      XXXXXXXXXX  XX         XXX ");
		PrintString(y+8,x,"XX   XXX      XX            XXX     XXX       XXX                 XX      XX          XXX      XXX         XX         XXX ");
		PrintString(y+9,x,"XX     XX     XXX            XXX   XXX       XXXXX              XXX       XX          XXX      XX       XX XX        XXX ");
		PrintString(y+10,x,"XX      XX    XXXXXXXXXXXX    XXX XXX     XXXXXXXXXXXX       XXXX        XXXXX      XXXXXX      XXX    XX  XXXXXXXXXXX ");
		PrintString(y+11,x,"XX       XX   XXXXXXXXXXXX      XXX       XXXXXXXXXX      XXXX         XXXXXXXXX   XXXXXXXXX     XXXXXXX   XXXXXXXXX ");
		SetColor(false, RB); 

	
	}
	bool PrintdRev()
	{
		return printedRev; 
	}
	void PaintSnake(int y, int x)
	{
		int del = 1;
		SetColor(true,GG); 
		if(paintSnake == 49)
			PrintString(y+13,x-56,"XXX");
		if(paintSnake == 48)
			PrintString(y+13,x-54,"XXX");
		if(paintSnake == 47)
			PrintString(y+13,x-52,"XXX");
		if(paintSnake == 46)
			PrintString(y+13,x-50,"XXX");
		if(paintSnake == 45)
			PrintString(y+13,x-48,"XXX");
		if(paintSnake == 44)
			PrintString(y+13,x-46,"XXX");
		if(paintSnake == 43)
			PrintString(y+13,x-44,"XXX");
		if(paintSnake == 42)
			PrintString(y+13,x-42,"XXX");
		if(paintSnake == 41)
			PrintString(y+13,x-40,"XXX");
		if(paintSnake == 40)
			PrintString(y+13,x-38,"XXX");
		if(paintSnake == 39)
			PrintString(y+13,x-36,"XXX");
		if(paintSnake == 38)
			PrintString(y+13,x-34,"XXX");
		if(paintSnake == 37)
			PrintString(y+13,x-32,"XXXX");
		if(paintSnake == 36)
			PrintString(y+13,x-30,"XXX");
		if(paintSnake == 35)
			PrintString(y+13,x-28,"XXX");
		if(paintSnake == 34)
			PrintString(y+13,x-26,"XXX");
		if(paintSnake == 33)
			PrintString(y+13,x-24,"XXX");
		if(paintSnake == 32)
			PrintString(y+13,x-22,"XXX");
		if(paintSnake == 31)
			PrintString(y+13,x-20,"XXX");
		if(paintSnake == 30)
			PrintString(y+13,x-18,"XXX");
		if(paintSnake == 29)
			PrintString(y+13,x-16,"XXX");
		if(paintSnake == 28)
			PrintString(y+13,x-14,"XXX");
		if(paintSnake == 27)
			PrintString(y+13,x-12,"XXXX");
		if(paintSnake == 26)
			PrintString(y+13,x-10,"XXX");
		if(paintSnake == 25)
			PrintString(y+13,x-8,"XXX");
		if(paintSnake == 24)
			PrintString(y+13,x-6,"XXX");
		if(paintSnake == 23)
			PrintString(y+13,x-4,"XXX");
		if(paintSnake == 22)
			PrintString(y+12,x-2,"XXXX");
		if(paintSnake == 21)
			PrintString(y+12,x-1,"XXXX");
		if(paintSnake == 20)
			PrintString(y,x+5,"XXXXXXXXXX");
		if(paintSnake == 19)
			PrintString(y+1,x+1,"XXXXXXXXXXXXXXXXX");
		if(paintSnake == 18)
			PrintString(y+2,x,"XXXXXXXXXXXXXXX");
		if(paintSnake == 17)
			PrintString(y+3,x,"XXX");
		if(paintSnake == 16)
			PrintString(y+4,x,"XX");
		if(paintSnake == 15)
			PrintString(y+5,x,"XXXXXXXXXX");
		if(paintSnake == 14)
			PrintString(y+6,x+1,"XXXXXXXXXX");
		if(paintSnake == 13)
			PrintString(y+7,x+8,"XXXX");
		if(paintSnake == 12)
			PrintString(y+8,x+10,"XX");
		if(paintSnake == 11)
			PrintString(y+9,x+8,"XXX");
		if(paintSnake == 10)
			PrintString(y+10,x+5,"XXXX");
		if(paintSnake == 9)
			PrintString(y+11,x+2,"XXXX");

		if(paintSnake == 60)
		{
			SetColor(true, GY);	
			PrintString(y,x+14, "@");
			SetColor(false, GY);
		}	
		if(paintSnake == 60+del*1)
		{
			SetColor(true, RB);	
			PrintString(y+1,x+18, "-");
			SetColor(false, RB);
		}
		if(paintSnake == 60+ del*2)
		{
			SetColor(true, RB);	
			PrintString(y+1,x+18+1, "-");
			SetColor(false, RB);
		}
		if(paintSnake == 60 +del*3)
		{
			SetColor(true, RB);	
			PrintString(y+1,x+18+2, "-");
			SetColor(false, RB);
		}
		if(paintSnake == 60 +del*4)
		{
			SetColor(true, RB);	
			PrintString(y+1,x+18+2, "<");
			SetColor(false, RB);
		}
		SetColor(false,GG);
	        paintSnake ++; 
       		if(paintSnake == 100)
		{
			paintSnake = 0; 
			printedRev = true; 
		}		
	}
	void PaintSnakeEasy(int y, int x)
	{
		SetColor(true,GG); 
		PrintString(y+13,x-56,"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
		PrintString(y+12,x-2,"XXXX");
		PrintString(y+12,x-1,"XXXX");
		PrintString(y,x+5,"XXXXXXXXXX");
		PrintString(y+1,x+1,"XXXXXXXXXXXXXXXXX");
		PrintString(y+2,x,"XXXXXXXXXXXXXXX");
		PrintString(y+3,x,"XXX");
		PrintString(y+4,x,"XX");
		PrintString(y+5,x,"XXXXXXXXXX");
		PrintString(y+6,x+1,"XXXXXXXXXX");
		PrintString(y+7,x+8,"XXXX");
		PrintString(y+8,x+10,"XX");
		PrintString(y+9,x+8,"XXX");
		PrintString(y+10,x+5,"XXXX");
		PrintString(y+11,x+2,"XXXX");
		SetColor(false,GG); 

		SetColor(true, GY);	
		PrintString(y,x+14, "@");
		SetColor(false, GY);
		SetColor(true, RB);	
		PrintString(y+1,x+18, "-");
		SetColor(false, RB);
		SetColor(true, RB);	
		PrintString(y+1,x+18+1, "-");
		SetColor(false, RB);
		SetColor(true, RB);	
		PrintString(y+1,x+18+2, "-");
		SetColor(false, RB);
		SetColor(true, RB);	
		PrintString(y+1,x+18+2, "<");
		SetColor(false, RB);
	}
	bool PrintFireWorks(int count, int y, int x, bool direction) 
	{
		bool done = false; 
		int direct = 1; 
		if(!direction)
		{
			direct = -1;
		}
		if(count >= 150)
		{
			done = printExplode(count,y+1,x-2);
		
		}
		else
		{
			SetColor(true,YR); 
		}
		if(count == 140)
		{
			PrintString(y-8,x,   "          *  ");
			PrintString(y-8,x,   "          ");
		}
		if(count == 130)
		{
			PrintString(y-8,x,   "          *  ");
			PrintString(y-7,x,   "         ");
		}
		if(count == 120)
		{
			PrintString(y-8,x,   "          *  ");
			PrintString(y-6,x,   "         ");
		}
		if(count == 110)
		{
			PrintString(y-8,x,   "          *  ");
			PrintString(y-5,x,   "         ");
		}
		if(count == 100)
		{
			PrintString(y-8,x,   "          *  ");
			PrintString(y-4,x,   "          ");
		}
		if(count == 90)
		{
			PrintString(y-8,x,   "         _    ");
		 	PrintString(y-3,x,   "          ");
		}
		if(count == 80)
		{
			PrintString(y-8,x,   "        _     ");
			PrintString(y-2,x   ,"         ");
		}
		if(count == 70)
		{
			PrintString(y-7,x,   "       /      ");
//			PrintString(y-1,x,   "         ");

		}
		if(count == 60)
		{
			PrintString(y-6,x,   "      /      ");
//			PrintString(y,x,     "          ");
		}
		if(count ==50) 
		{
			PrintString(y-5,x,   "     /    ");
		}
		if(count == 40)
		{
			PrintString(y-4,x,   "     |    ");
		}
		if(count == 30)
		{
		 	PrintString(y-3,x,   "     |    ");
		}
		if(count == 20)
		{
			PrintString(y-2,x   ,"     |    ");
		}
//		if(count == 10)
//		{
//			PrintString(y-1,x,   "     |    ");
//		}
		
//		if(count == 0)
//		{
//			PrintString(y,x,     "     |    ");
//		
		return done; 
	}
	void printString(int y, int x, string str)
	{
		PrintString(y,x,str);
	}
	bool printExplode(int count, int y, int x)
	{
		bool done = false; 
		if(count == 150)
		{
			printString(y-10,x,"           * *      ");
			printString(y-9,x, "          * * *     ");
			printString(y-8,x, "           * *      "); 
		}
		if(count == 160) 
		{
			printString(y-11,x,"          *   *     ");
			printString(y-10,x,"           * *      ");
			printString(y-9,x, "        * *   * *   ");
			printString(y-8,x, "           * *      "); 
			printString(y-7,x, "         *     *    "); 
		}
		
		if(count == 170)
		{
			printString(y-12,x,"        *       *       ");
			printString(y-11,x,"          *   *         ");
			printString(y-10,x,"           * *          ");
			printString(y-9,x, "      * * *   * * *     ");
			printString(y-8,x, "           * *          "); 
			printString(y-7,x, "         *     *        "); 
			printString(y-6,x, "        *       *       "); 
		}
		
		if(count == 180)
		{
			printString(y-13,x,"      *           *      ");
			printString(y-12,x,"        *       *        ");
			printString(y-11,x,"          *   *          ");
			printString(y-10,x,"                         ");
			printString(y-9,x, "    * * *      * * *     ");
			printString(y-8,x, "                         "); 
			printString(y-7,x, "         *     *         "); 
			printString(y-6,x, "        *       *        "); 
			printString(y-5,x, "       *         *       "); 
		}
		

		if(count ==190)
		{
			printString(y-14,x,"   *                 *   ");
			printString(y-13,x, "      *           *      ");
			printString(y-12,x,"        *       *        ");
			printString(y-11,x,"          *   *          ");
			printString(y-10,x,"                         ");
			printString(y-9,x, "     * * *      * * *    ");
			printString(y-8,x, "  *                    * "); 
			printString(y-7,x, "         *     *         "); 
			printString(y-6,x, "        *       *        "); 
			printString(y-5,x, "       *         *       "); 
			printString(y-4,x, "       *         *       "); 
		}
		
		if(count == 200)
		{
			printString(y-14,x,"   *                 *   ");
			printString(y-13,x,"      *           *      ");
			printString(y-12,x,"        *       *        ");
			printString(y-11,x,"                         ");
			printString(y-10,x,"                         ");
			printString(y-9,x, "     * *          * *    ");
			printString(y-8,x, "  *                    * "); 
			printString(y-7,x, "                         "); 
			printString(y-6,x, "        *       *        "); 
			printString(y-5,x, "       *         *       "); 
			printString(y-4,x, "       *         *       "); 
		}
		if(count ==210)
		{
			printString(y-14,x,"   *                 *    ");
			printString(y-13,x,"      *           *       ");
			printString(y-12,x,"                          ");
			printString(y-11,x,"                          ");
			printString(y-10,x,"                          ");
			printString(y-9,x, "     *              *     ");
			printString(y-8,x, "  *                    *  "); 
			printString(y-7,x, "                          "); 
			printString(y-6,x, "                          "); 
			printString(y-5,x, "       *         *       "); 
			printString(y-4,x, "       *         *       "); 
		}
		if(count ==220 || count == 240 || count == 280 || count == 320 )
		{
			printString(y-14,x,"   *                 *   ");
			printString(y-13,x,"                         ");
			printString(y-12,x,"                         ");
			printString(y-11,x,"                         ");
			printString(y-10,x,"                         ");
			printString(y-9,x ,"                         ");
			printString(y-8, x,"  *                    * "); 
			printString(y-7, x,"                         "); 
			printString(y-6, x,"                         "); 
			printString(y-5, x,"                         "); 
			printString(y-4, x,"       *         *       "); 
			if(count >250) 
			{
				done = true; 
			}
		}
		
		if(count == 230 || count == 250 || count == 290 || count == 330)
		{
			printString(y-14,x,"                         ");
			printString(y-13,x,"                         ");
			printString(y-12,x,"                         ");
			printString(y-11,x,"                         ");
			printString(y-10,x,"                         ");
			printString(y-9,x ,"                         ");
			printString(y-8, x,"                         "); 
			printString(y-7, x,"                         "); 
			printString(y-6, x,"                         "); 
			printString(y-5, x,"                         "); 
			printString(y-4, x,"                         "); 
		}
		return done; 
	}
	 	 	

};
#endif 

