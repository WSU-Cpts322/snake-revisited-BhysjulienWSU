#include "selectionMngr.h"

void SelectionManager::CustomColorSelect(Settings &myGame, int *scoresNum, string *names)
{
	EraseAll(); 
	bool returnFlag = false; 
	PrintSnakeHeader();
	SetColor(true,WW); 	
	PrintMultiChars("SELECT,,TWO,,COLOR,,SETS", 11,2); 
	PrintMultiChars("1ST:,,BOARD,,AND,,SNAKE", 17,2); 
	PrintMultiChars("2ND:,,GAME,,BOARDER", 23,2);
	PrintBox(0,132,64,51,64,51,BLBL,WW, false, true);
	SetColor(true, BB); 	
	PrintMultiChars("B,,=,,BLACK", 2,134);
	SetColor(true, RR); 	
	PrintMultiChars("R,,=,,RED", 8,134);
	SetColor(true, GG); 	
	PrintMultiChars("G,,=,,GREEN", 14,134);
	SetColor(true, GG); 	
	PrintMultiChars("G,,=,,GREEN", 14,134);
	SetColor(true, YY); 	
	PrintMultiChars("Y,,=,,YELLOW", 20,134);
	SetColor(true, BLBL); 	
	PrintMultiChars("L,,=,,BLUE", 26,134);
	SetColor(true, MM); 	
	PrintMultiChars("M,,=,,MEGENTA", 32,134);
	SetColor(true, CC); 	
	PrintMultiChars("C,,=,,CYAN", 38,134);
	SetColor(true, WB); 	
	PrintMultiChars("W,,=,,WHITE", 44,134);
	SetColor(false, WB); 	
	PrintString(30,2, "The first letter is the foreground for a given colorset, and the second is the background."); 
	PrintString(32,2, "Note: for the primary (1st) color set, two different colors are required."); 
	PrintMultiChars("1ST:,,,,,,,,,,,,,,,,,,,,,,,,,/,,,", 34,2); 
	PrintMultiChars("2ND:,,,,,,,,,,,,,,,,,,,,,,,,,/,,,", 41,2);
	SetColor(true,BR); 
	PrintString(49,2,"Menu supports WSDA navigation only"); 
	SetColor(false,BR); 
	UpdateTerminal();	
	string c11 = "";
	string c12 = "";
	string c21 = "";
	string c22 = "";
	
	int input = -1;
	int posY = 1; 
	int posX = 1; 
	while(!myGame.QuitGame() && !returnFlag)
	{
		input = KeyPress(); 
		if(input == KEY_UP)
		{
			if(posY > 1)
			{
				posY--; 
			}
		}
		else if(input == KEY_DOWN)
		{
			if(posY < 2)
			{
				posY++;
			}
		}
		else if(input == KEY_LEFT)
		{
			if(posX > 1)
			{
				posX--;
			}
		}
		else if(input == KEY_RIGHT)
		{
			if(posX<2)
			{
				posX++; 
			}
		}
		else if(input  == 'q')
		{
			myGame.SetQuitGame(true); 
		}
		else if(input == '\n')
		{
			returnFlag = true; 
		}
		else
		{
			int tempColor; 
			string tempStr = ""; 
			bool valid = false; 
			char temp = input;
			if(input >= 97 && input <= 122) //Then its uppercase 
			{
				temp = toupper(temp);	
			}
			if(temp == 'B' || temp == 'R' || temp == 'G' || temp == 'Y' || temp == 'L' || temp == 'M' || temp == 'C' || temp == 'W' || temp == 127 || temp ==8)
			{
				if(temp == 'B')
				{
					tempStr = "BLACK";
					tempColor = WB;
				}
				if(temp == 'R')
				{
					tempStr = "RED";
					tempColor = RR;
				}
				if(temp == 'G')
				{
					tempStr = "GREEN"; 
					tempColor = GG;
				}
				if(temp == 'Y')
				{
					tempStr = "YELLOW";
					tempColor = YY;
				}
				if(temp == 'L')
				{
					tempStr = "BLUE";
					tempColor = BLBL;
				}
				if(temp == 'M')
				{
					tempStr = "MAGENTA";
					tempColor = MM;
				}
				if(temp == 'C')
				{
					tempStr = "CYAN"; 
					tempColor = CC;
				}
				if(temp == 'W')
				{
					tempStr = "WHITE"; 
					tempColor = WW;
				}
				if(temp == 127 || temp == 8)
				{
					temp = ' ';
					tempStr = "";
					tempColor = BB; 
				}

				valid = true;
			}
			if(valid)
			{
				PrintSelection( tempStr, posY, posX, c11,c12,c21,c22,temp, tempColor);
				valid = false; 
			}
		}
		PrintBoxSel(posY, posX); 
	}
	string primary = c11+c12;
	string secondary = c21+c22; 
	SetCustomColor(primary, true, true); 
	SetCustomColor(secondary, false, true); 
	myGame.SetPrimColor(GetCurrentPrimaryColor()); 
	myGame.SetSecondColor(GetCurrentSecondColor());

}
void SelectionManager::PrintBoxSel(int posY, int posX)
{
	
	int j = -6;
	int y = 22;
	if(posY == 1 && posX ==1)
	{
		PrintBox(39+j,5+y,46,6,46,6,RR,BB,false, false); 
		PrintBox(39+j,56+y,46,6,46,6,BB,BB,false, false); 
		PrintBox(46+j,5+y,46,6,46,6,BB,BB,false, false); 
		PrintBox(46+j,56+y,46,6,46,6,BB,BB,false, false); 
	}
	else if(posY ==1 && posX ==2)
	{
		PrintBox(39+j,56+y,46,6,46,6,RR,RR,false, false); 
		PrintBox(39+j,5+y,46,6,46,6,BB,BB,false, false); 
		PrintBox(46+j,5+y,46,6,46,6,BB,BB,false, false); 
		PrintBox(46+j,56+y,46,6,46,6,BB,BB,false, false); 
	}
	else if(posY ==2 && posX ==1)
	{
		PrintBox(46+j,5+y,46,6,46,6,RR,RR,false, false); 
		PrintBox(39+j,5+y,46,6,46,6,BB,BB,false, false); 
		PrintBox(39+j,56+y,46,6,46,6,BB,BB,false, false); 
		PrintBox(46+j,56+y,46,6,46,6,BB,RR,false, false); 
	}
	else if(posY ==2 && posX ==2) 
	{
		PrintBox(46+j,56+y,46,6,46,6,RR,RR,false, false); 
		PrintBox(39+j,5+y,46,6,46,6,BB,BB,false, false); 
		PrintBox(39+j,56+y,46,6,46,6,BB,BB,false, false); 
		PrintBox(46+j,5+y,46,6,46,6,BB,BB,false, false); 
	}
}
SelectionManager::SelectionManager(){};
void SelectionManager::PrintSelection(string tempStr, int posY, int posX, string &c11,string &c12, string &c21, string &c22, char temp, int tempColor)
{
	if(posY == 1 && posX ==1)
	{
		string _tempStr;
		_tempStr.push_back(temp);
		if(_tempStr == "L")
		{
			_tempStr = "BL";
		}
		if(_tempStr == "H")
		{
			_tempStr = "W"; 
		}
		if(c12 == "" || _tempStr != c12)
		{
			c11 =""; 
			c11 = _tempStr; 
			PrintMultiChars("        ", 34,2+22); 
			SetColor(true, tempColor); 
			PrintMultiChars(tempStr,34,50+22-(tempStr.length()*6)); 
		}
	}
	else if(posY ==1 && posX ==2)
	{
		string _tempStr;
		_tempStr.push_back(temp);	
		if(_tempStr == "L")
		{
			_tempStr = "BL";
		}
		if(_tempStr == "H")
		{
			_tempStr = "W"; 
		}
		if(c11 == "" || c11 != _tempStr)
		{
			c12 =""; 
			c12 = _tempStr;
			PrintMultiChars("        ",34 ,59+22); 
			SetColor(true, tempColor); 
			PrintMultiChars(tempStr,34,59+22); 
		}
	}
	else if(posY ==2 && posX ==1)
	{
		c21 =""; 
		c21.push_back(temp);
		if(c21 == "L")
		{
			c21 = "BL";
		}
		if(c21 == "H")
		{
			c21 = "W"; 
		}
		PrintMultiChars("        ", 41,2+22); 
		SetColor(true, tempColor); 
		PrintMultiChars(tempStr,41,50+22-tempStr.length()*6); 
	}
	else if(posY ==2 && posX ==2) 
	{
		c22 =""; 
		c22.push_back(temp);
		if(c22 == "L")
		{
			c22 = "BL";
		}
		if(c22 == "H")
		{
			c22 = "W"; 
		}
		PrintMultiChars("        ", 41,59+22); 
		SetColor(true, tempColor); 
		PrintMultiChars(tempStr,41,59+22); 
	}
	if(c12 != "" && c11 !="")
	{
		string primary = c11+c12;
		int prim  = SetCustomColor(primary, true, false); 
		SetColor(true, prim); 
		PrintMultiChars("1ST:", 34,2); 
		SetColor(false, prim); 
	}
	if(c22 != "" && c21 !="")
	{
		string secondary = c21+c22; 
		int second  = SetCustomColor(secondary, false, false); 
		SetColor(true,second); 
		PrintMultiChars("2ND:", 41,2); 
		SetColor(false, second); 
	}

}
bool SelectionManager::ColorModeSelect(bool enterFlag, int position, Settings &myGame, int * scoresNum, string * names)
{

	EraseAll();
	PrintColorScreen(true); 
	PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
	UpdateTerminal();
	int position_temp = 1;
	PrintColorSelection(position_temp);
	int input = 1;
	//Display menu. have user select. Wriite difficulty to myGame object. 
	bool difFlag = false; 
	Revisited(0, 47, 0);
	PaintSnakeEasy(47,56); 	
	PrintHighScores(names, scoresNum); 	
	while(!difFlag && !myGame.QuitGame())
	{
		input = KeyPress();
		if(input == 's' || input == KEY_DOWN)
		{
			if(position_temp<6)
			{
				position_temp ++;
				PrintColorSelection(position_temp);
			}
		}
		if(input == 'w' || input == KEY_UP)
		{
			if(position_temp>1)
			{
				position_temp --;
				PrintColorSelection(position_temp);
			}
		}
		myGame.SetPrimColor(GetCurrentPrimaryColor());
		myGame.SetSecondColor(GetCurrentSecondColor()); 
		if (input == '\n')
		{
			if(position_temp == 6) 
			{
				//Custom Menu Selection; 
				CustomColorSelect(myGame, scoresNum, names);  
				myGame.SetPrimColor(GetCurrentPrimaryColor());
				myGame.SetSecondColor(GetCurrentSecondColor()); 
			}
			erase(); 
			difFlag = true; 
			enterFlag = false;
			OptionsScreen(true);
			PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
			UpdateTerminal(); 
			PrintSelected(position, 18); 
			Revisited(0, 41, 0);
			PaintSnakeEasy(41,56); 	
			PrintHighScores(names, scoresNum);	
		}
		else
		{
			HighLightSelection(WC,CC, position_temp,  myGame, 6, false);
			PrintColorScreen(false); 	
		}
		if(input == 'q')
		{
			//Quit game completely. 
			myGame.SetQuitGame(true);
		}
	}
	return enterFlag;
}


