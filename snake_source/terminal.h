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
#define WR 19
#define BR2 20
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
	bool printedRev = false; 
	int paintSnake = 0; 
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
	Terminal(int Height, int Width, string special) 
	{
		SetupTerminal(); 
		height = Height; 
		width = Width; 
		gameSize = special;
		difficultyString = "Special";
		difficulty = HARD; 
		gameType = 2; 
		gameTypeString = special + " School";
		colorTypeOne = BR2;
		colorTypeTwo = RR; 
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
			case 19:
				if(color ==true)
				{
					attron(COLOR_PAIR(WR));
				}
				else
				{
					attroff(COLOR_PAIR(WR));
				}
			case 20:
				if(color == true)
				{
					attron(COLOR_PAIR(BR2));
				}
				else
				{
					attroff(COLOR_PAIR(BR2)); 
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
	void SetPaintSnake(int value)
	{
		paintSnake = value; 
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
	//	ChangeColor(); 
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
		init_pair(19, COLOR_WHITE, COLOR_RED);
		init_pair(20, COLOR_BLACK, COLOR_RED);
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
	void PrintBoard()
	{
		if(gameTypeString == "WSU School")
		{
			//Call print WSU gameboard. 
			PrintWSUGameBoard(); 	
		}
		else
		{
			PrintBox(1,1,1,1,GetCurrentSecondColor(), GetCurrentPrimaryColor(), true); //myGame.GetCurrentColor()); 
		}
	}
	void PrintBox(int topLeftY, int topLeftX, int wDiv, int hDiv, int colorBoarder, int colorFill, bool divide)
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
		
		SetColor(true, colorFill);
		//Drop interior of box. 
		for(int topTemp =topLeftY+1; bottomLeftY-1>=topTemp; topTemp++)
		{
			mvhline(topTemp,topLeftX+1, ' ',boxWidth-2); 
		}
		SetColor(false, colorFill);
				
	}
	string GetDifficultyStr() 
	{
		return difficultyString; 
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
			mvprintw(10+i,54,clear.c_str()); 
		}
	}
	void PrintOptions(int selection)
	{     
		if(selection == 1)
		{
			Clear(20); 
			PrintSnake(10); 
		}
		if(selection ==2)
		{
			Clear(20); 
			PrintSnake(16); 
		}
	}
	void PrintSizeSelection(int selection)
	{
		if(selection == 1)
		{
			Clear(18);
			PrintSnake(10);
			gameSize = "Small";
			height = SMALLY;
			width = SMALLX; 
		}
		if(selection == 2)
		{
			Clear(18);
			PrintSnake(16);
			gameSize = "Medium";
			height = MEDIUMY;
			width = MEDIUMX;

		}
		if(selection == 3)
		{
			Clear(18);
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
			Clear(18);
			PrintSnake(10); 
			difficulty = EASY;
			difficultyString = "Easy"; 
		}	
		if(selection == 2)
		{
			Clear(18); 
			PrintSnake(16); 
			difficulty = HARD;
			difficultyString = "HARD"; 
		}
		if(selection ==3)
		{
			Clear(18);
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
			Clear(42); 
			attron(COLOR_PAIR(BW)); 
			PrintSnake(10);
			attroff(COLOR_PAIR(BW));
			//SetColor(selection);
		}
		else if(selection == CB)
		{
			Clear(42); 
			colorTypeTwo = CC; 
			attron(COLOR_PAIR(CB)); 
			PrintSnake(16);
			attroff(COLOR_PAIR(CB));
			//SetColor(selection);
		}
		else if(selection ==RW)
		{
			Clear(42); 
			colorTypeTwo =RR;
			attron(COLOR_PAIR(RW)); 
			PrintSnake(22);
			attroff(COLOR_PAIR(RW));
			//SetColor(selection);
		}
		else if(selection ==MC)
		{
			Clear(42);
			colorTypeTwo = MM; 
			attron(COLOR_PAIR(MC)); 
			PrintSnake(28);	
			attroff(COLOR_PAIR(MC));
			//SetColor(selection);
		}
		else if(selection ==BR)
		{
			colorTypeTwo = BBL;
			Clear(42);
			attron(COLOR_PAIR(BR)); 
			PrintSnake(34);
			attroff(COLOR_PAIR(BR));
			//SetColor(selection);
		}
		else if(selection ==BG)
		{
			colorTypeTwo = BBL; 
			Clear(42);
			attron(COLOR_PAIR(BG)); 
			PrintSnake(40);	
			attroff(COLOR_PAIR(BG));
			//SetColor(selection);
		}
		else if(selection ==GY)
		{
			Clear(42);
			attron(COLOR_PAIR(GY)); 
			PrintSnake(46);	
			attroff(COLOR_PAIR(GY));
			//SetColor(selection);
		}
	}
	int GetGameSize()
	{
		int size = 0; 
		if(gameSize == "Medium")
			size = MEDIUMX;
		else if(gameSize == "Small")
			size = SMALLX; 
		else if(gameSize == "Large")
			size = LARGEX; 
		else
			size = LARGEX;
		return size; 
	}
	string GetInitials()
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
				PrintString(14,2, "             "); 
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
			PrintString(14,2, initials); 
		
		}
		return initials; 
	}
	string* StringToInt(int*value, int count)
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
			Clear(clear); 
			PrintSnake(10);
		}
		else if(selection == 2)
		{
			Clear(clear); 
			PrintSnake(16);
		}
		else if(selection ==3)
		{
			Clear(clear); 
			PrintSnake(22);
		}
		else if(selection ==4)
		{
			Clear(clear);
			PrintSnake(28);	
		}
		else if(selection ==5)
		{
			Clear(clear);
			PrintSnake(34);
		}
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
	void SecurityAlert()
	{
		int i = -1; 
		while(i ==-1)
		{
			i = KeyPress(); 
			erase(); 
			PrintSnakeHeader(); 
			PrintString(13,2, "SECURITY ALERT: Your initials have been evaluated by the highly advance onboard \"Snake AI.\"");
			PrintString(14,2,  "Basd on your initals it was determined you are a generaly shady individual and not to be trusted."); 
			PrintString(15,2, "While we understand you didn't cheat on this game, our AI has determined it is only a matter of time before you do.");  
			PrintString(16,2, "As a result, your score has been deleted. Can't argue with Science!!!");
			PrintString(19,2, "Sincerely, Mr. Snake"); 
			PrintString(23,2, "          ----------------------------GOOD BYE-----------------------------------          "); 
		}	
		SetQuitGame(true);

	}

	void MainScreen(string *names, int *scores)
	{
		PrintSnakeHeader();
		PrintSnakePlayGame(); 
		PrintSnakeOptions(); 
		PrintHighScore(); 
		PrintHighScores(names, scores);
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
	void PrintHighScoreScreen(string *names, int *scores)
	{
		erase();
		PrintSnakeHeader(); 
		PrintHighScore(); 
		PrintCurrentSettings(); 
		UpdateTerminal(); 
		PrintHighScores(names, scores);
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

};
#endif 

