#include "terminal.h"

Terminal::Terminal()
{
	SetupTerminal(); 
}
Terminal::~Terminal()
{
	TeardownTerminal();
}
//This one needs to move to slection menus. 
void Terminal::SetColor(bool color, int colorNum)
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
//Setup Object 
void Terminal::SetupTerminal()
{
	initscr(); 
	scrollok(stdscr, TRUE);
	nodelay(stdscr,TRUE);
	keypad(stdscr, true); 
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
int Terminal::SetCustomColor(string color, bool primary, bool assign)
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
int Terminal::KeyPress()
{
	return getch(); 
}
void Terminal::TeardownTerminal()
{
	endwin(); 
}
void Terminal::printString(int y, int x, string str)
{
	PrintString(y,x,str);
}
//This function could take specific characters to only refresh changed points on gameboard???? 
void Terminal::ClearTerminal()
{
	clear(); 
}
void Terminal::UpdateTerminal()
{
	refresh(); 
}
int Terminal::GetCurrentPrimaryColor()
{
	return colorTypeOne;
}
int Terminal::GetCurrentSecondColor()
{
	return colorTypeTwo;
}
void Terminal::ChangeColor(int colorChangeOne, int colorChangeTwo)
{
	colorTypeOne = colorChangeOne; 
	colorTypeTwo = colorChangeTwo;
}	
void Terminal::PrintBox(int topLeftY, int topLeftX, int wDiv, int hDiv, int width, int height, int colorBoarder, int colorFill, bool divide, bool fill)
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
void Terminal::Blink(bool blink)
{
	if(blink)
		attron(A_BLINK); 
	else
		attroff(A_BLINK); 
}
void Terminal::Clear(int rows)
{
	string clear        = "                                       ";
	for(int i = 0; i<rows; i++)
	{
		mvprintw(10+i,65,clear.c_str()); 
	}
}
//string* Terminal::StringToInt(int*value, int count)//TODO release resources on function call. 
//{
//	string temp[10]; 
//	for(int i = 0; i<count; i++)
//	{
//		temp[i] = to_string(value[i]);
//	}
//	return temp; 
//}
void Terminal::PrintString(int y, int x, string String)
{	
	mvprintw(y,x, String.c_str());
}
void Terminal::EraseAll()
{
	erase(); 
}