bool SelectionManager::SizeModeSelect(bool enterFlag, int position, Settings &myGame, int * scoresNum, string * names)
{
	EraseAll();  
	PrintSizeScreen(true); 
	PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
	UpdateTerminal();
	int position_temp = 1;
	PrintSizeSelection(position_temp); //Print Dif Options 
	int input = 1;
	//Display menu. have user select. Wriite difficulty to myGame object. 
	bool difFlag = false; 
	Revisited(0, 35, 0);
	PaintSnakeEasy(35,56); 	
	PrintHighScores(names, scoresNum); 	
	PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
	while(!difFlag && !myGame.QuitGame())
	{
		input = KeyPress(); 
		if(input == 's' || input == KEY_DOWN)
		{
			if(position_temp<4)
			{
				position_temp ++;
				myGame.SetGameSize(PrintSizeSelection(position_temp)); //Print Dif Options 
			}
		}
		if(input == 'w' || input == KEY_UP)
		{
			if(position_temp>1)
			{
				position_temp --;
				myGame.SetGameSize(PrintSizeSelection(position_temp)); //Print Dif Options 
			}
		}
		if (input == '\n')
		{
			if(position_temp == 4)
			{
				CustomSize(myGame,scoresNum, names); 
			}
			myGame.SetGameSize(PrintSizeSelection(position_temp)); //Print Dif Options 
			EraseAll(); 
			difFlag = true; 
			enterFlag = false;
			OptionsScreen(true);
			PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
			UpdateTerminal(); 
			PrintSelected(position, 18); 
			Revisited(0, 41, 0);
			PaintSnakeEasy(41,56); 	
			PrintHighScores(names, scoresNum); 	
		}
		if(input == 'q')
		{
			myGame.SetQuitGame(true);
		}
		HighLightSelection(WC,CC, position_temp,  myGame, 4, false);
		PrintSizeScreen(false); 

	}
	return enterFlag; 
}
void SelectionManager::CustomSize(Settings &myGame, int *scoresNum, string *names)
{
	EraseAll();  
	PrintCustomSizeScreen(); 
	PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
	//Display menu. have user select. Wriite difficulty to myGame object. 
	bool difFlag = false; 
	Revisited(0, 29, 0);
	PaintSnakeEasy(29,56); 	
	PrintHighScores(names, scoresNum); 	
	UpdateTerminal();
	int height = 25;
	int width = 50; 
	int y = 15;
	PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
	PrintMultiChars("CUSTOM,SIZE", y-5,2); 
	PrintString(y+1,2,"Enter in two numbers. One for height and one for width. Enter numbers between 10 and 100");
	PrintString(y+3,2,"Select [Enter] when you've entered a number to continue"); 
	SetColor(true,RR); 
	PrintMultiChars("X",y+6,24); 
	PrintBox(y+4,2,y+4,8,27,7,RR,WW,false,true); 
	PrintBox(y+4,35,y+4,8,27,7,RR,WW,false,true); 
	SetColor(true,WR); 
	PrintString(y+4,2,"Height:");
	PrintString(y+4,35, "Width:");
	SetColor(false,WR);
	bool keepvals = false; 
	int input = - 1; 
	while(!difFlag && !myGame.QuitGame())
	{
		input = KeyPress(); 
		if(!keepvals) 
		{	bool myG = false; 
			height = GetNumbers(myG, y+6,4, RR, WW); 
			myGame.SetQuitGame(myG); 
			width = GetNumbers(myG, y+6,37, RR, WW); 
			myGame.SetQuitGame(myG);
			PrintString(y+13, 2, "                                                                               "); 
			PrintString(y+13, 2, "Do you want to set your gameboard to " + to_string(height) +" X " + to_string(width)); 
			PrintString(y+14,2,"Select \"Y\" for yes or \"N\" for no");
		}
		keepvals = true; 
		input = toupper(input); 
		if(input == 'Y' || '\n')
		{
			difFlag = true;
			myGame.SetHeight(height/2);
			myGame.SetWidth(width);
		}
		if(input == 'N')
		{
			keepvals = false; 
			SetColor(true,RR); 
			PrintMultiChars("X",y+6,24); 
			PrintBox(y+4,2,y+4,8,30,7,RR,WW,false,true); 
			PrintBox(y+4,35,y+4,8,30,7,RR,WW,false,true); 
			SetColor(true,WR); 
			PrintString(y+4,2,"Height:");
			PrintString(y+4,35, "Width:");
			SetColor(false,WR);

		}
		if(input == 'Q')
		{
			myGame.SetQuitGame(true); 
		}
		else if(input == '\n')
		{
			difFlag = true; 	
		}
	}
}
string SelectionManager::GetInit(int length)
{
	PrintSnakeHeader(); 
	Revisited(0, 24, 0);
	PaintSnakeEasy(24,56); 	
	PrintString(12,2, "Congratulations, you have achived a highscore. Please enter your initials:");
	return(GetInitials(length,14,2,RR,BB)); 
}
void SelectionManager::AdminSettings(Security &scores)
{
	int y = 24;
	EraseAll(); 
	AdminScreen(); 
	UpdateTerminal();
	string initials; 
	PrintBox(y-2,0,32,8,32,8,RR,WW,false,true); 
	bool enterFlag = false;
	bool check = false; 
	bool delAdd = false; 	
	int position = 1;
	//int input = -1;
	while(!enterFlag)
	{
	//	input = KeyPress(); 
		if(position == 1)
		{
			string addDel = GetInitials(1,y,2,RR,WW);
			if(addDel == "A")
			{	
				PrintString(y+10,2,"                                                                         "); 
				PrintString(y+10,2,"Now enter a set of initials"); 	
				delAdd = true; 
				SetColor(true, RR); 
				PrintMultiChars(":",y,8);
				SetColor(false, RR); 	
				initials = GetInitials(3,y,13,RR,WW); 
				position++; 
			}
			else if(addDel == "D")
			{
				PrintString(y+10,2,"                                                                         "); 
				PrintString(y+10,2,"Now enter a set of initials"); 	
				delAdd = false;
				SetColor(true, RR); 
				PrintMultiChars(":",y,8);
				SetColor(false, RR); 	
				initials = GetInitials(3,y,13,RR,WW); 
				position++; 
			}
			else if(addDel == "Q")
			{
				enterFlag = true; 			
			}
			else
			{
				//I'm sorry you did not enter a valid selection
				//Reset values and start again. 
				position = 1; 
				SetColor(true, WW); 
				PrintMultiChars("  ", y,2); 
				SetColor(false, WW); 
				SetColor(true, RB); 
				PrintString(y+8,2,"Please Enter Either \"A\" or \"D\". If you want to quit enter \"Q\""); 
				SetColor(false, RB); 
			}
		}
		
		if(position == 2 && initials != "") 
		{
			if(delAdd == true) //Then we want ot add to the list. 
			{
				scores.AddSecurity(initials); 
				SetColor(true,RB);
				PrintString(y+10,2,"Initials \"" + initials +"\" have been added to the security profile"); 
				SetColor(false,RB); 
				PrintBox(y-2,0,32,8,32,8,RR,WW,false,true); 
			}
			else //We want to remove from the list 
			{
				check = scores.DeleteSecurity(initials); 
				if(!check)
				{
					SetColor(true,RB);
					PrintString(y+10,2,"Initials \"" + initials +"\" could not be found in the security profile"); 
					SetColor(false,RB); 
					PrintBox(y-2,0,32,8,32,8,RR,WW,false,true); 
				}
				else
				{
					SetColor(true,RB);
					PrintString(y+10,2,"Initials \"" + initials +"\" have been deleted from the security profile"); 
					SetColor(false,RB);
					PrintBox(y-2,0,32,8,32,8,RR,WW,false,true); 
				}
			}
			position = 1; 
		}	
	}
	EraseAll(); 	
}	
bool SelectionManager::GameModeSelect(bool enterFlag, int position, Settings &myGame, int * scoresNum, string * names)
{ 

	EraseAll(); 
	DifficultyScreen(true); 
	PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
	UpdateTerminal();
	string dif = "Easy"; 
	int position_temp = 1;
	PrintDifficultySelection(position_temp); //Print Dif Options 
	int input = 1;
	//Display menu. have user select. Wriite difficulty to myGame object. 
	bool difFlag = false; 
	Revisited(0, 29, 0);
	PaintSnakeEasy(29,56); 	
	PrintHighScores(names, scoresNum); 	
	while(!difFlag && !myGame.QuitGame())
	{
		input = KeyPress(); 
		if(input == 's' || input == KEY_DOWN)
		{
			if(position_temp<3)
			{
				position_temp ++;
				dif = PrintDifficultySelection(position_temp); //Print Dif Options 
			}
		}
		if(input == 'w' || input == KEY_UP)
		{
			if(position_temp>1)
			{
				position_temp --;
				dif = PrintDifficultySelection(position_temp); //Print Dif Options 
			}
		}
		if (input == '\n')
		{
			myGame.SetDifficulty(dif); 
			EraseAll(); 
			difFlag = true; 
			enterFlag = false;
			OptionsScreen(true);
			PrintCurrentSettings(myGame.GetGameSize("S"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
			UpdateTerminal(); 
			PrintSelected(position, 18); 
			Revisited(0, 41, 0);
			PaintSnakeEasy(41,56); 	
			PrintHighScores(names, scoresNum); 	
		}
		else 
		{
		HighLightSelection(WC,CC, position_temp, myGame, 3, false);
		DifficultyScreen(false);
		}
		if(input == 'q')
		{
			myGame.SetQuitGame(true);
		}
	}
	return enterFlag; 
}


string SelectionManager::OptionsSelect(Settings &myGame, int * scoresNum, string * names)
{
	 
	ChangeColor(myGame.GetPrimColor(), myGame.GetSecondColor()); 
	int clear = 30;
	string selection = "";
	bool enterFlag = false;
	int input = 1;
	int position = 1; 
	Revisited(0, 41, 0);
	PaintSnakeEasy(41,56); 	
	PrintSelected(position, clear);
	PrintHighScores(names, scoresNum); 	
	PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
	while(selection != "Return" && !myGame.QuitGame()) //We dont want to return to the main menu until "return" 
	{
		while(!enterFlag && !myGame.QuitGame())
		{
			input = KeyPress(); 
			if(input == 's' || input == KEY_DOWN)
			{
				if(position <5)
				{
					position++;
					PrintSelected(position, clear); 
				}
			}
			else if(input == 'w' || input == KEY_UP)
			{
				if(position>1)
				{
					position--;
					PrintSelected(position, clear);
				}
			}
			else if(input == '\n')
			{
				enterFlag = true;
			}	
			else if(input == 'q')
			{
				myGame.SetQuitGame(true);
			}
			HighLightSelection(WC,CC, position,  myGame, 5, false);
			OptionsScreen(false); 


		//	erase();
		}
		if(position == 1)
		{
			myGame.SetGameType(1); 
			enterFlag = GameModeSelect( enterFlag, position, myGame, scoresNum, names);
		}
		else if (position ==2)
		{
			myGame.SetGameType(2); 
			enterFlag = GameModeSelect( enterFlag, position, myGame, scoresNum, names);
		}
		else if (position ==3)
		{
			enterFlag = ColorModeSelect( enterFlag, position, myGame, scoresNum, names); 	
		}
		else if (position ==4)
		{
			enterFlag = SizeModeSelect( enterFlag, position, myGame, scoresNum, names); 
		}
		else if (position ==5)
		{
			EraseAll(); 
		//	myGame.MainScreen(); 
			PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
			selection = "Return"; 
		}
	}	
	//Print the main menu and return a string option. 
	return selection;
}
bool SelectionManager::ShowScores(Settings myGame, Security &scores)
{
	  
	bool quitFlag = false; 
	EraseAll(); 	
	string names [6]; 
	int scoresNum[6]; 
	bool enterFlag = false;
	scores.GetHighScores(scoresNum, names); 
	PrintHighScoreScreen(names, scoresNum);
	PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
	int printXPosition = 4; 
	int printYPosition = 26;
	PrintBox(18,2,56, 15, 56, 15, RR, WW, false, true); 
	PrintBox(35,2,56, 15, 56, 15, RR, WW, false, true); 
	SetColor(true, BW);
	PrintString(19, 20, "Old School Scores");		
	PrintString(36, 20, "New School Scores");		
	PrintString(21, 5, "Easy");		
	PrintString(21, 26, "Hard");		
	PrintString(21, 44, "2020");		
	PrintString(38, 5, "Easy");		
	PrintString(38, 26, "Hard");		
	PrintString(38, 44, "2020");		
	for(int i = 1; i<=6; i++)
	{
		if(i <=3)
		{
			printYPosition = 22; //Retsrat at the top 
		}
		else if(i ==4) 
		{
		
			printYPosition = 39; 
			printXPosition = 4; 
		}
		else
		{
			printYPosition = 39; 
		}

	//	int *intScores = new int;
		int *intScores = scores.GetArrayScore(i);
		string stgScores[10];
		for(int i = 0; i< 10; i++)
		{
			stgScores[i] = to_string(intScores[i]);	
		}
		string *names =	scores.GetNames(i);
		for(int j = 0;j<10;j++)
		{
			string gap(10-stgScores[j].length(), '_'); 
			string temp;
			if(names[j] != "")
				temp = stgScores[j] + gap +" (" + names[j] +")";
			else
				temp = stgScores[j] + gap;
			PrintString(printYPosition, printXPosition, temp); 
			printYPosition++; 
		}
		printXPosition = printXPosition + 18;
	       	if(i == 3)
			printXPosition = printXPosition + 4;
	}
	
	SetColor(false, BW);
	PrintString(53,2, "Select \"Enter\" to return to the main menu.");
	UpdateTerminal();

	while(!enterFlag && !myGame.QuitGame())
	{	
		int input = KeyPress(); 
		if(input == 'q')
		{
			quitFlag = true; 
			break; 
		}
		else if(input == '\n')
		{
			enterFlag = true;
			erase(); 
		}
	}
	return quitFlag; 

}
string SelectionManager::menuSelection(Settings &myGame, string *names, int *scores)
{
	  
	ChangeColor(myGame.GetPrimColor(), myGame.GetSecondColor()); 
	string selection = ""; 
	bool enterFlag = false;
	bool w = false; 
	bool s = false;
	bool a = false;
	bool d = false;
	bool m = false;
	bool i = false; 
	int input = 1;
	int position = 1; 
	int x = 200;
	int y = 29; 
	int slowDown = 0; 
	int slowDownMore = 0; 
	int length = 10;
	MainScreen(names, scores); 
	PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
	UpdateTerminal();
	bool snakeB = true; 
	PrintSelected(position, 18);

	SetPaintSnake(0); 
	while(!enterFlag && !myGame.QuitGame())
	{
			
		if(x != 0)
			Revisited(x,y, length); 
		slowDown++;
		if(slowDown != 0)
		{
			if(slowDown == 60)
			{
				slowDown = 0;
			}
		}
		if(slowDown == 0)
		{
			if(x!= 0)
			{
				x--; 
			}
			else
			{
				if(snakeB) //Slow it down even more. 
				{
					slowDownMore++;
					if(slowDownMore == 7)
					{
						PaintSnake(y, 57); 
						slowDownMore = 0;
					}
					snakeB = false;
				}	
				else
				{
					snakeB = true; 
				}
			}
		}
		input = KeyPress(); 
		switch (input)
		{
			case 's':
				if(position < 3) //Then we're not at the bottom of the menu 
				{
					position++;
					PrintSelected(position, 18);
				}
				w = false;
				s = false;
			break;
			case KEY_DOWN:
				if(position < 3) //Then we're not at the bottom of the menu 
				{
					position++;
					PrintSelected(position, 18);
				}
				w = false;
				s = false;
			break;
			case KEY_UP:
				if(position > 1)
				{
					position--;
					PrintSelected(position,18);
				}	
				w =false;
				s =false; 
			break; 
		
			case 'w':
				if(position > 1)
				{
					position--;
					PrintSelected(position,18);
				}	
				w =false;
				s =false; 
			break; 
		
			case '\n':
				enterFlag = true; 
				w = false; 
				s = false;
			break; 
		
			case'q':
				myGame.SetQuitGame(true); 
				w = false;
				s = false;
			break;
			case 'a':
				a = true;
				d = false;
				m = false; 
				i = false;
			break; 
			case'd':
				if(a == true)
				{
					d = true; 
				}
				a = false; 
			break;
			case'm':
				if(d == true)
				{
					m = true; 
				}
				d = false; 
			break; 
			case 'i': 
				if(m == true)
				{
					i = true; 
				}
				m = false; 
			break;
			case 'n': 
				if(i == true) 
				{
					enterFlag= true; 
					return "admin"; 
				}	
			case 'W':
		
				w = true;
				s = false; 	
			break; 

			case 'S': 
				if(w == true)
					s = true; 
				w=false; 

			break; 

			case 'U':
				if(s == true)
				{
					enterFlag = true; 
					return "WSU"; 
				}
				w=false;
				s=false;

			break; 
		}
		HighLightSelection(WC,CC, position,  myGame, 3, false);
		MainScreen(); 
	}
	erase();
	if(position == 1 && !myGame.QuitGame())
	{
			selection = "Play Game";
	}
	else if (position ==2 && !myGame.QuitGame())
	{
			selection = "Options";
	}
	else if (position ==3 && !myGame.QuitGame())
	{
			selection = "High Scores";
	}
	
	//Print the main menu and return a string option. 
	return selection;
}
void SelectionManager::HighLightSelection(int _boarder, int _fill, int position, Settings &myGame, int maxPosi, bool color)
{ 
	int boarder, fill;
	if(color)
	{
		//Wrote logic bacwards for how it actually prints.
		boarder = _fill; 
		fill = _boarder; 
	}
	else
	{
		fill = myGame.GetPrimColor(); 
		boarder = myGame.GetSecondColor();  
	}
	int x = 0; 
	int len = 63;
	int ht = 6;
	if(position == 1)
	{
		if(maxPosi>1)
			PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>2)
			PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>3)
			PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>4) 
			PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>5) 
			PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>6) 
			PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>7) 
			PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(10,x,len,ht,len,ht,boarder,fill,false,true);
	}
	else if(position == 2)
	{
		PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>2)
			PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>3)
			PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>4) 
			PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>5) 
			PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>6) 
			PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>7) 
			PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(16,x,len,ht,len,ht,boarder,fill,false,true);
	}
	else if(position == 3)
	{
		PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>3)
			PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>4) 
			PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>5) 
			PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>6) 
			PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>7) 
			PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(22,x,len,ht,len,ht,boarder,fill,false,true);
	}
	else if(position == 4)
	{
		PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>4) 
			PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>5) 
			PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>6) 
			PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>7) 
			PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(28,x,len,ht,len,ht,boarder,fill,false,true);
	}
	else if(position == 5)
	{
		PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>5) 
			PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>6) 
			PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>7) 
			PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(34,x,len,ht,len,ht,boarder,fill,false,true);
	}
	else if(position == 6)
	{
		PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>6) 
			PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>7) 
			PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(40,x,len,ht,len,ht,boarder,fill,false,true);
	}
	else if(position == 7)
	{
		PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
		if(maxPosi>7) 
			PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(46,x,len,ht,len,ht,boarder,fill,false,true);
	}
	else if(position == 8)
	{
		PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
		PrintBox(52,x,len,ht,len,ht,boarder,fill,false,true);
	}
}


