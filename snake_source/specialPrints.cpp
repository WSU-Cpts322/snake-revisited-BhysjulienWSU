#include "specialPrints.h"

void SpecialPrint::SetPaintSnake(int value)
{
	paintSnake = value; 
}
//Function for printing game settings. 
void SpecialPrint::PrintCurrentSettings(string gameS, string gameTypeString, string difficultyString, int mult, int x, int y)
{
	gameSize = gameS; 
	string Color 		= "Color:       " + to_string(GetCurrentPrimaryColor()); 
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
void SpecialPrint::PrintKey(int y) 
{
	int j = 65;                                         
	string layer1 = "	               #####          ";
        string layer2 = "                     ##   ##         ";
        string layer3 = "                    ##     ##        ";
	string layer4 = "######################     ###       ";
	string layer5 = "######################     ###       ";
	string layer6 = "###   ###           ##     ##        ";
	string layer7 = "###   ###	      ##   ##         ";
        string layer8 = "###   ###             #####          ";

	mvprintw(y,j, layer1.c_str()); 
	mvprintw(y+1,j, layer2.c_str());
	mvprintw(y+2,j, layer3.c_str());
	mvprintw(y+3,j, layer4.c_str());
	mvprintw(y+4,j, layer5.c_str());
	mvprintw(y+5,j, layer6.c_str());
	mvprintw(y+6,j, layer7.c_str());
	mvprintw(y+7,j, layer8.c_str());

}
void SpecialPrint::PrintSnake(int y)
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
void SpecialPrint::PrintSnakeHeader()
{
	attron(COLOR_PAIR(RB));
	printw("\n\n     XXXX   XX     XX    XXX    XX  XX  XXXXXX  XX\n   XX   XX  XXX    XX   XX XX   XX XX   XX      XX\n   XX       XX X   XX  XX   XX  XXX     XX      XX \n      XX    XX  X  XX  XX   XX  XXX     XXXXXX  XX\n        XX  XX   X XX  XX   XX  XX XX   XX      XX\n   XX   XX  XX    XXX  XX   XX  XX  XX  XX     \n     XXX    XX     XX  XX   XX  XX   XX XXXXXX  XX __\n   ===============================================|__*|--- \n\n\n");
	attroff(COLOR_PAIR(RB));	
}
void SpecialPrint::PrintSnakeOptions()
{
	printw(" XXX  XXX  XXXXX XXXXX  XXX   X  X  XXXX\nX   X X  X   X     X   X   X  XX X  X\nX   X XXX    X     X   X   X  X  X  XXXX\nX   X X      X     X   X   X  X XX     X\n XXX  X      X   XXXXX  XXX   X  X  XXXX\n\n");
}
void SpecialPrint::PrintSnakePlayGame()
{
	printw("XXX  X      X   X   X   XXX    X    X     X  X X X\nX  X X     X X   X X   X      X X   XX   XX  X\nXXX  X    X   X   X    X XX  X   X  X X X X  X X\nX    X    X X X   X    X  X  X X X  X  X  X  X\nX    XXXX X   X   X     XX   X   X  X  X  X  X X X\n\n");

}
void SpecialPrint::PrintHighScore()
{
	printw("X   X XXXXX  XXX  X   X  XXXX  XXX   XXX   XXX  XXXXX\nX   X   X   X     X   X  X    X   X X   X X   X X\nXXXXX   X   X  XX XXXXX  XXX  X     X   X XXXX  XXX\nX   X   X   X   X X   X    X  X   X X   X X X   X\nX   X XXXXX  XXX  X   X  XXXX  XXX   XXX  X  X  XXXXX\n\n");
}
void SpecialPrint::PrintSnakeOld()
{
	printw(" XXX  X    XXX     XXXXX  XXX  X   X  XXX   XXX  X\nX   X X    X  X    X     X   X X   X X   X X   X X\nX   X X    X   X   XXXXX X     XXXXX X   X X   X X\nX   X X    X  X        X X   X X   X X   X X   X X\n XX   XXXX XXX     XXXXX  XXX  X   X  XXX   XXX  XXXXX\n\n");
}
void SpecialPrint::PrintSnakeNew()
{
	printw("X   X XXXXX X   X  XXXXX  XXX  X   X  XXX   XXX  X\nXX  X X     X   X  X     X   X X   X X   X X   X X\nX X X XXX   X X X  XXXXX X     XXXXX X   X X   X X\nX  XX X     XX XX      X X   X X   X X   X X   X X\nX   X XXXXX X   X  XXXXX  XXX  X   X  XXX   XXX  XXXXX\n\n");
} 
void SpecialPrint::PrintColor()
{
	printw(" XXX   XXX  X     XXX  XXX\nX   X X   X X    X   X X  X\nX   X X   X X    X   X XXX\nX   X X   X X    X   X X X\n XXX   XXX  XXXX  XXX  X  X\n\n");
}
void SpecialPrint::PrintBoardSize()
{
	printw(" XXX   XXX  X   X XXXXX  XXXXX XXXXX XXXXX XXXXXX\nX     X   X XX XX X      X       X      X  X\nX  XX X   X X X X XXX    XXXXX   X     X   XXXX\nX   X XXXXX X   X X          X   X    X    X\n XXX  X   X X   X XXXXX  XXXXX XXXXX XXXXX XXXXXX\n\n");
}
void SpecialPrint::PrintReturn()
{
	printw("XXXX  XXXXX XXXXX X   X XXXX  X   X\nX   X X       X   X   X X   X XX  X\nXXXX  XXX     X   X   x XXXX  X X X\nX  X  X       X   X   X X  X  X  XX\nX   X XXXXX   X    XXX  X   X X   X\n\n");
}
void SpecialPrint::PrintEasy()
{
	printw("XXXXX   XXX   XXXXX  X   X\nX      X   X  X      X   X\nXXX    XXXXX  XXXXX   XXX\nX      X   X      X    X\nXXXXX  X   X  XXXXX    X\n\n");
}
void SpecialPrint::PrintHard()
{
	printw("X   X   XXX   XXXX   XXXX\nX   X  X   X  X   X  X   X\nXXXXX  XXXXX  XXXX   X   X\nX   X  X   X  X  X   X   X\nX   X  X   X  X   X  XXXX\n\n");
}
void SpecialPrint::Print2020()
{
	printw(" XXXX    XXXX    XXXX    XXXX\nX   XX  XX  XX  X   XX  XX  XX\n   XX   XX  XX     XX   XX  XX\n  XX    XX  XX    XX    XX  XX\nXXXXXX   XXXX   XXXXXX   XXXX\n(For Expert Snake Players Only)\n\n");
}
void SpecialPrint::PrintColor1()
{
	printw(" XXX    XXX   X      XXX   XXXX      X\nX   X  X   X  X     X   X  X   X    XX\nX      X   X  X     X   X  XXXX    x X\nX   X  X   X  X     X   X  X  X      X\n XXX    XXX   XXXXX  XXX   X   X   XXXXX\n\n");		
}
void SpecialPrint::PrintColor2()
{
	printw(" XXX    XXX   X      XXX   XXXX    XXX\nX   X  X   X  X     X   X  X   X  X   X\nX      X   X  X     X   X  XXXX      X\nX   X  X   X  X     X   X  X  X     X\n XXX    XXX   XXXXX  XXX   X   X   XXXX\n\n");
}
void SpecialPrint::PrintColor3()
{
	printw(" XXX    XXX   X      XXX   XXXX   XXXXX\nX   X  X   X  X     X   X  X   X      X\nX      X   X  X     X   X  XXXX    XXX\nX   X  X   X  X     X   X  X  X       X \n XXX    XXX   XXXXX  XXX   X   X  XXXXX \n\n");
}
void SpecialPrint::PrintColor4()
{
	printw(" XXX    XXX   X      XXX   XXXX    X  X\nX   X  X   X  X     X   X  X   X   X  X\nX      X   X  X     X   X  XXXX    XXXXX\nX   X  X   X  X     X   X  X  X       X\n XXX    XXX   XXXXX  XXX   X   X      X\n\n");
}
void SpecialPrint::PrintColor5()
{
	printw(" XXX    XXX   X      XXX   XXXX    XXXXX\nX   X  X   X  X     X   X  X   X   X\nX      X   X  X     X   X  XXXX    XXXX\nX   X  X   X  X     X   X  X  X        X\n XXX    XXX   XXXXX  XXX   X   X   XXXX \n\n");
}
void SpecialPrint::PrintColor6()
{
	printw(" XXX    XXX   X      XXX   XXXX     XXX\nX   X  X   X  X     X   X  X   X   X \nX      X   X  X     X   X  XXXX    XXXX\nX   X  X   X  X     X   X  X  X    X   X\n XXX    XXX   XXXXX  XXX   X   X    XXX\n\n");
}
void SpecialPrint::PrintColor7()
{
	printw(" XXX    XXX   X      XXX   XXXX    XXXXX\nX   X  X   X  X     X   X  X   X       X\nX      X   X  X     X   X  XXXX       X\nX   X  X   X  X     X   X  X  X      X\n XXX    XXX   XXXXX  XXX   X   X    X\n\n");
}
void SpecialPrint::PrintSmall()
{
	printw("XXXXX  X   X   XXX   X     X\nX      XX XX  X   X  X     X\nXXXXX  X X X  XXXXX  X     X\n    X  X   X  X   X  X     X\nXXXXX  X   X  X   X  XXXXX XXXXXX\n\n");
}
void SpecialPrint::PrintMedium()
{
	printw("X   X  XXXXX  XXXX  XXXXX  X   X  X   X\nXX XX  X      X   X   X    X   X  XX XX\nX X X  XXX    X   X   X    X   X  X X X\nX   X  X      X   X   X    X   X  X   X\nX   X  XXXXX  XXXX  XXXXX   XXX   X   X\n\n");
}
void SpecialPrint::PrintLarge()
{
	printw("X      XXX   XXXX   XXXXX  XXXXX\nX     X   X  X   X  X      X\nX     XXXXX  XXXX   X XXX  XXXX\nX     X   X  X  X   X   X  X\nXXXXX X   X  X   X  XXXXX  XXXXX\n\n");
}
void SpecialPrint::Revisited(int x, int y, int length)
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
bool SpecialPrint::printExplode(int count, int y, int x)
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
bool SpecialPrint::PrintFireWorks(int count, int y, int x, bool direction) 
{
	bool done = false; 
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
	return done; 
}
void SpecialPrint::PaintSnake(int y, int x)
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
void SpecialPrint::PaintSnakeEasy(int y, int x)
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
//This function could take specific characters to only refresh changed points on gameboard???? 
void SpecialPrint::PrintOptions(int selection)
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
void SpecialPrint::PrintSecSelection(int selection)
{     
	if(selection == 1)
	{
		SetColor(true, GB);	
		Clear(20); 
		PrintKey(10); 
		SetColor(false, GB);	
	}
	if(selection ==2)
	{
		SetColor(true, GB);	
		Clear(20); 
		PrintKey(16); 
		SetColor(false, GB);	
	}
}
//Function that prints game size based on index and returns a string based on that selection. 
string SpecialPrint::PrintSizeSelection(int selection)
{
	string gameSize = "Large";
	if(selection == 1)
	{
		SetColor(true, GB);	
		Clear(18);
		PrintSnake(10);
		gameSize = "Small";
		//height = SMALLY;
		//width = SMALLX; 
		SetColor(false, GB);	
	}
	if(selection == 2)
	{
		SetColor(true, GB);	
		Clear(18);
		PrintSnake(16);
		gameSize = "Medium";
		//height = MEDIUMY;
		//width = MEDIUMX;
		SetColor(false, GB);	

	}
	if(selection == 3)
	{
		SetColor(true, GB);	
		Clear(18);
		PrintSnake(22);
		gameSize ="Large";
		//height = LARGEY;
		//width = LARGEX; 
		SetColor(false, GB);	
	}
	if(selection == 4)
	{
		SetColor(true, GB);	
		Clear(18);
		PrintSnake(26);
		gameSize ="Custom";
		//height = LARGEY;
		//width = LARGEX; 
		SetColor(false, GB);	
	}
	return gameSize; 
}	
string SpecialPrint::PrintDifficultySelection(int selection)
{
	string dif; 
	//difficulty = selection; 
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
void SpecialPrint::PrintColorSelection(int selection)
{
	if(selection == 1)
	{
		ChangeColor(BW,WB);
		Clear(37); 
		attron(COLOR_PAIR(BW)); 
		PrintSnake(10);
		attroff(COLOR_PAIR(BW));
		//SetColor(selection);
	}
	else if(selection == 2)
	{
		ChangeColor(CBL,CC);
		Clear(37); 
		attron(COLOR_PAIR(CBL)); 
		PrintSnake(16);
		attroff(COLOR_PAIR(CBL));
		//SetColor(selection);
	}
	else if(selection ==3)
	{
		ChangeColor(RW,RR);
		Clear(37); 
		attron(COLOR_PAIR(RW)); 
		PrintSnake(22);
		attroff(COLOR_PAIR(RW));
		//SetColor(selection);
	}
	else if(selection ==4)
	{
		ChangeColor(MC,MM);
		Clear(37);
		attron(COLOR_PAIR(MC)); 
		PrintSnake(28);	
		attroff(COLOR_PAIR(MC));
		//SetColor(selection);
	}
	else if(selection ==5)
	{
		ChangeColor(BR,BBL);
		Clear(37);
		attron(COLOR_PAIR(BR)); 
		PrintSnake(34);
		attroff(COLOR_PAIR(BR));
		//SetColor(selection);
	}
	else if(selection == 6)
	{
		Clear(37);
		ChangeColor(BW,WB);
		SetColor(true, BW);
		PrintSnake(40); 
		SetColor(false, BW); 
	}
}
int SpecialPrint::GetNumbers(bool &myG, int y, int x, int color, int color2)//TODO This probably sshould be moved to selection manager. Taking input and printing. To much function for sinle method. 
{
	SetColor(true,color); 
	int input;
	string numbers; 
	bool enterFlag = false; 
	int i = 0; 
	int size = 0; 
	while(!enterFlag && !myG)
	{
		input = KeyPress();
		if(i<0)
		{
			i=0; 
		}
		if(i == 0)
		{
			numbers = "_"; 
		}
		if(i<3)
		{
			if(input >= 48 && input <= 57 && i<2)
			{
				if(i == 0)
				{
					numbers = "";
				}
				if(i == 1)
				{
					numbers.resize(1); 
				}
				char temp = input;
				temp = input;
				numbers+=temp;
				if(i<1)
				{
					numbers = numbers + "_"; 
				}

				i++; 
			}
			else if(input >= 48 && input <= 57 && i<3)
			{
				i++; 
			}
		}
		if(input == KEY_BACKSPACE) 
		{
			string temp = numbers.substr(0,numbers.length()-1);
			numbers = temp; 
			SetColor(true,color2); 
			PrintMultiChars("  ",y,x); 
			SetColor(true,color); 
			i--; 
		}
		if(input == '\n' || i >=3)
		{
			stringstream temp(numbers);
			temp >> size; 
			if(size == 0)
			{
				SetColor(true,RB); 
				PrintString(y+7,x, "Please enter at least one character before continuing"); 
				SetColor(true,color);
			       	size = 0; 	
			}
			else if(size<10 || size>100)
			{
				SetColor(true,RB); 
				PrintString(y+7,x, "                                                        "); 
				PrintString(y+7,x, "Please enter a number between 1 and 100"); 
				SetColor(true,color); 
				size = 0;
			}
			else
			{
				enterFlag = true; 
			}
		}
		if( input == 'q')
		{
			myG = true; 
		}
		SetColor(true, WW);
		PrintMultiChars("  ", y,x); 
		SetColor(true,color); 
		PrintMultiChars(numbers, y,x); 
//		PrintString(14,2, initials); 
	
	}
	SetColor(false,color); 
	return size;
}	
string SpecialPrint::GetInitials(int length, int y, int x, int color, int color2, bool pw)//TODO This probably sshould be moved to selection manager. Taking input and printing. To much function for sinle method. 
{
	SetColor(true,color); 
	int input;
	string initials; 
	bool enterFlag = false; 
	int i = 0; 
	while(!enterFlag)
	{
		input = KeyPress();
		if(i<length)
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
		if(input == KEY_BACKSPACE) 
		{
			string temp = initials.substr(0,initials.length()-1);
			initials = temp; 
			SetColor(true,color2); 
			PrintMultiChars("   ",y,x);
		       	if(length > 3)	
				PrintMultiChars("          ",y,x);
			//PrintString(14,2, "             "); 
			SetColor(true,color); 
			i--; 
		}
		if(input == '\n')
		{
			if(i == 0)
			{
				SetColor(true,RB); 
				PrintString(y+7,x, "Please enter at least one character before continuing"); 
				SetColor(true,color); 
			}
			else
			{
				enterFlag = true; 
			}
		}
		if(!pw)
			PrintMultiChars(initials, y,x); 
		else 
		{
			string star(initials.length(), '*'); 
			PrintMultiChars(star, y,x); 
		}
//		PrintString(14,2, initials); 
	
	}
	SetColor(false,color); 
	return initials; 
}
void SpecialPrint::PrintSelected(int selection, int clear)
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
void SpecialPrint::PrintHighScores(string *name, int *scores)
{
	string stgScores [6];
	for(int i = 0; i<6; i++)
	{
		stgScores[i] = to_string(scores[i]); 
	}
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
bool SpecialPrint::SecurityAlert()
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
void SpecialPrint::PrintSecurityOptionScreen()
{
	PrintSnakeHeader(); 
	SetColor(true,RB);
	PrintString(11,2, "Which option would you like to make changes too"); 
	SetColor(true,GR);
	PrintMultiChars("SECURITY", 13,2); 
	PrintMultiChars("PASSWORD", 19,2);	
	SetColor(false,GR); 
}

void SpecialPrint::MainScreen(string *names, int *scores)
{
	PrintSnakeHeader();
	
	SetColor(true,GBL); 
	PrintMultiChars("PLAY,GAME", 11,2); 
	PrintMultiChars("OPTIONS", 11+6,2); 
	PrintMultiChars("HIGH,SCORES", 11+12,2);
	SetColor(false, GBL); 
	PrintHighScores(names, scores);
}
void SpecialPrint::MainScreen()
{
	SetColor(true,GBL); 
	PrintMultiChars("PLAY,GAME", 11,2); 
	PrintMultiChars("OPTIONS", 11+6,2); 
	PrintMultiChars("HIGH,SCORES", 11+12,2);
	SetColor(false, GBL); 
}
void SpecialPrint::AdminScreen()
{
	PrintSnakeHeader(); 
	SetColor(true,RR); 
	PrintMultiChars("ADMIN,SETTINGS", 11,2);
	SetColor(true,RB);
	PrintString(18,2, "Admin allows the addition or removal of specific initials for the security profile");
	PrintString(20,0, "Enter either \"A\" for add or \"D\" for delete. Enter \"Q\" to return to main menu.");
	PrintString(21,0, "Oncee you've entered an option, select [Enter] to continue"); 	
	SetColor(false,RB); 
}
void SpecialPrint::OptionsScreen(bool header)
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
void SpecialPrint::DifficultyScreen(bool header)
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
void SpecialPrint::PrintColorScreen(bool header) 
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
void SpecialPrint::PrintSizeScreen(bool header)
{
	if(header)
	{
		PrintSnakeHeader(); 
	}
	SetColor(true,GBL); 
	PrintMultiChars("SMALL", 11,2); 
	PrintMultiChars("MEDIUM", 11+6,2); 
	PrintMultiChars("LARGE", 11+12,2);
       	PrintMultiChars("CUSTOM", 11+18,2); 	
}
void SpecialPrint::PrintCustomSizeScreen()
{
		PrintSnakeHeader(); 
}
void SpecialPrint::PrintHighScoreScreen(string *names, int *scores)
{
	erase();
	PrintSnakeHeader(); 
	PrintMultiChars("HIGH SCORES!!!", 11,3); 		
	//PrintHighScore(); 
	UpdateTerminal(); 
	PrintHighScores(names, scores);
}
void SpecialPrint::HighScoreDisplay(int scoreNum)
{
	int x;
	int y; 
	PrintSnakeHeader(); 
	string scoreStr;
	scoreStr = to_string(scoreNum); 
	getyx(stdscr, y, x);
	PrintBox(y, 1, 109,26,109,26, GG,RR,false, true); 
	SetColor(true,GG); 
	PrintMultiChars("CONGRATULATIONS,...", y+2,3); 
	PrintMultiChars("NEW,,HIGHSCORE!!!",y+8,8); 
	SetColor(false,GG); 
	SetColor(true,BLBL); 
	PrintMultiChars("YOUR,,SCORE:", y+14,8); 
	SetColor(true, WW); 
	PrintMultiChars(scoreStr, y+20,8);
	SetColor(false,WW); 
	getyx(stdscr, y, x);
	Revisited(2,y+4, 0); 
	PaintSnakeEasy(y+4, 56+2);
}
bool SpecialPrint::PrintdRev()
{
	return printedRev; 
}


