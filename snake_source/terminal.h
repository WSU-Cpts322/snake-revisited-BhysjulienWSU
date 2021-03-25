#ifndef TERMINAL
#define TERMINAL
#include <ncurses.h>
#include<map>
#include<string>
#include<iostream>

#define BW 1
#define CB 2
#define RW 3
#define MC 4
#define BR 5
#define BG 6
#define GY 7
#define RB 8
#define RR 9
#define GG 10
#define BB 11
#define BBL 12
#define MM 13
#define RR1 14
#define CC 15
#define WW 16
#define GY22 17
#define WB 18
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
class Terminal
{
	private:
	bool gameover;
	bool quitgame;	
	int height;
	int width; 
	int difficulty = 1;
	string gameSize = "Medium"; 
	int gameType = 1;	
	int colorTypeOne = 1; 
	int colorTypeTwo = 18;
	string difficultyString; 
	string gameTypeString; 
	//map<string,int> m_colors;

	public:
	Terminal(int Height, int Width)
	{
		SetupTerminal(); 
		height = MEDIUMY;
		width = MEDIUMX;
	       	gameSize = "Medium";
		difficultyString = "Easy"; 
		difficulty = EASY; 
		gameType = 1;
		gameTypeString = "Old School";
	}
	~Terminal()
	{
		TeardownTerminal();
	}
	//Move this to score tracker 
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
	void PrintCurrentSettings()
	{
		string Color 		= "Color:       " + to_string(colorTypeOne); 
		string gameSizeTemp     = "Game Size:   " + gameSize; 
		string gameTyTemp	= "Game Type:   " + gameTypeString;
		string difTemp		= "Difficulty:  " + difficultyString; 
		string scoreMulti	= "Score Multi: " + to_string(ScoreMultiplier()); 
		mvprintw(1, 60, Color.c_str());
		mvprintw(2, 60, gameSizeTemp.c_str());
		mvprintw(3, 60, gameTyTemp.c_str());
		mvprintw(4, 60, difTemp.c_str());
		mvprintw(5, 60, scoreMulti.c_str()); 

	}
	//This one needs to move to slection menus. 
	void SetGameType(int _gameType)
	{
		gameType = _gameType; 
		if(gameType == OLD_SCHOOL)
			gameTypeString = "Old School";
		else if(gameType == NEW_SCHOOL)
			gameTypeString = "New School";
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
	void SetColor(bool color, int colorNum)
	{
		switch(colorNum)
		{
			case 1:
				if(color ==true)
				{
					attron(COLOR_PAIR(BW));
				}
				else
				{
					attroff(COLOR_PAIR(BW));

				}
				break;
			case 2:
				if(color ==true)
				{
					attron(COLOR_PAIR(CB));
				}
				else
				{
					attroff(COLOR_PAIR(CB));
				}
				break;
			case 3:
				if(color ==true)
				{
					attron(COLOR_PAIR(RW));
				}
				else
				{
					attroff(COLOR_PAIR(RW));

				}
				break;
			case 4:
				if(color ==true)
				{
					attron(COLOR_PAIR(MC));
				}
				else
				{
					attroff(COLOR_PAIR(MC));
				}
				break;
			case 5:
				if(color ==true)
				{
					attron(COLOR_PAIR(BR));
				}
				else
				{
					attroff(COLOR_PAIR(BR));

				}
				break;
			case 6:
				if(color ==true)
				{
					attron(COLOR_PAIR(BG));
				}
				else
				{
					attroff(COLOR_PAIR(BG));
				}
				break;
			case 7:
				if(color ==true)
				{
					attron(COLOR_PAIR(GY));
				}
				else
				{
					attroff(COLOR_PAIR(GY));
				}
				break;
			case 8:
				if(color ==true)
				{
					attron(COLOR_PAIR(RB));
				}
				else
				{
					attroff(COLOR_PAIR(RB));
				}
				break;
			case 9:
				if(color ==true)
				{
					attron(COLOR_PAIR(RR));
				}
				else
				{
					attroff(COLOR_PAIR(RR));
				}
				break;
			case 10:
				if(color ==true)
				{
					attron(COLOR_PAIR(GG));
				}
				else
				{
					attroff(COLOR_PAIR(GG));
				}
				break;
			case 11:
				if(color ==true)
				{
					attron(COLOR_PAIR(BB));
				}
				else
				{
					attroff(COLOR_PAIR(BB));
				}
				break;
			case 12:
				if(color ==true)
				{
					attron(COLOR_PAIR(BBL));
				}
				else
				{
					attroff(COLOR_PAIR(BBL));
				}
				break;
			case 13:
				if(color ==true)
				{
					attron(COLOR_PAIR(MM));
				}
				else
				{
					attroff(COLOR_PAIR(MM));
				}
				break;
			case 14:
				if(color ==true)
				{
					attron(COLOR_PAIR(RR));
				}
				else
				{
					attroff(COLOR_PAIR(RR));
				}
				break;
			case 15:
				if(color ==true)
				{
					attron(COLOR_PAIR(CC));
				}
				else
				{
					attroff(COLOR_PAIR(CC));
				}
				break;
			case 16:
				if(color ==true)
				{
					attron(COLOR_PAIR(WW));
				}
				else
				{
					attroff(COLOR_PAIR(WW));
				}
				break;
			case 17:
				if(color ==true)
				{
					attron(COLOR_PAIR(GY));
				}
				else
				{
					attroff(COLOR_PAIR(GY));
				}
				break;
			case 18:
				if(color ==true)
				{
					attron(COLOR_PAIR(WB));
				}
				else
				{
					attroff(COLOR_PAIR(WB));
				}
				break;
			default:
				break; 

		}
	}
	int GetGameType()
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
	bool GameOver()
	{
		return gameover; 
	}
	bool QuitGame()
	{
		return quitgame; 
	}
	
	//Setup Object 
	void SetupTerminal()
	{
		initscr(); 
		scrollok(stdscr, TRUE);
		nodelay(stdscr,TRUE);
		cbreak();
		noecho(); 
		gameover = false;  
		quitgame = false; 
		ChangeColor(); 
		curs_set(0);
		start_color(); 
		//First is forground second is background 
		init_pair(1, COLOR_BLACK, COLOR_WHITE); 	
		init_pair(2, COLOR_CYAN, COLOR_BLUE); 
		init_pair(3, COLOR_RED, COLOR_WHITE); 
		init_pair(4, COLOR_MAGENTA, COLOR_CYAN); 
		init_pair(5, COLOR_BLUE, COLOR_RED);
		init_pair(6, COLOR_BLACK, COLOR_GREEN); 
		init_pair(7, COLOR_GREEN, COLOR_YELLOW); 
		init_pair(8, COLOR_RED, COLOR_BLACK); 
		init_pair(9, COLOR_RED, COLOR_RED); 
	     	init_pair(10, COLOR_GREEN, COLOR_GREEN);
		init_pair(11, COLOR_BLACK, COLOR_BLACK);
		init_pair(12, COLOR_BLUE, COLOR_BLUE);
		init_pair(13, COLOR_MAGENTA, COLOR_MAGENTA); 
		init_pair(14, COLOR_RED, COLOR_RED); 
		init_pair(15, COLOR_CYAN, COLOR_CYAN);	
		init_pair(16, COLOR_WHITE, COLOR_WHITE);
		init_pair(17, COLOR_WHITE, COLOR_BLACK);
	        init_pair(18, COLOR_WHITE, COLOR_BLACK);	
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
	void PrintBox(int topRightY, int topRightX, int topLeftY, int topLeftX, int bottomLeftY, int bottomLeftX, int wDiv,int hDiv,int colorBoarder, int colorFill)
	{
		//Preserve previous color Settings. TODO: Make ColorSelect take int argument for modularity. 
		int boxWidth = width/wDiv;
		int boxHeight = height/hDiv; 
		SetColor(true, colorBoarder);
		//Draw Outline of Box 
		mvhline(topLeftY,topLeftX,'X',boxWidth); 
		mvvline(topLeftY,topLeftY,'X',boxHeight);
		mvvline(topRightY,topRightX,'X',boxHeight); 
		mvhline(bottomLeftY,bottomLeftX,'X',boxWidth); 
		SetColor(false, colorBoarder); 
		
		SetColor(true, colorFill);
		//Drop interior of box. 
		for(int topTemp =topLeftY+1; bottomLeftY-1>=topTemp; topTemp++)
		{
			mvhline(topTemp,topLeftX+1, ' ',boxWidth-2); 
		}
		SetColor(false, colorFill);
				
	}
	
	void PrintSnakeHeader()
	{
		attron(COLOR_PAIR(8));
		printw("  XXXX   XX     XX    XXX    XX  XX  XXXXXX  XX\nXX   XX  XXX    XX   XX XX   XX XX   XX      XX\nXX       XX X   XX  XX   XX  XXX     XX      XX \n   XX    XX  X  XX  XX   XX  XXX     XXXXXX  XX\n     XX  XX   X XX  XX   XX  XX XX   XX      XX\nXX   XX  XX    XXX  XX   XX  XX  XX  XX   \n  XXX    XX     XX  XX   XX  XX   XX XXXXXX  XX __\n===============================================|__*|--- \n\n\n");
		attroff(COLOR_PAIR(8));	
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
	
		string layer1       = "    ____                        "; 
		string layer2       = "   /. . \\                       ";
		string layer3	    = ">-----  /                       ";
		string layer4       = "   \\   /              __     /\\ ";
		string layer5       = "    \\  \\_____________/  \\___/ / ";
		string layer6       = "     \\________________/\\_____/  ";

		mvprintw(y,58, layer1.c_str()); 
		mvprintw(y+1,58, layer2.c_str());
		mvprintw(y+2,58, layer3.c_str());
		mvprintw(y+3,58, layer4.c_str());
		mvprintw(y+4,58, layer5.c_str());
		mvprintw(y+5,58, layer6.c_str());
	}
	void Clear()
	{
		string clear        = "                                       ";
		for(int i = 0; i<45; i++)
		{
			mvprintw(10+i,54,clear.c_str()); 
		}
	}
	void PrintOptions(int selection)
	{     
		if(selection == 1)
		{
			Clear(); 
			PrintSnake(10); 
		}
		if(selection ==2)
		{
			Clear(); 
			PrintSnake(16); 
		}
	}
	void PrintSizeSelection(int selection)
	{
		if(selection == 1)
		{
			Clear();
			PrintSnake(10);
			gameSize = "Small";
			height = SMALLY;
			width = SMALLX; 
		}
		if(selection == 2)
		{
			Clear();
			PrintSnake(16);
			gameSize = "Medium";
			height = MEDIUMY;
			width = MEDIUMX;

		}
		if(selection == 3)
		{
			Clear();
			PrintSnake(22);
			gameSize ="Large";
			height = LARGEY;
			width = LARGEX; 
		}
	}	
	void PrintDifficultySelection(int selection)
	{
		difficulty = selection; 
		if(selection == 1)
		{
			Clear();
			PrintSnake(10); 
			difficulty = EASY;
			difficultyString = "Easy"; 
		}	
		if(selection == 2)
		{
			Clear(); 
			PrintSnake(16); 
			difficulty = HARD;
			difficultyString = "HARD"; 
		}
		if(selection ==3)
		{
			Clear();
			PrintSnake(22);
			difficulty = YR2020;
			difficultyString = "2020";
		}
	}
	void PrintColorSelection(int selection)
	{
		colorTypeOne = selection;
		if(selection == BW)
		{
			colorTypeTwo = WB;
			Clear(); 
			attron(COLOR_PAIR(BW)); 
			PrintSnake(10);
			attroff(COLOR_PAIR(BW));
			//SetColor(selection);
		}
		else if(selection == CB)
		{
			Clear(); 
			colorTypeTwo = CC; 
			attron(COLOR_PAIR(CB)); 
			PrintSnake(16);
			attroff(COLOR_PAIR(CB));
			//SetColor(selection);
		}
		else if(selection ==RW)
		{
			Clear(); 
			colorTypeTwo =RR;
			attron(COLOR_PAIR(RW)); 
			PrintSnake(22);
			attroff(COLOR_PAIR(RW));
			//SetColor(selection);
		}
		else if(selection ==MC)
		{
			Clear();
			colorTypeTwo = MM; 
			attron(COLOR_PAIR(MC)); 
			PrintSnake(28);	
			attroff(COLOR_PAIR(MC));
			//SetColor(selection);
		}
		else if(selection ==BR)
		{
			colorTypeTwo = BBL;
			Clear();
			attron(COLOR_PAIR(BR)); 
			PrintSnake(34);
			attroff(COLOR_PAIR(BR));
			//SetColor(selection);
		}
		else if(selection ==BG)
		{
			colorTypeTwo = BBL; 
			Clear();
			attron(COLOR_PAIR(BG)); 
			PrintSnake(40);	
			attroff(COLOR_PAIR(BG));
			//SetColor(selection);
		}
		else if(selection ==GY)
		{
			Clear();
			attron(COLOR_PAIR(GY)); 
			PrintSnake(46);	
			attroff(COLOR_PAIR(GY));
			//SetColor(selection);
		}
	}

	void PrintSelection(int selection)
	{
		if(selection == 1)
		{
			Clear(); 
			PrintSnake(10);
		}
		else if(selection == 2)
		{
			Clear(); 
			PrintSnake(16);
		}
		else if(selection ==3)
		{
			Clear(); 
			PrintSnake(22);
		}
		else if(selection ==4)
		{
			Clear();
			PrintSnake(28);	
		}
		else if(selection ==5)
		{
			Clear();
			PrintSnake(34);
		}
	}
	void MainScreen()
	{
		PrintSnakeHeader();
		PrintSnakePlayGame(); 
		PrintSnakeOptions(); 
		PrintHighScore(); 
		PrintCurrentSettings(); 
	}
	void OptionsScreen()
	{
		PrintSnakeHeader(); 
		PrintSnakeOld(); 
		PrintSnakeNew(); 
		PrintColor();
		PrintBoardSize();
		PrintReturn(); 
		PrintCurrentSettings(); 
	}
	void DifficultyScreen()
	{
		PrintSnakeHeader(); 
		PrintEasy(); 
		PrintHard();
		Print2020(); 
		PrintCurrentSettings(); 
	}
	void PrintColorScreen() 
	{
		PrintSnakeHeader(); 
		PrintColor1();
		PrintColor2();
		PrintColor3();
		PrintColor4();
		PrintColor5();
		PrintColor6();
		PrintColor7();
		PrintCurrentSettings(); 
	}
	void PrintSizeScreen()
	{
		PrintSnakeHeader(); 
		PrintSmall(); 
		PrintMedium(); 
		PrintLarge(); 
		PrintCurrentSettings(); 
	}
};
#endif
